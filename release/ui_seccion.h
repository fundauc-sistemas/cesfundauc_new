/********************************************************************************
** Form generated from reading UI file 'seccion.ui'
**
** Created: Mon 26. May 11:13:59 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECCION_H
#define UI_SECCION_H

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

class Ui_seccion
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_11;
    QComboBox *status;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *codigo;
    QLabel *label_4;
    QComboBox *curso;
    QLabel *label_12;
    QComboBox *nivel;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *modalidad;
    QFrame *line_3;
    QLabel *label_6;
    QComboBox *profesor;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QComboBox *hora_ini;
    QLabel *label_10;
    QComboBox *edif;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QComboBox *salon;
    QLabel *label_8;
    QLineEdit *tope;
    QLabel *label_9;
    QComboBox *periodo;
    QDateEdit *fecha;
    QSpacerItem *horizontalSpacer_7;
    QFrame *line_10;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *guardar;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *seccion)
    {
        if (seccion->objectName().isEmpty())
            seccion->setObjectName(QString::fromUtf8("seccion"));
        seccion->resize(669, 296);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        seccion->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        seccion->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(seccion);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(seccion);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Gill Sans MT"));
        font1.setPointSize(22);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("font: 22pt \"Gill Sans MT\";\n"
"color: rgb(00,56,147);"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_11 = new QLabel(seccion);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(64, 0));
        QFont font2;
        font2.setPointSize(10);
        label_11->setFont(font2);

        horizontalLayout_6->addWidget(label_11);

        status = new QComboBox(seccion);
        status->setObjectName(QString::fromUtf8("status"));
        status->setMinimumSize(QSize(0, 25));

        horizontalLayout_6->addWidget(status);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_6);

        line_7 = new QFrame(seccion);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(seccion);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(64, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(10);
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        codigo = new QLineEdit(seccion);
        codigo->setObjectName(QString::fromUtf8("codigo"));
        codigo->setMinimumSize(QSize(70, 25));
        codigo->setMaximumSize(QSize(70, 16777215));
        QFont font4;
        font4.setPointSize(9);
        codigo->setFont(font4);

        horizontalLayout_2->addWidget(codigo);

        label_4 = new QLabel(seccion);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(64, 0));
        label_4->setMaximumSize(QSize(40, 16777215));
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_4);

        curso = new QComboBox(seccion);
        curso->setObjectName(QString::fromUtf8("curso"));
        curso->setMinimumSize(QSize(320, 25));
        curso->setFont(font4);

        horizontalLayout_2->addWidget(curso);

        label_12 = new QLabel(seccion);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(50, 0));
        label_12->setMaximumSize(QSize(26, 16777215));
        label_12->setFont(font3);
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_12);

        nivel = new QComboBox(seccion);
        nivel->setObjectName(QString::fromUtf8("nivel"));
        nivel->setMinimumSize(QSize(50, 25));
        nivel->setMaximumSize(QSize(50, 16777215));
        nivel->setFont(font4);

        horizontalLayout_2->addWidget(nivel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(seccion);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(50, 0));
        label_3->setMaximumSize(QSize(70, 16777215));
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        modalidad = new QComboBox(seccion);
        modalidad->setObjectName(QString::fromUtf8("modalidad"));
        modalidad->setMinimumSize(QSize(150, 25));
        modalidad->setFont(font4);

        horizontalLayout->addWidget(modalidad);

        line_3 = new QFrame(seccion);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        label_6 = new QLabel(seccion);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(64, 0));
        label_6->setMaximumSize(QSize(40, 16777215));
        label_6->setFont(font3);
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_6);

        profesor = new QComboBox(seccion);
        profesor->setObjectName(QString::fromUtf8("profesor"));
        profesor->setMinimumSize(QSize(150, 25));
        profesor->setFont(font4);

        horizontalLayout->addWidget(profesor);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout);

        line_8 = new QFrame(seccion);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(seccion);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(64, 0));
        label_5->setMaximumSize(QSize(40, 16777215));
        label_5->setFont(font3);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_5);

        hora_ini = new QComboBox(seccion);
        hora_ini->setObjectName(QString::fromUtf8("hora_ini"));
        hora_ini->setMinimumSize(QSize(120, 25));
        hora_ini->setMaximumSize(QSize(150, 16777215));
        hora_ini->setFont(font4);

        horizontalLayout_3->addWidget(hora_ini);

        label_10 = new QLabel(seccion);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(64, 0));
        label_10->setMaximumSize(QSize(50, 16777215));
        label_10->setFont(font3);
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_10);

        edif = new QComboBox(seccion);
        edif->setObjectName(QString::fromUtf8("edif"));
        edif->setMinimumSize(QSize(100, 25));
        edif->setFont(font4);

        horizontalLayout_3->addWidget(edif);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_7 = new QLabel(seccion);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(64, 0));
        label_7->setMaximumSize(QSize(40, 16777215));
        label_7->setFont(font3);
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_7);

        salon = new QComboBox(seccion);
        salon->setObjectName(QString::fromUtf8("salon"));
        salon->setMinimumSize(QSize(200, 25));
        salon->setMaximumSize(QSize(50, 16777215));
        salon->setFont(font4);

        horizontalLayout_4->addWidget(salon);

        label_8 = new QLabel(seccion);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(64, 0));
        label_8->setFont(font3);

        horizontalLayout_4->addWidget(label_8);

        tope = new QLineEdit(seccion);
        tope->setObjectName(QString::fromUtf8("tope"));
        tope->setMinimumSize(QSize(40, 25));
        tope->setMaximumSize(QSize(30, 16777215));
        tope->setFont(font4);

        horizontalLayout_4->addWidget(tope);

        label_9 = new QLabel(seccion);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(90, 0));
        label_9->setFont(font2);

        horizontalLayout_4->addWidget(label_9);

        periodo = new QComboBox(seccion);
        periodo->setObjectName(QString::fromUtf8("periodo"));
        periodo->setMinimumSize(QSize(50, 25));
        periodo->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(periodo);

        fecha = new QDateEdit(seccion);
        fecha->setObjectName(QString::fromUtf8("fecha"));
        fecha->setMinimumSize(QSize(0, 25));
        fecha->setFont(font4);

        horizontalLayout_4->addWidget(fecha);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_4);

        line_10 = new QFrame(seccion);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_10);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        guardar = new QPushButton(seccion);
        guardar->setObjectName(QString::fromUtf8("guardar"));
        guardar->setFont(font4);

        horizontalLayout_5->addWidget(guardar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(seccion);

        QMetaObject::connectSlotsByName(seccion);
    } // setupUi

    void retranslateUi(QWidget *seccion)
    {
        seccion->setWindowTitle(QApplication::translate("seccion", "CONTROL DE ESTUDIOS", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("seccion", "Nueva Seccion", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("seccion", "Status", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("seccion", "Codigo", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("seccion", "M\303\251todo", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("seccion", "Nivel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("seccion", "Modalidad", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("seccion", "Profesor", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("seccion", "Horario", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("seccion", "Edificio", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("seccion", "Salon", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("seccion", "Tope", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("seccion", "Fecha de Inicio", 0, QApplication::UnicodeUTF8));
        guardar->setText(QApplication::translate("seccion", "Guardar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class seccion: public Ui_seccion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECCION_H
