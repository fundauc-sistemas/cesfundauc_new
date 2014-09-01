/********************************************************************************
** Form generated from reading UI file 'salones.ui'
**
** Created: Mon 26. May 11:13:59 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALONES_H
#define UI_SALONES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_salon
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QTableWidget *tabla;
    QHBoxLayout *horizontalLayout;
    QPushButton *edificios;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *salon)
    {
        if (salon->objectName().isEmpty())
            salon->setObjectName(QString::fromUtf8("salon"));
        salon->resize(834, 328);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        salon->setFont(font);
        verticalLayout = new QVBoxLayout(salon);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(salon);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Gill Sans MT"));
        font1.setPointSize(22);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("font: 22pt \"Gill Sans MT\";\n"
"color: rgb(00,56,147);"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        tabla = new QTableWidget(salon);
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
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        tabla->setFont(font2);

        verticalLayout->addWidget(tabla);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        edificios = new QPushButton(salon);
        edificios->setObjectName(QString::fromUtf8("edificios"));
        QFont font3;
        font3.setPointSize(10);
        edificios->setFont(font3);

        horizontalLayout->addWidget(edificios);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(salon);

        QMetaObject::connectSlotsByName(salon);
    } // setupUi

    void retranslateUi(QWidget *salon)
    {
        salon->setWindowTitle(QApplication::translate("salon", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("salon", "Salones", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("salon", "Edif", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("salon", "Codigo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("salon", "Descripcion", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("salon", "Capacidad", 0, QApplication::UnicodeUTF8));
        edificios->setText(QApplication::translate("salon", "Edificios", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class salon: public Ui_salon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALONES_H
