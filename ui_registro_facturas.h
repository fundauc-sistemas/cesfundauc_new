/********************************************************************************
** Form generated from reading UI file 'registro_facturas.ui'
**
** Created: Fri 30. May 09:27:17 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRO_FACTURAS_H
#define UI_REGISTRO_FACTURAS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDateEdit>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reg_factura
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QCheckBox *r_factura;
    QLineEdit *r_factura_edit;
    QFrame *line;
    QCheckBox *r_year;
    QDateEdit *r_top;
    QLabel *label_2;
    QDateEdit *r_bottom;
    QLabel *label_3;
    QFrame *line_2;
    QCheckBox *r_empresa;
    QLineEdit *r_rif;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *r_tabla;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *reg_factura)
    {
        if (reg_factura->objectName().isEmpty())
            reg_factura->setObjectName(QString::fromUtf8("reg_factura"));
        reg_factura->resize(798, 800);
        reg_factura->setMaximumSize(QSize(16777215, 800));
        verticalLayout = new QVBoxLayout(reg_factura);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(reg_factura);
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
        r_factura = new QCheckBox(reg_factura);
        r_factura->setObjectName(QString::fromUtf8("r_factura"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        r_factura->setFont(font1);

        horizontalLayout->addWidget(r_factura);

        r_factura_edit = new QLineEdit(reg_factura);
        r_factura_edit->setObjectName(QString::fromUtf8("r_factura_edit"));
        r_factura_edit->setEnabled(false);
        r_factura_edit->setMinimumSize(QSize(0, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        r_factura_edit->setFont(font2);

        horizontalLayout->addWidget(r_factura_edit);

        line = new QFrame(reg_factura);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        r_year = new QCheckBox(reg_factura);
        r_year->setObjectName(QString::fromUtf8("r_year"));
        r_year->setFont(font1);

        horizontalLayout->addWidget(r_year);

        r_top = new QDateEdit(reg_factura);
        r_top->setObjectName(QString::fromUtf8("r_top"));
        r_top->setEnabled(false);
        r_top->setMinimumSize(QSize(0, 25));
        r_top->setFont(font2);
        r_top->setCalendarPopup(true);

        horizontalLayout->addWidget(r_top);

        label_2 = new QLabel(reg_factura);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        r_bottom = new QDateEdit(reg_factura);
        r_bottom->setObjectName(QString::fromUtf8("r_bottom"));
        r_bottom->setEnabled(false);
        r_bottom->setMinimumSize(QSize(0, 25));
        r_bottom->setFont(font2);
        r_bottom->setCalendarPopup(true);

        horizontalLayout->addWidget(r_bottom);

        label_3 = new QLabel(reg_factura);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout->addWidget(label_3);

        line_2 = new QFrame(reg_factura);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        r_empresa = new QCheckBox(reg_factura);
        r_empresa->setObjectName(QString::fromUtf8("r_empresa"));
        r_empresa->setFont(font1);

        horizontalLayout->addWidget(r_empresa);

        r_rif = new QLineEdit(reg_factura);
        r_rif->setObjectName(QString::fromUtf8("r_rif"));
        r_rif->setEnabled(false);
        r_rif->setMinimumSize(QSize(0, 25));
        r_rif->setFont(font2);

        horizontalLayout->addWidget(r_rif);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        r_tabla = new QTableWidget(reg_factura);
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
        r_tabla->setMinimumSize(QSize(520, 450));
        r_tabla->setFont(font2);

        verticalLayout->addWidget(r_tabla);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(reg_factura);

        QMetaObject::connectSlotsByName(reg_factura);
    } // setupUi

    void retranslateUi(QWidget *reg_factura)
    {
        reg_factura->setWindowTitle(QApplication::translate("reg_factura", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("reg_factura", "Facturas", 0, QApplication::UnicodeUTF8));
        r_factura->setText(QApplication::translate("reg_factura", "N\302\272 Factura", 0, QApplication::UnicodeUTF8));
        r_year->setText(QApplication::translate("reg_factura", "Fecha", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("reg_factura", "Desde", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("reg_factura", "Hasta", 0, QApplication::UnicodeUTF8));
        r_empresa->setText(QApplication::translate("reg_factura", "Empresa (RIF)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = r_tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("reg_factura", "Factura", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = r_tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("reg_factura", "Fecha", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = r_tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("reg_factura", "Monto", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = r_tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("reg_factura", "Cliente", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = r_tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("reg_factura", "Status", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class reg_factura: public Ui_reg_factura {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRO_FACTURAS_H
