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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *view_frame;
    QGridLayout *gridLayout_2;
    QFrame *View_frame1;
    QVBoxLayout *verticalLayout_3;
    QLabel *view_layout;
    QFrame *Message_frame;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *Message;
    QFrame *View_frame2;
    QVBoxLayout *verticalLayout_4;
    QLabel *view_layout_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QTextEdit *Message_show;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(852, 914);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"background-color:rgb(29, 31, 43);\n"
"}"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        view_frame = new QFrame(centralwidget);
        view_frame->setObjectName("view_frame");
        view_frame->setSizeIncrement(QSize(0, 0));
        view_frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	padding:2px;\n"
"	margin:3px\n"
"}"));
        view_frame->setFrameShape(QFrame::Shape::StyledPanel);
        view_frame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_2 = new QGridLayout(view_frame);
        gridLayout_2->setObjectName("gridLayout_2");
        View_frame1 = new QFrame(view_frame);
        View_frame1->setObjectName("View_frame1");
        View_frame1->setMinimumSize(QSize(0, 0));
        View_frame1->setMaximumSize(QSize(700, 70));
        View_frame1->setFrameShape(QFrame::Shape::StyledPanel);
        View_frame1->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(View_frame1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        view_layout = new QLabel(View_frame1);
        view_layout->setObjectName("view_layout");
        view_layout->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color:#303345;\n"
"	border:2px solid #303345;\n"
"	border-radius:20px;\n"
"}"));

        verticalLayout_3->addWidget(view_layout);


        gridLayout_2->addWidget(View_frame1, 0, 0, 1, 1);

        Message_frame = new QFrame(view_frame);
        Message_frame->setObjectName("Message_frame");
        Message_frame->setEnabled(true);
        Message_frame->setMinimumSize(QSize(0, 0));
        Message_frame->setMaximumSize(QSize(800, 80));
        Message_frame->setSizeIncrement(QSize(0, 0));
        Message_frame->setFrameShape(QFrame::Shape::StyledPanel);
        Message_frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_5 = new QVBoxLayout(Message_frame);
        verticalLayout_5->setObjectName("verticalLayout_5");
        Message = new QLineEdit(Message_frame);
        Message->setObjectName("Message");
        Message->setMaximumSize(QSize(800, 60));

        verticalLayout_5->addWidget(Message);


        gridLayout_2->addWidget(Message_frame, 2, 0, 1, 2);

        View_frame2 = new QFrame(view_frame);
        View_frame2->setObjectName("View_frame2");
        View_frame2->setMaximumSize(QSize(70, 70));
        View_frame2->setFrameShape(QFrame::Shape::StyledPanel);
        View_frame2->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_4 = new QVBoxLayout(View_frame2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        view_layout_2 = new QLabel(View_frame2);
        view_layout_2->setObjectName("view_layout_2");
        QFont font;
        font.setPointSize(20);
        view_layout_2->setFont(font);
        view_layout_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color:#303345;\n"
"	border:2px solid #303345;\n"
"	border-radius:20px;\n"
"}"));
        view_layout_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(view_layout_2);


        gridLayout_2->addWidget(View_frame2, 0, 1, 1, 1);

        frame_3 = new QFrame(view_frame);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setObjectName("horizontalLayout");
        Message_show = new QTextEdit(frame_3);
        Message_show->setObjectName("Message_show");

        horizontalLayout->addWidget(Message_show);


        gridLayout_2->addWidget(frame_3, 1, 0, 1, 2);


        verticalLayout->addWidget(view_frame);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        view_layout->setText(QCoreApplication::translate("MainWindow", "Chat Name", nullptr));
        Message->setInputMask(QCoreApplication::translate("MainWindow", "Message", nullptr));
        Message->setText(QCoreApplication::translate("MainWindow", "Messge", nullptr));
        view_layout_2->setText(QCoreApplication::translate("MainWindow", "\360\237\247\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
