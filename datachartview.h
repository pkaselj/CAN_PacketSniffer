#ifndef DATACHARTVIEW_H
#define DATACHARTVIEW_H

#include <QWidget>
#include <datalogger.h>
#include <QtCharts>
#include "datalogger.h"

namespace Ui {
class DataChartView;
}

class DataChartView : public QWidget
{
    Q_OBJECT

public:
    explicit DataChartView(unsigned int ID, DataLogger* pDataLogger, QWidget *parent = nullptr);
    ~DataChartView();

    unsigned int getID() const { return m_ID; }

public slots:
    // void UpdateData(uint64_t newValue);
    void Update();

private slots:
    void on_btnClose_clicked();

private:
    Ui::DataChartView *ui;
    unsigned int m_ID;

    QLineSeries* m_pDataSeries;
    QChart* m_pChart;
    QChartView* m_pChartView;
    DataLogger* m_pDataLogger;

    QPushButton* m_pBtnClose;

    bool m_bConnectedToDataChangedSignal;

    void FillData();

};

#endif // DATACHARTVIEW_H
