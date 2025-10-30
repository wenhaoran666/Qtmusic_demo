/****************************************************************************
** Meta object code from reading C++ file 'playerworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../playerworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playerworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayerWorker_t {
    QByteArrayData data[32];
    char stringdata0[357];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayerWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayerWorker_t qt_meta_stringdata_PlayerWorker = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PlayerWorker"
QT_MOC_LITERAL(1, 13, 17), // "playNextRequested"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 13), // "metadataReady"
QT_MOC_LITERAL(4, 46, 9), // "MusicInfo"
QT_MOC_LITERAL(5, 56, 4), // "info"
QT_MOC_LITERAL(6, 61, 12), // "stateChanged"
QT_MOC_LITERAL(7, 74, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(8, 94, 5), // "state"
QT_MOC_LITERAL(9, 100, 15), // "positionChanged"
QT_MOC_LITERAL(10, 116, 3), // "pos"
QT_MOC_LITERAL(11, 120, 15), // "durationChanged"
QT_MOC_LITERAL(12, 136, 8), // "duration"
QT_MOC_LITERAL(13, 145, 13), // "errorOccurred"
QT_MOC_LITERAL(14, 159, 19), // "QMediaPlayer::Error"
QT_MOC_LITERAL(15, 179, 5), // "error"
QT_MOC_LITERAL(16, 185, 3), // "msg"
QT_MOC_LITERAL(17, 189, 18), // "mediaStatusChanged"
QT_MOC_LITERAL(18, 208, 25), // "QMediaPlayer::MediaStatus"
QT_MOC_LITERAL(19, 234, 6), // "status"
QT_MOC_LITERAL(20, 241, 4), // "play"
QT_MOC_LITERAL(21, 246, 3), // "url"
QT_MOC_LITERAL(22, 250, 5), // "pause"
QT_MOC_LITERAL(23, 256, 1), // "a"
QT_MOC_LITERAL(24, 258, 6), // "resume"
QT_MOC_LITERAL(25, 265, 4), // "stop"
QT_MOC_LITERAL(26, 270, 11), // "setPosition"
QT_MOC_LITERAL(27, 282, 9), // "setVolume"
QT_MOC_LITERAL(28, 292, 6), // "volume"
QT_MOC_LITERAL(29, 299, 20), // "onPlayerStateChanged"
QT_MOC_LITERAL(30, 320, 20), // "onMediaStatusChanged"
QT_MOC_LITERAL(31, 341, 15) // "onErrorOccurred"

    },
    "PlayerWorker\0playNextRequested\0\0"
    "metadataReady\0MusicInfo\0info\0stateChanged\0"
    "QMediaPlayer::State\0state\0positionChanged\0"
    "pos\0durationChanged\0duration\0errorOccurred\0"
    "QMediaPlayer::Error\0error\0msg\0"
    "mediaStatusChanged\0QMediaPlayer::MediaStatus\0"
    "status\0play\0url\0pause\0a\0resume\0stop\0"
    "setPosition\0setVolume\0volume\0"
    "onPlayerStateChanged\0onMediaStatusChanged\0"
    "onErrorOccurred"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayerWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    1,   95,    2, 0x06 /* Public */,
       6,    1,   98,    2, 0x06 /* Public */,
       9,    1,  101,    2, 0x06 /* Public */,
      11,    1,  104,    2, 0x06 /* Public */,
      13,    2,  107,    2, 0x06 /* Public */,
      17,    1,  112,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    1,  115,    2, 0x0a /* Public */,
      22,    1,  118,    2, 0x0a /* Public */,
      24,    0,  121,    2, 0x0a /* Public */,
      25,    0,  122,    2, 0x0a /* Public */,
      26,    1,  123,    2, 0x0a /* Public */,
      27,    1,  126,    2, 0x0a /* Public */,
      29,    1,  129,    2, 0x08 /* Private */,
      30,    1,  132,    2, 0x08 /* Private */,
      31,    1,  135,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::LongLong,   10,
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void, 0x80000000 | 14, QMetaType::QString,   15,   16,
    QMetaType::Void, 0x80000000 | 18,   19,

 // slots: parameters
    QMetaType::Void, QMetaType::QUrl,   21,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   10,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void PlayerWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlayerWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playNextRequested(); break;
        case 1: _t->metadataReady((*reinterpret_cast< const MusicInfo(*)>(_a[1]))); break;
        case 2: _t->stateChanged((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 3: _t->positionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->durationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->errorOccurred((*reinterpret_cast< QMediaPlayer::Error(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->mediaStatusChanged((*reinterpret_cast< QMediaPlayer::MediaStatus(*)>(_a[1]))); break;
        case 7: _t->play((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 8: _t->pause((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->resume(); break;
        case 10: _t->stop(); break;
        case 11: _t->setPosition((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 12: _t->setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->onPlayerStateChanged((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 14: _t->onMediaStatusChanged((*reinterpret_cast< QMediaPlayer::MediaStatus(*)>(_a[1]))); break;
        case 15: _t->onErrorOccurred((*reinterpret_cast< QMediaPlayer::Error(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
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
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::Error >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::MediaStatus >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::MediaStatus >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::Error >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlayerWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerWorker::playNextRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlayerWorker::*)(const MusicInfo & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerWorker::metadataReady)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PlayerWorker::*)(QMediaPlayer::State );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerWorker::stateChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PlayerWorker::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerWorker::positionChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PlayerWorker::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerWorker::durationChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PlayerWorker::*)(QMediaPlayer::Error , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerWorker::errorOccurred)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PlayerWorker::*)(QMediaPlayer::MediaStatus );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerWorker::mediaStatusChanged)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PlayerWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PlayerWorker.data,
    qt_meta_data_PlayerWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PlayerWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayerWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayerWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PlayerWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void PlayerWorker::playNextRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PlayerWorker::metadataReady(const MusicInfo & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PlayerWorker::stateChanged(QMediaPlayer::State _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PlayerWorker::positionChanged(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PlayerWorker::durationChanged(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PlayerWorker::errorOccurred(QMediaPlayer::Error _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PlayerWorker::mediaStatusChanged(QMediaPlayer::MediaStatus _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
