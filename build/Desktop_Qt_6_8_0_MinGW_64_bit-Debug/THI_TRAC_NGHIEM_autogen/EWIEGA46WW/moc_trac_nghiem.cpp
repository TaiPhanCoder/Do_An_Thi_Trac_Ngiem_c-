/****************************************************************************
** Meta object code from reading C++ file 'trac_nghiem.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../trac_nghiem.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trac_nghiem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSTrac_NghiemENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSTrac_NghiemENDCLASS = QtMocHelpers::stringData(
    "Trac_Nghiem",
    "on_right_arow_clicked",
    "",
    "startCountdown",
    "times",
    "updateTime",
    "on_left_arow_clicked",
    "indsach",
    "handleListWidgetClick",
    "QListWidgetItem*",
    "item",
    "initializeMangDaThi",
    "handleAnswerSelection",
    "updateRadioButtonState",
    "setupTracNghiem",
    "on_NopBai_clicked",
    "ketQuaLamBai",
    "diem"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTrac_NghiemENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       3,    1,   87,    2, 0x08,    2 /* Private */,
       5,    0,   90,    2, 0x08,    4 /* Private */,
       6,    0,   91,    2, 0x08,    5 /* Private */,
       7,    0,   92,    2, 0x08,    6 /* Private */,
       8,    1,   93,    2, 0x08,    7 /* Private */,
      11,    0,   96,    2, 0x08,    9 /* Private */,
      12,    0,   97,    2, 0x08,   10 /* Private */,
      13,    0,   98,    2, 0x08,   11 /* Private */,
      14,    0,   99,    2, 0x08,   12 /* Private */,
      15,    0,  100,    2, 0x08,   13 /* Private */,
      16,    1,  101,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,   17,

       0        // eod
};

Q_CONSTINIT const QMetaObject Trac_Nghiem::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSTrac_NghiemENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTrac_NghiemENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTrac_NghiemENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Trac_Nghiem, std::true_type>,
        // method 'on_right_arow_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startCountdown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updateTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_left_arow_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'indsach'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleListWidgetClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'initializeMangDaThi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleAnswerSelection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateRadioButtonState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setupTracNghiem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_NopBai_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ketQuaLamBai'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const float &, std::false_type>
    >,
    nullptr
} };

void Trac_Nghiem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Trac_Nghiem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_right_arow_clicked(); break;
        case 1: _t->startCountdown((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->updateTime(); break;
        case 3: _t->on_left_arow_clicked(); break;
        case 4: _t->indsach(); break;
        case 5: _t->handleListWidgetClick((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 6: _t->initializeMangDaThi(); break;
        case 7: _t->handleAnswerSelection(); break;
        case 8: _t->updateRadioButtonState(); break;
        case 9: _t->setupTracNghiem(); break;
        case 10: _t->on_NopBai_clicked(); break;
        case 11: _t->ketQuaLamBai((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *Trac_Nghiem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Trac_Nghiem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTrac_NghiemENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Trac_Nghiem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
