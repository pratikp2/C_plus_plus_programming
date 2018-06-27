/****************************************************************************
** Meta object code from reading C++ file 'demoifadaptor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "demoifadaptor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'demoifadaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DemoIfAdaptor_t {
    QByteArrayData data[12];
    char stringdata[573];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_DemoIfAdaptor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_DemoIfAdaptor_t qt_meta_stringdata_DemoIfAdaptor = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 15),
QT_MOC_LITERAL(2, 30, 14),
QT_MOC_LITERAL(3, 45, 19),
QT_MOC_LITERAL(4, 65, 453),
QT_MOC_LITERAL(5, 478, 9),
QT_MOC_LITERAL(6, 488, 0),
QT_MOC_LITERAL(7, 489, 9),
QT_MOC_LITERAL(8, 499, 6),
QT_MOC_LITERAL(9, 506, 8),
QT_MOC_LITERAL(10, 515, 4),
QT_MOC_LITERAL(11, 520, 10)
    },
    "DemoIfAdaptor\0D-Bus Interface\0"
    "com.nokia.Demo\0D-Bus Introspection\0"
    "  <interface name=\"com.nokia.Demo\">\n    <method name=\"SayHello\">\n"
    "      <annotation value=\"QVariantMap\" name=\"com.trolltech.QtDBus.Qt"
    "TypeName.In1\"/>\n      <arg direction=\"in\" type=\"s\" name=\"name\""
    "/>\n      <arg direction=\"in\" type=\"a{sv}\" name=\"customdata\"/>\n"
    "    </method>\n    <method name=\"SayBye\"/>\n    <signal name=\"LateE"
    "vent\">\n      <arg direction=\"out\" type=\"s\" name=\"eventkind\"/>\n"
    "    </signal>\n  </interface>\n\0"
    "LateEvent\0\0eventkind\0SayBye\0SayHello\0"
    "name\0customdata\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DemoIfAdaptor[] = {

 // content:
       7,       // revision
       0,       // classname
       2,   14, // classinfo
       3,   18, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // signals: name, argc, parameters, tag, flags
       5,    1,   33,    6, 0x06,

 // slots: name, argc, parameters, tag, flags
       8,    0,   36,    6, 0x0a,
       9,    2,   37,    6, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantMap,   10,   11,

       0        // eod
};

void DemoIfAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DemoIfAdaptor *_t = static_cast<DemoIfAdaptor *>(_o);
        switch (_id) {
        case 0: _t->LateEvent((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->SayBye(); break;
        case 2: _t->SayHello((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DemoIfAdaptor::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DemoIfAdaptor::LateEvent)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject DemoIfAdaptor::staticMetaObject = {
    { &QDBusAbstractAdaptor::staticMetaObject, qt_meta_stringdata_DemoIfAdaptor.data,
      qt_meta_data_DemoIfAdaptor,  qt_static_metacall, 0, 0}
};


const QMetaObject *DemoIfAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DemoIfAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DemoIfAdaptor.stringdata))
        return static_cast<void*>(const_cast< DemoIfAdaptor*>(this));
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int DemoIfAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
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
void DemoIfAdaptor::LateEvent(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
