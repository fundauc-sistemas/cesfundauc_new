/********************************************************************************
** Form generated from reading UI file 'registro_deposito.ui'
**
** Created: Fri 30. May 09:27:18 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRO_DEPOSITO_H
#define UI_REGISTRO_DEPOSITO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDateEdit>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reg_deposito
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QCheckBox *r_referencia;
    QLineEdit *r_referencia_edit;
    QCheckBox *r_year;
    QDateEdit *r_top;
    QLabel *label_2;
    QDateEdit *r_bottom;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QTableWidget *r_tabla;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *reg_deposito)
    {
        if (reg_deposito->objectName().isEmpty())
            reg_deposito->setObjectName(QString::fromUtf8("reg_deposito"));
        reg_deposito->resize(749, 800);
        reg_deposito->setMaximumSize(QSize(16777215, 800));
        verticalLayout = new QVBoxLayout(reg_deposito);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(reg_deposito);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 25));
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
        r_referencia = new QCheckBox(reg_deposito);
        r_referencia->setObjectName(QString::fromUtf8("r_referencia"));
        r_referencia->setMinimumSize(QSize(0, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        r_referencia->setFont(font1);

        horizontalLayout->addWidget(r_referencia);

        r_referencia_edit = new QLineEdit(reg_deposito);
        r_referencia_edit->setObjectName(QString::fromUtf8("r_referencia_edit"));
        r_referencia_edit->setEnabled(false);
        r_referencia_edit->setMinimumSize(QSize(167, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        r_referencia_edit->setFont(font2);

        horizontalLayout->addWidget(r_referencia_edit);

        r_year = new QCheckBox(reg_deposito);
        r_year->setObjectName(QString::fromUtf8("r_year"));
        r_year->setMinimumSize(QSize(0, 25));
        r_year->setFont(font1);

        horizontalLayout->addWidget(r_year);

        r_top = new QDateEdit(reg_deposito);
        r_top->setObjectName(QString::fromUtf8("r_top"));
        r_top->setEnabled(false);
        r_top->setMinimumSize(QSize(0, 25));
        r_top->setFont(font2);
        r_top->setCalendarPopup(true);

        horizontalLayout->addWidget(r_top);

        label_2 = new QLabel(reg_deposito);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 25));
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        r_bottom = new QDateEdit(reg_deposito);
        r_bottom->setObjectName(QString::fromUtf8("r_bottom"));
        r_bottom->setEnabled(false);
        r_bottom->setMinimumSize(QSize(0, 25));
        r_bottom->setFont(font2);
        r_bottom->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        r_bottom->setCalendarPopup(true);

        horizontalLayout->addWidget(r_bottom);

        label_3 = new QLabel(reg_deposito);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 25));
        label_3->setFont(font1);

        horizontalLayout->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        r_tabla = new QTableWidget(reg_deposito);
        if (r_tabla->columnCount() < 5)
            r_tabla->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        r_tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        r_tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        r_tabla->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        r_tabla->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        r_tabla->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        r_tabla->setObjectName(QString::fromUtf8("r_tabla"));
        r_tabla->setMinimumSize(QSize(0, 480));
        r_tabla->setFont(font2);

        verticalLayout->addWidget(r_tabla);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(reg_deposito);

        QMetaObject::connectSlotsByName(reg_deposito);
    } // setupUi

    void retranslateUi(QWidget *reg_deposito)
    {
        reg_deposito->setWindowTitle(QApplication::translate("reg_deposito", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("reg_deposito", "Depositos", 0, QApplication::UnicodeUTF8));
        r_referencia->setText(QApplication::translate("reg_deposito", "Referencia", 0, QApplication::UnicodeUTF8));
        r_year->setText(QApplication::translate("reg_deposito", "Fecha", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("reg_deposito", "Desde", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("reg_deposito", "Hasta", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = r_tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("reg_deposito", "Referencia", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = r_tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("reg_deposito", "Fecha", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = r_tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("reg_deposito", "Banco", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = r_tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("reg_deposito", "Monto", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = r_tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("reg_deposito", "Factura", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class reg_deposito: public Ui_reg_deposito {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRO_DEPOSITO_H
