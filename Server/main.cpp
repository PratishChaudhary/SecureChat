#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
     // Create the Qt application object.
    QApplication a(argc, argv);
    // Create the main application window.
     MainWindow w;
     // Display the main window.
    w.show();
    return a.exec();
}
