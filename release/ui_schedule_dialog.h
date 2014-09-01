/********************************************************************************
** Form generated from reading UI file 'schedule_dialog.ui'
**
** Created: Mon 26. May 11:13:59 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULE_DIALOG_H
#define UI_SCHEDULE_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_schedules
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *metodo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *modalidad;
    QHBoxLayout *horizontalLayout_4;
    QLabel *gh;
    QComboBox *salida;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *aceptar;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *schedules)
    {
        if (schedules->objectName().isEmpty())
            schedules->setObjectName(QString::fromUtf8("schedules"));
        schedules->resize(400, 198);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        schedules->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        schedules->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(schedules);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(schedules);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Gill Sans MT"));
        font1.setPointSize(22);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("font: 22pt \"Gill Sans MT\";\n"
"color: rgb(00,56,147);"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(schedules);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(70, 16777215));
        QFont font2;
        font2.setPointSize(10);
        label->setFont(font2);

        horizontalLayout->addWidget(label);

        metodo = new QComboBox(schedules);
        metodo->setObjectName(QString::fromUtf8("metodo"));
        metodo->setMinimumSize(QSize(0, 25));
        QFont font3;
        font3.setPointSize(9);
        metodo->setFont(font3);

        horizontalLayout->addWidget(metodo);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(schedules);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(70, 16777215));
        label_2->setFont(font2);

        horizontalLayout_2->addWidget(label_2);

        modalidad = new QComboBox(schedules);
        modalidad->setObjectName(QString::fromUtf8("modalidad"));
        modalidad->setMinimumSize(QSize(0, 25));
        modalidad->setFont(font3);

        horizontalLayout_2->addWidget(modalidad);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        gh = new QLabel(schedules);
        gh->setObjectName(QString::fromUtf8("gh"));
        gh->setMinimumSize(QSize(70, 0));
        gh->setMaximumSize(QSize(70, 16777215));
        gh->setFont(font2);

        horizontalLayout_4->addWidget(gh);

        salida = new QComboBox(schedules);
        salida->setObjectName(QString::fromUtf8("salida"));
        salida->setMinimumSize(QSize(0, 25));
        salida->setFont(font3);

        horizontalLayout_4->addWidget(salida);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        aceptar = new QPushButton(schedules);
        aceptar->setObjectName(QString::fromUtf8("aceptar"));
        aceptar->setFont(font3);

        horizontalLayout_3->addWidget(aceptar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(schedules);

        QMetaObject::connectSlotsByName(schedules);
    } // setupUi

    void retranslateUi(QWidget *schedules)
    {
        schedules->setWindowTitle(QApplication::translate("schedules", "CONTROL DE ESTUDIOS", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("schedules", "Book Schedule", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("schedules", "M\303\251todo", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("schedules", "Modalidad", 0, QApplication::UnicodeUTF8));
        gh->setText(QApplication::translate("schedules", "Salida", 0, QApplication::UnicodeUTF8));
        aceptar->setText(QApplication::translate("schedules", "Aceptar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class schedules: public Ui_schedules {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULE_DIALOG_H
