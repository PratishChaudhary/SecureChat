// -----------------------------------------------------------------------------
// main.cpp
// Entry point of the application.
// Creates the QApplication object, initializes the main window,
// and starts the Qt event loop.
// -----------------------------------------------------------------------------
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
     // Create the Qt application object.
    QApplication app(argc, argv);
    // Create the main application window.
     MainWindow mainWindow;
     // Display the main window.
    mainWindow.show();
      // Start the Qt event loop.
    return app.exec();
}
