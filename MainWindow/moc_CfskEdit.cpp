/****************************************************************************
** Meta object code from reading C++ file 'CfskEdit.h'
**
** Created: Sun Apr 18 15:47:11 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CfskEdit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CfskEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CFskEdit[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      17,   10,    9,    9, 0x05,
      55,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      93,    9,    9,    9, 0x08,
     112,  107,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CFskEdit[] = {
    "CFskEdit\0\0str,cs\0findNext(QString,Qt::CaseSensitivity)\0"
    "findPrev(QString,Qt::CaseSensitivity)\0"
    "findClicked()\0text\0enableFindButton(QString)\0"
};

const QMetaObject CFskEdit::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CFskEdit,
      qt_meta_data_CFskEdit, 0 }
};

const QMetaObject *CFskEdit::metaObject() const
{
    return &staticMetaObject;
}

void *CFskEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CFskEdit))
        return static_cast<void*>(const_cast< CFskEdit*>(this));
    return QDialog::qt_metacast(_clname);
}

int CFskEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: findNext((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Qt::CaseSensitivity(*)>(_a[2]))); break;
        case 1: findPrev((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Qt::CaseSensitivity(*)>(_a[2]))); break;
        case 2: findClicked(); break;
        case 3: enableFindButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CFskEdit::findNext(const QString & _t1, Qt::CaseSensitivity _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CFskEdit::findPrev(const QString & _t1, Qt::CaseSensitivity _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
