/********************************************************************************
** Form generated from reading UI file 'cambio_seccion.ui'
**
** Created: Fri 30. May 09:27:21 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMBIO_SECCION_H
#define UI_CAMBIO_SECCION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cambio_seccion
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *matricula;
    QLabel *label_3;
    QLineEdit *cedula;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *nombre;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *curso;
    QLabel *label_6;
    QLineEdit *nivel;
    QLabel *label_7;
    QLineEdit *seccion;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLineEdit *condicion;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_11;
    QComboBox *nuevo_metodo;
    QLabel *label_10;
    QComboBox *nuevo_nivel;
    QLabel *label_9;
    QComboBox *nueva_seccion;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *aceptar;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *cambio_seccion)
    {
        if (cambio_seccion->objectName().isEmpty())
            cambio_seccion->setObjectName(QString::fromUtf8("cambio_seccion"));
        cambio_seccion->resize(554, 345);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        cambio_seccion->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(cambio_seccion);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(cambio_seccion);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans MT"));
        font.setPointSize(22);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 22pt \"Gill Sans MT\";\n"
"color: rgb(00,56,147);"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(cambio_seccion);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(60, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        matricula = new QLineEdit(cambio_seccion);
        matricula->setObjectName(QString::fromUtf8("matricula"));
        matricula->setMinimumSize(QSize(120, 25));
        matricula->setMaximumSize(QSize(120, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        matricula->setFont(font2);

        horizontalLayout->addWidget(matricula);

        label_3 = new QLabel(cambio_seccion);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(60, 0));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        cedula = new QLineEdit(cambio_seccion);
        cedula->setObjectName(QString::fromUtf8("cedula"));
        cedula->setMinimumSize(QSize(0, 25));
        cedula->setMaximumSize(QSize(120, 16777215));
        cedula->setFont(font2);

        horizontalLayout->addWidget(cedula);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(cambio_seccion);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(60, 0));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_4);

        nombre = new QLineEdit(cambio_seccion);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setMinimumSize(QSize(0, 25));
        nombre->setFont(font2);
        nombre->setReadOnly(true);

        horizontalLayout_2->addWidget(nombre);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(cambio_seccion);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(60, 0));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_5);

        curso = new QLineEdit(cambio_seccion);
        curso->setObjectName(QString::fromUtf8("curso"));
        curso->setMinimumSize(QSize(120, 25));
        curso->setFont(font2);
        curso->setReadOnly(true);

        horizontalLayout_3->addWidget(curso);

        label_6 = new QLabel(cambio_seccion);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(60, 0));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_6);

        nivel = new QLineEdit(cambio_seccion);
        nivel->setObjectName(QString::fromUtf8("nivel"));
        nivel->setMinimumSize(QSize(0, 25));
        nivel->setMaximumSize(QSize(80, 16777215));
        nivel->setFont(font2);
        nivel->setReadOnly(true);

        horizontalLayout_3->addWidget(nivel);

        label_7 = new QLabel(cambio_seccion);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(70, 0));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_7);

        seccion = new QLineEdit(cambio_seccion);
        seccion->setObjectName(QString::fromUtf8("seccion"));
        seccion->setMinimumSize(QSize(120, 25));
        seccion->setFont(font2);
        seccion->setReadOnly(true);

        horizontalLayout_3->addWidget(seccion);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_8 = new QLabel(cambio_seccion);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(60, 0));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_8);

        condicion = new QLineEdit(cambio_seccion);
        condicion->setObjectName(QString::fromUtf8("condicion"));
        condicion->setMinimumSize(QSize(0, 25));
        condicion->setMaximumSize(QSize(250, 16777215));
        condicion->setFont(font2);
        condicion->setReadOnly(true);

        horizontalLayout_4->addWidget(condicion);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_11 = new QLabel(cambio_seccion);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(85, 0));
        label_11->setFont(font1);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_11);

        nuevo_metodo = new QComboBox(cambio_seccion);
        nuevo_metodo->setObjectName(QString::fromUtf8("nuevo_metodo"));
        nuevo_metodo->setEnabled(false);
        nuevo_metodo->setMinimumSize(QSize(120, 25));

        horizontalLayout_6->addWidget(nuevo_metodo);

        label_10 = new QLabel(cambio_seccion);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(50, 0));
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_10);

        nuevo_nivel = new QComboBox(cambio_seccion);
        nuevo_nivel->setObjectName(QString::fromUtf8("nuevo_nivel"));
        nuevo_nivel->setEnabled(false);
        nuevo_nivel->setMinimumSize(QSize(50, 25));

        horizontalLayout_6->addWidget(nuevo_nivel);

        label_9 = new QLabel(cambio_seccion);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(85, 0));
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_9);

        nueva_seccion = new QComboBox(cambio_seccion);
        nueva_seccion->setObjectName(QString::fromUtf8("nueva_seccion"));
        nueva_seccion->setEnabled(false);
        nueva_seccion->setMinimumSize(QSize(100, 25));
        nueva_seccion->setFont(font2);

        horizontalLayout_6->addWidget(nueva_seccion);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        aceptar = new QPushButton(cambio_seccion);
        aceptar->setObjectName(QString::fromUtf8("aceptar"));
        aceptar->setFont(font2);

        horizontalLayout_5->addWidget(aceptar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(cambio_seccion);

        QMetaObject::connectSlotsByName(cambio_seccion);
    } // setupUi

    void retranslateUi(QWidget *cambio_seccion)
    {
        cambio_seccion->setWindowTitle(QApplication::translate("cambio_seccion", "CONTROL DE ESTUDIOS", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("cambio_seccion", "Cambio de Secci\303\263n", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("cambio_seccion", "Matr\303\255cula", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("cambio_seccion", "C\303\251dula", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("cambio_seccion", "Nombre", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("cambio_seccion", "Curso", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("cambio_seccion", "Nivel", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("cambio_seccion", "Secci\303\263n", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("cambio_seccion", "Condici\303\263n", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("cambio_seccion", "Nuevo Curso", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("cambio_seccion", "Nivel", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("cambio_seccion", "Nueva Secci\303\263n", 0, QApplication::UnicodeUTF8));
        aceptar->setText(QApplication::translate("cambio_seccion", "Aceptar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class cambio_seccion: public Ui_cambio_seccion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMBIO_SECCION_H
