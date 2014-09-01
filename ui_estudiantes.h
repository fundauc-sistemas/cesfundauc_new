/********************************************************************************
** Form generated from reading UI file 'estudiantes.ui'
**
** Created: Fri 30. May 09:27:19 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESTUDIANTES_H
#define UI_ESTUDIANTES_H

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

class Ui_estudiantes
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *matricula;
    QLabel *label_2;
    QLineEdit *cedula;
    QLabel *label_4;
    QLineEdit *nombre;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tabla;

    void setupUi(QWidget *estudiantes)
    {
        if (estudiantes->objectName().isEmpty())
            estudiantes->setObjectName(QString::fromUtf8("estudiantes"));
        estudiantes->resize(929, 524);
        verticalLayout = new QVBoxLayout(estudiantes);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(estudiantes);
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
        label_3 = new QLabel(estudiantes);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(60, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        label_3->setFont(font1);

        horizontalLayout->addWidget(label_3);

        matricula = new QLineEdit(estudiantes);
        matricula->setObjectName(QString::fromUtf8("matricula"));
        matricula->setMaximumSize(QSize(120, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        matricula->setFont(font2);

        horizontalLayout->addWidget(matricula);

        label_2 = new QLabel(estudiantes);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        cedula = new QLineEdit(estudiantes);
        cedula->setObjectName(QString::fromUtf8("cedula"));
        cedula->setMinimumSize(QSize(0, 25));
        cedula->setMaximumSize(QSize(120, 25));
        cedula->setFont(font2);

        horizontalLayout->addWidget(cedula);

        label_4 = new QLabel(estudiantes);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(60, 0));
        label_4->setFont(font1);

        horizontalLayout->addWidget(label_4);

        nombre = new QLineEdit(estudiantes);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(nombre);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tabla = new QTableWidget(estudiantes);
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


        retranslateUi(estudiantes);

        QMetaObject::connectSlotsByName(estudiantes);
    } // setupUi

    void retranslateUi(QWidget *estudiantes)
    {
        estudiantes->setWindowTitle(QApplication::translate("estudiantes", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("estudiantes", "Estudiantes", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("estudiantes", "Matricula", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("estudiantes", "C\303\251dula", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("estudiantes", "Nombre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("estudiantes", "Cedula", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("estudiantes", "Nombres", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("estudiantes", "Apellidos", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("estudiantes", "Telefono", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("estudiantes", "Telefono Celular", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tabla->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("estudiantes", "Matricula", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tabla->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("estudiantes", "Sede", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tabla->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("estudiantes", "Condicion", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tabla->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("estudiantes", "Condicion Especial", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class estudiantes: public Ui_estudiantes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESTUDIANTES_H
