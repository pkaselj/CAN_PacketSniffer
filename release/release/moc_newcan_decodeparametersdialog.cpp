/****************************************************************************
** Meta object code from reading C++ file 'newcan_decodeparametersdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../newcan_decodeparametersdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newcan_decodeparametersdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NewCAN_DecodeParametersDialog_t {
    QByteArrayData data[11];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewCAN_DecodeParametersDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewCAN_DecodeParametersDialog_t qt_meta_stringdata_NewCAN_DecodeParametersDialog = {
    {
QT_MOC_LITERAL(0, 0, 29), // "NewCAN_DecodeParametersDialog"
QT_MOC_LITERAL(1, 30, 27), // "NewCAN_DecodeParameterAdded"
QT_MOC_LITERAL(2, 58, 0), // ""
QT_MOC_LITERAL(3, 59, 2), // "ID"
QT_MOC_LITERAL(4, 62, 20), // "CAN_DecodeParameters"
QT_MOC_LITERAL(5, 83, 6), // "params"
QT_MOC_LITERAL(6, 90, 12), // "FormAccepted"
QT_MOC_LITERAL(7, 103, 13), // "Reject_wAlert"
QT_MOC_LITERAL(8, 117, 7), // "message"
QT_MOC_LITERAL(9, 125, 25), // "on_rbLittleEndian_clicked"
QT_MOC_LITERAL(10, 151, 22) // "on_rbBigEndian_clicked"

    },
    "NewCAN_DecodeParametersDialog\0"
    "NewCAN_DecodeParameterAdded\0\0ID\0"
    "CAN_DecodeParameters\0params\0FormAccepted\0"
    "Reject_wAlert\0message\0on_rbLittleEndian_clicked\0"
    "on_rbBigEndian_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewCAN_DecodeParametersDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   44,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,
       9,    0,   48,    2, 0x08 /* Private */,
      10,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewCAN_DecodeParametersDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NewCAN_DecodeParametersDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NewCAN_DecodeParameterAdded((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< CAN_DecodeParameters(*)>(_a[2]))); break;
        case 1: _t->FormAccepted(); break;
        case 2: _t->Reject_wAlert((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_rbLittleEndian_clicked(); break;
        case 4: _t->on_rbBigEndian_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NewCAN_DecodeParametersDialog::*)(unsigned int , CAN_DecodeParameters );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NewCAN_DecodeParametersDialog::NewCAN_DecodeParameterAdded)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NewCAN_DecodeParametersDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_NewCAN_DecodeParametersDialog.data,
    qt_meta_data_NewCAN_DecodeParametersDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NewCAN_DecodeParametersDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewCAN_DecodeParametersDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NewCAN_DecodeParametersDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int NewCAN_DecodeParametersDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void NewCAN_DecodeParametersDialog::NewCAN_DecodeParameterAdded(unsigned int _t1, CAN_DecodeParameters _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
