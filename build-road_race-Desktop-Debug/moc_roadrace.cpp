/****************************************************************************
** Meta object code from reading C++ file 'roadrace.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../road_race/roadrace.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roadrace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RoadRace_t {
    QByteArrayData data[11];
    char stringdata[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RoadRace_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RoadRace_t qt_meta_stringdata_RoadRace = {
    {
QT_MOC_LITERAL(0, 0, 8), // "RoadRace"
QT_MOC_LITERAL(1, 9, 19), // "on_btnStuff_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "dataReceived"
QT_MOC_LITERAL(4, 43, 18), // "serverDisconnected"
QT_MOC_LITERAL(5, 62, 8), // "loadFile"
QT_MOC_LITERAL(6, 71, 22), // "on_btnOpenGame_clicked"
QT_MOC_LITERAL(7, 94, 12), // "labelClicked"
QT_MOC_LITERAL(8, 107, 18), // "on_helpBtn_clicked"
QT_MOC_LITERAL(9, 126, 19), // "on_cheatBtn_clicked"
QT_MOC_LITERAL(10, 146, 9) // "openCheat"

    },
    "RoadRace\0on_btnStuff_clicked\0\0"
    "dataReceived\0serverDisconnected\0"
    "loadFile\0on_btnOpenGame_clicked\0"
    "labelClicked\0on_helpBtn_clicked\0"
    "on_cheatBtn_clicked\0openCheat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoadRace[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RoadRace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RoadRace *_t = static_cast<RoadRace *>(_o);
        switch (_id) {
        case 0: _t->on_btnStuff_clicked(); break;
        case 1: _t->dataReceived(); break;
        case 2: _t->serverDisconnected(); break;
        case 3: _t->loadFile(); break;
        case 4: _t->on_btnOpenGame_clicked(); break;
        case 5: _t->labelClicked(); break;
        case 6: _t->on_helpBtn_clicked(); break;
        case 7: _t->on_cheatBtn_clicked(); break;
        case 8: _t->openCheat(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject RoadRace::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RoadRace.data,
      qt_meta_data_RoadRace,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RoadRace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoadRace::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RoadRace.stringdata))
        return static_cast<void*>(const_cast< RoadRace*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RoadRace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
