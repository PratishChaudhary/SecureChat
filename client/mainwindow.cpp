#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QMessageBox>

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

// ─── Called by main() right after the window is constructed ──────────────────
void ClientMainWindow::setSessionUsername(const QString& username)
{
    myUsername = username;
    setWindowTitle("SecureChat — " + myUsername);
    ui->label_IdentityDisplay->setText("Logged in as:  " + myUsername);
    ui->textEdit_Log->append("Connecting to 127.0.0.1:8080...");

    socket->connectToHost("127.0.0.1", 8080);

    if (!socket->waitForConnected(3000)) {
        ui->textEdit_Log->append("❌  Cannot reach server. Start the Server app first, then relaunch the client.");
        ui->label_IdentityDisplay->setText("Logged in as:  " + myUsername + "  |  ⚠ Offline");
    } else {
        ui->textEdit_Log->append("✔  Connected. Waiting for handshake...");
    }
}

// ─── All incoming packets from the server ────────────────────────────────────
void ClientMainWindow::onSocketReadyRead()
{
    QByteArray rawStream = socket->readAll();

    // Split on newlines — our framing boundary (same convention as the server)
    const QList<QByteArray> packets = rawStream.split('\n');

    for (const QByteArray& raw : packets) {
        QByteArray clean = raw.trimmed();
        if (clean.isEmpty()) continue;

        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(clean, &err);
        if (err.error != QJsonParseError::NoError || doc.isNull()) {
            ui->textEdit_Log->append("⚠  Dropped malformed packet.");
            continue;
        }

        QJsonObject json = doc.object();
        int type = json["type"].toInt();

        // ── Packet 101: Server sends DH parameters ────────────────────────
        if (type == 101) {
            long long serverP = json["p_value"].toVariant().toLongLong();
            long long serverG = json["g_value"].toVariant().toLongLong();

            int myPubKey = cryptoEngine.generatePublicKey(serverP, serverG);

            QJsonObject reg;
            reg["type"]       = 102;
            reg["username"]   = myUsername;
            reg["public_key"] = myPubKey;

            socket->write(QJsonDocument(reg).toJson(QJsonDocument::Compact) + "\n");
            ui->textEdit_Log->append(QString("🔑  DH handshake done. Public key: %1").arg(myPubKey));
        }

        // ── Packet 104: We are the room leader — generate & distribute keys ─
        else if (type == 104) {
            ui->textEdit_Log->append("⭐  You are the room leader. Generating session keys...");
            QJsonArray peers = json["participants"].toArray();

            if (peers.isEmpty()) {
                // Leader is alone; generate a key for ourselves so we can chat
                // when peers join later the key will be re-sent automatically.
                ui->textEdit_Log->append("ℹ  No peers yet. Key will be distributed when others join.");
                // Generate room key locally so leader can still type when alone
                cryptoEngine.generateRawRoomKey();
                roomKeyReady = true;
                ui->sendButton->setEnabled(true);
                ui->lineEdit_ChatMsg->setEnabled(true);
                ui->lineEdit_ChatMsg->setPlaceholderText("Type a message...");
            } else {
                QByteArray packet105 = cryptoEngine.handleLeaderKeyGeneration(peers);
                socket->write(packet105 + "\n");
                roomKeyReady = true;
                ui->sendButton->setEnabled(true);
                ui->lineEdit_ChatMsg->setEnabled(true);
                ui->lineEdit_ChatMsg->setPlaceholderText("Type a message...");
                ui->textEdit_Log->append(QString("✔  Session keys sent to %1 peer(s).").arg(peers.size()));
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
            ui->textEdit_Log->append("🔒  Session key received. Chat is now encrypted.");
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

    if (!roomKeyReady) {
        ui->textEdit_Log->append("⚠  Key not ready yet — please wait.");
        return;
    }

    QString line = QString("[%1]: %2").arg(myUsername, text);

    QByteArray cipherHex = cryptoEngine.encryptChatMessage(line);

    QJsonObject pkt;
    pkt["type"]    = 1;
    pkt["payload"] = QString(cipherHex);

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
    ui->textEdit_Log->append("❌  Connection closed by server.");
    ui->label_IdentityDisplay->setText(ui->label_IdentityDisplay->text() + "  |  ⚠ Disconnected");
}