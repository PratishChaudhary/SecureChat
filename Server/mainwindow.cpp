#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDateTime>
#include <QListWidgetItem>
#include <QNetworkInterface>
#include <QNetworkAddressEntry>
#include <QMessageBox>
#include <QPushButton>
#include <QAbstractButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TCP_Server = new QTcpServer(this);
    connect(TCP_Server, &QTcpServer::newConnection, this, &MainWindow::newConnection);
    //listening at 8080
    qint16 port = 8080;

    if (TCP_Server->listen(QHostAddress::Any, port)) {
        log("=== Server started successfully on ===");
        QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
        for (const QNetworkInterface &interface : interfaces) {
            // 2. STAGE 1 FILTER: Interface must be up and actively running hardware
            bool isUp = interface.flags().testFlag(QNetworkInterface::IsUp);
            bool isRunning = interface.flags().testFlag(QNetworkInterface::IsRunning);

            if (!isUp || !isRunning) {
                continue; // Skip if the cable is unplugged or interface is disabled
            }
            else
            {
                QList<QNetworkAddressEntry> entries = interface.addressEntries();
                for (const QNetworkAddressEntry &entry : entries) {
                    QHostAddress ip = entry.ip();

                    // 4. STAGE 2 FILTER: Skip internal lookback/localhost strings (127.0.0.1 / ::1)
                    if (ip.isLoopback()) {
                        continue;
                    }

                    // Determine if it's IPv4 or IPv6
                    QString type = (ip.protocol() == QAbstractSocket::IPv4Protocol) ? "IPv4" : "IPv6";

                    // Print the live details
                    if(interface.humanReadableName() =="Wi-Fi" && type=="IPv4"){
                        QString haddr = ip.toString();
                        log("Address : " + haddr);
                    }
                }
            }
        }
        log("Port : " + QString::number(port));
        //firing the beacon including our local ip (where our server is started)
        discoveryBeacon = new ServerDiscoveryBeacon(port, this);
        statusBar()->showMessage("Server running on port 8080   |   0 clients connected");

    } else {
        log("!!! Server failed to start !!!");
        statusBar()->showMessage("Server failed to start");
    }
}

MainWindow::~MainWindow()
{
    qDeleteAll(UserRegistry);
    UserRegistry.clear();
    delete ui;
}


bool MainWindow::onNewAuthRequest(QTcpSocket* socket, QString username)
{
    QMessageBox msgBox;
    msgBox.setText("Allow user: " + username + "?");

    QPushButton* allow = msgBox.addButton("Allow", QMessageBox::AcceptRole);
    QPushButton* deny  = msgBox.addButton("Deny", QMessageBox::RejectRole);

    msgBox.exec();

    if (msgBox.clickedButton() == allow)
        return true;
    else
        return false;
}


// ─── Helpers ──────────────────────────────────────────────────────────────────

// Appends a timestamped line to the compact event log on the left panel
void MainWindow::logEvent(const QString &text)
{
    QString ts = QDateTime::currentDateTime().toString("hh:mm");
    ui->textEdit_Event_Log->append(QString("[%1] %2").arg(ts, text));
}

void MainWindow::sendUserList()
{
    /*So we alr have the data stored in UserRegistry so i just send that same data */
    QJsonObject packet;
    packet["type"] = USER_LIST;
    packet["leader"] = leaderUsername;
    QJsonArray users;
    for(auto it = UserRegistry.cbegin(); it!=UserRegistry.cend();it++)
    {
        users.append(it.key());
    }
    packet["users"] = users;
    QByteArray data = QJsonDocument(packet).toJson(QJsonDocument::Compact) + "\n";
    for(auto client: UserRegistry)
    {
        client->socket->write(data);
    }
}

// Appends a line to the main server message log in the center panel
void MainWindow::log(const QString &text)
{
    ui->textEdit_Client_Messages->append(text);
}

// Rebuilds the user list widget in the left panel and the target combobox in the send bar.
// Called whenever UserRegistry changes.
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

void MainWindow::newConnection()
{
    while (TCP_Server->hasPendingConnections()) {
        Add_New_Client_Connection(TCP_Server->nextPendingConnection());
    }
}

void MainWindow::Add_New_Client_Connection(QTcpSocket *socket)
{
    connect(socket, &QTcpSocket::readyRead,    this, &MainWindow::Read_Data_From_Socket);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::Client_Disconnected);

    QJsonObject packet101;
    packet101["type"]    = LEADER_KEY_SETUP;
    packet101["p_value"] = DH_P;
    packet101["g_value"] = DH_G;

    socket->write(QJsonDocument(packet101).toJson(QJsonDocument::Compact) + "\n");
    log("New unauthenticated client connected.");
}

// ─── Incoming data ─────────────────────────────────────────────────────────────
void MainWindow::Read_Data_From_Socket()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (!socket) return;

    while (socket->canReadLine()) {
        QByteArray cleanPacket = socket->readLine().trimmed();
        if (cleanPacket.isEmpty()) continue;

        QJsonParseError parseError;
        QJsonDocument doc = QJsonDocument::fromJson(cleanPacket, &parseError);

        if (parseError.error != QJsonParseError::NoError) {
            log("Parsing Warning: Dropped malformed segment: " + QString(cleanPacket));
            continue;
        }

        QJsonObject json = doc.object();
        int messageType = json["type"].toInt();


        //  CLIENT REGISTRATION (ADMIN APPROVAL HERE)

        if (messageType == CLIENT_REGISTRATION) {

            QString name = json["username"].toString();
            int clientPubKey = json["public_key"].toInt();

            if (name.isEmpty()) continue;

            // 🔐 ADMIN APPROVAL
            if (!onNewAuthRequest(socket, name)) {
                log("❌ Rejected: " + name);
                socket->disconnectFromHost();
                return;
            }

            // ✅ REGISTER USER
            if (UserRegistry.contains(name)) {
                ClientInfo *oldInfo = UserRegistry.take(name);
                if (oldInfo) {
                    socketToUsername.remove(oldInfo->socket);
                    delete oldInfo;
                }
            }

            ClientInfo *info = new ClientInfo();
            info->username  = name;
            info->socket    = socket;
            info->publicKey = clientPubKey;

            UserRegistry[name] = info;
            socketToUsername[socket] = name;

            log(QString("✔ Registered: %1").arg(name));

            if (leaderUsername.isEmpty() || !UserRegistry.contains(leaderUsername)) {
                leaderUsername = name;
                log("👑 Leader: " + leaderUsername);
            }

            refreshUserDisplay();
            sendLeaderUpdatedDirectory();
            sendUserList();//send the data when connecting
        }


        // 💬 NORMAL MESSAGE

        else if (messageType == NORMAL_MESSAGE) {

            if (!socketToUsername.contains(socket)) {
                log("⚠ Unauthorized message blocked");
                continue;
            }

            QByteArray forwardPacket =
                QJsonDocument(json).toJson(QJsonDocument::Compact) + "\n";

            for (auto client : UserRegistry.values()) {
                if (client->socket != socket) {
                    client->socket->write(forwardPacket);
                }
            }

            log("[CHAT] Message relayed");
        }

        //  KEY DISTRIBUTION
        else if (messageType == KEY_DISTRIBUTION) {

            if (!socketToUsername.contains(socket)) {
                log("⚠ Unauthorized key distribution blocked");
                continue;
            }

            int leaderPubKey = json["leader_public_key"].toInt();
            QJsonArray keyPayloads = json["key_payloads"].toArray();

            for (const QJsonValue &val : keyPayloads) {
                QJsonObject payload = val.toObject();
                QString targetUser = payload["target_user"].toString();
                QString encryptedKeyHex = payload["encrypted_key"].toString();

                if (UserRegistry.contains(targetUser)) {
                    QJsonObject dispatchPacket;
                    dispatchPacket["type"] = KEY_DISTRIBUTION;
                    dispatchPacket["leader_public_key"] = leaderPubKey;
                    dispatchPacket["encrypted_key"] = encryptedKeyHex;

                    UserRegistry[targetUser]->socket->write(
                        QJsonDocument(dispatchPacket).toJson(QJsonDocument::Compact) + "\n"
                        );
                }
            }

            log("🔑 Keys distributed");
        }
    }
}
// ─── Leader directory push ─────────────────────────────────────────────────────

void MainWindow::sendLeaderUpdatedDirectory()
{
    if (leaderUsername.isEmpty() || !UserRegistry.contains(leaderUsername)) {
        log("Directory sync skipped: leader missing.");
        return;
    }

    QJsonObject packet104;
    packet104["type"] = DIRECTORY_UPDATE;

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
//defining slots
void MainWindow::Client_Disconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (!socket) return;

    QString disconnectedUser = socketToUsername.take(socket);

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
        sendUserList();//send when user is out
    } else {
        socket->deleteLater();
    }
}

// ─── Send button ──────────────────────────────────────────────────────────────

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
