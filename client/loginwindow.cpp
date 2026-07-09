#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "clientmainwindow.h"
#include <QMessageBox>
#include <QWidget>
#include <QLineEdit>
#include <QIcon>
#include <QAction>
mainwindow1::mainwindow1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainwindow1)
{

    ui->setupUi(this);
    this->QWidget::setWindowTitle("Secure Chat");

}

mainwindow1::~mainwindow1()
{
    delete ui;
}

void mainwindow1::on_Login_clicked()
{
    QString username = ui->lineEdit_username->text().trimmed();
    QString HAddr = ui->lineEdit_Port->text().trimmed();
    if (!username.isEmpty())
    {
        ClientMainWindow *client = new ClientMainWindow();
        client->setAttribute(Qt::WA_DeleteOnClose);
        client->setSessionUsername(username,HAddr);
        client->show();
        close();
    }
    else
    {
        QMessageBox::information(this , "Noob" , "uh , No username entered");
    }
}
