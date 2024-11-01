/****************************************************************************
** Meta object code from reading C++ file 'QtWidgetsApplication1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../QtWidgetsApplication1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtWidgetsApplication1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtWidgetsApplication1_t {
    QByteArrayData data[17];
    char stringdata0[293];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtWidgetsApplication1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtWidgetsApplication1_t qt_meta_stringdata_QtWidgetsApplication1 = {
    {
QT_MOC_LITERAL(0, 0, 21), // "QtWidgetsApplication1"
QT_MOC_LITERAL(1, 22, 8), // "operate1"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 8), // "operate2"
QT_MOC_LITERAL(4, 41, 8), // "operate3"
QT_MOC_LITERAL(5, 50, 8), // "operate4"
QT_MOC_LITERAL(6, 59, 8), // "operate5"
QT_MOC_LITERAL(7, 68, 32), // "on_action_Button_ReadImg_clicked"
QT_MOC_LITERAL(8, 101, 32), // "on_action_Button_HistAna_clicked"
QT_MOC_LITERAL(9, 134, 34), // "on_action_Button_Threshold_cl..."
QT_MOC_LITERAL(10, 169, 38), // "on_action_Slider_ThresholdVal..."
QT_MOC_LITERAL(11, 208, 5), // "value"
QT_MOC_LITERAL(12, 214, 34), // "on_action_Button_Multiline_cl..."
QT_MOC_LITERAL(13, 249, 8), // "Finished"
QT_MOC_LITERAL(14, 258, 17), // "updateProgressbar"
QT_MOC_LITERAL(15, 276, 7), // "percent"
QT_MOC_LITERAL(16, 284, 8) // "showTime"

    },
    "QtWidgetsApplication1\0operate1\0\0"
    "operate2\0operate3\0operate4\0operate5\0"
    "on_action_Button_ReadImg_clicked\0"
    "on_action_Button_HistAna_clicked\0"
    "on_action_Button_Threshold_clicked\0"
    "on_action_Slider_ThresholdValue_edited\0"
    "value\0on_action_Button_Multiline_clicked\0"
    "Finished\0updateProgressbar\0percent\0"
    "showTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtWidgetsApplication1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    1,   82,    2, 0x06 /* Public */,
       4,    1,   85,    2, 0x06 /* Public */,
       5,    1,   88,    2, 0x06 /* Public */,
       6,    1,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    1,   97,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    0,  101,    2, 0x08 /* Private */,
      14,    1,  102,    2, 0x08 /* Private */,
      16,    0,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   15,
    QMetaType::Void,

       0        // eod
};

void QtWidgetsApplication1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtWidgetsApplication1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->operate1((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->operate2((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->operate3((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->operate4((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->operate5((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 5: _t->on_action_Button_ReadImg_clicked(); break;
        case 6: _t->on_action_Button_HistAna_clicked(); break;
        case 7: _t->on_action_Button_Threshold_clicked(); break;
        case 8: _t->on_action_Slider_ThresholdValue_edited((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_action_Button_Multiline_clicked(); break;
        case 10: _t->Finished(); break;
        case 11: _t->updateProgressbar((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->showTime(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtWidgetsApplication1::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtWidgetsApplication1::operate1)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtWidgetsApplication1::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtWidgetsApplication1::operate2)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QtWidgetsApplication1::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtWidgetsApplication1::operate3)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QtWidgetsApplication1::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtWidgetsApplication1::operate4)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QtWidgetsApplication1::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtWidgetsApplication1::operate5)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QtWidgetsApplication1::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_QtWidgetsApplication1.data,
    qt_meta_data_QtWidgetsApplication1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtWidgetsApplication1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtWidgetsApplication1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtWidgetsApplication1.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QtWidgetsApplication1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QtWidgetsApplication1::operate1(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtWidgetsApplication1::operate2(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtWidgetsApplication1::operate3(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QtWidgetsApplication1::operate4(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QtWidgetsApplication1::operate5(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
