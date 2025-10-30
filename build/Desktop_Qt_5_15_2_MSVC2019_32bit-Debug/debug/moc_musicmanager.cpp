/****************************************************************************
** Meta object code from reading C++ file 'musicmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../musicmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MusicManager_t {
    QByteArrayData data[13];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MusicManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MusicManager_t qt_meta_stringdata_MusicManager = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MusicManager"
QT_MOC_LITERAL(1, 13, 19), // "refreshListViewItem"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 6), // "songId"
QT_MOC_LITERAL(4, 41, 23), // "refreshLikeListViewItem"
QT_MOC_LITERAL(5, 65, 11), // "addLikesong"
QT_MOC_LITERAL(6, 77, 14), // "removeLikesong"
QT_MOC_LITERAL(7, 92, 14), // "refreshbanenrs"
QT_MOC_LITERAL(8, 107, 17), // "onImageDownloaded"
QT_MOC_LITERAL(9, 125, 17), // "ImageDownloadInfo"
QT_MOC_LITERAL(10, 143, 4), // "info"
QT_MOC_LITERAL(11, 148, 5), // "image"
QT_MOC_LITERAL(12, 154, 7) // "success"

    },
    "MusicManager\0refreshListViewItem\0\0"
    "songId\0refreshLikeListViewItem\0"
    "addLikesong\0removeLikesong\0refreshbanenrs\0"
    "onImageDownloaded\0ImageDownloadInfo\0"
    "info\0image\0success"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusicManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       5,    1,   50,    2, 0x06 /* Public */,
       6,    1,   53,    2, 0x06 /* Public */,
       7,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    3,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9, QMetaType::QPixmap, QMetaType::Bool,   10,   11,   12,

       0        // eod
};

void MusicManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MusicManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refreshListViewItem((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 1: _t->refreshLikeListViewItem((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->addLikesong((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->removeLikesong((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->refreshbanenrs(); break;
        case 5: _t->onImageDownloaded((*reinterpret_cast< ImageDownloadInfo(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MusicManager::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicManager::refreshListViewItem)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MusicManager::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicManager::refreshLikeListViewItem)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MusicManager::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicManager::addLikesong)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MusicManager::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicManager::removeLikesong)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MusicManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicManager::refreshbanenrs)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MusicManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MusicManager.data,
    qt_meta_data_MusicManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MusicManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MusicManager.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Singleton<MusicManager>"))
        return static_cast< Singleton<MusicManager>*>(this);
    if (!strcmp(_clname, "std::enable_shared_from_this<MusicManager>"))
        return static_cast< std::enable_shared_from_this<MusicManager>*>(this);
    return QObject::qt_metacast(_clname);
}

int MusicManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MusicManager::refreshListViewItem(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MusicManager::refreshLikeListViewItem(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MusicManager::addLikesong(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MusicManager::removeLikesong(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MusicManager::refreshbanenrs()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
