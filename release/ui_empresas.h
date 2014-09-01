/********************************************************************************
** Form generated from reading UI file 'empresas.ui'
**
** Created: Mon 26. May 11:14:00 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPRESAS_H
#define UI_EMPRESAS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_empresa
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLineEdit *matricula;
    QLabel *label_2;
    QLineEdit *rif;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *razon;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *dir;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *telefono;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *aceptar;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *empresa)
    {
        if (empresa->objectName().isEmpty())
            empresa->setObjectName(QString::fromUtf8("empresa"));
        empresa->resize(543, 304);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        empresa->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        empresa->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(empresa);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(empresa);
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

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(empresa);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(75, 0));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_6);

        matricula = new QLineEdit(empresa);
        matricula->setObjectName(QString::fromUtf8("matricula"));
        matricula->setMinimumSize(QSize(0, 25));
        matricula->setMaximumSize(QSize(150, 16777215));
        QFont font2;
        font2.setPointSize(9);
        matricula->setFont(font2);

        horizontalLayout_2->addWidget(matricula);

        label_2 = new QLabel(empresa);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(40, 0));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        rif = new QLineEdit(empresa);
        rif->setObjectName(QString::fromUtf8("rif"));
        rif->setMinimumSize(QSize(0, 25));
        rif->setMaximumSize(QSize(200, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(9);
        rif->setFont(font3);

        horizontalLayout_2->addWidget(rif);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(empresa);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(75, 0));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_3);

        razon = new QLineEdit(empresa);
        razon->setObjectName(QString::fromUtf8("razon"));
        razon->setMinimumSize(QSize(0, 25));
        razon->setFont(font3);

        horizontalLayout_5->addWidget(razon);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(empresa);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(75, 0));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_4);

        dir = new QLineEdit(empresa);
        dir->setObjectName(QString::fromUtf8("dir"));
        dir->setFont(font2);

        horizontalLayout->addWidget(dir);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(empresa);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(75, 0));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_5);

        telefono = new QLineEdit(empresa);
        telefono->setObjectName(QString::fromUtf8("telefono"));
        telefono->setMaximumSize(QSize(150, 16777215));
        telefono->setFont(font2);

        horizontalLayout_3->addWidget(telefono);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        aceptar = new QPushButton(empresa);
        aceptar->setObjectName(QString::fromUtf8("aceptar"));
        aceptar->setFont(font2);

        horizontalLayout_4->addWidget(aceptar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(empresa);

        QMetaObject::connectSlotsByName(empresa);
    } // setupUi

    void retranslateUi(QWidget *empresa)
    {
        empresa->setWindowTitle(QApplication::translate("empresa", "CONTROL DE ESTUDIOS", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("empresa", "Empresa", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("empresa", "Matricula", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("empresa", "RIF", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("empresa", "Razon Social", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("empresa", "Direcci\303\263n", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("empresa", "Tel\303\251fono", 0, QApplication::UnicodeUTF8));
        aceptar->setText(QApplication::translate("empresa", "Guardar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class empresa: public Ui_empresa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPRESAS_H
