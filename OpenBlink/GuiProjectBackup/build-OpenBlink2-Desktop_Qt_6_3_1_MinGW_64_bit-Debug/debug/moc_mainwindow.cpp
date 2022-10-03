/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../OpenBlink2/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[40];
    char stringdata0[421];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 25), // "on_seeInputButton_clicked"
QT_MOC_LITERAL(61, 16), // "totalTimerUpdate"
QT_MOC_LITERAL(78, 14), // "timerGUIUpdate"
QT_MOC_LITERAL(93, 11), // "blinkOccurs"
QT_MOC_LITERAL(105, 28), // "on_arbTargetBox_valueChanged"
QT_MOC_LITERAL(134, 4), // "arg1"
QT_MOC_LITERAL(139, 31), // "on_increaseBlinksButton_clicked"
QT_MOC_LITERAL(171, 23), // "on_slowerButton_clicked"
QT_MOC_LITERAL(195, 23), // "on_fasterButton_clicked"
QT_MOC_LITERAL(219, 28), // "on_flexValueBox_valueChanged"
QT_MOC_LITERAL(248, 26), // "on_actionHotkeys_triggered"
QT_MOC_LITERAL(275, 24), // "on_actionTimer_triggered"
QT_MOC_LITERAL(300, 25), // "on_actionSounds_triggered"
QT_MOC_LITERAL(326, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(350, 25), // "on_actionGithub_triggered"
QT_MOC_LITERAL(376, 21), // "on_copyButton_clicked"
QT_MOC_LITERAL(398, 22) // "on_pasteButton_clicked"

    },
    "MainWindow\0on_startButton_clicked\0\0"
    "on_seeInputButton_clicked\0totalTimerUpdate\0"
    "timerGUIUpdate\0blinkOccurs\0"
    "on_arbTargetBox_valueChanged\0arg1\0"
    "on_increaseBlinksButton_clicked\0"
    "on_slowerButton_clicked\0on_fasterButton_clicked\0"
    "on_flexValueBox_valueChanged\0"
    "on_actionHotkeys_triggered\0"
    "on_actionTimer_triggered\0"
    "on_actionSounds_triggered\0"
    "on_actionExit_triggered\0"
    "on_actionGithub_triggered\0"
    "on_copyButton_clicked\0on_pasteButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x08,    1 /* Private */,
       3,    0,  117,    2, 0x08,    2 /* Private */,
       4,    0,  118,    2, 0x08,    3 /* Private */,
       5,    0,  119,    2, 0x08,    4 /* Private */,
       6,    0,  120,    2, 0x08,    5 /* Private */,
       7,    1,  121,    2, 0x08,    6 /* Private */,
       9,    0,  124,    2, 0x08,    8 /* Private */,
      10,    0,  125,    2, 0x08,    9 /* Private */,
      11,    0,  126,    2, 0x08,   10 /* Private */,
      12,    1,  127,    2, 0x08,   11 /* Private */,
      13,    0,  130,    2, 0x08,   13 /* Private */,
      14,    0,  131,    2, 0x08,   14 /* Private */,
      15,    0,  132,    2, 0x08,   15 /* Private */,
      16,    0,  133,    2, 0x08,   16 /* Private */,
      17,    0,  134,    2, 0x08,   17 /* Private */,
      18,    0,  135,    2, 0x08,   18 /* Private */,
      19,    0,  136,    2, 0x08,   19 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_startButton_clicked(); break;
        case 1: _t->on_seeInputButton_clicked(); break;
        case 2: _t->totalTimerUpdate(); break;
        case 3: _t->timerGUIUpdate(); break;
        case 4: _t->blinkOccurs(); break;
        case 5: _t->on_arbTargetBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_increaseBlinksButton_clicked(); break;
        case 7: _t->on_slowerButton_clicked(); break;
        case 8: _t->on_fasterButton_clicked(); break;
        case 9: _t->on_flexValueBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->on_actionHotkeys_triggered(); break;
        case 11: _t->on_actionTimer_triggered(); break;
        case 12: _t->on_actionSounds_triggered(); break;
        case 13: _t->on_actionExit_triggered(); break;
        case 14: _t->on_actionGithub_triggered(); break;
        case 15: _t->on_copyButton_clicked(); break;
        case 16: _t->on_pasteButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
