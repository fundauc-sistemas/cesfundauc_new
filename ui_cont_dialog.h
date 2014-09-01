/********************************************************************************
** Form generated from reading UI file 'cont_dialog.ui'
**
** Created: Fri 30. May 09:27:20 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONT_DIALOG_H
#define UI_CONT_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_contingencia
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QComboBox *programa;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QComboBox *user;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QDateEdit *fecha;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *control1;
    QLabel *label_8;
    QLineEdit *control2;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *rango;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *observacion;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *salida;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *aceptar;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *contingencia)
    {
        if (contingencia->objectName().isEmpty())
            contingencia->setObjectName(QString::fromUtf8("contingencia"));
        contingencia->resize(450, 380);
        contingencia->setMaximumSize(QSize(450, 380));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        contingencia->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(contingencia);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(contingencia);
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
        label->setLineWidth(0);
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(contingencia);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(135, 0));
        label_5->setMaximumSize(QSize(114, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_5);

        programa = new QComboBox(contingencia);
        programa->setObjectName(QString::fromUtf8("programa"));
        programa->setMinimumSize(QSize(0, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        programa->setFont(font2);

        horizontalLayout_6->addWidget(programa);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_10 = new QLabel(contingencia);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(135, 0));
        label_10->setMaximumSize(QSize(135, 16777215));
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_10);

        user = new QComboBox(contingencia);
        user->setObjectName(QString::fromUtf8("user"));
        user->setMinimumSize(QSize(0, 25));
        user->setFont(font2);

        horizontalLayout_8->addWidget(user);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_9 = new QLabel(contingencia);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(135, 0));
        label_9->setMaximumSize(QSize(135, 16777215));
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_9);

        fecha = new QDateEdit(contingencia);
        fecha->setObjectName(QString::fromUtf8("fecha"));
        fecha->setMinimumSize(QSize(0, 25));
        fecha->setFont(font2);

        horizontalLayout_7->addWidget(fecha);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(contingencia);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(135, 0));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_6);

        control1 = new QLineEdit(contingencia);
        control1->setObjectName(QString::fromUtf8("control1"));
        control1->setMinimumSize(QSize(0, 25));
        control1->setFont(font2);

        horizontalLayout_5->addWidget(control1);

        label_8 = new QLabel(contingencia);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(40, 0));
        label_8->setFont(font2);

        horizontalLayout_5->addWidget(label_8);

        control2 = new QLineEdit(contingencia);
        control2->setObjectName(QString::fromUtf8("control2"));
        control2->setMinimumSize(QSize(0, 25));
        control2->setFont(font2);

        horizontalLayout_5->addWidget(control2);

        label_7 = new QLabel(contingencia);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(40, 0));
        label_7->setFont(font2);

        horizontalLayout_5->addWidget(label_7);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(contingencia);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(135, 0));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        rango = new QLineEdit(contingencia);
        rango->setObjectName(QString::fromUtf8("rango"));
        rango->setMinimumSize(QSize(0, 25));
        rango->setFont(font2);

        horizontalLayout_2->addWidget(rango);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(contingencia);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(135, 0));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_4);

        observacion = new QLineEdit(contingencia);
        observacion->setObjectName(QString::fromUtf8("observacion"));
        observacion->setMinimumSize(QSize(0, 25));
        observacion->setFont(font2);

        horizontalLayout_4->addWidget(observacion);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(contingencia);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(135, 0));
        label_3->setMaximumSize(QSize(135, 16777215));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        salida = new QComboBox(contingencia);
        salida->setObjectName(QString::fromUtf8("salida"));
        salida->setMinimumSize(QSize(0, 25));
        salida->setFont(font2);

        horizontalLayout_3->addWidget(salida);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        aceptar = new QPushButton(contingencia);
        aceptar->setObjectName(QString::fromUtf8("aceptar"));
        aceptar->setFont(font2);

        horizontalLayout->addWidget(aceptar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(contingencia);

        QMetaObject::connectSlotsByName(contingencia);
    } // setupUi

    void retranslateUi(QWidget *contingencia)
    {
        contingencia->setWindowTitle(QApplication::translate("contingencia", "CAJA", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("contingencia", "Cuadre Diario de Caja", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("contingencia", "Programa Academico", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("contingencia", "Usuario", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("contingencia", "Fecha", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("contingencia", "N\302\272 de Control", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("contingencia", "Desde", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("contingencia", "Hasta", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("contingencia", "Factura(s) Contingencia", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("contingencia", "Observaciones", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("contingencia", "Salida", 0, QApplication::UnicodeUTF8));
        aceptar->setText(QApplication::translate("contingencia", "Aceptar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class contingencia: public Ui_contingencia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONT_DIALOG_H
