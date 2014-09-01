/********************************************************************************
** Form generated from reading UI file 'edificios.ui'
**
** Created: Fri 30. May 09:27:19 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIFICIOS_H
#define UI_EDIFICIOS_H

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

class Ui_edificio
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tabla;
    QHBoxLayout *horizontalLayout;
    QPushButton *nuevo;
    QPushButton *quitar;
    QSpacerItem *horizontalSpacer;
    QPushButton *guardar;

    void setupUi(QWidget *edificio)
    {
        if (edificio->objectName().isEmpty())
            edificio->setObjectName(QString::fromUtf8("edificio"));
        edificio->resize(400, 300);
        verticalLayout = new QVBoxLayout(edificio);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(edificio);
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

        tabla = new QTableWidget(edificio);
        if (tabla->columnCount() < 2)
            tabla->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(9);
        tabla->setFont(font1);

        verticalLayout->addWidget(tabla);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        nuevo = new QPushButton(edificio);
        nuevo->setObjectName(QString::fromUtf8("nuevo"));
        nuevo->setFont(font1);

        horizontalLayout->addWidget(nuevo);

        quitar = new QPushButton(edificio);
        quitar->setObjectName(QString::fromUtf8("quitar"));
        quitar->setFont(font1);

        horizontalLayout->addWidget(quitar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        guardar = new QPushButton(edificio);
        guardar->setObjectName(QString::fromUtf8("guardar"));
        guardar->setFont(font1);

        horizontalLayout->addWidget(guardar);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(edificio);

        QMetaObject::connectSlotsByName(edificio);
    } // setupUi

    void retranslateUi(QWidget *edificio)
    {
        edificio->setWindowTitle(QApplication::translate("edificio", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("edificio", "Edificios", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("edificio", "Codigo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("edificio", "Descripcion", 0, QApplication::UnicodeUTF8));
        nuevo->setText(QApplication::translate("edificio", "Nuevo Edificio", 0, QApplication::UnicodeUTF8));
        quitar->setText(QApplication::translate("edificio", "Eliminar Edificio", 0, QApplication::UnicodeUTF8));
        guardar->setText(QApplication::translate("edificio", "Guardar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class edificio: public Ui_edificio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIFICIOS_H
