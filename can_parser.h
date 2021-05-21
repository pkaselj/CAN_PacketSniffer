#ifndef CAN_PARSER_H
#define CAN_PARSER_H

#include <QObject>
#include <QHash>

#include "Structures.h"

using DecodeTable = QHash<unsigned int, CAN_DecodeParameters>;
using DecodeTableIter = QHashIterator<unsigned int, CAN_DecodeParameters>;

class CAN_Parser : public QObject
{
    Q_OBJECT
public:
    CAN_Parser(QObject *parent = nullptr);

    DecodeTableIter getDecodeTableIter() { return DecodeTableIter(m_decodeTable); }

signals:
    void DataSuccessfullyDecoded(TableEntry tableEntry);
    void CAN_DecodeParametersChanged(unsigned int ID);

public slots:
    void AddEntry(unsigned int ID, CAN_DecodeParameters decodeParameters);
    void RemoveEntry(unsigned int ID);
    void DecodeData(RawData rawPacket);

private:
    DecodeTable m_decodeTable;

    TableEntry DecodeData_Existing(RawData rawData);
    TableEntry DecodeData_NonExistent(RawData rawData);
    uint64_t DecodeValue(RawData& rawData);

};

#endif // CAN_PARSER_H
