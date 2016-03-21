/****************************************************************************
** Meta object code from reading C++ file 'roadrace.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../road_race/roadrace.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roadrace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RoadRace_t {
    QByteArrayData data[13];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RoadRace_t, stringdata0) + ofs \
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
QT_MOC_LITERAL(10, 146, 9), // "openCheat"
QT_MOC_LITERAL(11, 156, 18), // "on_SaveBtn_clicked"
QT_MOC_LITERAL(12, 175, 18) // "on_tst2Btn_clicked"

    },
    "RoadRace\0on_btnStuff_clicked\0\0"
    "dataReceived\0serverDisconnected\0"
    "loadFile\0on_btnOpenGame_clicked\0"
    "labelClicked\0on_helpBtn_clicked\0"
    "on_cheatBtn_clicked\0openCheat\0"
    "on_SaveBtn_clicked\0on_tst2Btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoadRace[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RoadRace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RoadRace *_t = static_cast<RoadRace *>(_o);
        Q_UNUSED(_t)
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
        case 9: _t->on_SaveBtn_clicked(); break;
        case 10: _t->on_tst2Btn_clicked(); break;
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
    if (!strcmp(_clname, qt_meta_stringdata_RoadRace.stringdata0))
        return static_cast<void*>(const_cast< RoadRace*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RoadRace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
