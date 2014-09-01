/********************************************************************************
** Form generated from reading UI file 'control_evaluacion.ui'
**
** Created: Wed 13. Jun 11:53:17 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_EVALUACION_H
#define UI_CONTROL_EVALUACION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_evaluacion
{
public:
    QVBoxLayout *verticalLayout_4;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *profesor;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *metodo;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *nivel;
    QLabel *label_15;
    QComboBox *seccion;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *periodo;
    QLabel *label_6;
    QLineEdit *inicio;
    QLabel *label_7;
    QLineEdit *fin;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLineEdit *idioma;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QLineEdit *modalidad;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLineEdit *horario;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_11;
    QLineEdit *aprob;
    QLabel *label_14;
    QLineEdit *nc;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_12;
    QLineEdit *naprob;
    QLabel *label_16;
    QLineEdit *ubic;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_13;
    QLineEdit *rep;
    QLabel *label_17;
    QLineEdit *nivel_2;
    QSpacerItem *verticalSpacer_4;
    QTableWidget *tabla;

    void setupUi(QWidget *evaluacion)
    {
        if (evaluacion->objectName().isEmpty())
            evaluacion->setObjectName(QString::fromUtf8("evaluacion"));
        evaluacion->resize(1139, 700);
        verticalLayout_4 = new QVBoxLayout(evaluacion);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_19 = new QLabel(evaluacion);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(20);
        label_19->setFont(font);
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_19);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(evaluacion);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(50, 0));
        label->setMaximumSize(QSize(55, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        profesor = new QComboBox(evaluacion);
        profesor->setObjectName(QString::fromUtf8("profesor"));
        profesor->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(profesor);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(evaluacion);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(50, 0));
        label_2->setMaximumSize(QSize(55, 16777215));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        metodo = new QComboBox(evaluacion);
        metodo->setObjectName(QString::fromUtf8("metodo"));
        metodo->setMinimumSize(QSize(0, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        metodo->setFont(font2);

        horizontalLayout_2->addWidget(metodo);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(evaluacion);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(55, 0));
        label_3->setMaximumSize(QSize(55, 16777215));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        nivel = new QComboBox(evaluacion);
        nivel->setObjectName(QString::fromUtf8("nivel"));
        nivel->setMinimumSize(QSize(0, 25));
        nivel->setMaximumSize(QSize(70, 16777215));
        nivel->setFont(font2);

        horizontalLayout_3->addWidget(nivel);

        label_15 = new QLabel(evaluacion);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(55, 0));
        label_15->setMaximumSize(QSize(55, 16777215));
        label_15->setFont(font1);
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_15);

        seccion = new QComboBox(evaluacion);
        seccion->setObjectName(QString::fromUtf8("seccion"));
        seccion->setMinimumSize(QSize(80, 25));
        seccion->setFont(font2);

        horizontalLayout_3->addWidget(seccion);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(evaluacion);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(55, 0));
        label_5->setMaximumSize(QSize(55, 16777215));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_5);

        periodo = new QComboBox(evaluacion);
        periodo->setObjectName(QString::fromUtf8("periodo"));
        periodo->setMinimumSize(QSize(0, 25));
        periodo->setMaximumSize(QSize(70, 16777215));
        periodo->setFont(font2);

        horizontalLayout_5->addWidget(periodo);

        label_6 = new QLabel(evaluacion);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(40, 0));
        label_6->setMaximumSize(QSize(50, 16777215));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_6);

        inicio = new QLineEdit(evaluacion);
        inicio->setObjectName(QString::fromUtf8("inicio"));
        inicio->setMinimumSize(QSize(80, 25));
        inicio->setMaximumSize(QSize(70, 16777215));
        inicio->setFont(font2);

        horizontalLayout_5->addWidget(inicio);

        label_7 = new QLabel(evaluacion);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(40, 0));
        label_7->setMaximumSize(QSize(50, 16777215));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_7);

        fin = new QLineEdit(evaluacion);
        fin->setObjectName(QString::fromUtf8("fin"));
        fin->setMinimumSize(QSize(80, 25));
        fin->setMaximumSize(QSize(70, 16777215));
        fin->setFont(font2);

        horizontalLayout_5->addWidget(fin);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_13->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_8 = new QLabel(evaluacion);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(65, 0));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_8);

        idioma = new QLineEdit(evaluacion);
        idioma->setObjectName(QString::fromUtf8("idioma"));
        idioma->setMinimumSize(QSize(100, 25));
        idioma->setMaximumSize(QSize(246, 16777215));
        idioma->setFont(font2);

        horizontalLayout_6->addWidget(idioma);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_10 = new QLabel(evaluacion);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(65, 0));
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_10);

        modalidad = new QLineEdit(evaluacion);
        modalidad->setObjectName(QString::fromUtf8("modalidad"));
        modalidad->setMinimumSize(QSize(0, 25));
        modalidad->setMaximumSize(QSize(246, 16777215));
        modalidad->setFont(font2);

        horizontalLayout_8->addWidget(modalidad);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_9 = new QLabel(evaluacion);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(65, 0));
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_9);

        horario = new QLineEdit(evaluacion);
        horario->setObjectName(QString::fromUtf8("horario"));
        horario->setMinimumSize(QSize(100, 25));
        horario->setMaximumSize(QSize(246, 16777215));
        horario->setFont(font2);

        horizontalLayout_7->addWidget(horario);


        verticalLayout_2->addLayout(horizontalLayout_7);


        horizontalLayout_13->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_11 = new QLabel(evaluacion);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(142, 0));
        label_11->setMaximumSize(QSize(142, 16777215));
        label_11->setFont(font1);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_11);

        aprob = new QLineEdit(evaluacion);
        aprob->setObjectName(QString::fromUtf8("aprob"));
        aprob->setMinimumSize(QSize(40, 25));
        aprob->setMaximumSize(QSize(40, 16777215));
        aprob->setFont(font2);

        horizontalLayout_9->addWidget(aprob);

        label_14 = new QLabel(evaluacion);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(142, 0));
        label_14->setMaximumSize(QSize(142, 16777215));
        label_14->setFont(font1);
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_14);

        nc = new QLineEdit(evaluacion);
        nc->setObjectName(QString::fromUtf8("nc"));
        nc->setMinimumSize(QSize(40, 25));
        nc->setMaximumSize(QSize(40, 16777215));
        nc->setFont(font2);

        horizontalLayout_9->addWidget(nc);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_12 = new QLabel(evaluacion);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(16, 0));
        label_12->setFont(font1);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(label_12);

        naprob = new QLineEdit(evaluacion);
        naprob->setObjectName(QString::fromUtf8("naprob"));
        naprob->setMinimumSize(QSize(40, 25));
        naprob->setMaximumSize(QSize(40, 16777215));
        naprob->setFont(font2);

        horizontalLayout_10->addWidget(naprob);

        label_16 = new QLabel(evaluacion);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(142, 0));
        label_16->setFont(font1);
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(label_16);

        ubic = new QLineEdit(evaluacion);
        ubic->setObjectName(QString::fromUtf8("ubic"));
        ubic->setMinimumSize(QSize(40, 25));
        ubic->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_10->addWidget(ubic);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_13 = new QLabel(evaluacion);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(142, 0));
        label_13->setFont(font1);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(label_13);

        rep = new QLineEdit(evaluacion);
        rep->setObjectName(QString::fromUtf8("rep"));
        rep->setMinimumSize(QSize(40, 25));
        rep->setMaximumSize(QSize(40, 16777215));
        rep->setFont(font2);

        horizontalLayout_11->addWidget(rep);

        label_17 = new QLabel(evaluacion);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(142, 0));
        label_17->setFont(font1);
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(label_17);

        nivel_2 = new QLineEdit(evaluacion);
        nivel_2->setObjectName(QString::fromUtf8("nivel_2"));
        nivel_2->setMinimumSize(QSize(40, 25));
        nivel_2->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_11->addWidget(nivel_2);


        verticalLayout_3->addLayout(horizontalLayout_11);


        horizontalLayout_13->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_13);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_4);

        tabla = new QTableWidget(evaluacion);
        if (tabla->columnCount() < 6)
            tabla->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        tabla->setFont(font3);

        verticalLayout_4->addWidget(tabla);


        retranslateUi(evaluacion);

        QMetaObject::connectSlotsByName(evaluacion);
    } // setupUi

    void retranslateUi(QWidget *evaluacion)
    {
        evaluacion->setWindowTitle(QApplication::translate("evaluacion", "Form", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("evaluacion", "Control de Evaluacion - Idiomas", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("evaluacion", "Profesor", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("evaluacion", "Metodo", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("evaluacion", "Nivel", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("evaluacion", "Seccion", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("evaluacion", "Periodo", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("evaluacion", "Inicio", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("evaluacion", "Fin", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("evaluacion", "Idioma", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("evaluacion", "Modalidad", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("evaluacion", "Horario", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("evaluacion", "Alumnos Aprobados", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("evaluacion", "No Cursaron", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("evaluacion", "Alumnos No Aprobados", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("evaluacion", "Ingreso por Ubicacion", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("evaluacion", "Repitientes", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("evaluacion", "Ingreso por Nivelaci\303\263n", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("evaluacion", "Nombre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("evaluacion", "Cedula", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("evaluacion", "Factura", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("evaluacion", "Telefono", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("evaluacion", "Definitiva", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tabla->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("evaluacion", "Observaci\303\263n", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class evaluacion: public Ui_evaluacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_EVALUACION_H
