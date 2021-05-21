#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QTableWidget>
#include "Structures.h"
#include "can_parser.h"
#include "SerialReader.h"
#include "datalogger.h"
#include <QGridLayout>
#include <QHash>
#include <QtCharts/QChartView>

using GraphTable = QHash<unsigned int, QLine>;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class MainView : public QWidget
{
    Q_OBJECT

public:
    MainView(QApplication* pMainApplication, QWidget *parent = nullptr);
    ~MainView();

    const int ID_column = 0;
    const int value_column = 1;
    const int hex_column = 2;
    const int unit_column = 3;
    const int timestamp_column = 4;
    const int endianness_column = 5;

public slots:
    Q_SLOT void AddTableEntry(TableEntry tableEntry);

private slots:

    void on_btnClearTable_clicked();

    void on_btnCAN_DecodeParams_clicked();

    void CreateChart(int row, int col);

    void on_btnSerialPortSettings_clicked();

    void on_chkFreezeFrame_stateChanged(int state);

private:

    Ui::Widget *ui;
    QApplication* m_pMainApplication;
    CAN_Parser* m_pCAN_Parser;
    SerialReader* m_pSerialReader;
    DataLogger* m_pDataLogger;
    QtCharts::QChartView* m_pChartContainer;
    QTableWidget* m_pDataTable;

    void setupUI();
    void setupTable();
    void setupCAN_Parser();
    void setupSerialReader();
    void setupDataLogger();
    void setupCharts();

    void FreezeFrame();
    void UnfreezeFrame();

    int ReturnRowID_ifEntryExists(unsigned int packetID);
    void EditTableRow(unsigned int row, TableEntry& tableEntry);
};
#endif // MAINVIEW_H
