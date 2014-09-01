/********************************************************************************
** Form generated from reading UI file 'modalidades.ui'
**
** Created: Fri 30. May 09:27:18 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODALIDADES_H
#define UI_MODALIDADES_H

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

class Ui_modalidad
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tabla;

    void setupUi(QWidget *modalidad)
    {
        if (modalidad->objectName().isEmpty())
            modalidad->setObjectName(QString::fromUtf8("modalidad"));
        modalidad->resize(600, 397);
        modalidad->setMinimumSize(QSize(600, 0));
        modalidad->setMaximumSize(QSize(600, 16777215));
        verticalLayout = new QVBoxLayout(modalidad);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(modalidad);
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

        tabla = new QTableWidget(modalidad);
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


        retranslateUi(modalidad);

        QMetaObject::connectSlotsByName(modalidad);
    } // setupUi

    void retranslateUi(QWidget *modalidad)
    {
        modalidad->setWindowTitle(QApplication::translate("modalidad", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("modalidad", "Modalidades", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("modalidad", "Codigo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("modalidad", "Modalidad", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class modalidad: public Ui_modalidad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODALIDADES_H
