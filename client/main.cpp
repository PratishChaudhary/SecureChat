#include "mainwindow.h"
#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>
#include "mainwindow1.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    mainwindow1 login;
    login.show();



    // bool ok = false;
    // QString username = QInputDialog::getText(
    //     nullptr,
    //     "SecureChat — Identity Setup",
    //     "Enter your username:",
    //     QLineEdit::Normal,
    //     "",
    //     &ok
    // );

    // if (!ok || username.trimmed().isEmpty()) {
    //     QMessageBox::critical(nullptr, "Aborted", "A username is required to join the chat.");
    //     return 0;
    // }

    // ClientMainWindow window;
    // window.setSessionUsername(username.trimmed());
    // window.show();

    return app.exec();
}   