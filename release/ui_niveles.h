/********************************************************************************
** Form generated from reading UI file 'niveles.ui'
**
** Created: Mon 26. May 11:13:59 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NIVELES_H
#define UI_NIVELES_H

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

class Ui_niveles
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *metodo;
    QTableWidget *tabla;

    void setupUi(QWidget *niveles)
    {
        if (niveles->objectName().isEmpty())
            niveles->setObjectName(QString::fromUtf8("niveles"));
        niveles->resize(590, 400);
        niveles->setMaximumSize(QSize(590, 400));
        verticalLayout = new QVBoxLayout(niveles);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(niveles);
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

        metodo = new QComboBox(niveles);
        metodo->setObjectName(QString::fromUtf8("metodo"));
        metodo->setMinimumSize(QSize(0, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        metodo->setFont(font1);

        verticalLayout->addWidget(metodo);

        tabla = new QTableWidget(niveles);
        if (tabla->columnCount() < 3)
            tabla->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        tabla->setFont(font2);

        verticalLayout->addWidget(tabla);


        retranslateUi(niveles);

        QMetaObject::connectSlotsByName(niveles);
    } // setupUi

    void retranslateUi(QWidget *niveles)
    {
        niveles->setWindowTitle(QApplication::translate("niveles", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("niveles", "Niveles", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("niveles", "Nivel", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("niveles", "Horas", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("niveles", "Nota Minima", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class niveles: public Ui_niveles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVELES_H
