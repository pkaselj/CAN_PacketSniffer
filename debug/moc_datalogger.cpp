/****************************************************************************
** Meta object code from reading C++ file 'datalogger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../datalogger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datalogger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataLogger_t {
    QByteArrayData data[12];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataLogger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataLogger_t qt_meta_stringdata_DataLogger = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DataLogger"
QT_MOC_LITERAL(1, 11, 16), // "InsertTableEntry"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "TableEntry"
QT_MOC_LITERAL(4, 40, 4), // "data"
QT_MOC_LITERAL(5, 45, 10), // "InsertData"
QT_MOC_LITERAL(6, 56, 2), // "ID"
QT_MOC_LITERAL(7, 59, 8), // "uint64_t"
QT_MOC_LITERAL(8, 68, 5), // "value"
QT_MOC_LITERAL(9, 74, 8), // "DropData"
QT_MOC_LITERAL(10, 83, 12), // "GetDataArray"
QT_MOC_LITERAL(11, 96, 9) // "DataInfo*"

    },
    "DataLogger\0InsertTableEntry\0\0TableEntry\0"
    "data\0InsertData\0ID\0uint64_t\0value\0"
    "DropData\0GetDataArray\0DataInfo*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataLogger[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       5,    2,   37,    2, 0x0a /* Public */,
       9,    1,   42,    2, 0x0a /* Public */,
      10,    1,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::UInt,    6,
    0x80000000 | 11, QMetaType::UInt,    6,

       0        // eod
};

void DataLogger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataLogger *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->InsertTableEntry((*reinterpret_cast< TableEntry(*)>(_a[1]))); break;
        case 1: _t->InsertData((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint64_t(*)>(_a[2]))); break;
        case 2: _t->DropData((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 3: { DataInfo* _r = _t->GetDataArray((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< DataInfo**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataLogger::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DataLogger.data,
    qt_meta_data_DataLogger,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataLogger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataLogger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataLogger.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataLogger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
