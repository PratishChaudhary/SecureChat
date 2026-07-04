#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QString>
#include <QMutex>

enum PacketType {
    LEADER_KEY_SETUP = 101,
    CLIENT_REGISTRATION = 102,
    NORMAL_MESSAGE = 1,
    DIRECTORY_UPDATE = 104,
    KEY_DISTRIBUTION = 105
};

private:
    QMutex registryMutex;
    QMap<QTcpSocket*, QString> socketToUsername; // Reverse lookup
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct ClientInfo {
    QString username;
    QTcpSocket *socket = nullptr;
    int publicKey = 0;
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
    // void on_push_button_Send_clicked();
    void Client_Disconnected();

private:
    void Add_New_Client_Connection(QTcpSocket *socket);
    void sendLeaderUpdatedDirectory();

    // Rebuilds listWidget_Users, comboBox_Client_List, and the status bar
    void refreshUserDisplay();

    // Appends to the main center log (textEdit_Client_Messages)
    void log(const QString &text);

    // Appends a timestamped line to the left-panel event log (textEdit_Event_Log)
    void logEvent(const QString &text);

private:
    Ui::MainWindow *ui;
    QTcpServer     *TCP_Server;

    QMap<QString, ClientInfo *> UserRegistry;
    QString leaderUsername;

    const int DH_P = 23;
    const int DH_G = 5;
};

#endif // MAINWINDOW_H
