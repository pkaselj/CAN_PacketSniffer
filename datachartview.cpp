#include "datachartview.h"
#include "ui_datachartview.h"
#include <QDebug>
#include <algorithm>

DataChartView::DataChartView(unsigned int ID, DataLogger* pDataLogger, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataChartView),
    m_ID(ID),
    m_pDataLogger(pDataLogger),
    m_bConnectedToDataChangedSignal(false)
{
    setWindowIcon(QIcon(QDir::currentPath() + "\\resources\\icon.ico"));

    ui->setupUi(this);

    FillData();
}

DataChartView::~DataChartView()
{
    delete ui;
    delete m_pChart;
    delete m_pChartView;
    delete m_pDataSeries;
}

void DataChartView::FillData()
{

    DataInfo* pDataInfo = m_pDataLogger->GetDataArray(m_ID);
    if(pDataInfo == nullptr)
    {
        qDebug() << "Error while getting data array for ID: " << m_ID;
        close();
    }

    m_pDataSeries = pDataInfo->m_pData;

    // m_pDataSeries = new QLineSeries;
    //
    // unsigned counter = 0;
    // unsigned int i = pDataInfo->m_iter;
    // do
    // {
    //     m_pDataSeries->append(i, pDataInfo->m_pData[counter++]); // TODO
    //     i = (i + 1) % BufferSize;
    // }while(i != pDataInfo->m_iter);

    m_pChart = new QChart;
    m_pChart->legend()->hide();
    m_pChart->addSeries(m_pDataSeries);
    m_pChart->createDefaultAxes();

    m_pChartView = new QChartView(m_pChart, this);
    ui->gridLayout_2->addWidget(m_pChartView);
    m_pChartView->show();

    if(!m_bConnectedToDataChangedSignal)
    {
        connect(pDataInfo, &DataInfo::seriesChanged, this, &DataChartView::Update);
        m_bConnectedToDataChangedSignal = true;
    }


}

void DataChartView::Update()
{
    m_pChart->axisX()->setRange(m_pDataSeries->at(0).x(), m_pDataSeries->at(m_pDataSeries->count() - 1).x());
    auto points = m_pDataSeries->pointsVector();
    std::sort(points.begin(), points.end(), [&](QPointF& a, QPointF& b){ return a.y() <= b.y(); });
    m_pChart->axisY()->setRange(points.front().y(), points.back().y());
}

void DataChartView::on_btnClose_clicked()
{
    close();
}
