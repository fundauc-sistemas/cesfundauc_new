/********************************************************************************
** Form generated from reading UI file 'dialog_gen.ui'
**
** Created: Mon 26. May 11:14:00 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_GEN_H
#define UI_DIALOG_GEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialogo
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titulo;
    QHBoxLayout *lc_layout;
    QLabel *etiqueta;
    QLineEdit *cedula;
    QHBoxLayout *lc_layout2;
    QLabel *etiqueta2;
    QComboBox *combo;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *aceptar;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *dialogo)
    {
        if (dialogo->objectName().isEmpty())
            dialogo->setObjectName(QString::fromUtf8("dialogo"));
        dialogo->resize(329, 168);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        dialogo->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(dialogo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titulo = new QLabel(dialogo);
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

        lc_layout = new QHBoxLayout();
        lc_layout->setObjectName(QString::fromUtf8("lc_layout"));
        etiqueta = new QLabel(dialogo);
        etiqueta->setObjectName(QString::fromUtf8("etiqueta"));
        etiqueta->setMinimumSize(QSize(65, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        etiqueta->setFont(font1);
        etiqueta->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        lc_layout->addWidget(etiqueta);

        cedula = new QLineEdit(dialogo);
        cedula->setObjectName(QString::fromUtf8("cedula"));
        cedula->setMinimumSize(QSize(0, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        cedula->setFont(font2);

        lc_layout->addWidget(cedula);


        verticalLayout->addLayout(lc_layout);

        lc_layout2 = new QHBoxLayout();
        lc_layout2->setObjectName(QString::fromUtf8("lc_layout2"));
        etiqueta2 = new QLabel(dialogo);
        etiqueta2->setObjectName(QString::fromUtf8("etiqueta2"));
        etiqueta2->setMaximumSize(QSize(65, 16777215));
        etiqueta2->setFont(font1);
        etiqueta2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        lc_layout2->addWidget(etiqueta2);

        combo = new QComboBox(dialogo);
        combo->setObjectName(QString::fromUtf8("combo"));
        combo->setMinimumSize(QSize(0, 25));
        combo->setFont(font2);

        lc_layout2->addWidget(combo);


        verticalLayout->addLayout(lc_layout2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        aceptar = new QPushButton(dialogo);
        aceptar->setObjectName(QString::fromUtf8("aceptar"));
        aceptar->setFont(font2);

        horizontalLayout_2->addWidget(aceptar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(dialogo);

        QMetaObject::connectSlotsByName(dialogo);
    } // setupUi

    void retranslateUi(QWidget *dialogo)
    {
        dialogo->setWindowTitle(QApplication::translate("dialogo", "CONTROL DE ESTUDIOS", 0, QApplication::UnicodeUTF8));
        titulo->setText(QApplication::translate("dialogo", "Constancias", 0, QApplication::UnicodeUTF8));
        etiqueta->setText(QApplication::translate("dialogo", "C\303\251dula", 0, QApplication::UnicodeUTF8));
        etiqueta2->setText(QApplication::translate("dialogo", "Programa", 0, QApplication::UnicodeUTF8));
        aceptar->setText(QApplication::translate("dialogo", "Aceptar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialogo: public Ui_dialogo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_GEN_H
