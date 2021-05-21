/****************************************************************************
** Meta object code from reading C++ file 'can_decodeparametersview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../can_decodeparametersview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'can_decodeparametersview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CAN_DecodeParametersView_t {
    QByteArrayData data[12];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAN_DecodeParametersView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAN_DecodeParametersView_t qt_meta_stringdata_CAN_DecodeParametersView = {
    {
QT_MOC_LITERAL(0, 0, 24), // "CAN_DecodeParametersView"
QT_MOC_LITERAL(1, 25, 6), // "AddRow"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 2), // "ID"
QT_MOC_LITERAL(4, 36, 20), // "CAN_DecodeParameters"
QT_MOC_LITERAL(5, 57, 6), // "params"
QT_MOC_LITERAL(6, 64, 17), // "on_btnAdd_clicked"
QT_MOC_LITERAL(7, 82, 17), // "CellDoubleClicked"
QT_MOC_LITERAL(8, 100, 3), // "row"
QT_MOC_LITERAL(9, 104, 3), // "col"
QT_MOC_LITERAL(10, 108, 18), // "on_btnEdit_clicked"
QT_MOC_LITERAL(11, 127, 20) // "on_btnDelete_clicked"

    },
    "CAN_DecodeParametersView\0AddRow\0\0ID\0"
    "CAN_DecodeParameters\0params\0"
    "on_btnAdd_clicked\0CellDoubleClicked\0"
    "row\0col\0on_btnEdit_clicked\0"
    "on_btnDelete_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAN_DecodeParametersView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    2,   45,    2, 0x08 /* Private */,
      10,    0,   50,    2, 0x08 /* Private */,
      11,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4,    3,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CAN_DecodeParametersView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CAN_DecodeParametersView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AddRow((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< CAN_DecodeParameters(*)>(_a[2]))); break;
        case 1: _t->on_btnAdd_clicked(); break;
        case 2: _t->CellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_btnEdit_clicked(); break;
        case 4: _t->on_btnDelete_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CAN_DecodeParametersView::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CAN_DecodeParametersView.data,
    qt_meta_data_CAN_DecodeParametersView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CAN_DecodeParametersView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAN_DecodeParametersView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CAN_DecodeParametersView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CAN_DecodeParametersView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
