/********************************************************************************
** Form generated from reading UI file 'can_decodeparametersview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAN_DECODEPARAMETERSVIEW_H
#define UI_CAN_DECODEPARAMETERSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CAN_DecodeParametersView
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QPushButton *btnAdd;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QPushButton *btnClose;

    void setupUi(QWidget *CAN_DecodeParametersView)
    {
        if (CAN_DecodeParametersView->objectName().isEmpty())
            CAN_DecodeParametersView->setObjectName(QString::fromUtf8("CAN_DecodeParametersView"));
        CAN_DecodeParametersView->resize(690, 481);
        gridLayout = new QGridLayout(CAN_DecodeParametersView);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget = new QTableWidget(CAN_DecodeParametersView);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 4);

        btnAdd = new QPushButton(CAN_DecodeParametersView);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));

        gridLayout->addWidget(btnAdd, 1, 0, 1, 1);

        btnEdit = new QPushButton(CAN_DecodeParametersView);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));

        gridLayout->addWidget(btnEdit, 1, 1, 1, 1);

        btnDelete = new QPushButton(CAN_DecodeParametersView);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));

        gridLayout->addWidget(btnDelete, 1, 2, 1, 1);

        btnClose = new QPushButton(CAN_DecodeParametersView);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        gridLayout->addWidget(btnClose, 1, 3, 1, 1);


        retranslateUi(CAN_DecodeParametersView);

        QMetaObject::connectSlotsByName(CAN_DecodeParametersView);
    } // setupUi

    void retranslateUi(QWidget *CAN_DecodeParametersView)
    {
        CAN_DecodeParametersView->setWindowTitle(QCoreApplication::translate("CAN_DecodeParametersView", "CAN decode parameter list", nullptr));
        btnAdd->setText(QCoreApplication::translate("CAN_DecodeParametersView", "Add", nullptr));
        btnEdit->setText(QCoreApplication::translate("CAN_DecodeParametersView", "Edit", nullptr));
        btnDelete->setText(QCoreApplication::translate("CAN_DecodeParametersView", "Delete", nullptr));
        btnClose->setText(QCoreApplication::translate("CAN_DecodeParametersView", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CAN_DecodeParametersView: public Ui_CAN_DecodeParametersView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAN_DECODEPARAMETERSVIEW_H
