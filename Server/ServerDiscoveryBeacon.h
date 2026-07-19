#ifndef SERVERDISCOVERYBEACON_H
#define SERVERDISCOVERYBEACON_H

#include <QObject>
#include <QUdpSocket>
#include <QTimer>
#include <QNetworkInterface>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
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
                    qDebug()<<haddr;
                    return haddr;
                }
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
        // qDebug()<<"boom";
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

#endif

