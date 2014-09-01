/********************************************************************************
** Form generated from reading UI file 'mercadeo.ui'
**
** Created: Mon 26. May 11:14:01 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MERCADEO_H
#define UI_MERCADEO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mercadeo
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titulo;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_curso;
    QComboBox *curso;
    QLabel *label_nivel;
    QComboBox *nivel;
    QLabel *label_mod;
    QComboBox *modalidad;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_horario;
    QComboBox *horario;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QComboBox *reporte;
    QTableWidget *tabla;

    void setupUi(QWidget *mercadeo)
    {
        if (mercadeo->objectName().isEmpty())
            mercadeo->setObjectName(QString::fromUtf8("mercadeo"));
        mercadeo->resize(975, 603);
        verticalLayout = new QVBoxLayout(mercadeo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titulo = new QLabel(mercadeo);
        titulo->setObjectName(QString::fromUtf8("titulo"));
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans MT"));
        font.setPointSize(22);
        titulo->setFont(font);
        titulo->setStyleSheet(QString::fromUtf8("font: 22pt \"Gill Sans MT\";\n"
"color: rgb(00,56,147);"));
        titulo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(titulo);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_curso = new QLabel(mercadeo);
        label_curso->setObjectName(QString::fromUtf8("label_curso"));
        label_curso->setMinimumSize(QSize(70, 0));
        label_curso->setMaximumSize(QSize(70, 16777215));
        QFont font1;
        font1.setPointSize(10);
        label_curso->setFont(font1);

        horizontalLayout->addWidget(label_curso);

        curso = new QComboBox(mercadeo);
        curso->setObjectName(QString::fromUtf8("curso"));
        curso->setMinimumSize(QSize(320, 25));
        curso->setMaximumSize(QSize(320, 25));

        horizontalLayout->addWidget(curso);

        label_nivel = new QLabel(mercadeo);
        label_nivel->setObjectName(QString::fromUtf8("label_nivel"));
        label_nivel->setMinimumSize(QSize(70, 0));
        label_nivel->setMaximumSize(QSize(70, 16777215));
        label_nivel->setFont(font1);

        horizontalLayout->addWidget(label_nivel);

        nivel = new QComboBox(mercadeo);
        nivel->setObjectName(QString::fromUtf8("nivel"));
        nivel->setMinimumSize(QSize(0, 25));
        nivel->setMaximumSize(QSize(70, 16777215));

        horizontalLayout->addWidget(nivel);

        label_mod = new QLabel(mercadeo);
        label_mod->setObjectName(QString::fromUtf8("label_mod"));
        label_mod->setMinimumSize(QSize(70, 0));
        label_mod->setMaximumSize(QSize(70, 16777215));
        label_mod->setFont(font1);

        horizontalLayout->addWidget(label_mod);

        modalidad = new QComboBox(mercadeo);
        modalidad->setObjectName(QString::fromUtf8("modalidad"));
        modalidad->setMinimumSize(QSize(320, 25));
        modalidad->setMaximumSize(QSize(320, 16777215));

        horizontalLayout->addWidget(modalidad);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_horario = new QLabel(mercadeo);
        label_horario->setObjectName(QString::fromUtf8("label_horario"));
        label_horario->setMinimumSize(QSize(70, 0));
        label_horario->setMaximumSize(QSize(70, 16777215));
        label_horario->setFont(font1);

        horizontalLayout_2->addWidget(label_horario);

        horario = new QComboBox(mercadeo);
        horario->setObjectName(QString::fromUtf8("horario"));
        horario->setMinimumSize(QSize(250, 25));
        horario->setMaximumSize(QSize(250, 16777215));

        horizontalLayout_2->addWidget(horario);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_5 = new QLabel(mercadeo);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(70, 0));
        label_5->setMaximumSize(QSize(70, 16777215));
        label_5->setFont(font1);

        horizontalLayout_2->addWidget(label_5);

        reporte = new QComboBox(mercadeo);
        reporte->setObjectName(QString::fromUtf8("reporte"));
        reporte->setMinimumSize(QSize(250, 25));
        reporte->setMaximumSize(QSize(250, 16777215));

        horizontalLayout_2->addWidget(reporte);


        verticalLayout->addLayout(horizontalLayout_2);

        tabla = new QTableWidget(mercadeo);
        if (tabla->columnCount() < 4)
            tabla->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tabla->setObjectName(QString::fromUtf8("tabla"));

        verticalLayout->addWidget(tabla);


        retranslateUi(mercadeo);

        QMetaObject::connectSlotsByName(mercadeo);
    } // setupUi

    void retranslateUi(QWidget *mercadeo)
    {
        mercadeo->setWindowTitle(QApplication::translate("mercadeo", "Form", 0, QApplication::UnicodeUTF8));
        titulo->setText(QApplication::translate("mercadeo", "Estudiantes Idiomas", 0, QApplication::UnicodeUTF8));
        label_curso->setText(QApplication::translate("mercadeo", "Curso", 0, QApplication::UnicodeUTF8));
        label_nivel->setText(QApplication::translate("mercadeo", "Nivel", 0, QApplication::UnicodeUTF8));
        label_mod->setText(QApplication::translate("mercadeo", "Modalidad", 0, QApplication::UnicodeUTF8));
        label_horario->setText(QApplication::translate("mercadeo", "Horario", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("mercadeo", "Reporte", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("mercadeo", "Nombre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("mercadeo", "C\303\251dula", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("mercadeo", "Email", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("mercadeo", "Telefonos", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mercadeo: public Ui_mercadeo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERCADEO_H
