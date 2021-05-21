#ifndef CAN_DECODEPARAMETERSVIEW_H
#define CAN_DECODEPARAMETERSVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QTableWidget>
#include <can_parser.h>

namespace Ui {
class CAN_DecodeParametersView;
}

class CAN_DecodeParametersView : public QWidget
{
    Q_OBJECT

public:
    explicit CAN_DecodeParametersView(CAN_Parser* pCAN_Parser, QWidget *parent = nullptr);
    ~CAN_DecodeParametersView();

    const int ID_col = 0;
    const int Unit_col = 1;
    const int Multiplier_col = 2;
    const int Offset_col = 3;
    const int ValueByteMask_col = 4;
    const int Endianness_col = 5;

public slots:
    void AddRow(unsigned int ID, CAN_DecodeParameters params);

private slots:
    void on_btnAdd_clicked();
    void CellDoubleClicked(int row, int col);

    void on_btnEdit_clicked();

    void on_btnDelete_clicked();

private:
    Ui::CAN_DecodeParametersView *ui;
    QPushButton* m_pBtnAdd;
    QPushButton* m_pBtnClose;
    QTableWidget* m_pTable;
    CAN_Parser* m_pCAN_Parser;


    void SetupTable();
    void FillTable();
};

#endif // CAN_DECODEPARAMETERSVIEW_H
