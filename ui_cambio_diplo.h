/********************************************************************************
** Form generated from reading UI file 'cambio_diplo.ui'
**
** Created: Fri 30. May 09:27:21 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMBIO_DIPLO_H
#define UI_CAMBIO_DIPLO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cambio_diplo
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *rhorario;
    QRadioButton *rdiplomado;
    QHBoxLayout *horizontalLayout_8;
    QLabel *etiqueta;
    QComboBox *seleccion;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QComboBox *seleccion2;
    QSpacerItem *horizontalSpacer_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *aceptar;
    QSpacerItem *horizontalSpacer_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *matricula;
    QLabel *label_3;
    QLineEdit *cedula;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *nombre;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *diplomado;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLineEdit *cohorte;
    QLabel *label_6;
    QLineEdit *horario;

    void setupUi(QWidget *cambio_diplo)
    {
        if (cambio_diplo->objectName().isEmpty())
            cambio_diplo->setObjectName(QString::fromUtf8("cambio_diplo"));
        cambio_diplo->resize(545, 381);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        cambio_diplo->setWindowIcon(icon);
        groupBox = new QGroupBox(cambio_diplo);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 220, 521, 111));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        groupBox->setFont(font);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 501, 91));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        rhorario = new QRadioButton(layoutWidget);
        rhorario->setObjectName(QString::fromUtf8("rhorario"));

        horizontalLayout_6->addWidget(rhorario);

        rdiplomado = new QRadioButton(layoutWidget);
        rdiplomado->setObjectName(QString::fromUtf8("rdiplomado"));

        horizontalLayout_6->addWidget(rdiplomado);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        etiqueta = new QLabel(layoutWidget);
        etiqueta->setObjectName(QString::fromUtf8("etiqueta"));
        etiqueta->setMinimumSize(QSize(60, 25));
        etiqueta->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_8->addWidget(etiqueta);

        seleccion = new QComboBox(layoutWidget);
        seleccion->setObjectName(QString::fromUtf8("seleccion"));
        seleccion->setEnabled(false);
        seleccion->setMinimumSize(QSize(350, 25));
        QFont font1;
        font1.setPointSize(9);
        seleccion->setFont(font1);

        horizontalLayout_8->addWidget(seleccion);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(60, 25));

        horizontalLayout_5->addWidget(label_8);

        seleccion2 = new QComboBox(layoutWidget);
        seleccion2->setObjectName(QString::fromUtf8("seleccion2"));
        seleccion2->setEnabled(false);
        seleccion2->setMinimumSize(QSize(350, 25));

        horizontalLayout_5->addWidget(seleccion2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayoutWidget = new QWidget(cambio_diplo);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 340, 501, 31));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        aceptar = new QPushButton(horizontalLayoutWidget);
        aceptar->setObjectName(QString::fromUtf8("aceptar"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        aceptar->setFont(font2);

        horizontalLayout_7->addWidget(aceptar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        layoutWidget1 = new QWidget(cambio_diplo);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 9, 501, 201));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Gill Sans MT"));
        font3.setPointSize(22);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("font: 22pt \"Gill Sans MT\";\n"
"color: rgb(00,56,147);"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(70, 0));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        matricula = new QLineEdit(layoutWidget1);
        matricula->setObjectName(QString::fromUtf8("matricula"));
        matricula->setMinimumSize(QSize(0, 25));
        matricula->setFont(font2);

        horizontalLayout->addWidget(matricula);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(70, 0));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        cedula = new QLineEdit(layoutWidget1);
        cedula->setObjectName(QString::fromUtf8("cedula"));
        cedula->setMinimumSize(QSize(0, 25));
        cedula->setMaximumSize(QSize(170, 16777215));
        cedula->setFont(font2);

        horizontalLayout->addWidget(cedula);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(70, 0));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_4);

        nombre = new QLineEdit(layoutWidget1);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setMinimumSize(QSize(0, 25));
        nombre->setFont(font2);
        nombre->setReadOnly(true);

        horizontalLayout_2->addWidget(nombre);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(70, 0));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_5);

        diplomado = new QLineEdit(layoutWidget1);
        diplomado->setObjectName(QString::fromUtf8("diplomado"));
        diplomado->setMinimumSize(QSize(0, 25));
        diplomado->setFont(font2);
        diplomado->setReadOnly(true);

        horizontalLayout_3->addWidget(diplomado);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(70, 0));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_7);

        cohorte = new QLineEdit(layoutWidget1);
        cohorte->setObjectName(QString::fromUtf8("cohorte"));
        cohorte->setMinimumSize(QSize(0, 25));
        cohorte->setMaximumSize(QSize(170, 16777215));
        cohorte->setFont(font2);

        horizontalLayout_4->addWidget(cohorte);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(70, 0));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_6);

        horario = new QLineEdit(layoutWidget1);
        horario->setObjectName(QString::fromUtf8("horario"));
        horario->setMinimumSize(QSize(200, 25));
        horario->setMaximumSize(QSize(200, 16777215));
        horario->setFont(font2);
        horario->setReadOnly(true);

        horizontalLayout_4->addWidget(horario);


        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(cambio_diplo);

        QMetaObject::connectSlotsByName(cambio_diplo);
    } // setupUi

    void retranslateUi(QWidget *cambio_diplo)
    {
        cambio_diplo->setWindowTitle(QApplication::translate("cambio_diplo", "CONTROL DE ESTUDIOS", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("cambio_diplo", "Cambio", 0, QApplication::UnicodeUTF8));
        rhorario->setText(QApplication::translate("cambio_diplo", "Cohorte", 0, QApplication::UnicodeUTF8));
        rdiplomado->setText(QApplication::translate("cambio_diplo", "Diplomado", 0, QApplication::UnicodeUTF8));
        etiqueta->setText(QApplication::translate("cambio_diplo", "Nuevo", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("cambio_diplo", "TextLabel", 0, QApplication::UnicodeUTF8));
        aceptar->setText(QApplication::translate("cambio_diplo", "Aceptar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("cambio_diplo", "Cambio de Diplomado", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("cambio_diplo", "Matricula", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("cambio_diplo", "Cedula", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("cambio_diplo", "Nombre", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("cambio_diplo", "Diplomado", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("cambio_diplo", "Cohorte", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("cambio_diplo", "Horario", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class cambio_diplo: public Ui_cambio_diplo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMBIO_DIPLO_H
