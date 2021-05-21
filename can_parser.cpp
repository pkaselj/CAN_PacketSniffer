#include "can_parser.h"

#include <QDebug>
#include <QDateTime>

CAN_Parser::CAN_Parser(QObject *parent) : QObject(parent)
{

}

void CAN_Parser::AddEntry(unsigned int ID, CAN_DecodeParameters decodeParameters)
{
    m_decodeTable[ID] = decodeParameters;
    emit CAN_DecodeParametersChanged(ID);

}

void CAN_Parser::DecodeData(RawData rawPacket)
{
    TableEntry decodedData;

    if(m_decodeTable.contains(rawPacket.m_ID) == false)
    {
        qDebug() << QString("Received invalid data with ID: %1").arg(rawPacket.m_ID);

        decodedData = DecodeData_NonExistent(rawPacket);
    }
    else
    {
        decodedData = DecodeData_Existing(rawPacket);
    }

    decodedData.m_rawHex = QByteArray::fromRawData((const char*)rawPacket.m_value, sizeof(RawData::m_value));

    emit DataSuccessfullyDecoded(decodedData);
}

TableEntry CAN_Parser::DecodeData_Existing(RawData rawData)
{
    CAN_DecodeParameters params = m_decodeTable.value(rawData.m_ID);

    TableEntry decodedData;
    decodedData.m_unit = params.m_unit;
    decodedData.m_timestamp = QDateTime::currentDateTime().toString("hh:mm:ss,zzz");
    decodedData.m_ID = rawData.m_ID;

    uint64_t decodedValue = DecodeValue(rawData);

    qDebug() << "DECODED VALUE #1 " << decodedValue;

    decodedData.m_value = decodedValue * params.m_multiplier + params.m_offset;

    decodedData.m_endianness = params.m_bigEndian ? "BIG ENDIAN" : "LITTLE ENDIAN";

    return decodedData;
}

TableEntry CAN_Parser::DecodeData_NonExistent(RawData rawData)
{
    TableEntry decodedData;
    decodedData.m_unit = "RAW [DEC]";
    decodedData.m_timestamp = QDateTime::currentDateTime().toString("hh:mm:ss,zzz");
    decodedData.m_ID = rawData.m_ID;
    decodedData.m_value = DecodeValue(rawData);
    decodedData.m_endianness = "LITTLLE ENDIAN";

    return decodedData;
}

uint64_t CAN_Parser::DecodeValue(RawData& rawData)
{
    CAN_DecodeParameters decodeParameters;
    decodeParameters.m_valueMask = CAN_DecodeParameters::enuValueMask::ACCEPT_ALL;

    if(m_decodeTable.contains(rawData.m_ID) == true)
    {
        decodeParameters = m_decodeTable.value(rawData.m_ID);
    }

    uint64_t value = 0;

    QByteArray temp = QByteArray::fromRawData((const char*)rawData.m_value, 8);
    print("RAW VALUE", temp);
    qDebug() << "Value mask: " << decodeParameters.m_valueMask;

    if(decodeParameters.m_bigEndian)
    {
        qDebug() << "BIG ENDIAN";
        for(int i = 0; i < 8; ++i)
        {
            if(decodeParameters.m_valueMask & (1 << i))
            {
                qDebug() << "i = " << i << " value = " << (int)rawData.m_value[i];
                value = value << 8;
                value += (uint8_t)rawData.m_value[i];
            }
        }
    }
    else
    {
        qDebug() << "LITTLE ENDIAN";
        for(int i = 7; i >=0; --i)
        {
            if(decodeParameters.m_valueMask & (1 << i))
            {
                qDebug() << "i = " << i << " value = " << (int)rawData.m_value[i];
                value = value << 8;
                value += (uint8_t)rawData.m_value[i];
            }
        }
    }

    qDebug() << "VALUE: " << value;

    return value;
}

void CAN_Parser::RemoveEntry(unsigned int ID)
{
    if(!m_decodeTable.contains(ID))
    {
        qDebug() << "Decode table doesn't contain ID: " << ID;
        return;
    }

    m_decodeTable.remove(ID);
    emit CAN_DecodeParametersChanged(ID);
}
