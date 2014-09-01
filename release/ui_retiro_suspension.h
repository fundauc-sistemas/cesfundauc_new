/********************************************************************************
** Form generated from reading UI file 'retiro_suspension.ui'
**
** Created: Mon 26. May 11:13:59 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETIRO_SUSPENSION_H
#define UI_RETIRO_SUSPENSION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_retiro
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *matricula;
    QLabel *label_3;
    QLineEdit *cedula;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLineEdit *nombre;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *curso;
    QLabel *label_5;
    QLineEdit *nivel;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *retiro_check;
    QCheckBox *suspension_check;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *aceptar;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *retiro)
    {
        if (retiro->objectName().isEmpty())
            retiro->setObjectName(QString::fromUtf8("retiro"));
        retiro->resize(426, 247);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        retiro->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(retiro);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(retiro);
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
        label_2 = new QLabel(retiro);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(70, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        matricula = new QLineEdit(retiro);
        matricula->setObjectName(QString::fromUtf8("matricula"));
        matricula->setMinimumSize(QSize(0, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        matricula->setFont(font2);

        horizontalLayout->addWidget(matricula);

        label_3 = new QLabel(retiro);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(60, 0));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        cedula = new QLineEdit(retiro);
        cedula->setObjectName(QString::fromUtf8("cedula"));
        cedula->setMinimumSize(QSize(0, 25));
        cedula->setFont(font2);

        horizontalLayout->addWidget(cedula);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(retiro);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(70, 0));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_6);

        nombre = new QLineEdit(retiro);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setMinimumSize(QSize(0, 25));
        nombre->setFont(font2);

        horizontalLayout_2->addWidget(nombre);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(retiro);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(70, 0));
        label_4->setFont(font1);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_4);

        curso = new QLineEdit(retiro);
        curso->setObjectName(QString::fromUtf8("curso"));
        curso->setMinimumSize(QSize(0, 25));
        curso->setFont(font2);

        horizontalLayout_3->addWidget(curso);

        label_5 = new QLabel(retiro);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(60, 0));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_5);

        nivel = new QLineEdit(retiro);
        nivel->setObjectName(QString::fromUtf8("nivel"));
        nivel->setMinimumSize(QSize(0, 25));
        nivel->setFont(font2);

        horizontalLayout_3->addWidget(nivel);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        retiro_check = new QCheckBox(retiro);
        retiro_check->setObjectName(QString::fromUtf8("retiro_check"));
        retiro_check->setFont(font1);

        horizontalLayout_4->addWidget(retiro_check);

        suspension_check = new QCheckBox(retiro);
        suspension_check->setObjectName(QString::fromUtf8("suspension_check"));
        suspension_check->setFont(font1);

        horizontalLayout_4->addWidget(suspension_check);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        aceptar = new QPushButton(retiro);
        aceptar->setObjectName(QString::fromUtf8("aceptar"));
        aceptar->setFont(font2);

        horizontalLayout_5->addWidget(aceptar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(retiro);

        QMetaObject::connectSlotsByName(retiro);
    } // setupUi

    void retranslateUi(QWidget *retiro)
    {
        retiro->setWindowTitle(QApplication::translate("retiro", "CONTROL DE ESTUDIOS", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("retiro", "Retiro/Suspensi\303\263n de Nivel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("retiro", "Matr\303\255cula", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("retiro", "Cedula", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("retiro", "Nombre", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("retiro", "Metodo", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("retiro", "Nivel", 0, QApplication::UnicodeUTF8));
        retiro_check->setText(QApplication::translate("retiro", "Retiro", 0, QApplication::UnicodeUTF8));
        suspension_check->setText(QApplication::translate("retiro", "Suspensi\303\263n", 0, QApplication::UnicodeUTF8));
        aceptar->setText(QApplication::translate("retiro", "Aceptar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class retiro: public Ui_retiro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETIRO_SUSPENSION_H
