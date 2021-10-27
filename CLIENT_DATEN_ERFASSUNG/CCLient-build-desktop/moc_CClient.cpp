/****************************************************************************
** Meta object code from reading C++ file 'CClient.h'
**
** Created: Sun Jun 20 16:31:28 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CCLient/CClient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CCLient[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      22,   17,    8,    8, 0x08,
      42,    8,    8,    8, 0x08,
      59,   49,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CCLient[] = {
    "CCLient\0\0input()\0text\0sendenable(QString)\0"
    "send()\0time,date\0update(QString,QString)\0"
};

const QMetaObject CCLient::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CCLient,
      qt_meta_data_CCLient, 0 }
};

const QMetaObject *CCLient::metaObject() const
{
    return &staticMetaObject;
}

void *CCLient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CCLient))
        return static_cast<void*>(const_cast< CCLient*>(this));
    return QDialog::qt_metacast(_clname);
}

int CCLient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: input(); break;
        case 1: sendenable((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: send(); break;
        case 3: update((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
