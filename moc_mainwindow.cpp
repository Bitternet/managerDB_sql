/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[426];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_poisk_button_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 41), // "on_vibor_table_comBox_current..."
QT_MOC_LITERAL(4, 78, 4), // "arg1"
QT_MOC_LITERAL(5, 83, 24), // "on_connectButton_clicked"
QT_MOC_LITERAL(6, 108, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 130, 10), // "log_search"
QT_MOC_LITERAL(8, 141, 23), // "on_poisk_Button_clicked"
QT_MOC_LITERAL(9, 165, 23), // "on_updateButton_clicked"
QT_MOC_LITERAL(10, 189, 23), // "on_otchetButton_clicked"
QT_MOC_LITERAL(11, 213, 24), // "on_time_checkBox_clicked"
QT_MOC_LITERAL(12, 238, 27), // "on_element_checkBox_clicked"
QT_MOC_LITERAL(13, 266, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(14, 286, 21), // "on_checkBox_2_clicked"
QT_MOC_LITERAL(15, 308, 11), // "changeCombo"
QT_MOC_LITERAL(16, 320, 29), // "on_znachenie_checkBox_clicked"
QT_MOC_LITERAL(17, 350, 25), // "on_error_checkBox_clicked"
QT_MOC_LITERAL(18, 376, 19), // "on_pB_meteo_clicked"
QT_MOC_LITERAL(19, 396, 29) // "on_otchetButton_meteo_clicked"

    },
    "MainWindow\0on_poisk_button_clicked\0\0"
    "on_vibor_table_comBox_currentIndexChanged\0"
    "arg1\0on_connectButton_clicked\0"
    "on_pushButton_clicked\0log_search\0"
    "on_poisk_Button_clicked\0on_updateButton_clicked\0"
    "on_otchetButton_clicked\0"
    "on_time_checkBox_clicked\0"
    "on_element_checkBox_clicked\0"
    "on_checkBox_clicked\0on_checkBox_2_clicked\0"
    "changeCombo\0on_znachenie_checkBox_clicked\0"
    "on_error_checkBox_clicked\0on_pB_meteo_clicked\0"
    "on_otchetButton_meteo_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    1,  100,    2, 0x08 /* Private */,
       5,    0,  103,    2, 0x08 /* Private */,
       6,    0,  104,    2, 0x08 /* Private */,
       7,    0,  105,    2, 0x08 /* Private */,
       8,    0,  106,    2, 0x08 /* Private */,
       9,    0,  107,    2, 0x08 /* Private */,
      10,    0,  108,    2, 0x08 /* Private */,
      11,    0,  109,    2, 0x08 /* Private */,
      12,    0,  110,    2, 0x08 /* Private */,
      13,    0,  111,    2, 0x08 /* Private */,
      14,    0,  112,    2, 0x08 /* Private */,
      15,    0,  113,    2, 0x08 /* Private */,
      16,    0,  114,    2, 0x08 /* Private */,
      17,    0,  115,    2, 0x08 /* Private */,
      18,    0,  116,    2, 0x08 /* Private */,
      19,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_poisk_button_clicked(); break;
        case 1: _t->on_vibor_table_comBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_connectButton_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->log_search(); break;
        case 5: _t->on_poisk_Button_clicked(); break;
        case 6: _t->on_updateButton_clicked(); break;
        case 7: _t->on_otchetButton_clicked(); break;
        case 8: _t->on_time_checkBox_clicked(); break;
        case 9: _t->on_element_checkBox_clicked(); break;
        case 10: _t->on_checkBox_clicked(); break;
        case 11: _t->on_checkBox_2_clicked(); break;
        case 12: _t->changeCombo(); break;
        case 13: _t->on_znachenie_checkBox_clicked(); break;
        case 14: _t->on_error_checkBox_clicked(); break;
        case 15: _t->on_pB_meteo_clicked(); break;
        case 16: _t->on_otchetButton_meteo_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
struct qt_meta_stringdata_mDelegate_t {
    QByteArrayData data[1];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mDelegate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mDelegate_t qt_meta_stringdata_mDelegate = {
    {
QT_MOC_LITERAL(0, 0, 9) // "mDelegate"

    },
    "mDelegate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mDelegate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void mDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject mDelegate::staticMetaObject = {
    { &QStyledItemDelegate::staticMetaObject, qt_meta_stringdata_mDelegate.data,
      qt_meta_data_mDelegate,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *mDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mDelegate.stringdata0))
        return static_cast<void*>(this);
    return QStyledItemDelegate::qt_metacast(_clname);
}

int mDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
