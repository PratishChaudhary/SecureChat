/********************************************************************************
** Form generated from reading UI file 'bubblemessage.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
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
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *Name;
    QLabel *Message;
    QHBoxLayout *horizontalLayout;
    QLabel *Time;

    void setupUi(QDialog *BubbleMessage)
    {
        if (BubbleMessage->objectName().isEmpty())
            BubbleMessage->setObjectName("BubbleMessage");
        BubbleMessage->resize(568, 271);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BubbleMessage->sizePolicy().hasHeightForWidth());
        BubbleMessage->setSizePolicy(sizePolicy);
        BubbleMessage->setMinimumSize(QSize(0, 0));
        BubbleMessage->setMaximumSize(QSize(16777215, 16777215));
        BubbleMessage->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(BubbleMessage);
        verticalLayout_2->setObjectName("verticalLayout_2");
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
        Name = new QLabel(frame);
        Name->setObjectName("Name");
        QFont font;
        font.setFamilies({QString::fromUtf8("Calibri")});
        font.setPointSize(15);
        font.setBold(true);
        Name->setFont(font);
        Name->setStyleSheet(QString::fromUtf8("color:rgb(218, 218, 218);\n"
"border:none;"));
        Name->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        verticalLayout->addWidget(Name);

        Message = new QLabel(frame);
        Message->setObjectName("Message");
        Message->setStyleSheet(QString::fromUtf8("border:none;"));
        Message->setWordWrap(true);

        verticalLayout->addWidget(Message);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Time = new QLabel(frame);
        Time->setObjectName("Time");
        Time->setEnabled(true);
        Time->setStyleSheet(QString::fromUtf8("color:gray;\n"
"border:none;"));
        Time->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(Time);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(frame);


        retranslateUi(BubbleMessage);

        QMetaObject::connectSlotsByName(BubbleMessage);
    } // setupUi

    void retranslateUi(QDialog *BubbleMessage)
    {
        BubbleMessage->setWindowTitle(QCoreApplication::translate("BubbleMessage", "Dialog", nullptr));
#if QT_CONFIG(whatsthis)
        BubbleMessage->setWhatsThis(QCoreApplication::translate("BubbleMessage", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        Name->setText(QCoreApplication::translate("BubbleMessage", "Name", nullptr));
        Message->setText(QCoreApplication::translate("BubbleMessage", "TextLabel", nullptr));
        Time->setText(QCoreApplication::translate("BubbleMessage", "Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BubbleMessage: public Ui_BubbleMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUBBLEMESSAGE_H
