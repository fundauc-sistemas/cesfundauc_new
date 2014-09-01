/********************************************************************************
** Form generated from reading UI file 'secciones.ui'
**
** Created: Mon 26. May 11:13:59 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECCIONES_H
#define UI_SECCIONES_H

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

class Ui_secciones
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *Curso;
    QComboBox *curso;
    QLabel *label_2;
    QComboBox *modalidad;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tabla;

    void setupUi(QWidget *secciones)
    {
        if (secciones->objectName().isEmpty())
            secciones->setObjectName(QString::fromUtf8("secciones"));
        secciones->resize(1028, 300);
        verticalLayout = new QVBoxLayout(secciones);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(secciones);
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
        Curso = new QLabel(secciones);
        Curso->setObjectName(QString::fromUtf8("Curso"));
        Curso->setMinimumSize(QSize(50, 0));
        Curso->setMaximumSize(QSize(50, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        Curso->setFont(font1);
        Curso->setTextFormat(Qt::AutoText);
        Curso->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(Curso);

        curso = new QComboBox(secciones);
        curso->setObjectName(QString::fromUtf8("curso"));
        curso->setMinimumSize(QSize(0, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        curso->setFont(font2);

        horizontalLayout->addWidget(curso);

        label_2 = new QLabel(secciones);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(10);
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        modalidad = new QComboBox(secciones);
        modalidad->setObjectName(QString::fromUtf8("modalidad"));
        modalidad->setMinimumSize(QSize(300, 25));
        modalidad->setFont(font2);

        horizontalLayout->addWidget(modalidad);

        horizontalSpacer = new QSpacerItem(78, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tabla = new QTableWidget(secciones);
        if (tabla->columnCount() < 12)
            tabla->setColumnCount(12);
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
        tabla->setObjectName(QString::fromUtf8("tabla"));
        tabla->setFont(font2);

        verticalLayout->addWidget(tabla);


        retranslateUi(secciones);

        QMetaObject::connectSlotsByName(secciones);
    } // setupUi

    void retranslateUi(QWidget *secciones)
    {
        secciones->setWindowTitle(QApplication::translate("secciones", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("secciones", "Secciones", 0, QApplication::UnicodeUTF8));
        Curso->setText(QApplication::translate("secciones", "Curso", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("secciones", "Modalidad", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("secciones", "Codigo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("secciones", "Nivel", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("secciones", "Salon", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("secciones", "Edificio", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("secciones", "Tope", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tabla->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("secciones", "Actual", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tabla->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("secciones", "Horario", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tabla->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("secciones", "Profesor", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tabla->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("secciones", "Modalidad", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tabla->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("secciones", "Fecha Inicio", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tabla->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("secciones", "Periodo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tabla->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("secciones", "Status", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class secciones: public Ui_secciones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECCIONES_H
