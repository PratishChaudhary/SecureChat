#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QMessageBox>
//boilerplate codes and ui connections
ClientMainWindow::ClientMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientMainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::readyRead,    this, &ClientMainWindow::onSocketReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &ClientMainWindow::onSocketDisconnected);

    // Disable send until the room key is negotiated
    ui->sendButton->setEnabled(false);
    ui->lineEdit_ChatMsg->setEnabled(false);
    ui->lineEdit_ChatMsg->setPlaceholderText("Waiting for encryption key...");
}

ClientMainWindow::~ClientMainWindow()
{
    delete ui;
}

void ClientMainWindow::addlog(const QString &message)
{
    QString time  =  QTime::currentTime().toString("hh:mm:ss");
    QString LogEntry = QString("[%1] %2").arg(time).arg(message);

    ui->systemLog->addItem(LogEntry);
    ui->systemLog->scrollToBottom();
}

// void ClientMainWindow::addmessage(const QString &message)
// {

// }


// ─── Called by main() right after the window is constructed ──────────────────
void ClientMainWindow::setSessionUsername(const QString& username)
{
    //takes username and sets myUsername 
    myUsername = username;
    setWindowTitle("SecureChat — " + myUsername);
    ui->label_IdentityDisplay->setText(myUsername);
    addlog("Connecting to 127.0.0.1:8080...");
    // ui->textEdit_Log->append("Connecting to 127.0.0.1:8080...");

    //calls connectToHost for the QTcpSocket object.
    socket->connectToHost("127.0.0.1", 8080);

    //checking if the server is listening for new clients.
    if (!socket->waitForConnected(3000)) {
        addlog("❌  Cannot reach server. Start the Server app first, then relaunch the client.");
        // ui->textEdit_Log->append("❌  Cannot reach server. Start the Server app first, then relaunch the client.");
        addlog("Logged in as:  " + myUsername + "  |  ⚠ Offline");
        // ui->label_IdentityDisplay->setText("Logged in as:  " + myUsername + "  |  ⚠ Offline");
    } else {
        addlog("✔  Connected. Waiting for handshake...");
        // ui->textEdit_Log->append("✔  Connected. Waiting for handshake...");
    }
}

// ─── All incoming packets from the server ────────────────────────────────────
void ClientMainWindow::onSocketReadyRead()
{
    //reading data inside the socket.
    QByteArray rawStream = socket->readAll();

    // Split on newlines — our framing boundary (same convention as the server)
    const QList<QByteArray> packets = rawStream.split('\n');
    //looping through the packets
    for (const QByteArray& raw : packets) {
        QByteArray clean = raw.trimmed();
        if (clean.isEmpty()) continue;
        
        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(clean, &err);
        //checking for parsing errors:
        if (err.error != QJsonParseError::NoError || doc.isNull()) {
            addlog("⚠  Dropped malformed packet.");
            // ui->textEdit_Log->append("⚠  Dropped malformed packet.");
            continue;
        }
        //creating a json object to store data.
        QJsonObject json = doc.object();
        int type = json["type"].toInt();

        // ── Packet 101: Server sends DH parameters ────────────────────────
        if (type == 101) {
            long long serverP = json["p_value"].toVariant().toLongLong();
            long long serverG = json["g_value"].toVariant().toLongLong();
            //creating private public key pair.
            int myPubKey = cryptoEngine.generatePublicKey(serverP, serverG);
            
            QJsonObject reg;
            reg["type"]       = 102;
            reg["username"]   = myUsername;
            reg["public_key"] = myPubKey;
            //sending back public key to enable secrete messagaing.
            socket->write(QJsonDocument(reg).toJson(QJsonDocument::Compact) + "\n");
            addlog(QString(QString("🔑  DH handshake done. Public key: %1").arg(myPubKey)));
            // ui->textEdit_Log->append(QString("🔑  DH handshake done. Public key: %1").arg(myPubKey));
        }

        // ── Packet 104: We are the room leader — generate & distribute keys ─
        else if (type == 104) {
            addlog("⭐  You are the room leader. Generating session keys...");
            // ui->textEdit_Log->append("⭐  You are the room leader. Generating session keys...");
            QJsonArray peers = json["participants"].toArray();

            if (peers.isEmpty()) {
                // Leader is alone; generate a key for ourselves so we can chat
                // when peers join later the key will be re-sent automatically.
                addlog("ℹ  No peers yet. Key will be distributed when others join.");
                // ui->textEdit_Log->append("ℹ  No peers yet. Key will be distributed when others join.");
                // Generate room key locally so leader can still type when alone
                cryptoEngine.generateRawRoomKey();
                roomKeyReady = true;
                ui->sendButton->setEnabled(true);
                ui->lineEdit_ChatMsg->setEnabled(true);
                ui->lineEdit_ChatMsg->setPlaceholderText("Type a message...");
            } else {
                //sending encrypted keys to all the clients using the public key.
                QByteArray packet105 = cryptoEngine.handleLeaderKeyGeneration(peers);
                socket->write(packet105 + "\n");
                roomKeyReady = true;
                ui->sendButton->setEnabled(true);
                ui->lineEdit_ChatMsg->setEnabled(true);
                ui->lineEdit_ChatMsg->setPlaceholderText("Type a message...");
                addlog(QString("✔  Session keys sent to %1 peer(s).").arg(peers.size()));
                // ui->textEdit_Log->append(QString("✔  Session keys sent to %1 peer(s).").arg(peers.size()));
            }
        }

        // ── Packet 105: We received our encrypted session key from the leader ─
        else if (type == 105) {
            int  leaderPub      = json["leader_public_key"].toInt();
            QString encKeyHex   = json["encrypted_key"].toString();

            cryptoEngine.setRoomKeyFromLeaderPayload(leaderPub, encKeyHex);
            roomKeyReady = true;
            ui->sendButton->setEnabled(true);
            ui->lineEdit_ChatMsg->setEnabled(true);
            ui->lineEdit_ChatMsg->setPlaceholderText("Type a message...");
            addlog("🔒  Session key received. Chat is now encrypted.");
            // ui->textEdit_Log->append("🔒  Session key received. Chat is now encrypted.");
        }

        // ── Packet 1: Incoming chat message ───────────────────────────────
        else if (type == 1) {
            QString payload = json["payload"].toString();

            if (roomKeyReady) {
                // Payload is hex-encoded ciphertext — decrypt it
                QString plaintext = cryptoEngine.decryptChatMessage(payload.toUtf8());
                ui->textEdit_ChatDisplay->append(plaintext);
            } else {
                // No key yet (e.g. server admin message sent before key exchange)
                ui->textEdit_ChatDisplay->append("[unencrypted] " + payload);
            }
        }
    }
}

// ─── Send button ─────────────────────────────────────────────────────────────
void ClientMainWindow::on_sendButton_clicked()
{
    QString text = ui->lineEdit_ChatMsg->text().trimmed();
    if (text.isEmpty()) return;
    //checks if the encryption is done
    if (!roomKeyReady) {
        addlog("⚠  Key not ready yet — please wait.");
        // ui->textEdit_Log->append("⚠  Key not ready yet — please wait.");
        return;
    }
    //combining username and the message
    QString line = QString("[%1]: %2").arg(myUsername, text);
    //encrypting the line (hex encoding)
    QByteArray cipherHex = cryptoEngine.encryptChatMessage(line);

    //packing into a single json packet
    QJsonObject pkt;
    //using Packet : 1
    pkt["type"]    = 1;
    pkt["payload"] = QString(cipherHex);
    //sending to server
    socket->write(QJsonDocument(pkt).toJson(QJsonDocument::Compact) + "\n");

    // Show our own message locally (we won't receive our own echo from the server)
    ui->textEdit_ChatDisplay->append(line);
    ui->lineEdit_ChatMsg->clear();
}

// ─── Server disconnected ─────────────────────────────────────────────────────
void ClientMainWindow::onSocketDisconnected()
{
    roomKeyReady = false;
    ui->sendButton->setEnabled(false);
    ui->lineEdit_ChatMsg->setEnabled(false);
    ui->lineEdit_ChatMsg->setPlaceholderText("Disconnected from server.");
    addlog("❌  Connection closed by server.");
    // ui->textEdit_Log->append("❌  Connection closed by server.");
    ui->label_IdentityDisplay->setText(ui->label_IdentityDisplay->text() + "  |  ⚠ Disconnected");
}
