#ifndef QTENCRYPTIONENGINE_H
#define QTENCRYPTIONENGINE_H

#include <QString>
#include <QByteArray>
#include <QMap>
#include <QRandomGenerator>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class QtEncryptionEngine {
private:
    long long p = 0;
    long long g = 0;
    long long privateKey;
    long long publicKey = 0;
    QByteArray roomKey; // holds the master key for the active room chat

public:
    QtEncryptionEngine() {
        // secure random private key gen
        privateKey = QRandomGenerator::global()->bounded(1,100);
    }

    // creates a random 26-byte pool for symmetric encryption
    QByteArray generateRawRoomKey() {
        roomKey.clear();
        const char pool[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-*/!@#$%^&*()_=";
        int poolSize = sizeof(pool) - 1;
        for (int i = 0; i < 26; i++) {
            roomKey.append(pool[QRandomGenerator::global()->bounded(poolSize)]);
        }
        return roomKey;
    }

    long long modPow(long long base, long long exp, long long mod) {
        if (mod <= 0) return 0;
        long long result = 1;
        base = base % mod;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int generatePublicKey(long long P, long long G) {
        this->p = P;
        this->g = G;
        this->publicKey = modPow(g, privateKey,p); // basic dh math setup
        return publicKey;
    }

    // xor logic loop to encrypt msgs without crashing out of array bounds
    QByteArray encryptChatMessage(const QString& plaintextMessage) {
        QByteArray cleanBytes = plaintextMessage.toUtf8();
        QByteArray cipherText;
        for (int i = 0; i < cleanBytes.size(); i++) {
            cipherText.append(cleanBytes[i] ^ roomKey[i % roomKey.size()]);
        }
        return cipherText.toHex(); // hex string format is cleaner over sockets
    }

    QString decryptChatMessage(const QByteArray& hexCipherMessage) {
        QByteArray cipherBytes = QByteArray::fromHex(hexCipherMessage);
        QByteArray plainText;
        for (int i = 0; i < cipherBytes.size(); i++) {
            plainText.append(cipherBytes[i] ^ roomKey[i % roomKey.size()]);
        }
        return QString::fromUtf8(plainText);
    }

    // ran by room master to deal out the keys to everyone else (msg 104 handler)
    QByteArray handleLeaderKeyGeneration(const QJsonArray& participantsList) {
        this->roomKey = generateRawRoomKey();

        QJsonObject response105;
        response105["type"] = 105;
        response105["leader_public_key"] = (int)this->publicKey;

        QJsonArray payloadBundle;

        for (int i = 0; i < participantsList.size(); ++i) {
            QJsonObject peer = participantsList[i].toObject();
            QString targetName = peer["username"].toString();
            int peerPubKey = peer["public_key"].toInt();

            // compute shared secret value
            long long secret = modPow(peerPubKey, privateKey,p);

            // wrap master key in a secret container using peer secret
            QByteArray encryptedBox;
            for (int k = 0; k < roomKey.size(); k++) {
                encryptedBox.append(roomKey[k] ^ (secret & 0xFF));
            }

            QJsonObject individualContainer;
            individualContainer["target_user"] = targetName;
            individualContainer["encrypted_key"] = QString(encryptedBox.toHex());
            payloadBundle.append(individualContainer);
        }

        response105["key_payloads"] = payloadBundle;
        return QJsonDocument(response105).toJson(QJsonDocument::Compact);
    }

    // unpacking structural payload dropped from master client (msg 105 handler)
    void setRoomKeyFromLeaderPayload(int leaderPubKey, const QString& hexEncryptedRoomKey) {
        long long secret = modPow(leaderPubKey, privateKey,p);
        QByteArray encryptedBlob = QByteArray::fromHex(hexEncryptedRoomKey.toUtf8());

        roomKey.clear();
        for (int i = 0; i < encryptedBlob.size(); i++) {
            roomKey.append(encryptedBlob[i] ^ (secret & 0xFF));
        }
    }
};

#endif // QTENCRYPTIONENGINE_H