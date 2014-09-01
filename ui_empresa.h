/********************************************************************************
** Form generated from reading UI file 'empresa.ui'
**
** Created: Fri 30. May 09:27:22 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPRESA_H
#define UI_EMPRESA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_empresas
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QTableWidget *tabla;

    void setupUi(QWidget *empresas)
    {
        if (empresas->objectName().isEmpty())
            empresas->setObjectName(QString::fromUtf8("empresas"));
        empresas->resize(734, 471);
        verticalLayout = new QVBoxLayout(empresas);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(empresas);
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
        label_2 = new QLabel(empresas);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(30, 25));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(empresas);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 25));
        lineEdit->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(lineEdit);

        label_3 = new QLabel(empresas);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(label_3);

        lineEdit_2 = new QLineEdit(empresas);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout);

        tabla = new QTableWidget(empresas);
        if (tabla->columnCount() < 4)
            tabla->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tabla->setObjectName(QString::fromUtf8("tabla"));

        verticalLayout->addWidget(tabla);


        retranslateUi(empresas);

        QMetaObject::connectSlotsByName(empresas);
    } // setupUi

    void retranslateUi(QWidget *empresas)
    {
        empresas->setWindowTitle(QApplication::translate("empresas", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("empresas", "Empresas", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("empresas", "RIF", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("empresas", "Raz\303\263n Social", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("empresas", "RIF", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("empresas", "Raz\303\263n Social", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("empresas", "Direcci\303\263n", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("empresas", "Tel\303\251fono", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class empresas: public Ui_empresas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPRESA_H
