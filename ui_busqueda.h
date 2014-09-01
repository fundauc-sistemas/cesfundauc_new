/********************************************************************************
** Form generated from reading UI file 'busqueda.ui'
**
** Created: Fri 30. May 09:27:21 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUSQUEDA_H
#define UI_BUSQUEDA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_busqueda
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tabla;

    void setupUi(QWidget *busqueda)
    {
        if (busqueda->objectName().isEmpty())
            busqueda->setObjectName(QString::fromUtf8("busqueda"));
        busqueda->resize(753, 300);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(9);
        busqueda->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        busqueda->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(busqueda);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabla = new QTableWidget(busqueda);
        if (tabla->columnCount() < 2)
            tabla->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        tabla->setFont(font);

        verticalLayout->addWidget(tabla);


        retranslateUi(busqueda);

        QMetaObject::connectSlotsByName(busqueda);
    } // setupUi

    void retranslateUi(QWidget *busqueda)
    {
        busqueda->setWindowTitle(QApplication::translate("busqueda", "RESULTADOS", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("busqueda", "Matricula", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("busqueda", "Nombre", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class busqueda: public Ui_busqueda {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUSQUEDA_H
