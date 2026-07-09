#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QWidget>
#include <QLineEdit>
#include <QIcon>
#include <QAction>
#include "ui_mainwindow.h"
mainwindow1::mainwindow1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainwindow1)
{

    ui->setupUi(this);
    this->QWidget::setWindowTitle("Secure Chat");

}

mainwindow1::~mainwindow1(){}

void mainwindow1::on_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString HAddr = ui->lineEdit_Port->text();
    int Port = ui->lineEdit_Port->text().toInt();
    ClientMainWindow *client = new ClientMainWindow();
    if(!username.isEmpty())
    {
    //genius work with the port
        //using the process of non model method
        hide();
        client->setSessionUsername(username);
        client->show();
        close();

    }
    else QMessageBox::information(this , "Noob" , "uh , No username entered");

}
