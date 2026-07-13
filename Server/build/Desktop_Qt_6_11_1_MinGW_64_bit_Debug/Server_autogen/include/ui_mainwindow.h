/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *rootLayout;
    QFrame *leftPanel;
    QVBoxLayout *leftLayout;
    QLabel *label;
    QLabel *label_UsersHeader;
    QListWidget *listWidget_Users;
    QLabel *label_LogHeader;
    QTextEdit *textEdit_Event_Log;
    QVBoxLayout *centerLayout;
    QComboBox *comboBox_Client_List;
    QLabel *label_ServerStatus;
    QLabel *label_2;
    QTextEdit *textEdit_Client_Messages;
    QFrame *bottomBar;
    QHBoxLayout *bottomLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(980, 640);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setBold(true);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"/* \342\224\200\342\224\200 Base \342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200 */\n"
"QMainWindow, QWidget {\n"
"    background-color: #1c1f27;\n"
"    color: #d4dbe8;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"/* \342\224\200\342\224\200 Left panel \342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342"
                        "\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200 */\n"
"QFrame#leftPanel {\n"
"    background-color: #14171e;\n"
"    border-right: 1px solid #2a2e3d;\n"
"}\n"
"\n"
"/* \342\224\200\342\224\200 Section labels \342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200 */\n"
"QLabel#label_UsersHeader,\n"
"QLabel#label_LogHeader {\n"
"    font-size: 10px;\n"
"    font-weight: bold;\n"
"    letter-spacin"
                        "g: 1px;\n"
"    color: #4a5a72;\n"
"    background: transparent;\n"
"    padding: 0px 4px;\n"
"}\n"
"\n"
"/* \342\224\200\342\224\200 User list widget \342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200 */\n"
"QListWidget#listWidget_Users {\n"
"    background-color: #14171e;\n"
"    border: none;\n"
"    outline: none;\n"
"    font-size: 13px;\n"
"    color: #c8d4e3;\n"
"}\n"
"QListWidget#listWidget_Users::item {\n"
"    padding: 6px 8px;\n"
"    border-bottom: 1px solid #1e2330;\n"
"}\n"
"QListWidget#listWidget_Users::item:selected {\n"
"    background-color: #1e2b20;\n"
"    color: #7ecfb3;\n"
"}\n"
"\n"
"/* \342\224\200\342\224\200 Event log \342"
                        "\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200 */\n"
"QTextEdit#textEdit_Event_Log {\n"
"    background-color: #11131a;\n"
"    border: 1px solid #1e2330;\n"
"    border-radius: 6px;\n"
"    color: #4a8a72;\n"
"    font-family: \"Consolas\", \"Courier New\", monospace;\n"
"    font-size: 11px;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"/* \342\224\200\342\224\200 Center message log \342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200"
                        "\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200 */\n"
"QTextEdit#textEdit_Client_Messages {\n"
"    background-color: #181b23;\n"
"    border: 1px solid #2a2e3d;\n"
"    border-radius: 8px;\n"
"    color: #d4dbe8;\n"
"    font-size: 13px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"/* \342\224\200\342\224\200 Bottom bar \342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200 */\n"
"QFrame#bottomBar {\n"
"    background-color: #14171e"
                        ";\n"
"    border-top: 1px solid #2a2e3d;\n"
"}\n"
"\n"
"QComboBox#comboBox_Client_List,\n"
"QComboBox#combobox2_Send_Message_type {\n"
"    background-color: #1e2330;\n"
"    border: 1px solid #2e3650;\n"
"    border-radius: 6px;\n"
"    color: #c8d4e3;\n"
"    padding: 4px 8px;\n"
"    font-size: 12px;\n"
"    min-height: 32px;\n"
"}\n"
"QComboBox#comboBox_Client_List:hover,\n"
"QComboBox#combobox2_Send_Message_type:hover {\n"
"    border-color: #3d7a5e;\n"
"}\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 20px;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #1e2330;\n"
"    border: 1px solid #2e3650;\n"
"    color: #c8d4e3;\n"
"    selection-background-color: #1e2b20;\n"
"    selection-color: #7ecfb3;\n"
"}\n"
"\n"
"QLineEdit#lineEdit_send_message {\n"
"    background-color: #1e2330;\n"
"    border: 1px solid #2e3650;\n"
"    border-radius: 6px;\n"
"    color: #d4dbe8;\n"
"    padding: 4px 10px;\n"
"    font-size: 13px;\n"
"    min-height: 32px;\n"
"}\n"
"QLineEdit#lineEdi"
                        "t_send_message:focus {\n"
"    border-color: #3d7a5e;\n"
"}\n"
"\n"
"QPushButton#push_button_Send {\n"
"    background-color: #2d5e47;\n"
"    color: #a8e6cc;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 6px 18px;\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"    min-height: 32px;\n"
"}\n"
"QPushButton#push_button_Send:hover {\n"
"    background-color: #3d7a5e;\n"
"}\n"
"QPushButton#push_button_Send:pressed {\n"
"    background-color: #1e4a35;\n"
"}\n"
"\n"
"/* \342\224\200\342\224\200 Status bar \342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200"
                        " */\n"
"QStatusBar {\n"
"    background-color: #11131a;\n"
"    color: #4a6a58;\n"
"    font-size: 11px;\n"
"    border-top: 1px solid #1e2330;\n"
"}\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        rootLayout = new QHBoxLayout(centralwidget);
        rootLayout->setSpacing(0);
        rootLayout->setObjectName("rootLayout");
        rootLayout->setContentsMargins(0, 0, 0, 0);
        leftPanel = new QFrame(centralwidget);
        leftPanel->setObjectName("leftPanel");
        leftPanel->setFrameShape(QFrame::Shape::NoFrame);
        leftLayout = new QVBoxLayout(leftPanel);
        leftLayout->setSpacing(8);
        leftLayout->setObjectName("leftLayout");
        leftLayout->setContentsMargins(10, 12, 10, 10);
        label = new QLabel(leftPanel);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white;\n"
"    font-size: 13pt;\n"
"    font-weight: bold;\n"
"}"));

        leftLayout->addWidget(label);

        label_UsersHeader = new QLabel(leftPanel);
        label_UsersHeader->setObjectName("label_UsersHeader");
        label_UsersHeader->setFont(font);
        label_UsersHeader->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 12px;\n"
"}"));

        leftLayout->addWidget(label_UsersHeader);

        listWidget_Users = new QListWidget(leftPanel);
        listWidget_Users->setObjectName("listWidget_Users");
        listWidget_Users->setMinimumSize(QSize(0, 250));
        listWidget_Users->setMaximumSize(QSize(16777215, 250));
        listWidget_Users->setFrameShape(QFrame::Shape::NoFrame);
        listWidget_Users->setAlternatingRowColors(false);

        leftLayout->addWidget(listWidget_Users);

        label_LogHeader = new QLabel(leftPanel);
        label_LogHeader->setObjectName("label_LogHeader");
        label_LogHeader->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 12px;\n"
"}"));

        leftLayout->addWidget(label_LogHeader);

        textEdit_Event_Log = new QTextEdit(leftPanel);
        textEdit_Event_Log->setObjectName("textEdit_Event_Log");
        textEdit_Event_Log->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        textEdit_Event_Log->setReadOnly(true);

        leftLayout->addWidget(textEdit_Event_Log);


        rootLayout->addWidget(leftPanel);

        centerLayout = new QVBoxLayout();
        centerLayout->setSpacing(0);
        centerLayout->setObjectName("centerLayout");
        centerLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_Client_List = new QComboBox(centralwidget);
        comboBox_Client_List->setObjectName("comboBox_Client_List");

        centerLayout->addWidget(comboBox_Client_List);

        label_ServerStatus = new QLabel(centralwidget);
        label_ServerStatus->setObjectName("label_ServerStatus");
        label_ServerStatus->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 12pt;\n"
"    font-weight: bold;\n"
"}"));

        centerLayout->addWidget(label_ServerStatus);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white;\n"
"    font-size: 13pt;\n"
"    font-weight: bold;\n"
"}"));

        centerLayout->addWidget(label_2);

        textEdit_Client_Messages = new QTextEdit(centralwidget);
        textEdit_Client_Messages->setObjectName("textEdit_Client_Messages");
        textEdit_Client_Messages->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        textEdit_Client_Messages->setReadOnly(true);

        centerLayout->addWidget(textEdit_Client_Messages);

        bottomBar = new QFrame(centralwidget);
        bottomBar->setObjectName("bottomBar");
        bottomBar->setFrameShape(QFrame::Shape::NoFrame);
        bottomLayout = new QHBoxLayout(bottomBar);
        bottomLayout->setSpacing(8);
        bottomLayout->setObjectName("bottomLayout");
        bottomLayout->setContentsMargins(12, 10, 12, 10);

        centerLayout->addWidget(bottomBar);


        rootLayout->addLayout(centerLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 980, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SecureChat Server \342\200\224 port 8080", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\360\237\226\245\357\270\217 SecureChat Server Dashboard                       ", nullptr));
        label_UsersHeader->setText(QCoreApplication::translate("MainWindow", "\360\237\221\245 CONNECTED USERS", nullptr));
        label_LogHeader->setText(QCoreApplication::translate("MainWindow", "\360\237\223\234EVENT LOG", nullptr));
        label_ServerStatus->setText(QCoreApplication::translate("MainWindow", "\360\237\237\242 Running", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\360\237\223\213 Server Activity ", nullptr));
        textEdit_Client_Messages->setPlaceholderText(QCoreApplication::translate("MainWindow", "Server log will appear here...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
