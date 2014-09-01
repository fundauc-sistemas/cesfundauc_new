/********************************************************************************
** Form generated from reading UI file 'cursos.ui'
**
** Created: Mon 26. May 11:14:00 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURSOS_H
#define UI_CURSOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cursos
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QTableWidget *tabla_metodo;

    void setupUi(QWidget *cursos)
    {
        if (cursos->objectName().isEmpty())
            cursos->setObjectName(QString::fromUtf8("cursos"));
        cursos->resize(1147, 590);
        cursos->setMaximumSize(QSize(1150, 16777215));
        verticalLayout = new QVBoxLayout(cursos);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(cursos);
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

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        tabla_metodo = new QTableWidget(cursos);
        if (tabla_metodo->columnCount() < 8)
            tabla_metodo->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla_metodo->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla_metodo->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabla_metodo->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tabla_metodo->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tabla_metodo->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tabla_metodo->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tabla_metodo->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tabla_metodo->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tabla_metodo->setObjectName(QString::fromUtf8("tabla_metodo"));
        tabla_metodo->setMinimumSize(QSize(0, 500));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(9);
        tabla_metodo->setFont(font1);

        verticalLayout->addWidget(tabla_metodo);


        retranslateUi(cursos);

        QMetaObject::connectSlotsByName(cursos);
    } // setupUi

    void retranslateUi(QWidget *cursos)
    {
        cursos->setWindowTitle(QApplication::translate("cursos", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("cursos", "M\303\251todos y Cursos", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla_metodo->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("cursos", " Programa A.", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla_metodo->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("cursos", "Metodo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla_metodo->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("cursos", "Descripcion", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tabla_metodo->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("cursos", "Idioma", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tabla_metodo->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("cursos", "Niveles", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tabla_metodo->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("cursos", "Evaluaciones", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tabla_metodo->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("cursos", "Calendario", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tabla_metodo->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("cursos", "Cuotas", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class cursos: public Ui_cursos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURSOS_H
