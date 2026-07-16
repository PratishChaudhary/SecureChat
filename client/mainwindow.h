#ifndef CLIENTMAINWINDOW_H
#define CLIENTMAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QString>
#include "QtEncryptionEngine.h"
#include <QTime>
#include "systemlogdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ClientMainWindow; }
QT_END_NAMESPACE

class ClientMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientMainWindow(QWidget *parent = nullptr);
    ~ClientMainWindow();

    // Called from main() after username is collected
    void setSessionUsername(const QString& username,const QString& HAddr);

private slots:
    void on_sendButton_clicked();
    void onSocketReadyRead();
    void onSocketDisconnected();
    void addmessage(const QString &username,const QString &message , bool check);


    void on_pushButton_SystemLog_clicked();

private:
    Ui::ClientMainWindow *ui;
    QTcpSocket *socket;
    QtEncryptionEngine cryptoEngine;
    QString myUsername;
    // Whether the room key is ready for encrypting/decrypting chat
    bool roomKeyReady = false;
    SystemLogDialog *systemlog;
};

#endif // CLIENTMAINWINDOW_H