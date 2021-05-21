/********************************************************************************
** Form generated from reading UI file 'newcan_decodeparametersdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCAN_DECODEPARAMETERSDIALOG_H
#define UI_NEWCAN_DECODEPARAMETERSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewCAN_DecodeParametersDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *lblID;
    QLineEdit *txtID;
    QLabel *lblUnit;
    QLineEdit *txtUnit;
    QLabel *lblMultiplier;
    QLineEdit *txtMultiplier;
    QLabel *lblOffset;
    QLineEdit *txtOffset;
    QLabel *lblValueMask;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chkByte0;
    QCheckBox *chkByte1;
    QCheckBox *chkByte2;
    QCheckBox *chkByte3;
    QCheckBox *chkByte4;
    QCheckBox *chkByte5;
    QCheckBox *chkByte6;
    QCheckBox *chkByte7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblLeftByte;
    QLabel *lblRightByte;
    QLabel *lblEndianness;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *rbLittleEndian;
    QRadioButton *rbBigEndian;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewCAN_DecodeParametersDialog)
    {
        if (NewCAN_DecodeParametersDialog->objectName().isEmpty())
            NewCAN_DecodeParametersDialog->setObjectName(QString::fromUtf8("NewCAN_DecodeParametersDialog"));
        NewCAN_DecodeParametersDialog->resize(662, 309);
        NewCAN_DecodeParametersDialog->setModal(true);
        verticalLayout = new QVBoxLayout(NewCAN_DecodeParametersDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lblID = new QLabel(NewCAN_DecodeParametersDialog);
        lblID->setObjectName(QString::fromUtf8("lblID"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblID);

        txtID = new QLineEdit(NewCAN_DecodeParametersDialog);
        txtID->setObjectName(QString::fromUtf8("txtID"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtID);

        lblUnit = new QLabel(NewCAN_DecodeParametersDialog);
        lblUnit->setObjectName(QString::fromUtf8("lblUnit"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblUnit);

        txtUnit = new QLineEdit(NewCAN_DecodeParametersDialog);
        txtUnit->setObjectName(QString::fromUtf8("txtUnit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtUnit);

        lblMultiplier = new QLabel(NewCAN_DecodeParametersDialog);
        lblMultiplier->setObjectName(QString::fromUtf8("lblMultiplier"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lblMultiplier);

        txtMultiplier = new QLineEdit(NewCAN_DecodeParametersDialog);
        txtMultiplier->setObjectName(QString::fromUtf8("txtMultiplier"));

        formLayout->setWidget(2, QFormLayout::FieldRole, txtMultiplier);

        lblOffset = new QLabel(NewCAN_DecodeParametersDialog);
        lblOffset->setObjectName(QString::fromUtf8("lblOffset"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lblOffset);

        txtOffset = new QLineEdit(NewCAN_DecodeParametersDialog);
        txtOffset->setObjectName(QString::fromUtf8("txtOffset"));

        formLayout->setWidget(3, QFormLayout::FieldRole, txtOffset);

        lblValueMask = new QLabel(NewCAN_DecodeParametersDialog);
        lblValueMask->setObjectName(QString::fromUtf8("lblValueMask"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lblValueMask);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        chkByte0 = new QCheckBox(NewCAN_DecodeParametersDialog);
        chkByte0->setObjectName(QString::fromUtf8("chkByte0"));

        horizontalLayout->addWidget(chkByte0);

        chkByte1 = new QCheckBox(NewCAN_DecodeParametersDialog);
        chkByte1->setObjectName(QString::fromUtf8("chkByte1"));

        horizontalLayout->addWidget(chkByte1);

        chkByte2 = new QCheckBox(NewCAN_DecodeParametersDialog);
        chkByte2->setObjectName(QString::fromUtf8("chkByte2"));

        horizontalLayout->addWidget(chkByte2);

        chkByte3 = new QCheckBox(NewCAN_DecodeParametersDialog);
        chkByte3->setObjectName(QString::fromUtf8("chkByte3"));

        horizontalLayout->addWidget(chkByte3);

        chkByte4 = new QCheckBox(NewCAN_DecodeParametersDialog);
        chkByte4->setObjectName(QString::fromUtf8("chkByte4"));

        horizontalLayout->addWidget(chkByte4);

        chkByte5 = new QCheckBox(NewCAN_DecodeParametersDialog);
        chkByte5->setObjectName(QString::fromUtf8("chkByte5"));

        horizontalLayout->addWidget(chkByte5);

        chkByte6 = new QCheckBox(NewCAN_DecodeParametersDialog);
        chkByte6->setObjectName(QString::fromUtf8("chkByte6"));

        horizontalLayout->addWidget(chkByte6);

        chkByte7 = new QCheckBox(NewCAN_DecodeParametersDialog);
        chkByte7->setObjectName(QString::fromUtf8("chkByte7"));

        horizontalLayout->addWidget(chkByte7);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lblLeftByte = new QLabel(NewCAN_DecodeParametersDialog);
        lblLeftByte->setObjectName(QString::fromUtf8("lblLeftByte"));

        horizontalLayout_2->addWidget(lblLeftByte);

        lblRightByte = new QLabel(NewCAN_DecodeParametersDialog);
        lblRightByte->setObjectName(QString::fromUtf8("lblRightByte"));
        lblRightByte->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lblRightByte);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout_2);

        lblEndianness = new QLabel(NewCAN_DecodeParametersDialog);
        lblEndianness->setObjectName(QString::fromUtf8("lblEndianness"));

        formLayout->setWidget(8, QFormLayout::LabelRole, lblEndianness);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        rbLittleEndian = new QRadioButton(NewCAN_DecodeParametersDialog);
        rbLittleEndian->setObjectName(QString::fromUtf8("rbLittleEndian"));
        rbLittleEndian->setChecked(true);

        horizontalLayout_4->addWidget(rbLittleEndian);

        rbBigEndian = new QRadioButton(NewCAN_DecodeParametersDialog);
        rbBigEndian->setObjectName(QString::fromUtf8("rbBigEndian"));

        horizontalLayout_4->addWidget(rbBigEndian);


        formLayout->setLayout(8, QFormLayout::FieldRole, horizontalLayout_4);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(NewCAN_DecodeParametersDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        buttonBox->raise();

        retranslateUi(NewCAN_DecodeParametersDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewCAN_DecodeParametersDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewCAN_DecodeParametersDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewCAN_DecodeParametersDialog);
    } // setupUi

    void retranslateUi(QDialog *NewCAN_DecodeParametersDialog)
    {
        NewCAN_DecodeParametersDialog->setWindowTitle(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "Add new CAN Decode Parameters", nullptr));
        lblID->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "ID [HEX]:", nullptr));
        txtID->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "0x", nullptr));
        lblUnit->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "Unit:", nullptr));
        lblMultiplier->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "Multiplier:", nullptr));
        lblOffset->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "Offset:", nullptr));
        lblValueMask->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "Value Mask:", nullptr));
        chkByte0->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "Byte 0", nullptr));
        chkByte1->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "Byte 1", nullptr));
        chkByte2->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "Byte 2", nullptr));
        chkByte3->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "Byte 3", nullptr));
        chkByte4->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "Byte 4", nullptr));
        chkByte5->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "Byte 5", nullptr));
        chkByte6->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "Byte 6", nullptr));
        chkByte7->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "Byte 7", nullptr));
        lblLeftByte->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "LSB", nullptr));
        lblRightByte->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "MSB", nullptr));
        lblEndianness->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "Endianness:", nullptr));
        rbLittleEndian->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "Little Endian", nullptr));
        rbBigEndian->setText(QCoreApplication::translate("NewCAN_DecodeParametersDialog", "Big Endian", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewCAN_DecodeParametersDialog: public Ui_NewCAN_DecodeParametersDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCAN_DECODEPARAMETERSDIALOG_H
