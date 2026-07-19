#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
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
    setWindowIcon(QIcon(":/images/images.png"));
    setupDiscovery();
}
void mainwindow1::on_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString address = ui->lineEdit_address->text();
    if((username.isEmpty() && address.isEmpty()))

        QMessageBox::information(this,"Error" , "No username and address entered");
    else if(username.isEmpty())
        QMessageBox::information(this,"Error" , "No username entered");
    else if(address.isEmpty())
        QMessageBox::information(this,"Error" , "No address entered");
    else
    {
        //using the process of non model method
        ClientMainWindow *client = new ClientMainWindow();
        hide();
        client->setSessionUsername(username,address);
        client->show();
        close();
    }
}
void mainwindow1::setupDiscovery() {
    ServerDiscoverer *discoverer = new ServerDiscoverer(this);

    connect(discoverer, &ServerDiscoverer::serverFound, this, [this](const QString &name, const QString &ip, quint16 port){
        QString entryText = QString("%1 (%2:%3)").arg(name, ip).arg(port);

        // Check if we already listed this server to prevent duplicates
        if (ui->listWidget->findItems(entryText, Qt::MatchExactly).isEmpty()) {
            QListWidgetItem *item = new QListWidgetItem(entryText);

            // Store raw data variants in the UI item so it's easy to connect later
            item->setData(Qt::UserRole, ip);
            item->setData(Qt::UserRole + 1, port);

            ui->listWidget->addItem(item);
        }
    });
}

// When the user double-clicks an item in the list:
void mainwindow1::on_listWidget_itemDoubleClicked(QListWidgetItem *item) {
    QString targetIp = item->data(Qt::UserRole).toString();
    quint16 targetPort = item->data(Qt::UserRole + 1).toUInt();

    // Pass these directly to your QTcpSocket!
    ui->lineEdit_address->setText(targetIp);
}


mainwindow1::~mainwindow1(){}


