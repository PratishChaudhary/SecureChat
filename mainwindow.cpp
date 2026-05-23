#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TCP_Server = new QTcpServer(this);
    connect(TCP_Server, &QTcpServer::newConnection,this, &MainWindow::newConnection);
    if(TCP_Server->listen(QHostAddress::Any,8080)){
        QMessageBox::information(this,"SecureServer","Server has started");
    }
    else{
         QMessageBox::information(this,"SecureServer","Server start failed!");
    }

}
MainWindow::~MainWindow()
{
    delete ui;
}
//checks for all the available new connections and always listens for a new client
void MainWindow::newConnection(){
    while (TCP_Server->hasPendingConnections()){
        Add_New_Client_Connection(TCP_Server->nextPendingConnection());
    }
}
//used to read data from the clients
void MainWindow::Read_Data_From_Socket()
{
    QTcpSocket *socket = reinterpret_cast<QTcpSocket*>(sender());

    QByteArray Message_From_Server = socket->readAll();

    QString ClientName = QString::number(socket->socketDescriptor());

    QString Message = "Client : " + QString::number(socket->socketDescriptor()) +"::"+QString::fromStdString(Message_From_Server.toStdString());

    ui->textEdit_Client_Messages->append(Message);

}
//used to assign new clients its slots and signals
void MainWindow::Add_New_Client_Connection(QTcpSocket* socket)
{
    Client_Connection_List.append(socket);
    connect(socket,SIGNAL(readyRead()),this,SLOT(Read_Data_From_Socket()));
    ui->comboBox_Client_List->addItem(QString::number((socket->socketDescriptor())));
    qDebug() << "newConnection triggered!";
    QString Client = "Client: " + QString::number(socket->socketDescriptor()) + "Connected to the server.";
    ui->textEdit_Client_Messages->append(Client);
}


void MainWindow::on_push_button_Send_clicked()
{
    QString Message_For_Client = ui->lineEdit_send_message->text();
    QString Reciever = ui->comboBox_Client_List->currentText();

    //sends message to all who are connected to this server.
    if( ui->combobox2_Send_Message_type->currentText() == "All"){
        foreach(QTcpSocket *socket,Client_Connection_List){
            socket->write(Message_For_Client.toStdString().c_str());
        }
    }
    else
    {
        //sends messages to selected connected clients
        foreach(QTcpSocket *socket,Client_Connection_List){
            if(socket->socketDescriptor() == Reciever.toLongLong()){
                socket->write(Message_For_Client.toStdString().c_str());
            }
        }
    }

}



