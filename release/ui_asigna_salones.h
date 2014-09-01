/********************************************************************************
** Form generated from reading UI file 'asigna_salones.ui'
**
** Created: Mon 26. May 11:14:01 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASIGNA_SALONES_H
#define UI_ASIGNA_SALONES_H

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

class Ui_asigna_salon
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *edificio;
    QLabel *label;
    QComboBox *salon;
    QSpacerItem *verticalSpacer;
    QTableWidget *tabla;

    void setupUi(QWidget *asigna_salon)
    {
        if (asigna_salon->objectName().isEmpty())
            asigna_salon->setObjectName(QString::fromUtf8("asigna_salon"));
        asigna_salon->resize(839, 637);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        asigna_salon->setFont(font);
        verticalLayout = new QVBoxLayout(asigna_salon);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(asigna_salon);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Gill Sans MT"));
        font1.setPointSize(22);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("font: 22pt \"Gill Sans MT\";\n"
"color: rgb(00,56,147);"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(asigna_salon);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(70, 0));
        label_2->setMaximumSize(QSize(70, 16777215));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        label_2->setFont(font2);

        horizontalLayout->addWidget(label_2);

        edificio = new QComboBox(asigna_salon);
        edificio->setObjectName(QString::fromUtf8("edificio"));
        edificio->setMinimumSize(QSize(0, 25));
        QFont font3;
        font3.setPointSize(9);
        edificio->setFont(font3);

        horizontalLayout->addWidget(edificio);

        label = new QLabel(asigna_salon);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(70, 0));
        label->setMaximumSize(QSize(70, 16777215));
        QFont font4;
        font4.setPointSize(10);
        label->setFont(font4);

        horizontalLayout->addWidget(label);

        salon = new QComboBox(asigna_salon);
        salon->setObjectName(QString::fromUtf8("salon"));
        salon->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(salon);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        tabla = new QTableWidget(asigna_salon);
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
        tabla->setFont(font);

        verticalLayout->addWidget(tabla);


        retranslateUi(asigna_salon);

        QMetaObject::connectSlotsByName(asigna_salon);
    } // setupUi

    void retranslateUi(QWidget *asigna_salon)
    {
        asigna_salon->setWindowTitle(QApplication::translate("asigna_salon", "Form", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("asigna_salon", "Asignaci\303\263n de Salones", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("asigna_salon", "Edificio", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("asigna_salon", "Sal\303\263n", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("asigna_salon", "Lunes", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("asigna_salon", "Martes", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("asigna_salon", "Miercoles", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("asigna_salon", "Jueves", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("asigna_salon", "Viernes", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tabla->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("asigna_salon", "Sabado", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class asigna_salon: public Ui_asigna_salon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASIGNA_SALONES_H
