#ifndef SYSTEMLOGDIALOG_H
#define SYSTEMLOGDIALOG_H

#include <QDialog>

namespace Ui {
class SystemLogDialog;
}

class SystemLogDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SystemLogDialog(QWidget *parent = nullptr);
    void addlog(const QString &log);
    ~SystemLogDialog();

private:
    Ui::SystemLogDialog *ui;
};

#endif // SYSTEMLOGDIALOG_H
