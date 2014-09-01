/********************************************************************************
** Form generated from reading UI file 'horario_cfp.ui'
**
** Created: Mon 26. May 11:13:59 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HORARIO_CFP_H
#define UI_HORARIO_CFP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cohortes
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QComboBox *diplomado;
    QLabel *label_2;
    QLabel *codigo;
    QTableWidget *tabla;

    void setupUi(QWidget *cohortes)
    {
        if (cohortes->objectName().isEmpty())
            cohortes->setObjectName(QString::fromUtf8("cohortes"));
        cohortes->resize(1065, 291);
        verticalLayout = new QVBoxLayout(cohortes);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(cohortes);
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
        diplomado = new QComboBox(cohortes);
        diplomado->setObjectName(QString::fromUtf8("diplomado"));
        diplomado->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(diplomado);

        label_2 = new QLabel(cohortes);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(130, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        codigo = new QLabel(cohortes);
        codigo->setObjectName(QString::fromUtf8("codigo"));
        codigo->setMaximumSize(QSize(100, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(11);
        codigo->setFont(font2);

        horizontalLayout->addWidget(codigo);


        verticalLayout->addLayout(horizontalLayout);

        tabla = new QTableWidget(cohortes);
        if (tabla->columnCount() < 13)
            tabla->setColumnCount(13);
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
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(9);
        tabla->setFont(font3);

        verticalLayout->addWidget(tabla);


        retranslateUi(cohortes);

        QMetaObject::connectSlotsByName(cohortes);
    } // setupUi

    void retranslateUi(QWidget *cohortes)
    {
        cohortes->setWindowTitle(QApplication::translate("cohortes", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("cohortes", "Cohortes", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("cohortes", "C\303\263digo Diplomado:", 0, QApplication::UnicodeUTF8));
        codigo->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("cohortes", "Codigo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("cohortes", "Modalidad", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("cohortes", "Horario", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("cohortes", "Cohorte", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("cohortes", "Ciudad", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tabla->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("cohortes", "Actual", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tabla->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("cohortes", "Costo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tabla->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("cohortes", "Inicial", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tabla->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("cohortes", "Cuotas", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tabla->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("cohortes", "Costo Cuota", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tabla->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("cohortes", "Fecha Inicio", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tabla->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("cohortes", "Fecha Fin", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tabla->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("cohortes", "Status", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class cohortes: public Ui_cohortes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HORARIO_CFP_H
