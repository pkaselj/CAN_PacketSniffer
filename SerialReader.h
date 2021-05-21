#ifndef SERIALREADERTHREAD_H
#define SERIALREADERTHREAD_H

#include <QtCore>
#include <QtSerialPort>
#include <QSerialPortInfo>
#include "Structures.h"

class SerialReader : public QObject
{
    Q_OBJECT

public:
    SerialReader(QApplication* pParent);
    ~SerialReader();

    void Start();

    static QList<QSerialPortInfo> getAvailableSerialPorts();
    static QList<qint32> getAvailableBaudRates();


signals:
    Q_SIGNAL void DataReceived(RawData tableEntry);

public slots:
    Q_SLOT void StopExecution();
    void ConnectToSerialPort(SerialPortConnectionInfo connectionInfo);

private:
    bool m_bStop;
    bool m_bConnected;

    QByteArray m_receivedData;

    QSerialPort* m_pSerialPort;

    void run();
    RawData AcquireData();

    void ReadAndAppendNewDataToBuffer();
    void TruncateBufferToSyncSequence();
    bool isBufferFilled() const;
    QByteArray GetRawCAN_PacketAndTruncateBuffer();
    RawData DeserializeRawCAN_Packet(QByteArray& rawCAN_Packet);

private slots:
    void DataReadyToBeRead();

};

#endif // SERIALREADERTHREAD_H
