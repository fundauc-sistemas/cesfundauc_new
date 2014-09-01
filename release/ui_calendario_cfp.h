/********************************************************************************
** Form generated from reading UI file 'calendario_cfp.ui'
**
** Created: Mon 26. May 11:14:00 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARIO_CFP_H
#define UI_CALENDARIO_CFP_H

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

class Ui_calendarioPago
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QComboBox *diplomados;
    QLabel *label;
    QComboBox *cohorte;
    QLabel *label_6;
    QLineEdit *fecha_ini;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tabla;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *calendarioPago)
    {
        if (calendarioPago->objectName().isEmpty())
            calendarioPago->setObjectName(QString::fromUtf8("calendarioPago"));
        calendarioPago->resize(430, 479);
        calendarioPago->setMaximumSize(QSize(430, 16777215));
        verticalLayout = new QVBoxLayout(calendarioPago);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(calendarioPago);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        diplomados = new QComboBox(calendarioPago);
        diplomados->setObjectName(QString::fromUtf8("diplomados"));
        diplomados->setMinimumSize(QSize(0, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(9);
        diplomados->setFont(font1);

        verticalLayout->addWidget(diplomados);

        label = new QLabel(calendarioPago);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(10);
        label->setFont(font2);

        verticalLayout->addWidget(label);

        cohorte = new QComboBox(calendarioPago);
        cohorte->setObjectName(QString::fromUtf8("cohorte"));
        cohorte->setMinimumSize(QSize(0, 25));

        verticalLayout->addWidget(cohorte);

        label_6 = new QLabel(calendarioPago);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(16777215, 30));
        label_6->setFont(font);

        verticalLayout->addWidget(label_6);

        fecha_ini = new QLineEdit(calendarioPago);
        fecha_ini->setObjectName(QString::fromUtf8("fecha_ini"));
        fecha_ini->setMinimumSize(QSize(0, 25));
        fecha_ini->setFont(font1);

        verticalLayout->addWidget(fecha_ini);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabla = new QTableWidget(calendarioPago);
        if (tabla->columnCount() < 2)
            tabla->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        tabla->setMaximumSize(QSize(220, 16777215));
        tabla->setFont(font1);

        horizontalLayout->addWidget(tabla);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(calendarioPago);

        QMetaObject::connectSlotsByName(calendarioPago);
    } // setupUi

    void retranslateUi(QWidget *calendarioPago)
    {
        calendarioPago->setWindowTitle(QApplication::translate("calendarioPago", "Form", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("calendarioPago", "Diplomados", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("calendarioPago", "Cohorte", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("calendarioPago", "Fecha de Inicio", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("calendarioPago", "Cuota", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("calendarioPago", "Fecha", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class calendarioPago: public Ui_calendarioPago {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARIO_CFP_H
