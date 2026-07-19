#include "bubblemessage.h"
#include "ui_bubblemessage.h"

//basically stores the value that it get from client (its like a structure we use it in client)
BubbleMessage::BubbleMessage(const QString &username , const QString &message , const QString &time,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BubbleMessage)
{
    ui->setupUi(this);
    ui->Name->setText(username);
    ui->Message->setText(message);
    ui->Time->setText(time);
    ui->Message->setMaximumWidth(280);
    adjustSize();
}

BubbleMessage::~BubbleMessage()
{
    delete ui;
}
