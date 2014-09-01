/********************************************************************************
** Form generated from reading UI file 'codigos.ui'
**
** Created: Mon 26. May 11:14:00 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODIGOS_H
#define UI_CODIGOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_codigos
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QComboBox *programa;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QTableWidget *tabla;

    void setupUi(QWidget *codigos)
    {
        if (codigos->objectName().isEmpty())
            codigos->setObjectName(QString::fromUtf8("codigos"));
        codigos->resize(771, 700);
        verticalLayout = new QVBoxLayout(codigos);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(codigos);
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
        programa = new QComboBox(codigos);
        programa->setObjectName(QString::fromUtf8("programa"));
        programa->setMinimumSize(QSize(0, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(9);
        programa->setFont(font1);

        horizontalLayout->addWidget(programa);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        tabla = new QTableWidget(codigos);
        if (tabla->columnCount() < 3)
            tabla->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        tabla->setFont(font1);

        verticalLayout->addWidget(tabla);


        retranslateUi(codigos);

        QMetaObject::connectSlotsByName(codigos);
    } // setupUi

    void retranslateUi(QWidget *codigos)
    {
        codigos->setWindowTitle(QApplication::translate("codigos", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("codigos", "Codigos Contables", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("codigos", "Codigo Contable", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("codigos", "Concepto", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("codigos", "Tipo Material", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class codigos: public Ui_codigos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODIGOS_H
