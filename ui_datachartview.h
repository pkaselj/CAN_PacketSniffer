/********************************************************************************
** Form generated from reading UI file 'datachartview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATACHARTVIEW_H
#define UI_DATACHARTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataChartView
{
public:
    QGridLayout *gridLayout_2;

    void setupUi(QWidget *DataChartView)
    {
        if (DataChartView->objectName().isEmpty())
            DataChartView->setObjectName(QString::fromUtf8("DataChartView"));
        DataChartView->resize(656, 407);
        gridLayout_2 = new QGridLayout(DataChartView);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        retranslateUi(DataChartView);

        QMetaObject::connectSlotsByName(DataChartView);
    } // setupUi

    void retranslateUi(QWidget *DataChartView)
    {
        DataChartView->setWindowTitle(QCoreApplication::translate("DataChartView", "Graph", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataChartView: public Ui_DataChartView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATACHARTVIEW_H
