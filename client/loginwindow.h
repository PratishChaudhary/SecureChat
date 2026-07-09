#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class mainwindow1;
}

class mainwindow1 : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindow1(QWidget *parent = nullptr);
    ~mainwindow1();

private slots:
    void on_Login_clicked();

private:
    Ui::mainwindow1 *ui;

};

#endif // LOGINWINDOW_H
