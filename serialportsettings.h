#ifndef SERIALPORTSETTINGS_H
#define SERIALPORTSETTINGS_H

#include <QDialog>
#include <SerialReader.h>
#include <QComboBox>

namespace Ui {
class SerialPortSettings;
}

class SerialPortSettings : public QDialog
{
    Q_OBJECT

public:
    explicit SerialPortSettings(QWidget *parent = nullptr);
    ~SerialPortSettings();

signals:
    void SerialPortSettingsChanged(SerialPortConnectionInfo connectionInfo);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SerialPortSettings *ui;

    QComboBox* pMenuBaudRate;
    QComboBox* pMenuSerialPorts;

    QList<QSerialPortInfo> m_availablePorts;
    QList<qint32> m_availableBaudRates;

    void displayAvailablePorts();
    void displayAvailableBaudRates();
    void setDefault_BaudRate_9600();

    int findSerialPortInfoByName(QString& portName);
};

#endif // SERIALPORTSETTINGS_H
