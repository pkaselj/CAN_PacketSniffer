/********************************************************************************
** Form generated from reading UI file 'MainView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVIEW_H
#define UI_MAINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QCheckBox *chkFreezeFrame;
    QTableWidget *tblPacketTable;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSerialPortSettings;
    QPushButton *btnClearTable;
    QPushButton *btnCAN_DecodeParams;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1129, 613);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        chkFreezeFrame = new QCheckBox(Widget);
        chkFreezeFrame->setObjectName(QString::fromUtf8("chkFreezeFrame"));
        chkFreezeFrame->setLayoutDirection(Qt::RightToLeft);
        chkFreezeFrame->setStyleSheet(QString::fromUtf8(".switch {\n"
"  position: relative;\n"
"  display: inline-block;\n"
"  width: 60px;\n"
"  height: 34px;\n"
"}\n"
"\n"
"/* Hide default HTML checkbox */\n"
".switch input {\n"
"  opacity: 0;\n"
"  width: 0;\n"
"  height: 0;\n"
"}\n"
"\n"
"/* The slider */\n"
".slider {\n"
"  position: absolute;\n"
"  cursor: pointer;\n"
"  top: 0;\n"
"  left: 0;\n"
"  right: 0;\n"
"  bottom: 0;\n"
"  background-color: #ccc;\n"
"  -webkit-transition: .4s;\n"
"  transition: .4s;\n"
"}\n"
"\n"
".slider:before {\n"
"  position: absolute;\n"
"  content: \"\";\n"
"  height: 26px;\n"
"  width: 26px;\n"
"  left: 4px;\n"
"  bottom: 4px;\n"
"  background-color: white;\n"
"  -webkit-transition: .4s;\n"
"  transition: .4s;\n"
"}\n"
"\n"
"input:checked + .slider {\n"
"  background-color: #2196F3;\n"
"}\n"
"\n"
"input:focus + .slider {\n"
"  box-shadow: 0 0 1px #2196F3;\n"
"}\n"
"\n"
"input:checked + .slider:before {\n"
"  -webkit-transform: translateX(26px);\n"
"  -ms-transform: translateX(26px);\n"
"  transform: translateX(26px);\n"
"}\n"
""
                        "\n"
"/* Rounded sliders */\n"
".slider.round {\n"
"  border-radius: 34px;\n"
"}\n"
"\n"
".slider.round:before {\n"
"  border-radius: 50%;\n"
"}"));

        verticalLayout->addWidget(chkFreezeFrame);

        tblPacketTable = new QTableWidget(Widget);
        tblPacketTable->setObjectName(QString::fromUtf8("tblPacketTable"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tblPacketTable->sizePolicy().hasHeightForWidth());
        tblPacketTable->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(tblPacketTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnSerialPortSettings = new QPushButton(Widget);
        btnSerialPortSettings->setObjectName(QString::fromUtf8("btnSerialPortSettings"));

        horizontalLayout->addWidget(btnSerialPortSettings);

        btnClearTable = new QPushButton(Widget);
        btnClearTable->setObjectName(QString::fromUtf8("btnClearTable"));

        horizontalLayout->addWidget(btnClearTable);

        btnCAN_DecodeParams = new QPushButton(Widget);
        btnCAN_DecodeParams->setObjectName(QString::fromUtf8("btnCAN_DecodeParams"));

        horizontalLayout->addWidget(btnCAN_DecodeParams);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "CAN Packet Sniffer", nullptr));
        chkFreezeFrame->setText(QCoreApplication::translate("Widget", "Freeze Frame", nullptr));
        btnSerialPortSettings->setText(QCoreApplication::translate("Widget", "Connect to Serial Port", nullptr));
        btnClearTable->setText(QCoreApplication::translate("Widget", "Clear Table", nullptr));
        btnCAN_DecodeParams->setText(QCoreApplication::translate("Widget", "View CAN Decode Parameters", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEW_H
