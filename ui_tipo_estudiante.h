/********************************************************************************
** Form generated from reading UI file 'tipo_estudiante.ui'
**
** Created: Fri 30. May 09:27:17 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIPO_ESTUDIANTE_H
#define UI_TIPO_ESTUDIANTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tipo_estudiante
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tabla;

    void setupUi(QWidget *tipo_estudiante)
    {
        if (tipo_estudiante->objectName().isEmpty())
            tipo_estudiante->setObjectName(QString::fromUtf8("tipo_estudiante"));
        tipo_estudiante->resize(448, 361);
        tipo_estudiante->setMaximumSize(QSize(450, 370));
        verticalLayout = new QVBoxLayout(tipo_estudiante);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(tipo_estudiante);
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

        tabla = new QTableWidget(tipo_estudiante);
        if (tabla->columnCount() < 2)
            tabla->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(9);
        tabla->setFont(font1);

        verticalLayout->addWidget(tabla);


        retranslateUi(tipo_estudiante);

        QMetaObject::connectSlotsByName(tipo_estudiante);
    } // setupUi

    void retranslateUi(QWidget *tipo_estudiante)
    {
        tipo_estudiante->setWindowTitle(QApplication::translate("tipo_estudiante", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("tipo_estudiante", "Tipos Estudiante", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("tipo_estudiante", "Id", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("tipo_estudiante", "Descripcion", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class tipo_estudiante: public Ui_tipo_estudiante {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIPO_ESTUDIANTE_H
