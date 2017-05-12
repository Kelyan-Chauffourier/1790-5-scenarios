/****************************************************************************
** Meta object code from reading C++ file 'cxmlreader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SceneEditor/cxmlreader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cxmlreader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CXmlReader_t {
    QByteArrayData data[9];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CXmlReader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CXmlReader_t qt_meta_stringdata_CXmlReader = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CXmlReader"
QT_MOC_LITERAL(1, 11, 8), // "readData"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 3), // "xml"
QT_MOC_LITERAL(4, 25, 12), // "numberEvents"
QT_MOC_LITERAL(5, 38, 9), // "eventName"
QT_MOC_LITERAL(6, 48, 1), // "i"
QT_MOC_LITERAL(7, 50, 12), // "eventActions"
QT_MOC_LITERAL(8, 63, 16) // "eventDeclencheur"

    },
    "CXmlReader\0readData\0\0xml\0numberEvents\0"
    "eventName\0i\0eventActions\0eventDeclencheur"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CXmlReader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x02 /* Public */,
       4,    0,   42,    2, 0x02 /* Public */,
       5,    1,   43,    2, 0x02 /* Public */,
       7,    1,   46,    2, 0x02 /* Public */,
       8,    1,   49,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,    6,
    QMetaType::QString, QMetaType::Int,    6,
    QMetaType::QString, QMetaType::Int,    6,

       0        // eod
};

void CXmlReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CXmlReader *_t = static_cast<CXmlReader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: { int _r = _t->numberEvents();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->eventName((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->eventActions((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->eventDeclencheur((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject CXmlReader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CXmlReader.data,
      qt_meta_data_CXmlReader,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CXmlReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CXmlReader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CXmlReader.stringdata0))
        return static_cast<void*>(const_cast< CXmlReader*>(this));
    return QObject::qt_metacast(_clname);
}

int CXmlReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
