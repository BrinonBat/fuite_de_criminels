/****************************************************************************
** Meta object code from reading C++ file 'Fenetre_Ajout.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Fenetre_Ajout.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Fenetre_Ajout.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Fenetre_Ajout_t {
    QByteArrayData data[10];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Fenetre_Ajout_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Fenetre_Ajout_t qt_meta_stringdata_Fenetre_Ajout = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Fenetre_Ajout"
QT_MOC_LITERAL(1, 14, 14), // "Ajouter_Joueur"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17), // "Ajouter_NonJoueur"
QT_MOC_LITERAL(4, 48, 6), // "Apercu"
QT_MOC_LITERAL(5, 55, 13), // "Lancer_Partie"
QT_MOC_LITERAL(6, 69, 13), // "Choix_Exemple"
QT_MOC_LITERAL(7, 83, 8), // "Exemple1"
QT_MOC_LITERAL(8, 92, 8), // "Exemple2"
QT_MOC_LITERAL(9, 101, 8) // "Exemple3"

    },
    "Fenetre_Ajout\0Ajouter_Joueur\0\0"
    "Ajouter_NonJoueur\0Apercu\0Lancer_Partie\0"
    "Choix_Exemple\0Exemple1\0Exemple2\0"
    "Exemple3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Fenetre_Ajout[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
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

void Fenetre_Ajout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Fenetre_Ajout *_t = static_cast<Fenetre_Ajout *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Ajouter_Joueur(); break;
        case 1: _t->Ajouter_NonJoueur(); break;
        case 2: _t->Apercu(); break;
        case 3: _t->Lancer_Partie(); break;
        case 4: _t->Choix_Exemple(); break;
        case 5: _t->Exemple1(); break;
        case 6: _t->Exemple2(); break;
        case 7: _t->Exemple3(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Fenetre_Ajout::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Fenetre_Ajout.data,
      qt_meta_data_Fenetre_Ajout,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Fenetre_Ajout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Fenetre_Ajout::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Fenetre_Ajout.stringdata0))
        return static_cast<void*>(const_cast< Fenetre_Ajout*>(this));
    return QWidget::qt_metacast(_clname);
}

int Fenetre_Ajout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
