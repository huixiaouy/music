/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../music/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[23];
    char stringdata0[418];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 19), // "on_addmusic_clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 21), // "on_playButton_clicked"
QT_MOC_LITERAL(4, 50, 22), // "on_pauseButton_clicked"
QT_MOC_LITERAL(5, 73, 26), // "on_progress_sliderReleased"
QT_MOC_LITERAL(6, 100, 25), // "handPlayerPositionChanged"
QT_MOC_LITERAL(7, 126, 8), // "position"
QT_MOC_LITERAL(8, 135, 33), // "handlePlaylistCurrentMediaCha..."
QT_MOC_LITERAL(9, 169, 13), // "QMediaContent"
QT_MOC_LITERAL(10, 183, 7), // "content"
QT_MOC_LITERAL(11, 191, 23), // "on_playbackMode_clicked"
QT_MOC_LITERAL(12, 215, 23), // "handplaybackModeChanged"
QT_MOC_LITERAL(13, 239, 28), // "QMediaPlaylist::PlaybackMode"
QT_MOC_LITERAL(14, 268, 4), // "mode"
QT_MOC_LITERAL(15, 273, 25), // "on_previousButton_clicked"
QT_MOC_LITERAL(16, 299, 21), // "on_nextButton_clicked"
QT_MOC_LITERAL(17, 321, 11), // "handTimeout"
QT_MOC_LITERAL(18, 333, 13), // "handplayState"
QT_MOC_LITERAL(19, 347, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(20, 367, 5), // "state"
QT_MOC_LITERAL(21, 373, 21), // "on_addmusic_2_clicked"
QT_MOC_LITERAL(22, 395, 22) // "on_clearButton_clicked"

    },
    "Widget\0on_addmusic_clicked\0\0"
    "on_playButton_clicked\0on_pauseButton_clicked\0"
    "on_progress_sliderReleased\0"
    "handPlayerPositionChanged\0position\0"
    "handlePlaylistCurrentMediaChanged\0"
    "QMediaContent\0content\0on_playbackMode_clicked\0"
    "handplaybackModeChanged\0"
    "QMediaPlaylist::PlaybackMode\0mode\0"
    "on_previousButton_clicked\0"
    "on_nextButton_clicked\0handTimeout\0"
    "handplayState\0QMediaPlayer::State\0"
    "state\0on_addmusic_2_clicked\0"
    "on_clearButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    1,   88,    2, 0x08 /* Private */,
       8,    1,   91,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    1,   95,    2, 0x08 /* Private */,
      15,    0,   98,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,
      17,    0,  100,    2, 0x08 /* Private */,
      18,    1,  101,    2, 0x08 /* Private */,
      21,    0,  104,    2, 0x08 /* Private */,
      22,    0,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_addmusic_clicked(); break;
        case 1: _t->on_playButton_clicked(); break;
        case 2: _t->on_pauseButton_clicked(); break;
        case 3: _t->on_progress_sliderReleased(); break;
        case 4: _t->handPlayerPositionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->handlePlaylistCurrentMediaChanged((*reinterpret_cast< const QMediaContent(*)>(_a[1]))); break;
        case 6: _t->on_playbackMode_clicked(); break;
        case 7: _t->handplaybackModeChanged((*reinterpret_cast< QMediaPlaylist::PlaybackMode(*)>(_a[1]))); break;
        case 8: _t->on_previousButton_clicked(); break;
        case 9: _t->on_nextButton_clicked(); break;
        case 10: _t->handTimeout(); break;
        case 11: _t->handplayState((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;

        case 13: _t->on_clearButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaContent >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlaylist::PlaybackMode >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
