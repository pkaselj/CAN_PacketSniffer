/********************************************************************************
** Form generated from reading UI file 'serialportsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORTSETTINGS_H
#define UI_SERIALPORTSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SerialPortSettings
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QFormLayout *formLayout_2;
    QLabel *lblBaudRate;
    QComboBox *menuBaudRate;
    QLabel *lblSerialPorts;
    QComboBox *menuSerialPorts;

    void setupUi(QDialog *SerialPortSettings)
    {
        if (SerialPortSettings->objectName().isEmpty())
            SerialPortSettings->setObjectName(QString::fromUtf8("SerialPortSettings"));
        SerialPortSettings->resize(400, 300);
        gridLayout = new QGridLayout(SerialPortSettings);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(SerialPortSettings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        lblBaudRate = new QLabel(SerialPortSettings);
        lblBaudRate->setObjectName(QString::fromUtf8("lblBaudRate"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, lblBaudRate);

        menuBaudRate = new QComboBox(SerialPortSettings);
        menuBaudRate->setObjectName(QString::fromUtf8("menuBaudRate"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, menuBaudRate);

        lblSerialPorts = new QLabel(SerialPortSettings);
        lblSerialPorts->setObjectName(QString::fromUtf8("lblSerialPorts"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, lblSerialPorts);

        menuSerialPorts = new QComboBox(SerialPortSettings);
        menuSerialPorts->setObjectName(QString::fromUtf8("menuSerialPorts"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, menuSerialPorts);


        gridLayout->addLayout(formLayout_2, 0, 0, 1, 2);


        retranslateUi(SerialPortSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), SerialPortSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SerialPortSettings, SLOT(reject()));

        QMetaObject::connectSlotsByName(SerialPortSettings);
    } // setupUi

    void retranslateUi(QDialog *SerialPortSettings)
    {
        SerialPortSettings->setWindowTitle(QCoreApplication::translate("SerialPortSettings", "Serial port settings", nullptr));
        lblBaudRate->setText(QCoreApplication::translate("SerialPortSettings", "Baud rate:", nullptr));
        lblSerialPorts->setText(QCoreApplication::translate("SerialPortSettings", "Serial port:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerialPortSettings: public Ui_SerialPortSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTSETTINGS_H
