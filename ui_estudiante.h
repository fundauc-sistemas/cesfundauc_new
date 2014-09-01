/********************************************************************************
** Form generated from reading UI file 'estudiante.ui'
**
** Created: Fri 30. May 09:27:19 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESTUDIANTE_H
#define UI_ESTUDIANTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_estudiante
{
public:
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *mat_rif;
    QLineEdit *e_matricula;
    QLabel *label_3;
    QLineEdit *e_cedula;
    QLabel *label_2;
    QLineEdit *e_nombre;
    QLabel *label_12;
    QLineEdit *e_apellido;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *e_codigo;
    QLineEdit *e_telefono;
    QLabel *label_7;
    QLineEdit *e_codigo2;
    QLineEdit *e_celular;
    QLabel *label_6;
    QLineEdit *e_email;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_16;
    QLineEdit *estado;
    QLabel *label_15;
    QLineEdit *ciudad;
    QLabel *label_5;
    QLineEdit *zona;
    QGroupBox *groupBox_2;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label;
    QRadioButton *e_femenino;
    QRadioButton *e_masculino;
    QLabel *label_8;
    QDateEdit *e_fecha;
    QFrame *line_8;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QRadioButton *e_venezolano;
    QRadioButton *e_extranjero;
    QFrame *line_9;
    QLabel *label_10;
    QComboBox *e_civil;
    QGroupBox *groupBox_3;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_14;
    QComboBox *e_ocupacion;
    QLabel *label_13;
    QComboBox *e_instruccion;
    QPushButton *e_guardar;
    QGroupBox *groupBox_4;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_17;
    QComboBox *e_tipo;
    QLabel *label_11;
    QComboBox *e_sede;
    QLabel *label_18;
    QComboBox *e_condicion;
    QGroupBox *groupBox_5;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_19;
    QLineEdit *e_cedula2;
    QLabel *label_20;
    QLineEdit *e_nombre2;
    QLabel *label_21;
    QLineEdit *e_telefono2;

    void setupUi(QWidget *estudiante)
    {
        if (estudiante->objectName().isEmpty())
            estudiante->setObjectName(QString::fromUtf8("estudiante"));
        estudiante->resize(912, 560);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/iconos/esfera48.png"), QSize(), QIcon::Normal, QIcon::Off);
        estudiante->setWindowIcon(icon);
        groupBox = new QGroupBox(estudiante);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 891, 171));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        groupBox->setFont(font);
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 871, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mat_rif = new QLabel(horizontalLayoutWidget);
        mat_rif->setObjectName(QString::fromUtf8("mat_rif"));

        horizontalLayout->addWidget(mat_rif);

        e_matricula = new QLineEdit(horizontalLayoutWidget);
        e_matricula->setObjectName(QString::fromUtf8("e_matricula"));
        e_matricula->setEnabled(false);
        e_matricula->setMinimumSize(QSize(0, 25));
        e_matricula->setMaximumSize(QSize(60, 16777215));
        QFont font1;
        font1.setPointSize(9);
        e_matricula->setFont(font1);

        horizontalLayout->addWidget(e_matricula);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        e_cedula = new QLineEdit(horizontalLayoutWidget);
        e_cedula->setObjectName(QString::fromUtf8("e_cedula"));
        e_cedula->setMinimumSize(QSize(100, 25));
        e_cedula->setMaximumSize(QSize(70, 16777215));
        e_cedula->setFont(font1);

        horizontalLayout->addWidget(e_cedula);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMidLineWidth(0);

        horizontalLayout->addWidget(label_2);

        e_nombre = new QLineEdit(horizontalLayoutWidget);
        e_nombre->setObjectName(QString::fromUtf8("e_nombre"));
        e_nombre->setMinimumSize(QSize(200, 25));
        e_nombre->setFont(font1);

        horizontalLayout->addWidget(e_nombre);

        label_12 = new QLabel(horizontalLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFrameShadow(QFrame::Plain);

        horizontalLayout->addWidget(label_12);

        e_apellido = new QLineEdit(horizontalLayoutWidget);
        e_apellido->setObjectName(QString::fromUtf8("e_apellido"));
        e_apellido->setMinimumSize(QSize(200, 25));
        e_apellido->setFont(font1);

        horizontalLayout->addWidget(e_apellido);

        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 70, 871, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        e_codigo = new QLineEdit(horizontalLayoutWidget_2);
        e_codigo->setObjectName(QString::fromUtf8("e_codigo"));
        e_codigo->setMinimumSize(QSize(50, 25));
        e_codigo->setMaximumSize(QSize(50, 16777215));
        e_codigo->setMaxLength(4);

        horizontalLayout_2->addWidget(e_codigo);

        e_telefono = new QLineEdit(horizontalLayoutWidget_2);
        e_telefono->setObjectName(QString::fromUtf8("e_telefono"));
        e_telefono->setMinimumSize(QSize(100, 25));
        e_telefono->setMaximumSize(QSize(100, 16777215));
        e_telefono->setFont(font1);
        e_telefono->setMaxLength(7);

        horizontalLayout_2->addWidget(e_telefono);

        label_7 = new QLabel(horizontalLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);

        e_codigo2 = new QLineEdit(horizontalLayoutWidget_2);
        e_codigo2->setObjectName(QString::fromUtf8("e_codigo2"));
        e_codigo2->setMinimumSize(QSize(50, 25));
        e_codigo2->setMaximumSize(QSize(50, 16777215));
        e_codigo2->setMaxLength(4);

        horizontalLayout_2->addWidget(e_codigo2);

        e_celular = new QLineEdit(horizontalLayoutWidget_2);
        e_celular->setObjectName(QString::fromUtf8("e_celular"));
        e_celular->setMinimumSize(QSize(100, 25));
        e_celular->setMaximumSize(QSize(100, 16777215));
        e_celular->setFont(font1);
        e_celular->setMaxLength(7);

        horizontalLayout_2->addWidget(e_celular);

        label_6 = new QLabel(horizontalLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        e_email = new QLineEdit(horizontalLayoutWidget_2);
        e_email->setObjectName(QString::fromUtf8("e_email"));
        e_email->setMinimumSize(QSize(0, 25));
        e_email->setFont(font1);

        horizontalLayout_2->addWidget(e_email);

        horizontalLayoutWidget_7 = new QWidget(groupBox);
        horizontalLayoutWidget_7->setObjectName(QString::fromUtf8("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(10, 120, 871, 41));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(horizontalLayoutWidget_7);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_7->addWidget(label_16);

        estado = new QLineEdit(horizontalLayoutWidget_7);
        estado->setObjectName(QString::fromUtf8("estado"));
        estado->setMinimumSize(QSize(0, 25));

        horizontalLayout_7->addWidget(estado);

        label_15 = new QLabel(horizontalLayoutWidget_7);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_7->addWidget(label_15);

        ciudad = new QLineEdit(horizontalLayoutWidget_7);
        ciudad->setObjectName(QString::fromUtf8("ciudad"));
        ciudad->setMinimumSize(QSize(0, 25));

        horizontalLayout_7->addWidget(ciudad);

        label_5 = new QLabel(horizontalLayoutWidget_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(55, 16777215));

        horizontalLayout_7->addWidget(label_5);

        zona = new QLineEdit(horizontalLayoutWidget_7);
        zona->setObjectName(QString::fromUtf8("zona"));
        zona->setMinimumSize(QSize(0, 25));

        horizontalLayout_7->addWidget(zona);

        groupBox_2 = new QGroupBox(estudiante);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 350, 891, 71));
        groupBox_2->setFont(font);
        horizontalLayoutWidget_4 = new QWidget(groupBox_2);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 20, 871, 45));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(horizontalLayoutWidget_4);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_9 = new QHBoxLayout(widget);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(30, 0));
        label->setMaximumSize(QSize(30, 25));

        horizontalLayout_9->addWidget(label);

        e_femenino = new QRadioButton(widget);
        e_femenino->setObjectName(QString::fromUtf8("e_femenino"));
        e_femenino->setMinimumSize(QSize(0, 25));
        e_femenino->setMaximumSize(QSize(40, 25));
        e_femenino->setChecked(true);

        horizontalLayout_9->addWidget(e_femenino);

        e_masculino = new QRadioButton(widget);
        e_masculino->setObjectName(QString::fromUtf8("e_masculino"));
        e_masculino->setMinimumSize(QSize(0, 25));
        e_masculino->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_9->addWidget(e_masculino);


        horizontalLayout_4->addWidget(widget);

        label_8 = new QLabel(horizontalLayoutWidget_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(125, 16777215));

        horizontalLayout_4->addWidget(label_8);

        e_fecha = new QDateEdit(horizontalLayoutWidget_4);
        e_fecha->setObjectName(QString::fromUtf8("e_fecha"));
        e_fecha->setMinimumSize(QSize(0, 25));
        e_fecha->setFont(font1);

        horizontalLayout_4->addWidget(e_fecha);

        line_8 = new QFrame(horizontalLayoutWidget_4);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_8);

        widget_2 = new QWidget(horizontalLayoutWidget_4);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_8 = new QHBoxLayout(widget_2);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(widget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(110, 16777215));

        horizontalLayout_8->addWidget(label_9);

        e_venezolano = new QRadioButton(widget_2);
        e_venezolano->setObjectName(QString::fromUtf8("e_venezolano"));
        e_venezolano->setMinimumSize(QSize(40, 0));
        e_venezolano->setMaximumSize(QSize(40, 16777215));
        e_venezolano->setChecked(true);

        horizontalLayout_8->addWidget(e_venezolano);

        e_extranjero = new QRadioButton(widget_2);
        e_extranjero->setObjectName(QString::fromUtf8("e_extranjero"));
        e_extranjero->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_8->addWidget(e_extranjero);


        horizontalLayout_4->addWidget(widget_2);

        line_9 = new QFrame(horizontalLayoutWidget_4);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_9);

        label_10 = new QLabel(horizontalLayoutWidget_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_4->addWidget(label_10);

        e_civil = new QComboBox(horizontalLayoutWidget_4);
        e_civil->setObjectName(QString::fromUtf8("e_civil"));
        e_civil->setMinimumSize(QSize(0, 25));
        e_civil->setFont(font1);

        horizontalLayout_4->addWidget(e_civil);

        groupBox_3 = new QGroupBox(estudiante);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 190, 891, 71));
        groupBox_3->setFont(font);
        horizontalLayoutWidget_6 = new QWidget(groupBox_3);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(10, 20, 871, 41));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(horizontalLayoutWidget_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_6->addWidget(label_14);

        e_ocupacion = new QComboBox(horizontalLayoutWidget_6);
        e_ocupacion->setObjectName(QString::fromUtf8("e_ocupacion"));
        e_ocupacion->setMinimumSize(QSize(0, 25));
        e_ocupacion->setFont(font1);

        horizontalLayout_6->addWidget(e_ocupacion);

        label_13 = new QLabel(horizontalLayoutWidget_6);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_6->addWidget(label_13);

        e_instruccion = new QComboBox(horizontalLayoutWidget_6);
        e_instruccion->setObjectName(QString::fromUtf8("e_instruccion"));
        e_instruccion->setMinimumSize(QSize(0, 25));
        e_instruccion->setFont(font1);

        horizontalLayout_6->addWidget(e_instruccion);

        e_guardar = new QPushButton(estudiante);
        e_guardar->setObjectName(QString::fromUtf8("e_guardar"));
        e_guardar->setEnabled(true);
        e_guardar->setGeometry(QRect(410, 520, 91, 23));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        e_guardar->setFont(font2);
        groupBox_4 = new QGroupBox(estudiante);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 270, 891, 71));
        groupBox_4->setFont(font);
        horizontalLayoutWidget_3 = new QWidget(groupBox_4);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 20, 871, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(horizontalLayoutWidget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_3->addWidget(label_17);

        e_tipo = new QComboBox(horizontalLayoutWidget_3);
        e_tipo->setObjectName(QString::fromUtf8("e_tipo"));
        e_tipo->setMinimumSize(QSize(200, 25));
        e_tipo->setFont(font1);

        horizontalLayout_3->addWidget(e_tipo);

        label_11 = new QLabel(horizontalLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_3->addWidget(label_11);

        e_sede = new QComboBox(horizontalLayoutWidget_3);
        e_sede->setObjectName(QString::fromUtf8("e_sede"));
        e_sede->setMinimumSize(QSize(200, 25));
        e_sede->setFont(font1);

        horizontalLayout_3->addWidget(e_sede);

        label_18 = new QLabel(horizontalLayoutWidget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMaximumSize(QSize(120, 16777215));
        label_18->setFrameShadow(QFrame::Plain);

        horizontalLayout_3->addWidget(label_18);

        e_condicion = new QComboBox(horizontalLayoutWidget_3);
        e_condicion->setObjectName(QString::fromUtf8("e_condicion"));
        e_condicion->setMinimumSize(QSize(200, 25));
        e_condicion->setFont(font1);

        horizontalLayout_3->addWidget(e_condicion);

        groupBox_5 = new QGroupBox(estudiante);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 430, 891, 71));
        groupBox_5->setFont(font);
        horizontalLayoutWidget_5 = new QWidget(groupBox_5);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 20, 871, 41));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(horizontalLayoutWidget_5);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_5->addWidget(label_19);

        e_cedula2 = new QLineEdit(horizontalLayoutWidget_5);
        e_cedula2->setObjectName(QString::fromUtf8("e_cedula2"));
        e_cedula2->setEnabled(false);
        e_cedula2->setMinimumSize(QSize(100, 25));
        e_cedula2->setMaximumSize(QSize(100, 16777215));
        e_cedula2->setFont(font1);

        horizontalLayout_5->addWidget(e_cedula2);

        label_20 = new QLabel(horizontalLayoutWidget_5);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_5->addWidget(label_20);

        e_nombre2 = new QLineEdit(horizontalLayoutWidget_5);
        e_nombre2->setObjectName(QString::fromUtf8("e_nombre2"));
        e_nombre2->setEnabled(false);
        e_nombre2->setMinimumSize(QSize(0, 25));
        e_nombre2->setFont(font1);

        horizontalLayout_5->addWidget(e_nombre2);

        label_21 = new QLabel(horizontalLayoutWidget_5);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_5->addWidget(label_21);

        e_telefono2 = new QLineEdit(horizontalLayoutWidget_5);
        e_telefono2->setObjectName(QString::fromUtf8("e_telefono2"));
        e_telefono2->setEnabled(false);
        e_telefono2->setMinimumSize(QSize(150, 25));
        e_telefono2->setFont(font1);

        horizontalLayout_5->addWidget(e_telefono2);


        retranslateUi(estudiante);

        QMetaObject::connectSlotsByName(estudiante);
    } // setupUi

    void retranslateUi(QWidget *estudiante)
    {
        estudiante->setWindowTitle(QApplication::translate("estudiante", "CONTROL DE ESTUDIOS", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("estudiante", "Informaci\303\263n B\303\241sica", 0, QApplication::UnicodeUTF8));
        mat_rif->setText(QApplication::translate("estudiante", "Matr\303\255cula", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("estudiante", "C\303\251dula", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("estudiante", "Nombres", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("estudiante", "Apellidos", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("estudiante", "Telefono", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("estudiante", "Telefono Celular", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("estudiante", "Email", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("estudiante", "Estado", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("estudiante", "Ciudad", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("estudiante", "Zona", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("estudiante", "Informacion Legal", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("estudiante", "Sexo", 0, QApplication::UnicodeUTF8));
        e_femenino->setText(QApplication::translate("estudiante", "F", 0, QApplication::UnicodeUTF8));
        e_masculino->setText(QApplication::translate("estudiante", "M", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("estudiante", "Fecha de Nacimiento", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("estudiante", "Nacionalidad", 0, QApplication::UnicodeUTF8));
        e_venezolano->setText(QApplication::translate("estudiante", "V", 0, QApplication::UnicodeUTF8));
        e_extranjero->setText(QApplication::translate("estudiante", "E", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("estudiante", "Edo. Civil", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("estudiante", "Informaci\303\263n Profesional", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("estudiante", "Ocupaci\303\263n", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("estudiante", "Grado de Instrucci\303\263n", 0, QApplication::UnicodeUTF8));
        e_guardar->setText(QApplication::translate("estudiante", "Guardar", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("estudiante", "Informacion Academica", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("estudiante", "Tipo", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("estudiante", "Sede", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("estudiante", "Condici\303\263n Especial", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("estudiante", "Informaci\303\263n del Representante", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("estudiante", "C\303\251dula", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("estudiante", "Nombre y Apellido", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("estudiante", "Tel\303\251fono", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class estudiante: public Ui_estudiante {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESTUDIANTE_H
