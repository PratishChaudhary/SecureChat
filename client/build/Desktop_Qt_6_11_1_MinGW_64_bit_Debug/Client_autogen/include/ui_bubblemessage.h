/********************************************************************************
** Form generated from reading UI file 'bubblemessage.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUBBLEMESSAGE_H
#define UI_BUBBLEMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BubbleMessage
{
public:
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *Name;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Message;
    QLabel *Time;

    void setupUi(QDialog *BubbleMessage)
    {
        if (BubbleMessage->objectName().isEmpty())
            BubbleMessage->setObjectName("BubbleMessage");
        BubbleMessage->resize(489, 113);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BubbleMessage->sizePolicy().hasHeightForWidth());
        BubbleMessage->setSizePolicy(sizePolicy);
        BubbleMessage->setMinimumSize(QSize(0, 0));
        BubbleMessage->setMaximumSize(QSize(16777215, 16777215));
        BubbleMessage->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(BubbleMessage);
        horizontalLayout_2->setSpacing(9);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(9, 9, 9, 9);
        frame = new QFrame(BubbleMessage);
        frame->setObjectName("frame");
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #161D26;\n"
"    border: 1px solid #2A3440;\n"
"    border-radius: 9px;\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(12, 10, 12, 10);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Name = new QLabel(frame);
        Name->setObjectName("Name");
        QFont font;
        font.setFamilies({QString::fromUtf8("Calibri")});
        font.setPointSize(15);
        font.setBold(true);
        Name->setFont(font);
        Name->setStyleSheet(QString::fromUtf8("color:rgb(218, 218, 218);\n"
"border:none;"));

        horizontalLayout->addWidget(Name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        Message = new QLabel(frame);
        Message->setObjectName("Message");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Message->sizePolicy().hasHeightForWidth());
        Message->setSizePolicy(sizePolicy1);
        Message->setStyleSheet(QString::fromUtf8("color:white;\n"
"border:none;"));
        Message->setWordWrap(true);

        horizontalLayout_3->addWidget(Message);


        verticalLayout->addLayout(horizontalLayout_3);

        Time = new QLabel(frame);
        Time->setObjectName("Time");
        Time->setEnabled(true);
        Time->setStyleSheet(QString::fromUtf8("color:gray;\n"
"border:none;"));
        Time->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(Time);


        horizontalLayout_2->addWidget(frame);


        retranslateUi(BubbleMessage);

        QMetaObject::connectSlotsByName(BubbleMessage);
    } // setupUi

    void retranslateUi(QDialog *BubbleMessage)
    {
        BubbleMessage->setWindowTitle(QCoreApplication::translate("BubbleMessage", "Dialog", nullptr));
        Name->setText(QCoreApplication::translate("BubbleMessage", "Name", nullptr));
        Message->setText(QCoreApplication::translate("BubbleMessage", "Message", nullptr));
        Time->setText(QCoreApplication::translate("BubbleMessage", "Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BubbleMessage: public Ui_BubbleMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUBBLEMESSAGE_H
