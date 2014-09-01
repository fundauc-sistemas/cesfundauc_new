/********************************************************************************
** Form generated from reading UI file 'materiales.ui'
**
** Created: Mon 26. May 11:13:59 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALES_H
#define UI_MATERIALES_H

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

class Ui_materiales
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QTableWidget *tabla;

    void setupUi(QWidget *materiales)
    {
        if (materiales->objectName().isEmpty())
            materiales->setObjectName(QString::fromUtf8("materiales"));
        materiales->resize(683, 417);
        verticalLayout = new QVBoxLayout(materiales);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(materiales);
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

        tabla = new QTableWidget(materiales);
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
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(9);
        tabla->setFont(font1);

        verticalLayout->addWidget(tabla);


        retranslateUi(materiales);

        QMetaObject::connectSlotsByName(materiales);
    } // setupUi

    void retranslateUi(QWidget *materiales)
    {
        materiales->setWindowTitle(QApplication::translate("materiales", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("materiales", "Materiales", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("materiales", "Id", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("materiales", "Tipo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("materiales", "Descripcion", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("materiales", "Curso", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("materiales", "Evento", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tabla->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("materiales", "Nivel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class materiales: public Ui_materiales {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALES_H
