/********************************************************************************
** Form generated from reading UI file 'calendarios.ui'
**
** Created: Mon 26. May 11:14:00 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARIOS_H
#define UI_CALENDARIOS_H

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

class Ui_calendario
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *calendarios;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *modalidad;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tabla;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tabla2;

    void setupUi(QWidget *calendario)
    {
        if (calendario->objectName().isEmpty())
            calendario->setObjectName(QString::fromUtf8("calendario"));
        calendario->resize(700, 550);
        calendario->setMaximumSize(QSize(700, 550));
        verticalLayout = new QVBoxLayout(calendario);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(calendario);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(150, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        calendarios = new QComboBox(calendario);
        calendarios->setObjectName(QString::fromUtf8("calendarios"));
        calendarios->setMinimumSize(QSize(0, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(9);
        calendarios->setFont(font1);

        horizontalLayout->addWidget(calendarios);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_2 = new QLabel(calendario);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(319, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(10);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(calendario);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        modalidad = new QComboBox(calendario);
        modalidad->setObjectName(QString::fromUtf8("modalidad"));
        modalidad->setFont(font1);

        horizontalLayout_3->addWidget(modalidad);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabla = new QTableWidget(calendario);
        if (tabla->columnCount() < 3)
            tabla->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        tabla->setMaximumSize(QSize(400, 16777215));
        tabla->setFont(font1);

        horizontalLayout_2->addWidget(tabla);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        tabla2 = new QTableWidget(calendario);
        if (tabla2->columnCount() < 3)
            tabla2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tabla2->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tabla2->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tabla2->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        tabla2->setObjectName(QString::fromUtf8("tabla2"));
        tabla2->setFont(font1);

        horizontalLayout_2->addWidget(tabla2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(calendario);

        QMetaObject::connectSlotsByName(calendario);
    } // setupUi

    void retranslateUi(QWidget *calendario)
    {
        calendario->setWindowTitle(QApplication::translate("calendario", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("calendario", "Calendario Acad\303\251mico", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("calendario", "Periodos Academicos / Otras modalidades", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("calendario", "Periodos Academicos Intensivos", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("calendario", "Periodo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("calendario", "Fecha Inicio", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("calendario", "Fecha Fin", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tabla2->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("calendario", "Periodo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tabla2->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("calendario", "Fecha Inicio", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tabla2->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("calendario", "Fecha Fin", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class calendario: public Ui_calendario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARIOS_H
