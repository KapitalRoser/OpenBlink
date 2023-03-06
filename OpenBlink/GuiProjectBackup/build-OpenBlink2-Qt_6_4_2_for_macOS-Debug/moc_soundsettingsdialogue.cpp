/****************************************************************************
** Meta object code from reading C++ file 'soundsettingsdialogue.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../OpenBlink2/soundsettingsdialogue.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'soundsettingsdialogue.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_soundSettingsDialogue_t {
    uint offsetsAndSizes[18];
    char stringdata0[22];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[21];
    char stringdata5[18];
    char stringdata6[13];
    char stringdata7[19];
    char stringdata8[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_soundSettingsDialogue_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_soundSettingsDialogue_t qt_meta_stringdata_soundSettingsDialogue = {
    {
        QT_MOC_LITERAL(0, 21),  // "soundSettingsDialogue"
        QT_MOC_LITERAL(22, 14),  // "slide_Released"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 11),  // "slide_Moved"
        QT_MOC_LITERAL(50, 20),  // "box_Editing_Finished"
        QT_MOC_LITERAL(71, 17),  // "box_value_changed"
        QT_MOC_LITERAL(89, 12),  // "mute_clicked"
        QT_MOC_LITERAL(102, 18),  // "fileChange_clicked"
        QT_MOC_LITERAL(121, 15)   // "buttonBox_reset"
    },
    "soundSettingsDialogue",
    "slide_Released",
    "",
    "slide_Moved",
    "box_Editing_Finished",
    "box_value_changed",
    "mute_clicked",
    "fileChange_clicked",
    "buttonBox_reset"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_soundSettingsDialogue[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject soundSettingsDialogue::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_soundSettingsDialogue.offsetsAndSizes,
    qt_meta_data_soundSettingsDialogue,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_soundSettingsDialogue_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<soundSettingsDialogue, std::true_type>,
        // method 'slide_Released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slide_Moved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'box_Editing_Finished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'box_value_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mute_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fileChange_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buttonBox_reset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void soundSettingsDialogue::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<soundSettingsDialogue *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slide_Released(); break;
        case 1: _t->slide_Moved(); break;
        case 2: _t->box_Editing_Finished(); break;
        case 3: _t->box_value_changed(); break;
        case 4: _t->mute_clicked(); break;
        case 5: _t->fileChange_clicked(); break;
        case 6: _t->buttonBox_reset(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *soundSettingsDialogue::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *soundSettingsDialogue::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_soundSettingsDialogue.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int soundSettingsDialogue::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
