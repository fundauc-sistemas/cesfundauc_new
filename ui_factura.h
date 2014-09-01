/********************************************************************************
** Form generated from reading UI file 'factura.ui'
**
** Created: Fri 30. May 09:27:19 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACTURA_H
#define UI_FACTURA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form
{
public:
    QGroupBox *groupBox_2;
    QWidget *horizontalLayoutWidget_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QLineEdit *f_matricula;
    QLabel *label_31;
    QLineEdit *f_cedula_4;
    QLabel *label_32;
    QLineEdit *f_nombre_4;
    QWidget *horizontalLayoutWidget_9;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_34;
    QLineEdit *f_curso_2;
    QLabel *label_36;
    QLineEdit *f_nivel;
    QLabel *label_5;
    QLineEdit *f_seccion_2;
    QLabel *label_37;
    QLineEdit *f_turno;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_33;
    QLineEdit *f_condicion_2;
    QLabel *label_6;
    QLineEdit *f_cond_esp;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_39;
    QLineEdit *f_cedula_5;
    QLabel *label_40;
    QLineEdit *f_nombre_5;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *f_direccion;
    QLabel *label_41;
    QLineEdit *f_telf_3;
    QCheckBox *f_same;
    QGroupBox *groupBox_3;
    QWidget *gridLayoutWidget_2;
    QGridLayout *f_grid2_2;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_46;
    QLabel *label;
    QLabel *label_4;
    QComboBox *tp;
    QComboBox *metodo;
    QComboBox *item;
    QLineEdit *descripcion;
    QLineEdit *cantidad;
    QLineEdit *precio;
    QLineEdit *bs;
    QTableWidget *f_tabla;
    QGroupBox *f_datos;
    QWidget *layoutWidget_5;
    QGridLayout *f_grid_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_49;
    QLabel *label_50;
    QLabel *label_51;
    QDateEdit *fechas;
    QComboBox *detallespago;
    QComboBox *detallesbanco;
    QLineEdit *referencias;
    QLineEdit *montos;
    QCheckBox *f_postpago;
    QTableWidget *f_tabla0;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *f_quitar2;
    QSpacerItem *horizontalSpacer_4;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *f_quitar;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *f_subtotal_2;
    QLineEdit *f_iva_2;
    QLineEdit *f_total_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_38;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_47;
    QLineEdit *f_piva_2;
    QLabel *label_48;
    QLabel *label_30;

    void setupUi(QWidget *form)
    {
        if (form->objectName().isEmpty())
            form->setObjectName(QString::fromUtf8("form"));
        form->resize(971, 910);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(form->sizePolicy().hasHeightForWidth());
        form->setSizePolicy(sizePolicy);
        form->setMinimumSize(QSize(800, 910));
        form->setMaximumSize(QSize(16777215, 970));
        groupBox_2 = new QGroupBox(form);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(9, 10, 901, 121));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(780, 113));
        groupBox_2->setMaximumSize(QSize(1000, 200));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        groupBox_2->setFont(font);
        horizontalLayoutWidget_8 = new QWidget(groupBox_2);
        horizontalLayoutWidget_8->setObjectName(QString::fromUtf8("horizontalLayoutWidget_8"));
        horizontalLayoutWidget_8->setGeometry(QRect(10, 20, 881, 31));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_8);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_8);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_8->addWidget(label_3);

        f_matricula = new QLineEdit(horizontalLayoutWidget_8);
        f_matricula->setObjectName(QString::fromUtf8("f_matricula"));
        f_matricula->setMinimumSize(QSize(0, 25));
        f_matricula->setMaximumSize(QSize(100, 16777215));
        QFont font1;
        font1.setPointSize(9);
        f_matricula->setFont(font1);

        horizontalLayout_8->addWidget(f_matricula);

        label_31 = new QLabel(horizontalLayoutWidget_8);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        horizontalLayout_8->addWidget(label_31);

        f_cedula_4 = new QLineEdit(horizontalLayoutWidget_8);
        f_cedula_4->setObjectName(QString::fromUtf8("f_cedula_4"));
        f_cedula_4->setMinimumSize(QSize(0, 25));
        f_cedula_4->setMaximumSize(QSize(120, 16777215));
        f_cedula_4->setFont(font1);

        horizontalLayout_8->addWidget(f_cedula_4);

        label_32 = new QLabel(horizontalLayoutWidget_8);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        horizontalLayout_8->addWidget(label_32);

        f_nombre_4 = new QLineEdit(horizontalLayoutWidget_8);
        f_nombre_4->setObjectName(QString::fromUtf8("f_nombre_4"));
        f_nombre_4->setMinimumSize(QSize(250, 25));
        f_nombre_4->setFont(font1);
        f_nombre_4->setReadOnly(false);

        horizontalLayout_8->addWidget(f_nombre_4);

        horizontalLayoutWidget_9 = new QWidget(groupBox_2);
        horizontalLayoutWidget_9->setObjectName(QString::fromUtf8("horizontalLayoutWidget_9"));
        horizontalLayoutWidget_9->setGeometry(QRect(10, 50, 881, 31));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_9);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_34 = new QLabel(horizontalLayoutWidget_9);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        horizontalLayout_9->addWidget(label_34);

        f_curso_2 = new QLineEdit(horizontalLayoutWidget_9);
        f_curso_2->setObjectName(QString::fromUtf8("f_curso_2"));
        f_curso_2->setEnabled(true);
        f_curso_2->setMinimumSize(QSize(250, 25));
        f_curso_2->setMaximumSize(QSize(250, 16777215));
        f_curso_2->setFont(font1);
        f_curso_2->setReadOnly(true);

        horizontalLayout_9->addWidget(f_curso_2);

        label_36 = new QLabel(horizontalLayoutWidget_9);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        horizontalLayout_9->addWidget(label_36);

        f_nivel = new QLineEdit(horizontalLayoutWidget_9);
        f_nivel->setObjectName(QString::fromUtf8("f_nivel"));
        f_nivel->setMinimumSize(QSize(0, 25));
        f_nivel->setMaximumSize(QSize(50, 16777215));
        f_nivel->setFont(font1);

        horizontalLayout_9->addWidget(f_nivel);

        label_5 = new QLabel(horizontalLayoutWidget_9);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_9->addWidget(label_5);

        f_seccion_2 = new QLineEdit(horizontalLayoutWidget_9);
        f_seccion_2->setObjectName(QString::fromUtf8("f_seccion_2"));
        f_seccion_2->setMinimumSize(QSize(0, 25));
        f_seccion_2->setMaximumSize(QSize(100, 16777215));
        f_seccion_2->setFont(font1);
        f_seccion_2->setReadOnly(true);

        horizontalLayout_9->addWidget(f_seccion_2);

        label_37 = new QLabel(horizontalLayoutWidget_9);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        horizontalLayout_9->addWidget(label_37);

        f_turno = new QLineEdit(horizontalLayoutWidget_9);
        f_turno->setObjectName(QString::fromUtf8("f_turno"));
        f_turno->setMinimumSize(QSize(0, 25));
        f_turno->setMaximumSize(QSize(16777215, 16777215));
        f_turno->setFont(font1);
        f_turno->setReadOnly(true);

        horizontalLayout_9->addWidget(f_turno);

        horizontalLayoutWidget_2 = new QWidget(groupBox_2);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 80, 881, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_33 = new QLabel(horizontalLayoutWidget_2);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        horizontalLayout_2->addWidget(label_33);

        f_condicion_2 = new QLineEdit(horizontalLayoutWidget_2);
        f_condicion_2->setObjectName(QString::fromUtf8("f_condicion_2"));
        f_condicion_2->setMinimumSize(QSize(0, 25));
        f_condicion_2->setFont(font1);
        f_condicion_2->setReadOnly(true);

        horizontalLayout_2->addWidget(f_condicion_2);

        label_6 = new QLabel(horizontalLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        f_cond_esp = new QLineEdit(horizontalLayoutWidget_2);
        f_cond_esp->setObjectName(QString::fromUtf8("f_cond_esp"));
        f_cond_esp->setMinimumSize(QSize(0, 25));
        f_cond_esp->setFont(font1);

        horizontalLayout_2->addWidget(f_cond_esp);

        groupBox = new QGroupBox(form);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(9, 140, 901, 101));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(780, 0));
        groupBox->setMaximumSize(QSize(1000, 135));
        groupBox->setFont(font);
        horizontalLayoutWidget_10 = new QWidget(groupBox);
        horizontalLayoutWidget_10->setObjectName(QString::fromUtf8("horizontalLayoutWidget_10"));
        horizontalLayoutWidget_10->setGeometry(QRect(10, 30, 881, 31));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_10);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_39 = new QLabel(horizontalLayoutWidget_10);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setMinimumSize(QSize(70, 0));
        label_39->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_11->addWidget(label_39);

        f_cedula_5 = new QLineEdit(horizontalLayoutWidget_10);
        f_cedula_5->setObjectName(QString::fromUtf8("f_cedula_5"));
        f_cedula_5->setMinimumSize(QSize(120, 25));
        f_cedula_5->setMaximumSize(QSize(70, 16777215));
        f_cedula_5->setFont(font1);
        f_cedula_5->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_11->addWidget(f_cedula_5);

        label_40 = new QLabel(horizontalLayoutWidget_10);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setMinimumSize(QSize(110, 0));
        label_40->setMaximumSize(QSize(16777215, 16777215));
        label_40->setTextFormat(Qt::RichText);

        horizontalLayout_11->addWidget(label_40);

        f_nombre_5 = new QLineEdit(horizontalLayoutWidget_10);
        f_nombre_5->setObjectName(QString::fromUtf8("f_nombre_5"));
        f_nombre_5->setMinimumSize(QSize(250, 25));
        f_nombre_5->setFont(font1);
        f_nombre_5->setFocusPolicy(Qt::StrongFocus);
        f_nombre_5->setReadOnly(false);

        horizontalLayout_11->addWidget(f_nombre_5);

        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 60, 881, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        f_direccion = new QLineEdit(horizontalLayoutWidget);
        f_direccion->setObjectName(QString::fromUtf8("f_direccion"));
        f_direccion->setMinimumSize(QSize(0, 25));
        f_direccion->setFont(font1);

        horizontalLayout->addWidget(f_direccion);

        label_41 = new QLabel(horizontalLayoutWidget);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(label_41);

        f_telf_3 = new QLineEdit(horizontalLayoutWidget);
        f_telf_3->setObjectName(QString::fromUtf8("f_telf_3"));
        f_telf_3->setMinimumSize(QSize(100, 25));
        f_telf_3->setMaximumSize(QSize(70, 16777215));
        f_telf_3->setFont(font1);
        f_telf_3->setFocusPolicy(Qt::StrongFocus);
        f_telf_3->setReadOnly(false);

        horizontalLayout->addWidget(f_telf_3);

        f_same = new QCheckBox(groupBox);
        f_same->setObjectName(QString::fromUtf8("f_same"));
        f_same->setGeometry(QRect(800, 10, 91, 20));
        groupBox_3 = new QGroupBox(form);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(9, 250, 961, 81));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMinimumSize(QSize(780, 0));
        groupBox_3->setMaximumSize(QSize(1000, 100));
        groupBox_3->setFont(font);
        gridLayoutWidget_2 = new QWidget(groupBox_3);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 20, 940, 51));
        f_grid2_2 = new QGridLayout(gridLayoutWidget_2);
        f_grid2_2->setObjectName(QString::fromUtf8("f_grid2_2"));
        f_grid2_2->setSizeConstraint(QLayout::SetMinAndMaxSize);
        f_grid2_2->setHorizontalSpacing(3);
        f_grid2_2->setVerticalSpacing(6);
        f_grid2_2->setContentsMargins(0, 0, 0, 0);
        label_42 = new QLabel(gridLayoutWidget_2);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setMinimumSize(QSize(0, 15));
        label_42->setMaximumSize(QSize(50, 20));
        label_42->setAlignment(Qt::AlignCenter);

        f_grid2_2->addWidget(label_42, 0, 6, 1, 1);

        label_43 = new QLabel(gridLayoutWidget_2);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setMinimumSize(QSize(0, 15));
        label_43->setMaximumSize(QSize(50, 20));
        label_43->setAlignment(Qt::AlignCenter);

        f_grid2_2->addWidget(label_43, 0, 5, 1, 1);

        label_44 = new QLabel(gridLayoutWidget_2);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setMinimumSize(QSize(50, 15));
        label_44->setMaximumSize(QSize(50, 20));
        label_44->setAlignment(Qt::AlignCenter);

        f_grid2_2->addWidget(label_44, 0, 4, 1, 1);

        label_45 = new QLabel(gridLayoutWidget_2);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setMinimumSize(QSize(300, 15));
        label_45->setMaximumSize(QSize(300, 20));
        label_45->setAlignment(Qt::AlignCenter);

        f_grid2_2->addWidget(label_45, 0, 3, 1, 1);

        label_46 = new QLabel(gridLayoutWidget_2);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setMinimumSize(QSize(120, 15));
        label_46->setMaximumSize(QSize(120, 20));
        label_46->setAlignment(Qt::AlignCenter);

        f_grid2_2->addWidget(label_46, 0, 0, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(180, 15));
        label->setMaximumSize(QSize(180, 20));
        label->setAlignment(Qt::AlignCenter);

        f_grid2_2->addWidget(label, 0, 2, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(100, 15));
        label_4->setMaximumSize(QSize(100, 20));
        label_4->setAlignment(Qt::AlignCenter);

        f_grid2_2->addWidget(label_4, 0, 1, 1, 1);

        tp = new QComboBox(gridLayoutWidget_2);
        tp->setObjectName(QString::fromUtf8("tp"));
        tp->setMinimumSize(QSize(120, 25));
        tp->setMaximumSize(QSize(120, 16777215));
        tp->setFont(font1);

        f_grid2_2->addWidget(tp, 1, 0, 1, 1);

        metodo = new QComboBox(gridLayoutWidget_2);
        metodo->setObjectName(QString::fromUtf8("metodo"));
        metodo->setMinimumSize(QSize(100, 25));
        metodo->setMaximumSize(QSize(100, 16777215));
        metodo->setFont(font1);

        f_grid2_2->addWidget(metodo, 1, 1, 1, 1);

        item = new QComboBox(gridLayoutWidget_2);
        item->setObjectName(QString::fromUtf8("item"));
        item->setMinimumSize(QSize(180, 25));
        item->setMaximumSize(QSize(180, 16777215));
        item->setFont(font1);

        f_grid2_2->addWidget(item, 1, 2, 1, 1);

        descripcion = new QLineEdit(gridLayoutWidget_2);
        descripcion->setObjectName(QString::fromUtf8("descripcion"));
        descripcion->setMinimumSize(QSize(350, 25));
        descripcion->setMaximumSize(QSize(300, 16777215));
        descripcion->setFont(font1);

        f_grid2_2->addWidget(descripcion, 1, 3, 1, 1);

        cantidad = new QLineEdit(gridLayoutWidget_2);
        cantidad->setObjectName(QString::fromUtf8("cantidad"));
        cantidad->setMinimumSize(QSize(50, 25));
        cantidad->setMaximumSize(QSize(50, 16777215));
        cantidad->setFont(font1);

        f_grid2_2->addWidget(cantidad, 1, 4, 1, 1);

        precio = new QLineEdit(gridLayoutWidget_2);
        precio->setObjectName(QString::fromUtf8("precio"));
        precio->setMinimumSize(QSize(50, 25));
        precio->setMaximumSize(QSize(50, 16777215));
        precio->setFont(font1);

        f_grid2_2->addWidget(precio, 1, 5, 1, 1);

        bs = new QLineEdit(gridLayoutWidget_2);
        bs->setObjectName(QString::fromUtf8("bs"));
        bs->setMinimumSize(QSize(50, 25));
        bs->setMaximumSize(QSize(50, 16777215));
        bs->setFont(font1);

        f_grid2_2->addWidget(bs, 1, 6, 1, 1);

        f_tabla = new QTableWidget(form);
        if (f_tabla->columnCount() < 6)
            f_tabla->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        f_tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        f_tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        f_tabla->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        f_tabla->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        f_tabla->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        f_tabla->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        f_tabla->setObjectName(QString::fromUtf8("f_tabla"));
        f_tabla->setGeometry(QRect(9, 340, 901, 192));
        sizePolicy.setHeightForWidth(f_tabla->sizePolicy().hasHeightForWidth());
        f_tabla->setSizePolicy(sizePolicy);
        f_tabla->setMinimumSize(QSize(891, 192));
        f_tabla->setMaximumSize(QSize(1000, 192));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        f_tabla->setFont(font2);
        f_tabla->setGridStyle(Qt::SolidLine);
        f_datos = new QGroupBox(form);
        f_datos->setObjectName(QString::fromUtf8("f_datos"));
        f_datos->setGeometry(QRect(9, 640, 901, 101));
        sizePolicy.setHeightForWidth(f_datos->sizePolicy().hasHeightForWidth());
        f_datos->setSizePolicy(sizePolicy);
        f_datos->setMinimumSize(QSize(780, 0));
        f_datos->setMaximumSize(QSize(1000, 1000));
        f_datos->setFont(font);
        layoutWidget_5 = new QWidget(f_datos);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 30, 881, 61));
        f_grid_2 = new QGridLayout(layoutWidget_5);
        f_grid_2->setObjectName(QString::fromUtf8("f_grid_2"));
        f_grid_2->setSizeConstraint(QLayout::SetNoConstraint);
        f_grid_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 15));
        label_7->setMaximumSize(QSize(16777215, 20));
        label_7->setAlignment(Qt::AlignCenter);

        f_grid_2->addWidget(label_7, 0, 1, 1, 1);

        label_8 = new QLabel(layoutWidget_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 15));
        label_8->setMaximumSize(QSize(16777215, 20));
        label_8->setAlignment(Qt::AlignCenter);

        f_grid_2->addWidget(label_8, 0, 2, 1, 1);

        label_49 = new QLabel(layoutWidget_5);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setMinimumSize(QSize(0, 15));
        label_49->setMaximumSize(QSize(16777215, 20));
        label_49->setAlignment(Qt::AlignCenter);

        f_grid_2->addWidget(label_49, 0, 3, 1, 1);

        label_50 = new QLabel(layoutWidget_5);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setMinimumSize(QSize(0, 15));
        label_50->setMaximumSize(QSize(16777215, 20));
        label_50->setAlignment(Qt::AlignCenter);

        f_grid_2->addWidget(label_50, 0, 4, 1, 1);

        label_51 = new QLabel(layoutWidget_5);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setMinimumSize(QSize(0, 15));
        label_51->setMaximumSize(QSize(16777215, 20));
        label_51->setAlignment(Qt::AlignCenter);

        f_grid_2->addWidget(label_51, 0, 0, 1, 1);

        fechas = new QDateEdit(layoutWidget_5);
        fechas->setObjectName(QString::fromUtf8("fechas"));
        fechas->setMinimumSize(QSize(0, 25));
        fechas->setFont(font1);

        f_grid_2->addWidget(fechas, 1, 0, 1, 1);

        detallespago = new QComboBox(layoutWidget_5);
        detallespago->setObjectName(QString::fromUtf8("detallespago"));
        detallespago->setMinimumSize(QSize(200, 25));
        detallespago->setMaximumSize(QSize(120, 16777215));
        detallespago->setFont(font1);

        f_grid_2->addWidget(detallespago, 1, 1, 1, 1);

        detallesbanco = new QComboBox(layoutWidget_5);
        detallesbanco->setObjectName(QString::fromUtf8("detallesbanco"));
        detallesbanco->setMinimumSize(QSize(300, 25));
        detallesbanco->setMaximumSize(QSize(240, 16777215));
        detallesbanco->setFont(font1);

        f_grid_2->addWidget(detallesbanco, 1, 2, 1, 1);

        referencias = new QLineEdit(layoutWidget_5);
        referencias->setObjectName(QString::fromUtf8("referencias"));
        referencias->setMinimumSize(QSize(150, 25));
        referencias->setMaximumSize(QSize(150, 16777215));
        referencias->setFont(font1);

        f_grid_2->addWidget(referencias, 1, 3, 1, 1);

        montos = new QLineEdit(layoutWidget_5);
        montos->setObjectName(QString::fromUtf8("montos"));
        montos->setMinimumSize(QSize(100, 25));
        montos->setMaximumSize(QSize(100, 16777215));
        montos->setFont(font1);

        f_grid_2->addWidget(montos, 1, 4, 1, 1);

        f_postpago = new QCheckBox(f_datos);
        f_postpago->setObjectName(QString::fromUtf8("f_postpago"));
        f_postpago->setGeometry(QRect(770, 10, 131, 20));
        f_tabla0 = new QTableWidget(form);
        if (f_tabla0->columnCount() < 5)
            f_tabla0->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        f_tabla0->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        f_tabla0->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        f_tabla0->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        f_tabla0->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        f_tabla0->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        f_tabla0->setObjectName(QString::fromUtf8("f_tabla0"));
        f_tabla0->setEnabled(true);
        f_tabla0->setGeometry(QRect(9, 750, 901, 100));
        sizePolicy.setHeightForWidth(f_tabla0->sizePolicy().hasHeightForWidth());
        f_tabla0->setSizePolicy(sizePolicy);
        f_tabla0->setMinimumSize(QSize(780, 100));
        f_tabla0->setMaximumSize(QSize(1000, 100));
        f_tabla0->setFont(font2);
        horizontalLayoutWidget_3 = new QWidget(form);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 860, 901, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        f_quitar2 = new QPushButton(horizontalLayoutWidget_3);
        f_quitar2->setObjectName(QString::fromUtf8("f_quitar2"));
        f_quitar2->setMinimumSize(QSize(0, 25));
        f_quitar2->setFont(font);

        horizontalLayout_3->addWidget(f_quitar2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        layoutWidget_2 = new QWidget(form);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 540, 91, 31));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        f_quitar = new QPushButton(layoutWidget_2);
        f_quitar->setObjectName(QString::fromUtf8("f_quitar"));
        f_quitar->setMinimumSize(QSize(0, 25));
        f_quitar->setFont(font);

        horizontalLayout_10->addWidget(f_quitar);

        layoutWidget = new QWidget(form);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(810, 540, 92, 91));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        f_subtotal_2 = new QLineEdit(layoutWidget);
        f_subtotal_2->setObjectName(QString::fromUtf8("f_subtotal_2"));
        f_subtotal_2->setMinimumSize(QSize(90, 25));
        f_subtotal_2->setMaximumSize(QSize(90, 25));
        f_subtotal_2->setFont(font2);
        f_subtotal_2->setReadOnly(true);

        verticalLayout->addWidget(f_subtotal_2);

        f_iva_2 = new QLineEdit(layoutWidget);
        f_iva_2->setObjectName(QString::fromUtf8("f_iva_2"));
        f_iva_2->setMinimumSize(QSize(90, 25));
        f_iva_2->setMaximumSize(QSize(90, 25));
        f_iva_2->setFont(font2);
        f_iva_2->setReadOnly(true);

        verticalLayout->addWidget(f_iva_2);

        f_total_2 = new QLineEdit(layoutWidget);
        f_total_2->setObjectName(QString::fromUtf8("f_total_2"));
        f_total_2->setMinimumSize(QSize(90, 25));
        f_total_2->setMaximumSize(QSize(90, 25));
        f_total_2->setFont(font2);
        f_total_2->setReadOnly(true);

        verticalLayout->addWidget(f_total_2);

        layoutWidget1 = new QWidget(form);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(680, 540, 122, 91));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_38 = new QLabel(layoutWidget1);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setMinimumSize(QSize(120, 0));
        label_38->setFont(font);
        label_38->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_38);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_47 = new QLabel(layoutWidget1);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setMinimumSize(QSize(32, 0));
        label_47->setFont(font);
        label_47->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_47);

        f_piva_2 = new QLineEdit(layoutWidget1);
        f_piva_2->setObjectName(QString::fromUtf8("f_piva_2"));
        f_piva_2->setEnabled(false);
        f_piva_2->setMinimumSize(QSize(0, 25));
        f_piva_2->setMaximumSize(QSize(30, 16777215));
        f_piva_2->setFont(font2);

        horizontalLayout_4->addWidget(f_piva_2);

        label_48 = new QLabel(layoutWidget1);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setFont(font);

        horizontalLayout_4->addWidget(label_48);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label_30 = new QLabel(layoutWidget1);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setMinimumSize(QSize(120, 0));
        label_30->setFont(font);
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_30);


        retranslateUi(form);

        QMetaObject::connectSlotsByName(form);
    } // setupUi

    void retranslateUi(QWidget *form)
    {
        form->setWindowTitle(QApplication::translate("form", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("form", "Datos del Participante", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("form", "Matricula", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("form", "Cedula", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("form", "Nombre", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("form", "Curso", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("form", "Nivel", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("form", "Seccion", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("form", "Modalidad", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("form", "Condicion", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("form", "Condicion Especial", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("form", "Datos del Cliente", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("form", "Cedula / RIF", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("form", "Nombre / Raz\303\263n Social", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("form", "Direcci\303\263n", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("form", "Telefono", 0, QApplication::UnicodeUTF8));
        f_same->setText(QApplication::translate("form", "Participante", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("form", "Detalle de la Factura", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("form", "Total", 0, QApplication::UnicodeUTF8));
        label_43->setText(QApplication::translate("form", "Precio", 0, QApplication::UnicodeUTF8));
        label_44->setText(QApplication::translate("form", "Cantidad", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("form", "Descripcion", 0, QApplication::UnicodeUTF8));
        label_46->setText(QApplication::translate("form", "Tipo", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("form", "Item", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("form", "M\303\251todo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = f_tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("form", "Tipo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = f_tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("form", "Item", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = f_tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("form", "Descripcion", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = f_tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("form", "Cantidad", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = f_tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("form", "Precio", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = f_tabla->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("form", "Total", 0, QApplication::UnicodeUTF8));
        f_datos->setTitle(QApplication::translate("form", "Datos del Pago", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("form", "Forma de Pago", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("form", "Banco", 0, QApplication::UnicodeUTF8));
        label_49->setText(QApplication::translate("form", "Referencia", 0, QApplication::UnicodeUTF8));
        label_50->setText(QApplication::translate("form", "Monto", 0, QApplication::UnicodeUTF8));
        label_51->setText(QApplication::translate("form", "Emision", 0, QApplication::UnicodeUTF8));
        f_postpago->setText(QApplication::translate("form", "Factura Proforma", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = f_tabla0->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("form", "Emision", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = f_tabla0->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("form", "Forma de Pago", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = f_tabla0->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("form", "Banco", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = f_tabla0->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("form", "Referencia", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = f_tabla0->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("form", "Monto", 0, QApplication::UnicodeUTF8));
        f_quitar2->setText(QApplication::translate("form", "Eliminar Item", 0, QApplication::UnicodeUTF8));
        f_quitar->setText(QApplication::translate("form", "Eliminar Item", 0, QApplication::UnicodeUTF8));
        f_subtotal_2->setText(QApplication::translate("form", "0", 0, QApplication::UnicodeUTF8));
        f_total_2->setText(QApplication::translate("form", "0", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("form", "Subtotal", 0, QApplication::UnicodeUTF8));
        label_47->setText(QApplication::translate("form", "I.V.A.", 0, QApplication::UnicodeUTF8));
        f_piva_2->setText(QApplication::translate("form", "0", 0, QApplication::UnicodeUTF8));
        label_48->setText(QApplication::translate("form", "%", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("form", "Total a Cancelar Bs.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class form: public Ui_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACTURA_H
