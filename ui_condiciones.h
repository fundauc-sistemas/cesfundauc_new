/********************************************************************************
** Form generated from reading UI file 'condiciones.ui'
**
** Created: Fri 30. May 09:27:20 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONDICIONES_H
#define UI_CONDICIONES_H

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

class Ui_condiciones
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tabla;

    void setupUi(QWidget *condiciones)
    {
        if (condiciones->objectName().isEmpty())
            condiciones->setObjectName(QString::fromUtf8("condiciones"));
        condiciones->resize(634, 379);
        condiciones->setMaximumSize(QSize(635, 380));
        verticalLayout = new QVBoxLayout(condiciones);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(condiciones);
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

        tabla = new QTableWidget(condiciones);
        if (tabla->columnCount() < 3)
            tabla->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(9);
        tabla->setFont(font1);

        verticalLayout->addWidget(tabla);


        retranslateUi(condiciones);

        QMetaObject::connectSlotsByName(condiciones);
    } // setupUi

    void retranslateUi(QWidget *condiciones)
    {
        condiciones->setWindowTitle(QApplication::translate("condiciones", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("condiciones", "Condiciones Especiales", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("condiciones", "Id", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("condiciones", "Descripci\303\263n", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("condiciones", "Descuento", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class condiciones: public Ui_condiciones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONDICIONES_H
