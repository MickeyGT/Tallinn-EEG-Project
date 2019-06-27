/****************************************************************************
** Meta object code from reading C++ file 'ShooterGameConnection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ShooterGameConnection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ShooterGameConnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ShooterGameConnection_t {
    QByteArrayData data[8];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShooterGameConnection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShooterGameConnection_t qt_meta_stringdata_ShooterGameConnection = {
    {
QT_MOC_LITERAL(0, 0, 21), // "ShooterGameConnection"
QT_MOC_LITERAL(1, 22, 27), // "updateBitalinoDeviceFftFlag"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 23), // "processTimeDomainValues"
QT_MOC_LITERAL(4, 75, 12), // "QVector<int>"
QT_MOC_LITERAL(5, 88, 16), // "processFftValues"
QT_MOC_LITERAL(6, 105, 20), // "QPair<double,double>"
QT_MOC_LITERAL(7, 126, 20) // "notifyBitalinoFftMap"

    },
    "ShooterGameConnection\0updateBitalinoDeviceFftFlag\0"
    "\0processTimeDomainValues\0QVector<int>\0"
    "processFftValues\0QPair<double,double>\0"
    "notifyBitalinoFftMap"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShooterGameConnection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   37,    2, 0x0a /* Public */,
       5,    1,   40,    2, 0x0a /* Public */,
       7,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void ShooterGameConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ShooterGameConnection *_t = static_cast<ShooterGameConnection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateBitalinoDeviceFftFlag((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->processTimeDomainValues((*reinterpret_cast< const QVector<int>(*)>(_a[1]))); break;
        case 2: _t->processFftValues((*reinterpret_cast< const QPair<double,double>(*)>(_a[1]))); break;
        case 3: _t->notifyBitalinoFftMap((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ShooterGameConnection::*)(const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShooterGameConnection::updateBitalinoDeviceFftFlag)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ShooterGameConnection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ShooterGameConnection.data,
      qt_meta_data_ShooterGameConnection,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ShooterGameConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShooterGameConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ShooterGameConnection.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ShooterGameConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ShooterGameConnection::updateBitalinoDeviceFftFlag(const bool & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
