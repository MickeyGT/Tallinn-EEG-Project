/****************************************************************************
** Meta object code from reading C++ file 'EEGsignals.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EEGsignals.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EEGsignals.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EEGsignals_t {
    QByteArrayData data[7];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EEGsignals_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EEGsignals_t qt_meta_stringdata_EEGsignals = {
    {
QT_MOC_LITERAL(0, 0, 10), // "EEGsignals"
QT_MOC_LITERAL(1, 11, 30), // "changeDancerSignalRecevingPort"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 31), // "changeDancerSignalSendingValues"
QT_MOC_LITERAL(4, 75, 15), // "alphaSignalPlot"
QT_MOC_LITERAL(5, 91, 4), // "data"
QT_MOC_LITERAL(6, 96, 20) // "alphaThetaSignalPlot"

    },
    "EEGsignals\0changeDancerSignalRecevingPort\0"
    "\0changeDancerSignalSendingValues\0"
    "alphaSignalPlot\0data\0alphaThetaSignalPlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EEGsignals[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    1,   36,    2, 0x0a /* Public */,
       6,    1,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void EEGsignals::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EEGsignals *_t = static_cast<EEGsignals *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeDancerSignalRecevingPort(); break;
        case 1: _t->changeDancerSignalSendingValues(); break;
        case 2: _t->alphaSignalPlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->alphaThetaSignalPlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EEGsignals::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_EEGsignals.data,
      qt_meta_data_EEGsignals,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EEGsignals::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EEGsignals::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EEGsignals.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int EEGsignals::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
