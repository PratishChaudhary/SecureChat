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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientMainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_7;
    QTextEdit *textEdit_ChatDisplay;
    QFrame *Window;
    QVBoxLayout *verticalLayout_2;
    QFrame *upperportion;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *secure_icon;
    QFrame *SecureChatframe;
    QFormLayout *formLayout;
    QLabel *SecureLabel;
    QLabel *ChatLabel;
    QLabel *label;
    QFrame *User_;
    QGridLayout *gridLayout_2;
    QLabel *label_IdentityDisplay;
    QLabel *Loginn_text;
    QLabel *Userlogo;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_5;
    QFrame *Chat;
    QVBoxLayout *verticalLayout;
    QFrame *Chatandlogoframe;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *chat_icon;
    QLabel *chat_label;
    QPushButton *pushButton_SystemLog;
    QHBoxLayout *Chat_layout;
    QFrame *Handele_Frame;
    QHBoxLayout *horizontalLayout_6;
    QListWidget *Chatlist;
    QFrame *UserList_Frame;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QListWidget *listwidget_userlist;
    QFrame *Chat_sendbuttonFrame;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_ChatMsg;
    QPushButton *sendButton;

    void setupUi(QMainWindow *ClientMainWindow)
    {
        if (ClientMainWindow->objectName().isEmpty())
            ClientMainWindow->setObjectName("ClientMainWindow");
        ClientMainWindow->resize(1104, 925);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ClientMainWindow->sizePolicy().hasHeightForWidth());
        ClientMainWindow->setSizePolicy(sizePolicy);
        ClientMainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(ClientMainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-color:black;"));
        horizontalLayout_7 = new QHBoxLayout(centralwidget);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        textEdit_ChatDisplay = new QTextEdit(centralwidget);
        textEdit_ChatDisplay->setObjectName("textEdit_ChatDisplay");
        textEdit_ChatDisplay->setMaximumSize(QSize(0, 16777215));
        textEdit_ChatDisplay->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        textEdit_ChatDisplay->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"border-top: 1px solid #2A3445;\n"
"border-bottom:none;\n"
"border-left:none;\n"
"border-right:none;\n"
""));
        textEdit_ChatDisplay->setReadOnly(true);

        horizontalLayout_7->addWidget(textEdit_ChatDisplay);

        Window = new QFrame(centralwidget);
        Window->setObjectName("Window");
        Window->setStyleSheet(QString::fromUtf8("background-color:#0B0F14;"));
        Window->setFrameShape(QFrame::Shape::StyledPanel);
        Window->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(Window);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, -1, 0, -1);
        upperportion = new QFrame(Window);
        upperportion->setObjectName("upperportion");
        upperportion->setMinimumSize(QSize(0, 30));
        upperportion->setMaximumSize(QSize(16777215, 100));
        upperportion->setStyleSheet(QString::fromUtf8("background-color:#0B0F14;\n"
"border-bottom:1px solid #2A3445;\n"
"border-top:none;\n"
"border-right:none;\n"
"border-left:none;"));
        upperportion->setFrameShape(QFrame::Shape::StyledPanel);
        upperportion->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_3 = new QHBoxLayout(upperportion);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(11, 9, 12, 9);
        secure_icon = new QLabel(upperportion);
        secure_icon->setObjectName("secure_icon");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(secure_icon->sizePolicy().hasHeightForWidth());
        secure_icon->setSizePolicy(sizePolicy1);
        secure_icon->setMinimumSize(QSize(0, 44));
        secure_icon->setMaximumSize(QSize(70, 70));
        secure_icon->setSizeIncrement(QSize(8, 0));
        secure_icon->setAutoFillBackground(false);
        secure_icon->setStyleSheet(QString::fromUtf8("border:none;"));
        secure_icon->setPixmap(QPixmap(QString::fromUtf8(":/images/images.png")));
        secure_icon->setScaledContents(true);
        secure_icon->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTop|Qt::AlignmentFlag::AlignTrailing);

        horizontalLayout->addWidget(secure_icon);

        SecureChatframe = new QFrame(upperportion);
        SecureChatframe->setObjectName("SecureChatframe");
        SecureChatframe->setMinimumSize(QSize(0, 50));
        SecureChatframe->setMaximumSize(QSize(16777215, 50));
        SecureChatframe->setStyleSheet(QString::fromUtf8("border:none;"));
        SecureChatframe->setFrameShape(QFrame::Shape::StyledPanel);
        SecureChatframe->setFrameShadow(QFrame::Shadow::Raised);
        formLayout = new QFormLayout(SecureChatframe);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(0);
        SecureLabel = new QLabel(SecureChatframe);
        SecureLabel->setObjectName("SecureLabel");
        SecureLabel->setMinimumSize(QSize(30, 0));
        SecureLabel->setMaximumSize(QSize(67, 70));
        QFont font;
        font.setFamilies({QString::fromUtf8("Calibri")});
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        SecureLabel->setFont(font);
        SecureLabel->setStyleSheet(QString::fromUtf8("\n"
"    QLabel {\n"
"    color: White;\n"
"	border:none;\n"
"	background-color:none;\n"
"    }\n"
""));
        SecureLabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, SecureLabel);

        ChatLabel = new QLabel(SecureChatframe);
        ChatLabel->setObjectName("ChatLabel");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Calibri")});
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setItalic(false);
        ChatLabel->setFont(font1);
        ChatLabel->setStyleSheet(QString::fromUtf8("color:rgb(15, 200, 194);\n"
"border:none;"));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, ChatLabel);

        label = new QLabel(SecureChatframe);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("color:rgb(102, 102, 102);"));

        formLayout->setWidget(1, QFormLayout::ItemRole::SpanningRole, label);


        horizontalLayout->addWidget(SecureChatframe);

        User_ = new QFrame(upperportion);
        User_->setObjectName("User_");
        User_->setMinimumSize(QSize(500, 60));
        User_->setMaximumSize(QSize(16777215, 80));
        User_->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid #2A3445;"));
        User_->setFrameShape(QFrame::Shape::StyledPanel);
        User_->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_2 = new QGridLayout(User_);
        gridLayout_2->setObjectName("gridLayout_2");
        label_IdentityDisplay = new QLabel(User_);
        label_IdentityDisplay->setObjectName("label_IdentityDisplay");
        label_IdentityDisplay->setMinimumSize(QSize(0, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Calibri")});
        font2.setPointSize(13);
        label_IdentityDisplay->setFont(font2);
        label_IdentityDisplay->setStyleSheet(QString::fromUtf8("border:none;"));
        label_IdentityDisplay->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(label_IdentityDisplay, 1, 1, 1, 1);

        Loginn_text = new QLabel(User_);
        Loginn_text->setObjectName("Loginn_text");
        Loginn_text->setMinimumSize(QSize(0, 30));
        Loginn_text->setMaximumSize(QSize(16777215, 30));
        QFont font3;
        font3.setPointSize(12);
        Loginn_text->setFont(font3);
        Loginn_text->setStyleSheet(QString::fromUtf8("border:none;"));

        gridLayout_2->addWidget(Loginn_text, 0, 1, 1, 1);

        Userlogo = new QLabel(User_);
        Userlogo->setObjectName("Userlogo");
        Userlogo->setMinimumSize(QSize(40, 40));
        Userlogo->setMaximumSize(QSize(50, 16777215));
        Userlogo->setAutoFillBackground(false);
        Userlogo->setStyleSheet(QString::fromUtf8("border:none;"));
        Userlogo->setPixmap(QPixmap(QString::fromUtf8(":/images/user.png")));
        Userlogo->setScaledContents(true);

        gridLayout_2->addWidget(Userlogo, 0, 0, 2, 1);


        horizontalLayout->addWidget(User_);


        horizontalLayout_3->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(upperportion);

        frame_2 = new QFrame(Window);
        frame_2->setObjectName("frame_2");
        frame_2->setStyleSheet(QString::fromUtf8("border:none;"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_2);
        horizontalLayout_5->setSpacing(20);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, -1, 0, -1);
        Chat = new QFrame(frame_2);
        Chat->setObjectName("Chat");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(5);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Chat->sizePolicy().hasHeightForWidth());
        Chat->setSizePolicy(sizePolicy2);
        Chat->setMinimumSize(QSize(0, 0));
        Chat->setMaximumSize(QSize(16777215, 16777215));
        Chat->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border-top:1px solid #2A3445;\n"
"border-bottom:1px solid #2A3445;\n"
"}"));
        Chat->setFrameShape(QFrame::Shape::StyledPanel);
        Chat->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout = new QVBoxLayout(Chat);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Chatandlogoframe = new QFrame(Chat);
        Chatandlogoframe->setObjectName("Chatandlogoframe");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Chatandlogoframe->sizePolicy().hasHeightForWidth());
        Chatandlogoframe->setSizePolicy(sizePolicy3);
        Chatandlogoframe->setMinimumSize(QSize(0, 0));
        Chatandlogoframe->setStyleSheet(QString::fromUtf8("border:none;"));
        Chatandlogoframe->setFrameShape(QFrame::Shape::StyledPanel);
        Chatandlogoframe->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_4 = new QVBoxLayout(Chatandlogoframe);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, -1, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(30, -1, 9, -1);
        chat_icon = new QLabel(Chatandlogoframe);
        chat_icon->setObjectName("chat_icon");
        chat_icon->setMinimumSize(QSize(30, 20));
        chat_icon->setMaximumSize(QSize(30, 30));
        chat_icon->setAutoFillBackground(false);
        chat_icon->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:none;"));
        chat_icon->setPixmap(QPixmap(QString::fromUtf8(":/images/chat.png")));
        chat_icon->setScaledContents(true);
        chat_icon->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        horizontalLayout_4->addWidget(chat_icon);

        chat_label = new QLabel(Chatandlogoframe);
        chat_label->setObjectName("chat_label");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(chat_label->sizePolicy().hasHeightForWidth());
        chat_label->setSizePolicy(sizePolicy4);
        chat_label->setMinimumSize(QSize(0, 34));
        chat_label->setMaximumSize(QSize(16777215, 30));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Calibri")});
        font4.setPointSize(18);
        font4.setItalic(false);
        chat_label->setFont(font4);
        chat_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"    padding: 0px;\n"
"    margin: 0px;\n"
"}"));

        horizontalLayout_4->addWidget(chat_label);

        pushButton_SystemLog = new QPushButton(Chatandlogoframe);
        pushButton_SystemLog->setObjectName("pushButton_SystemLog");

        horizontalLayout_4->addWidget(pushButton_SystemLog);


        verticalLayout_4->addLayout(horizontalLayout_4);

        Chat_layout = new QHBoxLayout();
        Chat_layout->setObjectName("Chat_layout");
        Handele_Frame = new QFrame(Chatandlogoframe);
        Handele_Frame->setObjectName("Handele_Frame");
        Handele_Frame->setStyleSheet(QString::fromUtf8("#Handele_Frame {\n"
"border-radius:0px;\n"
"border:none;\n"
"border-top:1px solid #2A3445;\n"
"}"));
        Handele_Frame->setFrameShape(QFrame::Shape::NoFrame);
        Handele_Frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_6 = new QHBoxLayout(Handele_Frame);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(-1, 2, -1, 0);
        Chatlist = new QListWidget(Handele_Frame);
        Chatlist->setObjectName("Chatlist");
        Chatlist->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        Chatlist->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    background: transparent;\n"
"    border: none;\n"
"    outline: none;\n"
"    padding: 0px;\n"
"}\n"
"\n"
"QListWidget::item {\n"
"    background: transparent;\n"
"    border: none;\n"
"    padding: 4px;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QListWidget::item:hover {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QListWidget::item:focus {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background: transparent;\n"
"    width: 8px;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #2A3440;\n"
"    border-radius: 4px;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #3B4C60;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical,\n"
"QScrollBar::add-page:vertical,\n"
"QScrollBar::sub-page:vertical {\n"
"    backgrou"
                        "nd: transparent;\n"
"    height: 0px;\n"
"}"));
        Chatlist->setFrameShape(QFrame::Shape::NoFrame);
        Chatlist->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);

        horizontalLayout_6->addWidget(Chatlist);

        UserList_Frame = new QFrame(Handele_Frame);
        UserList_Frame->setObjectName("UserList_Frame");
        UserList_Frame->setMaximumSize(QSize(200, 16777215));
        UserList_Frame->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-left:1px solid #2A3445;"));
        UserList_Frame->setFrameShape(QFrame::Shape::StyledPanel);
        UserList_Frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(UserList_Frame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, 20, -1, 4);
        label_2 = new QLabel(UserList_Frame);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("border:none;"));

        verticalLayout_3->addWidget(label_2);

        listwidget_userlist = new QListWidget(UserList_Frame);
        listwidget_userlist->setObjectName("listwidget_userlist");
        listwidget_userlist->setMinimumSize(QSize(50, 0));
        listwidget_userlist->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        listwidget_userlist->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"	border:none;\n"
"}\n"
"QListWidget::item{\n"
"	padding: 6px;\n"
"}\n"
"QListWidget::item:hover {\n"
"	background: transparent;\n"
"}\n"
"QListWidget::item:selected {\n"
"    background: transparent;\n"
"}\n"
""));
        listwidget_userlist->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);

        verticalLayout_3->addWidget(listwidget_userlist);


        horizontalLayout_6->addWidget(UserList_Frame);


        Chat_layout->addWidget(Handele_Frame);


        verticalLayout_4->addLayout(Chat_layout);


        verticalLayout->addWidget(Chatandlogoframe);


        horizontalLayout_5->addWidget(Chat);


        verticalLayout_2->addWidget(frame_2);

        Chat_sendbuttonFrame = new QFrame(Window);
        Chat_sendbuttonFrame->setObjectName("Chat_sendbuttonFrame");
        Chat_sendbuttonFrame->setMinimumSize(QSize(0, 90));
        Chat_sendbuttonFrame->setStyleSheet(QString::fromUtf8("border:none;"));
        Chat_sendbuttonFrame->setFrameShape(QFrame::Shape::StyledPanel);
        Chat_sendbuttonFrame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(Chat_sendbuttonFrame);
        horizontalLayout_2->setSpacing(8);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(12, 8, 12, 8);
        lineEdit_ChatMsg = new QLineEdit(Chat_sendbuttonFrame);
        lineEdit_ChatMsg->setObjectName("lineEdit_ChatMsg");
        lineEdit_ChatMsg->setMinimumSize(QSize(0, 52));
        lineEdit_ChatMsg->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_ChatMsg->setStyleSheet(QString::fromUtf8("\n"
"border: 1px solid #3a4050;\n"
" border-radius: 8px;\n"
" padding-left:12px;\n"
"padding-right:12px;\n"
"border :  1px solid  rgb(0, 85, 127);\n"
"border-radius:10px;"));

        horizontalLayout_2->addWidget(lineEdit_ChatMsg);

        sendButton = new QPushButton(Chat_sendbuttonFrame);
        sendButton->setObjectName("sendButton");
        sizePolicy1.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy1);
        sendButton->setMinimumSize(QSize(90, 52));
        sendButton->setStyleSheet(QString::fromUtf8("QPushButton#sendButton {\n"
"    background:#22b8c7;\n"
"    color:white;\n"
"    border:none;\n"
"    border-radius:10px;\n"
"    font-weight:bold;\n"
"}\n"
"QPushButton#sendButton:hover {\n"
"    background-color: #32d0df;\n"
"}\n"
"QPushButton#sendButton:pressed {\n"
"    background-color: #1699a7;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(sendButton);


        verticalLayout_2->addWidget(Chat_sendbuttonFrame);


        horizontalLayout_7->addWidget(Window);

        ClientMainWindow->setCentralWidget(centralwidget);

        retranslateUi(ClientMainWindow);

        QMetaObject::connectSlotsByName(ClientMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ClientMainWindow)
    {
        ClientMainWindow->setWindowTitle(QCoreApplication::translate("ClientMainWindow", "SecureChat \342\200\224 Client", nullptr));
#if QT_CONFIG(accessibility)
        secure_icon->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        secure_icon->setText(QString());
        SecureLabel->setText(QCoreApplication::translate("ClientMainWindow", "Secure", nullptr));
        ChatLabel->setText(QCoreApplication::translate("ClientMainWindow", "Chat", nullptr));
        label->setText(QCoreApplication::translate("ClientMainWindow", "End to Encrypted Group Chat", nullptr));
        label_IdentityDisplay->setText(QCoreApplication::translate("ClientMainWindow", "Connecting...", nullptr));
        Loginn_text->setText(QCoreApplication::translate("ClientMainWindow", "Logged in as:", nullptr));
        Userlogo->setText(QString());
        chat_icon->setText(QString());
        chat_label->setText(QCoreApplication::translate("ClientMainWindow", "Chat", nullptr));
        pushButton_SystemLog->setText(QCoreApplication::translate("ClientMainWindow", "SystemLog", nullptr));
        label_2->setText(QCoreApplication::translate("ClientMainWindow", "Members", nullptr));
        lineEdit_ChatMsg->setPlaceholderText(QCoreApplication::translate("ClientMainWindow", "Type a message...", nullptr));
        sendButton->setText(QCoreApplication::translate("ClientMainWindow", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientMainWindow: public Ui_ClientMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
