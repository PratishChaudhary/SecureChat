/********************************************************************************
** Form generated from reading UI file 'systemlogdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMLOGDIALOG_H
#define UI_SYSTEMLOGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SystemLogDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *Layout;
    QLabel *Systemlog_icon;
    QLabel *label_LogHeader;
    QListWidget *systemLog;

    void setupUi(QDialog *SystemLogDialog)
    {
        if (SystemLogDialog->objectName().isEmpty())
            SystemLogDialog->setObjectName("SystemLogDialog");
        SystemLogDialog->resize(506, 744);
        SystemLogDialog->setStyleSheet(QString::fromUtf8("background-color:#0B0F14;"));
        horizontalLayout = new QHBoxLayout(SystemLogDialog);
        horizontalLayout->setObjectName("horizontalLayout");
        frame = new QFrame(SystemLogDialog);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid #2A3445;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, -1);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setStyleSheet(QString::fromUtf8("border:none;"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_3);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(-1, 0, -1, 0);
        Layout = new QHBoxLayout();
        Layout->setObjectName("Layout");
        Layout->setContentsMargins(9, 9, 9, 3);
        Systemlog_icon = new QLabel(frame_3);
        Systemlog_icon->setObjectName("Systemlog_icon");
        Systemlog_icon->setMinimumSize(QSize(30, 30));
        Systemlog_icon->setMaximumSize(QSize(30, 30));
        Systemlog_icon->setStyleSheet(QString::fromUtf8("border:none;"));
        Systemlog_icon->setPixmap(QPixmap(QString::fromUtf8(":/images/systemlog.png")));
        Systemlog_icon->setScaledContents(true);

        Layout->addWidget(Systemlog_icon);

        label_LogHeader = new QLabel(frame_3);
        label_LogHeader->setObjectName("label_LogHeader");
        label_LogHeader->setMinimumSize(QSize(0, 34));
        label_LogHeader->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Calibri")});
        font.setPointSize(18);
        label_LogHeader->setFont(font);
        label_LogHeader->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:#0B0F14;\n"
""));

        Layout->addWidget(label_LogHeader);


        verticalLayout_5->addLayout(Layout);


        verticalLayout_3->addWidget(frame_3);

        systemLog = new QListWidget(frame);
        systemLog->setObjectName("systemLog");
        systemLog->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	border-radius:0px;\n"
"	border-top: 1px solid #2A3445;\n"
"	border-bottom:none;\n"
"	border-left:none;\n"
"	border-right:none;\n"
"    color: white;\n"
"    outline: none;\n"
"    font-size: 11pt;\n"
"}\n"
"\n"
"QListWidget::item\n"
"{\n"
"    border-bottom: 1px solid rgb(42, 48, 58);\n"
"    padding: 12px;\n"
"}\n"
"\n"
"QListWidget::item:selected\n"
"{\n"
"    background: transparent;\n"
"    color: white;\n"
"}"));

        verticalLayout_3->addWidget(systemLog);


        horizontalLayout->addWidget(frame);


        retranslateUi(SystemLogDialog);

        QMetaObject::connectSlotsByName(SystemLogDialog);
    } // setupUi

    void retranslateUi(QDialog *SystemLogDialog)
    {
        SystemLogDialog->setWindowTitle(QCoreApplication::translate("SystemLogDialog", "Dialog", nullptr));
        Systemlog_icon->setText(QString());
        label_LogHeader->setText(QCoreApplication::translate("SystemLogDialog", "System Log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemLogDialog: public Ui_SystemLogDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMLOGDIALOG_H
