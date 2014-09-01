/********************************************************************************
** Form generated from reading UI file 'control_evaluacion_cfp.ui'
**
** Created: Mon 26. May 11:14:00 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_EVALUACION_CFP_H
#define UI_CONTROL_EVALUACION_CFP_H

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

class Ui_evaluacion_cfp
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titulo;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *diplomado;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *modalidad;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *modulo;
    QSpacerItem *horizontalSpacer_3;
    QTableWidget *tabla;

    void setupUi(QWidget *evaluacion_cfp)
    {
        if (evaluacion_cfp->objectName().isEmpty())
            evaluacion_cfp->setObjectName(QString::fromUtf8("evaluacion_cfp"));
        evaluacion_cfp->resize(752, 700);
        evaluacion_cfp->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(evaluacion_cfp);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titulo = new QLabel(evaluacion_cfp);
        titulo->setObjectName(QString::fromUtf8("titulo"));
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans MT"));
        font.setPointSize(22);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        titulo->setFont(font);
        titulo->setStyleSheet(QString::fromUtf8("font: 22pt \"Gill Sans MT\";\n"
"color: rgb(00,56,147);"));
        titulo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(titulo);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        label = new QLabel(evaluacion_cfp);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 25));
        label->setMaximumSize(QSize(100, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        diplomado = new QComboBox(evaluacion_cfp);
        diplomado->setObjectName(QString::fromUtf8("diplomado"));
        diplomado->setMinimumSize(QSize(600, 25));
        diplomado->setMaximumSize(QSize(600, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        diplomado->setFont(font2);

        horizontalLayout->addWidget(diplomado);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        label_4 = new QLabel(evaluacion_cfp);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(100, 0));
        label_4->setMaximumSize(QSize(100, 16777215));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_4);

        modalidad = new QComboBox(evaluacion_cfp);
        modalidad->setObjectName(QString::fromUtf8("modalidad"));
        modalidad->setEnabled(false);
        modalidad->setMinimumSize(QSize(600, 25));
        modalidad->setMaximumSize(QSize(600, 16777215));
        modalidad->setFont(font2);

        horizontalLayout_3->addWidget(modalidad);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        label_2 = new QLabel(evaluacion_cfp);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(100, 25));
        label_2->setMaximumSize(QSize(100, 16777215));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        modulo = new QComboBox(evaluacion_cfp);
        modulo->setObjectName(QString::fromUtf8("modulo"));
        modulo->setEnabled(false);
        modulo->setMinimumSize(QSize(600, 25));
        modulo->setMaximumSize(QSize(600, 16777215));
        modulo->setFont(font2);

        horizontalLayout_2->addWidget(modulo);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        tabla = new QTableWidget(evaluacion_cfp);
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
        tabla->setMaximumSize(QSize(730, 16777215));
        tabla->setFont(font2);

        verticalLayout->addWidget(tabla);


        retranslateUi(evaluacion_cfp);

        QMetaObject::connectSlotsByName(evaluacion_cfp);
    } // setupUi

    void retranslateUi(QWidget *evaluacion_cfp)
    {
        evaluacion_cfp->setWindowTitle(QApplication::translate("evaluacion_cfp", "Form", 0, QApplication::UnicodeUTF8));
        titulo->setText(QApplication::translate("evaluacion_cfp", "Control de Evaluaci\303\263n - CFP", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("evaluacion_cfp", "Diplomado", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("evaluacion_cfp", "Modalidad", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("evaluacion_cfp", "M\303\263dulo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("evaluacion_cfp", "Matr\303\255cula", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("evaluacion_cfp", "Nombre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("evaluacion_cfp", "Apellido", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("evaluacion_cfp", "Nota Definitiva", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class evaluacion_cfp: public Ui_evaluacion_cfp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_EVALUACION_CFP_H
