/****************************************************************************
** Meta object code from reading C++ file 'processface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../processface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProcessFace_t {
    QByteArrayData data[13];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProcessFace_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProcessFace_t qt_meta_stringdata_ProcessFace = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ProcessFace"
QT_MOC_LITERAL(1, 12, 12), // "startClicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "readFrame"
QT_MOC_LITERAL(4, 36, 13), // "sketchClicked"
QT_MOC_LITERAL(5, 50, 14), // "cartoonClicked"
QT_MOC_LITERAL(6, 65, 13), // "addHatClicked"
QT_MOC_LITERAL(7, 79, 13), // "addWigClicked"
QT_MOC_LITERAL(8, 93, 19), // "beautifyFaceClicked"
QT_MOC_LITERAL(9, 113, 15), // "maxFrameClicked"
QT_MOC_LITERAL(10, 129, 15), // "minFrameClicked"
QT_MOC_LITERAL(11, 145, 15), // "eyesZoomClicked"
QT_MOC_LITERAL(12, 161, 12) // "closeClicked"

    },
    "ProcessFace\0startClicked\0\0readFrame\0"
    "sketchClicked\0cartoonClicked\0addHatClicked\0"
    "addWigClicked\0beautifyFaceClicked\0"
    "maxFrameClicked\0minFrameClicked\0"
    "eyesZoomClicked\0closeClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProcessFace[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
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

void ProcessFace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProcessFace *_t = static_cast<ProcessFace *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startClicked(); break;
        case 1: _t->readFrame(); break;
        case 2: _t->sketchClicked(); break;
        case 3: _t->cartoonClicked(); break;
        case 4: _t->addHatClicked(); break;
        case 5: _t->addWigClicked(); break;
        case 6: _t->beautifyFaceClicked(); break;
        case 7: _t->maxFrameClicked(); break;
        case 8: _t->minFrameClicked(); break;
        case 9: _t->eyesZoomClicked(); break;
        case 10: _t->closeClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ProcessFace::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ProcessFace.data,
      qt_meta_data_ProcessFace,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ProcessFace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProcessFace::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ProcessFace.stringdata0))
        return static_cast<void*>(const_cast< ProcessFace*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ProcessFace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
