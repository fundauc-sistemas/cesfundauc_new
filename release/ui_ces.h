/********************************************************************************
** Form generated from reading UI file 'ces.ui'
**
** Created: Mon 26. May 11:14:00 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CES_H
#define UI_CES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ces
{
public:
    QHBoxLayout *horizontalLayout;
    QScrollArea *toolbox;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QToolButton *botonImprimir;
    QToolButton *botonGuardar;
    QToolButton *botonNuevo;
    QToolButton *botonAnular;
    QToolButton *botonBuscar;
    QToolButton *botonCargar;
    QToolButton *botonModificar;
    QToolButton *botonSalir;
    QSpacerItem *verticalSpacer;
    QLabel *etiqueta;
    QScrollArea *workspace;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *ces)
    {
        if (ces->objectName().isEmpty())
            ces->setObjectName(QString::fromUtf8("ces"));
        ces->resize(819, 593);
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans MT"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        ces->setFont(font);
        horizontalLayout = new QHBoxLayout(ces);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolbox = new QScrollArea(ces);
        toolbox->setObjectName(QString::fromUtf8("toolbox"));
        toolbox->setMinimumSize(QSize(140, 500));
        toolbox->setMaximumSize(QSize(180, 16777215));
        toolbox->setStyleSheet(QString::fromUtf8("background-color: rgb(231, 231, 231);"));
        toolbox->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 178, 573));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        botonImprimir = new QToolButton(scrollAreaWidgetContents_2);
        botonImprimir->setObjectName(QString::fromUtf8("botonImprimir"));
        botonImprimir->setEnabled(false);
        botonImprimir->setMinimumSize(QSize(50, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/Print.png"), QSize(), QIcon::Normal, QIcon::On);
        botonImprimir->setIcon(icon);
        botonImprimir->setIconSize(QSize(48, 48));

        gridLayout->addWidget(botonImprimir, 0, 1, 1, 1);

        botonGuardar = new QToolButton(scrollAreaWidgetContents_2);
        botonGuardar->setObjectName(QString::fromUtf8("botonGuardar"));
        botonGuardar->setEnabled(false);
        botonGuardar->setMinimumSize(QSize(50, 50));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/iconos/Save.png"), QSize(), QIcon::Normal, QIcon::On);
        botonGuardar->setIcon(icon1);
        botonGuardar->setIconSize(QSize(48, 48));

        gridLayout->addWidget(botonGuardar, 0, 2, 1, 1);

        botonNuevo = new QToolButton(scrollAreaWidgetContents_2);
        botonNuevo->setObjectName(QString::fromUtf8("botonNuevo"));
        botonNuevo->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/iconos/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonNuevo->setIcon(icon2);
        botonNuevo->setIconSize(QSize(48, 48));

        gridLayout->addWidget(botonNuevo, 1, 1, 1, 1);

        botonAnular = new QToolButton(scrollAreaWidgetContents_2);
        botonAnular->setObjectName(QString::fromUtf8("botonAnular"));
        botonAnular->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/iconos/Delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonAnular->setIcon(icon3);
        botonAnular->setIconSize(QSize(48, 48));

        gridLayout->addWidget(botonAnular, 1, 2, 1, 1);

        botonBuscar = new QToolButton(scrollAreaWidgetContents_2);
        botonBuscar->setObjectName(QString::fromUtf8("botonBuscar"));
        botonBuscar->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/iconos/Search.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonBuscar->setIcon(icon4);
        botonBuscar->setIconSize(QSize(48, 48));

        gridLayout->addWidget(botonBuscar, 2, 2, 1, 1);

        botonCargar = new QToolButton(scrollAreaWidgetContents_2);
        botonCargar->setObjectName(QString::fromUtf8("botonCargar"));
        botonCargar->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/iconos/Load.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonCargar->setIcon(icon5);
        botonCargar->setIconSize(QSize(48, 48));

        gridLayout->addWidget(botonCargar, 3, 1, 1, 1);

        botonModificar = new QToolButton(scrollAreaWidgetContents_2);
        botonModificar->setObjectName(QString::fromUtf8("botonModificar"));
        botonModificar->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/iconos/Modify.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonModificar->setIcon(icon6);
        botonModificar->setIconSize(QSize(48, 48));

        gridLayout->addWidget(botonModificar, 2, 1, 1, 1);

        botonSalir = new QToolButton(scrollAreaWidgetContents_2);
        botonSalir->setObjectName(QString::fromUtf8("botonSalir"));
        botonSalir->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/iconos/Back.png"), QSize(), QIcon::Normal, QIcon::On);
        botonSalir->setIcon(icon7);
        botonSalir->setIconSize(QSize(48, 48));

        gridLayout->addWidget(botonSalir, 3, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        etiqueta = new QLabel(scrollAreaWidgetContents_2);
        etiqueta->setObjectName(QString::fromUtf8("etiqueta"));

        verticalLayout->addWidget(etiqueta);

        toolbox->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout->addWidget(toolbox);

        workspace = new QScrollArea(ces);
        workspace->setObjectName(QString::fromUtf8("workspace"));
        workspace->setMinimumSize(QSize(500, 500));
        workspace->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 613, 573));
        workspace->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(workspace);


        retranslateUi(ces);

        QMetaObject::connectSlotsByName(ces);
    } // setupUi

    void retranslateUi(QWidget *ces)
    {
        ces->setWindowTitle(QApplication::translate("ces", "Form", 0, QApplication::UnicodeUTF8));
        botonImprimir->setText(QString());
        botonGuardar->setText(QString());
        botonNuevo->setText(QApplication::translate("ces", "...", 0, QApplication::UnicodeUTF8));
        botonAnular->setText(QApplication::translate("ces", "...", 0, QApplication::UnicodeUTF8));
        botonBuscar->setText(QApplication::translate("ces", "...", 0, QApplication::UnicodeUTF8));
        botonCargar->setText(QApplication::translate("ces", "...", 0, QApplication::UnicodeUTF8));
        botonModificar->setText(QApplication::translate("ces", "...", 0, QApplication::UnicodeUTF8));
        botonSalir->setText(QApplication::translate("ces", "...", 0, QApplication::UnicodeUTF8));
        etiqueta->setText(QApplication::translate("ces", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ces: public Ui_ces {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CES_H
