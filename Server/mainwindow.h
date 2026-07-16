#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QString>
#include <QMutex>
#include <QUdpSocket>
#include <QTimer>
#include "ServerDiscoveryBeacon.h"

enum PacketType {
    LEADER_KEY_SETUP = 101,
    CLIENT_REGISTRATION = 102,
    NORMAL_MESSAGE = 1,
    DIRECTORY_UPDATE = 104,
    KEY_DISTRIBUTION = 105,
    USER_LIST = 106
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct ClientInfo {
    QString username;
    QTcpSocket *socket = nullptr;
    int publicKey = 0;

    ~ClientInfo() {
        if (socket) {
            socket->disconnect();
            socket->close();
            socket->deleteLater();
        }
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void newConnection();
    void Read_Data_From_Socket();
    void Client_Disconnected();

private:
    bool onNewAuthRequest(QTcpSocket* socket, QString username);
    void Add_New_Client_Connection(QTcpSocket *socket);
    void sendLeaderUpdatedDirectory();
    void refreshUserDisplay();
    void log(const QString &text);
    void logEvent(const QString &text);
    void sendUserList();//this send the list to the client
private:
    Ui::MainWindow *ui;
    QTcpServer *TCP_Server;

    QMap<QString, ClientInfo *> UserRegistry;
    QString leaderUsername;

    QMap<QTcpSocket*, QString> socketToUsername; // moved inside class

    const int DH_P = 23;
    const int DH_G = 5;
    QTcpServer *tcpServer;
    ServerDiscoveryBeacon *discoveryBeacon;
};

#endif // MAINWINDOW_H