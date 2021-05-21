/****************************************************************************
** Meta object code from reading C++ file 'can_parser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../can_parser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'can_parser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CAN_Parser_t {
    QByteArrayData data[14];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAN_Parser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAN_Parser_t qt_meta_stringdata_CAN_Parser = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CAN_Parser"
QT_MOC_LITERAL(1, 11, 23), // "DataSuccessfullyDecoded"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 10), // "TableEntry"
QT_MOC_LITERAL(4, 47, 10), // "tableEntry"
QT_MOC_LITERAL(5, 58, 27), // "CAN_DecodeParametersChanged"
QT_MOC_LITERAL(6, 86, 2), // "ID"
QT_MOC_LITERAL(7, 89, 8), // "AddEntry"
QT_MOC_LITERAL(8, 98, 20), // "CAN_DecodeParameters"
QT_MOC_LITERAL(9, 119, 16), // "decodeParameters"
QT_MOC_LITERAL(10, 136, 11), // "RemoveEntry"
QT_MOC_LITERAL(11, 148, 10), // "DecodeData"
QT_MOC_LITERAL(12, 159, 7), // "RawData"
QT_MOC_LITERAL(13, 167, 9) // "rawPacket"

    },
    "CAN_Parser\0DataSuccessfullyDecoded\0\0"
    "TableEntry\0tableEntry\0CAN_DecodeParametersChanged\0"
    "ID\0AddEntry\0CAN_DecodeParameters\0"
    "decodeParameters\0RemoveEntry\0DecodeData\0"
    "RawData\0rawPacket"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAN_Parser[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   45,    2, 0x0a /* Public */,
      10,    1,   50,    2, 0x0a /* Public */,
      11,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::UInt,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 8,    6,    9,
    QMetaType::Void, QMetaType::UInt,    6,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void CAN_Parser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CAN_Parser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DataSuccessfullyDecoded((*reinterpret_cast< TableEntry(*)>(_a[1]))); break;
        case 1: _t->CAN_DecodeParametersChanged((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 2: _t->AddEntry((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< CAN_DecodeParameters(*)>(_a[2]))); break;
        case 3: _t->RemoveEntry((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 4: _t->DecodeData((*reinterpret_cast< RawData(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CAN_Parser::*)(TableEntry );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Parser::DataSuccessfullyDecoded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CAN_Parser::*)(unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAN_Parser::CAN_DecodeParametersChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CAN_Parser::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CAN_Parser.data,
    qt_meta_data_CAN_Parser,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CAN_Parser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAN_Parser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CAN_Parser.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CAN_Parser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CAN_Parser::DataSuccessfullyDecoded(TableEntry _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CAN_Parser::CAN_DecodeParametersChanged(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
