#include "MainView.h"
#include "ui_MainView.h"
#include "newcan_decodeparametersdialog.h"
#include "can_decodeparametersview.h"
#include "QtCharts/QLineSeries"
#include "datachartview.h"
#include "serialportsettings.h"

MainView::MainView(QApplication* pMainApplication, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_pMainApplication(pMainApplication)
{
    setWindowIcon(QIcon(QDir::currentPath() + "\\resources\\icon.ico"));
    qRegisterMetaType<TableEntry>("TableEntry");

    setupCAN_Parser();
    setupSerialReader();
    setupDataLogger();

    ui->setupUi(this);
    setupUI();

    // setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    m_pSerialReader->Start();
}

MainView::~MainView()
{
    delete ui;
    delete m_pCAN_Parser;
    delete m_pSerialReader;
    delete m_pDataLogger;
}

void MainView::setupUI()
{
    setupTable();
    setupCharts();
}

void MainView::setupTable()
{
    m_pDataTable = ui->tblPacketTable;

    const QStringList tableHeaderLabels = {"ID", "Value", "Raw - HEX", "Unit", "Timestamp", "Endianness"};
    const bool bAlternateRowColors = true;

    m_pDataTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    m_pDataTable->setRowCount(0);
    m_pDataTable->setColumnCount(tableHeaderLabels.size());
    m_pDataTable->setAlternatingRowColors(bAlternateRowColors);
    m_pDataTable->setHorizontalHeaderLabels(tableHeaderLabels);

    m_pDataTable->setSelectionBehavior(QTableWidget::SelectRows);
    m_pDataTable->setSelectionMode(QTableWidget::SingleSelection);

    connect(m_pDataTable, &QTableWidget::cellDoubleClicked, this, &MainView::CreateChart);

}

void MainView::CreateChart(int row, int col)
{
    QString qstrID = m_pDataTable->item(row, col)->text();
    unsigned int ID = qstrID.toInt(nullptr, 0);

    DataChartView* pChart(new DataChartView(ID, m_pDataLogger));
    connect(pChart, &DataChartView::destroyed, this, &MainView::deleteLater);
    pChart->show();
}

void MainView::setupCharts()
{
    // m_pChartContainer = new QtCharts::QChartView(ui->tabDash);
}

void MainView::setupDataLogger()
{
    m_pDataLogger = new DataLogger(this);
    connect(m_pCAN_Parser, &CAN_Parser::CAN_DecodeParametersChanged, m_pDataLogger, &DataLogger::DropData);
    connect(m_pCAN_Parser, &CAN_Parser::DataSuccessfullyDecoded, m_pDataLogger, &DataLogger::InsertTableEntry);
}

void MainView::AddTableEntry(TableEntry tableEntry)
{
    int rowId = ReturnRowID_ifEntryExists(tableEntry.m_ID);
    if(rowId < 0)
    {
        rowId = m_pDataTable->rowCount();
        m_pDataTable->insertRow(rowId);
    }

    EditTableRow(rowId, tableEntry);

}

void MainView::EditTableRow(unsigned int row, TableEntry& tableEntry)
{
    // Possible mem leak

    qDebug() << "Value !!!---" << tableEntry.m_value;
    m_pDataTable->setItem(row, ID_column, new QTableWidgetItem(QString("0x%1").arg(tableEntry.m_ID, 0, 16)));
    m_pDataTable->setItem(row, value_column, new QTableWidgetItem(QString("%1").arg(tableEntry.m_value)));
    m_pDataTable->setItem(row, hex_column, new QTableWidgetItem(QString(tableEntry.m_rawHex.toHex(':').toUpper())));
    m_pDataTable->setItem(row, unit_column, new QTableWidgetItem(tableEntry.m_unit));
    m_pDataTable->setItem(row, timestamp_column, new QTableWidgetItem(tableEntry.m_timestamp));
    m_pDataTable->setItem(row, endianness_column, new QTableWidgetItem(tableEntry.m_endianness));
}

int MainView::ReturnRowID_ifEntryExists(unsigned int packetID)
{
    QString sPacketID = QString("0x%1").arg(packetID, 0, 16);
    auto results = m_pDataTable->findItems(sPacketID, Qt::MatchExactly);

    if(results.isEmpty())
    {
        return -1;
    }

    for (auto& result : results)
    {
        if(result->column() == ID_column)
        {
            return result->row();
        }
    }

    return -1;

}

void MainView::on_btnClearTable_clicked()
{
    m_pDataTable->setRowCount(0);
}

void MainView::setupCAN_Parser()
{
    m_pCAN_Parser = new CAN_Parser(this);
    QObject::connect(m_pCAN_Parser, &CAN_Parser::DataSuccessfullyDecoded, this, &MainView::AddTableEntry);
}

void MainView::setupSerialReader()
{
    m_pSerialReader = new SerialReader(m_pMainApplication);
    QObject::connect(m_pSerialReader, &SerialReader::DataReceived, m_pCAN_Parser, &CAN_Parser::DecodeData);
}

void MainView::on_btnCAN_DecodeParams_clicked()
{
    CAN_DecodeParametersView* pView(new CAN_DecodeParametersView(m_pCAN_Parser));
    pView->show();

    connect(pView, &CAN_DecodeParametersView::destroyed, this, &MainView::deleteLater);
}

void MainView::on_btnSerialPortSettings_clicked()
{
    SerialPortSettings* windowSerialPortSettings(new SerialPortSettings(this));
    windowSerialPortSettings->show();

    connect(windowSerialPortSettings, &SerialPortSettings::destroyed, this, &MainView::deleteLater);
    connect(windowSerialPortSettings, &SerialPortSettings::SerialPortSettingsChanged, m_pSerialReader, &SerialReader::ConnectToSerialPort);
}


void MainView::on_chkFreezeFrame_stateChanged(int state)
{
    if(state == Qt::CheckState::Checked)
    {
        FreezeFrame();
        return;
    }

    UnfreezeFrame();
}

void MainView::FreezeFrame()
{
    disconnect(m_pCAN_Parser, &CAN_Parser::DataSuccessfullyDecoded, this, &MainView::AddTableEntry);
}

void MainView::UnfreezeFrame()
{
    connect(m_pCAN_Parser, &CAN_Parser::DataSuccessfullyDecoded, this, &MainView::AddTableEntry);
}
