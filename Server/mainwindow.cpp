#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDateTime>
#include <QListWidgetItem>

// Constructor: Initializes the UI, creates the TCP server,
// connects the newConnection signal, and starts listening on port 8080.
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TCP_Server = new QTcpServer(this);
    connect(TCP_Server, &QTcpServer::newConnection, this, &MainWindow::newConnection);

    if (TCP_Server->listen(QHostAddress::Any, 8080)) {
        log("=== Server started successfully on port 8080 ===");
        statusBar()->showMessage("Server running on port 8080   |   0 clients connected");
    } else {
        log("!!! Server failed to start !!!");
        statusBar()->showMessage("Server failed to start");
    }
}
// Destructor: Releases dynamically allocated client information
// and cleans up the user interface.
MainWindow::~MainWindow()
{
    qDeleteAll(UserRegistry);
    UserRegistry.clear();
    delete ui;
}

// ─── Helpers ──────────────────────────────────────────────────────────────────

// Adds a timestamped event to the event log panel.
// Used for connection, disconnection, and leader updates.
void MainWindow::logEvent(const QString &text)
{
    QString ts = QDateTime::currentDateTime().toString("hh:mm");
    ui->textEdit_Event_Log->append(QString("[%1] %2").arg(ts, text));
}

// Displays server messages in the main log window.
void MainWindow::log(const QString &text)
{
    ui->textEdit_Client_Messages->append(text);
}

/// Refreshes the connected user list, updates the receiver
// selection box, and displays the latest server status.
void MainWindow::refreshUserDisplay()
{
    // ── Left panel list widget ────────────────────────────────────────────
    ui->listWidget_Users->clear();
    for (auto it = UserRegistry.cbegin(); it != UserRegistry.cend(); ++it) {
        bool isLeader = (it.key() == leaderUsername);
        QString label = it.key();
        if (isLeader) label += "  ★";
        QListWidgetItem *item = new QListWidgetItem(label);
        item->setToolTip(QString("Public key: %1").arg(it.value()->publicKey));
        ui->listWidget_Users->addItem(item);
    }

    // ── Target combobox in the send bar ──────────────────────────────────
    ui->comboBox_Client_List->clear();
    ui->comboBox_Client_List->addItems(UserRegistry.keys());

    // ── Status bar ────────────────────────────────────────────────────────
    QString leaderInfo = leaderUsername.isEmpty() ? "none" : leaderUsername;
    statusBar()->showMessage(
        QString("Server running on port 8080   |   %1 client(s) connected   |   leader: %2")
        .arg(UserRegistry.size()).arg(leaderInfo)
    );
}

// ─── Connection handling ───────────────────────────────────────────────────────
// Handles every incoming TCP connection request.
// Each pending connection is passed for initialization.
void MainWindow::newConnection()
{
    while (TCP_Server->hasPendingConnections()) {
        Add_New_Client_Connection(TCP_Server->nextPendingConnection());
    }
}
// Sets up signal-slot connections for a newly connected client
// and sends the initial Diffie-Hellman parameters.
void MainWindow::Add_New_Client_Connection(QTcpSocket *socket)
{
    connect(socket, &QTcpSocket::readyRead,    this, &MainWindow::Read_Data_From_Socket);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::Client_Disconnected);

    QJsonObject packet101;
    packet101["type"]    = 101;
    packet101["p_value"] = DH_P;
    packet101["g_value"] = DH_G;

    socket->write(QJsonDocument(packet101).toJson(QJsonDocument::Compact) + "\n");
    log("New unauthenticated client connected.");
}

// ─── Incoming data ─────────────────────────────────────────────────────────────
// Reads incoming JSON packets from clients,
// validates them, and processes them according to message type.
void MainWindow::Read_Data_From_Socket()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());

    if (!socket) return;
    QByteArray rawIncomingStream = socket->readAll();
    QList<QByteArray> segmentedPackets = rawIncomingStream.split('\n');

    for (const QByteArray &rawPacket : segmentedPackets) {
        QByteArray cleanPacket = rawPacket.trimmed();
        if (cleanPacket.isEmpty()) continue;

        QJsonParseError parseError;
        QJsonDocument doc = QJsonDocument::fromJson(cleanPacket, &parseError);

        if (parseError.error != QJsonParseError::NoError) {
            log("Parsing Warning: Dropped malformed segment: " + QString(cleanPacket));
            continue;
        }

        QJsonObject json    = doc.object();
        int messageType = json["type"].toInt();

        // ── Type 102: Client registration ────────────────────────────────
        if (messageType == CLIENT_REGISTRATION) {
            QString name      = json["username"].toString();
            int clientPubKey  = json["public_key"].toInt();

            if (name.isEmpty()) continue;

            if (UserRegistry.contains(name)) {
                delete UserRegistry.take(name);
            }

            ClientInfo *info  = new ClientInfo();
            info->username    = name;
            info->socket      = socket;
            info->publicKey   = clientPubKey;
            UserRegistry[name] = info;

            log(QString("Registered: %1 (key: %2)").arg(name).arg(clientPubKey));
            logEvent(name + " connected");

            if (leaderUsername.isEmpty() || !UserRegistry.contains(leaderUsername)) {
                leaderUsername = name;
                log(QString("+++ Leader appointed: %1 +++").arg(leaderUsername));
                logEvent(name + " appointed leader");
            }

            refreshUserDisplay();
            sendLeaderUpdatedDirectory();
        }
        //Message type 101 normal
        else if (messageType == NORMAL_MESSAGE){
            QByteArray forwardPacket =
                QJsonDocument(json).toJson(QJsonDocument::Compact) + "\n";

            for (auto client : UserRegistry.values())
            {
                if (client->socket != socket) // don't echo back to sender
                {
                    client->socket->write(forwardPacket);
                }
            }

            log(QString("[CHAT] Relayed encrypted message"));
        }

        // ── Type KEY_DISTRIBUTION : Leader distributes encrypted session keys ───────────
        else if (messageType == KEY_DISTRIBUTION) {
            int leaderPubKey          = json["leader_public_key"].toInt();
            QJsonArray keyPayloads    = json["key_payloads"].toArray();

            log("Leader delivered key bundles. Routing...");

            for (int i = 0; i < keyPayloads.size(); ++i) {
                QJsonObject payload      = keyPayloads[i].toObject();
                QString targetUser       = payload["target_user"].toString();
                QString encryptedKeyHex  = payload["encrypted_key"].toString();

                if (UserRegistry.contains(targetUser)) {
                    QJsonObject dispatchPacket;
                    dispatchPacket["type"]             = ;
                    dispatchPacket["leader_public_key"] = leaderPubKey;
                    dispatchPacket["encrypted_key"]    = encryptedKeyHex;

                    UserRegistry[targetUser]->socket->write(
                        QJsonDocument(dispatchPacket).toJson(QJsonDocument::Compact) + "\n"
                    );
                }
            }
        }
    }
}

// ─── Leader directory push ─────────────────────────────────────────────────────
// Sends the updated participant list to the current leader.
// The leader uses this information for key distribution.
void MainWindow::sendLeaderUpdatedDirectory()
{
    if (leaderUsername.isEmpty() || !UserRegistry.contains(leaderUsername)) {
        log("Directory sync skipped: leader missing.");
        return;
    }

    QJsonObject packet104;
    packet104["type"] = 104;

    QJsonArray participantsArray;
    for (auto it = UserRegistry.cbegin(); it != UserRegistry.cend(); ++it) {
        if (it.key() == leaderUsername) continue;
        QJsonObject peer;
        peer["username"]   = it.value()->username;
        peer["public_key"] = it.value()->publicKey;
        participantsArray.append(peer);
    }

    packet104["participants"] = participantsArray;

    QTcpSocket *leaderSocket = UserRegistry[leaderUsername]->socket;
    leaderSocket->write(QJsonDocument(packet104).toJson(QJsonDocument::Compact) + "\n");
    log(QString("Updated directory sent to leader (%1).").arg(leaderUsername));
}

// ─── Disconnect ────────────────────────────────────────────────────────────────

void MainWindow::Client_Disconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (!socket) return;

    QString disconnectedUser;
    for (auto it = UserRegistry.begin(); it != UserRegistry.end(); ++it) {
        if (it.value()->socket == socket) {
            disconnectedUser = it.key();
            break;
        }
    }

    if (!disconnectedUser.isEmpty()) {
        log(QString("!!! Client disconnected: %1 !!!").arg(disconnectedUser));
        logEvent(disconnectedUser + " disconnected");

        delete UserRegistry.take(disconnectedUser);

        if (leaderUsername == disconnectedUser) {
            leaderUsername.clear();
            if (!UserRegistry.isEmpty()) {
                leaderUsername = UserRegistry.firstKey();
                log(QString("+++ Leader left. New leader: %1 +++").arg(leaderUsername));
                logEvent(leaderUsername + " appointed leader");
                sendLeaderUpdatedDirectory();
            } else {
                log("Room is now empty.");
                logEvent("Room empty");
            }
        }

        refreshUserDisplay();
    }

    socket->deleteLater();
}

// ───────────────── Send Button───────────────────────────────────────

// void MainWindow::on_push_button_Send_clicked()
// {
//     // QString rawMessage = ui->lineEdit_send_message->text().trimmed();
//    QString receiver   = ui->comboBox_Client_List->currentText();

//     if (rawMessage.isEmpty()) return;

//     QJsonObject msgObj;
//     msgObj["type"]    = 1;
//     msgObj["payload"] = rawMessage;

//     QByteArray msgPayload = QJsonDocument(msgObj).toJson(QJsonDocument::Compact) + "\n";

//      if (ui->combobox2_Send_Message_type->currentText() == "All") {
//      for (auto client : UserRegistry.values()) {
//          client->socket->write(msgPayload);
//     }
//       log(QString("[SERVER → ALL] %1").arg(rawMessage));
//     } else {
//        if (UserRegistry.contains(receiver)) {
//           UserRegistry[receiver]->socket->write(msgPayload);
//           log(QString("[SERVER → %1] %2").arg(receiver, rawMessage));
//         }
//      }

//     // ui->lineEdit_send_message->clear();
// }
