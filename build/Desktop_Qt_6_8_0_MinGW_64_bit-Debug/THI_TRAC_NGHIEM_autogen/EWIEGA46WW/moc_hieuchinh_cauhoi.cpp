/****************************************************************************
** Meta object code from reading C++ file 'hieuchinh_cauhoi.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../hieuchinh_cauhoi.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hieuchinh_cauhoi.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASShieuchinh_CauHoiENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASShieuchinh_CauHoiENDCLASS = QtMocHelpers::stringData(
    "hieuchinh_CauHoi",
    "themDapAnVaoComboBox",
    "",
    "dsMonHoc",
    "NodeMonHoc*",
    "root",
    "setupHieuChinh",
    "getNoiDung",
    "getMonHoc",
    "getDapAn",
    "getA",
    "getB",
    "getC",
    "getD",
    "thongBaoLoi",
    "accept"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASShieuchinh_CauHoiENDCLASS[] = {

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
       6,    0,   90,    2, 0x08,    4 /* Private */,
       7,    0,   91,    2, 0x08,    5 /* Private */,
       8,    0,   92,    2, 0x08,    6 /* Private */,
       9,    0,   93,    2, 0x08,    7 /* Private */,
      10,    0,   94,    2, 0x08,    8 /* Private */,
      11,    0,   95,    2, 0x08,    9 /* Private */,
      12,    0,   96,    2, 0x08,   10 /* Private */,
      13,    0,   97,    2, 0x08,   11 /* Private */,
      14,    0,   98,    2, 0x08,   12 /* Private */,
      15,    0,   99,    2, 0x08,   13 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Bool,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject hieuchinh_CauHoi::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASShieuchinh_CauHoiENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASShieuchinh_CauHoiENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASShieuchinh_CauHoiENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<hieuchinh_CauHoi, std::true_type>,
        // method 'themDapAnVaoComboBox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dsMonHoc'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<NodeMonHoc *, std::false_type>,
        // method 'setupHieuChinh'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getNoiDung'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getMonHoc'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getDapAn'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getA'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getB'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getC'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getD'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'thongBaoLoi'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'accept'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void hieuchinh_CauHoi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<hieuchinh_CauHoi *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->themDapAnVaoComboBox(); break;
        case 1: _t->dsMonHoc((*reinterpret_cast< std::add_pointer_t<NodeMonHoc*>>(_a[1]))); break;
        case 2: _t->setupHieuChinh(); break;
        case 3: { QString _r = _t->getNoiDung();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->getMonHoc();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getDapAn();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->getA();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->getB();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->getC();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->getD();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->thongBaoLoi();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->accept(); break;
        default: ;
        }
    }
}

const QMetaObject *hieuchinh_CauHoi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hieuchinh_CauHoi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASShieuchinh_CauHoiENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int hieuchinh_CauHoi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
