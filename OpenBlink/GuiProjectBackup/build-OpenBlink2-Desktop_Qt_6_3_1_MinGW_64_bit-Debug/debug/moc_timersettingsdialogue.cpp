/****************************************************************************
** Meta object code from reading C++ file 'timersettingsdialogue.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../OpenBlink2/timersettingsdialogue.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timersettingsdialogue.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_timerSettingsDialogue_t {
    const uint offsetsAndSize[14];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_timerSettingsDialogue_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_timerSettingsDialogue_t qt_meta_stringdata_timerSettingsDialogue = {
    {
QT_MOC_LITERAL(0, 21), // "timerSettingsDialogue"
QT_MOC_LITERAL(22, 18), // "on_buttonBox_reset"
QT_MOC_LITERAL(41, 0), // ""
QT_MOC_LITERAL(42, 29), // "on_exitOffsetBox_valueChanged"
QT_MOC_LITERAL(72, 4), // "arg1"
QT_MOC_LITERAL(77, 31), // "on_exitIntervalBox_valueChanged"
QT_MOC_LITERAL(109, 28) // "on_exitBeepsBox_valueChanged"

    },
    "timerSettingsDialogue\0on_buttonBox_reset\0"
    "\0on_exitOffsetBox_valueChanged\0arg1\0"
    "on_exitIntervalBox_valueChanged\0"
    "on_exitBeepsBox_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_timerSettingsDialogue[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x08,    1 /* Private */,
       3,    1,   39,    2, 0x08,    2 /* Private */,
       5,    1,   42,    2, 0x08,    4 /* Private */,
       6,    1,   45,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void timerSettingsDialogue::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<timerSettingsDialogue *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_buttonBox_reset(); break;
        case 1: _t->on_exitOffsetBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_exitIntervalBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->on_exitBeepsBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject timerSettingsDialogue::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_timerSettingsDialogue.offsetsAndSize,
    qt_meta_data_timerSettingsDialogue,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_timerSettingsDialogue_t
, QtPrivate::TypeAndForceComplete<timerSettingsDialogue, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *timerSettingsDialogue::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *timerSettingsDialogue::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_timerSettingsDialogue.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int timerSettingsDialogue::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
