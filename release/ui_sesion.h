/********************************************************************************
** Form generated from reading UI file 'sesion.ui'
**
** Created: Mon 26. May 11:13:59 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SESION_H
#define UI_SESION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sesion
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *usuario;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *password;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QDialogButtonBox *box;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *sesion)
    {
        if (sesion->objectName().isEmpty())
            sesion->setObjectName(QString::fromUtf8("sesion"));
        sesion->resize(300, 291);
        sesion->setMinimumSize(QSize(300, 200));
        sesion->setMaximumSize(QSize(16775, 16775));
        verticalLayout = new QVBoxLayout(sesion);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(sesion);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: none;"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/iconos/fundauc2.png")));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        usuario = new QLineEdit(sesion);
        usuario->setObjectName(QString::fromUtf8("usuario"));
        usuario->setMinimumSize(QSize(166, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans MT"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        usuario->setFont(font);
        usuario->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(usuario);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        password = new QLineEdit(sesion);
        password->setObjectName(QString::fromUtf8("password"));
        password->setMinimumSize(QSize(166, 25));
        password->setFont(font);
        password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(password);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        box = new QDialogButtonBox(sesion);
        box->setObjectName(QString::fromUtf8("box"));
        box->setMaximumSize(QSize(16777215, 25));
        box->setFont(font);
        box->setStyleSheet(QString::fromUtf8(""));
        box->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        box->setCenterButtons(true);

        verticalLayout->addWidget(box);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(sesion);

        QMetaObject::connectSlotsByName(sesion);
    } // setupUi

    void retranslateUi(QWidget *sesion)
    {
        sesion->setWindowTitle(QApplication::translate("sesion", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        usuario->setInputMask(QString());
        usuario->setText(QString());
        usuario->setPlaceholderText(QApplication::translate("sesion", "Usuario", 0, QApplication::UnicodeUTF8));
        password->setPlaceholderText(QApplication::translate("sesion", "Contrase\303\261a", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sesion: public Ui_sesion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SESION_H
