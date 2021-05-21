#include "Structures.h"

CAN_DecodeParameters::enuValueMask operator| (CAN_DecodeParameters::enuValueMask a, CAN_DecodeParameters::enuValueMask b)
{
    return static_cast<CAN_DecodeParameters::enuValueMask>((uint8_t)a | (uint8_t)b);
}

CAN_DecodeParameters::enuValueMask operator& (CAN_DecodeParameters::enuValueMask a, CAN_DecodeParameters::enuValueMask b)
{
    return static_cast<CAN_DecodeParameters::enuValueMask>((uint8_t)a & (uint8_t)b);
}

DataInfo::DataInfo(const DataInfo& other)
{
    memcpy(m_pData, other.m_pData, BufferSize);
    m_iter = other.m_iter;
    m_pointCount = other.m_pointCount;
}

DataInfo& DataInfo::operator= (const DataInfo& other)
{
    if(&other == this) return *this;

    memcpy(m_pData, other.m_pData, BufferSize);
    m_iter = other.m_iter;
    m_pointCount = other.m_pointCount;

    return *this;
}

DataInfo::DataInfo(DataInfo&& other)
{
    m_pData = other.m_pData;
    m_iter = other.m_iter;
    m_pointCount = other.m_pointCount;

    other.m_pData = nullptr;
    other.m_iter = 0;
    other.m_pointCount = 0;
}

DataInfo& DataInfo::operator= (DataInfo&& other)
{
    if(&other == this) return *this;

    m_pData = other.m_pData;
    m_iter = other.m_iter;
    m_pointCount = other.m_pointCount;

    other.m_pData = nullptr;
    other.m_iter = 0;
    other.m_pointCount = 0;

    return *this;
}

void DataInfo::addPoint(uint64_t point)
{
    m_pData->append(m_pointCount, point);
    ++m_pointCount;
    if(m_pointCount >= BufferSize)
    {
        m_pData->remove(0);
    }

    emit seriesChanged();
}

void print(const QString& name, const QByteArray& arr)
{
    QString temp = "";
    for(int i = 0; i < arr.size(); ++i)
    {
        temp += QString::number((uint8_t)arr.at(i), 16);
        temp += " ";
    }

    qDebug() << "ARRAY: " << name << " - " << temp;
}
