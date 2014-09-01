/********************************************************************************
** Form generated from reading UI file 'listado_seccion.ui'
**
** Created: Mon 26. May 11:13:59 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTADO_SECCION_H
#define UI_LISTADO_SECCION_H

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

class Ui_listado_seccion
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *cursolabel;
    QComboBox *metodo;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *nivel;
    QLabel *label_2;
    QComboBox *seccion;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *salida;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QDateEdit *fecini;
    QLabel *label_6;
    QDateEdit *fecfin;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *boton_generar;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *listado_seccion)
    {
        if (listado_seccion->objectName().isEmpty())
            listado_seccion->setObjectName(QString::fromUtf8("listado_seccion"));
        listado_seccion->resize(516, 260);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        listado_seccion->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(listado_seccion);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(listado_seccion);
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
        cursolabel = new QLabel(listado_seccion);
        cursolabel->setObjectName(QString::fromUtf8("cursolabel"));
        cursolabel->setMaximumSize(QSize(74, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        cursolabel->setFont(font1);
        cursolabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(cursolabel);

        metodo = new QComboBox(listado_seccion);
        metodo->setObjectName(QString::fromUtf8("metodo"));
        metodo->setMinimumSize(QSize(300, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        metodo->setFont(font2);

        horizontalLayout_2->addWidget(metodo);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(listado_seccion);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(74, 16777215));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        nivel = new QComboBox(listado_seccion);
        nivel->setObjectName(QString::fromUtf8("nivel"));
        nivel->setMinimumSize(QSize(0, 25));
        nivel->setMaximumSize(QSize(60, 16777215));
        nivel->setFont(font2);

        horizontalLayout->addWidget(nivel);

        label_2 = new QLabel(listado_seccion);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(74, 16777215));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        seccion = new QComboBox(listado_seccion);
        seccion->setObjectName(QString::fromUtf8("seccion"));
        seccion->setMinimumSize(QSize(0, 25));
        seccion->setFont(font2);

        horizontalLayout->addWidget(seccion);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(listado_seccion);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(74, 16777215));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_4);

        salida = new QComboBox(listado_seccion);
        salida->setObjectName(QString::fromUtf8("salida"));
        salida->setMinimumSize(QSize(0, 25));
        salida->setFont(font2);

        horizontalLayout_3->addWidget(salida);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(listado_seccion);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(74, 25));
        label_5->setMaximumSize(QSize(74, 16777215));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_5);

        fecini = new QDateEdit(listado_seccion);
        fecini->setObjectName(QString::fromUtf8("fecini"));
        fecini->setMinimumSize(QSize(0, 25));
        fecini->setFont(font2);

        horizontalLayout_5->addWidget(fecini);

        label_6 = new QLabel(listado_seccion);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(74, 25));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_6);

        fecfin = new QDateEdit(listado_seccion);
        fecfin->setObjectName(QString::fromUtf8("fecfin"));
        fecfin->setMinimumSize(QSize(0, 25));
        fecfin->setFont(font2);

        horizontalLayout_5->addWidget(fecfin);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));

        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        boton_generar = new QPushButton(listado_seccion);
        boton_generar->setObjectName(QString::fromUtf8("boton_generar"));
        boton_generar->setEnabled(false);
        boton_generar->setFont(font2);

        horizontalLayout_4->addWidget(boton_generar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(listado_seccion);

        QMetaObject::connectSlotsByName(listado_seccion);
    } // setupUi

    void retranslateUi(QWidget *listado_seccion)
    {
        listado_seccion->setWindowTitle(QApplication::translate("listado_seccion", "CONTROL DE ESTUDIOS", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("listado_seccion", "Listado", 0, QApplication::UnicodeUTF8));
        cursolabel->setText(QApplication::translate("listado_seccion", "M\303\251todo", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("listado_seccion", "Nivel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("listado_seccion", "Secci\303\263n", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("listado_seccion", "Salida", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("listado_seccion", "Fecha Inicio", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("listado_seccion", "Fecha Fin", 0, QApplication::UnicodeUTF8));
        boton_generar->setText(QApplication::translate("listado_seccion", "Aceptar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class listado_seccion: public Ui_listado_seccion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTADO_SECCION_H
