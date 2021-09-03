/****************************************************************************
** Meta object code from reading C++ file 'figures.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../App/figures.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'figures.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Figure_t {
    const uint offsetsAndSize[8];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Figure_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Figure_t qt_meta_stringdata_Figure = {
    {
QT_MOC_LITERAL(0, 6), // "Figure"
QT_MOC_LITERAL(7, 12), // "pointChanged"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 12) // "updateFigure"

    },
    "Figure\0pointChanged\0\0updateFigure"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Figure[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   27,    2, 0x0a,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Figure::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Figure *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->pointChanged(); break;
        case 1: _t->updateFigure(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Figure::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Figure::pointChanged)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject Figure::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Figure.offsetsAndSize,
    qt_meta_data_Figure,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Figure_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Figure::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Figure::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Figure.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    if (!strcmp(_clname, "org.qt-project.Qt.QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Figure::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Figure::pointChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Triangle_t {
    const uint offsetsAndSize[2];
    char stringdata0[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Triangle_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Triangle_t qt_meta_stringdata_Triangle = {
    {
QT_MOC_LITERAL(0, 8) // "Triangle"

    },
    "Triangle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Triangle[] = {

 // content:
       9,       // revision
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

void Triangle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject Triangle::staticMetaObject = { {
    QMetaObject::SuperData::link<Figure::staticMetaObject>(),
    qt_meta_stringdata_Triangle.offsetsAndSize,
    qt_meta_data_Triangle,
    qt_static_metacall,
    nullptr,
    nullptr,
    nullptr
} };


const QMetaObject *Triangle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Triangle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Triangle.stringdata0))
        return static_cast<void*>(this);
    return Figure::qt_metacast(_clname);
}

int Triangle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Figure::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Rectangle_t {
    const uint offsetsAndSize[2];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Rectangle_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Rectangle_t qt_meta_stringdata_Rectangle = {
    {
QT_MOC_LITERAL(0, 9) // "Rectangle"

    },
    "Rectangle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Rectangle[] = {

 // content:
       9,       // revision
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

void Rectangle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject Rectangle::staticMetaObject = { {
    QMetaObject::SuperData::link<Figure::staticMetaObject>(),
    qt_meta_stringdata_Rectangle.offsetsAndSize,
    qt_meta_data_Rectangle,
    qt_static_metacall,
    nullptr,
    nullptr,
    nullptr
} };


const QMetaObject *Rectangle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Rectangle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Rectangle.stringdata0))
        return static_cast<void*>(this);
    return Figure::qt_metacast(_clname);
}

int Rectangle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Figure::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Ellipse_t {
    const uint offsetsAndSize[2];
    char stringdata0[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Ellipse_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Ellipse_t qt_meta_stringdata_Ellipse = {
    {
QT_MOC_LITERAL(0, 7) // "Ellipse"

    },
    "Ellipse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ellipse[] = {

 // content:
       9,       // revision
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

void Ellipse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject Ellipse::staticMetaObject = { {
    QMetaObject::SuperData::link<Figure::staticMetaObject>(),
    qt_meta_stringdata_Ellipse.offsetsAndSize,
    qt_meta_data_Ellipse,
    qt_static_metacall,
    nullptr,
    nullptr,
    nullptr
} };


const QMetaObject *Ellipse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ellipse::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Ellipse.stringdata0))
        return static_cast<void*>(this);
    return Figure::qt_metacast(_clname);
}

int Ellipse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Figure::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
