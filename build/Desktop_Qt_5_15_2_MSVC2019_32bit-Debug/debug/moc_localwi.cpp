/****************************************************************************
** Meta object code from reading C++ file 'localwi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../localwi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'localwi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Localwi_t {
    QByteArrayData data[11];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Localwi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Localwi_t qt_meta_stringdata_Localwi = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Localwi"
QT_MOC_LITERAL(1, 8, 9), // "localplay"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 16), // "QList<MusicInfo>"
QT_MOC_LITERAL(4, 36, 10), // "m_playlist"
QT_MOC_LITERAL(5, 47, 9), // "MusicInfo"
QT_MOC_LITERAL(6, 57, 7), // "message"
QT_MOC_LITERAL(7, 65, 10), // "updatelist"
QT_MOC_LITERAL(8, 76, 22), // "on_content_btn_clicked"
QT_MOC_LITERAL(9, 99, 21), // "on_reload_btn_clicked"
QT_MOC_LITERAL(10, 121, 22) // "on_playall_btn_clicked"

    },
    "Localwi\0localplay\0\0QList<MusicInfo>\0"
    "m_playlist\0MusicInfo\0message\0updatelist\0"
    "on_content_btn_clicked\0on_reload_btn_clicked\0"
    "on_playall_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Localwi[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       7,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   45,    2, 0x08 /* Private */,
       9,    0,   46,    2, 0x08 /* Private */,
      10,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Localwi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Localwi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->localplay((*reinterpret_cast< const QList<MusicInfo>(*)>(_a[1])),(*reinterpret_cast< const MusicInfo(*)>(_a[2]))); break;
        case 1: _t->updatelist(); break;
        case 2: _t->on_content_btn_clicked(); break;
        case 3: _t->on_reload_btn_clicked(); break;
        case 4: _t->on_playall_btn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MusicInfo >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<MusicInfo> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Localwi::*)(const QList<MusicInfo> , const MusicInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Localwi::localplay)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Localwi::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Localwi::updatelist)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Localwi::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Localwi.data,
    qt_meta_data_Localwi,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Localwi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Localwi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Localwi.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Localwi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Localwi::localplay(const QList<MusicInfo> _t1, const MusicInfo _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Localwi::updatelist()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
