/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_mainwindow1
{
public:
    QHBoxLayout *horizontalLayout_5;
    QFrame *Over;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *Main_icon;
    QLabel *Images;
    QFrame *SecureChatContainer;
    QHBoxLayout *horizontalLayout_6;
    QLabel *Secure;
    QLabel *Chat;
    QFrame *borderusername;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *UsernameLayout;
    QLabel *label_image;
    QLineEdit *lineEdit_username;
    QFrame *borderport;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *PortLayout;
    QLabel *label_image_2;
    QLineEdit *lineEdit_address;
    QFrame *LoginBoxFrame;
    QHBoxLayout *horizontalLayout;
    QPushButton *Login;
    QListWidget *listWidget;

    void setupUi(QDialog *mainwindow1)
    {
        if (mainwindow1->objectName().isEmpty())
            mainwindow1->setObjectName("mainwindow1");
        mainwindow1->resize(568, 873);
        mainwindow1->setMinimumSize(QSize(550, 700));
        mainwindow1->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(17);
        mainwindow1->setFont(font);
        mainwindow1->setAcceptDrops(false);
        mainwindow1->setStyleSheet(QString::fromUtf8("background-color:#1D1D1D;\n"
""));
        horizontalLayout_5 = new QHBoxLayout(mainwindow1);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        Over = new QFrame(mainwindow1);
        Over->setObjectName("Over");
        Over->setMinimumSize(QSize(550, 700));
        Over->setMaximumSize(QSize(16777215, 16777215));
        Over->setStyleSheet(QString::fromUtf8("background-color:#0B0F14;\n"
"border:1px solid rgba(0, 207, 239, 0.25);\n"
""));
        Over->setFrameShape(QFrame::Shape::StyledPanel);
        Over->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(Over);
        verticalLayout_2->setSpacing(16);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(40, 100, 40, 60);
        Main_icon = new QHBoxLayout();
        Main_icon->setObjectName("Main_icon");
        Images = new QLabel(Over);
        Images->setObjectName("Images");
        Images->setMinimumSize(QSize(0, 120));
        Images->setMaximumSize(QSize(240, 250));
#if QT_CONFIG(accessibility)
        Images->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        Images->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        Images->setAutoFillBackground(false);
        Images->setStyleSheet(QString::fromUtf8("background:none;\n"
"border:none"));
        Images->setPixmap(QPixmap(QString::fromUtf8(":/images/images.png")));
        Images->setScaledContents(true);
        Images->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        Main_icon->addWidget(Images);


        verticalLayout_2->addLayout(Main_icon);

        SecureChatContainer = new QFrame(Over);
        SecureChatContainer->setObjectName("SecureChatContainer");
        SecureChatContainer->setMinimumSize(QSize(0, 50));
        SecureChatContainer->setMaximumSize(QSize(16777215, 50));
        SecureChatContainer->setStyleSheet(QString::fromUtf8("border:none;"));
        SecureChatContainer->setFrameShape(QFrame::Shape::StyledPanel);
        SecureChatContainer->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_6 = new QHBoxLayout(SecureChatContainer);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        Secure = new QLabel(SecureChatContainer);
        Secure->setObjectName("Secure");
        Secure->setMaximumSize(QSize(16777215, 70));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Calibri")});
        font1.setPointSize(30);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        Secure->setFont(font1);
        Secure->setStyleSheet(QString::fromUtf8("\n"
"    QLabel {\n"
"    color: White;\n"
"\n"
"background-color:none;\n"
"    }\n"
""));
        Secure->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_6->addWidget(Secure);

        Chat = new QLabel(SecureChatContainer);
        Chat->setObjectName("Chat");
        Chat->setMaximumSize(QSize(16777215, 70));
        Chat->setFont(font1);
        Chat->setStyleSheet(QString::fromUtf8("\n"
"    QLabel {\n"
"    color: #00CFE8;\n"
"    \n"
"	background-color:none;\n"
"    }\n"
""));
        Chat->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_6->addWidget(Chat);


        verticalLayout_2->addWidget(SecureChatContainer);

        borderusername = new QFrame(Over);
        borderusername->setObjectName("borderusername");
        borderusername->setMinimumSize(QSize(0, 56));
        borderusername->setMaximumSize(QSize(16777215, 56));
        borderusername->setStyleSheet(QString::fromUtf8("border: 1px solid rgba(0, 207, 239, 0.35);\n"
"border-radius:10px;"));
        borderusername->setFrameShape(QFrame::Shape::StyledPanel);
        borderusername->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(borderusername);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(10, -1, 3, -1);
        UsernameLayout = new QHBoxLayout();
        UsernameLayout->setSpacing(20);
        UsernameLayout->setObjectName("UsernameLayout");
        label_image = new QLabel(borderusername);
        label_image->setObjectName("label_image");
        label_image->setMinimumSize(QSize(30, 0));
        label_image->setMaximumSize(QSize(30, 30));
        label_image->setStyleSheet(QString::fromUtf8("border:none;"));
        label_image->setPixmap(QPixmap(QString::fromUtf8(":/images/icon.png")));
        label_image->setScaledContents(true);

        UsernameLayout->addWidget(label_image);

        lineEdit_username = new QLineEdit(borderusername);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setMinimumSize(QSize(60, 30));
        lineEdit_username->setMaximumSize(QSize(800, 40));
        lineEdit_username->setSizeIncrement(QSize(700, 60));
        lineEdit_username->setStyleSheet(QString::fromUtf8("border:none;"));

        UsernameLayout->addWidget(lineEdit_username);


        horizontalLayout_2->addLayout(UsernameLayout);


        verticalLayout_2->addWidget(borderusername);

        borderport = new QFrame(Over);
        borderport->setObjectName("borderport");
        borderport->setMinimumSize(QSize(0, 56));
        borderport->setMaximumSize(QSize(16777215, 56));
        borderport->setStyleSheet(QString::fromUtf8("border: 1px solid rgba(0, 207, 239, 0.35);\n"
"border-radius:10px;"));
        borderport->setFrameShape(QFrame::Shape::StyledPanel);
        borderport->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout = new QVBoxLayout(borderport);
        verticalLayout->setObjectName("verticalLayout");
        PortLayout = new QHBoxLayout();
        PortLayout->setSpacing(20);
        PortLayout->setObjectName("PortLayout");
        label_image_2 = new QLabel(borderport);
        label_image_2->setObjectName("label_image_2");
        label_image_2->setMinimumSize(QSize(30, 0));
        label_image_2->setMaximumSize(QSize(35, 30));
        label_image_2->setSizeIncrement(QSize(0, 60));
        label_image_2->setBaseSize(QSize(0, 60));
        label_image_2->setStyleSheet(QString::fromUtf8("border:none;"));
        label_image_2->setPixmap(QPixmap(QString::fromUtf8(":/images/port.png")));
        label_image_2->setScaledContents(true);

        PortLayout->addWidget(label_image_2);

        lineEdit_address = new QLineEdit(borderport);
        lineEdit_address->setObjectName("lineEdit_address");
        lineEdit_address->setMaximumSize(QSize(16777215, 40));
        lineEdit_address->setStyleSheet(QString::fromUtf8("border:none;"));

        PortLayout->addWidget(lineEdit_address);


        verticalLayout->addLayout(PortLayout);


        verticalLayout_2->addWidget(borderport);

        LoginBoxFrame = new QFrame(Over);
        LoginBoxFrame->setObjectName("LoginBoxFrame");
        LoginBoxFrame->setMaximumSize(QSize(16777215, 80));
        LoginBoxFrame->setStyleSheet(QString::fromUtf8("border:none;"));
        LoginBoxFrame->setFrameShape(QFrame::Shape::StyledPanel);
        LoginBoxFrame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(LoginBoxFrame);
        horizontalLayout->setObjectName("horizontalLayout");
        Login = new QPushButton(LoginBoxFrame);
        Login->setObjectName("Login");
        Login->setMinimumSize(QSize(0, 60));
        Login->setMaximumSize(QSize(16777215, 60));
        QFont font2;
        font2.setPointSize(21);
        Login->setFont(font2);
        Login->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 207, 239, 0.65);\n"
"border:rgb(14, 130, 255);\n"
"border-radius:10px;"));

        horizontalLayout->addWidget(Login);


        verticalLayout_2->addWidget(LoginBoxFrame);

        listWidget = new QListWidget(Over);
        listWidget->setObjectName("listWidget");

        verticalLayout_2->addWidget(listWidget);


        horizontalLayout_5->addWidget(Over);


        retranslateUi(mainwindow1);

        QMetaObject::connectSlotsByName(mainwindow1);
    } // setupUi

    void retranslateUi(QDialog *mainwindow1)
    {
        mainwindow1->setWindowTitle(QCoreApplication::translate("mainwindow1", "Dialog", nullptr));
        Images->setText(QString());
        Secure->setText(QCoreApplication::translate("mainwindow1", "Secure", nullptr));
        Chat->setText(QCoreApplication::translate("mainwindow1", "Chat", nullptr));
        label_image->setText(QString());
        lineEdit_username->setText(QString());
        lineEdit_username->setPlaceholderText(QCoreApplication::translate("mainwindow1", "Username", nullptr));
        label_image_2->setText(QString());
        lineEdit_address->setText(QString());
        lineEdit_address->setPlaceholderText(QCoreApplication::translate("mainwindow1", "Address", nullptr));
        Login->setText(QCoreApplication::translate("mainwindow1", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindow1: public Ui_mainwindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
