/********************************************************************************
** Form generated from reading UI file 'precios.ui'
**
** Created: Fri 30. May 09:27:18 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRECIOS_H
#define UI_PRECIOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDateEdit>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_precios
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tabla;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QDateEdit *p_fecha;
    QLabel *label_4;
    QCheckBox *p_arancel;
    QCheckBox *p_cd;
    QCheckBox *p_constancia;
    QCheckBox *p_boleta;
    QCheckBox *p_curso;
    QCheckBox *p_descuento;
    QCheckBox *p_examen;
    QCheckBox *p_factura;
    QCheckBox *p_guia;
    QCheckBox *p_libro;
    QCheckBox *p_matricula;
    QCheckBox *p_otro;

    void setupUi(QWidget *precios)
    {
        if (precios->objectName().isEmpty())
            precios->setObjectName(QString::fromUtf8("precios"));
        precios->resize(847, 644);
        verticalLayout_2 = new QVBoxLayout(precios);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(precios);
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

        verticalLayout_2->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabla = new QTableWidget(precios);
        if (tabla->columnCount() < 5)
            tabla->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        tabla->setFont(font1);

        horizontalLayout->addWidget(tabla);

        groupBox_2 = new QGroupBox(precios);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 0));
        label_5->setMaximumSize(QSize(16777215, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        label_5->setFont(font2);

        verticalLayout->addWidget(label_5);

        p_fecha = new QDateEdit(groupBox_2);
        p_fecha->setObjectName(QString::fromUtf8("p_fecha"));
        p_fecha->setMinimumSize(QSize(0, 25));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(9);
        p_fecha->setFont(font3);

        verticalLayout->addWidget(p_fecha);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(16777215, 25));
        label_4->setFont(font2);

        verticalLayout->addWidget(label_4);

        p_arancel = new QCheckBox(groupBox_2);
        p_arancel->setObjectName(QString::fromUtf8("p_arancel"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Segoe UI"));
        font4.setPointSize(10);
        p_arancel->setFont(font4);

        verticalLayout->addWidget(p_arancel);

        p_cd = new QCheckBox(groupBox_2);
        p_cd->setObjectName(QString::fromUtf8("p_cd"));
        p_cd->setFont(font4);

        verticalLayout->addWidget(p_cd);

        p_constancia = new QCheckBox(groupBox_2);
        p_constancia->setObjectName(QString::fromUtf8("p_constancia"));
        p_constancia->setFont(font4);

        verticalLayout->addWidget(p_constancia);

        p_boleta = new QCheckBox(groupBox_2);
        p_boleta->setObjectName(QString::fromUtf8("p_boleta"));
        p_boleta->setFont(font4);

        verticalLayout->addWidget(p_boleta);

        p_curso = new QCheckBox(groupBox_2);
        p_curso->setObjectName(QString::fromUtf8("p_curso"));
        p_curso->setFont(font4);

        verticalLayout->addWidget(p_curso);

        p_descuento = new QCheckBox(groupBox_2);
        p_descuento->setObjectName(QString::fromUtf8("p_descuento"));
        p_descuento->setFont(font4);

        verticalLayout->addWidget(p_descuento);

        p_examen = new QCheckBox(groupBox_2);
        p_examen->setObjectName(QString::fromUtf8("p_examen"));
        p_examen->setFont(font4);

        verticalLayout->addWidget(p_examen);

        p_factura = new QCheckBox(groupBox_2);
        p_factura->setObjectName(QString::fromUtf8("p_factura"));
        p_factura->setFont(font4);

        verticalLayout->addWidget(p_factura);

        p_guia = new QCheckBox(groupBox_2);
        p_guia->setObjectName(QString::fromUtf8("p_guia"));
        p_guia->setFont(font4);

        verticalLayout->addWidget(p_guia);

        p_libro = new QCheckBox(groupBox_2);
        p_libro->setObjectName(QString::fromUtf8("p_libro"));
        p_libro->setFont(font4);

        verticalLayout->addWidget(p_libro);

        p_matricula = new QCheckBox(groupBox_2);
        p_matricula->setObjectName(QString::fromUtf8("p_matricula"));
        p_matricula->setFont(font4);

        verticalLayout->addWidget(p_matricula);

        p_otro = new QCheckBox(groupBox_2);
        p_otro->setObjectName(QString::fromUtf8("p_otro"));
        p_otro->setFont(font4);

        verticalLayout->addWidget(p_otro);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(precios);

        QMetaObject::connectSlotsByName(precios);
    } // setupUi

    void retranslateUi(QWidget *precios)
    {
        precios->setWindowTitle(QApplication::translate("precios", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("precios", "Precios", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("precios", "Id", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("precios", "Descripcion", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("precios", "Precio", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("precios", "Noct./Sab.", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("precios", "Base Descuento", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        label_5->setText(QApplication::translate("precios", "Fecha de Vigencia", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("precios", "Items", 0, QApplication::UnicodeUTF8));
        p_arancel->setText(QApplication::translate("precios", "Aranceles", 0, QApplication::UnicodeUTF8));
        p_cd->setText(QApplication::translate("precios", "CD's", 0, QApplication::UnicodeUTF8));
        p_constancia->setText(QApplication::translate("precios", "Constancias", 0, QApplication::UnicodeUTF8));
        p_boleta->setText(QApplication::translate("precios", "Control de notas", 0, QApplication::UnicodeUTF8));
        p_curso->setText(QApplication::translate("precios", "Cursos", 0, QApplication::UnicodeUTF8));
        p_descuento->setText(QApplication::translate("precios", "Descuentos", 0, QApplication::UnicodeUTF8));
        p_examen->setText(QApplication::translate("precios", "Examenes", 0, QApplication::UnicodeUTF8));
        p_factura->setText(QApplication::translate("precios", "Facturas", 0, QApplication::UnicodeUTF8));
        p_guia->setText(QApplication::translate("precios", "Guias", 0, QApplication::UnicodeUTF8));
        p_libro->setText(QApplication::translate("precios", "Libros", 0, QApplication::UnicodeUTF8));
        p_matricula->setText(QApplication::translate("precios", "Matriculas", 0, QApplication::UnicodeUTF8));
        p_otro->setText(QApplication::translate("precios", "Otros", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class precios: public Ui_precios {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRECIOS_H
