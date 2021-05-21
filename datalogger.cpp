#include "datalogger.h"

DataLogger::DataLogger(QObject *parent) : QObject(parent)
{

}

void DataLogger::InsertTableEntry(TableEntry data)
{
    InsertData(data.m_ID, data.m_value);
}

void DataLogger::InsertData(unsigned int ID, uint64_t value)
{
    if(!m_dataTable.contains(ID))
    {
        m_dataTable[ID] = new DataInfo;
    }

    DataInfo* pDataBlock = m_dataTable[ID];
    pDataBlock->addPoint(value);
    pDataBlock->m_iter = (++pDataBlock->m_iter) % BufferSize;
}

void DataLogger::DropData(unsigned ID)
{
    if(m_dataTable.contains(ID))
    {
        m_dataTable.remove(ID);
    }
}

DataInfo* DataLogger::GetDataArray(unsigned int ID)
{
    if(!m_dataTable.contains(ID))
    {
        return nullptr;
    }

    return m_dataTable[ID];
}
