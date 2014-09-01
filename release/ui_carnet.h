/********************************************************************************
** Form generated from reading UI file 'carnet.ui'
**
** Created: Mon 26. May 11:14:00 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARNET_H
#define UI_CARNET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_carnet_form
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *matricula;
    QLabel *label_2;
    QLineEdit *cedula;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *programa;
    QLabel *label_5;
    QLineEdit *curso;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *nombre;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *sede;
    QLabel *label_8;
    QLineEdit *telefono;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QLineEdit *dir;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *imprimir;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *carnet_form)
    {
        if (carnet_form->objectName().isEmpty())
            carnet_form->setObjectName(QString::fromUtf8("carnet_form"));
        carnet_form->resize(600, 309);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        carnet_form->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(carnet_form);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(carnet_form);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans MT"));
        font.setPointSize(22);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("font: 22pt \"Gill Sans MT\";\n"
"color: rgb(00,56,147);"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(carnet_form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(80, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        matricula = new QLineEdit(carnet_form);
        matricula->setObjectName(QString::fromUtf8("matricula"));
        matricula->setMinimumSize(QSize(0, 25));
        matricula->setMaximumSize(QSize(116, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        matricula->setFont(font2);

        horizontalLayout->addWidget(matricula);

        label_2 = new QLabel(carnet_form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        cedula = new QLineEdit(carnet_form);
        cedula->setObjectName(QString::fromUtf8("cedula"));
        cedula->setMinimumSize(QSize(116, 25));
        cedula->setMaximumSize(QSize(116, 16777215));
        cedula->setFont(font2);

        horizontalLayout->addWidget(cedula);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        frame = new QFrame(carnet_form);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 170));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 561, 27));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_4);

        programa = new QLineEdit(layoutWidget);
        programa->setObjectName(QString::fromUtf8("programa"));
        programa->setEnabled(false);
        programa->setMinimumSize(QSize(170, 25));
        programa->setMaximumSize(QSize(170, 16777215));
        programa->setFont(font2);

        horizontalLayout_3->addWidget(programa);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(55, 0));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_5);

        curso = new QLineEdit(layoutWidget);
        curso->setObjectName(QString::fromUtf8("curso"));
        curso->setEnabled(false);
        curso->setMinimumSize(QSize(170, 25));

        horizontalLayout_3->addWidget(curso);

        layoutWidget1 = new QWidget(frame);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 50, 561, 27));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(55, 0));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_6);

        nombre = new QLineEdit(layoutWidget1);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setEnabled(false);
        nombre->setMinimumSize(QSize(0, 25));

        horizontalLayout_4->addWidget(nombre);

        layoutWidget2 = new QWidget(frame);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 90, 561, 27));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(55, 0));
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_7);

        sede = new QLineEdit(layoutWidget2);
        sede->setObjectName(QString::fromUtf8("sede"));
        sede->setEnabled(false);
        sede->setMinimumSize(QSize(0, 25));

        horizontalLayout_5->addWidget(sede);

        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(55, 0));
        label_8->setFont(font2);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_8);

        telefono = new QLineEdit(layoutWidget2);
        telefono->setObjectName(QString::fromUtf8("telefono"));
        telefono->setEnabled(true);
        telefono->setMinimumSize(QSize(0, 25));

        horizontalLayout_5->addWidget(telefono);

        layoutWidget3 = new QWidget(frame);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 130, 561, 27));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(55, 0));
        label_9->setFont(font2);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_9);

        dir = new QLineEdit(layoutWidget3);
        dir->setObjectName(QString::fromUtf8("dir"));
        dir->setEnabled(true);
        dir->setMinimumSize(QSize(0, 25));

        horizontalLayout_6->addWidget(dir);


        verticalLayout->addWidget(frame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        imprimir = new QPushButton(carnet_form);
        imprimir->setObjectName(QString::fromUtf8("imprimir"));
        imprimir->setEnabled(false);
        imprimir->setFont(font1);

        horizontalLayout_2->addWidget(imprimir);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(carnet_form);

        QMetaObject::connectSlotsByName(carnet_form);
    } // setupUi

    void retranslateUi(QWidget *carnet_form)
    {
        carnet_form->setWindowTitle(QApplication::translate("carnet_form", "CONTROL DE ESTUDIOS", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("carnet_form", "Carnet Estudiante", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("carnet_form", "Matr\303\255cula", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("carnet_form", "C\303\251dula", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("carnet_form", "Programa:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("carnet_form", "Curso:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("carnet_form", "Nombre:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("carnet_form", "Sede:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("carnet_form", "Telefono:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("carnet_form", "Direcci\303\263n:", 0, QApplication::UnicodeUTF8));
        imprimir->setText(QApplication::translate("carnet_form", "Imprimir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class carnet_form: public Ui_carnet_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARNET_H
