/********************************************************************************
** Form generated from reading UI file 'actividades_cfp.ui'
**
** Created: Fri 30. May 09:27:22 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVIDADES_CFP_H
#define UI_ACTIVIDADES_CFP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_act_cfp
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *diplomado;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *modulo;
    QLabel *label;
    QLineEdit *nombre;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *facilitador;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *duracion;
    QLabel *label_8;
    QComboBox *cohorte;
    QLabel *label_7;
    QLineEdit *clases;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QTableWidget *fechas;

    void setupUi(QWidget *act_cfp)
    {
        if (act_cfp->objectName().isEmpty())
            act_cfp->setObjectName(QString::fromUtf8("act_cfp"));
        act_cfp->resize(763, 219);
        act_cfp->setMaximumSize(QSize(11111, 16777215));
        layoutWidget = new QWidget(act_cfp);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 9, 721, 196));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(70, 0));
        label_4->setMaximumSize(QSize(70, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_4);

        diplomado = new QComboBox(layoutWidget);
        diplomado->setObjectName(QString::fromUtf8("diplomado"));
        diplomado->setMinimumSize(QSize(0, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(9);
        diplomado->setFont(font1);

        horizontalLayout_4->addWidget(diplomado);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(70, 0));
        label_5->setMaximumSize(QSize(70, 16777215));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_5);

        modulo = new QComboBox(layoutWidget);
        modulo->setObjectName(QString::fromUtf8("modulo"));
        modulo->setEnabled(false);
        modulo->setMinimumSize(QSize(0, 25));
        modulo->setMaximumSize(QSize(50, 16777215));
        modulo->setFont(font1);

        horizontalLayout_5->addWidget(modulo);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(70, 0));
        label->setMaximumSize(QSize(70, 16777215));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label);

        nombre = new QLineEdit(layoutWidget);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setEnabled(false);
        nombre->setMinimumSize(QSize(0, 25));
        nombre->setFont(font1);

        horizontalLayout_5->addWidget(nombre);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(70, 0));
        label_2->setMaximumSize(QSize(70, 16777215));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        facilitador = new QLineEdit(layoutWidget);
        facilitador->setObjectName(QString::fromUtf8("facilitador"));
        facilitador->setEnabled(false);
        facilitador->setMinimumSize(QSize(0, 25));
        facilitador->setFont(font1);

        horizontalLayout_2->addWidget(facilitador);


        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(100, 0));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        duracion = new QLineEdit(layoutWidget);
        duracion->setObjectName(QString::fromUtf8("duracion"));
        duracion->setEnabled(false);
        duracion->setMinimumSize(QSize(0, 25));
        duracion->setMaximumSize(QSize(60, 16777215));
        duracion->setFont(font1);

        horizontalLayout_3->addWidget(duracion);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(60, 0));
        label_8->setMaximumSize(QSize(60, 16777215));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_8);

        cohorte = new QComboBox(layoutWidget);
        cohorte->setObjectName(QString::fromUtf8("cohorte"));
        cohorte->setEnabled(false);
        cohorte->setMinimumSize(QSize(90, 25));
        cohorte->setFont(font1);

        horizontalLayout_3->addWidget(cohorte);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(60, 25));
        label_7->setMaximumSize(QSize(60, 16777215));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_7);

        clases = new QLineEdit(layoutWidget);
        clases->setObjectName(QString::fromUtf8("clases"));
        clases->setEnabled(false);
        clases->setMinimumSize(QSize(0, 25));
        clases->setMaximumSize(QSize(60, 16777215));
        clases->setFont(font1);

        horizontalLayout_3->addWidget(clases);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(70, 0));
        label_6->setMaximumSize(QSize(70, 16777215));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_6);

        fechas = new QTableWidget(layoutWidget);
        if (fechas->columnCount() < 1)
            fechas->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        fechas->setHorizontalHeaderItem(0, __qtablewidgetitem);
        fechas->setObjectName(QString::fromUtf8("fechas"));
        fechas->setMinimumSize(QSize(140, 0));
        fechas->setMaximumSize(QSize(120, 16777215));
        fechas->setFont(font1);

        horizontalLayout_6->addWidget(fechas);


        horizontalLayout->addLayout(horizontalLayout_6);


        retranslateUi(act_cfp);

        QMetaObject::connectSlotsByName(act_cfp);
    } // setupUi

    void retranslateUi(QWidget *act_cfp)
    {
        act_cfp->setWindowTitle(QApplication::translate("act_cfp", "Form", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("act_cfp", "Diplomado", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("act_cfp", "M\303\263dulo", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("act_cfp", "Nombre", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("act_cfp", "Facilitador", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("act_cfp", "Duraci\303\263n (Horas)", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("act_cfp", "Cohorte", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("act_cfp", "N\302\272 Clases", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("act_cfp", "Fechas", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = fechas->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("act_cfp", "Fecha Clase", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class act_cfp: public Ui_act_cfp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVIDADES_CFP_H
