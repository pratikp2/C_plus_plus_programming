/****************************************************************************
** Meta object code from reading C++ file 'demoif.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "demoif.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'demoif.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DemoIf_t {
    QByteArrayData data[9];
    char stringdata[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_DemoIf_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_DemoIf_t qt_meta_stringdata_DemoIf = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 9),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 9),
QT_MOC_LITERAL(4, 28, 6),
QT_MOC_LITERAL(5, 35, 19),
QT_MOC_LITERAL(6, 55, 8),
QT_MOC_LITERAL(7, 64, 4),
QT_MOC_LITERAL(8, 69, 10)
    },
    "DemoIf\0LateEvent\0\0eventkind\0SayBye\0"
    "QDBusPendingReply<>\0SayHello\0name\0"
    "customdata\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DemoIf[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   32,    2, 0x0a,
       6,    2,   33,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    0x80000000 | 5,
    0x80000000 | 5, QMetaType::QString, QMetaType::QVariantMap,    7,    8,

       0        // eod
};

void DemoIf::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DemoIf *_t = static_cast<DemoIf *>(_o);
        switch (_id) {
        case 0: _t->LateEvent((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: { QDBusPendingReply<> _r = _t->SayBye();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        case 2: { QDBusPendingReply<> _r = _t->SayHello((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DemoIf::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DemoIf::LateEvent)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject DemoIf::staticMetaObject = {
    { &QDBusAbstractInterface::staticMetaObject, qt_meta_stringdata_DemoIf.data,
      qt_meta_data_DemoIf,  qt_static_metacall, 0, 0}
};


const QMetaObject *DemoIf::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DemoIf::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DemoIf.stringdata))
        return static_cast<void*>(const_cast< DemoIf*>(this));
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int DemoIf::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DemoIf::LateEvent(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
