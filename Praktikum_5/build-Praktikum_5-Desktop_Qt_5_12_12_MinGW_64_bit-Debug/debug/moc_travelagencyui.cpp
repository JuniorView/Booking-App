/****************************************************************************
** Meta object code from reading C++ file 'travelagencyui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Praktikum_5/travelagencyui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'travelagencyui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Travelagencyui_t {
    QByteArrayData data[18];
    char stringdata0[389];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Travelagencyui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Travelagencyui_t qt_meta_stringdata_Travelagencyui = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Travelagencyui"
QT_MOC_LITERAL(1, 15, 11), // "checkSignal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 27), // "on_actionEinlesen_triggered"
QT_MOC_LITERAL(4, 56, 25), // "on_actionsuchen_triggered"
QT_MOC_LITERAL(5, 82, 32), // "on_travelTable_itemDoubleClicked"
QT_MOC_LITERAL(6, 115, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(7, 133, 4), // "item"
QT_MOC_LITERAL(8, 138, 40), // "on_customerTravelTable_itemDo..."
QT_MOC_LITERAL(9, 179, 25), // "on_savePushButton_clicked"
QT_MOC_LITERAL(10, 205, 27), // "on_cancelPushButton_clicked"
QT_MOC_LITERAL(11, 233, 28), // "on_actionSpeichern_triggered"
QT_MOC_LITERAL(12, 262, 9), // "slotCheck"
QT_MOC_LITERAL(13, 272, 27), // "on_fromDateFlug_textChanged"
QT_MOC_LITERAL(14, 300, 4), // "arg1"
QT_MOC_LITERAL(15, 305, 25), // "on_toDateflug_textChanged"
QT_MOC_LITERAL(16, 331, 27), // "on_actionAnzeigen_triggered"
QT_MOC_LITERAL(17, 359, 29) // "on_actionset_config_triggered"

    },
    "Travelagencyui\0checkSignal\0\0"
    "on_actionEinlesen_triggered\0"
    "on_actionsuchen_triggered\0"
    "on_travelTable_itemDoubleClicked\0"
    "QTableWidgetItem*\0item\0"
    "on_customerTravelTable_itemDoubleClicked\0"
    "on_savePushButton_clicked\0"
    "on_cancelPushButton_clicked\0"
    "on_actionSpeichern_triggered\0slotCheck\0"
    "on_fromDateFlug_textChanged\0arg1\0"
    "on_toDateflug_textChanged\0"
    "on_actionAnzeigen_triggered\0"
    "on_actionset_config_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Travelagencyui[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    1,   82,    2, 0x08 /* Private */,
       8,    1,   85,    2, 0x08 /* Private */,
       9,    0,   88,    2, 0x08 /* Private */,
      10,    0,   89,    2, 0x08 /* Private */,
      11,    0,   90,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    1,   92,    2, 0x08 /* Private */,
      15,    1,   95,    2, 0x08 /* Private */,
      16,    0,   98,    2, 0x08 /* Private */,
      17,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Travelagencyui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Travelagencyui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkSignal(); break;
        case 1: _t->on_actionEinlesen_triggered(); break;
        case 2: _t->on_actionsuchen_triggered(); break;
        case 3: _t->on_travelTable_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->on_customerTravelTable_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->on_savePushButton_clicked(); break;
        case 6: _t->on_cancelPushButton_clicked(); break;
        case 7: _t->on_actionSpeichern_triggered(); break;
        case 8: _t->slotCheck(); break;
        case 9: _t->on_fromDateFlug_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_toDateflug_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_actionAnzeigen_triggered(); break;
        case 12: _t->on_actionset_config_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Travelagencyui::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Travelagencyui::checkSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Travelagencyui::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Travelagencyui.data,
    qt_meta_data_Travelagencyui,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Travelagencyui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Travelagencyui::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Travelagencyui.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Travelagencyui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Travelagencyui::checkSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
