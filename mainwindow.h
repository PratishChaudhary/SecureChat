#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMainWindow>
#include <QTcpServer>
#include <QMessageBox>
#include <QByteArray>
#include <QList>
#include <QString>
#include <QLabel>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void newConnection();
    void Read_Data_From_Socket();
    void on_push_button_Send_clicked();

private:
    void Add_New_Client_Connection(QTcpSocket* socket);
private:
    Ui::MainWindow *ui;
    QTcpServer *TCP_Server;
    QList<QTcpSocket*> Client_Connection_List;

};
#endif // MAINWINDOW_H
