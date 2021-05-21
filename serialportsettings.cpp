#include "serialportsettings.h"
#include "ui_serialportsettings.h"

SerialPortSettings::SerialPortSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialPortSettings)
{
    ui->setupUi(this);

    pMenuBaudRate = ui->menuBaudRate;
    pMenuSerialPorts = ui->menuSerialPorts;

    m_availablePorts = SerialReader::getAvailableSerialPorts();
    displayAvailablePorts();

    m_availableBaudRates = SerialReader::getAvailableBaudRates();
    displayAvailableBaudRates();

}

SerialPortSettings::~SerialPortSettings()
{
    delete ui;
}

void SerialPortSettings::displayAvailablePorts()
{
    QStringList availablePortNames;
    for (const auto& portInfo : m_availablePorts)
    {
        availablePortNames.append(portInfo.portName());
    }

    ui->menuSerialPorts->addItems(availablePortNames);
}

void SerialPortSettings::displayAvailableBaudRates()
{
    QStringList availableBaudRates;
    for (const auto& baudRate : m_availableBaudRates)
    {
        availableBaudRates.append(QString::number(baudRate));
    }

    ui->menuBaudRate->addItems(availableBaudRates);
    setDefault_BaudRate_9600();
}

void SerialPortSettings::setDefault_BaudRate_9600()
{

    for(int i = 0; i < pMenuBaudRate->count(); ++i)
    {
        if(pMenuBaudRate->itemText(i) == "9600")
        {
            pMenuBaudRate->setCurrentIndex(i);
        }
    }
}

int SerialPortSettings::findSerialPortInfoByName(QString& portName)
{
    int index = -1;

    for(int i = 0; i < m_availablePorts.count(); ++i)
    {
        if(m_availablePorts.at(i).portName() == portName)
        {
            return i;
        }
    }

    return index;
}

void SerialPortSettings::on_buttonBox_accepted()
{
    SerialPortConnectionInfo connectionInfo;

    QString selectedSerialPortName = pMenuSerialPorts->currentText();
    int selectedPortIndex = findSerialPortInfoByName(selectedSerialPortName);
    if(selectedPortIndex < 0)
    {
        qDebug() << "Could not find port name: " << selectedSerialPortName;
        return;
    }

    connectionInfo.m_serialPortInfo = m_availablePorts.at(selectedPortIndex);

    QString selectedBaudRate_String = pMenuBaudRate->currentText();
    qint32 selectedBaudRate = selectedBaudRate_String.toInt();
    connectionInfo.m_baudRate = selectedBaudRate;

    emit SerialPortSettingsChanged(connectionInfo);
}
