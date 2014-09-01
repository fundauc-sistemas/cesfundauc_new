/********************************************************************************
** Form generated from reading UI file 'ced_ingreso_dialog.ui'
**
** Created: Fri 30. May 09:27:21 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CED_INGRESO_DIALOG_H
#define UI_CED_INGRESO_DIALOG_H

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

class Ui_ced_ingreso
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titulo;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *programa;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *metodo;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QDateEdit *inicio;
    QLabel *label_4;
    QDateEdit *fin;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *salida;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *aceptar;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ced_ingreso)
    {
        if (ced_ingreso->objectName().isEmpty())
            ced_ingreso->setObjectName(QString::fromUtf8("ced_ingreso"));
        ced_ingreso->resize(434, 278);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        ced_ingreso->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(ced_ingreso);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titulo = new QLabel(ced_ingreso);
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
        label = new QLabel(ced_ingreso);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(124, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        programa = new QComboBox(ced_ingreso);
        programa->setObjectName(QString::fromUtf8("programa"));
        programa->setMinimumSize(QSize(0, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        programa->setFont(font2);

        horizontalLayout->addWidget(programa);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(ced_ingreso);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(124, 16777215));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_5);

        metodo = new QComboBox(ced_ingreso);
        metodo->setObjectName(QString::fromUtf8("metodo"));
        metodo->setMinimumSize(QSize(0, 25));
        metodo->setFont(font2);

        horizontalLayout_5->addWidget(metodo);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(ced_ingreso);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(124, 0));
        label_3->setMaximumSize(QSize(124, 16777215));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_3);

        inicio = new QDateEdit(ced_ingreso);
        inicio->setObjectName(QString::fromUtf8("inicio"));
        inicio->setEnabled(true);
        inicio->setMinimumSize(QSize(0, 25));
        inicio->setFont(font2);

        horizontalLayout_4->addWidget(inicio);

        label_4 = new QLabel(ced_ingreso);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(30, 16777215));
        label_4->setFont(font1);

        horizontalLayout_4->addWidget(label_4);

        fin = new QDateEdit(ced_ingreso);
        fin->setObjectName(QString::fromUtf8("fin"));
        fin->setEnabled(true);
        fin->setMinimumSize(QSize(0, 25));
        fin->setFont(font2);

        horizontalLayout_4->addWidget(fin);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(ced_ingreso);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(124, 16777215));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        salida = new QComboBox(ced_ingreso);
        salida->setObjectName(QString::fromUtf8("salida"));
        salida->setMinimumSize(QSize(0, 25));
        salida->setFont(font2);

        horizontalLayout_2->addWidget(salida);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        aceptar = new QPushButton(ced_ingreso);
        aceptar->setObjectName(QString::fromUtf8("aceptar"));
        aceptar->setFont(font2);

        horizontalLayout_3->addWidget(aceptar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(ced_ingreso);

        QMetaObject::connectSlotsByName(ced_ingreso);
    } // setupUi

    void retranslateUi(QWidget *ced_ingreso)
    {
        ced_ingreso->setWindowTitle(QApplication::translate("ced_ingreso", "CAJA", 0, QApplication::UnicodeUTF8));
        titulo->setText(QApplication::translate("ced_ingreso", "Cedula de Ingreso Mensual", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ced_ingreso", "Programa Academico", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ced_ingreso", "M\303\251todo", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ced_ingreso", "Periodo del:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ced_ingreso", "Al:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ced_ingreso", "Salida", 0, QApplication::UnicodeUTF8));
        aceptar->setText(QApplication::translate("ced_ingreso", "Aceptar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ced_ingreso: public Ui_ced_ingreso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CED_INGRESO_DIALOG_H
