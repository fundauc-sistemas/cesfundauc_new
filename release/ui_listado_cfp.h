/********************************************************************************
** Form generated from reading UI file 'listado_cfp.ui'
**
** Created: Mon 26. May 11:13:59 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTADO_CFP_H
#define UI_LISTADO_CFP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_listado_cfp
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *cursolabel;
    QComboBox *metodo;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QComboBox *modulo;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *modalidad;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *salida;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QDateEdit *fecini;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QDateEdit *fecfin;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *boton_generar;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *listado_cfp)
    {
        if (listado_cfp->objectName().isEmpty())
            listado_cfp->setObjectName(QString::fromUtf8("listado_cfp"));
        listado_cfp->resize(500, 357);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        listado_cfp->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(listado_cfp);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(listado_cfp);
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

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cursolabel = new QLabel(listado_cfp);
        cursolabel->setObjectName(QString::fromUtf8("cursolabel"));
        cursolabel->setMinimumSize(QSize(74, 0));
        cursolabel->setMaximumSize(QSize(74, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        cursolabel->setFont(font1);
        cursolabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(cursolabel);

        metodo = new QComboBox(listado_cfp);
        metodo->setObjectName(QString::fromUtf8("metodo"));
        metodo->setMinimumSize(QSize(300, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        metodo->setFont(font2);

        horizontalLayout_2->addWidget(metodo);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(listado_cfp);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(74, 0));
        label_3->setMaximumSize(QSize(74, 16777215));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_3);

        modulo = new QComboBox(listado_cfp);
        modulo->setObjectName(QString::fromUtf8("modulo"));
        modulo->setEnabled(false);
        modulo->setMinimumSize(QSize(300, 25));
        modulo->setFont(font2);

        horizontalLayout_7->addWidget(modulo);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(listado_cfp);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(74, 0));
        label_2->setMaximumSize(QSize(74, 16777215));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        modalidad = new QComboBox(listado_cfp);
        modalidad->setObjectName(QString::fromUtf8("modalidad"));
        modalidad->setEnabled(false);
        modalidad->setMinimumSize(QSize(0, 25));
        modalidad->setFont(font2);

        horizontalLayout->addWidget(modalidad);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(listado_cfp);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(74, 0));
        label_4->setMaximumSize(QSize(74, 16777215));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_4);

        salida = new QComboBox(listado_cfp);
        salida->setObjectName(QString::fromUtf8("salida"));
        salida->setMinimumSize(QSize(0, 25));
        salida->setFont(font2);

        horizontalLayout_3->addWidget(salida);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(listado_cfp);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(74, 25));
        label_5->setMaximumSize(QSize(74, 16777215));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_5);

        fecini = new QDateEdit(listado_cfp);
        fecini->setObjectName(QString::fromUtf8("fecini"));
        fecini->setMinimumSize(QSize(0, 25));
        fecini->setFont(font2);

        horizontalLayout_5->addWidget(fecini);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(listado_cfp);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(74, 25));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_6);

        fecfin = new QDateEdit(listado_cfp);
        fecfin->setObjectName(QString::fromUtf8("fecfin"));
        fecfin->setMinimumSize(QSize(0, 25));
        fecfin->setFont(font2);

        horizontalLayout_6->addWidget(fecfin);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        boton_generar = new QPushButton(listado_cfp);
        boton_generar->setObjectName(QString::fromUtf8("boton_generar"));
        boton_generar->setEnabled(false);
        boton_generar->setFont(font2);

        horizontalLayout_4->addWidget(boton_generar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(listado_cfp);

        QMetaObject::connectSlotsByName(listado_cfp);
    } // setupUi

    void retranslateUi(QWidget *listado_cfp)
    {
        listado_cfp->setWindowTitle(QApplication::translate("listado_cfp", "CONTROL DE ESTUDIOS", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("listado_cfp", "Listado", 0, QApplication::UnicodeUTF8));
        cursolabel->setText(QApplication::translate("listado_cfp", "Diplomado", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("listado_cfp", "M\303\263dulo", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("listado_cfp", "Cohorte", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("listado_cfp", "Salida", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("listado_cfp", "Fecha Inicio", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("listado_cfp", "Fecha Fin", 0, QApplication::UnicodeUTF8));
        boton_generar->setText(QApplication::translate("listado_cfp", "Aceptar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class listado_cfp: public Ui_listado_cfp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTADO_CFP_H
