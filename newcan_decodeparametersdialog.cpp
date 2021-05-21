#include "newcan_decodeparametersdialog.h"
#include "ui_newcan_decodeparametersdialog.h"
#include <QDebug>
#include <QMessageBox>

void NewCAN_DecodeParametersDialog::init()
{
    ui->setupUi(this);

    LoadCheckboxArray();
    LoadCheckboxToMaskMap();

    on_rbLittleEndian_clicked();

    connect(this, &QDialog::accepted, this, &NewCAN_DecodeParametersDialog::FormAccepted);
}

NewCAN_DecodeParametersDialog::NewCAN_DecodeParametersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCAN_DecodeParametersDialog),
    m_bError(false)
{
    init();

}

NewCAN_DecodeParametersDialog::NewCAN_DecodeParametersDialog(QString qstrID_hex, CAN_DecodeParameters_Stringified preset, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCAN_DecodeParametersDialog),
    m_bError(false)

{
    init();
    FillData(qstrID_hex, preset);
}

void NewCAN_DecodeParametersDialog::FillData(QString qstrID_hex, const CAN_DecodeParameters_Stringified& data)
{
    ui->txtID->setText(qstrID_hex);
    ui->txtMultiplier->setText(data.m_qstrMultiplier);
    ui->txtUnit->setText(data.m_qstrUnit);
    ui->txtOffset->setText(data.m_qstrOffset);

    for(int i = 0; i < 8; ++i)
    {
        if(data.m_qstrValueMask.at(i) == '1')
        {
            m_chkValueMask[7 - i]->setChecked(true);
        }
    }

    if(data.m_endianness == "BIG ENDIAN")
    {
        ui->rbBigEndian->setChecked(true);
        ui->rbLittleEndian->setChecked(false);
    }
    else
    {
        ui->rbBigEndian->setChecked(false);
        ui->rbLittleEndian->setChecked(true);
    }
}

NewCAN_DecodeParametersDialog::~NewCAN_DecodeParametersDialog()
{
    delete ui;
}

void NewCAN_DecodeParametersDialog::LoadCheckboxArray()
{
    m_chkValueMask[0] = ui->chkByte0;
    m_chkValueMask[1] = ui->chkByte1;
    m_chkValueMask[2] = ui->chkByte2;
    m_chkValueMask[3] = ui->chkByte3;
    m_chkValueMask[4] = ui->chkByte4;
    m_chkValueMask[5] = ui->chkByte5;
    m_chkValueMask[6] = ui->chkByte6;
    m_chkValueMask[7] = ui->chkByte7;
}

void NewCAN_DecodeParametersDialog::LoadCheckboxToMaskMap()
{
    m_mapCheckboxToMask[0] = CAN_DecodeParameters::enuValueMask::BYTE_0;
    m_mapCheckboxToMask[1] = CAN_DecodeParameters::enuValueMask::BYTE_1;
    m_mapCheckboxToMask[2] = CAN_DecodeParameters::enuValueMask::BYTE_2;
    m_mapCheckboxToMask[3] = CAN_DecodeParameters::enuValueMask::BYTE_3;
    m_mapCheckboxToMask[4] = CAN_DecodeParameters::enuValueMask::BYTE_4;
    m_mapCheckboxToMask[5] = CAN_DecodeParameters::enuValueMask::BYTE_5;
    m_mapCheckboxToMask[6] = CAN_DecodeParameters::enuValueMask::BYTE_6;
    m_mapCheckboxToMask[7] = CAN_DecodeParameters::enuValueMask::BYTE_7;
}

void NewCAN_DecodeParametersDialog::FormAccepted()
{
    qDebug() << "Accepted dialog!";

    if(hasEmptyField())
    {
        QMessageBox mbox;

        mbox.setText("Form has empty fields!");
        mbox.setIcon(QMessageBox::Icon::Critical);
        mbox.exec();

        return;
    }

    CAN_DecodeParameters result;

    result.m_unit = ui->txtUnit->text();
    if(m_bError) return;

    result.m_multiplier = GetMultiplier();
    if(m_bError) return;

    result.m_offset = GetOffset();
    if(m_bError) return;

    result.m_valueMask = GetValueMask();
    if(m_bError) return;

    int ID = GetID();
    if(m_bError) return;

    result.m_bigEndian = ui->rbBigEndian->isChecked();

    emit NewCAN_DecodeParameterAdded(ID, result);
}

CAN_DecodeParameters::enuValueMask NewCAN_DecodeParametersDialog::GetValueMask()
{
    CAN_DecodeParameters::enuValueMask mask = CAN_DecodeParameters::enuValueMask::IGNORE_ALL;

    for (int i = 0; i < 8; ++i)
    {
        if(m_chkValueMask[i]->isChecked())
        {
            mask = mask | m_mapCheckboxToMask[i];
        }
    }

    return mask;
}

int NewCAN_DecodeParametersDialog::GetID()
{
    QString qstrID = ui->txtID->text();

    bool ok = false;
    unsigned int ID = qstrID.toUInt(&ok, 0);

    if(!ok)
    {
        Reject_wAlert("Error while parsing ID!");
        return 0;
    }

    return ID;
}

int NewCAN_DecodeParametersDialog::GetMultiplier()
{
    bool ok = false;
    int multiplier = ui->txtMultiplier->text().toInt(&ok, 10);
    if(!ok)
    {
        Reject_wAlert("Error while parsing multiplier!");
        return 0;
    }

    return multiplier;
}

int NewCAN_DecodeParametersDialog::GetOffset()
{
    bool ok = false;
    int offset = ui->txtOffset->text().toInt(&ok, 10);
    if(!ok)
    {
        Reject_wAlert("Error while parsing offset!");
        return 0;
    }

    return offset;
}

bool NewCAN_DecodeParametersDialog::hasEmptyField()
{
    return ui->txtID->text().isEmpty() ||
            ui->txtMultiplier->text().isEmpty() ||
            ui ->txtOffset->text().isEmpty() ||
            ui->txtUnit->text().isEmpty();
}

void NewCAN_DecodeParametersDialog::Reject_wAlert(QString message)
{
    qDebug() << message;

    QMessageBox mbox;
    mbox.setText(message);
    mbox.setIcon(QMessageBox::Icon::Critical);
    mbox.exec();

    m_bError = true;

    reject();
    close();
}


void NewCAN_DecodeParametersDialog::on_rbLittleEndian_clicked()
{
    ui->rbBigEndian->setChecked(false);
    ui->lblLeftByte->setText("LSB");
    ui->lblRightByte->setText("MSB");
}

void NewCAN_DecodeParametersDialog::on_rbBigEndian_clicked()
{
    ui->rbLittleEndian->setChecked(false);
    ui->lblLeftByte->setText("MSB");
    ui->lblRightByte->setText("LSB");
}
