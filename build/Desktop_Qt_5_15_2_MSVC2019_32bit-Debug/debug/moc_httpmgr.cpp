/****************************************************************************
** Meta object code from reading C++ file 'httpmgr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../httpmgr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpmgr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HttpMgr_t {
    QByteArrayData data[22];
    char stringdata0[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpMgr_t qt_meta_stringdata_HttpMgr = {
    {
QT_MOC_LITERAL(0, 0, 7), // "HttpMgr"
QT_MOC_LITERAL(1, 8, 15), // "sig_http_finish"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "ReqId"
QT_MOC_LITERAL(4, 31, 2), // "id"
QT_MOC_LITERAL(5, 34, 3), // "res"
QT_MOC_LITERAL(6, 38, 10), // "ErrorCodes"
QT_MOC_LITERAL(7, 49, 3), // "err"
QT_MOC_LITERAL(8, 53, 7), // "Modules"
QT_MOC_LITERAL(9, 61, 3), // "mod"
QT_MOC_LITERAL(10, 65, 23), // "sig_music_search_finish"
QT_MOC_LITERAL(11, 89, 21), // "sig_music_like_finish"
QT_MOC_LITERAL(12, 111, 26), // "sig_music_recommend_finish"
QT_MOC_LITERAL(13, 138, 25), // "sig_image_download_finish"
QT_MOC_LITERAL(14, 164, 17), // "ImageDownloadInfo"
QT_MOC_LITERAL(15, 182, 4), // "info"
QT_MOC_LITERAL(16, 187, 5), // "image"
QT_MOC_LITERAL(17, 193, 7), // "success"
QT_MOC_LITERAL(18, 201, 16), // "slot_http_finish"
QT_MOC_LITERAL(19, 218, 23), // "onImageDownloadFinished"
QT_MOC_LITERAL(20, 242, 14), // "QNetworkReply*"
QT_MOC_LITERAL(21, 257, 5) // "reply"

    },
    "HttpMgr\0sig_http_finish\0\0ReqId\0id\0res\0"
    "ErrorCodes\0err\0Modules\0mod\0"
    "sig_music_search_finish\0sig_music_like_finish\0"
    "sig_music_recommend_finish\0"
    "sig_image_download_finish\0ImageDownloadInfo\0"
    "info\0image\0success\0slot_http_finish\0"
    "onImageDownloadFinished\0QNetworkReply*\0"
    "reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpMgr[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   49,    2, 0x06 /* Public */,
      10,    3,   58,    2, 0x06 /* Public */,
      11,    3,   65,    2, 0x06 /* Public */,
      12,    3,   72,    2, 0x06 /* Public */,
      13,    3,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    4,   86,    2, 0x08 /* Private */,
      19,    1,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, 0x80000000 | 6, 0x80000000 | 8,    4,    5,    7,    9,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, 0x80000000 | 6,    4,    5,    7,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, 0x80000000 | 6,    4,    5,    7,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, 0x80000000 | 6,    4,    5,    7,
    QMetaType::Void, 0x80000000 | 14, QMetaType::QPixmap, QMetaType::Bool,   15,   16,   17,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, 0x80000000 | 6, 0x80000000 | 8,    4,    5,    7,    9,
    QMetaType::Void, 0x80000000 | 20,   21,

       0        // eod
};

void HttpMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HttpMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_http_finish((*reinterpret_cast< ReqId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< ErrorCodes(*)>(_a[3])),(*reinterpret_cast< Modules(*)>(_a[4]))); break;
        case 1: _t->sig_music_search_finish((*reinterpret_cast< ReqId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< ErrorCodes(*)>(_a[3]))); break;
        case 2: _t->sig_music_like_finish((*reinterpret_cast< ReqId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< ErrorCodes(*)>(_a[3]))); break;
        case 3: _t->sig_music_recommend_finish((*reinterpret_cast< ReqId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< ErrorCodes(*)>(_a[3]))); break;
        case 4: _t->sig_image_download_finish((*reinterpret_cast< ImageDownloadInfo(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 5: _t->slot_http_finish((*reinterpret_cast< ReqId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< ErrorCodes(*)>(_a[3])),(*reinterpret_cast< Modules(*)>(_a[4]))); break;
        case 6: _t->onImageDownloadFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HttpMgr::*)(ReqId , QString , ErrorCodes , Modules );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpMgr::sig_http_finish)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HttpMgr::*)(ReqId , QString , ErrorCodes );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpMgr::sig_music_search_finish)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HttpMgr::*)(ReqId , QString , ErrorCodes );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpMgr::sig_music_like_finish)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (HttpMgr::*)(ReqId , QString , ErrorCodes );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpMgr::sig_music_recommend_finish)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (HttpMgr::*)(ImageDownloadInfo , const QPixmap & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpMgr::sig_image_download_finish)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HttpMgr::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_HttpMgr.data,
    qt_meta_data_HttpMgr,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HttpMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HttpMgr.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Singleton<HttpMgr>"))
        return static_cast< Singleton<HttpMgr>*>(this);
    if (!strcmp(_clname, "std::enable_shared_from_this<HttpMgr>"))
        return static_cast< std::enable_shared_from_this<HttpMgr>*>(this);
    return QObject::qt_metacast(_clname);
}

int HttpMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void HttpMgr::sig_http_finish(ReqId _t1, QString _t2, ErrorCodes _t3, Modules _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HttpMgr::sig_music_search_finish(ReqId _t1, QString _t2, ErrorCodes _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HttpMgr::sig_music_like_finish(ReqId _t1, QString _t2, ErrorCodes _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void HttpMgr::sig_music_recommend_finish(ReqId _t1, QString _t2, ErrorCodes _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void HttpMgr::sig_image_download_finish(ImageDownloadInfo _t1, const QPixmap & _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
