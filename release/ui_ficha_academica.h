/********************************************************************************
** Form generated from reading UI file 'ficha_academica.ui'
**
** Created: Mon 26. May 11:14:00 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FICHA_ACADEMICA_H
#define UI_FICHA_ACADEMICA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_academica
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *matricula;
    QLabel *label_2;
    QLineEdit *cedula;
    QLabel *label_3;
    QLineEdit *nombre;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QTableWidget *tabla;

    void setupUi(QWidget *academica)
    {
        if (academica->objectName().isEmpty())
            academica->setObjectName(QString::fromUtf8("academica"));
        academica->resize(1000, 750);
        academica->setMinimumSize(QSize(0, 500));
        academica->setMaximumSize(QSize(1000, 1000));
        verticalLayout = new QVBoxLayout(academica);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(academica);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans MT"));
        font.setPointSize(22);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("font: 22pt \"Gill Sans MT\";\n"
"color: rgb(00,56,147);"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(academica);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(70, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        matricula = new QLineEdit(academica);
        matricula->setObjectName(QString::fromUtf8("matricula"));
        matricula->setMinimumSize(QSize(0, 25));
        matricula->setMaximumSize(QSize(70, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        matricula->setFont(font2);

        horizontalLayout->addWidget(matricula);

        label_2 = new QLabel(academica);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(70, 0));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        cedula = new QLineEdit(academica);
        cedula->setObjectName(QString::fromUtf8("cedula"));
        cedula->setMinimumSize(QSize(0, 25));
        cedula->setMaximumSize(QSize(100, 16777215));
        cedula->setFont(font2);

        horizontalLayout->addWidget(cedula);

        label_3 = new QLabel(academica);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(70, 0));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        nombre = new QLineEdit(academica);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setMinimumSize(QSize(0, 25));
        nombre->setMaximumSize(QSize(300, 16777215));
        nombre->setFont(font2);

        horizontalLayout->addWidget(nombre);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        tabla = new QTableWidget(academica);
        if (tabla->columnCount() < 9)
            tabla->setColumnCount(9);
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
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        tabla->setFont(font2);

        verticalLayout->addWidget(tabla);


        retranslateUi(academica);

        QMetaObject::connectSlotsByName(academica);
    } // setupUi

    void retranslateUi(QWidget *academica)
    {
        academica->setWindowTitle(QApplication::translate("academica", "Form", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("academica", "Ficha Academica", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("academica", "Matricula", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("academica", "C\303\251dula", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("academica", "Nombre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("academica", "Renglon", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("academica", "Codigo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("academica", "Descripcion", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("academica", "Curso", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("academica", "Seccion", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tabla->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("academica", "Fecha", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tabla->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("academica", "Fecha Inicio", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tabla->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("academica", "Nota", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tabla->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("academica", "Observacion", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class academica: public Ui_academica {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FICHA_ACADEMICA_H
