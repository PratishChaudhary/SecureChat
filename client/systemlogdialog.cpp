#include "systemlogdialog.h"
#include "ui_systemlogdialog.h"
#include <QTime>
SystemLogDialog::SystemLogDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SystemLogDialog)
{
    ui->setupUi(this);

}

void SystemLogDialog::addlog(const QString &log)
{
    QString time  =  QTime::currentTime().toString("hh:mm:ss");
    QString LogEntry = QString("[%1] %2").arg(time,log);

    ui->systemLog->addItem(LogEntry);
    ui->systemLog->scrollToBottom();
}

SystemLogDialog::~SystemLogDialog()
{
    delete ui;
}
