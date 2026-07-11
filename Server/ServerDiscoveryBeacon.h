// ServerDiscoveryBeacon.h
#pragma once
#include <QObject>
#include <QUdpSocket>
#include <QTimer>
#include <QNetworkInterface>
#include <QJsonDocument>
#include <QJsonObject>

class ServerDiscoveryBeacon : public QObject {
    Q_OBJECT
private:
    QUdpSocket *udpSocket;
    QTimer *broadcastTimer;
    quint16 tcpListenPort;

    // Helper function to grab the server's real active IP address
    QString getActiveServerIp() {
        QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
        for (const QNetworkInterface &interface : interfaces) {
            // Must be up and actively running
            if (!interface.flags().testFlag(QNetworkInterface::IsUp) ||
                !interface.flags().testFlag(QNetworkInterface::IsRunning)) {
                continue;
            }

            for (const QNetworkAddressEntry &entry : interface.addressEntries()) {
                QHostAddress ip = entry.ip();
                // Filter out loopback and look for a standard IPv4 address
                if (!ip.isLoopback() && ip.protocol() == QAbstractSocket::IPv4Protocol) {
                    return ip.toString();
                }
            }
        }
        return "127.0.0.1"; // Fallback
    }

public:
    ServerDiscoveryBeacon(quint16 serverPort, QObject *parent = nullptr)
        : QObject(parent), tcpListenPort(serverPort)
    {
        udpSocket = new QUdpSocket(this);
        broadcastTimer = new QTimer(this);

        connect(broadcastTimer, &QTimer::timeout, this, &ServerDiscoveryBeacon::sendBeacon);
        broadcastTimer->start(2000); // Send beacon every 2 seconds
    }

private slots:
    void sendBeacon() {
        QString currentIp = getActiveServerIp();

        // Package both values cleanly using JSON
        QJsonObject serverInfo;
        serverInfo["serverName"] = "My Qt Game Server";
        serverInfo["ipAddress"] = currentIp;
        serverInfo["port"] = tcpListenPort;

        QJsonDocument doc(serverInfo);
        QByteArray datagram = doc.toJson(QJsonDocument::Compact);

        // Broadcast on discovery channel 9999
        udpSocket->writeDatagram(datagram, QHostAddress::Broadcast, 9999);
    }
};