/********************************************************************************
** Form generated from reading UI file 'nuevo_deposito.ui'
**
** Created: Mon 26. May 11:14:01 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUEVO_DEPOSITO_H
#define UI_NUEVO_DEPOSITO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
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

class Ui_nuevodeposito
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *prog;
    QLabel *label_51;
    QDateEdit *fecha;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QComboBox *pago;
    QLabel *label_49;
    QLineEdit *referencia;
    QHBoxLayout *horizontalLayout;
    QLabel *label_50;
    QLineEdit *monto;
    QLabel *label_8;
    QComboBox *banco;
    QLabel *label_3;
    QLineEdit *factura;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *guardar;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *nuevodeposito)
    {
        if (nuevodeposito->objectName().isEmpty())
            nuevodeposito->setObjectName(QString::fromUtf8("nuevodeposito"));
        nuevodeposito->resize(640, 249);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        nuevodeposito->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(nuevodeposito);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(nuevodeposito);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans MT"));
        font.setPointSize(22);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("font: 22pt \"Gill Sans MT\";\n"
"color: rgb(00,56,147);"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(nuevodeposito);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(130, 0));
        label->setMaximumSize(QSize(130, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        prog = new QComboBox(nuevodeposito);
        prog->setObjectName(QString::fromUtf8("prog"));
        prog->setMinimumSize(QSize(300, 25));
        prog->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_2->addWidget(prog);

        label_51 = new QLabel(nuevodeposito);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setMinimumSize(QSize(50, 30));
        label_51->setMaximumSize(QSize(16777215, 30));
        label_51->setFont(font1);
        label_51->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_51);

        fecha = new QDateEdit(nuevodeposito);
        fecha->setObjectName(QString::fromUtf8("fecha"));
        fecha->setMinimumSize(QSize(90, 25));
        fecha->setMaximumSize(QSize(90, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        fecha->setFont(font2);

        horizontalLayout_2->addWidget(fecha);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_7 = new QLabel(nuevodeposito);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(90, 30));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_7);

        pago = new QComboBox(nuevodeposito);
        pago->setObjectName(QString::fromUtf8("pago"));
        pago->setMinimumSize(QSize(200, 25));
        pago->setMaximumSize(QSize(120, 16777215));
        QFont font3;
        font3.setPointSize(9);
        pago->setFont(font3);

        horizontalLayout_3->addWidget(pago);

        label_49 = new QLabel(nuevodeposito);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setMinimumSize(QSize(60, 0));
        label_49->setMaximumSize(QSize(16777215, 30));
        label_49->setFont(font1);
        label_49->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_49);

        referencia = new QLineEdit(nuevodeposito);
        referencia->setObjectName(QString::fromUtf8("referencia"));
        referencia->setMinimumSize(QSize(160, 25));
        referencia->setMaximumSize(QSize(160, 16777215));
        referencia->setFont(font1);

        horizontalLayout_3->addWidget(referencia);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_50 = new QLabel(nuevodeposito);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setMinimumSize(QSize(50, 0));
        label_50->setMaximumSize(QSize(16777215, 30));
        label_50->setFont(font1);
        label_50->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_50);

        monto = new QLineEdit(nuevodeposito);
        monto->setObjectName(QString::fromUtf8("monto"));
        monto->setMinimumSize(QSize(80, 25));
        monto->setMaximumSize(QSize(80, 16777215));
        monto->setFont(font3);

        horizontalLayout->addWidget(monto);

        label_8 = new QLabel(nuevodeposito);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(50, 0));
        label_8->setMaximumSize(QSize(16777215, 30));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_8);

        banco = new QComboBox(nuevodeposito);
        banco->setObjectName(QString::fromUtf8("banco"));
        banco->setMinimumSize(QSize(250, 25));
        banco->setMaximumSize(QSize(250, 16777215));
        banco->setFont(font3);

        horizontalLayout->addWidget(banco);

        label_3 = new QLabel(nuevodeposito);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(50, 0));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        factura = new QLineEdit(nuevodeposito);
        factura->setObjectName(QString::fromUtf8("factura"));
        factura->setMinimumSize(QSize(0, 25));
        factura->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(factura);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(nuevodeposito);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        guardar = new QPushButton(nuevodeposito);
        guardar->setObjectName(QString::fromUtf8("guardar"));
        guardar->setMinimumSize(QSize(0, 25));
        guardar->setFont(font2);

        horizontalLayout_4->addWidget(guardar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(nuevodeposito);

        QMetaObject::connectSlotsByName(nuevodeposito);
    } // setupUi

    void retranslateUi(QWidget *nuevodeposito)
    {
        nuevodeposito->setWindowTitle(QApplication::translate("nuevodeposito", "CAJA", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("nuevodeposito", "Nuevo Deposito", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("nuevodeposito", "Programa Academico", 0, QApplication::UnicodeUTF8));
        label_51->setText(QApplication::translate("nuevodeposito", "Emision", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("nuevodeposito", "Forma de Pago", 0, QApplication::UnicodeUTF8));
        label_49->setText(QApplication::translate("nuevodeposito", "Referencia", 0, QApplication::UnicodeUTF8));
        label_50->setText(QApplication::translate("nuevodeposito", "Monto", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("nuevodeposito", "Banco", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("nuevodeposito", "Factura", 0, QApplication::UnicodeUTF8));
        guardar->setText(QApplication::translate("nuevodeposito", "Guardar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class nuevodeposito: public Ui_nuevodeposito {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUEVO_DEPOSITO_H
