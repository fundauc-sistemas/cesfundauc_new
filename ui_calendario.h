/********************************************************************************
** Form generated from reading UI file 'calendario.ui'
**
** Created: Fri 30. May 09:27:21 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARIO_H
#define UI_CALENDARIO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calendarios
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *id_calendario;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *descripcion;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *periodos;
    QCheckBox *otra_mod;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *modalidad;
    QLineEdit *periodos2;
    QPushButton *agregar;
    QPushButton *quitar;
    QTableWidget *tabla;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *aceptar;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *calendarios)
    {
        if (calendarios->objectName().isEmpty())
            calendarios->setObjectName(QString::fromUtf8("calendarios"));
        calendarios->resize(509, 451);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        calendarios->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(calendarios);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(calendarios);
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
        label_2 = new QLabel(calendarios);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(112, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        id_calendario = new QLineEdit(calendarios);
        id_calendario->setObjectName(QString::fromUtf8("id_calendario"));
        id_calendario->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(id_calendario);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(calendarios);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(112, 0));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_3);

        descripcion = new QLineEdit(calendarios);
        descripcion->setObjectName(QString::fromUtf8("descripcion"));
        descripcion->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(descripcion);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(calendarios);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(112, 0));
        label_4->setFont(font1);
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_4);

        periodos = new QLineEdit(calendarios);
        periodos->setObjectName(QString::fromUtf8("periodos"));
        periodos->setMinimumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(periodos);


        verticalLayout->addLayout(horizontalLayout_3);

        otra_mod = new QCheckBox(calendarios);
        otra_mod->setObjectName(QString::fromUtf8("otra_mod"));
        otra_mod->setFont(font1);

        verticalLayout->addWidget(otra_mod);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(260, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        label_5 = new QLabel(calendarios);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(59, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        modalidad = new QComboBox(calendarios);
        modalidad->setObjectName(QString::fromUtf8("modalidad"));
        modalidad->setEnabled(false);
        modalidad->setMinimumSize(QSize(260, 25));

        horizontalLayout_5->addWidget(modalidad);

        periodos2 = new QLineEdit(calendarios);
        periodos2->setObjectName(QString::fromUtf8("periodos2"));
        periodos2->setEnabled(false);
        periodos2->setMinimumSize(QSize(0, 25));

        horizontalLayout_5->addWidget(periodos2);

        agregar = new QPushButton(calendarios);
        agregar->setObjectName(QString::fromUtf8("agregar"));
        agregar->setEnabled(false);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(9);
        agregar->setFont(font3);

        horizontalLayout_5->addWidget(agregar);

        quitar = new QPushButton(calendarios);
        quitar->setObjectName(QString::fromUtf8("quitar"));
        quitar->setEnabled(false);
        quitar->setFont(font3);

        horizontalLayout_5->addWidget(quitar);


        verticalLayout_2->addLayout(horizontalLayout_5);

        tabla = new QTableWidget(calendarios);
        if (tabla->columnCount() < 2)
            tabla->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        tabla->setEnabled(false);
        tabla->setFont(font3);

        verticalLayout_2->addWidget(tabla);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        aceptar = new QPushButton(calendarios);
        aceptar->setObjectName(QString::fromUtf8("aceptar"));
        aceptar->setFont(font3);

        horizontalLayout_4->addWidget(aceptar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(calendarios);

        QMetaObject::connectSlotsByName(calendarios);
    } // setupUi

    void retranslateUi(QWidget *calendarios)
    {
        calendarios->setWindowTitle(QApplication::translate("calendarios", "CONTROL DE ESTUDIOS", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("calendarios", " Calendario Academico", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("calendarios", "ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("calendarios", "Descripcion", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("calendarios", "Periodos Intensivos", 0, QApplication::UnicodeUTF8));
        otra_mod->setText(QApplication::translate("calendarios", "Otras Modalidades", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("calendarios", "Per\303\255odos", 0, QApplication::UnicodeUTF8));
        agregar->setText(QApplication::translate("calendarios", "Agregar", 0, QApplication::UnicodeUTF8));
        quitar->setText(QApplication::translate("calendarios", "Quitar", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("calendarios", "Modalidad", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("calendarios", "Periodos", 0, QApplication::UnicodeUTF8));
        aceptar->setText(QApplication::translate("calendarios", "Aceptar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class calendarios: public Ui_calendarios {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARIO_H
