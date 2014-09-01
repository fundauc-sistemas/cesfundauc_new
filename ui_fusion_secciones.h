/********************************************************************************
** Form generated from reading UI file 'fusion_secciones.ui'
**
** Created: Fri 30. May 09:27:19 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUSION_SECCIONES_H
#define UI_FUSION_SECCIONES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
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

class Ui_fusion_secciones
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *metodo;
    QLabel *label_15;
    QComboBox *modalidad;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *nivel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QComboBox *seccion1;
    QLabel *label_6;
    QLineEdit *cantidad1;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QComboBox *seccion2;
    QLabel *label_7;
    QLineEdit *cantidad2;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QComboBox *nueva_seccion;
    QLabel *label_9;
    QComboBox *profesor;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QComboBox *edif;
    QLabel *label_11;
    QComboBox *aula;
    QLabel *label_13;
    QLineEdit *tope;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_12;
    QComboBox *horario;
    QLabel *label_14;
    QComboBox *periodo;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *aceptar;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *fusion_secciones)
    {
        if (fusion_secciones->objectName().isEmpty())
            fusion_secciones->setObjectName(QString::fromUtf8("fusion_secciones"));
        fusion_secciones->resize(675, 412);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        fusion_secciones->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(fusion_secciones);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(fusion_secciones);
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
        label_2 = new QLabel(fusion_secciones);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(70, 0));
        label_2->setMaximumSize(QSize(50, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        metodo = new QComboBox(fusion_secciones);
        metodo->setObjectName(QString::fromUtf8("metodo"));
        metodo->setMinimumSize(QSize(200, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        metodo->setFont(font2);

        horizontalLayout->addWidget(metodo);

        label_15 = new QLabel(fusion_secciones);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(70, 0));
        label_15->setFont(font1);
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_15);

        modalidad = new QComboBox(fusion_secciones);
        modalidad->setObjectName(QString::fromUtf8("modalidad"));
        modalidad->setMinimumSize(QSize(230, 25));
        modalidad->setFont(font2);

        horizontalLayout->addWidget(modalidad);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(fusion_secciones);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(70, 0));
        label_3->setMaximumSize(QSize(45, 16777215));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_3);

        nivel = new QComboBox(fusion_secciones);
        nivel->setObjectName(QString::fromUtf8("nivel"));
        nivel->setMinimumSize(QSize(0, 25));
        nivel->setMaximumSize(QSize(70, 16777215));
        nivel->setFont(font2);

        horizontalLayout_2->addWidget(nivel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_4 = new QLabel(fusion_secciones);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(70, 0));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_4);

        seccion1 = new QComboBox(fusion_secciones);
        seccion1->setObjectName(QString::fromUtf8("seccion1"));
        seccion1->setMinimumSize(QSize(100, 25));
        seccion1->setFont(font2);

        horizontalLayout_2->addWidget(seccion1);

        label_6 = new QLabel(fusion_secciones);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(100, 0));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_6);

        cantidad1 = new QLineEdit(fusion_secciones);
        cantidad1->setObjectName(QString::fromUtf8("cantidad1"));
        cantidad1->setEnabled(false);
        cantidad1->setMinimumSize(QSize(0, 25));
        cantidad1->setMaximumSize(QSize(60, 16777215));
        cantidad1->setFont(font2);

        horizontalLayout_2->addWidget(cantidad1);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_5 = new QLabel(fusion_secciones);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(70, 0));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_5);

        seccion2 = new QComboBox(fusion_secciones);
        seccion2->setObjectName(QString::fromUtf8("seccion2"));
        seccion2->setMinimumSize(QSize(100, 25));
        seccion2->setFont(font2);

        horizontalLayout_3->addWidget(seccion2);

        label_7 = new QLabel(fusion_secciones);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(100, 0));
        label_7->setFont(font1);
        label_7->setMouseTracking(true);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_7);

        cantidad2 = new QLineEdit(fusion_secciones);
        cantidad2->setObjectName(QString::fromUtf8("cantidad2"));
        cantidad2->setEnabled(false);
        cantidad2->setMinimumSize(QSize(0, 25));
        cantidad2->setMaximumSize(QSize(60, 16777215));
        cantidad2->setFont(font2);

        horizontalLayout_3->addWidget(cantidad2);


        verticalLayout->addLayout(horizontalLayout_3);

        line = new QFrame(fusion_secciones);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMaximumSize(QSize(16777215, 10));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_8 = new QLabel(fusion_secciones);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(90, 16777215));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_8);

        nueva_seccion = new QComboBox(fusion_secciones);
        nueva_seccion->setObjectName(QString::fromUtf8("nueva_seccion"));
        nueva_seccion->setMinimumSize(QSize(0, 25));
        nueva_seccion->setMaximumSize(QSize(100, 16777215));
        nueva_seccion->setFont(font2);

        horizontalLayout_4->addWidget(nueva_seccion);

        label_9 = new QLabel(fusion_secciones);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(60, 0));
        label_9->setMaximumSize(QSize(60, 16777215));
        label_9->setFont(font1);
        label_9->setMouseTracking(true);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_9);

        profesor = new QComboBox(fusion_secciones);
        profesor->setObjectName(QString::fromUtf8("profesor"));
        profesor->setMinimumSize(QSize(190, 25));
        profesor->setFont(font2);

        horizontalLayout_4->addWidget(profesor);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_10 = new QLabel(fusion_secciones);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(70, 0));
        label_10->setMaximumSize(QSize(70, 16777215));
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_10);

        edif = new QComboBox(fusion_secciones);
        edif->setObjectName(QString::fromUtf8("edif"));
        edif->setMinimumSize(QSize(230, 25));
        edif->setFont(font2);

        horizontalLayout_5->addWidget(edif);

        label_11 = new QLabel(fusion_secciones);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(70, 0));
        label_11->setMaximumSize(QSize(45, 16777215));
        label_11->setFont(font1);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_11);

        aula = new QComboBox(fusion_secciones);
        aula->setObjectName(QString::fromUtf8("aula"));
        aula->setMinimumSize(QSize(120, 25));
        aula->setFont(font2);

        horizontalLayout_5->addWidget(aula);

        label_13 = new QLabel(fusion_secciones);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(70, 0));
        label_13->setMaximumSize(QSize(50, 16777215));
        label_13->setFont(font1);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_13);

        tope = new QLineEdit(fusion_secciones);
        tope->setObjectName(QString::fromUtf8("tope"));
        tope->setMinimumSize(QSize(50, 25));
        tope->setMaximumSize(QSize(50, 16777215));
        tope->setFont(font2);

        horizontalLayout_5->addWidget(tope);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_12 = new QLabel(fusion_secciones);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(60, 0));
        label_12->setMaximumSize(QSize(70, 16777215));
        label_12->setFont(font1);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_12);

        horario = new QComboBox(fusion_secciones);
        horario->setObjectName(QString::fromUtf8("horario"));
        horario->setMinimumSize(QSize(140, 25));
        horario->setFont(font2);

        horizontalLayout_7->addWidget(horario);

        label_14 = new QLabel(fusion_secciones);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(60, 0));
        label_14->setMaximumSize(QSize(70, 16777215));
        label_14->setFont(font1);
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_14);

        periodo = new QComboBox(fusion_secciones);
        periodo->setObjectName(QString::fromUtf8("periodo"));
        periodo->setMinimumSize(QSize(0, 25));
        periodo->setMaximumSize(QSize(59, 16777215));

        horizontalLayout_7->addWidget(periodo);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_7);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        aceptar = new QPushButton(fusion_secciones);
        aceptar->setObjectName(QString::fromUtf8("aceptar"));
        aceptar->setFont(font2);

        horizontalLayout_6->addWidget(aceptar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(fusion_secciones);

        QMetaObject::connectSlotsByName(fusion_secciones);
    } // setupUi

    void retranslateUi(QWidget *fusion_secciones)
    {
        fusion_secciones->setWindowTitle(QApplication::translate("fusion_secciones", "CONTROL DE ESTUDIOS", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("fusion_secciones", "Fusi\303\263n de Secciones", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("fusion_secciones", "M\303\251todo", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("fusion_secciones", "Modalidad", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("fusion_secciones", "Nivel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("fusion_secciones", "Seccion 1", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("fusion_secciones", "Cantidad Actual", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("fusion_secciones", "Seccion 2", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("fusion_secciones", "Cantidad Actual", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("fusion_secciones", "Nuevo C\303\263digo", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("fusion_secciones", "Profesor", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("fusion_secciones", "Edificio", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("fusion_secciones", "Aula", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("fusion_secciones", "Tope", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("fusion_secciones", "Horario", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("fusion_secciones", "Periodo", 0, QApplication::UnicodeUTF8));
        aceptar->setText(QApplication::translate("fusion_secciones", "Aceptar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class fusion_secciones: public Ui_fusion_secciones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUSION_SECCIONES_H
