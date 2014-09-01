/********************************************************************************
** Form generated from reading UI file 'usuario.ui'
**
** Created: Mon 26. May 11:13:59 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USUARIO_H
#define UI_USUARIO_H

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

class Ui_usuario
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *nombre;
    QLabel *label_4;
    QLineEdit *cedula;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *username;
    QLabel *label_2;
    QLineEdit *passwd;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *email;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *guardar;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *usuario)
    {
        if (usuario->objectName().isEmpty())
            usuario->setObjectName(QString::fromUtf8("usuario"));
        usuario->resize(553, 220);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        usuario->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(usuario);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_6 = new QLabel(usuario);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans MT"));
        font.setPointSize(22);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("font: 22pt \"Gill Sans MT\";\n"
"color: rgb(00,56,147);"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_6);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(usuario);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(50, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_3);

        nombre = new QLineEdit(usuario);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setEnabled(false);
        nombre->setMinimumSize(QSize(0, 25));
        nombre->setMaximumSize(QSize(254, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        nombre->setFont(font2);

        horizontalLayout_2->addWidget(nombre);

        label_4 = new QLabel(usuario);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(66, 0));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_4);

        cedula = new QLineEdit(usuario);
        cedula->setObjectName(QString::fromUtf8("cedula"));
        cedula->setEnabled(false);
        cedula->setMinimumSize(QSize(0, 25));
        cedula->setMaximumSize(QSize(150, 16777215));
        cedula->setFont(font2);

        horizontalLayout_2->addWidget(cedula);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(usuario);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(50, 0));
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        username = new QLineEdit(usuario);
        username->setObjectName(QString::fromUtf8("username"));
        username->setMinimumSize(QSize(0, 25));
        username->setFont(font2);

        horizontalLayout->addWidget(username);

        label_2 = new QLabel(usuario);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        passwd = new QLineEdit(usuario);
        passwd->setObjectName(QString::fromUtf8("passwd"));
        passwd->setMinimumSize(QSize(0, 25));
        passwd->setMaximumSize(QSize(150, 16777215));
        passwd->setFont(font2);

        horizontalLayout->addWidget(passwd);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(usuario);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_5);

        email = new QLineEdit(usuario);
        email->setObjectName(QString::fromUtf8("email"));
        email->setMinimumSize(QSize(0, 25));
        email->setFont(font2);

        horizontalLayout_3->addWidget(email);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        guardar = new QPushButton(usuario);
        guardar->setObjectName(QString::fromUtf8("guardar"));
        guardar->setFont(font2);

        horizontalLayout_4->addWidget(guardar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(usuario);

        QMetaObject::connectSlotsByName(usuario);
    } // setupUi

    void retranslateUi(QWidget *usuario)
    {
        usuario->setWindowTitle(QApplication::translate("usuario", "ADMINISTRACION", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("usuario", "Usuario", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("usuario", "Nombre", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("usuario", "Cedula", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("usuario", "Usuario", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("usuario", "Contrase\303\261a", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("usuario", "Correo electr\303\263nico", 0, QApplication::UnicodeUTF8));
        guardar->setText(QApplication::translate("usuario", "Guardar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class usuario: public Ui_usuario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USUARIO_H
