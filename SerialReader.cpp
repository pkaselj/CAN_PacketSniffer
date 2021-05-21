#include "SerialReader.h"
#include <QtConcurrent/QtConcurrent>
#include <QApplication>
#include <QRandomGenerator>
#include <QDateTime>
#include <QMessageBox>

SerialReader::SerialReader(QApplication* pParent)
    :   m_bStop(false),
      m_bConnected(false),
      m_pSerialPort(nullptr)
{
    qRegisterMetaType<RawData>("RawData");
    QObject::connect(pParent, &QApplication::aboutToQuit, this, &SerialReader::StopExecution);

    m_receivedData.clear();
}

SerialReader::~SerialReader()
{
    delete m_pSerialPort;
}

QList<QSerialPortInfo> SerialReader::getAvailableSerialPorts()
{
    return QSerialPortInfo::availablePorts();
}

QList<qint32> SerialReader::getAvailableBaudRates()
{
    qDebug() << "Available: " << QSerialPortInfo::standardBaudRates().count() << " baud rates!";
    return QSerialPortInfo::standardBaudRates();
}

void SerialReader::Start()
{
    QFuture<void> serialReaderThread = QtConcurrent::run(this, &SerialReader::run);
}

void SerialReader::run()
{
    while(!m_bStop)
    {
        qDebug() << "Signal";

        RawData data = AcquireData();
        emit DataReceived(data);

        QThread::sleep(1);
    }
}

void SerialReader::StopExecution()
{
    m_bStop = true;
}

RawData SerialReader::AcquireData()
{
    RawData temp;

    // temp.m_ID = QRandomGenerator::global()->generate() % 10;
    temp.m_ID = 0x0;

    for(int i = 0; i < 2; i++)
        temp.m_value[i] = QRandomGenerator::global()->generate() % 256;

    return temp;
}

void SerialReader::ConnectToSerialPort(SerialPortConnectionInfo connectionInfo)
{
    qDebug() << "Trying to open Serial port: " << connectionInfo.m_serialPortInfo.portName() << " connected! Baud rate: " << connectionInfo.m_baudRate;

    m_pSerialPort = new QSerialPort(connectionInfo.m_serialPortInfo);
    m_pSerialPort->setBaudRate(connectionInfo.m_baudRate);
    m_pSerialPort->setDataBits(QSerialPort::Data8);
    m_pSerialPort->setParity(QSerialPort::NoParity);
    m_pSerialPort->setStopBits(QSerialPort::OneStop);
    m_pSerialPort->setFlowControl(QSerialPort::NoFlowControl);

    if(!m_pSerialPort->open(QIODevice::ReadWrite))
    {
        qDebug() << "Serial port could not be opened!";

        QMessageBox msg;
        msg.setText("Serial port: " + connectionInfo.m_serialPortInfo.portName() + "\n" +
                    "Baud rate: " + QString::number(connectionInfo.m_baudRate) + "\n" +
                    "Couldn't be opened!");

        msg.setIcon(QMessageBox::Critical);
        msg.exec();

        return;
    }


    m_bConnected = true;

    connect(m_pSerialPort, &QSerialPort::readyRead, this, &SerialReader::DataReadyToBeRead);

    qDebug() << "Serial port: " << connectionInfo.m_serialPortInfo.portName() << " connected! Baud rate: " << connectionInfo.m_baudRate;
}

void SerialReader::DataReadyToBeRead()
{
    qDebug() << "Data arrived to serial port!";

    ReadAndAppendNewDataToBuffer();

    qDebug() << "Data read!";

    TruncateBufferToSyncSequence();

    qDebug() << "Data truncated!";

    if(!isBufferFilled())
    {
        qDebug() << "Buffer NOT filled";
        return;
    }

    qDebug() << "Buffer filled!!!!";

    QByteArray rawCAN_PacketByteArray = GetRawCAN_PacketAndTruncateBuffer();
    RawData refinedData = DeserializeRawCAN_Packet(rawCAN_PacketByteArray);

    emit DataReceived(refinedData);
}

void SerialReader::ReadAndAppendNewDataToBuffer()
{
    m_receivedData.append(m_pSerialPort->readAll());
    print("RECEIVED DATA", m_receivedData);
}

void SerialReader::TruncateBufferToSyncSequence()
{
    while(m_receivedData.at(0) != SYNC_SEQUENCE)
    {
        m_receivedData = m_receivedData.right(m_receivedData.size() - 1);
        qDebug() << "Truncate SIZE: " << m_receivedData.size();
        if(m_receivedData.size() == 0) break;
    }
}

bool SerialReader::isBufferFilled() const
{
    // +1 because of sync sequence at the start
    return m_receivedData.size() >= (sizeof(RawData) + sizeof(SYNC_SEQUENCE));
}

QByteArray SerialReader::GetRawCAN_PacketAndTruncateBuffer()
{
    QByteArray dataBuffer = m_receivedData.left(sizeof(RawData) + sizeof(SYNC_SEQUENCE));
    m_receivedData = m_receivedData.right(m_receivedData.size() - sizeof(RawData) - sizeof(SYNC_SEQUENCE));

    print("DATA BUFFER", dataBuffer);
    print("RECEIVED DATA LEFT", m_receivedData);

    return dataBuffer;
}

RawData SerialReader::DeserializeRawCAN_Packet(QByteArray& rawCAN_Packet)
{
    RawData refinedData;

    const char* pRawPacket = rawCAN_Packet.constData();
    memcpy(&refinedData.m_ID, pRawPacket + sizeof(SYNC_SEQUENCE), sizeof(RawData::m_ID));
    memcpy(&refinedData.m_value, pRawPacket + sizeof(SYNC_SEQUENCE) + sizeof(RawData::m_ID), sizeof(RawData::m_value));

    return refinedData;
}
