#include "can_decodeparametersview.h"
#include "ui_can_decodeparametersview.h"
#include "newcan_decodeparametersdialog.h"
#include <QMessageBox>


CAN_DecodeParametersView::CAN_DecodeParametersView(CAN_Parser* pCAN_Parser, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CAN_DecodeParametersView),
    m_pCAN_Parser(pCAN_Parser)
{

    setWindowIcon(QIcon(QDir::currentPath() + "\\resources\\icon.ico"));
    ui->setupUi(this);

    m_pBtnAdd = ui->btnAdd;
    m_pBtnClose = ui->btnClose;
    m_pTable = ui->tableWidget;

    connect(m_pBtnClose, &QPushButton::clicked, this, &QWidget::close);
    connect(m_pTable, &QTableWidget::cellDoubleClicked, this, &CAN_DecodeParametersView::CellDoubleClicked);

    SetupTable();
    FillTable();
}

CAN_DecodeParametersView::~CAN_DecodeParametersView()
{
    delete ui;
}

void CAN_DecodeParametersView::SetupTable()
{

    const QStringList tableHeaderLabels = {"ID", "Unit", "Multiplier", "Offset", "Value Byte Mask", "Endianess"};
    const bool bAlternateRowColors = true;

    m_pTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    m_pTable->setRowCount(0);
    m_pTable->setColumnCount(tableHeaderLabels.size());
    m_pTable->setAlternatingRowColors(bAlternateRowColors);
    m_pTable->setHorizontalHeaderLabels(tableHeaderLabels);

    m_pTable->setSelectionBehavior(QTableWidget::SelectRows);
    m_pTable->setSelectionMode(QTableWidget::SingleSelection);
}

void CAN_DecodeParametersView::FillTable()
{
    // Clear Table
    m_pTable->setRowCount(0);

    DecodeTableIter i = m_pCAN_Parser->getDecodeTableIter();

    while(i.hasNext())
    {
        i.next();
        AddRow(i.key(), i.value());
    }
}

void CAN_DecodeParametersView::AddRow(unsigned int ID, CAN_DecodeParameters params)
{
    unsigned int rowId = m_pTable->rowCount();
    m_pTable->insertRow(rowId);

    m_pTable->setItem(rowId, ID_col, new QTableWidgetItem(QString("0x%1").arg(ID, 0, 16)));
    m_pTable->setItem(rowId, Unit_col, new QTableWidgetItem(params.m_unit));
    m_pTable->setItem(rowId, Multiplier_col, new QTableWidgetItem(QString::number(params.m_multiplier)));
    m_pTable->setItem(rowId, Offset_col, new QTableWidgetItem(QString::number(params.m_offset)));
    m_pTable->setItem(rowId, ValueByteMask_col, new QTableWidgetItem(QString::number(params.m_valueMask, 2).rightJustified(8, '0')));
    m_pTable->setItem(rowId, Endianness_col, new QTableWidgetItem(params.m_bigEndian ? "BIG ENDIAN" : "LITTLE ENDIAN"));
}

void CAN_DecodeParametersView::on_btnAdd_clicked()
{
    NewCAN_DecodeParametersDialog* pDialog = new NewCAN_DecodeParametersDialog(this);

    connect(pDialog, &NewCAN_DecodeParametersDialog::NewCAN_DecodeParameterAdded, m_pCAN_Parser, &CAN_Parser::AddEntry);
    connect(pDialog, &NewCAN_DecodeParametersDialog::NewCAN_DecodeParameterAdded, this, &CAN_DecodeParametersView::FillTable);

    pDialog->exec();
}

void CAN_DecodeParametersView::CellDoubleClicked(int row, int col)
{
    QString qstrID = m_pTable->item(row, ID_col)->text();

    CAN_DecodeParameters_Stringified data;
    data.m_qstrMultiplier = m_pTable->item(row, Multiplier_col)->text();
    data.m_qstrOffset = m_pTable->item(row, Offset_col)->text();
    data.m_qstrUnit = m_pTable->item(row, Unit_col)->text();
    data.m_qstrValueMask = m_pTable->item(row, ValueByteMask_col)->text();
    data.m_endianness = m_pTable->item(row, Endianness_col)->text();

    qDebug() << "ID: " << qstrID << "\n"
             << "Multiplier: " << data.m_qstrMultiplier << "\n"
             << "Offset: " << data.m_qstrOffset << "\n"
             << "Unit: " << data.m_qstrUnit << "\n"
             << "ValueMask: " << data.m_qstrValueMask << "\n"
             << "Endianess: " << data.m_endianness << "\n";

    NewCAN_DecodeParametersDialog* pDialog = new NewCAN_DecodeParametersDialog(qstrID, data, this);

    connect(pDialog, &NewCAN_DecodeParametersDialog::NewCAN_DecodeParameterAdded, m_pCAN_Parser, &CAN_Parser::AddEntry);
    connect(pDialog, &NewCAN_DecodeParametersDialog::NewCAN_DecodeParameterAdded, this, &CAN_DecodeParametersView::FillTable);

    pDialog->exec();

}


void CAN_DecodeParametersView::on_btnEdit_clicked()
{
    auto selectedItemList = m_pTable->selectedItems();
    if(selectedItemList.isEmpty())
    {
        QMessageBox mbox;
        mbox.setText("No items selected!");
        mbox.setIcon(QMessageBox::Icon::Warning);
        mbox.exec();

        return;
    }

    auto selectedItem = selectedItemList.first();

    CellDoubleClicked(selectedItem->row(), selectedItem->column());
}

void CAN_DecodeParametersView::on_btnDelete_clicked()
{
    auto selectedItemList = m_pTable->selectedItems();
    if(selectedItemList.isEmpty())
    {
        QMessageBox mbox;
        mbox.setText("No items selected!");
        mbox.setIcon(QMessageBox::Icon::Warning);
        mbox.exec();

        return;
    }

    auto selectedItem = selectedItemList.first();

    int selectedRow = selectedItem->row();
    QString qstrID = m_pTable->item(selectedRow, ID_col)->text();
    int ID = qstrID.toInt(nullptr, 0);

    m_pCAN_Parser->RemoveEntry(ID);
    FillTable();
}
