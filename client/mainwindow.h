#ifndef CLIENTMAINWINDOW_H
#define CLIENTMAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QString>
#include "QtEncryptionEngine.h"
#include <QTime>

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
    void setSessionUsername(const QString& username);

private slots:
    void on_sendButton_clicked();
    void onSocketReadyRead();
    void onSocketDisconnected();
    void addlog(const QString &message);
    // void addmessage(const QString &message);

private:
    Ui::ClientMainWindow *ui;
    QTcpSocket *socket;
    QtEncryptionEngine cryptoEngine;
    QString myUsername;
    // Whether the room key is ready for encrypting/decrypting chat
    bool roomKeyReady = false;
};

#endif // CLIENTMAINWINDOW_H