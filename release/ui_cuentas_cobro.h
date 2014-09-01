/********************************************************************************
** Form generated from reading UI file 'cuentas_cobro.ui'
**
** Created: Mon 26. May 11:14:00 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUENTAS_COBRO_H
#define UI_CUENTAS_COBRO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cuentas
{
public:
    QLabel *label;
    QTableWidget *tabla;
    QGroupBox *datos;
    QWidget *layoutWidget_5;
    QGridLayout *f_grid_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_49;
    QLabel *label_50;
    QLabel *label_51;
    QDateEdit *fechas;
    QComboBox *detallespago;
    QComboBox *detallesbanco;
    QLineEdit *referencias;
    QLineEdit *montos;
    QTableWidget *tabla2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *rif;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *cuentas)
    {
        if (cuentas->objectName().isEmpty())
            cuentas->setObjectName(QString::fromUtf8("cuentas"));
        cuentas->resize(918, 600);
        cuentas->setMaximumSize(QSize(16777215, 600));
        label = new QLabel(cuentas);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 891, 38));
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
        tabla = new QTableWidget(cuentas);
        if (tabla->columnCount() < 7)
            tabla->setColumnCount(7);
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
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        tabla->setGeometry(QRect(10, 110, 900, 191));
        tabla->setMinimumSize(QSize(900, 100));
        tabla->setMaximumSize(QSize(16777215, 300));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(9);
        tabla->setFont(font1);
        datos = new QGroupBox(cuentas);
        datos->setObjectName(QString::fromUtf8("datos"));
        datos->setGeometry(QRect(10, 330, 900, 100));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(datos->sizePolicy().hasHeightForWidth());
        datos->setSizePolicy(sizePolicy);
        datos->setMinimumSize(QSize(780, 100));
        datos->setMaximumSize(QSize(1000, 100));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(10);
        datos->setFont(font2);
        layoutWidget_5 = new QWidget(datos);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 20, 881, 71));
        f_grid_2 = new QGridLayout(layoutWidget_5);
        f_grid_2->setObjectName(QString::fromUtf8("f_grid_2"));
        f_grid_2->setSizeConstraint(QLayout::SetNoConstraint);
        f_grid_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(16777215, 30));
        label_7->setAlignment(Qt::AlignCenter);

        f_grid_2->addWidget(label_7, 0, 1, 1, 1);

        label_8 = new QLabel(layoutWidget_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(16777215, 30));
        label_8->setAlignment(Qt::AlignCenter);

        f_grid_2->addWidget(label_8, 0, 2, 1, 1);

        label_49 = new QLabel(layoutWidget_5);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setMaximumSize(QSize(16777215, 30));
        label_49->setAlignment(Qt::AlignCenter);

        f_grid_2->addWidget(label_49, 0, 3, 1, 1);

        label_50 = new QLabel(layoutWidget_5);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setMaximumSize(QSize(16777215, 30));
        label_50->setAlignment(Qt::AlignCenter);

        f_grid_2->addWidget(label_50, 0, 4, 1, 1);

        label_51 = new QLabel(layoutWidget_5);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setMinimumSize(QSize(0, 30));
        label_51->setMaximumSize(QSize(16777215, 30));
        label_51->setAlignment(Qt::AlignCenter);

        f_grid_2->addWidget(label_51, 0, 0, 1, 1);

        fechas = new QDateEdit(layoutWidget_5);
        fechas->setObjectName(QString::fromUtf8("fechas"));

        f_grid_2->addWidget(fechas, 1, 0, 1, 1);

        detallespago = new QComboBox(layoutWidget_5);
        detallespago->setObjectName(QString::fromUtf8("detallespago"));
        detallespago->setMinimumSize(QSize(200, 25));
        detallespago->setMaximumSize(QSize(120, 16777215));
        QFont font3;
        font3.setPointSize(9);
        detallespago->setFont(font3);

        f_grid_2->addWidget(detallespago, 1, 1, 1, 1);

        detallesbanco = new QComboBox(layoutWidget_5);
        detallesbanco->setObjectName(QString::fromUtf8("detallesbanco"));
        detallesbanco->setMinimumSize(QSize(300, 25));
        detallesbanco->setMaximumSize(QSize(240, 16777215));
        detallesbanco->setFont(font3);

        f_grid_2->addWidget(detallesbanco, 1, 2, 1, 1);

        referencias = new QLineEdit(layoutWidget_5);
        referencias->setObjectName(QString::fromUtf8("referencias"));
        referencias->setMinimumSize(QSize(150, 25));
        referencias->setMaximumSize(QSize(150, 16777215));
        referencias->setFont(font3);

        f_grid_2->addWidget(referencias, 1, 3, 1, 1);

        montos = new QLineEdit(layoutWidget_5);
        montos->setObjectName(QString::fromUtf8("montos"));
        montos->setMinimumSize(QSize(100, 25));
        montos->setMaximumSize(QSize(100, 16777215));
        montos->setFont(font3);

        f_grid_2->addWidget(montos, 1, 4, 1, 1);

        tabla2 = new QTableWidget(cuentas);
        if (tabla2->columnCount() < 5)
            tabla2->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tabla2->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tabla2->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tabla2->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tabla2->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tabla2->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        tabla2->setObjectName(QString::fromUtf8("tabla2"));
        tabla2->setEnabled(true);
        tabla2->setGeometry(QRect(9, 440, 900, 131));
        sizePolicy.setHeightForWidth(tabla2->sizePolicy().hasHeightForWidth());
        tabla2->setSizePolicy(sizePolicy);
        tabla2->setMinimumSize(QSize(780, 100));
        tabla2->setMaximumSize(QSize(1000, 200));
        tabla2->setFont(font1);
        layoutWidget = new QWidget(cuentas);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 70, 901, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(55, 25));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        rif = new QLineEdit(layoutWidget);
        rif->setObjectName(QString::fromUtf8("rif"));
        rif->setMinimumSize(QSize(0, 25));
        rif->setMaximumSize(QSize(200, 16777215));
        rif->setFont(font1);

        horizontalLayout->addWidget(rif);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(cuentas);

        QMetaObject::connectSlotsByName(cuentas);
    } // setupUi

    void retranslateUi(QWidget *cuentas)
    {
        cuentas->setWindowTitle(QApplication::translate("cuentas", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("cuentas", "Cuentas por Cobrar", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("cuentas", "Factura", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("cuentas", "Cliente", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("cuentas", "Fecha de emision", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("cuentas", "Saldo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("cuentas", "Ultimo pago", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tabla->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("cuentas", "Monto", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tabla->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("cuentas", "Ultimo deposito", 0, QApplication::UnicodeUTF8));
        datos->setTitle(QApplication::translate("cuentas", "Dep\303\263sito", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("cuentas", "Forma de Pago", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("cuentas", "Banco", 0, QApplication::UnicodeUTF8));
        label_49->setText(QApplication::translate("cuentas", "Referencia", 0, QApplication::UnicodeUTF8));
        label_50->setText(QApplication::translate("cuentas", "Monto", 0, QApplication::UnicodeUTF8));
        label_51->setText(QApplication::translate("cuentas", "Emision", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tabla2->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("cuentas", "Emision", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tabla2->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("cuentas", "Forma de Pago", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tabla2->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("cuentas", "Banco", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tabla2->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("cuentas", "Referencia", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tabla2->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("cuentas", "Monto", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("cuentas", "RIF/CI", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class cuentas: public Ui_cuentas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUENTAS_COBRO_H
