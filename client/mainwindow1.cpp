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
    QPixmap pix(":/images/images.png");
    ui->Images->setPixmap(pix);
    ui->Images->setAlignment(Qt::AlignCenter);
    ui->Images->setPixmap(pix.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    //holder
    // ui->Over->setStyleSheet(
    //     "Frame{"
    //     "backgound-color:#0A0A0A;"
    //     "border:2px sold white;"
    //     "}");
    ui->lineEdit_username->setPlaceholderText("username");
    ui->lineEdit_username->setStyleSheet(
       "QLineEdit{"
        "placeholder-text-color:white;"
        "font-size: 20px;"
        "border:none;"
        "border-bottom:2px solid #00CFE8;"
        "color:white;"
        "}"
        );

    ui->lineEdit_Port->setPlaceholderText("port");
    ui->lineEdit_Port->setStyleSheet(
        "QLineEdit{"
        "placeholder-text-color:white;"
        "font-size:20px;"
        "border:none;"
        "border-bottom:2px solid #00CFE8;"
        "color:white;"
        "}"
        );
    //for user name

    QPixmap image_username(":/images/icon.png");
    ui->label_image->setPixmap(image_username);
    ui->label_image->setAlignment(Qt::AlignLeft);
    ui->label_image->setPixmap(image_username.scaled(90,60,Qt::KeepAspectRatio , Qt::SmoothTransformation));

    //for port
    QPixmap image_port(":/images/port.png");
    ui->label_image_2->setPixmap(image_port);
    ui->label_image_2->setPixmap(image_port.scaled(90,60,Qt::KeepAspectRatio , Qt::SmoothTransformation));



    // QIcon Icon(":/images/icon.png");
    // ui->lineEdit_username->addAction(Icon , QLineEdit::LeadingPosition);



}

mainwindow1::~mainwindow1(){}

void mainwindow1::on_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
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
