#ifndef NEWCAN_DECODEPARAMETERSDIALOG_H
#define NEWCAN_DECODEPARAMETERSDIALOG_H

#include <QDialog>
#include "Structures.h"
#include <QCheckBox>

namespace Ui {
class NewCAN_DecodeParametersDialog;
}

class NewCAN_DecodeParametersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewCAN_DecodeParametersDialog(QWidget *parent = nullptr);
    explicit NewCAN_DecodeParametersDialog(QString qstrID_hex, CAN_DecodeParameters_Stringified preset, QWidget *parent = nullptr);
    ~NewCAN_DecodeParametersDialog();

signals:
    void NewCAN_DecodeParameterAdded(unsigned int ID, CAN_DecodeParameters params);


private:
    Ui::NewCAN_DecodeParametersDialog *ui;
    QCheckBox* m_chkValueMask[8];
    CAN_DecodeParameters::enuValueMask m_mapCheckboxToMask[8];

    CAN_DecodeParameters::enuValueMask GetValueMask();
    int GetID();
    int GetMultiplier();
    int GetOffset();

    void LoadCheckboxArray();
    void LoadCheckboxToMaskMap();
    bool hasEmptyField();

    void init();

    void FillData(QString qstrID_hex, const CAN_DecodeParameters_Stringified& data);

    bool m_bError;


private slots:
    void FormAccepted();
    void Reject_wAlert(QString message);

    void on_rbLittleEndian_clicked();
    void on_rbBigEndian_clicked();
};

#endif // NEWCAN_DECODEPARAMETERSDIALOG_H
