/********************************************************************************
** Form generated from reading UI file 'carga_academica.ui'
**
** Created: Fri 30. May 09:27:21 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARGA_ACADEMICA_H
#define UI_CARGA_ACADEMICA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ca
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QComboBox *profesor;
    QTableWidget *tabla;

    void setupUi(QWidget *ca)
    {
        if (ca->objectName().isEmpty())
            ca->setObjectName(QString::fromUtf8("ca"));
        ca->resize(538, 500);
        verticalLayout = new QVBoxLayout(ca);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(ca);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(20);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_2);

        label = new QLabel(ca);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        profesor = new QComboBox(ca);
        profesor->setObjectName(QString::fromUtf8("profesor"));
        profesor->setMinimumSize(QSize(0, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        profesor->setFont(font2);

        verticalLayout->addWidget(profesor);

        tabla = new QTableWidget(ca);
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
        tabla->setFont(font2);

        verticalLayout->addWidget(tabla);


        retranslateUi(ca);

        QMetaObject::connectSlotsByName(ca);
    } // setupUi

    void retranslateUi(QWidget *ca)
    {
        ca->setWindowTitle(QApplication::translate("ca", "Form", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ca", "Carga Academica", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ca", "Profesor", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ca", "Renglon", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ca", "Metodo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ca", "Modalidad", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ca", "Horario", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ca", "Nivel", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tabla->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("ca", "Periodo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ca: public Ui_ca {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARGA_ACADEMICA_H
