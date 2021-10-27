/****************************************************************************
** Meta object code from reading C++ file 'CNewFsk.h'
**
** Created: Thu Apr 22 18:47:36 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CNewFsk.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CNewFsk.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CNewFsk[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      11,    9,    8,    8, 0x08,
      27,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CNewFsk[] = {
    "CNewFsk\0\0i\0changeLine(int)\0CreateFsk()\0"
};

const QMetaObject CNewFsk::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CNewFsk,
      qt_meta_data_CNewFsk, 0 }
};

const QMetaObject *CNewFsk::metaObject() const
{
    return &staticMetaObject;
}

void *CNewFsk::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CNewFsk))
        return static_cast<void*>(const_cast< CNewFsk*>(this));
    return QDialog::qt_metacast(_clname);
}

int CNewFsk::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: changeLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: CreateFsk(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
