#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
     // Create the Qt application object.
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
