/********************************************************************************
** Form generated from reading UI file 'periodo_ingreso.ui'
**
** Created: Fri 30. May 09:27:22 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERIODO_INGRESO_H
#define UI_PERIODO_INGRESO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_periodo_ingreso
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDateEdit *fecha_ini;
    QLabel *label_4;
    QDateEdit *fecha_fin;
    QSpacerItem *horizontalSpacer;
    QPushButton *boton;
    QTextEdit *text;

    void setupUi(QWidget *periodo_ingreso)
    {
        if (periodo_ingreso->objectName().isEmpty())
            periodo_ingreso->setObjectName(QString::fromUtf8("periodo_ingreso"));
        periodo_ingreso->resize(400, 201);
        verticalLayout = new QVBoxLayout(periodo_ingreso);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(periodo_ingreso);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans MT"));
        font.setPointSize(22);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 22pt \"Gill Sans MT\";\n"
"color: rgb(00,56,147);"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(periodo_ingreso);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(30, 0));

        horizontalLayout_2->addWidget(label_3);

        fecha_ini = new QDateEdit(periodo_ingreso);
        fecha_ini->setObjectName(QString::fromUtf8("fecha_ini"));
        fecha_ini->setEnabled(true);
        fecha_ini->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(fecha_ini);

        label_4 = new QLabel(periodo_ingreso);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(30, 0));

        horizontalLayout_2->addWidget(label_4);

        fecha_fin = new QDateEdit(periodo_ingreso);
        fecha_fin->setObjectName(QString::fromUtf8("fecha_fin"));
        fecha_fin->setEnabled(true);
        fecha_fin->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(fecha_fin);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        boton = new QPushButton(periodo_ingreso);
        boton->setObjectName(QString::fromUtf8("boton"));
        boton->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(boton);


        verticalLayout->addLayout(horizontalLayout_2);

        text = new QTextEdit(periodo_ingreso);
        text->setObjectName(QString::fromUtf8("text"));
        text->setEnabled(false);
        text->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 16pt \"Gill Sans MT\";"));

        verticalLayout->addWidget(text);


        retranslateUi(periodo_ingreso);

        QMetaObject::connectSlotsByName(periodo_ingreso);
    } // setupUi

    void retranslateUi(QWidget *periodo_ingreso)
    {
        periodo_ingreso->setWindowTitle(QApplication::translate("periodo_ingreso", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("periodo_ingreso", "Ingresos por per\303\255odo", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("periodo_ingreso", "Del", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("periodo_ingreso", "al", 0, QApplication::UnicodeUTF8));
        boton->setText(QApplication::translate("periodo_ingreso", "Consultar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class periodo_ingreso: public Ui_periodo_ingreso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERIODO_INGRESO_H
