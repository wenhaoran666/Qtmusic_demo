/****************************************************************************
** Meta object code from reading C++ file 'likemusicwi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../likemusicwi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'likemusicwi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Likemusicwi_t {
    QByteArrayData data[19];
    char stringdata0[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Likemusicwi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Likemusicwi_t qt_meta_stringdata_Likemusicwi = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Likemusicwi"
QT_MOC_LITERAL(1, 12, 13), // "playRequested"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "MusicInfo"
QT_MOC_LITERAL(4, 37, 4), // "info"
QT_MOC_LITERAL(5, 42, 17), // "itemDoubleClicked"
QT_MOC_LITERAL(6, 60, 17), // "LikePlayRequested"
QT_MOC_LITERAL(7, 78, 9), // "musicInfo"
QT_MOC_LITERAL(8, 88, 16), // "QList<MusicInfo>"
QT_MOC_LITERAL(9, 105, 4), // "list"
QT_MOC_LITERAL(10, 110, 16), // "onremoveLikesong"
QT_MOC_LITERAL(11, 127, 6), // "songId"
QT_MOC_LITERAL(12, 134, 13), // "onaddLikesong"
QT_MOC_LITERAL(13, 148, 21), // "onDelegatePlayClicked"
QT_MOC_LITERAL(14, 170, 11), // "QModelIndex"
QT_MOC_LITERAL(15, 182, 5), // "index"
QT_MOC_LITERAL(16, 188, 13), // "onItemClicked"
QT_MOC_LITERAL(17, 202, 19), // "onItemDoubleClicked"
QT_MOC_LITERAL(18, 222, 25) // "onrefreshLikeListViewItem"

    },
    "Likemusicwi\0playRequested\0\0MusicInfo\0"
    "info\0itemDoubleClicked\0LikePlayRequested\0"
    "musicInfo\0QList<MusicInfo>\0list\0"
    "onremoveLikesong\0songId\0onaddLikesong\0"
    "onDelegatePlayClicked\0QModelIndex\0"
    "index\0onItemClicked\0onItemDoubleClicked\0"
    "onrefreshLikeListViewItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Likemusicwi[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,
       6,    2,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   70,    2, 0x08 /* Private */,
      12,    1,   73,    2, 0x08 /* Private */,
      13,    1,   76,    2, 0x08 /* Private */,
      16,    1,   79,    2, 0x08 /* Private */,
      17,    1,   82,    2, 0x08 /* Private */,
      18,    1,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 8,    7,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong,   11,
    QMetaType::Void, QMetaType::LongLong,   11,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::LongLong,   11,

       0        // eod
};

void Likemusicwi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Likemusicwi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playRequested((*reinterpret_cast< const MusicInfo(*)>(_a[1]))); break;
        case 1: _t->itemDoubleClicked((*reinterpret_cast< const MusicInfo(*)>(_a[1]))); break;
        case 2: _t->LikePlayRequested((*reinterpret_cast< const MusicInfo(*)>(_a[1])),(*reinterpret_cast< QList<MusicInfo>(*)>(_a[2]))); break;
        case 3: _t->onremoveLikesong((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->onaddLikesong((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->onDelegatePlayClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->onItemClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->onItemDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->onrefreshLikeListViewItem((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MusicInfo >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MusicInfo >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MusicInfo >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<MusicInfo> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Likemusicwi::*)(const MusicInfo & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Likemusicwi::playRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Likemusicwi::*)(const MusicInfo & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Likemusicwi::itemDoubleClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Likemusicwi::*)(const MusicInfo & , QList<MusicInfo> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Likemusicwi::LikePlayRequested)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Likemusicwi::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Likemusicwi.data,
    qt_meta_data_Likemusicwi,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Likemusicwi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Likemusicwi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Likemusicwi.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Likemusicwi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Likemusicwi::playRequested(const MusicInfo & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Likemusicwi::itemDoubleClicked(const MusicInfo & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Likemusicwi::LikePlayRequested(const MusicInfo & _t1, QList<MusicInfo> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
