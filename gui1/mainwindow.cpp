#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QWidget>
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("message");
    this->setFixedSize(852,914);

    ui->Message_show->setReadOnly(true); // won't allw for tet

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Message_returnPressed() //Display the text to the Message_Show
{
    QString hold_message = ui->Message->text();

    ui->Message_show->append("You: " + hold_message);
    ui->Message->clear();

}


