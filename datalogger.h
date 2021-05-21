#ifndef DATALOGGER_H
#define DATALOGGER_H

#include <QObject>
#include <QHash>
#include "Structures.h"

using DataTable = QHash<unsigned int, DataInfo*>; // TODO Memory Leak
using DataTableIter = QHashIterator<unsigned int, DataInfo*>;

class DataLogger : public QObject
{
    Q_OBJECT
public:
    explicit DataLogger(QObject *parent = nullptr);

    DataTableIter getDataIter() { return DataTableIter(m_dataTable); }

public slots:
   void InsertTableEntry(TableEntry data);
   void InsertData(unsigned int ID, uint64_t value);
   void DropData(unsigned ID);
   DataInfo* GetDataArray(unsigned int ID);



signals:

private:
    DataTable m_dataTable;

};

#endif // DATALOGGER_H
