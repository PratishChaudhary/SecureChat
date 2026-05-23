/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit_Client_Messages;
    QComboBox *comboBox_Client_List;
    QComboBox *combobox2_Send_Message_type;
    QLineEdit *lineEdit_send_message;
    QPushButton *push_button_Send;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        textEdit_Client_Messages = new QTextEdit(centralwidget);
        textEdit_Client_Messages->setObjectName("textEdit_Client_Messages");
        QFont font;
        font.setPointSize(24);
        textEdit_Client_Messages->setFont(font);

        gridLayout->addWidget(textEdit_Client_Messages, 0, 0, 1, 4);

        comboBox_Client_List = new QComboBox(centralwidget);
        comboBox_Client_List->setObjectName("comboBox_Client_List");
        QFont font1;
        font1.setPointSize(18);
        comboBox_Client_List->setFont(font1);

        gridLayout->addWidget(comboBox_Client_List, 1, 0, 1, 1);

        combobox2_Send_Message_type = new QComboBox(centralwidget);
        combobox2_Send_Message_type->addItem(QString());
        combobox2_Send_Message_type->addItem(QString());
        combobox2_Send_Message_type->setObjectName("combobox2_Send_Message_type");
        combobox2_Send_Message_type->setFont(font1);

        gridLayout->addWidget(combobox2_Send_Message_type, 1, 1, 1, 1);

        lineEdit_send_message = new QLineEdit(centralwidget);
        lineEdit_send_message->setObjectName("lineEdit_send_message");
        lineEdit_send_message->setFont(font1);

        gridLayout->addWidget(lineEdit_send_message, 1, 2, 1, 1);

        push_button_Send = new QPushButton(centralwidget);
        push_button_Send->setObjectName("push_button_Send");
        push_button_Send->setFont(font1);

        gridLayout->addWidget(push_button_Send, 1, 3, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        combobox2_Send_Message_type->setItemText(0, QCoreApplication::translate("MainWindow", "All", nullptr));
        combobox2_Send_Message_type->setItemText(1, QCoreApplication::translate("MainWindow", "Aayush", nullptr));

        push_button_Send->setText(QCoreApplication::translate("MainWindow", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
