/********************************************************************************
** Form generated from reading UI file 'historico.ui'
**
** Created: Fri 30. May 09:27:19 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORICO_H
#define UI_HISTORICO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
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

class Ui_historico
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *prog;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDateEdit *fecha;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QLineEdit *promo;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QTableWidget *tabla;

    void setupUi(QWidget *historico)
    {
        if (historico->objectName().isEmpty())
            historico->setObjectName(QString::fromUtf8("historico"));
        historico->resize(843, 480);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        historico->setFont(font);
        verticalLayout = new QVBoxLayout(historico);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(historico);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Gill Sans MT"));
        font1.setPointSize(22);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("font: 22pt \"Gill Sans MT\";\n"
"color: rgb(00,56,147);"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(historico);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 25));
        label->setMaximumSize(QSize(130, 25));

        horizontalLayout->addWidget(label);

        prog = new QComboBox(historico);
        prog->setObjectName(QString::fromUtf8("prog"));
        prog->setMinimumSize(QSize(0, 25));
        prog->setMaximumSize(QSize(255, 16777215));

        horizontalLayout->addWidget(prog);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(historico);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(90, 0));

        horizontalLayout_2->addWidget(label_3);

        fecha = new QDateEdit(historico);
        fecha->setObjectName(QString::fromUtf8("fecha"));
        fecha->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(fecha);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_4 = new QLabel(historico);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(110, 0));

        horizontalLayout_2->addWidget(label_4);

        promo = new QLineEdit(historico);
        promo->setObjectName(QString::fromUtf8("promo"));
        promo->setMinimumSize(QSize(0, 25));
        promo->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(promo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        tabla = new QTableWidget(historico);
        if (tabla->columnCount() < 2)
            tabla->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        tabla->setFont(font2);

        verticalLayout->addWidget(tabla);


        retranslateUi(historico);

        QMetaObject::connectSlotsByName(historico);
    } // setupUi

    void retranslateUi(QWidget *historico)
    {
        historico->setWindowTitle(QApplication::translate("historico", "Form", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("historico", "Egresados a Hist\303\263rico", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("historico", "Programa Academico", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("historico", "Fecha del Acto", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("historico", "N\302\272 de Promoci\303\263n", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("historico", "Diplomado", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class historico: public Ui_historico {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORICO_H
