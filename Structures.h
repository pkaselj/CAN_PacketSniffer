#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <QtCore>
#include <QtSerialPort>
#include <QtCharts>

struct TableEntry
{
    uint32_t m_ID;
    uint64_t m_value;
    QByteArray m_rawHex;
    QString m_unit;
    QString m_timestamp;
    QString m_endianness;
};

struct CAN_DecodeParameters
{
    typedef enum : uint8_t
    {
        IGNORE_ALL = 0,
        BYTE_0 = 1,
        BYTE_1 = 1 << 1,
        BYTE_2 = 1 << 2,
        BYTE_3 = 1 << 3,
        BYTE_4 = 1 << 4,
        BYTE_5 = 1 << 5,
        BYTE_6 = 1 << 6,
        BYTE_7 = 1 << 7,
        ACCEPT_ALL = 0xFF,
    } enuValueMask;

    CAN_DecodeParameters()
        : m_multiplier(0),
          m_offset(0),
          m_unit(QString("Invalid parameters!")),
          m_valueMask(ACCEPT_ALL),
          m_bigEndian(false)
    { }

    CAN_DecodeParameters(int multiplier, int offset, QString unit, enuValueMask valueMask, bool bigEndian)
        :   m_multiplier(multiplier),
            m_offset(offset),
            m_unit(unit),
            m_valueMask(valueMask),
            m_bigEndian(bigEndian)
    { }

    int m_multiplier;
    int m_offset;
    QString m_unit;
    enuValueMask m_valueMask;
    bool m_bigEndian;
};

CAN_DecodeParameters::enuValueMask operator| (CAN_DecodeParameters::enuValueMask a, CAN_DecodeParameters::enuValueMask b);
CAN_DecodeParameters::enuValueMask operator& (CAN_DecodeParameters::enuValueMask a, CAN_DecodeParameters::enuValueMask b);

const uint8_t SYNC_SEQUENCE = (uint8_t)'A';

struct RawData
{
    uint32_t m_ID = 0;
    uint8_t m_value[8] = {0};
};

struct CAN_DecodeParameters_Stringified
{
    QString m_qstrMultiplier;
    QString m_qstrOffset;
    QString m_qstrUnit;
    QString m_qstrValueMask;
    QString m_endianness;

};

const unsigned int BufferSize = 100;

class DataInfo : public QObject
{
    Q_OBJECT
public:
    DataInfo() : m_pData( new QLineSeries() ), m_iter(0), m_pointCount(0) {}
    ~DataInfo() { delete m_pData; }

    DataInfo(const DataInfo& other);
    DataInfo& operator= (const DataInfo& other);
    DataInfo(DataInfo&& other);
    DataInfo& operator= (DataInfo&& other);

    void addPoint(uint64_t point);

    QLineSeries* m_pData;
    unsigned int m_iter;
    unsigned int m_pointCount;

signals:
    void seriesChanged();
};

struct SerialPortConnectionInfo
{
    QSerialPortInfo m_serialPortInfo;
    qint32 m_baudRate;
};

void print(const QString& name, const QByteArray& arr);


#endif // TABLEENTRY_H
