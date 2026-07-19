#ifndef SERVERDISCOVERER_H
#define SERVERDISCOVERER_H

#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QJsonDocument>
#include <QJsonObject>

class ServerDiscoverer : public QObject {
    Q_OBJECT
private:
    QUdpSocket *udpSocket;

signals:
    // Emits the structured data ready for THE UI
    void serverFound(const QString &name, const QString &ip, quint16 port);

public:
    ServerDiscoverer(QObject *parent = nullptr) : QObject(parent) {
        udpSocket = new QUdpSocket(this);
        udpSocket->bind(9999, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
        connect(udpSocket, &QUdpSocket::readyRead, this, &ServerDiscoverer::processPendingDatagrams);
    }

private slots:
    void processPendingDatagrams() {
        while (udpSocket->hasPendingDatagrams()) {
            QNetworkDatagram datagram = udpSocket->receiveDatagram();

            // 1. Convert the raw network data into a JSON document
            QJsonDocument doc = QJsonDocument::fromJson(datagram.data());

            if (!doc.isNull() && doc.isObject()) {
                QJsonObject obj = doc.object();
                QString name = obj["serverName"].toString();
                quint16 port = obj["port"].toInt();
                QString ip = obj["ipAddress"].toString();
                // Clean up IPv6-mapped IPv4 styling (e.g., "::ffff:192.168.1.5" -> "192.168.1.5")
                if (ip.startsWith("::ffff:")) {
                    ip = ip.mid(7);
                } else if (ip == "::1") {
                    ip = "127.0.0.1"; // Clean up local loopback notation
                }

                // Fires off to mainwindow1
                emit serverFound(name, ip, port);
            }
        }
    }
};
#endif // SERVERDISCOVERER_H
