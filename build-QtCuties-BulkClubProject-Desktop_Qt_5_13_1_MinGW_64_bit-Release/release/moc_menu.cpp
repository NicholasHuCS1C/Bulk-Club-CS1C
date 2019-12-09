/****************************************************************************
** Meta object code from reading C++ file 'menu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../QtCuties-BulkClubProject/menu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Menu_t {
    QByteArrayData data[16];
    char stringdata0[382];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Menu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Menu_t qt_meta_stringdata_Menu = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Menu"
QT_MOC_LITERAL(1, 5, 19), // "on_load_all_clicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 25), // "on_comboBoxDays_activated"
QT_MOC_LITERAL(4, 52, 4), // "arg1"
QT_MOC_LITERAL(5, 57, 27), // "on_checkBoxStandard_toggled"
QT_MOC_LITERAL(6, 85, 7), // "checked"
QT_MOC_LITERAL(7, 93, 25), // "on_standardButton_clicked"
QT_MOC_LITERAL(8, 119, 28), // "on_buttonAddCustomer_clicked"
QT_MOC_LITERAL(9, 148, 31), // "on_buttonDeleteCustomer_clicked"
QT_MOC_LITERAL(10, 180, 34), // "on_buttonDeleteCustomerNum_cl..."
QT_MOC_LITERAL(11, 215, 31), // "on_buttonClearPurchases_clicked"
QT_MOC_LITERAL(12, 247, 31), // "on_comboBoxNameSearch_activated"
QT_MOC_LITERAL(13, 279, 41), // "on_comboBoxItemSearch_current..."
QT_MOC_LITERAL(14, 321, 31), // "on_buttonCalcTotalPrice_clicked"
QT_MOC_LITERAL(15, 353, 28) // "on_buttonAddPurchase_clicked"

    },
    "Menu\0on_load_all_clicked\0\0"
    "on_comboBoxDays_activated\0arg1\0"
    "on_checkBoxStandard_toggled\0checked\0"
    "on_standardButton_clicked\0"
    "on_buttonAddCustomer_clicked\0"
    "on_buttonDeleteCustomer_clicked\0"
    "on_buttonDeleteCustomerNum_clicked\0"
    "on_buttonClearPurchases_clicked\0"
    "on_comboBoxNameSearch_activated\0"
    "on_comboBoxItemSearch_currentIndexChanged\0"
    "on_buttonCalcTotalPrice_clicked\0"
    "on_buttonAddPurchase_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Menu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    1,   75,    2, 0x08 /* Private */,
       5,    1,   78,    2, 0x08 /* Private */,
       7,    0,   81,    2, 0x08 /* Private */,
       8,    0,   82,    2, 0x08 /* Private */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    0,   84,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,
      12,    1,   86,    2, 0x08 /* Private */,
      13,    1,   89,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Menu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_load_all_clicked(); break;
        case 1: _t->on_comboBoxDays_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_checkBoxStandard_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_standardButton_clicked(); break;
        case 4: _t->on_buttonAddCustomer_clicked(); break;
        case 5: _t->on_buttonDeleteCustomer_clicked(); break;
        case 6: _t->on_buttonDeleteCustomerNum_clicked(); break;
        case 7: _t->on_buttonClearPurchases_clicked(); break;
        case 8: _t->on_comboBoxNameSearch_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_comboBoxItemSearch_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_buttonCalcTotalPrice_clicked(); break;
        case 11: _t->on_buttonAddPurchase_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Menu::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Menu.data,
    qt_meta_data_Menu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Menu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Menu.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
