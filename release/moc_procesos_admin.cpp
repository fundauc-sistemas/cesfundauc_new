/****************************************************************************
** Meta object code from reading C++ file 'procesos_admin.h'
**
** Created: Fri 30. May 09:32:19 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../procesos_admin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'procesos_admin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_procesos_admin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      31,   15,   15,   15, 0x08,
      47,   15,   15,   15, 0x08,
      75,   64,   15,   15, 0x08,
      98,   15,   15,   15, 0x08,
     118,   15,   15,   15, 0x08,
     136,  134,   15,   15, 0x08,
     153,   15,   15,   15, 0x08,
     171,   15,   15,   15, 0x08,
     187,   15,   15,   15, 0x08,
     205,   15,   15,   15, 0x08,
     226,   64,   15,   15, 0x08,
     250,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_procesos_admin[] = {
    "procesos_admin\0\0nuevoUsuario()\0"
    "llenarUsuario()\0guardarUsuario()\0"
    "row,column\0editarUsuario(int,int)\0"
    "actualizarUsuario()\0borrarUsuario()\0"
    "s\0toUpper(QString)\0llenarProgramas()\0"
    "nuevoPrograma()\0guardarPrograma()\0"
    "actualizarPrograma()\0editarPrograma(int,int)\0"
    "eliminarPrograma()\0"
};

void procesos_admin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        procesos_admin *_t = static_cast<procesos_admin *>(_o);
        switch (_id) {
        case 0: _t->nuevoUsuario(); break;
        case 1: _t->llenarUsuario(); break;
        case 2: _t->guardarUsuario(); break;
        case 3: _t->editarUsuario((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->actualizarUsuario(); break;
        case 5: _t->borrarUsuario(); break;
        case 6: _t->toUpper((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->llenarProgramas(); break;
        case 8: _t->nuevoPrograma(); break;
        case 9: _t->guardarPrograma(); break;
        case 10: _t->actualizarPrograma(); break;
        case 11: _t->editarPrograma((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->eliminarPrograma(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData procesos_admin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject procesos_admin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_procesos_admin,
      qt_meta_data_procesos_admin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &procesos_admin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *procesos_admin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *procesos_admin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_procesos_admin))
        return static_cast<void*>(const_cast< procesos_admin*>(this));
    return QWidget::qt_metacast(_clname);
}

int procesos_admin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
