/****************************************************************************
** Meta object code from reading C++ file 'themcauhoi.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../themcauhoi.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'themcauhoi.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSthemcauhoiENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSthemcauhoiENDCLASS = QtMocHelpers::stringData(
    "themcauhoi",
    "dsMonHoc",
    "",
    "NodeMonHoc*",
    "root",
    "randomID",
    "index",
    "themDapAnVaoComboBox",
    "thongBaoLoi",
    "getNoiDung",
    "getMonHoc",
    "getDapAn",
    "getA",
    "getB",
    "getC",
    "getD",
    "accept",
    "luuCauHoi"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSthemcauhoiENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    2, 0x08,    1 /* Private */,
       5,    1,   95,    2, 0x08,    3 /* Private */,
       7,    0,   98,    2, 0x08,    5 /* Private */,
       8,    0,   99,    2, 0x08,    6 /* Private */,
       9,    0,  100,    2, 0x08,    7 /* Private */,
      10,    0,  101,    2, 0x08,    8 /* Private */,
      11,    0,  102,    2, 0x08,    9 /* Private */,
      12,    0,  103,    2, 0x08,   10 /* Private */,
      13,    0,  104,    2, 0x08,   11 /* Private */,
      14,    0,  105,    2, 0x08,   12 /* Private */,
      15,    0,  106,    2, 0x08,   13 /* Private */,
      16,    0,  107,    2, 0x08,   14 /* Private */,
      17,    0,  108,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject themcauhoi::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSthemcauhoiENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSthemcauhoiENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSthemcauhoiENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<themcauhoi, std::true_type>,
        // method 'dsMonHoc'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<NodeMonHoc *, std::false_type>,
        // method 'randomID'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'themDapAnVaoComboBox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'thongBaoLoi'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
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
        // method 'accept'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'luuCauHoi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void themcauhoi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<themcauhoi *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dsMonHoc((*reinterpret_cast< std::add_pointer_t<NodeMonHoc*>>(_a[1]))); break;
        case 1: _t->randomID((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->themDapAnVaoComboBox(); break;
        case 3: { bool _r = _t->thongBaoLoi();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->getNoiDung();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getMonHoc();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->getDapAn();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->getA();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->getB();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->getC();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->getD();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->accept(); break;
        case 12: _t->luuCauHoi(); break;
        default: ;
        }
    }
}

const QMetaObject *themcauhoi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *themcauhoi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSthemcauhoiENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int themcauhoi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
