/*
 * procesos_caja.cpp
 *
 *  Created on: 12/03/2009
 *      Author: Oriana Gómez.
 */

#include "procesos_caja.h"



/** Constructor de la clase. Inicializa algunas variables y carga la barra de herramientas.
 * @param prog Indica el programa al que pertenece el usuario que acaba de iniciar sesion.
 * @param user Indica el nombre del usuario que acaba de iniciar sesion.
 *
 * @return
*/

procesos_caja::procesos_caja(QString prog,QString user,QSqlDatabase db,QSqlDatabase db2,QWidget *parent): QWidget(parent)
{
    compania=prog;
    usuario=user;
    container.setupUi(this);
    database = db;
    mysql=db2;
    report= new NCReport();
    QSqlQuery consulta("select nombre from usuarios where nombre_usuario='"+user+"'");
    while(consulta.next())
    {
        container.etiqueta->setText(consulta.value(0).toString());
    }
}

/** Crea y muestra un dialogo para seleccionar el programa academico en el que se va a facturar
*/

void procesos_caja::seleccionProgramaAcademico()
{
    dialogo = new QWidget();
    sel_programa = new QComboBox();
    QPushButton *ok = new QPushButton(tr("Aceptar"),this);
    connect(ok,SIGNAL(clicked()),this,SLOT(seleccionPA()));
    QLabel *titulo = new QLabel(tr("Programa Academico"));
    QVBoxLayout *v = new QVBoxLayout();
    QSqlQuery consulta("select descripcion from programa_academico order by id");
    while(consulta.next())
    {
        sel_programa->addItem(consulta.value(0).toString());
    }
    v->addWidget(titulo);
    v->addWidget(sel_programa);
    v->addWidget(ok);

    dialogo->setWindowModality(Qt::ApplicationModal);
    dialogo->setLayout(v);
    dialogo->resize(270,60);
    dialogo->move(500,200);
    dialogo->show();
}



/** Una vez seleccionado el programa academico, se inicializa el listado de tipos de material de
 * acuerdo con el mismo.
*/

void procesos_caja::seleccionPA()
{
    int indice = sel_programa->currentIndex();
    QSqlQuery consulta;

    consulta.exec("select codigo from companias where id='"+compania+"'");
    while(consulta.next())
    {
        programa=consulta.value(0).toString();
    }
    switch(indice)
    {
        case 0://IDIOMAS NIÑOS
        {
            //Selecciono materiales asociados a idiomas excepto ingresos diferidos.
            consulta.exec("select descripcion from tipo_material where idiomas='S' and abrev<>'IP' and abrev<>'IN' order by descripcion");
            tipo_item.clear();
            tipo_item.append("-");
            while(consulta.next())
            {
                tipo_item.append(consulta.value(0).toString());
            }
        }
        break;
        case 1://IDIOMAS MODERNOS
        {
            //Selecciono materiales asociados a idiomas excepto ingresos diferidos
            consulta.exec("select descripcion from tipo_material where idiomas='S' and abrev<>'IP' and abrev<>'IN' order by descripcion");
            tipo_item.clear();
            tipo_item.append("-");
            while(consulta.next())
            {
                tipo_item.append(consulta.value(0).toString());
            }
        }
        break;
        case 4://COMPUTACION
        {
            consulta.exec("select descripcion from tipo_material where ctc='S' and abrev<>'IP' and abrev<>'IN' order by descripcion");
            tipo_item.clear();
            tipo_item.append("-");
            while(consulta.next())
            {
                tipo_item.append(consulta.value(0).toString());
            }
        }
        break;
        case 2://CAPACITACION Y FORMACION PROFESIONAL
        {
            consulta.exec("select descripcion from tipo_material where cfp='S' and abrev<>'IP' and abrev<>'IN' order by descripcion");
            tipo_item.clear();
            tipo_item.append("-");
            while(consulta.next())
            {
                tipo_item.append(consulta.value(0).toString());
            }
        }
        break;
        case 3://FUNDAUC VA A TU COLEGIO
        {
            consulta.exec("select descripcion from tipo_material where fvtc='S' and abrev<>'IP' and abrev<>'IN' order by descripcion");
            tipo_item.clear();
            tipo_item.append("-");
            while(consulta.next())
            {
                tipo_item.append(consulta.value(0).toString());
            }
        }
        break;
        case 5://INGRESOS DE DIRECCION CENTRAL
        {
            consulta.exec("select descripcion from tipo_material where abrev='O'");
            tipo_item.clear();
            tipo_item.append("-");
            while(consulta.next())
            {
                tipo_item.append(consulta.value(0).toString());
            }
        }
    }
    prog_academico.setNum(indice+1);
    facturaSetup();//Llamo a la configuracion del formulario de factura
    dialogo->close();
}


/** Crea y muestra un dialogo para seleccionar el tipo de factura a crear (Particular/Empresa)
*/

void procesos_caja::seleccionTipoFactura()
{
    dialogo2 = new QWidget();
    sel_tipo = new QComboBox();
    QPushButton *ok = new QPushButton(tr("Aceptar"),this);
    connect(ok,SIGNAL(clicked()),this,SLOT(seleccionTF()));

    QLabel *titulo = new QLabel(tr("Factura para:"));
    QVBoxLayout *v = new QVBoxLayout();
    sel_tipo->addItem("PARTICULAR");
    sel_tipo->addItem("EMPRESA");
    v->addWidget(titulo);
    v->addWidget(sel_tipo);
    v->addWidget(ok);

    dialogo2->setWindowModality(Qt::ApplicationModal);
    dialogo2->setLayout(v);
    dialogo2->resize(270,60);
    dialogo2->move(500,200);
    dialogo2->show();
}


/** Una vez seleccionado el tipo de factura, se inicializa la variable que lo indicará.
*/

void procesos_caja::seleccionTF()
{
    int indice = sel_tipo->currentIndex(); //0-> Particular 1->Empresa

    tipo_factura=indice+1;
    dialogo2->close();
}


/** Muestra el formulario de creacion de facturas e inicializa y configura sus componentes.
*/

void procesos_caja::nuevaFactura()
{
    frame = new QFrame();
    factura.setupUi(frame);
    container.workspace->setWidget(frame);
    depositoSetup();
    proforma=false;
    f_curso="";
    f_seccion="";
    factura.f_tabla0->setColumnWidth(0,80);
    factura.f_tabla0->setColumnWidth(1,200);
    factura.f_tabla0->setColumnWidth(2,300);
    factura.f_tabla0->setColumnWidth(3,150);
    factura.f_tabla0->setColumnWidth(4,100);

    factura.f_tabla->setColumnWidth(0,50);
    factura.f_tabla->setColumnWidth(1,100);
    factura.f_tabla->setColumnWidth(2,500);
    factura.f_tabla->setColumnWidth(3,70);
    factura.f_tabla->setColumnWidth(4,70);
    factura.f_tabla->setColumnWidth(5,70);

    connect(factura.f_nombre_4,SIGNAL(returnPressed()),this,SLOT(nombreChanged()));
    connect(factura.f_cedula_4,SIGNAL(returnPressed()),this,SLOT(cedulaChanged()));
    connect(factura.f_cedula_5,SIGNAL(returnPressed()),this,SLOT(rifChanged()));
    connect(factura.f_nombre_5,SIGNAL(returnPressed()),this,SLOT(razonChanged()));
    connect(factura.f_matricula,SIGNAL(returnPressed()),this,SLOT(matriculaChanged()));
    connect(factura.f_piva_2,SIGNAL(textChanged(const QString)),this,SLOT(ivaChanged(const QString)));
    connect(factura.f_same,SIGNAL(clicked(bool)),this,SLOT(sameAsParticipant(bool)));
    connect(factura.f_postpago,SIGNAL(clicked(bool)),this,SLOT(facturaProforma(bool)));
    connect(factura.f_nombre_5,SIGNAL(textChanged(const QString)),this,SLOT(toUpper(const QString)));
    connect(factura.f_cedula_5,SIGNAL(textChanged(const QString)),this,SLOT(toUpper(const QString)));
    connect(factura.f_direccion,SIGNAL(textChanged(const QString)),this,SLOT(toUpper(const QString)));
    connect(factura.f_nombre_4,SIGNAL(textChanged(const QString)),this,SLOT(toUpper(const QString)));

    disconnect(container.botonImprimir,SIGNAL(clicked()),0,0);
    connect(container.botonImprimir,SIGNAL(clicked()),this,SLOT(imprimirFactura()));
    container.botonImprimir->setEnabled(true);

    seleccionProgramaAcademico();
    seleccionTipoFactura();
}


/** Toma el contenido de un QLineEdit y lo convierte en Mayusculas
*/
void procesos_caja::toUpper(QString s)
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    if (!le)
        return;
    le->setText(s.toUpper());
}


/** Muestra el modulo de registro de facturas e inicializa y configura sus componentes
*/

void procesos_caja::registroFacturas()
{
    frame = new QFrame();
    reg_factura.setupUi(frame);
    container.workspace->setWidget(frame);

    reg_factura.r_tabla->setColumnWidth(3,300);
    connect(reg_factura.r_factura,SIGNAL(clicked(bool)),this,SLOT(facturaSelect(bool)));
    connect(reg_factura.r_year,SIGNAL(clicked(bool)),this,SLOT(yearSelect(bool)));
    connect(reg_factura.r_empresa,SIGNAL(clicked(bool)),this,SLOT(rifSelect(bool)));
    connect(reg_factura.r_factura_edit,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_factura.r_factura_edit,SIGNAL(returnPressed()),this,SLOT(filtrarFact()));
    connect(reg_factura.r_rif,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_factura.r_rif,SIGNAL(returnPressed()),this,SLOT(filtrarEmpresa()));
    reg_factura.r_top->setDate(QDate::currentDate());
    reg_factura.r_bottom->setDate(QDate::currentDate());

    disconnect(container.botonAnular,SIGNAL(clicked()),0,0);
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(anularFactura()));
    disconnect(container.botonBuscar,SIGNAL(clicked()),0,0);
    connect(container.botonBuscar,SIGNAL(clicked()),this,SLOT(filtrarFecha()));
    container.botonImprimir->setEnabled(false);
    container.botonAnular->setEnabled(true);
    container.botonBuscar->setEnabled(true);
}


/** Muestra el modulo de registro de depositos e inicializa y configura sus componentes
*/
void procesos_caja::registroDepositos()
{
    frame = new QFrame();
    reg_deposito.setupUi(frame);
    container.workspace->setWidget(frame);

    reg_deposito.r_tabla->setColumnWidth(2,300);
    connect(reg_deposito.r_referencia,SIGNAL(clicked(bool)),this,SLOT(referenciaSelect(bool)));
    connect(reg_deposito.r_year,SIGNAL(clicked(bool)),this,SLOT(yearSelect2(bool)));
    connect(reg_deposito.r_referencia_edit,SIGNAL(returnPressed()),this,SLOT(filtrarRef()));
    disconnect(container.botonBuscar,SIGNAL(clicked()),0,0);
    connect(container.botonBuscar,SIGNAL(clicked()),this,SLOT(filtrarFecha_Bancos()));
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoDeposito()));
    reg_deposito.r_top->setDate(QDate::currentDate());
    reg_deposito.r_bottom->setDate(QDate::currentDate());

    container.botonNuevo->setEnabled(true);
    container.botonBuscar->setEnabled(true);
}


/** Genera un dialogo para ingresar un deposito manualmente. Inicializa los combobox de: Programa academico, forma de pago y banco.
  */
void procesos_caja::nuevoDeposito()
{
    QSqlQuery consulta;
    QString aux;

    dialogo = new QWidget();
    new_deposito.setupUi(dialogo);

    new_deposito.prog->addItem("-");
    consulta.exec("select descripcion from programa_academico order by id");
    while(consulta.next())
    {
        new_deposito.prog->addItem(consulta.value(0).toString());
    }

    new_deposito.pago->addItem("-");
    consulta.exec("select descripcion from forma_pago order by id_pago");
    while(consulta.next())
    {
        new_deposito.pago->addItem(consulta.value(0).toString());
    }

    new_deposito.banco->addItem("-");
    consulta.exec("select nombre from bancos order by id_banco");
    while(consulta.next())
    {
        new_deposito.banco->addItem(consulta.value(0).toString());
    }

    new_deposito.fecha->setDate(QDate::currentDate());
    connect(new_deposito.guardar,SIGNAL(clicked()),this,SLOT(guardarDeposito()));
    dialogo->show();
}

/** Guarda un deposito manual en la tabla de control interno, en la tabla para exportar a Jupiter y la asocia a su numero de factura.
  */

void procesos_caja::guardarDeposito()
{
    QSqlQuery consulta;
    QString clase,banco,monto,pago;

    consulta.exec("select id from programa_academico where descripcion='"+new_deposito.prog->currentText()+"'");
    while(consulta.next())
    {
        prog_academico=consulta.value(0).toString();
    }

    consulta.exec("select id_banco from bancos where nombre='"+new_deposito.banco->currentText()+"'");
    while(consulta.next())
    {
        banco=consulta.value(0).toString();
    }

    consulta.exec("select id_pago from forma_pago where descripcion='"+new_deposito.pago->currentText()+"'");
    while(consulta.next())
    {
        pago=consulta.value(0).toString();
    }

    clase.setNum(determinarClaseDoc());//Clase de documento Jupiter por programa.

    if(!consulta.exec("insert into documentos_trf values('1','DP','"+clase+"','"+new_deposito.referencia->text()+"','B','"+banco+"','',to_date('"+new_deposito.fecha->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'','"+new_deposito.monto->text()+"','','"+usuario+"','','',to_date('"+new_deposito.fecha->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'','','','s','0','0','"+banco+"','','"+pago+"','','','','','','','','','"+new_deposito.factura->text()+"')"))
    {
        QMessageBox::critical(0,"Error Documentos Jupiter",consulta.lastError().text());
        return;
    }
    else
        consulta.exec("commit");

    if(!consulta.exec("insert into deposito values('"+new_deposito.referencia->text()+"',to_date('"+new_deposito.fecha->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+banco+"','"+new_deposito.monto->text()+"','"+compania+"','"+clase+"','"+usuario+"','s','"+pago+"','"+prog_academico+"')"))
    {
        QMessageBox::critical(0,"Error Deposito",consulta.lastError().text());
        return;
    }
    else
        consulta.exec("commit");

    if(!consulta.exec("insert into factura_deposito values('"+new_deposito.factura->text()+"','"+new_deposito.referencia->text()+"','"+banco+"','"+pago+"')"))
    {
        QMessageBox::critical(0,"Error Factura-Deposito",consulta.lastError().text());
        return;
    }
    else
    {
        consulta.exec("commit");
        dialogo->close();
    }
}


/** Crea y muestra un dialogo que permite seleccionar las fechas entre las cuales se generará la valija de ingresos
*/
void procesos_caja::mesValija()
{
    dialogo = new QWidget();
    top = new QDateEdit();
    bottom = new QDateEdit();
    QPushButton *ok = new QPushButton(tr("Aceptar"),this);
    connect(ok,SIGNAL(clicked()),this,SLOT(generarValija()));

    QLabel *label1,*label2;
    label1= new QLabel(tr("Desde:"));
    label2= new QLabel(tr("Hasta:"));
    QVBoxLayout *v = new QVBoxLayout();

    v->addWidget(label1);
    v->addWidget(top);
    v->addWidget(label2);
    v->addWidget(bottom);
    v->addWidget(ok);

    dialogo->setLayout(v);
    dialogo->resize(70,60);
    dialogo->move(500,200);
    dialogo->show();
}


/** Genera un archivo .dmp con el respaldo de los depositos en las fechas seleccionadas
*/

void procesos_caja::generarValija()
{
    FILE *aux;
    QFile file;
    QByteArray ba;
    QString query,desde,hasta;
    desde=top->date().toString("dd-MM-yyyy");
    hasta=bottom->date().toString("dd-MM-yyyy");

    aux = fopen("auxiliar.txt","wb+");
    if(file.open(aux,QIODevice::ReadWrite))
    {
        query="query=\"where dc_fecemi between to_date('"+desde+"','dd-MM-yyyy') and to_date('"+hasta+"','dd-MM-yyyy')\"";

        ba=QByteArray();
        ba.append(query);
        file.write(ba);
        file.close();
        fclose(aux);
        remove("script_valija.txt");
        rename("auxiliar.txt","script_valija.txt");
        dialogo->close();
    }
    system("valija.bat");
}


/** Muestra por pantalla el total de ingresos en un rango de fechas. Sólo para el director de programa.
*/

void procesos_caja::ingresosPeriodo()
{
    dialogo = new QWidget();
    per_dialog.setupUi(dialogo);
    per_dialog.fecha_ini->setDate(QDate::currentDate());
    per_dialog.fecha_fin->setDate(QDate::currentDate());
    connect(per_dialog.boton,SIGNAL(clicked()),this,SLOT(periodoChanged()));
    dialogo->show();
}


void procesos_caja::periodoChanged()
{
    QSqlQuery consulta;
    QString prog;

    consulta.exec("select prog_academico from usuarios where nombre_usuario='"+usuario+"'");
    while(consulta.next())
    {
        prog = consulta.value(0).toString();
    }

    if(prog!="3")
        consulta.exec("select sum(monto) from deposito where (referencia,id_banco) in (select referencia,id_banco from factura_deposito where id_fact in (select id_fact from factura where (prog_academico=1 or prog_academico=2) and fecha_emi between to_date('"+per_dialog.fecha_ini->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy') and to_date('"+per_dialog.fecha_fin->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy')))");
    else
        consulta.exec("select sum(monto) from deposito where (referencia,id_banco) in (select referencia,id_banco from factura_deposito where id_fact in (select id_fact from factura where prog_academico='"+prog+"' and fecha_emi between to_date('"+per_dialog.fecha_ini->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy') and to_date('"+per_dialog.fecha_fin->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy')))");

    while(consulta.next())
    {
        per_dialog.text->setText(consulta.value(0).toString());
    }
}


/** Permite la busqueda de un estudiante por nombre y muestra los resultados en un cuadro de dialogo al momento de elaborar factura.
  */
void procesos_caja::nombreChanged()
{
    QTableWidgetItem *ni;
    int row;
    dialogo = new QWidget();
    busqueda_dialog.setupUi(dialogo);
    dialogo->setWindowTitle("Resultados");
    busqueda_dialog.tabla->setColumnWidth(1,400);

    QSqlQuery consulta("select matricula,nombre,apellido from estudiante where (nombre like '%"+factura.f_nombre_4->text()+"%' or apellido like '%"+factura.f_nombre_4->text()+"%') order by nombre");
    while(consulta.next())
    {
        row = busqueda_dialog.tabla->rowCount();
        busqueda_dialog.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        busqueda_dialog.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()+" "+consulta.value(2).toString()));
        busqueda_dialog.tabla->setItem(row,1,ni);
    }
    connect(busqueda_dialog.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(llenarEstudiante(int,int)));
    dialogo->show();
}


/** Llena el encabezado de la factura con los datos del estudiante cuando este es seleccionado despues de una busqueda por nombre.
  */

void procesos_caja::llenarEstudiante(int row,int column)
{
    QSqlQuery consulta,consulta2;

    factura.f_nombre_4->clear();
    factura.f_condicion_2->clear();
    factura.f_matricula->clear();
    factura.f_direccion->clear();
    factura.f_seccion_2->clear();
    factura.f_curso_2->clear();
    factura.f_turno->clear();
    factura.f_nivel->clear();

    consulta.exec("select cedula_est,id_tipo_est,condicion_especial,cedula_rep FROM estudiante WHERE matricula ='"+busqueda_dialog.tabla->item(row,0)->text()+"'");
    while(consulta.next())
    {
        factura.f_nombre_4->setText(busqueda_dialog.tabla->item(row,1)->text());
        factura.f_matricula->setText(busqueda_dialog.tabla->item(row,0)->text());
        factura.f_cedula_4->setText(consulta.value(0).toString());
        consulta2.exec("select descripcion from tipo_estudiante where id_tipo_est='"+consulta.value(1).toString()+"'");
        while(consulta2.next())
        {
            factura.f_condicion_2->setText(consulta2.value(0).toString());
        }
        consulta2.exec("select descripcion from condiciones_especiales where id_condicion='"+consulta.value(2).toString()+"'");
        while(consulta2.next())
        {
            factura.f_cond_esp->setText(consulta2.value(0).toString());
        }

        consulta2.exec("select * from empresas where rif='"+consulta.value(3).toString()+"'");
        while(consulta.next())
        {
            factura.f_cedula_5->setText(consulta2.value(0).toString());
            factura.f_cedula_5->setEnabled(false);
            factura.f_nombre_5->setText(consulta2.value(1).toString());
            factura.f_nombre_5->setEnabled(false);
            factura.f_telf_3->setText(consulta2.value(3).toString());
            factura.f_telf_3->setEnabled(false);
            factura.f_direccion->setText(consulta2.value(2).toString());
            factura.f_direccion->setEnabled(false);
        }
    }
    dialogo->close();
    chequeoEstudiante(factura.f_matricula->text());
}


/** Busca los datos asociados al Rif de empresa o cedula de representante. Si no existen, abre el formulario para su registro.
  */
void procesos_caja::rifChanged()
{

    bool not_found=true;

    factura.f_direccion->clear();
    factura.f_nombre_5->clear();
    factura.f_telf_3->clear();

    QSqlQuery consulta("select * from empresas where rif='"+factura.f_cedula_5->text()+"'");
    while(consulta.next())
    {
        factura.f_nombre_5->setText(consulta.value(1).toString());
        factura.f_direccion->setText(consulta.value(2).toString());
        factura.f_telf_3->setText(consulta.value(3).toString());
        not_found=false; //La empresa o representante legal ya existe
    }

    if(not_found)//La empresa o representante legal no existe
    {
        QMessageBox msgBox;
        msgBox.setText("Empresa no registrada");
        msgBox.setInformativeText("¿Registrar?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        int ret = msgBox.exec();
        switch (ret)
        {
            case QMessageBox::Yes: //El usuario selecciona la opcion para registrar
            {
               procesos_ces *ces = new procesos_ces(compania,"",usuario,database,mysql);
               ces->registroEmpresas(factura.f_cedula_5->text(),factura.f_matricula->text());//Abre el dialogo de registro de empresas
            }
            break;
            case QMessageBox::No://El usuario selecciona no registrar
               msgBox.close();
            break;
        }
    }
}


void procesos_caja::razonChanged()
{
    QTableWidgetItem *ni;
    int row;
    dialogo = new QWidget();
    busqueda_dialog.setupUi(dialogo);
    dialogo->setWindowTitle("Resultados");
    busqueda_dialog.tabla->setColumnWidth(1,400);

    busqueda_dialog.tabla->setHorizontalHeaderLabels(QStringList() << "Rif "<< "Razon Social");

    //reg_diplomado.tabla->setColumnWidth(1,400);
    QSqlQuery consulta("select rif,razon from empresas where razon like '%"+factura.f_nombre_5->text()+"%'");
    while(consulta.next())
    {
        row = busqueda_dialog.tabla->rowCount();
        busqueda_dialog.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        busqueda_dialog.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        busqueda_dialog.tabla->setItem(row,1,ni);
    }
    connect(busqueda_dialog.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(buscarEmpresa(int,int)));
    dialogo->show();
}


void procesos_caja::buscarEmpresa(int row ,int column)
{
    QSqlQuery consulta;

    consulta.exec("select direccion,telefono from empresas where rif='"+busqueda_dialog.tabla->item(row,0)->text()+"'");
    while(consulta.next())
    {
        factura.f_direccion->setText(consulta.value(0).toString());
        factura.f_telf_3->setText(consulta.value(1).toString());
    }
    factura.f_cedula_5->setText(busqueda_dialog.tabla->item(row,0)->text());
    factura.f_nombre_5->setText(busqueda_dialog.tabla->item(row,1)->text());

    dialogo->close();
}

/** Al ingresar un numero de cedula en el formulario de facturacion, indica si el participante está registrado.
 * En caso de estarlo, llena los campos con su informacion. En el caso contrario, pregunta al usuario si desea
 * registrarlo.
*/

void procesos_caja::cedulaChanged()
{
    QString cedula(factura.f_cedula_4->text());
    QSqlQuery consulta,consulta2;
    bool not_found=true;

    factura.f_nombre_4->clear();
    factura.f_condicion_2->clear();
    factura.f_matricula->clear();
    factura.f_direccion->clear();
    factura.f_seccion_2->clear();
    factura.f_curso_2->clear();
    factura.f_turno->clear();
    factura.f_nivel->clear();

    //crearConexionMysql(); //Para abrir bd de datapro
    QSqlQuery query(mysql);

    consulta.exec("SELECT nombre,id_tipo_est,matricula,condicion_especial,apellido,cedula_rep FROM estudiante WHERE cedula_est ='"+cedula+"'");
    while(consulta.next())
    {
        factura.f_nombre_4->setText(consulta.value(0).toString()+" "+consulta.value(4).toString());
        consulta2.exec("select descripcion from tipo_estudiante where id_tipo_est='"+consulta.value(1).toString()+"'");
        while(consulta2.next())
        {
            factura.f_condicion_2->setText(consulta2.value(0).toString());
        }
        consulta2.exec("select descripcion from condiciones_especiales where id_condicion='"+consulta.value(3).toString()+"'");
        while(consulta2.next())
        {
            factura.f_cond_esp->setText(consulta2.value(0).toString());
        }
        factura.f_matricula->setText(consulta.value(2).toString());

        //Consultar DPCLIENTES
        query.exec("select cli_dir1,cli_nombre,cli_tel1 from dpclientes where cli_codigo="+consulta.value(5).toString()+"");
        while(query.next())
        {
            factura.f_cedula_5->setText(consulta.value(5).toString());
            factura.f_cedula_5->setEnabled(false);
            factura.f_nombre_5->setText(query.value(1).toString());
            factura.f_nombre_5->setEnabled(false);
            factura.f_telf_3->setText(query.value(2).toString());
            factura.f_telf_3->setEnabled(false);
            factura.f_direccion->setText(query.value(0).toString());
            factura.f_direccion->setEnabled(false);
        }
        /*consulta2.exec("select * from empresas where rif='"+consulta.value(5).toString()+"'");
        while(consulta2.next())
        {
            factura.f_cedula_5->setText(consulta2.value(0).toString());
            factura.f_cedula_5->setEnabled(false);
            factura.f_nombre_5->setText(consulta2.value(1).toString());
            factura.f_nombre_5->setEnabled(false);
            factura.f_telf_3->setText(consulta2.value(3).toString());
            factura.f_telf_3->setEnabled(false);
            factura.f_direccion->setText(consulta2.value(2).toString());
            factura.f_direccion->setEnabled(false);
        }*/
        not_found=false;
    }

    if(not_found)
    {
        QMessageBox msgBox;
        msgBox.setText("Estudiante no registrado");
        msgBox.setInformativeText("¿Registrar?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        int ret = msgBox.exec();
        switch (ret)
        {
           case QMessageBox::Yes:
           {
               procesos_ces *ces = new procesos_ces(compania,"",usuario,database,mysql);
               ces->registroEstudiantes(cedula);
           }
           break;
           case QMessageBox::No:
               msgBox.close();
           break;
        }

        consulta.exec();
        while(consulta.next())
        {
            factura.f_nombre_4->setText(consulta.value(1).toString()+" "+consulta.value(4).toString());
            factura.f_condicion_2->setText(consulta.value(1).toString());
        }
    }
    else
        chequeoEstudiante(factura.f_matricula->text());
    //closeConexionMysql(mysql);
}


/** Al ingresar un numero de matricula en el formulario de facturacion, indica si el participante está registrado.
 * En caso de estarlo, llena los campos con su informacion. En el caso contrario, pregunta al usuario si desea
 * registrarlo.
*/

void procesos_caja::matriculaChanged()
{
    QString matricula(factura.f_matricula->text());
    QSqlQuery consulta,consulta2;
    QMessageBox msgBox;
    bool not_found=true;
    bool cliente=true;

    factura.f_nombre_4->clear();
    factura.f_condicion_2->clear();
    factura.f_cedula_4->clear();
    factura.f_direccion->clear();
    factura.f_seccion_2->clear();
    factura.f_curso_2->clear();
    factura.f_turno->clear();
    factura.f_nivel->clear();

    //crearConexionMysql(); //Para abrir bd de datapro
    QSqlQuery query(mysql);

    consulta.exec("SELECT cedula_est,nombre,id_tipo_est,condicion_especial,apellido,cedula_rep FROM estudiante WHERE matricula ='"+matricula+"'");
    while(consulta.next())
    {
        factura.f_nombre_4->setText(consulta.value(1).toString()+" "+consulta.value(4).toString());
        consulta2.exec("select descripcion from tipo_estudiante where id_tipo_est='"+consulta.value(2).toString()+"'");
        while(consulta2.next())
        {
            factura.f_condicion_2->setText(consulta2.value(0).toString());
        }
        consulta2.exec("select descripcion from condiciones_especiales where id_condicion='"+consulta.value(3).toString()+"'");
        while(consulta2.next())
        {
            factura.f_cond_esp->setText(consulta2.value(0).toString());
        }
        factura.f_cedula_4->setText(consulta.value(0).toString());

        query.exec("select cli_dir1,cli_nombre,cli_tel1 from dpclientes where cli_codigo="+consulta.value(5).toString()+"");
        while(query.next())
        {
            factura.f_cedula_5->setText(consulta.value(5).toString());
            factura.f_cedula_5->setEnabled(false);
            factura.f_nombre_5->setText(query.value(1).toString());
            factura.f_nombre_5->setEnabled(false);
            factura.f_telf_3->setText(query.value(2).toString());
            factura.f_telf_3->setEnabled(false);
            factura.f_direccion->setText(query.value(0).toString());
            factura.f_direccion->setEnabled(false);
            cliente=false;
        }
        if(cliente)
        {
            msgBox.setText("Cliente no registrado");
            msgBox.setInformativeText("¿Añadir datos?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::Yes);
            int ret = msgBox.exec();
            switch (ret)
            {
                case QMessageBox::Yes: //El usuario selecciona la opcion para registrar
                {
                   procesos_ces *ces = new procesos_ces(compania,"",usuario,database,mysql);
                   ces->registroEmpresas(factura.f_cedula_5->text(),factura.f_matricula->text());//Abre el dialogo de registro de empresas
                }
                break;
                case QMessageBox::No://El usuario selecciona no registrar
                   msgBox.close();
                break;
            }
        }
        /*
        consulta2.exec("select * from empresas where rif='"+consulta.value(5).toString()+"'");
        while(consulta2.next())
        {
            factura.f_cedula_5->setText(consulta2.value(0).toString());
            factura.f_cedula_5->setEnabled(false);
            factura.f_nombre_5->setText(consulta2.value(1).toString());
            factura.f_nombre_5->setEnabled(false);
            factura.f_telf_3->setText(consulta2.value(3).toString());
            factura.f_telf_3->setEnabled(false);
            factura.f_direccion->setText(consulta2.value(2).toString());
            factura.f_direccion->setEnabled(false);
        }*/

        not_found=false;
    }
    if(not_found)
    {
        msgBox.setText("Estudiante no registrado");
        msgBox.setInformativeText("¿Registrar?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        int ret = msgBox.exec();
        switch (ret)
        {
           case QMessageBox::Yes:
           {
               procesos_ces *ces = new procesos_ces(compania,"",usuario,database,mysql);
               ces->registroEstudiantes(" ");
           }
           break;
           case QMessageBox::No:
               msgBox.close();
           break;
        }

        consulta.exec();
        while(consulta.next())
        {
            factura.f_nombre_4->setText(consulta.value(1).toString()+" "+consulta.value(4).toString());
            factura.f_condicion_2->setText(consulta.value(1).toString());
        }
    }
    else
        chequeoEstudiante(matricula);
    //closeConexionMysql(mysql);
}


/** Busca la informacion asociada con el estudiante al cual se le está facturando:
 * - Curso, nivel y seccion actuales.
 * - Calificacion del nivel anterior.
 * En el caso de participantes de diplomados o talleres:
 * - Diplomado o taller actual.
 * - Ultima cuota cancelada y numero de cuotas restantes.
 * @param matricula Matricula asignada al participante.
*/

void procesos_caja::chequeoEstudiante(QString matricula)
{
    QString nota,seccion,date,tiva,ttotal,mod;
    QSqlQuery consulta,consulta2;
    int cuotas,evento;
    float inicial,iva,total,pre;

    cuotas=0;
    inicial=pre=0;
    consulta.exec("select id_evento,id_curso,id_seccion,status from ficha_academica where matricula='"+factura.f_matricula->text()+"' and (id_evento='2' or id_evento='47') and status='V'");
    while(consulta.next())
    {
        factura.f_curso_2->setText(consulta.value(1).toString());
        evento= consulta.value(0).toInt();
        factura.f_seccion_2->setText(consulta.value(2).toString());
        consulta2.exec("select modalidad,nivel from secciones where id_seccion='"+consulta.value(2).toString()+"'");
        while(consulta2.next())
        {
            mod=consulta2.value(0).toString();
            factura.f_nivel->setText(consulta2.value(1).toString());
        }
        consulta2.exec("select descripcion from modalidades where id_modalidad='"+mod+"'");
        while(consulta2.next())
        {
            factura.f_turno->setText(consulta2.value(0).toString());
        }
    }

    if(prog_academico=="3")
    {
        consulta.exec("select id_modalidad from cohortes where id='"+factura.f_seccion_2->text()+"'");
        while(consulta.next())
        {
            consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                factura.f_turno->setText(consulta2.value(0).toString());
            }
        }

        consulta.exec("select to_char(fecha,'dd-mm-yyyy'),ult_cuota from ficha_pago_cfp where renglon =(select max(renglon) from ficha_pago_cfp where matricula='"+factura.f_matricula->text()+"' and id_evento='18' or id_evento='2')");
        while(consulta.next())
        {
            cuota_actual.setNum(consulta.value(1).toInt()+1);

            consulta2.exec("select cuotas from cohortes where id='"+factura.f_seccion_2->text()+"'");
            while(consulta2.next())
            {
                cuotas=consulta2.value(0).toInt();
            }
            if(consulta.value(1).toInt()<cuotas)
                QMessageBox::information(0,"Diplomados",tr("Cuotas Canceladas: %1 (%2)").arg(consulta.value(1).toString()).arg(consulta.value(0).toString()));
            else
                QMessageBox::information(0,"Diplomados",tr("Totalidad de cuotas canceladas"));
        }
        if(evento==47)
        {
            consulta2.exec("select inicial from cohortes where id='"+factura.f_seccion_2->text()+"'");
            while(consulta2.next())
            {
                inicial=consulta2.value(0).toDouble();
            }
            consulta2.exec("select monto from ficha_pago_cfp where status='V' and matricula='"+factura.f_matricula->text()+"' and id_evento='47'");
            while(consulta2.next())
            {
                pre=consulta2.value(0).toDouble();
            }

            int row = factura.f_tabla->rowCount();
            factura.f_tabla->insertRow(row);
            QTableWidgetItem *ni = new QTableWidgetItem(tr("DP"));
            factura.f_tabla->setItem(row,0,ni);
            ni = new QTableWidgetItem(tr("%1").arg(factura.f_seccion_2->text()));
            factura.f_tabla->setItem(row,1,ni);
            ni = new QTableWidgetItem(tr("RESTO INSCRIPCION"));
            factura.f_tabla->setItem(row,2,ni);
            ni = new QTableWidgetItem(tr("1"));
            factura.f_tabla->setItem(row,3,ni);
            ni = new QTableWidgetItem(tr("%1").arg(inicial-pre));
            factura.f_tabla->setItem(row,4,ni);
            ni = new QTableWidgetItem(tr("%1").arg(inicial-pre));
            factura.f_tabla->setItem(row,5,ni);
            factura.f_subtotal_2->setText(tr("%1").arg(inicial-pre));
            iva = (factura.f_subtotal_2->text().toFloat()*factura.f_iva_2->text().toFloat())/100;
            total = factura.f_subtotal_2->text().toFloat() + iva;
            tiva.setNum(iva,'g',8);
            ttotal.setNum(total,'g',8);
            factura.f_iva_2->setText(tiva);
            factura.f_total_2->setText(ttotal);
            f_curso = factura.f_curso_2->text();
            f_seccion = factura.f_seccion_2->text();
        }
    }

    else
    {
        consulta.exec("select calificacion from ficha_academica where renglon = (select max(renglon) from ficha_academica where matricula='"+factura.f_matricula->text()+"' and id_evento='21')");
        while(consulta.next())
        {
            nota = consulta.value(0).toString();
        }
        consulta.exec("select nota_minima from niveles where id_metodo='"+factura.f_curso_2->text()+"' and nivel='"+factura.f_nivel->text()+"'");
        while(consulta.next())
        {
            QString minima(consulta.value(0).toString());
            if(nota.toInt()>minima.toInt())
            {
                QMessageBox::information(0,"Aviso","El estudiante no aprobó el nivel");
            }
        }
        if((prog_academico=="4")||(factura.f_curso_2->text()=="SF")||(factura.f_curso_2->text()=="EAD"))
        {
            consulta.exec("select to_char(fecha,'dd-mm-yyyy'),cuota_o_libro from ficha_pago where renglon =(select max(renglon) from ficha_pago where matricula='"+factura.f_matricula->text()+"' and id_evento in (18,2))");
            while(consulta.next())
            {
                cuota_actual.setNum(consulta.value(1).toInt()+1);

                consulta2.exec("select cuotas from metodos where id_metodo='"+factura.f_curso_2->text()+"'");
                while(consulta2.next())
                {
                    cuotas=consulta2.value(0).toInt();
                }
                if(consulta.value(1).toInt()<cuotas)
                    QMessageBox::information(0,"Idiomas Niños",tr("Cuotas Canceladas: %1 (%2)").arg(consulta.value(1).toString()).arg(consulta.value(0).toString()));
                else
                    QMessageBox::information(0,"Idiomas Niños",tr("Totalidad de cuotas canceladas"));
            }
        }
    }
}


/** Controla el resultado de marcar la casilla 'Participante'.
 * Si la casilla está marcada, indica que la factura debe salir a nombre del estudiante.
 * Si no, se habilitan los campos del formulario para ingresar esa informacion.
 * @param checked Indica si el QCheckBox está marcado o no.
*/

void procesos_caja::sameAsParticipant(bool checked)
{
    if(checked)
    {
        QSqlQuery consulta,consulta2;
        QString cedula = factura.f_matricula->text();
        consulta.exec("select cedula_est,nombre,zona,telf_hab,apellido from estudiante where matricula='"+cedula+"'");
        while(consulta.next())
        {
            factura.f_cedula_5->setText(consulta.value(0).toString());
            factura.f_cedula_5->setEnabled(false);
            factura.f_nombre_5->setText(consulta.value(1).toString()+" "+consulta.value(4).toString());
            factura.f_nombre_5->setEnabled(false);
            factura.f_telf_3->setText(consulta.value(3).toString());
            factura.f_telf_3->setEnabled(false);
            factura.f_direccion->setText(consulta.value(2).toString());
            factura.f_direccion->setEnabled(false);
        }
    }
    else
    {
        factura.f_cedula_5->clear();
        factura.f_cedula_5->setEnabled(true);
        factura.f_nombre_5->clear();
        factura.f_nombre_5->setEnabled(true);
        factura.f_telf_3->clear();
        factura.f_telf_3->setEnabled(true);
        factura.f_direccion->clear();
        factura.f_direccion->setEnabled(true);
    }
}


void procesos_caja::facturaProforma(bool checked)
{
    if(checked)
    {
        factura.fechas->setEnabled(false);
        factura.detallespago->setEnabled(false);
        factura.detallesbanco->setEnabled(false);
        factura.referencias->setEnabled(false);
        factura.montos->setEnabled(false);
        factura.f_tabla0->setEnabled(false);
        proforma=true;
    }
    else
    {
        factura.fechas->setEnabled(true);
        factura.detallespago->setEnabled(true);
        factura.detallesbanco->setEnabled(true);
        factura.referencias->setEnabled(true);
        factura.montos->setEnabled(true);
        factura.f_tabla0->setEnabled(true);
        proforma=false;
    }
}


/** Si el porcentaje de IVA cambia, se realizan los ajustes necesarios en el total a cancelar.
 * @param s Texto del QLineEdit que indica el valor del IVA
*/

void procesos_caja::ivaChanged(QString s)
{
    float iva,total;
    QString tiva,ttotal;

    iva = (factura.f_subtotal_2->text().toFloat()*s.toFloat())/100;
    total = factura.f_subtotal_2->text().toFloat() + iva;

    tiva.setNum(iva,'g',10);
    ttotal.setNum(total,'g',10);
    factura.f_iva_2->setText(tiva);
    factura.f_total_2->setText(ttotal);
}


/** Inicializa y configura los componentes de la seccion de ingreso de informacion del deposito.
*/

void procesos_caja::depositoSetup()
{
    QSqlQuery consulta;
    factura.fechas->setDate(QDate::currentDate());
    factura.detallespago->addItem("-");
    consulta.exec("select descripcion from forma_pago order by descripcion"); //DPBANCOTIP
    while(consulta.next())
    {
        factura.detallespago->addItem(consulta.value(0).toString());
    }
    connect(factura.detallespago,SIGNAL(currentIndexChanged(const QString)),this,SLOT(pagoChanged(const QString)));
    connect(factura.montos,SIGNAL(returnPressed()),this,SLOT(agregarDeposito()));
    connect(factura.referencias,SIGNAL(returnPressed()),this,SLOT(agregarDeposito()));
    connect(factura.f_quitar2,SIGNAL(pressed()),this,SLOT(quitarItem2()));
}


/**
 *
 */

void procesos_caja::pagoChanged(QString s)
{
    QSqlQuery consulta("SELECT id_pago FROM forma_pago WHERE descripcion='"+s+"'");
    int pago=0;

    while(consulta.next())
    {
        pago=consulta.value(0).toInt();
    }
    if((pago==20)||(pago==25))
    {
        factura.detallesbanco->setEnabled(false);
        factura.referencias->setEnabled(false);
    }
    else
    {
        factura.detallesbanco->clear();
        factura.detallesbanco->addItem("-");
        if(pago==3)
        {
            consulta.exec("select nombre from bancos where deposito='S' order by nombre");
            while(consulta.next())
            {
                factura.detallesbanco->addItem(consulta.value(0).toString());
            }
        }
        else if(pago==4||pago==5)
        {
            consulta.exec("select nombre from bancos where debito='S' order by nombre");
            while(consulta.next())
            {
                factura.detallesbanco->addItem(consulta.value(0).toString());
            }
        }
        factura.detallesbanco->setEnabled(true);
        factura.referencias->setEnabled(true);
    }
}


void procesos_caja::pagoChanged2(QString s)
{
    QSqlQuery consulta("SELECT id_pago FROM forma_pago WHERE descripcion='"+s+"'");
    int pago=0;

    while(consulta.next())
    {
        pago=consulta.value(0).toInt();
    }
    if((pago==20)||(pago==25))
    {
        cuentas_cobro.detallesbanco->setEnabled(false);
        cuentas_cobro.referencias->setEnabled(false);
    }
    else
    {
        cuentas_cobro.detallesbanco->clear();
        cuentas_cobro.detallesbanco->addItem("-");
        if(pago==3)
        {
            consulta.exec("select nombre from bancos where deposito='S' order by nombre");
            while(consulta.next())
            {
                cuentas_cobro.detallesbanco->addItem(consulta.value(0).toString());
            }
        }
        else if(pago==4||pago==5)
        {
            consulta.exec("select nombre from bancos where debito='S' order by nombre");
            while(consulta.next())
            {
                cuentas_cobro.detallesbanco->addItem(consulta.value(0).toString());
            }
        }
        cuentas_cobro.detallesbanco->setEnabled(true);
        cuentas_cobro.referencias->setEnabled(true);
    }
}



/** Inicializa y configura los componentes de la seccion de ingreso de informacion de los items a facturar.
*/

void procesos_caja::facturaSetup()
{
    factura.tp->addItems(tipo_item);
    connect(factura.tp,SIGNAL(currentIndexChanged(const QString)),this,SLOT(verificarTipoItem(const QString)));
    connect(factura.cantidad,SIGNAL(textChanged(const QString)),this,SLOT(cantidadChanged(const QString)));
    factura.bs->setReadOnly(true);

    connect(factura.f_quitar,SIGNAL(pressed()),this,SLOT(quitarItem()));

    if(tipo_factura>1)
    {
        factura.f_matricula->setEnabled(false);
        factura.f_cedula_4->setEnabled(false);
        factura.f_nombre_4->setEnabled(false);
        factura.f_condicion_2->setEnabled(false);
        factura.f_curso_2->setEnabled(false);
        factura.f_seccion_2->setEnabled(false);
        factura.f_turno->setEnabled(false);
        factura.f_same->setEnabled(false);
        factura.f_nivel->setEnabled(false);
        factura.f_cond_esp->setEnabled(false);
    }

    disconnect(container.botonNuevo,SIGNAL(clicked()),0,0);
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevaFactura()));
    container.botonNuevo->setEnabled(true);

}


/** Agrega un item a la tabla de items del formulario de facturacion
*/

void procesos_caja::agregarItem()
{
    QString texto,tiva,ttotal,tipo;
    QSqlQuery consulta;
    float iva,total;

    int row = factura.f_tabla->rowCount();
    factura.f_tabla->insertRow(row);

    consulta.exec("select abrev from tipo_material where descripcion='"+factura.tp->currentText()+"'");
    while(consulta.next())
    {
        tipo=consulta.value(0).toString();
    }

    QTableWidgetItem *ni = new QTableWidgetItem(tipo);
    ni->setSizeHint(QSize(30,20));
    factura.f_tabla->setItem(row,0,ni);

    if((tipo=="C")||(tipo=="DP"))
        ni = new QTableWidgetItem(f_seccion);
    else if(tipo=="RN")
        ni = new QTableWidgetItem("RN-"+factura.item->currentText());
    else
        ni = new QTableWidgetItem(factura.item->currentText());

    factura.f_tabla->setItem(row,1,ni);

    ni = new QTableWidgetItem(factura.descripcion->text());
    factura.f_tabla->setItem(row,2,ni);

    texto=factura.bs->text();
    if(!texto.contains(".",Qt::CaseInsensitive)&&!texto.contains(",",Qt::CaseInsensitive))
        texto= texto+".00";
    ni = new QTableWidgetItem(texto);
    factura.f_tabla->setItem(row,5,ni);

    texto.setNum(factura.f_subtotal_2->text().toFloat() + factura.bs->text().toFloat(),'g',8);

    if(!texto.contains(".",Qt::CaseInsensitive)&&!texto.contains(",",Qt::CaseInsensitive))
        texto= texto+".00";
    factura.f_subtotal_2->setText(texto);

    iva = (factura.f_subtotal_2->text().toFloat()*factura.f_iva_2->text().toFloat())/100;
    total = factura.f_subtotal_2->text().toFloat() + iva;
    tiva.setNum(iva,'g',8);
    ttotal.setNum(total,'g',8);

    if(!tiva.contains(".",Qt::CaseInsensitive)&&!tiva.contains(",",Qt::CaseInsensitive))
        tiva= tiva+".00";
    factura.f_iva_2->setText(tiva);
    if(!ttotal.contains(".",Qt::CaseInsensitive)&&!ttotal.contains(",",Qt::CaseInsensitive))
        ttotal= ttotal+".00";
    factura.f_total_2->setText(ttotal);

    ni = new QTableWidgetItem(factura.cantidad->text());
    factura.f_tabla->setItem(row,3,ni);

    texto=factura.precio->text();
    if(!texto.contains(".",Qt::CaseInsensitive)&&!texto.contains(",",Qt::CaseInsensitive))
        texto= texto+".00";
    ni = new QTableWidgetItem(texto);
    factura.f_tabla->setItem(row,4,ni);

    factura.precio->clear();
    factura.descripcion->clear();
    factura.bs->clear();
    factura.cantidad->clear();
    disconnect(factura.cantidad,SIGNAL(returnPressed()),0,0);
        //factura.tp->clear();

        /*if((tipo=="C")||(tipo=="DP"))
    {
        consulta.exec("select descuento from condiciones_especiales where descripcion='"+factura.f_cond_esp->text()+"'");
        while(consulta.next())
        {
            descuento(consulta.value(0).toString());
        }
        }*/
}


/** Agrega una item a la tabla de informacion del deposito.
*/

void procesos_caja::agregarDeposito()
{
    int row = factura.f_tabla0->rowCount();

    if(row<6)
    {
        factura.f_tabla0->insertRow(row);
        QTableWidgetItem *ni = new QTableWidgetItem(tr("%1").arg(factura.fechas->date().toString("dd-MM-yyyy")));
        ni->setSizeHint(QSize(30,20));
        factura.f_tabla0->setItem(row,0,ni);

        ni= new QTableWidgetItem(tr("%1").arg(factura.detallespago->currentText()));
        factura.f_tabla0->setItem(row,1,ni);

        ni= new QTableWidgetItem(tr("%1").arg(factura.detallesbanco->currentText()));
        factura.f_tabla0->setItem(row,2,ni);

        ni= new QTableWidgetItem(tr("%1").arg(factura.referencias->text()));
        factura.f_tabla0->setItem(row,3,ni);

        ni= new QTableWidgetItem(tr("%1").arg(factura.montos->text()));

        factura.f_tabla0->setItem(row,4,ni);
        factura.montos->clear();
        factura.detallespago->setCurrentIndex(0);
        factura.detallesbanco->setCurrentIndex(0);
        factura.referencias->clear();
        factura.fechas->clear();
    }
    else
    {
        QMessageBox::information(0,"","Máximo de 3 Depositos");
    }
}


void procesos_caja::agregarDeposito2()
{
    int row = cuentas_cobro.tabla2->rowCount();
    if(row<6)
    {
        cuentas_cobro.tabla2->insertRow(row);
        QTableWidgetItem *ni = new QTableWidgetItem(tr("%1").arg(cuentas_cobro.fechas->date().toString("dd-MM-yyyy")));
        ni->setSizeHint(QSize(30,20));
        cuentas_cobro.tabla2->setItem(row,0,ni);

        ni= new QTableWidgetItem(tr("%1").arg(cuentas_cobro.detallespago->currentText()));
        cuentas_cobro.tabla2->setItem(row,1,ni);

        ni= new QTableWidgetItem(tr("%1").arg(cuentas_cobro.detallesbanco->currentText()));
        cuentas_cobro.tabla2->setItem(row,2,ni);

        ni= new QTableWidgetItem(tr("%1").arg(cuentas_cobro.referencias->text()));
        cuentas_cobro.tabla2->setItem(row,3,ni);

        ni= new QTableWidgetItem(tr("%1").arg(cuentas_cobro.montos->text()));

        cuentas_cobro.tabla2->setItem(row,4,ni);
        cuentas_cobro.montos->clear();
        cuentas_cobro.detallespago->setCurrentIndex(0);
        cuentas_cobro.detallesbanco->setCurrentIndex(0);
        cuentas_cobro.referencias->clear();
        cuentas_cobro.fechas->clear();
    }
    else
    {
        QMessageBox::information(0,"","Máximo de 3 Depositos");
    }
}


/** Se utiliza solo con los items que permiten ingreso manual del precio. Al ser modificado ajusta el monto a cancelar
 * de acuerdo a la cantidad de items.
 * @param s Texto del QLineEdit que indica el precio.
*/

void procesos_caja::precioChanged(QString s)
{
    QString texto;
    double total;
    total=factura.precio->text().toFloat() * s.toFloat();

    texto.setNum(total,'g',10);
    if(!texto.contains(".",Qt::CaseInsensitive)&&!texto.contains(",",Qt::CaseInsensitive))
        texto= texto+".00";
    factura.bs->setText(texto);
}


/** Al ser modificada la cantidad, ajusta el monto a cancelar
 * @param s Texto del QLineEdit que indica el precio.
*/

void procesos_caja::cantidadChanged(QString s)
{
    QString texto;
    double total;
    total=factura.precio->text().toDouble() * s.toDouble();
    texto.setNum(total,'g',10);
    if(!texto.contains(".",Qt::CaseInsensitive)&&!texto.contains(",",Qt::CaseInsensitive))
        texto= texto+".00";
    factura.bs->setText(texto);
}


void procesos_caja::saldoDiferido(QString tabla)
{
    QSqlQuery consulta,consulta2;
    QString tiva,ttotal,texto,tsaldo;
    float iva,total,saldo;

    consulta.exec("select renglon,monto from "+tabla+" where matricula='"+factura.f_matricula->text()+"' and id_evento='43' and status='V'");
    while(consulta.next())
    {
        int row = factura.f_tabla->rowCount();
        factura.f_tabla->insertRow(row);
        QTableWidgetItem *ni = new QTableWidgetItem(tr("ID"));
        factura.f_tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("IDN"));
        factura.f_tabla->setItem(row,1,ni);
        ni = new QTableWidgetItem(tr("INGRESO DIFERIDO NEGATIVO"));
        factura.f_tabla->setItem(row,2,ni);
        ni = new QTableWidgetItem(tr("1"));
        factura.f_tabla->setItem(row,3,ni);
        saldo=consulta.value(1).toDouble()*(-1);
        tsaldo.setNum(saldo,'g',10);
        if(!tsaldo.contains(".",Qt::CaseInsensitive)&&!tsaldo.contains(",",Qt::CaseInsensitive))
            tsaldo= tsaldo+".00";
        ni = new QTableWidgetItem(tr("%1").arg(tsaldo));
        factura.f_tabla->setItem(row,4,ni);
        ni = new QTableWidgetItem(tr("%1").arg(tsaldo));
        factura.f_tabla->setItem(row,5,ni);

        texto.setNum(factura.f_subtotal_2->text().toFloat() + saldo,'g',10);
        factura.f_subtotal_2->setText(texto);
        iva = (factura.f_subtotal_2->text().toFloat()*factura.f_iva_2->text().toFloat())/100;
        total = factura.f_subtotal_2->text().toFloat() + iva;
        tiva.setNum(iva,'g',10);
        ttotal.setNum(total,'g',10);
        factura.f_iva_2->setText(tiva);
        factura.f_total_2->setText(ttotal);
        consulta2.exec("update "+tabla+" set status='H' where renglon='"+consulta2.value(0).toString()+"'");
        consulta2.exec("commit");
    }
}


/**Al seleccionar el tipo de item, se inicializan y configuran las listas y se establecen las conexiones necesarias.
 * @param s Texto actual del QComboBox que indica el tipo de item
 */

void procesos_caja::verificarTipoItem(QString s)
{
    QSqlQuery consulta;
    QString tipo;
    factura.item->setEnabled(true);
    consulta.exec("select abrev from tipo_material where descripcion='"+s+"'");
    while(consulta.next())
    {
        tipo=consulta.value(0).toString();
    }

    disconnect(factura.item,SIGNAL(currentIndexChanged(const QString)),0,0);
    disconnect(factura.metodo,SIGNAL(currentIndexChanged(const QString)),0,0);
    connect(factura.cantidad,SIGNAL(returnPressed()),this,SLOT(agregarItem()));

    if(tipo=="C")
    {
        consulta.exec("select id_metodo from metodos where prog_academico='"+prog_academico+"' order by id_metodo");
        factura.metodo->clear();
        factura.metodo->addItem("-");
        while(consulta.next())
        {
            factura.metodo->addItem(consulta.value(0).toString());
        }
        factura.metodo->setEnabled(true);
        connect(factura.metodo,SIGNAL(currentIndexChanged(const QString)),this,SLOT(llenarHorario(const QString)));
        saldoDiferido("ficha_pago");
    }
    else if(tipo=="PC")
    {
        consulta.exec("select id_certi from diplo_certi order by id_certi");
        factura.metodo->clear();
        factura.metodo->addItem("-");
        while(consulta.next())
        {
            factura.metodo->addItem(consulta.value(0).toString());
        }
        factura.metodo->setEnabled(true);
        connect(factura.metodo,SIGNAL(currentIndexChanged(const QString)),this,SLOT(llenarHorario(const QString)));
        connect(factura.descripcion,SIGNAL(returnPressed()),this,SLOT(descripcionChanged()));
        connect(factura.descripcion,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    }
    else if((tipo=="DP")||(tipo=="PRE"))
    {
        //consulta.exec("select id_diplomado from diplomados");
        consulta.exec("select id_diplomado from diplo_temp order by id_diplomado");
        factura.metodo->clear();
        factura.metodo->addItem("-");
        while(consulta.next())
        {
            factura.metodo->addItem(consulta.value(0).toString());
        }
        factura.metodo->setEnabled(true);
        connect(factura.metodo,SIGNAL(currentIndexChanged(const QString)),this,SLOT(llenarHorario(const QString)));
        saldoDiferido("ficha_pago_cfp");
        connect(factura.descripcion,SIGNAL(returnPressed()),this,SLOT(descripcionChanged()));
        connect(factura.descripcion,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    }
    /*else if(tipo=="PRE")
    {
        factura.metodo->setEnabled(false);
        consulta.exec("select id_diplomado from diplo_temp ");
        factura.item->clear();
        factura.item->addItem("-");
        while(consulta.next())
        {
            factura.item->addItem(consulta.value(0).toString());
        }
        connect(factura.item,SIGNAL(currentIndexChanged(const QString)),this,SLOT(llenarPreDiplomado(const QString)));
        saldoDiferido("ficha_pago_cfp");
        //saldoDiferido("ficha_pago");
    }*/
    else if(tipo=="CU")
    {
        //factura.metodo->setEnabled(false);
        consulta.exec("select id_diplomado from diplo_temp order by id_diplomado");
        factura.metodo->clear();
        factura.metodo->addItem("-");
        while(consulta.next())
        {
            factura.metodo->addItem(consulta.value(0).toString());
        }
        connect(factura.metodo,SIGNAL(currentIndexChanged(const QString)),this,SLOT(llenarHorario(const QString)));
        factura.metodo->setCurrentIndex(factura.metodo->findText(factura.f_curso_2->text()));
        saldoDiferido("ficha_pago_cfp");
    }
    else if(tipo=="RN")
    {
        factura.metodo->setEnabled(false);
        consulta.exec("select id_diplomado from diplo_temp order by id_diplomado");
        factura.item->clear();
        factura.item->addItem("-");
        while(consulta.next())
        {
            factura.item->addItem(consulta.value(0).toString());
        }
        connect(factura.item,SIGNAL(currentIndexChanged(const QString)),this,SLOT(recargoNivelacion(const QString)));
        factura.item->setCurrentIndex(factura.item->findText(factura.f_curso_2->text()));
        saldoDiferido("ficha_pago_cfp");
    }
    else if(tipo=="CI")
    {
        factura.metodo->setEnabled(false);
        consulta.exec("select id_metodo from metodos where cuotas>1 order by id_metodo");
        factura.item->clear();
        factura.item->addItem("-");
        while(consulta.next())
        {
            factura.item->addItem(consulta.value(0).toString());
        }

        connect(factura.item,SIGNAL(currentIndexChanged(const QString)),this,SLOT(setPrecioCuota2(const QString)));
        factura.item->setCurrentIndex(factura.item->findText(factura.f_curso_2->text()));
        saldoDiferido("ficha_pago");
    }
    else if(tipo=="D")
    {
        factura.metodo->setEnabled(false);
        consulta.exec("select id_mat from materiales where tipo='D' order by id_mat");
        factura.item->clear();
        factura.item->addItem("-");
        while(consulta.next())
        {
            factura.item->addItem(consulta.value(0).toString());
        }

        disconnect(factura.cantidad,SIGNAL(returnPressed()),0,0);
        connect(factura.item,SIGNAL(currentIndexChanged(const QString)),this,SLOT(descuento(const QString)));
        //saldoDiferido("ficha_pago_cfp");
        //saldoDiferido("ficha_pago");
    }
    else if(tipo=="M")
    {
        factura.metodo->setEnabled(false);
        consulta.exec("select id_mat from materiales where tipo='M' order by id_mat");
        factura.item->clear();
        factura.item->addItem("-");
        while(consulta.next())
        {
            factura.item->addItem(consulta.value(0).toString());
        }
        connect(factura.item,SIGNAL(currentIndexChanged(const QString)),this,SLOT(setPrecioMaterial(const QString)));
    }
    else
    {
        factura.metodo->setEnabled(false);
        consulta.exec("select id_mat from materiales where tipo='"+tipo+"' order by id_mat");
        factura.item->clear();
        factura.item->addItem("-");
        while(consulta.next())
        {
            factura.item->addItem(consulta.value(0).toString());
        }

        connect(factura.item,SIGNAL(currentIndexChanged(const QString)),this,SLOT(setPrecioMaterial(const QString)));
        saldoDiferido("ficha_pago");
    }
}


/** Al seleccionar el item, se consulta su precio en la base de datos y se muestra en el QLineEdit de precio.
 * @param s Texto actual del QComboBox que contiene el listado de items
 */

void procesos_caja::setPrecioMaterial(QString s)
{
    QString price;
    double porcentaje;
    QSqlQuery consulta("select descripcion from materiales where id_mat='"+s+"'");
    while(consulta.next())
    {
        factura.descripcion->setText(consulta.value(0).toString());
    }
    consulta.exec("select precio1 from precios where item='"+s+"'");
    while(consulta.next())
    {
        /*if(s=="RECAD")
        {
            porcentaje=consulta.value(0).toDouble();
            price.setNum(factura.f_subtotal_2->text().toFloat()*porcentaje/100);
            factura.cantidad->setText("1");
            factura.precio->setText((tr("%1").arg(price)));
            factura.bs->setText((tr("%1").arg(price)));
            agregarItem();
        }
        else
        {*/
            price=consulta.value(0).toString();
            if(!price.contains(".",Qt::CaseInsensitive)&&!price.contains(",",Qt::CaseInsensitive))
                price+=".00";
            factura.precio->setText(price);
        //}
    }
    connect(factura.cantidad,SIGNAL(textChanged(const QString)),this,SLOT(cantidadChanged(const QString)));
}


void procesos_caja::recargoNivelacion(QString s)
{
    QSqlQuery consulta("select descripcion from diplo_temp where id_diplomado='"+s+"'");
    while(consulta.next())
    {
        factura.descripcion->setText("RECARGO NIVELACION - "+consulta.value(0).toString());
    }
    connect(factura.cantidad,SIGNAL(textChanged(const QString)),this,SLOT(cantidadChanged(const QString)));
}

/** Si el item seleccionado es una cuota de diplomado, se consulta el costo de la misma en la base de datos.
 * @param s Texto actual del QComboBox que contiene el listado de codigos de diplomados
 */

void procesos_caja::setPrecioCuota(QString s)
{
    QString price,desc;
    prontoPago(cuota_actual,s);
    QSqlQuery consulta("select descripcion from diplo_temp where id_diplomado='"+f_curso+"'");
    while(consulta.next())
    {
        desc=consulta.value(0).toString();
    }

    consulta.exec("select costo_cuota from cohortes where id='"+s+"'");
    while(consulta.next())
    {
        factura.descripcion->setText(tr("CUOTA %1 DIPLOMADO %2").arg(cuota_actual).arg(desc));
        price=consulta.value(0).toString();
        if(!price.contains(".",Qt::CaseInsensitive)&&!price.contains(",",Qt::CaseInsensitive))
            price+=".00";
        factura.precio->setText(price);
    }
    connect(factura.cantidad,SIGNAL(textChanged(const QString)),this,SLOT(cantidadChanged(const QString)));
    //f_seccion= s;
}


void procesos_caja::setPrecioCuota2(QString s)
{
    QString price,metodo,hora;
        float cuotas=0;

    QSqlQuery consulta("select cuotas,descripcion from metodos where id_metodo='"+s+"'");
    while(consulta.next())
    {
        cuotas=consulta.value(0).toDouble();
        metodo=consulta.value(1).toString();
    }

    consulta.exec("select horario from secciones where id_seccion='"+factura.f_seccion_2->text()+"'");
    while(consulta.next())
    {
        hora=consulta.value(0).toString();
    }

    consulta.exec("select precio1 from precios where item='"+s+"'");
    while(consulta.next())
    {
        factura.descripcion->setText(tr("CUOTA %1 %2 - NIVEL %3 %4").arg(cuota_actual).arg(metodo).arg(factura.f_nivel->text()).arg(hora));
        price.setNum(consulta.value(0).toDouble()/cuotas,'g',10);
        if(!price.contains(".",Qt::CaseInsensitive)&&!price.contains(",",Qt::CaseInsensitive))
            price+=".00";
        factura.precio->setText(price);
    }
    connect(factura.cantidad,SIGNAL(textChanged(const QString)),this,SLOT(cantidadChanged(const QString)));
}


void procesos_caja::descripcionChanged()
{
    QTableWidgetItem *ni;
    int row;
    dialogo = new QWidget();
    busqueda_dialog.setupUi(dialogo);
    dialogo->setWindowTitle("Resultados");
    busqueda_dialog.tabla->setColumnWidth(1,400);

    busqueda_dialog.tabla->setHorizontalHeaderLabels(QStringList() << "Codigo "<< "Diplomado");

    //reg_diplomado.tabla->setColumnWidth(1,400);
    QSqlQuery consulta("select id_diplomado,descripcion from diplo_temp where descripcion like '%"+factura.descripcion->text()+"%'");
    while(consulta.next())
    {
        row = busqueda_dialog.tabla->rowCount();
        busqueda_dialog.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        busqueda_dialog.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        busqueda_dialog.tabla->setItem(row,1,ni);
    }
    connect(busqueda_dialog.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(buscarDiplo(int,int)));
    dialogo->show();
}


void procesos_caja::buscarDiplo(int row ,int column)
{
    factura.metodo->setCurrentIndex(factura.metodo->findText(busqueda_dialog.tabla->item(row,0)->text()));
    factura.descripcion->clear();
    dialogo->close();
}

/** LLena el QLineEdit de descripcion con el nombre del diplomado seleccionado.
 * @param s Texto actual del QComboBox que contiene el listado de codigos de diplomados
 */

void procesos_caja::llenarDiplomado(QString s)
{
    QSqlQuery consulta;
    QString price,desc,mod,ciudad;
    int min,max,actual=0;
    f_curso = factura.metodo->currentText();
    f_seccion = s;
    //factura.item->setEnabled(false);

    //QMessageBox::information(0,"","select minimo,maximo,descripcion from diplo_temp where id_diplomado='"+factura.metodo->currentText()+"'");
    consulta.exec("select minimo,maximo,descripcion from diplo_temp where id_diplomado='"+factura.metodo->currentText()+"'");
    while(consulta.next())
    {
        min=consulta.value(0).toInt();
        max=consulta.value(1).toInt();
        desc=consulta.value(2).toString();
    }
    //QMessageBox::information(0,"","select cant_actual,id_modalidad,inicial,ciudad from cohortes where id='"+s+"'");
    consulta.exec("select cant_actual,id_modalidad,inicial,ciudad from cohortes where id='"+s+"'");
    while(consulta.next())
    {
        actual=consulta.value(0).toInt();
        mod=consulta.value(1).toString();
        price=consulta.value(2).toString();
        ciudad=consulta.value(3).toString();
    }

    if(actual==max)
        QMessageBox::information(0,"","Cupo Lleno");
    else
    {
        consulta.exec("select descripcion from modalidades where id_modalidad='"+mod+"'");
        while(consulta.next())
        {
            factura.descripcion->setText(desc+" - "+consulta.value(0).toString()+" - "+ciudad);
        }
        //factura.descripcion->setText(desc);

        //price=consulta.value(1).toString();
        if(!price.contains(".",Qt::CaseInsensitive)&&!price.contains(",",Qt::CaseInsensitive))
            price+=".00";
        factura.precio->setText(price);
        connect(factura.cantidad,SIGNAL(textChanged(const QString)),this,SLOT(cantidadChanged(const QString)));
    }
}


void procesos_caja::llenarCerti(QString s)
{
    QSqlQuery consulta;
    QString price,desc,ciudad;

    f_curso = factura.metodo->currentText();
    f_seccion = s;

    consulta.exec("select descripcion from diplo_certi where id_certi='"+factura.metodo->currentText()+"'");
    while(consulta.next())
    {
        desc=consulta.value(0).toString();
    }
    consulta.exec("select restante,ciudad from cohorte_certi where id='"+s+"'");
    while(consulta.next())
    {
        price=consulta.value(0).toString();
        ciudad=consulta.value(1).toString();
    }

    factura.descripcion->setText(desc+" - "+ciudad);
    if(!price.contains(".",Qt::CaseInsensitive)&&!price.contains(",",Qt::CaseInsensitive))
        price+=".00";
    factura.precio->setText(price);
    connect(factura.cantidad,SIGNAL(textChanged(const QString)),this,SLOT(cantidadChanged(const QString)));
}


/** LLena el QLineEdit de descripcion con 'Preinscripcion' mas el nombre del diplomado seleccionado. Asigna el precio de la
 * preinscripcion al QLineEdit de precio.
 * @param s Texto actual del QComboBox que contiene el listado de codigos de diplomados
 */

void procesos_caja::llenarPreDiplomado(QString s)
{
    QSqlQuery consulta;
    QString desc,mod;
    int min,max,actual;
    f_seccion = s;

    consulta.exec("select minimo,maximo,descripcion from diplo_temp where id_diplomado='"+factura.metodo->currentText()+"'");
    while(consulta.next())
    {
        min= consulta.value(0).toInt();
        max= consulta.value(1).toInt();
        desc=consulta.value(2).toString();
    }
    consulta.exec("select cant_actual,id_modalidad from cohortes where id='"+s+"'");
    while(consulta.next())
    {
        actual=consulta.value(0).toInt();
        mod=consulta.value(1).toString();
    }
    if(actual==max)
        QMessageBox::information(0,"","Cupo Lleno");
    else
    {
        consulta.exec("select descripcion from modalidades where id_modalidad='"+mod+"'");
        while(consulta.next())
        {
            factura.descripcion->setText("PREINSCRIPCION "+desc+" - "+consulta.value(0).toString());
            factura.precio->setText("300.00");
        }
        connect(factura.cantidad,SIGNAL(textChanged(const QString)),this,SLOT(cantidadChanged(const QString)));
    }
}


/** Lista las secciones disponibles del curso o metodo seleccionado.
 * @param s Texto actual del QComboBox que contiene el listado de codigos de cursos.
 */

void procesos_caja::llenarHorario(QString s)
{
    QString seccion,fecha,mod,cal;
    QSqlQuery consulta,consulta2;
    int periodo;
    int niveles;
    f_curso = s;
    if(prog_academico!="3")
    {
        factura.item->clear();
        factura.item->addItem("-");
        consulta.exec("select id_calendario,niveles from metodos where id_metodo='"+s+"'");
        while(consulta.next())
        {
           cal=consulta.value(0).toString();
           niveles=consulta.value(1).toInt();
        }
        for(int i=1;i<=niveles;i++)
        {
            consulta.exec("select distinct(modalidad) from secciones where id_metodo='"+s+"' and nivel='"+tr("%1").arg(i)+"'");
            while(consulta.next())
            {
                if(consulta.value(0).toString()=="19")
                   consulta2.exec("select min(periodo) from calendarios_detalle where id_calendario='"+cal+"' and modalidad='1' and fecha_ini > to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy')");
                else
                   consulta2.exec("select min(periodo) from calendarios_detalle where id_calendario='"+cal+"' and modalidad='"+consulta.value(0).toString()+"' and fecha_ini > to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy')");
                while(consulta2.next())
                {
                    if(consulta2.value(0).toInt()>1)
                        periodo=consulta2.value(0).toInt()-1;
                    else
                        periodo=consulta2.value(0).toInt();
                }
                /*if(consulta.value(0).toString()=="19")
                    consulta2.exec("select id_seccion,horario from secciones where nivel='"+tr("%1").arg(i)+"' and id_metodo='"+s+"' and modalidad='"+consulta.value(0).toString()+"' and periodo >= (select periodo from calendarios_detalle where id_calendario='"+cal+"' and modalidad='1' and fecha_ini <= to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy') and fecha_fin >= to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy')) and status='V'");
                else*/
                consulta2.exec("select id_seccion,horario from secciones where nivel='"+tr("%1").arg(i)+"' and id_metodo='"+s+"' and modalidad='"+consulta.value(0).toString()+"' and periodo >='"+tr("%1").arg(periodo)+"' and status='V'");
                while(consulta2.next())
                {
                    if(consulta.value(0).toInt()<10)
                        mod="0"+consulta.value(0).toString();
                    else
                        mod=consulta.value(0).toString();

                    if(consulta2.value(0).toString().right(1).toInt()<10)
                        seccion="0"+consulta2.value(0).toString().right(1);
                    else
                        seccion=consulta2.value(0).toString().right(1);

                    if(i<10)
                        factura.item->addItem("0"+tr("%1").arg(i)+"-"+consulta2.value(1).toString()+"-"+mod+"-"+seccion);
                    else
                        factura.item->addItem(tr("%1").arg(i)+"-"+consulta2.value(1).toString()+"-"+mod+"-"+seccion);
                }
            }
        }

        connect(factura.item,SIGNAL(currentIndexChanged(QString)),this,SLOT(llenarCurso(QString)));
    }
    else
    {
        factura.item->clear();
        factura.item->addItem("-");
        if(factura.tp->currentText()=="CERTIFICACION")
        {
            consulta2.exec("select id from cohorte_certi where id_certi='"+s+"' and status='V' order by id");
            while(consulta2.next())
            {
                factura.item->addItem(consulta2.value(0).toString());
            }
            connect(factura.item,SIGNAL(currentIndexChanged(QString)),this,SLOT(llenarCerti(QString)));
        }
        else
        {
            consulta2.exec("select id from cohortes where id_diplomado='"+s+"' and status='V' order by id");
            while(consulta2.next())
            {
                factura.item->addItem(consulta2.value(0).toString());
            }

            if(factura.tp->currentText()=="PREINSCRIPCION")
                connect(factura.item,SIGNAL(currentIndexChanged(QString)),this,SLOT(llenarPreDiplomado(QString)));
            else if(factura.tp->currentText()=="CUOTA")
                connect(factura.item,SIGNAL(currentIndexChanged(const QString)),this,SLOT(setPrecioCuota(const QString)));
                //factura.item->setCurrentIndex(factura.item->findText(factura.f_curso_2->text()));
            else
                connect(factura.item,SIGNAL(currentIndexChanged(QString)),this,SLOT(llenarDiplomado(QString)));
        }

        factura.item->setCurrentIndex(factura.item->findText(factura.f_seccion_2->text()));
    }
}


/** Verifica si la seccion seleccionada tiene cupos disponibles; de ser así, llena la descripcion del item con el nivel
 * y horario seleccionados.
 * @param s Texto actual del QComboBox con los codigos de secciones.
 */

void procesos_caja::llenarCurso(QString s)
{
    int tope,actual;
    QString nivel,horario,mod,price,salon,metodo,cal;
    float libro,cd,guia,cuota;
    QSqlQuery consulta,consulta2;

    libro=guia=cd=0;
    nivel=s.left(2);
    salon=s.right(1);
    horario=s.remove(s.lastIndexOf("-"),3);
    mod=horario.right(2);
    horario= s.remove(nivel+"-",Qt::CaseInsensitive);
    //horario=horario.remove("-"+mod,Qt::CaseInsensitive);
    horario=horario.remove(horario.lastIndexOf("-"+mod),3);

    consulta.exec("select cuotas,id_calendario from metodos where id_metodo='"+f_curso+"'");
    while(consulta.next())
    {
        cuota=consulta.value(0).toDouble();
        cal=consulta.value(1).toString();
    }

    consulta.exec("select id_seccion,tope,cant_actual,periodo,to_char(fec_inicio,'dd-mm-yyyy') from secciones where nivel='"+nivel+"' and horario='"+horario+"' and id_metodo='"+f_curso+"' and modalidad='"+mod+"' and id_seccion like '%"+salon+"'");
    while(consulta.next())
    {
        f_seccion=consulta.value(0).toString();
        tope= consulta.value(1).toInt();
        actual=consulta.value(2).toInt();
        f_fecha=consulta.value(4).toString();
        QMessageBox::information(0,"Tope - Actual",tr("%1-%2").arg(tope).arg(actual));
    }

    if((prog_academico=="2")&&(mod=="02"||mod=="19"||mod=="03"))
        consulta.exec("select precio2 from precios where item='"+f_curso+"'");
    else
        consulta.exec("select precio1 from precios where item='"+f_curso+"'");

    while(consulta.next())
    {
        f_costo.setNum(consulta.value(0).toDouble()/cuota,'g',10);
    }

    if(actual==tope)
        QMessageBox::information(0,"","Seccion Llena");
    else
    {
        if(prog_academico=="4")
            price.setNum(f_costo.toDouble()*2,'g',10);
        else
        {
            if((f_curso=="AEC")||(f_curso=="AEC-J"))
            {
                metodo="AEC";
            }
            else
            {
                metodo=f_curso;
                //El precio del libro va aqui si no va incluido en el paquete AEC
            }
            consulta.exec("select id_mat from materiales where id_curso='"+metodo+"' and tipo='L'");
            while(consulta.next())
            {
                consulta2.exec("select precio1 from precios where item='"+consulta.value(0).toString()+"'");
                while(consulta2.next())
                {
                    libro=consulta2.value(0).toDouble();
                }
            }
            consulta.exec("select min(id_mat) from materiales where id_curso='"+metodo+"' and tipo='G'");
            if(consulta.next())
            {
                consulta2.exec("select precio1 from precios where item='"+consulta.value(0).toString()+"'");
                while(consulta2.next())
                {
                    guia=consulta2.value(0).toDouble();
                }
            }
            consulta.exec("select min(id_mat) from materiales where id_curso='"+metodo+"' and tipo='CD'");
            if(consulta.next())
            {
                consulta2.exec("select precio1 from precios where item='"+consulta.value(0).toString()+"'");
                while(consulta2.next())
                {
                    cd=consulta2.value(0).toDouble();
                }
            }
            //PARA AMERICAN ENGLISH LIBRO=0. PROBAR
            price.setNum(f_costo.toDouble()+libro+guia+cd,'g',10);
        }
        consulta.exec("select descripcion from modalidades where id_modalidad='"+mod+"'");
        while(consulta.next())
        {
            mod=consulta.value(0).toString();
        }
        factura.descripcion->setText(f_curso+" NIVEL "+nivel+" "+horario+" "+f_fecha+" "+mod+" "+salon);
        if(!price.contains(".",Qt::CaseInsensitive)&&!price.contains(",",Qt::CaseInsensitive))
            price+=".00";
        factura.precio->setText(price);
    }
}


/**
 *
 */

void procesos_caja::guardarFactura(QList<QList<QString> > items,QString factura,QString cedula,QString nombre,QString monto,QString piva,QString iva,QString dir,QString cedula2,QString nombre2,QString matricula,QString recibo)
{
    QSqlQuery consulta,consulta2;
    QSqlQuery query(mysql);
    QList<QString> aux;
    QString precio,subtotal,tipo,cuota,evento,actual,nivel,cencos,sucursal,codigo;
    float acumulado;

    int i;
    //piva.replace(QString("."), QString(","));
    //iva.replace(QString("."), QString(","));
    //monto.replace(QString("."), QString(","));

    consulta.exec("select cencos from companias where id='"+compania+"'");
    while(consulta.next())
    {
        cencos=consulta.value(0).toString();
    }

    if(!query.exec("insert into dpdoccli values('FAV','"+cedula2+"','"+factura+"',str_to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','%d-%m-%Y'),'000001','000001','"+monto+"','0','0','0','"+cencos+"','Bs','Contado','0',str_to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','%d-%m-%Y'),'"+QTime::currentTime().toString("hh:mm:ss")+"','0','1.0','0','0','PA','D','"+recibo+"','1','"+factura+"','N','TRANSP','"+usuario+"','','1','A','1','LIBRE','',str_to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','%d-%m-%Y'),'0','','0','','N','V','','','0','0','0','','"+monto+"','','','0','','0','','000000000000','0','0')"))
        QMessageBox::critical(0,"Error Factura",query.lastError().text());
    else
        query.exec("commit");
    if(!query.exec("insert into dpdoccli values('FAV','"+cedula2+"','"+factura+"',str_to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','%d-%m-%Y'),'000001','000001','"+monto+"','0','0','0','"+cencos+"','Bs','Contado','0',str_to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','%d-%m-%Y'),'"+QTime::currentTime().toString("hh:mm:ss")+"','0','1.0','0','0','AC','P','"+recibo+"','-1','"+factura+"','N','TRANSP','"+usuario+"','','1','A','1','LIBRE','',str_to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','%d-%m-%Y'),'0','','0','','N','P','','','0','0','0','','0','','','0','','0','','000000000000','0','0')"))
        QMessageBox::critical(0,"Error Factura",query.lastError().text());
    else
        query.exec("commit");

    /*if(!consulta.exec("insert into factura values('"+factura+"','FA','"+cedula2+"','"+nombre+"','1',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+monto+"','"+piva+"','"+iva+"','0','0','"+dir+"','"+cedula+"','V','1','0','"+programa+"','s','"+nombre2+"','"+prog_academico+"','"+usuario+"')"))
        QMessageBox::critical(0,"Error Factura",consulta.lastError().text());
    else
        consulta.exec("commit");*/

    for(i=0;i<items.size();i++)
    {
        aux=items[i];
        precio= aux[4];
        //precio.replace(QString("."), QString(","));
        subtotal= aux[5];
        //subtotal.replace(QString("."), QString(","));
        tipo=aux[0];

        sucursal="0001"; //Si no se va a trabajar por sucursales. Sucursal 001 es fundauc y los almacenes estan asociados al codigo de 'companias'.

        //Insertar en dpmovinv aqui
        if(tipo=="C")
        {
            consulta.exec("select id_metodo from secciones where id_seccion='"+aux[1]+"'");
            while(consulta.next())
            {
                codigo=consulta.value(0).toString();
            }
            QMessageBox::information(0,"","insert into dpmovinv values ('"+codigo+"','','"+cedula2+"','"+factura+"',str_to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','%d-%m-%Y'),'S000','UND','"+aux[3]+"',0,'"+usuario+"','"+subtotal+"','0','"+precio+"',0,'','"+iva+"',0,0,'','','I','"+tr("%1").arg(i+1)+"','A','FAV','"+QTime::currentTime().toString("hh:mm:ss")+"','1','1','"+sucursal+"','"+compania+"','EX','-"+aux[3]+"','-"+aux[3]+"','-"+aux[3]+"','','V','"+cencos+"',0,0,'',0,0,0,'',0,0,0,0,0,0,0,0,0,0,str_to_date('','%d-%m-%Y'),'','','',0,0,0,0)");
            query.prepare("insert into dpmovinv values ('"+codigo+"','','"+cedula2+"','"+factura+"',str_to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','%d-%m-%Y'),'S000','UND','"+aux[3]+"',0,'"+usuario+"','"+subtotal+"','0','"+precio+"',0,'','"+iva+"',0,0,'','','I','"+tr("%1").arg(i+1)+"','A','FAV','"+QTime::currentTime().toString("hh:mm:ss")+"','1','1','"+sucursal+"','"+compania+"','EX','-"+aux[3]+"','-"+aux[3]+"','-"+aux[3]+"','','V','"+cencos+"',0,0,'',0,0,0,'',0,0,0,0,0,0,0,0,0,0,str_to_date('','%d-%m-%Y'),'','','',0,0,0,0)");
        }
        else if(tipo=="L" || tipo=="G" || tipo=="CD")
        {
            query.prepare("insert into dpmovinv values ('"+codigo+"','','"+cedula2+"','"+factura+"',str_to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','%d-%m-%Y'),'S000','UND','"+aux[3]+"',0,'"+usuario+"','"+subtotal+"','0','"+precio+"',0,'','"+iva+"',0,0,'','','I','"+tr("%1").arg(i+1)+"','A','FAV','"+QTime::currentTime().toString("hh:mm:ss")+"','1','1','"+sucursal+"','"+compania+"','EX','-"+aux[3]+"','-"+aux[3]+"','-"+aux[3]+"','','V','"+cencos+"',0,0,'',0,0,0,'',0,0,0,0,0,0,0,0,0,0,str_to_date('','%d-%m-%Y'),'','','',0,0,0,0)");
        }
        else
            query.prepare("insert into dpmovinv values ('"+codigo+"','','"+cedula2+"','"+factura+"',str_to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','%d-%m-%Y'),'S000','UND','"+aux[3]+"',0,'"+usuario+"','"+subtotal+"','0','"+precio+"',0,'','"+iva+"',0,0,'','','I','"+tr("%1").arg(i+1)+"','A','FAV','"+QTime::currentTime().toString("hh:mm:ss")+"','1','1','"+sucursal+"','"+compania+"','EX',0,0,0,'','V','"+cencos+"',0,0,'',0,0,0,'',0,0,0,0,0,0,0,0,0,0,str_to_date('','%d-%m-%Y'),'','','',0,0,0,0)");

        if(!query.exec())
            QMessageBox::critical(0,"Error mov inv",query.lastError().text());
        else
            query.exec("commit");

        /*if(!consulta.exec("insert into detalle_factura values (detalle_factura_sec.nextval,'"+programa+"','"+factura+"','"+aux[0]+"','"+aux[1]+"','"+aux[2]+"','"+aux[3]+"','"+precio+"','0','"+subtotal+"','0')"))
            QMessageBox::critical(0,"Error Detalle Factura",consulta.lastError().text());
        else
            consulta.exec("commit");*/

        if(tipo=="C") //CURSO
        {
            int nivel=0;
            cuota.setNum(1);
            consulta.exec("select nivel from secciones where id_seccion=(select id_seccion from ficha_academica where matricula='"+matricula+"' and id_evento='2' and status='V')");
            while(consulta.next())
            {
                nivel=consulta.value(0).toInt();
            }
            if(!consulta.exec("update ficha_academica set status='H' where matricula='"+matricula+"'"))
                QMessageBox::critical(0,"Error 2",consulta.lastError().text());
            else
                consulta.exec("commit");

            if(!consulta.exec("update ficha_pago set status='H' where matricula='"+matricula+"'"))
                QMessageBox::critical(0,"Error 2",consulta.lastError().text());
            else
                consulta.exec("commit");

            if(prog_academico=="4")
                cuota.setNum(2);

            if(!consulta.exec("insert into ficha_academica values(ficha_academica_s.nextval,'2',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'0','N','"+f_seccion+"','"+f_curso+"','"+matricula+"','V',to_date('"+f_fecha+"','dd-mm-yyyy'))"))
                QMessageBox::critical(0,"Error Ficha Academica",consulta.lastError().text());
            else
                consulta.exec("commit");

            consulta.exec("select cant_actual,nivel from secciones where id_seccion='"+f_seccion+"'");
            while(consulta.next())
            {
                actual.setNum(consulta.value(0).toInt()+1);

                if(!consulta2.exec("insert into ficha_pago values(ficha_pago_s.nextval,'2',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+subtotal+"','"+programa+"','"+factura+"','"+aux[2]+"','"+cuota+"','"+matricula+"','V','"+tr("%1").arg(consulta.value(1).toInt())+"')"))
                    QMessageBox::critical(0,"Error Ficha Pago",consulta2.lastError().text());
                else
                    consulta2.exec("commit");

                if(nivel==consulta.value(1).toInt())
                {
                    if(consulta2.exec("update estudiante set id_tipo_est='2' where matricula='"+matricula+"'"))
                        consulta2.exec("commmit");
                }
                else
                {
                    if(consulta2.exec("update estudiante set id_tipo_est='1' where matricula='"+matricula+"'"))
                        consulta2.exec("commmit");
                }
            }

            if(!consulta.exec("update secciones set cant_actual='"+actual+"' where id_seccion='"+f_seccion+"'"))
                QMessageBox::critical(0,"Error Update Seccion",consulta.lastError().text());
            else
                consulta.exec("commit");

        }
        else if(tipo=="M") //MATRICULA
        {
            if(!consulta.exec("insert into ficha_pago values(ficha_pago_s.nextval,'1',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+subtotal+"','"+programa+"','"+factura+"','"+aux[2]+"','0','"+matricula+"','V','1')"))
                QMessageBox::critical(0,"Error Ficha Pago",consulta.lastError().text());
            else
                consulta.exec("commit");
        }
        else if(tipo=="DP") //DIPLOMADO
        {
            if(!consulta.exec("update ficha_academica set status='H' where matricula='"+matricula+"'"))
                QMessageBox::critical(0,"Error 6",consulta.lastError().text());
            else
                consulta.exec("commit");

            if(!consulta.exec("update ficha_pago_cfp set status='H' where matricula='"+matricula+"'"))
                QMessageBox::critical(0,"Error 6",consulta.lastError().text());
            else
                consulta.exec("commit");

            if(!consulta.exec("insert into ficha_pago_cfp values(ficha_pago_cfp_s.nextval,'2',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+subtotal+"','"+programa+"','"+factura+"','"+aux[2]+"','"+matricula+"','0','V','"+subtotal+"','"+f_curso+"')"))
                QMessageBox::critical(0,"Error Ficha Pago CFP",consulta.lastError().text());
            else
                consulta.exec("commit");

            if(!consulta.exec("insert into ficha_academica values(ficha_academica_s.nextval,'2',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'0','N','"+f_seccion+"','"+f_curso+"','"+matricula+"','V','')"))
                QMessageBox::critical(0,"Error Ficha Academica",consulta.lastError().text());
            else
                consulta.exec("commit");

            consulta.exec("select cant_actual from cohortes where id='"+f_seccion+"'");
            while(consulta.next())
            {
                if(!consulta2.exec("update cohortes set cant_actual='"+tr("%1").arg(consulta.value(0).toInt()+1)+"' where id ='"+f_seccion+"'"))
                    QMessageBox::critical(0,"Error Tope Diplomado",consulta.lastError().text());
                else
                {
                    consulta2.exec("commit");
                    consulta2.exec("select maximo from diplo_temp where id_diplomado='"+f_curso+"'");
                    while(consulta2.next())
                    {
                        if(consulta2.value(0).toInt()==consulta.value(0).toInt()+1)
                        {
                            if(duplicarCohorte(f_seccion))
                                QMessageBox::information(0,"Atencion","Se ha creado una nueva cohorte.");
                        }
                    }
                }
            }
        }
        else if(tipo=="PRE") //PREINSCRIPCION
        {
            if(!consulta.exec("update ficha_academica set status='H' where matricula='"+matricula+"'"))
                QMessageBox::critical(0,"Error 6",consulta.lastError().text());
            else
                consulta.exec("commit");

            if(!consulta.exec("update ficha_pago_cfp set status='H' where matricula='"+matricula+"'"))
                QMessageBox::critical(0,"Error 6",consulta.lastError().text());
            else
                consulta.exec("commit");

            if(!consulta.exec("insert into ficha_pago_cfp values(ficha_pago_cfp_s.nextval,'47',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+subtotal+"','"+programa+"','"+factura+"','"+aux[2]+"','"+matricula+"','0','V','"+subtotal+"','"+f_curso+"')"))
                QMessageBox::critical(0,"Error Ficha Pago CFP",consulta.lastError().text());
            else
                consulta.exec("commit");

            if(!consulta.exec("insert into ficha_academica values(ficha_academica_s.nextval,'47',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'0','N','"+f_seccion+"','"+f_curso+"','"+matricula+"','V','')"))
                QMessageBox::critical(0,"Error Ficha Academica",consulta.lastError().text());
            else
                consulta.exec("commit");
        }
        else if(tipo=="CU") //CUOTA DIPLOMADO
        {
            consulta.exec("select ult_cuota,acumulado from ficha_pago_cfp where renglon =(select max(renglon) from ficha_pago_cfp where matricula='"+matricula+"')");
            while(consulta.next())
            {
                cuota.setNum(consulta.value(0).toInt()+ aux[3].toInt());
                acumulado=consulta.value(1).toDouble();
            }
            if(!consulta.exec("insert into ficha_pago_cfp values(ficha_pago_cfp_s.nextval,'18',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+subtotal+"','"+programa+"','"+factura+"','"+aux[2]+"','"+matricula+"','"+cuota+"','V','"+tr("%1").arg(acumulado+subtotal.toDouble())+"','"+f_curso+"')"))
                QMessageBox::critical(0,"Error Ficha Pago CFP",consulta.lastError().text());
            else
                consulta.exec("commit");
        }
        else if(tipo=="PC") //CERTIFICACION
        {
            double restante;
            QMessageBox::information(0,"","select pagado,restante from cohorte_certi where id='"+f_seccion+"'");
            consulta.exec("select pagado,restante from cohorte_certi where id='"+f_seccion+"'");
            while(consulta.next())
            {
                acumulado=consulta.value(0).toDouble();
                restante=consulta.value(1).toDouble();
            }
            if(!consulta.exec("update cohorte_certi set pagado='"+tr("%1").arg(acumulado+subtotal.toDouble())+"',restante='"+tr("%1").arg(restante-subtotal.toDouble())+"' where id='"+f_seccion+"'"))
                 QMessageBox::critical(0,"Error Ficha Pago",consulta.lastError().text());
            else
                consulta.exec("commit");
        }
        else if(tipo=="CI") //CUOTA IDIOMAS
        {
            consulta.exec("select cuota_o_libro,nivel from ficha_pago where renglon =(select max(renglon) from ficha_pago where matricula='"+matricula+"')");
            while(consulta.next())
            {
                cuota.setNum(consulta.value(0).toInt()+ aux[3].toInt());
                nivel=consulta.value(1).toString();
            }
            if(!consulta.exec("insert into ficha_pago values(ficha_pago_s.nextval,'18',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+subtotal+"','"+programa+"','"+factura+"','"+aux[2]+"','"+cuota+"','"+matricula+"','V','"+nivel+"')"))
                QMessageBox::critical(0,"Error Ficha Pago",consulta.lastError().text());
            else
                consulta.exec("commit");
        }
        else //RESTO: INVENTARIO SOLO AFECTA CDS, GUIAS, LIBROS
        {
            if(prog_academico=="6")
            {
                return;
            }
            else if(prog_academico=="3")
            {
                if(aux[1]=="IDN")
                {
                    if(!consulta.exec("update ficha_academica set status='H' where matricula='"+matricula+"' and id_evento='43'"))
                        QMessageBox::critical(0,"Error 6",consulta.lastError().text());
                    else
                        consulta.exec("commit");
                    if(!consulta.exec("update ficha_pago_cfp set status='H' where matricula='"+matricula+"' and id_evento='43'"))
                        QMessageBox::critical(0,"Error 6",consulta.lastError().text());
                    else
                        consulta.exec("commit");
                }
                else if(tipo=="D")
                {
                    consulta.exec("select ult_cuota,acumulado from ficha_pago_cfp where renglon =(select max(renglon) from ficha_pago_cfp where matricula='"+matricula+"')");
                    while(consulta.next())
                    {
                        cuota.setNum(consulta.value(0).toInt());
                        acumulado=consulta.value(1).toDouble();
                    }
                    if(!consulta.exec("insert into ficha_pago_cfp values(ficha_pago_cfp_s.nextval,'53',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+subtotal+"','"+programa+"','"+factura+"','"+aux[2]+"','"+matricula+"','"+cuota+"','V','"+tr("%1").arg(acumulado+subtotal.toDouble())+"','"+f_curso+"')"))
                        QMessageBox::critical(0,"Error Ficha Pago CFP",consulta.lastError().text());
                    else
                        consulta.exec("commit");
                }
                else
                {
                    consulta.exec("select ult_cuota,acumulado from ficha_pago_cfp where renglon =(select max(renglon) from ficha_pago_cfp where matricula='"+matricula+"')");
                    while(consulta.next())
                    {
                        cuota=consulta.value(0).toString();
                        acumulado=consulta.value(1).toDouble();
                    }
                    consulta.exec("select evento from materiales where id_mat='"+aux[1]+"'");
                    while(consulta.next())
                    {
                        evento=consulta.value(0).toString();
                    }
                    if(!consulta.exec("insert into ficha_pago_cfp values(ficha_pago_cfp_s.nextval,'"+evento+"',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+subtotal+"','"+programa+"','"+factura+"','"+aux[2]+"','"+matricula+"','"+cuota+"','V','"+tr("%1").arg(acumulado)+"','"+f_curso+"')"))
                        QMessageBox::critical(0,"Error Ficha Pago CFP",consulta.lastError().text());
                    else
                        consulta.exec("commit");
                }
            }
            else
            {
                if(aux[1]=="IDN")
                {
                    if(!consulta.exec("update ficha_academica set status='H' where matricula='"+matricula+"' and id_evento='43'"))
                        QMessageBox::critical(0,"Error 6",consulta.lastError().text());
                    else
                        consulta.exec("commit");
                    if(!consulta.exec("update ficha_pago set status='H' where matricula='"+matricula+"' and id_evento='43'"))
                        QMessageBox::critical(0,"Error 6",consulta.lastError().text());
                    else
                        consulta.exec("commit");
                }
                else
                {
                    consulta.exec("select cuota_o_libro,nivel from ficha_pago where renglon =(select max(renglon) from ficha_pago where matricula='"+matricula+"')");
                    while(consulta.next())
                    {
                        cuota=consulta.value(0).toString();
                        nivel=consulta.value(1).toString();
                    }
                    consulta.exec("select evento from materiales where id_mat='"+aux[1]+"'");
                    while(consulta.next())
                    {
                        evento=consulta.value(0).toString();
                    }
                    if(!consulta.exec("insert into ficha_pago values(ficha_pago_s.nextval,'"+evento+"',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+subtotal+"','"+programa+"','"+factura+"','N','"+cuota+"','"+matricula+"','V','"+nivel+"')"))
                        QMessageBox::critical(0,"Error Ficha Pago",consulta.lastError().text());
                    else
                        consulta.exec("commit");
                }
            }
        }
    }
}


/**
 *
 */

QList<QString> procesos_caja::paginate(QList<QList<QString> > items,QList<QList<QString> > pago_items,QString razon, QString rif, QString telefono, QString dir, QString iva, QString piva, int fact, QString cedula_est, QString nombre_est, QString matricula, QString condicion, int recibo)
{
    int i;
    int pag=0;
    QList<QString> facturas;
    QList<QList<QString> > aux;
    QList<QList<QString> > new_items(items);
    QString subtotal,total,factura,reci;
    double suma=0;
    reci.setNum(recibo);

    while(new_items.size()>7)
    {
        aux.clear();
        for(i=0;i<7;i++)
        {
            aux.append(new_items.first());
            suma= suma + new_items.first().last().toDouble();
            new_items.removeFirst();
        }
        subtotal.setNum(suma,'g',10);
        total.setNum(suma,'g',10);
        suma=0;
        factura.setNum(fact);
        facturas.append(factura);

        if(!subtotal.contains(".",Qt::CaseInsensitive)&&!subtotal.contains(",",Qt::CaseInsensitive))
            subtotal= subtotal+".00";
        if(!total.contains(".",Qt::CaseInsensitive)&&!total.contains(",",Qt::CaseInsensitive))
            total= total+".00";

        guardarFactura(aux,factura,rif,razon,total,piva,iva,dir,cedula_est,nombre_est,matricula,reci);
        crearFactura(aux,pago_items,pag,razon,rif,telefono,dir,subtotal,iva,total,factura,false,cedula_est,nombre_est,condicion);
        fact++;
    }
    if(new_items.size()>0)
    {
        for(i=0;i<new_items.size();i++)
            suma= suma + new_items.at(i).last().toDouble();

        subtotal.setNum(suma,'g',10);
        total.setNum(suma,'g',10);
        factura.setNum(fact);
        facturas.append(factura);

        if(!subtotal.contains(".",Qt::CaseInsensitive)&&!subtotal.contains(",",Qt::CaseInsensitive))
            subtotal= subtotal+".00";
        if(!total.contains(".",Qt::CaseInsensitive)&&!total.contains(",",Qt::CaseInsensitive))
            total= total+".00";

        guardarFactura(new_items,factura,rif,razon,total,piva,iva,dir,cedula_est,nombre_est,matricula,reci);
    }
    crearFactura(new_items,pago_items,pag,razon,rif,telefono,dir,subtotal,iva,total,factura,false,cedula_est,nombre_est,condicion);
    return facturas;
}


/**
 *
 */

int procesos_caja::determinarClaseDoc()
{
    QSqlQuery consulta("select clase from clase_doc_prog where id_compania='"+compania+"' and id_programa='"+prog_academico+"'");
    while(consulta.next())
    {
        return consulta.value(0).toInt();
    }
    return 0;
}


/**
 *
 */

void procesos_caja::descuento(QString s)
{
    QSqlQuery consulta,consulta2;
    QString desc,cantidad;
    float porcentaje;
    int cuotas=0;
    QString metodo;

    consulta.exec("select descripcion from materiales where id_mat='"+s+"'");
    while(consulta.next())
    {
        factura.descripcion->setText(consulta.value(0).toString());
    }
    cantidad="1";
    if(s=="DL")
    {
        consulta.exec("select id_mat from materiales where tipo='L' and id_curso='"+factura.metodo->currentText()+"'");
        if(consulta.next())
        {
            consulta2.exec("select precio1 from precios where item='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                desc=consulta2.value(0).toString();
            }
        }
    }
    else if(s=="DCD")
    {
        consulta.exec("select id_mat from materiales where tipo='CD' and id_curso='"+factura.metodo->currentText()+"'");
        if(consulta.next())
        {
            consulta2.exec("select precio1 from precios where item='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                desc=consulta2.value(0).toString();
            }
        }
    }
    else if((s=="DFAM")||(s=="DPUC")||(s=="DEUC")||(s=="DESUC"))//Arreglar!
    {
        cantidad=factura.f_tabla->item(factura.f_tabla->rowCount()-1,3)->text();
        if(prog_academico=="3")
        {
            if(factura.f_tabla->item(factura.f_tabla->rowCount()-1,0)->text()=="CU")
                consulta.exec("select costo_cuota from cohortes where id='"+factura.f_tabla->item(factura.f_tabla->rowCount()-1,1)->text()+"'");
            else
                consulta.exec("select inicial from cohortes where id='"+factura.f_tabla->item(factura.f_tabla->rowCount()-1,1)->text()+"'");
            while(consulta.next())
            {
                consulta2.exec("select precio1 from precios where item='"+s+"'");
                while(consulta2.next())
                {
                    porcentaje=consulta2.value(0).toDouble();
                    desc.setNum((consulta.value(0).toDouble())*(porcentaje/100),'g',10);
                }
            }
        }
        else
        {
            consulta.exec("select cuotas from metodos where id_metodo='"+factura.metodo->currentText()+"'");
            while(consulta.next())
            {
                cuotas=consulta.value(0).toInt();
            }
            if(cuotas==1)
            //if((factura.metodo->currentText()=="AEC")||(factura.metodo->currentText()=="AEC-J")||(factura.metodo->currentText()=="CAV")||(factura.metodo->currentText()=="CAA"))
            {
                consulta.exec("select precio3 from precios where item='"+factura.metodo->currentText()+"'");
            }
            else
            {
                if(factura.metodo->currentText()=="")
                {
                    consulta.exec("select cuotas from metodos where id_metodo='"+factura.f_tabla->item(factura.f_tabla->rowCount()-1,1)->text()+"'");
                    while(consulta.next())
                    {
                        cuotas=consulta.value(0).toInt();
                    }
                    consulta.exec("select precio1 from precios where item='"+factura.f_tabla->item(factura.f_tabla->rowCount()-1,1)->text()+"'");
                }
                else
                    consulta.exec("select precio1 from precios where item='"+factura.metodo->currentText()+"'");
            }
            while(consulta.next())
            {
                consulta2.exec("select precio1 from precios where item='"+s+"'");
                while(consulta2.next())
                {
                    porcentaje=consulta2.value(0).toDouble();
                    desc.setNum((consulta.value(0).toDouble()/cuotas)*(porcentaje/100),'g',10);
                }
            }
        }
    }
    else if(s=="DDA")
    {
        consulta.exec("select precio1 from precios where item='"+s+"'");
        while(consulta.next())
        {
            desc.setNum(consulta.value(0).toDouble(),'g',10);
        }
    }
    else if(s=="DPP")
    {
        consulta.exec("select precio1 from precios where item='"+s+"'");
        while(consulta.next())
        {
            porcentaje=consulta.value(0).toDouble();
            desc.setNum(factura.f_tabla->item(factura.f_tabla->rowCount()-1,5)->text().toFloat()*porcentaje/100,'g',10);
        }
    }
    else
    {
        consulta.exec("select precio1 from precios where item='"+s+"'");
        while(consulta.next())
        {
            porcentaje=consulta.value(0).toDouble();
            desc.setNum(factura.f_subtotal_2->text().toFloat()*porcentaje/100,'g',10);
        }
    }
    factura.cantidad->setText(cantidad);
    factura.precio->setText("-"+desc);
    factura.bs->setText((tr("-%1").arg(desc.toFloat()*cantidad.toFloat())));

    agregarItem();
}


/**
 *
 */

void procesos_caja::prontoPago(QString cuota,QString diplo)
{
    QSqlQuery consulta;
    consulta.exec("select fecha_corte from calendario_cfp where cuota='"+cuota+"' and cohorte='"+diplo+"'");
    while(consulta.next())
    {
        if(QDate::currentDate()<consulta.value(0).toDate())
        {
            QMessageBox::information(0,"Atención","Corresponde Descuento por Pronto Pago");
            //descuento("DPP");
        }
    }
}


/**
 *
 */

void procesos_caja::imprimirFactura()
{
    int row,i,correlativo,recibo;
    QString pago,nfactura,monto2,cencos;
    QString banco,diferencia,texto,tiva,ttotal,clase,cuenta,codban,ctacon;
    double total,iva,monto,suma;
    QList<QString> facturas;
    suma=0;

    //crearConexionMysql(); //Para abrir bd de datapro
    QSqlQuery query(mysql);
    QSqlQuery consulta;

    query.exec("select max(doc_numero + 0) from dpdoccli");
    while(query.next())
    {
        nfactura.setNum(query.value(0).toInt()+1);
    }

    consulta.exec("select cencos from companias where id='"+compania+"'");
    while(consulta.next())
    {
        cencos=consulta.value(0).toString();
    }

    monto = factura.f_total_2->text().toFloat();
    row= factura.f_tabla0->rowCount();

    for(i=0;i<row;i++)
    {
        suma = suma + factura.f_tabla0->item(i,4)->text().toFloat();
    }

    if(!proforma)
    {
        if(monto-suma>0.01)
        {
            QMessageBox::critical(0,"Atencion!","El monto depositado es menor al monto a cancelar");
        }
        else
        {
            if(monto<suma)
            {
                diferencia.setNum(suma-monto,'g',10);
                diferencia.replace(QString(","), QString("."));

                if(!diferencia.contains(".",Qt::CaseInsensitive)&&!diferencia.contains(",",Qt::CaseInsensitive))
                    diferencia= diferencia+".00";
                int row = factura.f_tabla->rowCount();
                factura.f_tabla->insertRow(row);
                QTableWidgetItem *ni = new QTableWidgetItem(tr("ID"));
                factura.f_tabla->setItem(row,0,ni);
                ni = new QTableWidgetItem(tr("IDP"));
                factura.f_tabla->setItem(row,1,ni);
                ni = new QTableWidgetItem(tr("INGRESO DIFERIDO POSITIVO"));
                factura.f_tabla->setItem(row,2,ni);
                ni = new QTableWidgetItem(tr("1"));
                factura.f_tabla->setItem(row,3,ni);

                ni = new QTableWidgetItem(tr("%1").arg(diferencia));
                factura.f_tabla->setItem(row,4,ni);
                ni = new QTableWidgetItem(tr("%1").arg(diferencia));
                factura.f_tabla->setItem(row,5,ni);

                texto.setNum(factura.f_subtotal_2->text().toFloat() + suma-monto,'g',10);
                factura.f_subtotal_2->setText(texto);
                iva = (factura.f_subtotal_2->text().toFloat()*factura.f_iva_2->text().toFloat())/100;
                total = factura.f_subtotal_2->text().toFloat() + iva;
                tiva.setNum(iva,'g',10);
                ttotal.setNum(total,'g',10);
                factura.f_iva_2->setText(tiva);
                factura.f_total_2->setText(ttotal);

                QMessageBox::information(0,"Exceso","Bs. "+diferencia);
            }
            for(i=0;i<row;i++)
            {
                consulta.exec("select id_pago from forma_pago where descripcion='"+factura.f_tabla0->item(i,1)->text()+"'");
                while(consulta.next())
                {
                    pago = consulta.value(0).toString();//buscar id segun nombre
                }
                consulta.exec("select ctabco from bancos where nombre='"+factura.f_tabla0->item(i,2)->text()+"'");
                while(consulta.next())
                {
                    cuenta = consulta.value(0).toString();//buscar id segun nombre
                }

                query.exec("select max(rec_numero + 0) from dpreciboscli");
                while(query.next())
                {
                    recibo = query.value(0).toInt() + 1;
                }

                monto2=factura.f_tabla0->item(i,4)->text();
                clase.setNum(determinarClaseDoc());

                if((pago != "25")&&(prog_academico != "6"))
                {
                    query.exec("select bco_codigo,bco_cuenta from dpctabanco where bco_ctaban='"+cuenta+"'");
                    while(query.next())
                    {
                        codban=query.value(0).toString();
                        ctacon=query.value(1).toString();
                    }
                    query.exec("select ban_nombre from dpbancos where ban_codigo='"+codban+"'");
                    while(query.next())
                    {
                        banco=query.value(0).toString();
                    }

                    //el deposito
                    query.exec("select max(mob_numtra + 0) from dpctabancomov where mob_origen='REC' and mob_cuenta='"+cuenta+"' and mob_codbco='"+codban+"'");
                    while(query.next())
                    {
                        correlativo=query.value(0).toInt()+1;
                    }

                    if(!query.exec("insert into dpctabancomov values (str_to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','%d-%m-%Y'),'"+QTime::currentTime().toString("hh:mm:ss")+"','"+tr("%1").arg(monto)+"','"+tr("%1").arg(monto)+"','DEP','Cliente: "+factura.f_nombre_5->text()+"','"+ctacon+"','0','000001','',str_to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','%d-%m-%Y'),'"+codban+"','"+cuenta+"','"+factura.f_tabla0->item(i,3)->text()+"','REC','"+tr("%1").arg(recibo)+"','"+tr("%1").arg(correlativo)+"',str_to_date('','%d-%m-%Y'),'1','','',str_to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','%d-%m-%Y'),'','0','0','0','"+cencos+"','','"+usuario+"','0','0','','','0','','0')"))
                    {
                        QMessageBox::critical(0,"Error Banco Mov",query.lastError().text());
                        return;
                    }
                    else
                        query.exec("commit");
                }
            }
            facturas= paginate(orderItems(),pagoItems(),factura.f_nombre_5->text(),factura.f_cedula_5->text(),factura.f_telf_3->text(),factura.f_direccion->text(),factura.f_iva_2->text(),factura.f_piva_2->text(),nfactura.toInt(),factura.f_cedula_4->text(),factura.f_nombre_4->text(),factura.f_matricula->text(),factura.f_condicion_2->text(),recibo);

            //Insert into dpreciboscli
            QMessageBox::information(0,"","insert into dpreciboscli values('"+tr("%1").arg(correlativo)+"','000001','"+factura.f_cedula_5->text()+"','000001','0',str_to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','%d-%m-%Y'),'P','caja','0','Bs','"+QDateTime::currentDateTime().toString("hh:mm:ss")+"','1','FAV','','','','"+cencos+"','','"+tr("%1").arg(monto)+"','0','0')");
            if(!query.exec("insert into dpreciboscli values('"+tr("%1").arg(recibo)+"','000001','"+factura.f_cedula_5->text()+"','000001','0',str_to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','%d-%m-%Y'),'P','caja','0','Bs','"+QDateTime::currentDateTime().toString("hh:mm:ss")+"','1','FAV','','','','"+cencos+"','','"+tr("%1").arg(monto)+"','0','0')"))
                QMessageBox::critical(0,"Error Recibo de Pago",query.lastError().text());
            else
                query.exec("commit");

            /*if(pago != "25")
            {
                for(i=0;i<row;i++)
                {
                    consulta.exec("select id_pago from forma_pago where descripcion='"+factura.f_tabla0->item(i,1)->text()+"'");
                    while(consulta.next())
                    {
                        pago = consulta.value(0).toString();
                    }
                    consulta.exec("select id_banco from bancos where nombre='"+factura.f_tabla0->item(i,2)->text()+"'");
                    while(consulta.next())
                    {
                        banco = consulta.value(0).toString();
                    }
                    for(j=0;j<facturas.size();j++)
                    {
                        if(!consulta.exec("insert into factura_deposito values('"+facturas.at(j)+"','"+factura.f_tabla0->item(i,3)->text()+"','"+banco+"','"+pago+"')"))
                            QMessageBox::critical(0,"Error Factura-Deposito",consulta.lastError().text());
                        else
                            consulta.exec("commit");
                    }
                }
            }*/
            nuevaFactura();
        }
    }
    else
    {
        facturas=paginate(orderItems(),pagoItems(),factura.f_nombre_5->text(),factura.f_cedula_5->text(),factura.f_telf_3->text(),factura.f_direccion->text(),factura.f_iva_2->text(),factura.f_piva_2->text(),nfactura.toInt(),factura.f_cedula_4->text(),factura.f_nombre_4->text(),factura.f_matricula->text(),factura.f_condicion_2->text(),recibo);

        if(!consulta.exec("insert into cuentas_por_cobrar values('"+factura.f_cedula_5->text()+"','"+tr("%1").arg(monto)+"','','0',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'','"+nfactura+"','"+prog_academico+"')"))
            QMessageBox::critical(0,"Error Cuenta por Cobrar",consulta.lastError().text());
        else
            consulta.exec("commit");
        nuevaFactura();
    }
}


void procesos_caja::cuentasPorCobrar()
{
    QSqlQuery consulta;
    frame = new QFrame();
    cuentas_cobro.setupUi(frame);
    container.workspace->setWidget(frame);
    rows= new QList<int>();

    cuentas_cobro.tabla->setColumnWidth(0,300);
    cuentas_cobro.tabla->setColumnWidth(1,90);
    cuentas_cobro.tabla->setColumnWidth(2,120);
    cuentas_cobro.tabla->setColumnWidth(3,80);
    cuentas_cobro.tabla->setColumnWidth(4,90);
    cuentas_cobro.tabla->setColumnWidth(5,100);

    cuentas_cobro.tabla2->setColumnWidth(0,80);
    cuentas_cobro.tabla2->setColumnWidth(1,100);
    cuentas_cobro.tabla2->setColumnWidth(2,240);
    cuentas_cobro.tabla2->setColumnWidth(3,90);
    cuentas_cobro.tabla2->setColumnWidth(4,80);

    cuentas_cobro.fechas->setDate(QDate::currentDate());
    cuentas_cobro.detallespago->addItem("-");
    consulta.exec("select descripcion from forma_pago order by descripcion");
    while(consulta.next())
    {
        cuentas_cobro.detallespago->addItem(consulta.value(0).toString());
    }
    connect(cuentas_cobro.rif,SIGNAL(returnPressed()),this,SLOT(buscarCuenta()));
    connect(cuentas_cobro.detallespago,SIGNAL(currentIndexChanged(const QString)),this,SLOT(pagoChanged2(const QString)));
    connect(cuentas_cobro.montos,SIGNAL(returnPressed()),this,SLOT(agregarDeposito2()));
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(procesarCuenta()));
    //connect(cuentas_cobro.tabla,SIGNAL(cellClicked(int,int)),this,SLOT(rowSelected(int,int)));
    container.botonGuardar->setEnabled(true);
}


void procesos_caja::rowSelected(int row,int column)
{
    if(rows->contains(row))
    {
        rows->removeAll(row);
        QMessageBox::information(0,"tamaño",tr("%1").arg(rows->size()));
        return;
    }
    rows->append(row);
    QMessageBox::information(0,"tamaño",tr("%1").arg(rows->size()));
}


void procesos_caja::buscarCuenta()
{
    QSqlQuery consulta,consulta2;
    QTableWidgetItem *ni;
    int i,row;
    for(i=cuentas_cobro.tabla->rowCount()-1;i>=0;i--)
        cuentas_cobro.tabla->removeRow(i);

    consulta.exec("select cliente,saldo,to_char(ultimo_pago,'dd-mm-yyyy'),ultimo_monto,ultimo_deposito,to_char(fec_emi,'dd-mm-yyyy'),id_fact from cuentas_por_cobrar where cliente='"+cuentas_cobro.rif->text()+"'");
    while(consulta.next())
    {
        row = cuentas_cobro.tabla->rowCount();
        cuentas_cobro.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(6).toString()));
        cuentas_cobro.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(5).toString()));
        cuentas_cobro.tabla->setItem(row,2,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        cuentas_cobro.tabla->setItem(row,3,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        cuentas_cobro.tabla->setItem(row,4,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        cuentas_cobro.tabla->setItem(row,5,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(4).toString()));
        cuentas_cobro.tabla->setItem(row,6,ni);
        consulta2.exec("select razon from empresas where rif='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            cuentas_cobro.tabla->setItem(row,1,ni);
        }
    }
}


void procesos_caja::procesarCuenta()
{
    QSqlQuery consulta;
    QString banco,pago,factura;
    double saldo,suma;
    int i;

    QList<QTableWidgetItem*> lista;
    lista=cuentas_cobro.tabla->selectedItems();

    suma=saldo=0;
    for(i=0;i<cuentas_cobro.tabla2->rowCount();i++)
    {
        consulta.exec("select id_banco from bancos where nombre ='"+cuentas_cobro.tabla2->item(i,2)->text()+"'");
        while(consulta.next())
        {
            banco=consulta.value(0).toString();
        }
        consulta.exec("select id_pago from forma_pago where descripcion ='"+cuentas_cobro.tabla2->item(i,1)->text()+"'");
        while(consulta.next())
        {
            pago=consulta.value(0).toString();
        }
        if(!consulta.exec("insert into documentos_trf values('1','DP','36','"+cuentas_cobro.tabla2->item(i,3)->text()+"','B','"+banco+"','',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'','"+cuentas_cobro.tabla2->item(i,4)->text()+"','','"+usuario+"','','',to_date('"+cuentas_cobro.tabla2->item(i,0)->text()+"','dd-mm-yyyy'),'','','','s','0','0.00','"+banco+"','','"+pago+"','','','','','','','beneficiario','','')"))
        {
            QMessageBox::critical(0,"Error Documentos Jupiter",consulta.lastError().text());
            return;
        }
        else
            consulta.exec("commit");
        if(!consulta.exec("insert into deposito values('"+cuentas_cobro.tabla2->item(i,3)->text()+"',to_date('"+cuentas_cobro.tabla2->item(i,0)->text()+"','dd-mm-yyyy'),'"+banco+"','"+cuentas_cobro.tabla2->item(i,4)->text()+"','"+compania+"','36','"+usuario+"','s','"+pago+"','"+prog_academico+"')"))
        {
            QMessageBox::critical(0,"Error Deposito",consulta.lastError().text());
            return;
        }
        else
            consulta.exec("commit");


        suma+=cuentas_cobro.tabla2->item(i,4)->text().toDouble();
    }

    if(lista.size()<=1)
    {
        consulta.exec("select saldo from cuentas_por_cobrar where cliente='"+cuentas_cobro.rif->text()+"' and id_fact='"+lista.at(0)->text()+"'");
        while(consulta.next())
        {
            saldo=consulta.value(0).toDouble();
        }
        if(suma==saldo)
        {
            consulta.exec("delete cuentas_por_cobrar where cliente='"+cuentas_cobro.rif->text()+"' and id_fact='"+lista.at(0)->text()+"'");
            consulta.exec("commit");
        }
        else
        {
            if(!consulta.exec("update cuentas_por_cobrar set saldo ='"+tr("%1").arg(saldo-suma)+"',ultimo_pago=to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'), ultimo_monto='"+tr("%1").arg(suma)+"', ultimo_deposito='"+cuentas_cobro.tabla2->item(cuentas_cobro.tabla2->rowCount()-1,3)->text()+"' where cliente='"+cuentas_cobro.rif->text()+"' and id_fact='"+lista.at(0)->text()+"'"))
            {
                QMessageBox::critical(0,"Error Actualizar Cuenta por Cobrar",consulta.lastError().text());
                return;
            }
            else
                consulta.exec("commit");
        }
    }
    else
    {
        for(i=0;i<lista.size();i++)
        {
            consulta.exec("delete cuentas_por_cobrar where cliente='"+cuentas_cobro.rif->text()+"' and id_fact='"+lista.at(i)->text()+"'");
            consulta.exec("commit");
        }
    }
    buscarCuenta();
}

/**
 *
 */

QStringList procesos_caja::listaBancos()
{
    QStringList bancos;//revisar la lista de items y buscar el nombre del banco que aparezca
    QSqlQuery consulta("select nombre from bancos");
    while(consulta.next())
    {
        bancos.append(consulta.value(0).toString());
    }
    return bancos;
}


/**
 *
 */

QList<QList<QString> > procesos_caja::orderItems()
{
    QList<QList<QString> > orderList;

    for (int row = 0; row < factura.f_tabla->rowCount(); ++row)
    {
        QList<QString> item;
        item.append(factura.f_tabla->item(row, 0)->text());
        item.append(factura.f_tabla->item(row, 1)->text());
        item.append(factura.f_tabla->item(row, 2)->text());
        item.append(factura.f_tabla->item(row, 3)->text());
        item.append(factura.f_tabla->item(row, 4)->text());
        item.append(factura.f_tabla->item(row, 5)->text());
        orderList.append(item);
    }
    return orderList;
}


/**
 *
 */

QList<QList<QString> > procesos_caja::pagoItems()
{
    QList<QList<QString> > pagoList;

    for (int row = 0; row < factura.f_tabla0->rowCount(); ++row)
    {
        QList<QString> item;
        item.append(factura.f_tabla0->item(row, 0)->text());
        item.append(factura.f_tabla0->item(row, 1)->text());
        item.append(factura.f_tabla0->item(row, 2)->text());
        item.append(factura.f_tabla0->item(row, 3)->text());
        item.append(factura.f_tabla0->item(row, 4)->text());
        pagoList.append(item);
    }
    return pagoList;
}


/**
 *
 */

QList<QList<QString> > procesos_caja::depositoItems()
{
    QList<QList<QString> > orderList;
    int row;
    for(row=0;row<reg_deposito.r_tabla->rowCount();++row)
    {
        QList<QString> item;
        item.append(reg_deposito.r_tabla->item(row, 0)->text());
        item.append(reg_deposito.r_tabla->item(row, 1)->text());
        item.append(reg_deposito.r_tabla->item(row, 2)->text());
        item.append(reg_deposito.r_tabla->item(row, 3)->text());
        item.append(reg_deposito.r_tabla->item(row, 4)->text());
        orderList.append(item);
    }
    return orderList;
}


/**
 *
 */

QList<QList<QString> > procesos_caja::facturaItems()
{
    QList<QList<QString> > orderList;
    int row;

    for(row=0;row<reg_factura.r_tabla->rowCount();++row)
    {
        QList<QString> item;
        item.append(reg_factura.r_tabla->item(row, 0)->text());
        item.append(reg_factura.r_tabla->item(row, 1)->text());
        item.append(reg_factura.r_tabla->item(row, 2)->text());
        item.append(reg_factura.r_tabla->item(row, 3)->text());
        item.append(reg_factura.r_tabla->item(row, 4)->text());
        orderList.append(item);
    }
    return orderList;
}


/**
 *
 */

QList<QList<QString> > procesos_caja::facturaConceptoItems()
{
    QList<QList<QString> > orderList;
    QString top,bottom,id_factura,programa,fecha;
    QSqlQuery consulta;

    top = reg_factura.r_top->text();
    bottom = reg_factura.r_bottom->text();

    consulta.exec("select id_fact,to_char(fecha_emi,'dd-mm-yyyy'),programa from factura where status='V' and fecha_emi between '"+top+"' and '"+bottom+"'");
    while(consulta.next())
    {
        id_factura = consulta.value(0).toString();
        fecha = consulta.value(1).toString();
        programa = consulta.value(2).toString();

        QSqlQuery consulta2("select descripcion,cantidad,p_unidad from detalle_factura where id_fact='"+id_factura+"' and programa='"+programa+"'");
        while(consulta2.next())
        {
            QList<QString> item;
            item.append(id_factura);
            item.append(fecha);
            item.append(consulta2.value(1).toString());
            item.append(consulta2.value(2).toString());
            item.append(consulta2.value(0).toString());
            orderList.append(item);
        }
    }
    return orderList;
}


/**
 *
 */

void procesos_caja::facturaSelect(bool checked)
{
    if(checked)
    {
        reg_factura.r_year->setEnabled(false);
        reg_factura.r_top->setEnabled(false);
        reg_factura.r_bottom->setEnabled(false);
        reg_factura.r_empresa->setEnabled(false);
        reg_factura.r_rif->setEnabled(false);
        reg_factura.r_factura_edit->setEnabled(true);
    }
    else
    {
        reg_factura.r_year->setEnabled(true);
        reg_factura.r_empresa->setEnabled(true);
        reg_factura.r_factura_edit->setEnabled(false);
    }
}


/**
 *
 */

void procesos_caja::referenciaSelect(bool checked)
{
    if(checked)
    {
        reg_deposito.r_year->setEnabled(false);
        reg_deposito.r_top->setEnabled(false);
        reg_deposito.r_bottom->setEnabled(false);
        reg_deposito.r_referencia_edit->setEnabled(true);
    }
    else
    {
        reg_deposito.r_year->setEnabled(true);
        reg_deposito.r_referencia_edit->setEnabled(false);
    }
}


/**
 *
 */

void procesos_caja::filtrarFact()
{
    QString id_pago,id_banco;
    QTableWidgetItem *ni;
    int i,row;
    QString id_fact=reg_factura.r_factura_edit->text();
    QString programa,numero;

    reg_factura.r_factura_edit->clear();
    row = reg_factura.r_tabla->rowCount();

    QSqlQuery consulta,consulta2;

    consulta.exec("select id_fact,nombre_cliente,to_char(fecha_emi,'dd-mm-yyyy'),monto,programa,status from factura where id_fact='"+id_fact+"'");

    for(i=row-1;i>=0;i--)
        reg_factura.r_tabla->removeRow(i);

    while(consulta.next())
    {
        row = reg_factura.r_tabla->rowCount();
        reg_factura.r_tabla->insertRow(row);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_factura.r_tabla->setItem(row,0,ni);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        reg_factura.r_tabla->setItem(row,1,ni);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        reg_factura.r_tabla->setItem(row,2,ni);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_factura.r_tabla->setItem(row,3,ni);

        if(consulta.value(5).toString()=="A")
        {
            ni = new QTableWidgetItem(tr("Anulada"));
            reg_factura.r_tabla->setItem(row,4,ni);
        }
        else
        {
            ni = new QTableWidgetItem(tr(" "));
            reg_factura.r_tabla->setItem(row,4,ni);
        }
    }
    if(reg_factura.r_tabla->rowCount()==0)
        QMessageBox::information(0,"Aviso","No se encontraron registros");
    else
    {
        disconnect(container.botonImprimir,SIGNAL(clicked()),0,0);
        connect(container.botonImprimir,SIGNAL(clicked()),this,SLOT(cierreFacturas()));
        container.botonImprimir->setEnabled(true);
    }
}


/**
 *
 */

void procesos_caja::filtrarFecha()
{
    QString top,bottom,fecha1,fecha2,id_pago,banco,id_banco;
    QTableWidgetItem *ni;
    QSqlQuery consulta,consulta2;
    int i,row;

    row = reg_factura.r_tabla->rowCount();
    for(i=row-1;i>=0;i--)
        reg_factura.r_tabla->removeRow(i);

    top = reg_factura.r_top->text();
    bottom = reg_factura.r_bottom->text();

    consulta.exec("select id_fact,nombre_cliente,to_char(fecha_emi,'dd-mm-yyyy'),monto,programa,status from factura where fecha_emi between to_date('"+top+"','dd-mm-yyyy') and to_date('"+bottom+"','dd-mm-yyyy') order by id_fact");
    while(consulta.next())
    {
        row = reg_factura.r_tabla->rowCount();
        reg_factura.r_tabla->insertRow(row);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_factura.r_tabla->setItem(row,0,ni);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        reg_factura.r_tabla->setItem(row,1,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        reg_factura.r_tabla->setItem(row,2,ni);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_factura.r_tabla->setItem(row,3,ni);

        if(consulta.value(5).toString()=="A")
        {
            ni = new QTableWidgetItem(tr("Anulada"));
            reg_factura.r_tabla->setItem(row,4,ni);
        }
        else
        {
            ni = new QTableWidgetItem(tr(" "));
            reg_factura.r_tabla->setItem(row,4,ni);
        }
    }

    if(reg_factura.r_tabla->rowCount()==0)
        QMessageBox::information(0,"Aviso","No se encontraron registros");
    else
    {
        disconnect(container.botonImprimir,SIGNAL(clicked()),0,0);
        connect(container.botonImprimir,SIGNAL(clicked()),this,SLOT(cierreFacturas()));
        container.botonImprimir->setEnabled(true);
    }
}


void procesos_caja::filtrarEmpresa()
{
    QString id_pago,id_banco;
    QTableWidgetItem *ni;
    int i,row;
    QString rif=reg_factura.r_rif->text();

    reg_factura.r_rif->clear();
    row = reg_factura.r_tabla->rowCount();

    QSqlQuery consulta,consulta2;

    consulta.exec("select id_fact,nombre_cliente,to_char(fecha_emi,'dd-mm-yyyy'),monto,programa,status from factura where rif='"+rif+"' and cedula_est is null");

    for(i=row-1;i>=0;i--)
        reg_factura.r_tabla->removeRow(i);

    while(consulta.next())
    {
        row = reg_factura.r_tabla->rowCount();
        reg_factura.r_tabla->insertRow(row);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_factura.r_tabla->setItem(row,0,ni);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        reg_factura.r_tabla->setItem(row,1,ni);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        reg_factura.r_tabla->setItem(row,2,ni);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_factura.r_tabla->setItem(row,3,ni);

        if(consulta.value(5).toString()=="A")
        {
            ni = new QTableWidgetItem(tr("Anulada"));
            reg_factura.r_tabla->setItem(row,4,ni);
        }
        else
        {
            ni = new QTableWidgetItem(tr(" "));
            reg_factura.r_tabla->setItem(row,4,ni);
        }
    }
    if(reg_factura.r_tabla->rowCount()==0)
        QMessageBox::information(0,"Aviso","No se encontraron registros");
    /*else
    {
        disconnect(container.botonImprimir,SIGNAL(clicked()),0,0);
        connect(container.botonImprimir,SIGNAL(clicked()),this,SLOT(cierreFacturas()));
        container.botonImprimir->setEnabled(true);
    }*/
}


/**
 *
 */

void procesos_caja::filtrarFecha_Bancos()
{
    QString banco,anio,mes,top,bottom;
    QTableWidgetItem *ni;
    QSqlQuery consulta,consulta2;
    int i,row;

    row = reg_deposito.r_tabla->rowCount();
    for(i=row-1;i>=0;i--)
        reg_deposito.r_tabla->removeRow(i);

    top = reg_deposito.r_top->text();
    bottom = reg_deposito.r_bottom->text();

    consulta2.exec("select referencia,to_char(fecha_emi,'dd-mm-yyyy'),id_banco,monto,forma_pago from deposito where fecha_emi between to_date('"+top+"','dd-mm-yyyy') and to_date('"+bottom+"','dd-mm-yyyy') order by fecha_emi");
    while(consulta2.next())
    {
        row = reg_deposito.r_tabla->rowCount();
        reg_deposito.r_tabla->insertRow(row);

        ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
        reg_deposito.r_tabla->setItem(row,0,ni);

        consulta.exec("select nombre from bancos where id_banco='"+consulta2.value(2).toString()+"'");
        while(consulta.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
            reg_deposito.r_tabla->setItem(row,2,ni);
        }

        ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(1).toString()));
        reg_deposito.r_tabla->setItem(row,1,ni);

        ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(3).toString()));
        reg_deposito.r_tabla->setItem(row,3,ni);

        consulta.exec("select id_fact from factura_deposito where referencia='"+consulta2.value(0).toString()+"' and id_banco='"+consulta2.value(2).toString()+"' and forma_pago='"+consulta2.value(4).toString()+"'");
        while(consulta.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
            reg_deposito.r_tabla->setItem(row,4,ni);
        }
    }

    if(reg_deposito.r_tabla->rowCount()==0)
        QMessageBox::information(0,"Aviso","No se encontraron registros");
    else
    {
        disconnect(container.botonImprimir,SIGNAL(clicked()),0,0);
        connect(container.botonImprimir,SIGNAL(clicked()),this,SLOT(cierreDepositos()));
        container.botonImprimir->setEnabled(true);
    }
}


/**
 *
 */

void procesos_caja::filtrarRef()
{
    QString id_banco;
    QTableWidgetItem *ni;
    int i,row;
    QString referencia=reg_deposito.r_referencia_edit->text();
    reg_deposito.r_referencia_edit->clear();
    row = reg_deposito.r_tabla->rowCount();

    QSqlQuery consulta,consulta2;
    consulta.exec("select referencia,to_char(fecha_emi,'dd-mm-yyyy'),id_banco,monto from deposito where referencia='"+referencia+"'");

    for(i=row-1;i>=0;i--)
        reg_deposito.r_tabla->removeRow(i);

    while(consulta.next())
    {
        row = reg_deposito.r_tabla->rowCount();
        reg_deposito.r_tabla->insertRow(row);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_deposito.r_tabla->setItem(row,0,ni);

        id_banco=consulta.value(2).toString();
        consulta2.exec("select nombre from bancos where id_banco='"+id_banco+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_deposito.r_tabla->setItem(row,2,ni);
        }

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_deposito.r_tabla->setItem(row,1,ni);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        reg_deposito.r_tabla->setItem(row,3,ni);

        consulta2.exec("select id_fact from factura_deposito where referencia='"+consulta.value(0).toString()+"' and id_banco='"+id_banco+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_deposito.r_tabla->setItem(row,4,ni);
        }
    }

    if(reg_deposito.r_tabla->rowCount()==0)
        QMessageBox::information(0,"Aviso","No se encontraron registros");
    else
    {
        disconnect(container.botonImprimir,SIGNAL(clicked()),0,0);
        connect(container.botonImprimir,SIGNAL(clicked()),this,SLOT(cierreDepositos()));
        container.botonImprimir->setEnabled(true);
    }
}


/**
 *
 */

void procesos_caja::yearSelect(bool checked)
{
    if(checked)
    {
        reg_factura.r_factura->setEnabled(false);
        reg_factura.r_top->setEnabled(true);
        reg_factura.r_bottom->setEnabled(true);
        reg_factura.r_empresa->setEnabled(false);
    }
    else
    {
        reg_factura.r_factura->setEnabled(true);
        reg_factura.r_top->setEnabled(false);
        reg_factura.r_bottom->setEnabled(false);
        reg_factura.r_empresa->setEnabled(true);
    }
}


/**
 *
 */

void procesos_caja::rifSelect(bool checked)
{
    if(checked)
    {
        reg_factura.r_factura->setEnabled(false);
        reg_factura.r_top->setEnabled(false);
        reg_factura.r_bottom->setEnabled(false);
        reg_factura.r_year->setEnabled(false);
        reg_factura.r_rif->setEnabled(true);
    }
    else
    {
        reg_factura.r_factura->setEnabled(true);
        reg_factura.r_top->setEnabled(true);
        reg_factura.r_bottom->setEnabled(true);
        reg_factura.r_year->setEnabled(true);
        reg_factura.r_rif->setEnabled(false);
    }
}


/**
 *
 */

void procesos_caja::yearSelect2(bool checked)
{
    if(checked)
    {
        reg_deposito.r_referencia->setEnabled(false);
        reg_deposito.r_top->setEnabled(true);
        reg_deposito.r_bottom->setEnabled(true);
    }
    else
    {
        reg_deposito.r_referencia->setEnabled(true);
        reg_deposito.r_top->setEnabled(false);
        reg_deposito.r_bottom->setEnabled(false);
    }
}


/**
 *
 */

void procesos_caja::crearFactura(QList<QList<QString> > items,QList<QList<QString> > pago_items,int pagina, QString nombre, QString cedula, QString telefono, QString dir, QString subtotal, QString iva, QString total, QString fact, bool copia, QString cedula_est, QString nombre_est, QString condicion)
{
    QSqlQuery consulta,consulta2,consulta3;
    NCReportPrinterOutput *output;
    int i;
    report->reset();
    QStandardItemModel *model1 = new QStandardItemModel(0,5);
    QStandardItemModel *model2 = new QStandardItemModel(0,6);
    QStandardItem *item;
    QString mod,matricula,programa;

    consulta.exec("select matricula from estudiante where cedula_est='"+cedula_est+"'");
    while(consulta.next())
    {
        report->addParameter("matricula",consulta.value(0).toString());
        matricula=consulta.value(0).toString();
    }

    consulta.exec("select prog_academico,usuario from factura where id_fact='"+fact+"'");
    while(consulta.next())
    {
        programa=consulta.value(0).toString();
        consulta2.exec("select nombre from usuarios where nombre_usuario='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            report->addParameter("usuario",consulta2.value(0).toString());
        }
    }

    report->addParameter("nfactura",fact);
    report->addParameter("nombre",nombre);
    report->addParameter("cedula",cedula);
    report->addParameter("direccion",dir);
    report->addParameter("telf",telefono);
    report->addParameter("nombre2",nombre_est);
    report->addParameter("cedula1",cedula_est);
    report->addParameter("condicion",condicion);
    report->addParameter("subtotal",subtotal);
    report->addParameter("iva",iva);
    report->addParameter("total",total);

    for(i=0;i<items.count();i++)
    {
        model1->insertRow(i);
        QList<QString> row = items[i];
        item = new QStandardItem();
        item->setData(row[1],Qt::EditRole);
        model1->setItem(i,0,item);
        item = new QStandardItem();
        item->setData(row[2],Qt::EditRole);
        model1->setItem(i,1,item);
        item = new QStandardItem();
        item->setData(row[3],Qt::EditRole);
        model1->setItem(i,2,item);
        item = new QStandardItem();
        item->setData(row[4],Qt::EditRole);
        model1->setItem(i,3,item);
        item = new QStandardItem();
        item->setData(row[5],Qt::EditRole);
        model1->setItem(i,4,item);
    }

    for(i=0;i<pago_items.count();i++)
    {
        model2->insertRow(i);
        QList<QString> row = pago_items[i];
        item = new QStandardItem();
        item->setData(row[0],Qt::EditRole);
        model2->setItem(i,0,item);
        item = new QStandardItem();
        item->setData(row[1],Qt::EditRole);
        model2->setItem(i,1,item);
        item = new QStandardItem();
        item->setData(row[2],Qt::EditRole);
        model2->setItem(i,2,item);
        item = new QStandardItem();
        item->setData(row[3],Qt::EditRole);
        model2->setItem(i,3,item);
        item = new QStandardItem();
        item->setData(row[4],Qt::EditRole);
        model2->setItem(i,4,item);
    }

    report->addItemModel(model1,"model1");

    if(copia)
    {
        if(programa=="3")
            consulta.exec("select distinct(to_char(fecha,'dd-mm-yyyy')) from ficha_pago_cfp where id_fact='"+fact+"' and matricula='"+matricula+"'");
        else
            consulta.exec("select distinct(to_char(fecha,'dd-mm-yyyy')) from ficha_pago where id_fact='"+fact+"' and matricula='"+matricula+"'");
        while(consulta.next())
        {
            report->addParameter("fecemi",consulta.value(0).toString());
            consulta2.exec("select id_curso,id_seccion from ficha_academica where matricula='"+matricula+"' and fecha=(select max(fecha) from ficha_academica where matricula='"+matricula+"' and fecha <=to_date('"+consulta.value(0).toString()+"','dd-mm-yyyy'))");
            while(consulta2.next())
            {
                if(programa=="3")
                {
                    report->addParameter("curso",consulta2.value(0).toString());
                    mod=consulta2.value(1).toString();
                }
                else
                {
                    consulta3.exec("select modalidad,nivel from secciones where id_seccion='"+consulta2.value(1).toString()+"'");
                    while(consulta3.next())
                    {
                        mod=consulta3.value(0).toString();
                        report->addParameter("curso",consulta2.value(0).toString()+" "+consulta3.value(1).toString());
                    }
                }
                consulta3.exec("select descripcion from modalidades where id_modalidad='"+mod+"'");
                while(consulta3.next())
                {
                    report->addParameter("horario",consulta3.value(0).toString());
                }
            }
        }

        report->addItemModel(model2,"model2");
        report->setReportFile("reportes/factura_copia.xml");
        output = new NCReportPdfOutput();
        output->setFileName("test.pdf");
        report->setOutput( output );
        report->runReport();
        if(!report->hasError())
        {
            ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        }
        else
            QMessageBox::information(0,"Error",report->lastErrorMsg());
    }
    else
    {
        consulta.exec("select nombre from usuarios where nombre_usuario='"+usuario+"'");
        while(consulta.next())
        {
            report->addParameter("usuario",consulta.value(0).toString());
        }
        report->addParameter("fecemi",QDate::currentDate().toString("dd-MM-yyyy"));
        report->addParameter("curso",factura.f_curso_2->text()+" "+factura.f_nivel->text());
        report->addParameter("horario",factura.f_turno->text());

        if(proforma)
            report->setReportFile("reportes/factura_proforma.xml");
        else
        {
            report->addItemModel(model2,"model2");
            if(programa=="6")
                report->setReportFile("reportes/factura_otros.xml");
            else
                report->setReportFile("reportes/factura.xml");
        }

        output = new NCReportPrinterOutput();
        output->setShowPrintDialog(FALSE);
        report->setOutput( output );
        report->runReport();
        if (report->hasError())
        {
            QMessageBox::information(0,"Error",report->lastErrorMsg());
        }

        //
        /*
        output = new NCReportPdfOutput();
        output->setFileName("test.pdf");
        report->setOutput( output );
        report->runReport();
        if(!report->hasError())
        {
            ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        }
        else
            QMessageBox::information(0,"Error",report->lastErrorMsg());
        */
    }
}


void procesos_caja::crearCarnet()
{
    dialogo = new QWidget();
    carnet_dialog.setupUi(dialogo);
    connect(carnet_dialog.cedula,SIGNAL(returnPressed()),this,SLOT(cedulaChanged2()));
    connect(carnet_dialog.matricula,SIGNAL(returnPressed()),this,SLOT(matriculaChanged2()));
    connect(carnet_dialog.imprimir,SIGNAL(clicked()),this,SLOT(imprimirCarnet()));
    dialogo->show();
}


void procesos_caja::cedulaChanged2()
{
    bool found=false;
    QString matricula,curso;
    QSqlQuery consulta,consulta2;

    carnet_dialog.nombre->clear();
    carnet_dialog.matricula->clear();
    carnet_dialog.sede->clear();
    carnet_dialog.curso->clear();
    carnet_dialog.programa->clear();

    consulta.exec("select nombre,apellido,matricula,sede,telf_hab,zona from estudiante where cedula_est='"+carnet_dialog.cedula->text()+"'");
    while(consulta.next())
    {
        carnet_dialog.nombre->setText(consulta.value(0).toString()+" "+consulta.value(1).toString());
        carnet_dialog.matricula->setText(consulta.value(2).toString());
        carnet_dialog.sede->setText(consulta.value(3).toString());
        carnet_dialog.telefono->setText(consulta.value(4).toString());
        carnet_dialog.dir->setText(consulta.value(5).toString());
        carnet_dialog.imprimir->setEnabled(true);
        found=true;
    }
    if(!found)
    {
        carnet_dialog.nombre->setText("Estudiante no registrado");
    }
    else
    {
        consulta.exec("select id_curso from ficha_academica where matricula='"+matricula+"' and id_evento='2' and status='V'");
        while(consulta.next())
        {
            curso=consulta.value(0).toString();
        }
        consulta.exec("select descripcion,prog_academico from metodos where id_metodo='"+curso+"'");
        while(consulta.next())
        {
            carnet_dialog.curso->setText(consulta.value(0).toString());
            consulta2.exec("select descripcion from programa_academico where id='"+consulta.value(1).toString()+"'");
            while(consulta2.next())
            {
                carnet_dialog.programa->setText(consulta2.value(0).toString());
            }
        }
    }
}


void procesos_caja::matriculaChanged2()
{
    bool found=false;
    QString curso;
    QSqlQuery consulta,consulta2;

    carnet_dialog.nombre->clear();
    carnet_dialog.cedula->clear();
    carnet_dialog.sede->clear();
    carnet_dialog.curso->clear();
    carnet_dialog.programa->clear();

    consulta.exec("select nombre,apellido,cedula_est,sede,telf_hab,zona from estudiante where matricula='"+carnet_dialog.matricula->text()+"'");
    while(consulta.next())
    {
        carnet_dialog.nombre->setText(consulta.value(0).toString()+" "+consulta.value(1).toString());
        carnet_dialog.cedula->setText(consulta.value(2).toString());
        carnet_dialog.imprimir->setEnabled(true);
        carnet_dialog.sede->setText(consulta.value(3).toString());
        carnet_dialog.telefono->setText(consulta.value(4).toString());
        carnet_dialog.dir->setText(consulta.value(5).toString());
        found=true;
    }
    if(!found)
    {
        carnet_dialog.nombre->setText("ESTUDIANTE NO REGISTRADO");
    }
    else
    {
        consulta.exec("select id_curso from ficha_academica where matricula='"+carnet_dialog.matricula->text()+"' and (id_evento='2') and status='V'");
        while(consulta.next())
        {
            curso=consulta.value(0).toString();
        }
        consulta.exec("select descripcion,prog_academico from metodos where id_metodo='"+curso+"'");
        while(consulta.next())
        {
            carnet_dialog.curso->setText(consulta.value(0).toString());
            consulta2.exec("select descripcion from programa_academico where id='"+consulta.value(1).toString()+"'");
            while(consulta2.next())
            {
                carnet_dialog.programa->setText(consulta2.value(0).toString());
            }
        }
    }
}


void procesos_caja::imprimirCarnet()
{
    report->reset();
    QStandardItemModel *model=new QStandardItemModel(1,6);
    QStandardItem *item= new QStandardItem();

    report->addParameter("vence","01-01-2012");
    item->setData(carnet_dialog.programa->text(),Qt::EditRole);
    model->setItem(0,0,item);
    item= new QStandardItem();
    item->setData(carnet_dialog.curso->text(),Qt::EditRole);
    model->setItem(0,1,item);
    item= new QStandardItem();
    item->setData(carnet_dialog.nombre->text(),Qt::EditRole);
    model->setItem(0,2,item);
    item= new QStandardItem();
    item->setData("Idiomas Niños Mañongo",Qt::EditRole);
    model->setItem(0,3,item);
    item= new QStandardItem();
    item->setData("Prolongacion Av. Salvador Feo la Cruz",Qt::EditRole);
    model->setItem(0,4,item);
    item= new QStandardItem();
    item->setData("0241-8431185",Qt::EditRole);
    model->setItem(0,5,item);

    dialogo->close();

    report->addItemModel(model,"model");
    report->setReportFile("reportes/carnet.xml");
    report->runReportToPDF("test.pdf");
    if (!report->hasError())
    {
        ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
    }
    else
        QMessageBox::information(0,"Error",report->lastErrorMsg());
}

/**
 *
 */
void procesos_caja::cierreDepositos()
{
    QDialog *orden = new QDialog();
    QComboBox *tipos= new QComboBox();
    QComboBox *salida= new QComboBox();
    int i,j,x;
    tipos->addItem("POR FECHA");
    tipos->addItem("POR BANCO");

    salida->addItem("PANTALLA");
    salida->addItem("IMPRESORA");

    container.botonImprimir->setEnabled(false);
    QLabel *label= new QLabel("Ordenar Por:");

    QPushButton *ok= new QPushButton("Aceptar",this);
    connect(ok,SIGNAL(clicked()),orden,SLOT(accept()));

    QVBoxLayout *v = new QVBoxLayout();
    v->addWidget(label);
    v->addWidget(tipos);
    v->addWidget(salida);
    v->addWidget(ok);

    orden->setLayout(v);
    orden->setMinimumSize(200,100);
    orden->exec();
    if(orden->result()==1)
    {
        QList<QList<QString> > items = depositoItems();
        QString monto;
        if(tipos->currentIndex()==1)
        {
            QStandardItemModel *model = new QStandardItemModel(items.count(),6);
            QStandardItem *item;
            report->reset();
            report->addParameter("fecha",reg_deposito.r_bottom->text());
            report->addParameter("fecha_actual",QDate::currentDate().toString("dd-MM-yyyy"));

            QStringList bancos = listaBancos();//Solo los bancos que aparezcan
            x=0;
            for(j=0;j<bancos.count();j++)
            {
                for(i=0;i<items.count();i++)
                {
                    QList<QString> row = items[i];
                    if(row[2]==bancos.at(j))
                    {
                        item = new QStandardItem();
                        item->setData(x,Qt::EditRole);
                        model->setItem(x,0,item);
                        item = new QStandardItem();
                        item->setData(row[0],Qt::EditRole);
                        model->setItem(x,1,item);
                        item = new QStandardItem();
                        item->setData(row[1],Qt::EditRole);
                        model->setItem(x,2,item);
                        item = new QStandardItem();
                        item->setData(row[4],Qt::EditRole);
                        model->setItem(x,3,item);
                        item = new QStandardItem();
                        item->setData(row[3].toFloat(),Qt::EditRole);
                        model->setItem(x,4,item);
                        item = new QStandardItem();
                        item->setData(row[2],Qt::EditRole);
                        model->setItem(x,5,item);
                        x++;
                    }
                }
            }
            report->addItemModel(model,"model");
            report->setReportFile("reportes/depositos_by_banco.xml");
        }
        else
        {
            QStandardItemModel *model = new QStandardItemModel(items.count(),5);
            QStandardItem *item;
            report->reset();
            report->addParameter("fecha",reg_deposito.r_bottom->text());
            report->addParameter("fecha_actual",QDate::currentDate().toString("dd-MM-yyyy"));

            for(i=0;i<items.count();i++)
            {
                QList<QString> row = items[i];
                monto=row[3];
                if(!monto.contains(".",Qt::CaseInsensitive)&&!monto.contains(",",Qt::CaseInsensitive))
                    monto= monto+".00";

                item = new QStandardItem();
                item->setData(i,Qt::EditRole);
                model->setItem(i,0,item);
                item = new QStandardItem();
                item->setData(row[0],Qt::EditRole);
                model->setItem(i,1,item);
                item = new QStandardItem();
                item->setData(row[1],Qt::EditRole);
                model->setItem(i,2,item);
                item = new QStandardItem();
                item->setData(row[4],Qt::EditRole);
                model->setItem(i,3,item);
                item = new QStandardItem();
                item->setData(monto.toFloat(),Qt::EditRole);
                model->setItem(i,4,item);

            }
            report->addItemModel(model,"model");
            report->setReportFile("reportes/depositos_by_fecha.xml");
        }

        report->runReportToPDF("test.pdf");
        if (!report->hasError())
        {
            if(salida->currentIndex()==1)
                ShellExecuteA(NULL,"print",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
            else
                ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        }
        else
            QMessageBox::information(0,"Error",report->lastErrorMsg());
    }
}


/**
 *
 */

void procesos_caja::cierreFacturas()
{
    QSqlQuery consulta,consulta2,consulta3;

    if(reg_factura.r_factura->isChecked())
    {
        QList<QList<QString> > items;
        QList<QList<QString> > pago_items;
        QString aux,cliente,rif,dir,monto,iva,total,pago,ref,banco,cedula,nombre,condicion;
        QString factura = reg_factura.r_tabla->item(0,0)->text();

        consulta.exec("select item,descripcion,cantidad,p_unidad,subtotal from detalle_factura where id_fact='"+factura+"'");
        while(consulta.next())
        {
            QList<QString> fila;
            fila.append("");
            fila.append(consulta.value(0).toString());
            fila.append(consulta.value(1).toString());
            fila.append(consulta.value(2).toString());
            aux= consulta.value(3).toString();
            if(!aux.contains(".",Qt::CaseInsensitive)&&!aux.contains(",",Qt::CaseInsensitive))
                aux=aux+".00";
            fila.append(aux);

            aux= consulta.value(4).toString();
            if(!aux.contains(".",Qt::CaseInsensitive)&&!aux.contains(",",Qt::CaseInsensitive))
                aux=aux+".00";
            fila.append(aux);
            items.append(fila);
        }

        consulta.exec("select id_fact,nombre_cliente,rif,dir_fiscal,monto,p_iva,cedula_est,nombre_est from factura where id_fact='"+factura+"'");
        while(consulta.next())
        {
            cliente=consulta.value(1).toString();
            rif=consulta.value(2).toString();
            dir=consulta.value(3).toString();
            total=consulta.value(4).toString();
            iva=consulta.value(5).toString();
            cedula=consulta.value(6).toString();
            nombre=consulta.value(7).toString();
        }

        consulta.exec("select id_tipo_est from estudiante where cedula_est ='"+cedula+"'");
        while(consulta.next())
        {
            consulta2.exec("select descripcion from tipo_estudiante where id_tipo_est='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                condicion=consulta2.value(0).toString();
            }
        }

        if(!total.contains(".",Qt::CaseInsensitive)&&!total.contains(",",Qt::CaseInsensitive))
            total= total+".00";

        consulta.exec("select referencia,id_banco,forma_pago from factura_deposito where id_fact='"+factura+"'");
        while(consulta.next())
        {
            consulta2.exec("select to_char(fecha_emi,'dd-mm-yyyy'),monto from deposito where referencia='"+consulta.value(0).toString()+"' and id_banco='"+consulta.value(1).toString()+"' and forma_pago='"+consulta.value(2).toString()+"'");
            while(consulta2.next())
            {
                QList<QString> fila;
                consulta3.exec("select descripcion from forma_pago where id_pago='"+consulta.value(2).toString()+"'");
                while(consulta3.next())
                {
                    aux=consulta3.value(0).toString();
                }
                fila.append(aux);
                fila.append(consulta.value(0).toString());
                consulta3.exec("select nombre from bancos where id_banco='"+consulta.value(1).toString()+"'");
                while(consulta3.next())
                {
                    aux=consulta3.value(0).toString();
                }
                fila.append(aux);
                fila.append(consulta2.value(0).toString());

                aux= consulta2.value(1).toString();
                if(!aux.contains(".",Qt::CaseInsensitive)&&!aux.contains(",",Qt::CaseInsensitive))
                    aux=aux+".00";
                fila.append(aux);
                pago_items.append(fila);
            }
        }
        crearFactura(items,pago_items,0,cliente,rif,"",dir,total,iva,total,factura,true,cedula,nombre,condicion);
    }
    else
    {
        QDialog *orden = new QDialog();
        QComboBox *tipos= new QComboBox();
        QComboBox *salida= new QComboBox();
        QComboBox *prog= new QComboBox();
        QStandardItemModel *model=new QStandardItemModel(0,10);
        QStandardItem *item;

        QString ttotal,aux;
        int i,j;
        float total2,total3;
        int cant2,cant3;

        tipos->addItem("POR FECHA");
        tipos->addItem("POR CONCEPTO");
        salida->addItem("PANTALLA");
        salida->addItem("IMPRESORA");

        consulta.exec("select descripcion from programa_academico order by id");
        while(consulta.next())
        {
            prog->addItem(consulta.value(0).toString());
        }
        QPushButton *ok= new QPushButton("Aceptar",this);
        connect(ok,SIGNAL(clicked()),orden,SLOT(accept()));

        QVBoxLayout *v = new QVBoxLayout();
        v->addWidget(new QLabel("Ordenar Por:"));
        v->addWidget(tipos);
        v->addWidget(new QLabel("Programa Academico:"));
        v->addWidget(prog);
        v->addWidget(new QLabel("Salida:"));
        v->addWidget(salida);
        v->addWidget(ok);

        orden->setLayout(v);
        orden->setMinimumSize(200,100);
        orden->exec();

        if(orden->result()==1)
        {
            report->reset();
            report->addParameter("fecha_actual",QDate::currentDate().toString("dd-MM-yyyy"));
            report->addParameter("fecha",reg_factura.r_bottom->text());
            report->addParameter("prog",prog->currentText());

            if(tipos->currentIndex()==1)
            {
                QString cedula,fecha,status,nombre,concepto,programa;
                QStringList tipos,tipos2;
                QStringList linea,facturas_nivel;
                total3=cant3=0;
                int x=-1;

                if((prog->currentIndex()==0)||(prog->currentIndex()==1)||(prog->currentIndex()==3))
                {
                    //POR METODO
                    programa.setNum(prog->currentIndex()+1);
                    consulta.exec("select id_metodo,descripcion,niveles from metodos where prog_academico='"+programa+"'");
                    while(consulta.next())
                    {
                        total2=0;cant2=0;
                        for(i=0;i<consulta.value(2).toInt();i++)
                        {
                            //SECCIONES
                            consulta2.exec("select id_seccion from secciones where id_metodo='"+consulta.value(0).toString()+"' and nivel='"+tr("%1").arg(i+1)+"'");
                            while(consulta2.next())
                            {
                                consulta3.exec("select id_fact,cantidad,subtotal from detalle_factura where item ='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi between to_date('"+reg_factura.r_top->text()+"','dd-mm-yyyy') and to_date('"+reg_factura.r_bottom->text()+"','dd-mm-yyyy') and status='V' and prog_academico='"+programa+"')");
                                while(consulta3.next())
                                {
                                    x++;
                                    model->insertRow(x);
                                    item = new QStandardItem();
                                    item->setData(consulta3.value(0).toString(),Qt::EditRole);
                                    model->setItem(x,0,item);


                                    QSqlQuery query("select cedula_est,to_char(fecha_emi,'dd-mm-yyyy'),status,nombre_est from factura where id_fact='"+consulta3.value(0).toString()+"'");
                                    while(query.next())
                                    {
                                        item = new QStandardItem();
                                        item->setData(query.value(1).toString(),Qt::EditRole);
                                        model->setItem(x,1,item);
                                        item = new QStandardItem();
                                        item->setData(query.value(2).toString(),Qt::EditRole);
                                        model->setItem(x,2,item);
                                        item = new QStandardItem();
                                        item->setData(query.value(0).toString(),Qt::EditRole);
                                        model->setItem(x,3,item);
                                        item = new QStandardItem();
                                        item->setData(query.value(3).toString(),Qt::EditRole);
                                        model->setItem(x,4,item);
                                    }
                                    item = new QStandardItem();
                                    item->setData(consulta3.value(1).toString(),Qt::EditRole);
                                    model->setItem(x,5,item);
                                    item = new QStandardItem();
                                    item->setData(consulta3.value(2).toDouble(),Qt::EditRole);
                                    model->setItem(x,6,item);
                                    concepto=consulta.value(1).toString()+" NIVEL "+tr("%1").arg(i+1)+" - SECCION: "+consulta2.value(0).toString();
                                    item = new QStandardItem();
                                    item->setData(concepto,Qt::EditRole);
                                    model->setItem(x,7,item);
                                    item = new QStandardItem();
                                    item->setData("CURSOS",Qt::EditRole);
                                    model->setItem(x,8,item);
                                    facturas_nivel.append(consulta3.value(0).toString());
                                }
                            }

                            //CURSOS SIN LIBRO
                            for(j=0;j<facturas_nivel.count();j++)
                            {
                                consulta3.exec("select cantidad,subtotal from detalle_factura where id_fact='"+facturas_nivel.at(j)+"' and item='DL'");
                                while(consulta3.next())
                                {
                                    x++;
                                    model->insertRow(x);
                                    item = new QStandardItem();
                                    item->setData(facturas_nivel.at(j),Qt::EditRole);
                                    model->setItem(x,0,item);

                                    QSqlQuery query("select cedula_est,to_char(fecha_emi,'dd-mm-yyyy'),status,nombre_est from factura where id_fact='"+facturas_nivel.at(j)+"'");
                                    while(query.next())
                                    {
                                        item = new QStandardItem();
                                        item->setData(query.value(1).toString(),Qt::EditRole);
                                        model->setItem(x,1,item);
                                        item = new QStandardItem();
                                        item->setData(query.value(2).toString(),Qt::EditRole);
                                        model->setItem(x,2,item);
                                        item = new QStandardItem();
                                        item->setData(query.value(0).toString(),Qt::EditRole);
                                        model->setItem(x,3,item);
                                        item = new QStandardItem();
                                        item->setData(query.value(3).toString(),Qt::EditRole);
                                        model->setItem(x,4,item);
                                    }
                                    item = new QStandardItem();
                                    item->setData(consulta3.value(0).toString(),Qt::EditRole);
                                    model->setItem(x,5,item);
                                    item = new QStandardItem();
                                    item->setData(consulta3.value(1).toDouble(),Qt::EditRole);
                                    model->setItem(x,6,item);
                                    concepto=consulta.value(1).toString()+" NIVEL "+tr("%1").arg(i+1)+" - SIN LIBRO";
                                    item = new QStandardItem();
                                    item->setData(concepto,Qt::EditRole);
                                    model->setItem(x,7,item);
                                    item = new QStandardItem();
                                    item->setData("CURSOS",Qt::EditRole);
                                    model->setItem(x,8,item);
                                }
                            }

                            //CURSOS SIN CD
                            for(j=0;j<facturas_nivel.count();j++)
                            {
                                consulta3.exec("select cantidad,subtotal from detalle_factura where id_fact='"+facturas_nivel.at(j)+"' and item='DCD'");
                                while(consulta3.next())
                                {
                                    x++;
                                    model->insertRow(x);
                                    item = new QStandardItem();
                                    item->setData(facturas_nivel.at(j),Qt::EditRole);
                                    model->setItem(x,0,item);
                                    QSqlQuery query("select cedula_est,to_char(fecha_emi,'dd-mm-yyyy'),status,nombre_est from factura where id_fact='"+facturas_nivel.at(j)+"'");
                                    while(query.next())
                                    {
                                        item = new QStandardItem();
                                        item->setData(query.value(1).toString(),Qt::EditRole);
                                        model->setItem(x,1,item);
                                        item = new QStandardItem();
                                        item->setData(query.value(2).toString(),Qt::EditRole);
                                        model->setItem(x,2,item);
                                        item = new QStandardItem();
                                        item->setData(query.value(0).toString(),Qt::EditRole);
                                        model->setItem(x,3,item);
                                        item = new QStandardItem();
                                        item->setData(query.value(3).toString(),Qt::EditRole);
                                        model->setItem(x,4,item);
                                    }
                                    item = new QStandardItem();
                                    item->setData(consulta3.value(0).toString(),Qt::EditRole);
                                    model->setItem(x,5,item);
                                    item = new QStandardItem();
                                    item->setData(consulta3.value(1).toDouble(),Qt::EditRole);
                                    model->setItem(x,6,item);
                                    concepto=consulta.value(1).toString()+" NIVEL "+tr("%1").arg(i+1)+" - SIN CD";
                                    item = new QStandardItem();
                                    item->setData(concepto,Qt::EditRole);
                                    model->setItem(x,7,item);
                                    item = new QStandardItem();
                                    item->setData("CURSOS",Qt::EditRole);
                                    model->setItem(x,8,item);
                                }
                            }
                            facturas_nivel.clear();
                        }

                        //LIBROS
                        total2=0;cant2=0;
                        consulta2.exec("select id_mat from materiales where tipo='L' and id_curso='"+consulta.value(0).toString()+"'");
                        while(consulta2.next())
                        {
                            consulta3.exec("select id_fact,cantidad,subtotal from detalle_factura where item = '"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi between to_date('"+reg_factura.r_top->text()+"','dd-mm-yyyy') and to_date('"+reg_factura.r_bottom->text()+"','dd-mm-yyyy') and status='V' and prog_academico='"+programa+"')");
                            while(consulta3.next())
                            {
                                x++;
                                model->insertRow(x);
                                item = new QStandardItem();
                                item->setData(consulta3.value(0).toString(),Qt::EditRole);
                                model->setItem(x,0,item);

                                QSqlQuery query("select cedula_est,to_char(fecha_emi,'dd-mm-yyyy'),status,nombre_est from factura where id_fact='"+consulta3.value(0).toString()+"'");
                                while(query.next())
                                {
                                    item = new QStandardItem();
                                    item->setData(query.value(1).toString(),Qt::EditRole);
                                    model->setItem(x,1,item);
                                    item = new QStandardItem();
                                    item->setData(query.value(2).toString(),Qt::EditRole);
                                    model->setItem(x,2,item);
                                    item = new QStandardItem();
                                    item->setData(query.value(0).toString(),Qt::EditRole);
                                    model->setItem(x,3,item);
                                    item = new QStandardItem();
                                    item->setData(query.value(3).toString(),Qt::EditRole);
                                    model->setItem(x,4,item);
                                }

                                item = new QStandardItem();
                                item->setData(consulta3.value(1).toString(),Qt::EditRole);
                                model->setItem(x,5,item);
                                item = new QStandardItem();
                                item->setData(consulta3.value(2).toDouble(),Qt::EditRole);
                                model->setItem(x,6,item);
                                concepto=consulta.value(1).toString()+" - LIBRO "+consulta2.value(0).toString();
                                item = new QStandardItem();
                                item->setData(concepto,Qt::EditRole);
                                model->setItem(x,7,item);
                                item = new QStandardItem();
                                item->setData("LIBROS",Qt::EditRole);
                                model->setItem(x,8,item);
                            }
                        }

                        //GUIAS
                        total2=0;cant2=0;
                        consulta2.exec("select id_mat from materiales where tipo='G' and id_curso='"+consulta.value(0).toString()+"'");
                        while(consulta2.next())
                        {
                            consulta3.exec("select id_fact,cantidad,subtotal from detalle_factura where item = '"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi between to_date('"+reg_factura.r_top->text()+"','dd-mm-yyyy') and to_date('"+reg_factura.r_bottom->text()+"','dd-mm-yyyy') and status='V' and prog_academico='"+programa+"')");
                            while(consulta3.next())
                            {
                                x++;
                                model->insertRow(x);
                                item = new QStandardItem();
                                item->setData(consulta3.value(0).toString(),Qt::EditRole);
                                model->setItem(x,0,item);

                                QSqlQuery query("select cedula_est,to_char(fecha_emi,'dd-mm-yyyy'),status,nombre_est from factura where id_fact='"+consulta3.value(0).toString()+"'");
                                while(query.next())
                                {
                                    item = new QStandardItem();
                                    item->setData(query.value(1).toString(),Qt::EditRole);
                                    model->setItem(x,1,item);
                                    item = new QStandardItem();
                                    item->setData(query.value(2).toString(),Qt::EditRole);
                                    model->setItem(x,2,item);
                                    item = new QStandardItem();
                                    item->setData(query.value(0).toString(),Qt::EditRole);
                                    model->setItem(x,3,item);
                                    item = new QStandardItem();
                                    item->setData(query.value(3).toString(),Qt::EditRole);
                                    model->setItem(x,4,item);
                                }

                                item = new QStandardItem();
                                item->setData(consulta3.value(1).toString(),Qt::EditRole);
                                model->setItem(x,5,item);
                                item = new QStandardItem();
                                item->setData(consulta3.value(2).toDouble(),Qt::EditRole);
                                model->setItem(x,6,item);
                                concepto=consulta.value(1).toString()+" - GUIA "+consulta2.value(0).toString();
                                item = new QStandardItem();
                                item->setData(concepto,Qt::EditRole);
                                model->setItem(x,7,item);
                                item = new QStandardItem();
                                item->setData("GUIAS",Qt::EditRole);
                                model->setItem(x,8,item);
                            }
                        }

                        //CDS
                        total2=0;cant2=0;
                        consulta2.exec("select id_mat from materiales where tipo='CD' and id_curso='"+consulta.value(0).toString()+"'");
                        while(consulta2.next())
                        {
                            consulta3.exec("select id_fact,cantidad,subtotal from detalle_factura where item = '"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi between to_date('"+reg_factura.r_top->text()+"','dd-mm-yyyy') and to_date('"+reg_factura.r_bottom->text()+"','dd-mm-yyyy') and status='V' and prog_academico='"+programa+"')");
                            while(consulta3.next())
                            {
                                item = new QStandardItem();
                                item->setData(consulta.value(0).toString(),Qt::EditRole);
                                model->setItem(x,0,item);
                                QSqlQuery query("select cedula_est,to_char(fecha_emi,'dd-mm-yyyy'),status,nombre_est from factura where id_fact='"+consulta3.value(0).toString()+"'");
                                while(query.next())
                                {
                                    item = new QStandardItem();
                                    item->setData(query.value(1).toString(),Qt::EditRole);
                                    model->setItem(x,1,item);
                                    item = new QStandardItem();
                                    item->setData(query.value(2).toString(),Qt::EditRole);
                                    model->setItem(x,2,item);
                                    item = new QStandardItem();
                                    item->setData(query.value(0).toString(),Qt::EditRole);
                                    model->setItem(x,3,item);
                                    item = new QStandardItem();
                                    item->setData(query.value(3).toString(),Qt::EditRole);
                                    model->setItem(x,4,item);
                                }

                                item = new QStandardItem();
                                item->setData(consulta3.value(1).toString(),Qt::EditRole);
                                model->setItem(x,5,item);
                                item = new QStandardItem();
                                item->setData(consulta3.value(2).toDouble(),Qt::EditRole);
                                model->setItem(x,6,item);
                                concepto=consulta.value(1).toString()+" - CD MP3 "+consulta2.value(0).toString();
                                item = new QStandardItem();
                                item->setData(concepto,Qt::EditRole);
                                model->setItem(x,7,item);
                                item = new QStandardItem();
                                item->setData("CD MP3",Qt::EditRole);
                                model->setItem(x,8,item);
                                x++;
                                model->insertRow(x);
                            }
                        }
                    }
                    total3+=total2;
                    cant3+=cant2;
                    if((prog->currentIndex()==0)||(prog->currentIndex()==1))
                        consulta.exec("select abrev from tipo_material where idiomas='S'");
                    else if(prog->currentIndex()==2)
                        consulta.exec("select abrev from tipo_material where cfp='S'");
                    else if(prog->currentIndex()==3)
                        consulta.exec("select abrev from tipo_material where fvtc='S'");
                    while(consulta.next())
                    {
                        total2=0;cant2=0;
                        if(consulta.value(0).toString()=="D")
                            consulta2.exec("select id_mat,descripcion from materiales where tipo='"+consulta.value(0).toString()+"' and id_mat<>'DCD' and id_mat<>'DL'");
                        else
                            consulta2.exec("select id_mat,descripcion from materiales where tipo='"+consulta.value(0).toString()+"'");
                        while(consulta2.next())
                        {
                            consulta3.exec("select id_fact,cantidad,subtotal from detalle_factura where item = '"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi between to_date('"+reg_factura.r_top->text()+"','dd-mm-yyyy') and to_date('"+reg_factura.r_bottom->text()+"','dd-mm-yyyy') and status='V' and prog_academico='"+programa+"')");
                            while(consulta3.next())
                            {
                                item = new QStandardItem();
                                item->setData(consulta3.value(0).toString(),Qt::EditRole);
                                model->setItem(x,0,item);
                                QSqlQuery query("select cedula_est,to_char(fecha_emi,'dd-mm-yyyy'),status,nombre_est from factura where id_fact='"+consulta3.value(0).toString()+"'");
                                while(query.next())
                                {
                                    item = new QStandardItem();
                                    item->setData(query.value(1).toString(),Qt::EditRole);
                                    model->setItem(x,1,item);
                                    item = new QStandardItem();
                                    item->setData(query.value(2).toString(),Qt::EditRole);
                                    model->setItem(x,2,item);
                                    item = new QStandardItem();
                                    item->setData(query.value(0).toString(),Qt::EditRole);
                                    model->setItem(x,3,item);
                                    item = new QStandardItem();
                                    item->setData(query.value(3).toString(),Qt::EditRole);
                                    model->setItem(x,4,item);
                                }

                                item = new QStandardItem();
                                item->setData(consulta3.value(1).toString(),Qt::EditRole);
                                model->setItem(x,5,item);
                                item = new QStandardItem();
                                item->setData(consulta3.value(2).toDouble(),Qt::EditRole);
                                model->setItem(x,6,item);
                                concepto=consulta2.value(1).toString();
                                item = new QStandardItem();
                                item->setData(concepto,Qt::EditRole);
                                model->setItem(x,7,item);
                                item = new QStandardItem();
                                item->setData(consulta2.value(1).toString(),Qt::EditRole);// COLOCAR LA DESCRIPCION DEL MATERIAL
                                model->setItem(x,8,item);
                                x++;
                                model->insertRow(x);
                            }
                        }
                    }
                    /*for(i=0;i<tipos2.size();i++)
                    {
                        detalles = new QList<QStringList>();
                        consulta3.exec("select id_fact,cantidad,subtotal from detalle_factura where tipo_item = '"+tipos2.at(i)+"' and id_fact in (select id_fact from factura where fecha_emi between to_date('"+reg_factura.r_top->text()+"','dd-mm-yyyy') and to_date('"+reg_factura.r_bottom->text()+"','dd-mm-yyyy') and status='V' and prog_academico='"+programa+"')");
                        while(consulta3.next())
                        {
                            item = new QStandardItem();
                            item->setData(consulta3.value(0).toString(),Qt::EditRole);
                            model->setItem(x,0,item);
                            QSqlQuery query("select cedula_est,to_char(fecha_emi,'dd-mm-yyyy'),status,nombre_est from factura where id_fact='"+consulta3.value(0).toString()+"'");
                            while(query.next())
                            {
                                item = new QStandardItem();
                                item->setData(query.value(1).toString(),Qt::EditRole);
                                model->setItem(x,1,item);
                                item = new QStandardItem();
                                item->setData(query.value(2).toString(),Qt::EditRole);
                                model->setItem(x,2,item);
                                item = new QStandardItem();
                                item->setData(query.value(0).toString(),Qt::EditRole);
                                model->setItem(x,3,item);
                                item = new QStandardItem();
                                item->setData(query.value(3).toString(),Qt::EditRole);
                                model->setItem(x,4,item);
                            }

                            item = new QStandardItem();
                            item->setData(consulta3.value(1).toString(),Qt::EditRole);
                            model->setItem(x,5,item);
                            item = new QStandardItem();
                            item->setData(consulta3.value(2).toDouble(),Qt::EditRole);
                            model->setItem(x,6,item);
                            consulta2.exec("select concepto from codigo_concepto where tipo='"+tipos2.at(i)+"'");
                            while(consulta2.next())
                            {
                                concepto=consulta2.value(0).toString();
                            }
                            item = new QStandardItem();
                            item->setData(concepto,Qt::EditRole);
                            model->setItem(x,7,item);
                            consulta2.exec("select descripcion from materiales where tipo='"+tipos2.at(i)+"'");
                            while(consulta2.next())
                            {
                                item = new QStandardItem();
                                item->setData(tipos2[i],Qt::EditRole);
                                model->setItem(x,8,item);
                            }
                            x++;
                            model->insertRow(x);
                        }
                    }*/
                }
                report->addItemModel(model,"model");
                report->setReportFile("reportes/facturas_by_concepto.xml");
            }
            else
            {
                i=-1;
                consulta.exec("select id_fact,nombre_cliente,to_char(fecha_emi,'dd-mm-yyyy'),monto,status from factura a where fecha_emi between to_date('"+reg_factura.r_top->text()+"','dd-mm-yyyy') and to_date('"+reg_factura.r_bottom->text()+"','dd-mm-yyyy') and prog_academico='"+tr("%1").arg(prog->currentIndex()+1)+"'  and not exists (select b.id_fact from cuentas_por_cobrar b where a.id_fact=b.id_fact) order by id_fact");
                while(consulta.next())
                {
                    i++;
                    model->insertRow(i);
                    item = new QStandardItem();
                    item->setData(consulta.value(0).toString(), Qt::EditRole );
                    model->setItem(i,0,item);
                    item = new QStandardItem();
                    item->setData(consulta.value(2).toString(), Qt::EditRole );
                    model->setItem(i,1,item);
                    item = new QStandardItem();
                    item->setData(consulta.value(4).toString(), Qt::EditRole );
                    model->setItem(i,2,item);
                    item = new QStandardItem();
                    item->setData(consulta.value(1).toString(), Qt::EditRole );
                    model->setItem(i,3,item);
                    item = new QStandardItem();
                    if(consulta.value(4).toString()=="A")
                        item->setData("0", Qt::EditRole );
                    else
                        item->setData(consulta.value(3).toString(), Qt::EditRole );
                    model->setItem(i,4,item);
                    item = new QStandardItem();
                    item->setData(tr("%1").arg(i), Qt::EditRole );
                    model->setItem(i,5,item);
                }

                report->addItemModel(model,"model");
                QStandardItemModel *model2=new QStandardItemModel(0,5);
                i=-1;
                consulta.exec("select id_fact,nombre_cliente,to_char(fecha_emi,'dd-mm-yyyy'),monto,status from factura where fecha_emi between to_date('"+reg_factura.r_top->text()+"','dd-mm-yyyy') and to_date('"+reg_factura.r_bottom->text()+"','dd-mm-yyyy') and prog_academico='"+tr("%1").arg(prog->currentIndex()+1)+"' and id_fact in (select id_fact from cuentas_por_cobrar where prog_academico='"+tr("%1").arg(prog->currentIndex()+1)+"' and fecha_emi between to_date('"+reg_factura.r_top->text()+"','dd-mm-yyyy') and to_date('"+reg_factura.r_bottom->text()+"','dd-mm-yyyy')) order by id_fact");
                while(consulta.next())
                {
                    i++;
                    model2->insertRow(i);
                    item = new QStandardItem();
                    item->setData(consulta.value(0).toString(), Qt::EditRole );
                    model2->setItem(i,0,item);
                    item = new QStandardItem();
                    item->setData(consulta.value(2).toString(), Qt::EditRole );
                    model2->setItem(i,1,item);
                    item = new QStandardItem();
                    item->setData(consulta.value(4).toString(), Qt::EditRole );
                    model2->setItem(i,2,item);
                    item = new QStandardItem();
                    item->setData(consulta.value(1).toString(), Qt::EditRole );
                    model2->setItem(i,3,item);
                    item = new QStandardItem();
                    if(consulta.value(4).toString()=="A")
                        item->setData("0", Qt::EditRole );
                    else
                        item->setData(consulta.value(3).toString(), Qt::EditRole );
                    model2->setItem(i,4,item);
                    item = new QStandardItem();
                    item->setData(tr("%1").arg(i), Qt::EditRole );
                    model2->setItem(i,5,item);
                }
                report->addItemModel(model2,"model2");
                report->setReportFile("reportes/facturas_by_fecha.xml");
            }

            report->runReportToPDF("test.pdf");
            if (!report->hasError())
            {
                if(salida->currentIndex()==1)
                    ShellExecuteA(NULL,"print",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
                else
                    ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
            }
            else
                QMessageBox::information(0,"Error",report->lastErrorMsg());
        }
    }
}


void procesos_caja::cierreMensual()
{
    QSqlQuery consulta;

    consulta.exec("update saldo_acum_bancos set saldo=0");
    consulta.exec("commit");

    if(!consulta.exec("update saldo_acum_conceptos set dia_1=0,dia_2=0,dia_3=0,dia_4=0,dia_5=0,dia_6=0,dia_7=0,dia_8=0,dia_9=0,dia_10=0,dia_11=0,dia_12=0,dia_13=0,dia_14=0,dia_15=0,dia_16=0,dia_17=0,dia_18=0,dia_19=0,dia_20=0,dia_21=0,dia_22=0,dia_23=0,dia_24=0,dia_25=0,dia_26=0,dia_27=0,dia_28=0,dia_29=0,dia_30=0,dia_31=0"))
        QMessageBox::critical(0,"Error",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        if(!consulta.exec("update saldo_acum_bancos set dia_1=0,dia_2=0,dia_3=0,dia_4=0,dia_5=0,dia_6=0,dia_7=0,dia_8=0,dia_9=0,dia_10=0,dia_11=0,dia_12=0,dia_13=0,dia_14=0,dia_15=0,dia_16=0,dia_17=0,dia_18=0,dia_19=0,dia_20=0,dia_21=0,dia_22=0,dia_23=0,dia_24=0,dia_25=0,dia_26=0,dia_27=0,dia_28=0,dia_29=0,dia_30=0,dia_31=0"))
            QMessageBox::critical(0,"Error",consulta.lastError().text());
        else
        {
            consulta.exec("commit");
            QMessageBox::information(0,"Cierre Mensual","Se ha actualizado la informacion exitosamente");
        }
    }
}


void procesos_caja::setupCierre()
{
    dialogo = new QWidget();
    cont_dialog.setupUi(dialogo);
    QSqlQuery consulta("select descripcion from programa_academico order by id");
    while(consulta.next())
    {
        cont_dialog.programa->addItem(consulta.value(0).toString());
    }

    cont_dialog.user->addItem("ACTUAL");
    cont_dialog.user->addItem("TODOS");
    cont_dialog.salida->addItem("PANTALLA");
    cont_dialog.salida->addItem("IMPRESORA");

    cont_dialog.fecha->setDate(QDate::currentDate());
    connect(cont_dialog.aceptar,SIGNAL(clicked()),this,SLOT(cuadreCaja()));
    dialogo->show();
}


void procesos_caja::cuadreCaja()
{
    QSqlQuery consulta,consulta2,consulta3,consulta4,consulta5,consulta6;
    QList<QString> *id_fact;
    QString prog,concepto,academico,rango,observacion,anuladas,desde,hasta,fecha,curso;
    int i,j,cant,sin_libro,sin_cd,x;
    float saldo_total2,saldo,total,total2,total3,total4,total5,total_cursos,total_libros,total_guias,total_cds,total_otros,precio_guia,precio_cd,precio_libro;
    bool in=false;

    total_cursos=total_libros=total_guias=total_cds=total_otros=0;

    consulta.exec("select descripcion from companias where id='"+compania+"'");
    while(consulta.next())
    {
        prog=consulta.value(0).toString();
    }

    QStandardItemModel *model = new QStandardItemModel(0,5);
    QStandardItemModel *model2 = new QStandardItemModel(0,4);
    QStandardItemModel *model3 = new QStandardItemModel(0,4);
    QStandardItemModel *model4 = new QStandardItemModel(0,4);
    QStandardItem *item;

    x=-1;
    report->reset();
    fecha=cont_dialog.fecha->date().toString("dd-MM-yyyy");
    report->addParameter("date",fecha);
    report->addParameter("programa",prog);

    consulta.exec("select id from programa_academico where descripcion='"+cont_dialog.programa->currentText()+"'");
    while(consulta.next())
    {
        academico=consulta.value(0).toString();
    }

    /*if(academico=="6")//DIRECCION CENTRAL
    {
        report->addParameter("programa","DIRECCION CENTRAL");
        total=0;
        if(cont_dialog.user->currentText()=="ACTUAL")
            consulta3.exec("select cantidad,subtotal from detalle_factura where tipo_item='O' and id_fact in (select id_fact from factura where fecha_emi =to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
        else
            consulta3.exec("select cantidad,subtotal from detalle_factura where tipo_item='O' and id_fact in (select id_fact from factura where fecha_emi =to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");

        while(consulta3.next())
        {
            total+=consulta3.value(1).toDouble();
        }

        //Codigo contable de los alquileres
        consulta2.exec("select cod_contable,concepto from codigo_concepto where tipo='O'");
        while(consulta2.next())
        {
            saldo=0;
            consulta3.exec("select * from saldo_acum_conceptos where cod_contable='"+consulta2.value(0).toString()+"' and prog_academico='"+academico+"'");
            while(consulta3.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta3.value(i).toDouble();
            }
            x++;
            model->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta2.value(0).toString(),Qt::EditRole);
            model->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(consulta2.value(1).toString(), Qt::EditRole);
            model->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);
            model->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total, Qt::EditRole);
            model->setItem(x,3,item);
            item = new QStandardItem();
            item->setData(total+saldo,Qt::EditRole);
            model->setItem(x,4,item);

            consulta3.exec("update saldo_acum_conceptos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total)+"' where cod_contable='"+consulta2.value(0).toString()+"' and prog_academico='"+academico+"'");
            consulta3.exec("commit");
        }
        report->addItemModel(model,"model");
    }

    else*/
    if((academico=="1")||(academico=="2")) //IDIOMAS
    {
        report->addParameter("programa","IDIOMAS MODERNOS");
        consulta.exec("select id_metodo,descripcion,niveles from metodos where prog_academico='"+academico+"'");
        while(consulta.next())
        {
            total2=0;
            if((consulta.value(0).toString()=="AEC")||(consulta.value(0).toString()=="AEC-J"))
                curso="AEC";
            else
                curso=consulta.value(0).toString();

            //CUOTAS DE ENGLISH ADVENTURE Y SCOTT FORESMAN
            if(cont_dialog.user->currentText()=="ACTUAL")
                consulta3.exec("select cantidad,subtotal from detalle_factura where item='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi =to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
            else
                consulta3.exec("select cantidad,subtotal from detalle_factura where item='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi =to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
            while(consulta3.next())
            {
                total2+=consulta3.value(1).toDouble();
            }

            //INGRESO POR INSCRIPCION EN SECCIONES
            for(i=0;i<consulta.value(2).toInt();i++)//Iteracion por niveles
            {
                id_fact=new QList<QString>();
                precio_guia=precio_libro=precio_cd=0;
                total3=total4=total5=0;
                sin_cd=sin_libro=0;

                //Establezco el precio de guia, libro y cd para este metodo en este nivel
                consulta2.exec("select id_mat from materiales where tipo='G' and id_curso='"+curso+"' and nivel='"+tr("%1").arg(i+1)+"'");
                while(consulta2.next())
                {
                    consulta6.exec("select precio1 from precios where item='"+consulta2.value(0).toString()+"'");
                    while(consulta6.next())
                    {
                        precio_guia=consulta6.value(0).toDouble();
                    }
                }

                consulta2.exec("select id_mat from materiales where tipo='L' and id_curso='"+curso+"' and nivel='"+tr("%1").arg(i+1)+"'");
                while(consulta2.next())
                {
                    consulta6.exec("select precio1 from precios where item='"+consulta2.value(0).toString()+"'");
                    while(consulta6.next())
                    {
                        precio_libro=consulta6.value(0).toDouble();
                    }
                }

                consulta2.exec("select id_mat from materiales where tipo='CD' and id_curso='"+curso+"' and nivel='"+tr("%1").arg(i+1)+"'");
                while(consulta2.next())
                {
                    consulta6.exec("select precio1 from precios where item='"+consulta2.value(0).toString()+"'");
                    while(consulta6.next())
                    {
                        precio_cd=consulta6.value(0).toDouble();
                    }
                }

                //Si existe factura de una seccion de ese nivel y metodo se suman individualmente los 3 items (libro, guia, cd) y el costo por concepto de curso (curso=subtotal-libro-guia-cd)
                consulta2.exec("select id_seccion,modalidad from secciones where id_metodo='"+consulta.value(0).toString()+"' and nivel='"+tr("%1").arg(i+1)+"'");
                while(consulta2.next())
                {
                    cant=0;
                    if(cont_dialog.user->currentText()=="ACTUAL")
                        consulta3.exec("select cantidad,subtotal,id_fact from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi =to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
                    else
                        consulta3.exec("select cantidad,subtotal,id_fact from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi =to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
                    while(consulta3.next())
                    {
                        total4+=precio_guia;
                        total5+=precio_cd;
                        /*if(curso=="AEC")//NO SE SUMA LIBRO AUTOMATICAMENTE POR VENTA DE SECCION. PROBAR
                            total2+=consulta3.value(1).toDouble()-precio_guia-precio_cd; //Ingreso por curso
                        else
                        {*/
                        total3+=precio_libro;
                        total2+=consulta3.value(1).toDouble()-precio_libro-precio_guia-precio_cd; //Ingreso por curso


                        if(i==9)
                            QMessageBox::information(0,curso,tr("%1 - %2").arg(consulta3.value(2).toString()).arg(total2));
                        id_fact->append(consulta3.value(2).toString());
                    }
                }

                //CANTIDAD DE SIN LIBRO Y SIN CD DE ESE NIVEL
                for(j=0;j<id_fact->size();j++)
                {
                    consulta2.exec("select cantidad from detalle_factura where item='DL' and id_fact = '"+id_fact->at(j)+"'");
                    while(consulta2.next())
                    {
                        sin_libro+=consulta2.value(0).toInt();

                    }
                    consulta2.exec("select cantidad from detalle_factura where item='DCD' and id_fact = '"+id_fact->at(j)+"'");
                    while(consulta2.next())
                    {
                        sin_cd+=consulta2.value(0).toInt();
                    }
                }

                //LIBROS SUELTOS EN BS DE ESE NIVEL
                consulta2.exec("select id_mat from materiales where tipo='L' and id_curso='"+curso+"' and nivel='"+tr("%1").arg(i+1)+"'");
                while(consulta2.next())
                {
                    if(cont_dialog.user->currentText()=="ACTUAL")
                        consulta3.exec("select subtotal from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
                    else
                        consulta3.exec("select subtotal from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
                    while(consulta3.next())
                    {
                        total3+=consulta3.value(0).toDouble();
                    }
                }
                //GUIAS SUELTAS EN BS DE ESE NIVEL
                consulta2.exec("select id_mat from materiales where tipo='G' and id_curso='"+curso+"' and nivel='"+tr("%1").arg(i+1)+"'");
                while(consulta2.next())
                {
                    if(cont_dialog.user->currentText()=="ACTUAL")
                        consulta3.exec("select subtotal from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
                    else
                        consulta3.exec("select subtotal from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
                    while(consulta3.next())
                    {
                        total4+=consulta3.value(0).toDouble();
                    }
                }
                //CDS SUELTOS EN BS DE ESE NIVEL
                consulta2.exec("select id_mat from materiales where tipo='CD' and id_curso='"+curso+"' and nivel='"+tr("%1").arg(i+1)+"'");
                while(consulta2.next())
                {
                    if(cont_dialog.user->currentText()=="ACTUAL")
                        consulta3.exec("select subtotal from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
                    else
                        consulta3.exec("select subtotal from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
                    while(consulta3.next())
                    {
                        total5+=consulta3.value(0).toDouble();
                    }
                }

                total_libros+=total3-(sin_libro*precio_libro);
                total_cds+=total5-(sin_cd*precio_cd);
                total_guias+=total4;
            }

            total_cursos+=total2;
        }

        //Actualizo y presento el saldo acumulado, total del día y nuevo acumulado de ingresos por concepto contable
        //POR CURSO
        consulta.exec("select cod_contable,concepto from codigo_concepto where tipo='CI'");
        while(consulta.next())
        {
            saldo=0;
            consulta2.exec("select * from saldo_acum_conceptos where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta2.value(i).toDouble();
            }
            x++;
            model->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta.value(0).toString(),Qt::EditRole); //Codigo contable
            model->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString(), Qt::EditRole);//Descripcion
            model->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);//Acumulado
            model->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total_cursos, Qt::EditRole);//Total del día
            model->setItem(x,3,item);
            item = new QStandardItem();
            item->setData(total_cursos+saldo,Qt::EditRole);//Nuevo acumulado
            model->setItem(x,4,item);

            consulta2.exec("update saldo_acum_conceptos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total_cursos)+"' where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
            consulta2.exec("commit");
        }

        //POR LIBROS
        consulta.exec("select cod_contable,concepto from codigo_concepto where tipo='L'");
        while(consulta.next())
        {
            saldo=0;
            consulta2.exec("select * from saldo_acum_conceptos where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta2.value(i).toDouble();
            }
            x++;
            model->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta.value(0).toString(),Qt::EditRole);
            model->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString(), Qt::EditRole);
            model->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);
            model->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total_libros, Qt::EditRole);
            model->setItem(x,3,item);
            item = new QStandardItem();
            item->setData(total_libros+saldo,Qt::EditRole);
            model->setItem(x,4,item);

            consulta2.exec("update saldo_acum_conceptos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total_libros)+"' where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
            consulta2.exec("commit");
        }

        //POR GUIAS
        consulta.exec("select cod_contable,concepto from codigo_concepto where tipo='G'");
        while(consulta.next())
        {
            saldo=0;
            consulta2.exec("select * from saldo_acum_conceptos where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta2.value(i).toDouble();
            }
            x++;
            model->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta.value(0).toString(),Qt::EditRole);
            model->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString(), Qt::EditRole);
            model->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);
            model->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total_guias, Qt::EditRole);
            model->setItem(x,3,item);
            item = new QStandardItem();
            item->setData(saldo+total_guias,Qt::EditRole);
            model->setItem(x,4,item);

            consulta2.exec("update saldo_acum_conceptos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total_guias)+"' where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
            consulta2.exec("commit");
        }

        //POR CDS
        consulta.exec("select cod_contable,concepto from codigo_concepto where tipo='CD'");
        while(consulta.next())
        {
            saldo=0;
            consulta2.exec("select * from saldo_acum_conceptos where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta2.value(i).toDouble();
            }
            x++;
            model->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta.value(0).toString(),Qt::EditRole);
            model->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString(), Qt::EditRole);
            model->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);
            model->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total_cds, Qt::EditRole);
            model->setItem(x,3,item);
            item = new QStandardItem();
            item->setData(saldo+total_cds,Qt::EditRole);
            model->setItem(x,4,item);

            consulta2.exec("update saldo_acum_conceptos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total_cds)+"' where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
            consulta2.exec("commit");
        }

        //Calculo totales de los conceptos distintos a cursos/libros
        consulta.exec("select abrev from tipo_material where idiomas='S' and abrev <>'L' and abrev <>'G' and abrev <>'CD' and abrev <>'CI' and abrev <>'C'");
        while(consulta.next())
        {
            total=0;
            if(consulta.value(0).toString()=="D") //Descuentos
            {
                if(cont_dialog.user->currentText()=="ACTUAL")
                    consulta3.exec("select cantidad,subtotal from detalle_factura where tipo_item='"+consulta.value(0).toString()+"' and item<>'DCD' and item<>'DL' and id_fact in (select id_fact from factura where fecha_emi =to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
                else
                    consulta3.exec("select cantidad,subtotal from detalle_factura where tipo_item='"+consulta.value(0).toString()+"' and item<>'DCD' and item<>'DL' and id_fact in (select id_fact from factura where fecha_emi =to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
            }
            else
            {
                if(cont_dialog.user->currentText()=="ACTUAL")
                    consulta3.exec("select cantidad,subtotal from detalle_factura where tipo_item='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi =to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
                else
                    consulta3.exec("select cantidad,subtotal from detalle_factura where tipo_item='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi =to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
            }
            while(consulta3.next())
            {
                total+=consulta3.value(1).toDouble();
            }

            consulta2.exec("select cod_contable,concepto from codigo_concepto where tipo='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                saldo=0;
                consulta3.exec("select * from saldo_acum_conceptos where cod_contable='"+consulta2.value(0).toString()+"' and prog_academico='"+academico+"'");
                while(consulta3.next())
                {
                    for(i=1;i<32;i++)
                        saldo+=consulta3.value(i).toDouble();
                }
                x++;
                model->insertRow(x);
                item = new QStandardItem();
                item->setData(consulta2.value(0).toString(),Qt::EditRole);
                model->setItem(x,0,item);
                item = new QStandardItem();
                item->setData(consulta2.value(1).toString(), Qt::EditRole);
                model->setItem(x,1,item);
                item = new QStandardItem();
                item->setData(saldo, Qt::EditRole);
                model->setItem(x,2,item);
                item = new QStandardItem();
                item->setData(total, Qt::EditRole);
                model->setItem(x,3,item);
                item = new QStandardItem();
                item->setData(total+saldo,Qt::EditRole);
                model->setItem(x,4,item);

                consulta3.exec("update saldo_acum_conceptos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total)+"' where cod_contable='"+consulta2.value(0).toString()+"' and prog_academico='"+academico+"'");
                consulta3.exec("commit");
            }
        }
        report->addItemModel(model,"model");
        x=-1;
        total2=saldo_total2=0;

        //Sumo el total diario, desglosado por forma de pago y banco
        //DEPOSITOS
        consulta.exec("select id_banco,nombre from bancos where deposito='S'");
        while(consulta.next())
        {
            total=0;
            if(cont_dialog.user->currentText()=="ACTUAL")
                consulta3.exec("select referencia from factura_deposito where forma_pago='3' and id_banco='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
            else
                consulta3.exec("select referencia from factura_deposito where forma_pago='3' and id_banco='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");

            while(consulta3.next())
            {
                consulta4.exec("select monto from deposito where referencia='"+consulta3.value(0).toString()+"' and forma_pago='3' and id_banco='"+consulta.value(0).toString()+"'");
                while(consulta4.next())
                {
                    total+=consulta4.value(0).toDouble();
                }
            }
            saldo=0;
            consulta2.exec("select * from saldo_acum_bancos where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=1");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                     saldo+=consulta2.value(i).toDouble();

            }
            x++;
            model2->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString(), Qt::EditRole);
            model2->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);
            model2->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(total, Qt::EditRole);
            model2->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total+saldo,Qt::EditRole);
            model2->setItem(x,3,item);

            consulta2.exec("update saldo_acum_bancos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total)+"' where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=1");
            //consulta2.exec("update saldo_acum_bancos set saldo ='"+tr("%1").arg(total+saldo)+"' where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=1");
            consulta2.exec("commit");

            total2+=total;
            saldo_total2+=saldo;
        }

        report->addItemModel(model2,"model2");
        x=-1;

        //DEBITO
        consulta.exec("select id_banco,nombre from bancos where debito='S'");
        while(consulta.next())
        {
            total=0;
            if(cont_dialog.user->currentText()=="ACTUAL")
                consulta3.exec("select referencia from factura_deposito where forma_pago='4' and id_banco='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
            else
                consulta3.exec("select referencia from factura_deposito where forma_pago='4' and id_banco='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
            while(consulta3.next())
            {
                consulta4.exec("select monto from deposito where referencia='"+consulta3.value(0).toString()+"' and forma_pago='4' and id_banco='"+consulta.value(0).toString()+"'");
                while(consulta4.next())
                {
                    total+=consulta4.value(0).toDouble();
                }
            }
            saldo=0;
            consulta2.exec("select * from saldo_acum_bancos where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=2");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta2.value(i).toDouble();
            }
            x++;
            model3->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString(), Qt::EditRole);
            model3->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);
            model3->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(total, Qt::EditRole);
            model3->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total+saldo,Qt::EditRole);
            model3->setItem(x,3,item);

            consulta2.exec("update saldo_acum_bancos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total)+"' where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=2");
            //consulta2.exec("update saldo_acum_bancos set saldo ='"+tr("%1").arg(total+saldo)+"' where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=2");
            consulta2.exec("commit");
            total2+=total;
            saldo_total2+=saldo;
        }

        report->addItemModel(model3,"model3");
        x=-1;

        //CREDITO
        consulta.exec("select id_banco,nombre from bancos where credito='S'");
        while(consulta.next())
        {
            total=0;
            if(cont_dialog.user->currentText()=="ACTUAL")
                consulta3.exec("select referencia from factura_deposito where forma_pago='5' and id_banco='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
            else
                consulta3.exec("select referencia from factura_deposito where forma_pago='5' and id_banco='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
            while(consulta3.next())
            {
                consulta4.exec("select monto from deposito where referencia='"+consulta3.value(0).toString()+"' and forma_pago='5' and id_banco='"+consulta.value(0).toString()+"'");
                while(consulta4.next())
                {
                    total+=consulta4.value(0).toDouble();
                }
            }
            saldo=0;
            consulta2.exec("select * from saldo_acum_bancos where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=3");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta2.value(i).toDouble();
            }
            x++;
            model4->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString(), Qt::EditRole);
            model4->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);
            model4->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(total, Qt::EditRole);
            model4->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total+saldo,Qt::EditRole);
            model4->setItem(x,3,item);

            consulta2.exec("update saldo_acum_bancos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total)+"' where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=3");
            //consulta2.exec("update saldo_acum_bancos set saldo ='"+tr("%1").arg(total+saldo)+"' where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=2");
            consulta2.exec("commit");
            total2+=total;
            saldo_total2+=saldo;
        }

        report->addItemModel(model4,"model4");
        report->addParameter("saldo",saldo_total2);
        report->addParameter("total",total2);
        report->addParameter("saldo_total",saldo_total2+total2);
    }
    else if(academico=="4")//FUNDAUC VA A TU COLEGIO
    {
        report->addParameter("programa","FUNDAUC VA A TU COLEGIO");
        bool rif=false;
        x=-1;
        consulta.exec("select * from cuentas_por_cobrar where prog_academico='"+academico+"' and ultimo_pago=to_date('"+fecha+"','dd-mm-yyyy')");
        while(consulta.next())
        {
            x++;
            model->insertRow(x);
            consulta2.exec("select cod_contable from codigo_concepto where tipo='CPC'");
            while(consulta2.next())
            {
                item = new QStandardItem();
                item->setData(consulta2.value(0).toString(),Qt::EditRole);
                model->setItem(x,0,item);
            }
            consulta2.exec("select razon from empresas where rif='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                item = new QStandardItem();
                item->setData("CUENTA POR COBRAR "+consulta2.value(0).toString(), Qt::EditRole);
                model->setItem(x,1,item);
                rif=true;
            }
            if(!rif)
            {
                consulta2.exec("select nombre from estudiante where cedula_est='"+consulta.value(0).toString()+"'");
                while(consulta2.next())
                {
                    item = new QStandardItem();
                    item->setData("CUENTA POR COBRAR "+consulta2.value(0).toString(), Qt::EditRole);
                    model->setItem(x,1,item);
                }
            }
            item = new QStandardItem();
            item->setData(consulta.value(1).toDouble()+consulta.value(3).toDouble(), Qt::EditRole);
            model->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(consulta.value(3).toDouble(), Qt::EditRole);
            model->setItem(x,3,item);
            item = new QStandardItem();
            item->setData(consulta.value(1).toDouble(),Qt::EditRole);
            model->setItem(x,4,item);
        }

        rif=false;
        consulta.exec("select * from cuentas_por_cobrar where prog_academico='"+academico+"' and fec_emi=to_date('"+fecha+"','dd-mm-yyyy')");
        while(consulta.next())
        {
            x++;
            model->insertRow(x);
            consulta2.exec("select cod_contable from codigo_concepto where tipo='CPC'");
            while(consulta2.next())
            {
                item = new QStandardItem();
                item->setData(consulta2.value(0).toString(),Qt::EditRole);
                model->setItem(x,0,item);
            }
            consulta2.exec("select razon from empresas where rif='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                item = new QStandardItem();
                item->setData("CUENTA POR COBRAR "+consulta2.value(0).toString(), Qt::EditRole);
                model->setItem(x,1,item);
                rif=true;
            }
            if(!rif)
            {
                consulta2.exec("select nombre from estudiante where cedula_est='"+consulta.value(0).toString()+"'");
                while(consulta2.next())
                {
                    item = new QStandardItem();
                    item->setData("CUENTA POR COBRAR "+consulta2.value(0).toString(), Qt::EditRole);
                    model->setItem(x,1,item);
                }
            }
            item = new QStandardItem();
            item->setData(0, Qt::EditRole);
            model->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(consulta.value(1).toDouble()*(-1), Qt::EditRole);
            model->setItem(x,3,item);
            item = new QStandardItem();
            item->setData(consulta.value(1).toDouble(),Qt::EditRole);
            model->setItem(x,4,item);
        }

        consulta.exec("select id_metodo,descripcion,niveles from metodos where prog_academico='"+academico+"'");
        while(consulta.next())
        {
            total2=total3=total4=total5=0;
            if((consulta.value(0).toString()=="AEC")||(consulta.value(0).toString()=="AEC-J"))
                curso="AEC";
            else
                curso=consulta.value(0).toString();

            //CUOTAS
            if(cont_dialog.user->currentText()=="ACTUAL")
                consulta3.exec("select cantidad,subtotal from detalle_factura where item='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi =to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
            else
                consulta3.exec("select cantidad,subtotal from detalle_factura where item='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi =to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
            while(consulta3.next())
            {
                total2+=consulta3.value(1).toDouble();
            }

            //INGRESO POR INSCRIPCION EN SECCIONES
            for(i=0;i<consulta.value(2).toInt();i++)
            {
                id_fact=new QList<QString>();
                precio_guia=precio_libro=precio_cd=0;
                total3=total4=total5=0;
                sin_cd=sin_libro=0;

                //Establezco el precio de guia, libro y cd para este metodo en este nivel

                consulta2.exec("select id_mat from materiales where tipo='G' and id_curso='"+curso+"' and nivel='"+tr("%1").arg(i+1)+"'");
                while(consulta2.next())
                {
                    consulta6.exec("select precio1 from precios where item='"+consulta2.value(0).toString()+"'");
                    while(consulta6.next())
                    {
                        precio_guia=consulta6.value(0).toDouble();
                    }
                }
                consulta2.exec("select id_mat from materiales where tipo='L' and id_curso='"+curso+"' and nivel='"+tr("%1").arg(i+1)+"'");
                while(consulta2.next())
                {
                    consulta6.exec("select precio1 from precios where item='"+consulta2.value(0).toString()+"'");
                    while(consulta6.next())
                    {
                        precio_libro=consulta6.value(0).toDouble();
                    }
                }
                consulta2.exec("select id_mat from materiales where tipo='CD' and id_curso='"+curso+"' and nivel='"+tr("%1").arg(i+1)+"'");
                while(consulta2.next())
                {
                    consulta6.exec("select precio1 from precios where item='"+consulta2.value(0).toString()+"'");
                    while(consulta6.next())
                    {
                        precio_cd=consulta6.value(0).toDouble();
                    }
                }

                //Si existe factura de una seccion de ese nivel y metodo se suman individualmente los 3 items (libro, guia, cd) y el costo por concepto de curso (curso=subtotal-libro-guia-cd)

                consulta2.exec("select id_seccion,modalidad from secciones where id_metodo='"+consulta.value(0).toString()+"' and nivel='"+tr("%1").arg(i+1)+"'");
                while(consulta2.next())
                {
                    cant=0;
                    if(cont_dialog.user->currentText()=="ACTUAL")
                        consulta3.exec("select cantidad,subtotal,id_fact from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi =to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
                    else
                        consulta3.exec("select cantidad,subtotal,id_fact from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi =to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
                    while(consulta3.next())
                    {
                        if(curso=="AEC") //Para fundauc va a tu colegio, se suma el costo de 4 libros, 4 guias y 2 cd's si es American English. Para el resto, 2 libros y guias.
                        {
                            total4+=4*precio_guia;
                            total3+=4*precio_libro;
                            total5+=2*precio_cd;
                            total2+=consulta3.value(1).toDouble()-(4*precio_libro)-(4*precio_guia)-(2*precio_cd); //Ingreso por curso
                        }
                        else
                        {
                            total4+=2*precio_guia;
                            total3+=2*precio_libro;
                            total5+=precio_cd;
                            total2+=consulta3.value(1).toDouble()-(2*precio_libro)-(2*precio_guia)-(precio_cd); //Ingreso por curso
                        }
                        id_fact->append(consulta3.value(2).toString());
                    }
                }

                //CANTIDAD DE SIN LIBRO Y SIN CD DE ESE NIVEL -- Revisar si en fvtc existe esta modalidad
                for(j=0;j<id_fact->size();j++)
                {
                    consulta2.exec("select cantidad from detalle_factura where item='DL' and id_fact = '"+id_fact->at(j)+"'");
                    while(consulta2.next())
                    {
                        sin_libro+=consulta2.value(0).toInt();
                    }
                    consulta2.exec("select cantidad from detalle_factura where item='DCD' and id_fact = '"+id_fact->at(j)+"'");
                    while(consulta2.next())
                    {
                        sin_cd+=consulta2.value(0).toInt();
                    }
                }

                //LIBROS SUELTOS EN BS DE ESE NIVEL
                consulta2.exec("select id_mat from materiales where tipo='L' and id_curso='"+curso+"' and nivel='"+tr("%1").arg(i+1)+"'");
                while(consulta2.next())
                {
                    if(cont_dialog.user->currentText()=="ACTUAL")
                        consulta3.exec("select subtotal from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
                    else
                        consulta3.exec("select subtotal from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
                    while(consulta3.next())
                    {
                        total3+=consulta3.value(0).toDouble();
                    }
                }

                //GUIAS SUELTAS EN BS DE ESE NIVEL
                consulta2.exec("select id_mat from materiales where tipo='G' and id_curso='"+curso+"' and nivel='"+tr("%1").arg(i+1)+"'");
                while(consulta2.next())
                {
                    if(cont_dialog.user->currentText()=="ACTUAL")
                        consulta3.exec("select subtotal from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
                    else
                        consulta3.exec("select subtotal from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
                    while(consulta3.next())
                    {
                        total4+=consulta3.value(0).toDouble();
                    }
                }

                //CDS SUELTOS EN BS DE ESE NIVEL
                consulta2.exec("select id_mat from materiales where tipo='CD' and id_curso='"+curso+"' and nivel='"+tr("%1").arg(i+1)+"'");
                while(consulta2.next())
                {
                    if(cont_dialog.user->currentText()=="ACTUAL")
                        consulta3.exec("select subtotal from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
                    else
                        consulta3.exec("select subtotal from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
                    while(consulta3.next())
                    {
                        total5+=consulta3.value(0).toDouble();
                    }
                }
                total_libros+=total3-(sin_libro*precio_libro);
                total_cds+=total5-(sin_cd*precio_cd);
                total_guias+=total4;
            }
            total_cursos+=total2;
        }

        consulta.exec("select cod_contable,concepto from codigo_concepto where tipo='CI'");//codigo contable de fvtc
        while(consulta.next())
        {
            saldo=0;
            consulta2.exec("select * from saldo_acum_conceptos where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta2.value(i).toDouble();
            }
            x++;
            model->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta.value(0).toString(),Qt::EditRole);
            model->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString(), Qt::EditRole);
            model->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);
            model->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total_cursos, Qt::EditRole);
            model->setItem(x,3,item);
            item = new QStandardItem();
            item->setData(total_cursos+saldo,Qt::EditRole);
            model->setItem(x,4,item);

            consulta2.exec("update saldo_acum_conceptos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total_cursos)+"' where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
            consulta2.exec("commit");
        }

        consulta.exec("select cod_contable,concepto from codigo_concepto where tipo='L'");
        while(consulta.next())
        {
            saldo=0;
            consulta2.exec("select * from saldo_acum_conceptos where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta2.value(i).toDouble();
            }
            x++;
            model->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta.value(0).toString(),Qt::EditRole);
            model->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString(), Qt::EditRole);
            model->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);
            model->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total_libros, Qt::EditRole);
            model->setItem(x,3,item);
            item = new QStandardItem();
            item->setData(total_libros+saldo,Qt::EditRole);
            model->setItem(x,4,item);

            consulta2.exec("update saldo_acum_conceptos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total_libros)+"' where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
            consulta2.exec("commit");
        }

        consulta.exec("select cod_contable,concepto from codigo_concepto where tipo='G'");
        while(consulta.next())
        {
            saldo=0;
            consulta2.exec("select * from saldo_acum_conceptos where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta2.value(i).toDouble();
            }
            x++;
            model->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta.value(0).toString(),Qt::EditRole);
            model->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString(), Qt::EditRole);
            model->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);
            model->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total_guias, Qt::EditRole);
            model->setItem(x,3,item);
            item = new QStandardItem();
            item->setData(saldo+total_guias,Qt::EditRole);
            model->setItem(x,4,item);

            consulta2.exec("update saldo_acum_conceptos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total_guias)+"' where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
            consulta2.exec("commit");
        }

        consulta.exec("select cod_contable,concepto from codigo_concepto where tipo='CD'");
        while(consulta.next())
        {
            saldo=0;
            consulta2.exec("select * from saldo_acum_conceptos where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta2.value(i).toDouble();
            }
            x++;
            model->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta.value(0).toString(),Qt::EditRole);
            model->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString(), Qt::EditRole);
            model->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);
            model->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total_cds, Qt::EditRole);
            model->setItem(x,3,item);
            item = new QStandardItem();
            item->setData(saldo+total_cds,Qt::EditRole);
            model->setItem(x,4,item);

            consulta2.exec("update saldo_acum_conceptos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total_cds)+"' where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
            consulta2.exec("commit");
        }
        /*
        //Calculo totales de los conceptos distintos a cursos/libros
        consulta.exec("select abrev from tipo_material where idiomas='S' and abrev <>'L' and abrev <>'G' and abrev <>'CD' and abrev <>'CI' and abrev <>'C'");
        while(consulta.next())
        {
            total=0;
            consulta2.exec("select id_fact from factura where fecha_emi =to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='1' and usuario='"+usuario+"'");
            while(consulta2.next())
            {
                if(consulta.value(0).toString()=="D")
                    consulta3.exec("select cantidad,subtotal from detalle_factura where id_fact='"+consulta2.value(0).toString()+"' and tipo_item='"+consulta.value(0).toString()+"' and item<>'DCD' and item<>'DL'");
                else
                    consulta3.exec("select cantidad,subtotal from detalle_factura where id_fact='"+consulta2.value(0).toString()+"' and tipo_item='"+consulta.value(0).toString()+"'");
                while(consulta3.next())
                {
                    total+=consulta3.value(1).toDouble();
                }
            }

            consulta2.exec("select cod_contable,concepto from codigo_concepto where tipo='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                consulta3.exec("select saldo from saldo_acum_conceptos where cod_contable='"+consulta2.value(0).toString()+"' and prog_academico=1");
                while(consulta3.next())
                {
                    saldo=consulta3.value(0).toDouble();
                }
                x++;
                model->insertRow(x);
                item = new QStandardItem();
                item->setData(consulta2.value(0).toString(),Qt::EditRole);
                model->setItem(x,0,item);
                item = new QStandardItem();
                item->setData(consulta2.value(1).toString(), Qt::EditRole);
                model->setItem(x,1,item);
                item = new QStandardItem();
                item->setData(saldo, Qt::EditRole);
                model->setItem(x,2,item);
                item = new QStandardItem();
                item->setData(total, Qt::EditRole);
                model->setItem(x,3,item);
                item = new QStandardItem();
                item->setData(total+saldo,Qt::EditRole);
                model->setItem(x,4,item);

                consulta3.exec("update saldo_acum_conceptos set "+tr("dia_%1").arg(fecha.day())+"='"+tr("%1").arg(total)+"',saldo='"+tr("%1").arg(total+saldo)+"' where cod_contable='"+consulta2.value(0).toString()+"' and prog_academico=1");
                consulta3.exec("commit");
            }
        }*/
        report->addItemModel(model,"model");

        x=-1;
        total2=saldo_total2=0;
        consulta.exec("select id_banco,nombre from bancos where deposito='S'");
        while(consulta.next())
        {
            total=0;
            if(cont_dialog.user->currentText()=="ACTUAL")
                consulta3.exec("select referencia from factura_deposito where forma_pago='3' and id_banco='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
            else
                consulta3.exec("select referencia from factura_deposito where forma_pago='3' and id_banco='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");

            while(consulta3.next())
            {
                consulta4.exec("select monto from deposito where referencia='"+consulta3.value(0).toString()+"' and forma_pago='3' and id_banco='"+consulta.value(0).toString()+"'");
                while(consulta4.next())
                {
                    total+=consulta4.value(0).toDouble();
                }
            }
            saldo=0;
            consulta2.exec("select * from saldo_acum_bancos where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago='1'");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta2.value(i).toDouble();
            }
            x++;
            model2->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString(), Qt::EditRole);
            model2->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);
            model2->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(total, Qt::EditRole);
            model2->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total+saldo,Qt::EditRole);
            model2->setItem(x,3,item);

            consulta2.exec("update saldo_acum_bancos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total)+"' where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=1");
            //consulta2.exec("update saldo_acum_bancos set saldo='"+tr("%1").arg(total+saldo)+"' where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago='1'");
            consulta2.exec("commit");

            total2+=total;
            saldo_total2+=saldo;
        }

        report->addItemModel(model2,"model2");
        x=0;
        consulta.exec("select id_banco,nombre from bancos where debito='S'");
        while(consulta.next())
        {
            total=0;
            if(cont_dialog.user->currentText()=="ACTUAL")
                consulta3.exec("select referencia from factura_deposito where forma_pago='4' and id_banco='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
            else
                consulta3.exec("select referencia from factura_deposito where forma_pago='4' and id_banco='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");

            while(consulta3.next())
            {
                consulta4.exec("select monto from deposito where referencia='"+consulta3.value(0).toString()+"' and forma_pago='4' and id_banco='"+consulta.value(0).toString()+"'");
                while(consulta4.next())
                {
                    total+=consulta4.value(0).toDouble();
                }
            }
            saldo=0;
            consulta2.exec("select * from saldo_acum_bancos where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago='2'");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta2.value(i).toDouble();
            }
            x++;
            model3->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString(), Qt::EditRole);
            model3->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);
            model3->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(total, Qt::EditRole);
            model3->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total+saldo,Qt::EditRole);
            model3->setItem(x,3,item);

            consulta2.exec("update saldo_acum_bancos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total)+"' where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=2");
            //consulta2.exec("update saldo_acum_bancos set saldo='"+tr("%1").arg(total+saldo)+"' where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago='2'");
            consulta2.exec("commit");
            total2+=total;
            saldo_total2+=saldo;
        }
        report->addItemModel(model3,"model3");
        report->addItemModel(model4,"model4");
        report->addParameter("saldo",saldo_total2);
        report->addParameter("total",total2);
        report->addParameter("saldo_total",saldo_total2+total2);
    }

    else if(academico=="3")//DIPLOMADOS
    {
        bool rif=false;
        report->addParameter("programa","CAPACITACION Y FORMACION PROFESIONAL");
        x=-1;
        consulta.exec("select * from cuentas_por_cobrar where prog_academico='"+academico+"' and ultimo_pago=to_date('"+fecha+"','dd-mm-yyyy')");
        while(consulta.next())
        {
            x++;
            model->insertRow(x);
            consulta2.exec("select cod_contable from codigo_concepto where tipo='CPC'");
            while(consulta2.next())
            {
                item = new QStandardItem();
                item->setData(consulta2.value(0).toString(),Qt::EditRole);
                model->setItem(x,0,item);
            }
            consulta2.exec("select razon from empresas where rif='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                item = new QStandardItem();
                item->setData("CUENTA POR COBRAR "+consulta2.value(0).toString(), Qt::EditRole);
                model->setItem(x,1,item);
                rif=true;
            }
            if(!rif)
            {
                consulta2.exec("select nombre from estudiante where cedula_est='"+consulta.value(0).toString()+"'");
                while(consulta2.next())
                {
                    item = new QStandardItem();
                    item->setData("CUENTA POR COBRAR "+consulta2.value(0).toString(), Qt::EditRole);
                    model->setItem(x,1,item);
                }
            }
            item = new QStandardItem();
            item->setData(consulta.value(1).toDouble()+consulta.value(3).toDouble(), Qt::EditRole);
            model->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(consulta.value(3).toDouble(), Qt::EditRole);
            model->setItem(x,3,item);
            item = new QStandardItem();
            item->setData(consulta.value(1).toDouble(),Qt::EditRole);
            model->setItem(x,4,item);
        }

        rif=false;
        consulta.exec("select * from cuentas_por_cobrar where prog_academico='"+academico+"' and fec_emi=to_date('"+fecha+"','dd-mm-yyyy')");
        while(consulta.next())
        {
            x++;
            model->insertRow(x);
            consulta2.exec("select cod_contable from codigo_concepto where tipo='CPC'");
            while(consulta2.next())
            {
                item = new QStandardItem();
                item->setData(consulta2.value(0).toString(),Qt::EditRole);
                model->setItem(x,0,item);
            }
            consulta2.exec("select razon from empresas where rif='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                item = new QStandardItem();
                item->setData("CUENTA POR COBRAR "+consulta2.value(0).toString(), Qt::EditRole);
                model->setItem(x,1,item);
                rif=true;
            }
            if(!rif)
            {
                consulta2.exec("select nombre from estudiante where cedula_est='"+consulta.value(0).toString()+"'");
                while(consulta2.next())
                {
                    item = new QStandardItem();
                    item->setData("CUENTA POR COBRAR "+consulta2.value(0).toString(), Qt::EditRole);
                    model->setItem(x,1,item);
                }
            }
            item = new QStandardItem();
            item->setData(0, Qt::EditRole);
            model->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(consulta.value(1).toDouble()*(-1), Qt::EditRole);
            model->setItem(x,3,item);
            item = new QStandardItem();
            item->setData(consulta.value(1).toDouble(),Qt::EditRole);
            model->setItem(x,4,item);
        }

        consulta.exec("select id_diplomado,cod_contable,cod_descuento,descripcion from diplo_temp");
        while(consulta.next())
        {
            total=0; total2=0;
            consulta2.exec("select id from cohortes where id_diplomado='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                if(cont_dialog.user->currentText()=="ACTUAL")
                    consulta4.exec("select subtotal,id_fact from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"'  and usuario='"+usuario+"')");
                else
                    consulta4.exec("select subtotal,id_fact from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
                while(consulta4.next())
                {
                    total+=consulta4.value(0).toDouble();
                    in=true;
                }
                //meter esta consulta dentro de la anterior
                if(in)
                {
                    consulta4.exec("select subtotal from detalle_factura where id_fact='"+consulta3.value(0).toString()+"' and tipo_item='D'");
                    while(consulta4.next())
                    {
                        total2+=consulta4.value(0).toDouble();
                    }
                    in=false;
                }
            }
            saldo=0;
            consulta2.exec("select * from saldo_acum_conceptos where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta2.value(i).toDouble();
            }
            x++;
            model->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString(),Qt::EditRole);
            model->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(consulta.value(3).toString(), Qt::EditRole);
            model->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);
            model->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total, Qt::EditRole);
            model->setItem(x,3,item);
            item = new QStandardItem();
            item->setData(total+saldo,Qt::EditRole);
            model->setItem(x,4,item);

            consulta2.exec("update saldo_acum_conceptos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total)+"' where cod_contable='"+consulta.value(1).toString()+"' and prog_academico='"+academico+"'");
            consulta2.exec("commit");

            saldo=0;
            consulta2.exec("select * from saldo_acum_conceptos where cod_contable='"+consulta.value(2).toString()+"' and prog_academico='"+academico+"'");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta2.value(i).toDouble();
                x++;
                model->insertRow(x);
                item = new QStandardItem();
                item->setData(consulta.value(2).toString(),Qt::EditRole);
                model->setItem(x,0,item);
                item = new QStandardItem();
                item->setData("DESCUENTO "+consulta.value(3).toString(), Qt::EditRole);
                model->setItem(x,1,item);
                item = new QStandardItem();
                item->setData(saldo, Qt::EditRole);
                model->setItem(x,2,item);
                item = new QStandardItem();
                item->setData(total2, Qt::EditRole);
                model->setItem(x,3,item);
                item = new QStandardItem();
                item->setData((total2+saldo),Qt::EditRole);
                model->setItem(x,4,item);

                consulta2.exec("update saldo_acum_conceptos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total2)+"' where cod_contable='"+consulta.value(2).toString()+"' and prog_academico='"+academico+"'");
                consulta2.exec("commit");
            }
        }

        consulta.exec("select abrev from tipo_material where cfp='S' and abrev <>'DP' and abrev<>'D'");
        while(consulta.next())
        {
            total=0;
            consulta2.exec("select id_mat from materiales where tipo='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                if(cont_dialog.user->currentText()=="ACTUAL")
                    consulta4.exec("select subtotal from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
                else
                    consulta4.exec("select subtotal from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
                while(consulta4.next())
                {
                    total+=consulta4.value(0).toDouble();
                }
            }

            consulta2.exec("select cod_contable,concepto from codigo_concepto where tipo='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                saldo=0;
                consulta3.exec("select * from saldo_acum_conceptos where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
                while(consulta3.next())
                {
                    for(i=1;i<32;i++)
                        saldo+=consulta2.value(i).toDouble();
                }

                x++;
                model->insertRow(x);
                item = new QStandardItem();
                item->setData(consulta2.value(0).toString(),Qt::EditRole);
                model->setItem(x,0,item);
                item = new QStandardItem();
                item->setData(consulta2.value(1).toString(), Qt::EditRole);
                model->setItem(x,1,item);
                item = new QStandardItem();
                item->setData(saldo, Qt::EditRole);
                model->setItem(x,2,item);
                item = new QStandardItem();
                item->setData(total, Qt::EditRole);
                model->setItem(x,3,item);
                item = new QStandardItem();
                item->setData(total+saldo,Qt::EditRole);
                model->setItem(x,4,item);

                consulta3.exec("update saldo_acum_conceptos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total)+"' where cod_contable='"+consulta2.value(0).toString()+"' and prog_academico='"+academico+"'");
                consulta3.exec("commit");
            }
        }

        report->addItemModel(model,"model");
        x=-1;
        total2=saldo_total2=0;
        consulta.exec("select id_banco,nombre from bancos where deposito='S'");
        while(consulta.next())
        {
            total=0;
            if(cont_dialog.user->currentText()=="ACTUAL")
            consulta3.exec("select referencia from factura_deposito where forma_pago='3' and id_banco='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
            else
            consulta3.exec("select referencia from factura_deposito where forma_pago='3' and id_banco='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");

            while(consulta3.next())
            {
                consulta4.exec("select monto from deposito where referencia='"+consulta3.value(0).toString()+"' and forma_pago='3' and id_banco='"+consulta.value(0).toString()+"'");
                while(consulta4.next())
                {
                    total+=consulta4.value(0).toDouble();
                }
            }

            consulta2.exec("select ultimo_deposito from cuentas_por_cobrar where ultimo_pago=to_date('"+fecha+"','dd-mm-yyyy')");
            while(consulta2.next())
            {
                if(cont_dialog.user->currentText()=="ACTUAL")

                consulta3.exec("select monto from deposito where referencia='"+consulta2.value(0).toString()+"' and forma_pago='3' and id_banco='"+consulta.value(0).toString()+"' and usuario='"+usuario+"'");
                else
                    consulta3.exec("select monto from deposito where referencia='"+consulta2.value(0).toString()+"' and forma_pago='3' and id_banco='"+consulta.value(0).toString()+"'");

                while(consulta3.next())
                {
                    total+=consulta3.value(0).toDouble();
                }
            }
            saldo=0;
            consulta2.exec("select * from saldo_acum_bancos where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=1");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta2.value(i).toDouble();
            }
            x++;
            model2->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString(), Qt::EditRole);
            model2->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);
            model2->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(total, Qt::EditRole);
            model2->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total+saldo,Qt::EditRole);
            model2->setItem(x,3,item);

            consulta2.exec("update saldo_acum_bancos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total)+"' where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=1");
            //consulta2.exec("update saldo_acum_bancos set saldo='"+tr("%1").arg(total+saldo)+"' where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=1");
            consulta2.exec("commit");
            total2+=total;
            saldo_total2+=saldo;
        }
        report->addItemModel(model2,"model2");

        x=-1;
        consulta.exec("select id_banco,nombre from bancos where debito='S'");
        while(consulta.next())
        {
            total=0;
            if(cont_dialog.user->currentText()=="ACTUAL")
            consulta3.exec("select referencia from factura_deposito where forma_pago='4' and id_banco='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
            else
                consulta3.exec("select referencia from factura_deposito where forma_pago='4' and id_banco='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");

            while(consulta3.next())
            {
                consulta4.exec("select monto from deposito where referencia='"+consulta3.value(0).toString()+"' and forma_pago='4' and id_banco='"+consulta.value(0).toString()+"'");
                while(consulta4.next())
                {
                    total+=consulta4.value(0).toDouble();
                }
            }
            saldo=0;
            consulta2.exec("select * from saldo_acum_bancos where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=2");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta2.value(i).toDouble();
            }
            x++;
            model3->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString(), Qt::EditRole);
            model3->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);
            model3->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(total, Qt::EditRole);
            model3->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total+saldo,Qt::EditRole);
            model3->setItem(x,3,item);

            consulta2.exec("update saldo_acum_bancos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total)+"' where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=2");
            //consulta2.exec("update saldo_acum_bancos set saldo='"+tr("%1").arg(total+saldo)+"' where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=2");
            consulta2.exec("commit");
            total2+=total;
            saldo_total2+=saldo;
        }
        report->addItemModel(model3,"model3");

        x=-1;
        consulta.exec("select id_banco,nombre from bancos where credito='S'");
        while(consulta.next())
        {
            total=0;
            if(cont_dialog.user->currentText()=="ACTUAL")
            consulta3.exec("select referencia from factura_deposito where forma_pago='5' and id_banco='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"' and usuario='"+usuario+"')");
            else
                consulta3.exec("select referencia from factura_deposito where forma_pago='5' and id_banco='"+consulta.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");

            while(consulta3.next())
            {
                consulta4.exec("select monto from deposito where referencia='"+consulta3.value(0).toString()+"' and forma_pago='5' and id_banco='"+consulta.value(0).toString()+"'");
                while(consulta4.next())
                {
                    total+=consulta4.value(0).toDouble();
                }
            }
            saldo=0;
            consulta2.exec("select * from saldo_acum_bancos where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=3");
            while(consulta2.next())
            {
                for(i=1;i<32;i++)
                    saldo+=consulta2.value(i).toDouble();
            }
            x++;
            model4->insertRow(x);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString(), Qt::EditRole);
            model4->setItem(x,0,item);
            item = new QStandardItem();
            item->setData(saldo, Qt::EditRole);
            model4->setItem(x,1,item);
            item = new QStandardItem();
            item->setData(total, Qt::EditRole);
            model4->setItem(x,2,item);
            item = new QStandardItem();
            item->setData(total+saldo,Qt::EditRole);
            model4->setItem(x,3,item);

            consulta2.exec("update saldo_acum_bancos set "+tr("dia_%1").arg(cont_dialog.fecha->date().day())+"='"+tr("%1").arg(total)+"' where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=3");
            //consulta2.exec("update saldo_acum_bancos set saldo='"+tr("%1").arg(total+saldo)+"' where id_banco='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"' and forma_pago=3");
            consulta2.exec("commit");
            total2+=total;
            saldo_total2+=saldo;
        }
        report->addItemModel(model4,"model4");
        report->addParameter("saldo",saldo_total2);
        report->addParameter("total",total2);
        report->addParameter("saldo_total",total2+saldo_total2);

    }

    //Poner aqui la suma de los depositos

    if(cont_dialog.user->currentText()=="ACTUAL")
    consulta.exec("select max(id_fact),min(id_fact) from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy')  and usuario='"+usuario+"'");
    else
        consulta.exec("select max(id_fact),min(id_fact) from factura where fecha_emi=to_date('"+fecha+"','dd-mm-yyyy')");

    while(consulta.next())
    {
        desde=consulta.value(1).toString();
        hasta=consulta.value(0).toString();
    }

    report->addParameter("desde0",desde);
    report->addParameter("hasta0",hasta);
    report->addParameter("desde1",cont_dialog.control1->text());
    report->addParameter("hasta1",cont_dialog.control2->text());

    if(cont_dialog.user->currentText()=="ACTUAL")
        consulta.exec("select id_fact from factura where status='A' and fecha_emi=to_date('"+fecha+"','dd-mm-yyyy')  and usuario='"+usuario+"'");
    else
    consulta.exec("select id_fact from factura where status='A' and fecha_emi=to_date('"+fecha+"','dd-mm-yyyy')");

    while(consulta.next())
    {
        anuladas+=" "+consulta.value(0).toString();
    }

    if(cont_dialog.rango->text().isNull())
        rango="";
    else
        rango=cont_dialog.rango->text();

    if(cont_dialog.observacion->text().isNull())
        observacion="";
    else
        observacion=cont_dialog.observacion->text();

    report->addParameter("anuladas",anuladas);
    report->addParameter("contingencia",rango);
    report->addParameter("observaciones",observacion);
    if(cont_dialog.user->currentText()=="ACTUAL")
        report->addParameter("usuario",usuario);
    else
        report->addParameter("usuario","TODOS");

    if(cont_dialog.programa->currentText()=="DIPLOMADOS")
        report->setReportFile("reportes/cuadre_caja_cfp.xml");
    else
        report->setReportFile("reportes/cuadre_caja.xml");

    report->runReportToPDF("test.pdf");
    if (!report->hasError())
    {
        if(cont_dialog.salida->currentIndex()==0)
            ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        else
            ShellExecuteA(NULL,"print",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
    }
    else
        QMessageBox::information(0,"Error",report->lastErrorMsg());

    dialogo->close();
}


void procesos_caja::setupCedula()
{
    dialogo = new QWidget();
    ced_dialog.setupUi(dialogo);
    QSqlQuery consulta("select descripcion from programa_academico order by id");
    while(consulta.next())
    {
        ced_dialog.programa->addItem(consulta.value(0).toString());
    }

    ced_dialog.salida->addItem("PANTALLA");
    ced_dialog.salida->addItem("IMPRESORA");
    ced_dialog.fin->setDate(QDate::currentDate());
    ced_dialog.inicio->setDate(QDate::currentDate());
    ced_dialog.metodo->setEnabled(false);
    //ced_dialog.fin->setDate(QDate::fromString(tr("%1-%2-%3").arg(QDate::currentDate().daysInMonth()).arg(QDate::currentDate().month()).arg(QDate::currentDate().year()),"dd-M-yyyy"));
    //connect(ced_dialog.programa,SIGNAL(currentIndexChanged(QString)),this,SLOT(programaChanged2(QString)));
    connect(ced_dialog.aceptar,SIGNAL(clicked()),this,SLOT(cedulaMensual()));
    dialogo->show();
}


void procesos_caja::programaChanged2(QString s)
{
    QSqlQuery consulta,consulta2;
    ced_dialog.metodo->clear();
    ced_dialog.metodo->addItem("TODOS");
    consulta.exec("select id from programa_academico where descripcion ='"+s+"'");
    while(consulta.next())
    {
        consulta2.exec("select descripcion from metodos where prog_academico='"+consulta.value(0).toString()+"' order by descripcion");
        while(consulta2.next())
        {
            ced_dialog.metodo->addItem(consulta2.value(0).toString());
        }
    }
    connect(ced_dialog.aceptar,SIGNAL(clicked()),this,SLOT(cedulaMensual()));
}


void procesos_caja::cedulaMensual()
{
    QSqlQuery consulta,consulta2;
    QString concepto,prog,mes,anio,academico;
    double total_dia;
    int i,j;
    QStandardItem *item;

    consulta.exec("select id from programa_academico where descripcion='"+ced_dialog.programa->currentText()+"'");
    while(consulta.next())
    {
        academico=consulta.value(0).toString();
    }

    report->reset();
    //QStandardItemModel *model = new QStandardItemModel(0,33);
    report->addParameter("prog",ced_dialog.programa->currentText());
    report->addParameter("mes",tr("%1").arg(ced_dialog.fin->date().month()));
    report->addParameter("anio",tr("%1").arg(ced_dialog.fin->date().year()));

    if(academico=="3")
    {
        i=-1;
        double descuento,ingreso;
        QStandardItemModel *model = new QStandardItemModel(0,2);
        consulta.exec("select cod_contable,cod_descuento,descripcion from diplo_temp order by descripcion");
        while(consulta.next())
        {
            descuento=ingreso=0;
            for(j=1;j<32;j++)
            {
                consulta2.exec("select dia_"+tr("%1").arg(j)+" from saldo_acum_conceptos where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
                while(consulta2.next())
                {
                    ingreso+=consulta2.value(0).toDouble();
                }
                consulta2.exec("select dia_"+tr("%1").arg(j)+" from saldo_acum_conceptos where cod_contable='"+consulta.value(1).toString()+"' and prog_academico='"+academico+"'");
                while(consulta2.next())
                {
                    descuento+=consulta2.value(0).toDouble();
                }
            }
            i++;
            item = new QStandardItem();
            item->setData(consulta.value(2).toString(),Qt::EditRole );
            model->setItem(i,0,item);
            item = new QStandardItem();
            item->setData(tr("%1").arg(ingreso),Qt::EditRole );
            model->setItem(i,1,item);
            i++;
            item = new QStandardItem();
            item->setData("DESCUENTO "+consulta.value(2).toString(),Qt::EditRole );
            model->setItem(i,0,item);
            item = new QStandardItem();
            item->setData(tr("%1").arg(descuento),Qt::EditRole );
            model->setItem(i,1,item);  
        }

        /*consulta.exec("select cod_contable from codigo_concepto where tipo in (select abrev from tipo_material where cfp='S')");
        while(consulta.next())
        {
            ingreso=0;
            for(j=1;j<32;j++)
            {
                consulta2.exec("select dia_"+tr("%1").arg(i)+" from saldo_acum_conceptos where cod_contable='"+consulta.value(0).toString()+"' and prog_academico='"+academico+"'");
                while(consulta2.next())
                {
                    ingreso+=consulta2.value(0).toDouble();
                }
            }
            item = new QStandardItem();
            item->setData(consulta.value(2).toString(),Qt::EditRole );
            model->setItem(i,0,item);
            item = new QStandardItem();
            item->setData(tr("%1").arg(ingreso),Qt::EditRole );
            model->setItem(i,1,item);
            i++;
        }*/
        report->addItemModel(model,"model");
        report->setReportFile("reportes/cedula_ingresoscfp.xml");
    }
    else
    {
        QStandardItemModel *model = new QStandardItemModel(0,33);
        for(i=0;i<31;i++)
        {
            model->insertRow(i);
            item = new QStandardItem();
            item->setData(tr("%1-%2-%3").arg(i+1).arg(QDate::currentDate().month()).arg(QDate::currentDate().year()),Qt::EditRole );
            model->setItem(i,0,item);
            j=2;
            total_dia=0;
            //EL ORDEN NO CONCUERDA CON LOS TITULOS
            consulta.exec("select dia_"+tr("%1").arg(i+1)+" from saldo_acum_conceptos where prog_academico='"+academico+"' order by cod_contable");
            while(consulta.next())
            {
                item = new QStandardItem();
                item->setData(consulta.value(0).toString(),Qt::EditRole );
                model->setItem(i,j,item);
                total_dia+=consulta.value(0).toDouble();
                j++;
            }
            item = new QStandardItem();
            item->setData(tr("%1").arg(total_dia),Qt::EditRole );
            model->setItem(i,j,item);
        }
        report->addItemModel(model,"model");
        report->setReportFile("reportes/cedula_ingresos.xml");
    }

    /*for(i=1;i<=31;i++)
    {
        depositos=0;
        consulta.exec("select "+tr("dia_%1").arg(i)+" from saldo_acum_bancos where prog_academico='"+academico+"'");
        while(consulta.next())
        {
            depositos+=consulta.value(0).toDouble();
        }

        item = new QStandardItem();
        item->setData(tr("%1/%2/%3").arg(i).arg(mes).arg(anio),Qt::EditRole );
        model->setItem(i-1,0,item);
        item = new QStandardItem();
        item->setData(depositos,Qt::EditRole);
        model->setItem(i-1,1,item);
        total_dia=0;
        j=2;
        consulta.exec("select "+tr("dia_%1").arg(i)+" from saldo_acum_conceptos where prog_academico='"+academico+"'");
        while(consulta.next())
        {
            item = new QStandardItem();
            item->setData(consulta.value(0).toString(),Qt::EditRole);
            model->setItem(i-1,j,item);
            j++;
            total_dia+=consulta.value(0).toDouble();
        }
        item = new QStandardItem();
        item->setData(total_dia,Qt::EditRole);
        model->setItem(i-1,16,item);
    }*/

    report->runReportToPDF("test.pdf");
    if (!report->hasError())
    {
        if(ced_dialog.salida->currentIndex()==1)
            ShellExecuteA(NULL,"print",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        else
            ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
    }
    else
        QMessageBox::information(0,"Error",report->lastErrorMsg());

    dialogo->close();
}


/**
 *
 */

void procesos_caja::anularFactura()
{
    int row= reg_factura.r_tabla->currentRow();
    if(row>=0)
    {
        QString factura = reg_factura.r_tabla->item(row,0)->text();
        QSqlQuery consulta,consulta2,consulta3,consulta4;
        QString matricula,evento;

        consulta.exec("select cedula_est,fecha_emi,prog_academico from factura where id_fact='"+factura+"'");
        while(consulta.next())
        {
            consulta2.exec("select matricula from estudiante where cedula_est='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                matricula=consulta2.value(0).toString();
            }
            if(consulta.value(2).toString()=="3")
            {
                consulta2.exec("select id_evento from ficha_pago_cfp where id_fact='"+factura+"' and matricula='"+matricula+"'");
                while(consulta2.next())
                {
                    if(consulta2.value(0).toString()=="2")
                    {
                        int actual;
                        consulta3.exec("select id_seccion from ficha_academica where id_evento='"+consulta2.value(0).toString()+"' and matricula='"+matricula+"' and fecha='"+consulta.value(1).toString()+"'");
                        while(consulta3.next())
                        {
                            consulta4.exec("select cant_actual from cohortes where id='"+consulta3.value(0).toString()+"'");
                            while(consulta4.next())
                            {
                                actual=consulta4.value(0).toInt()-1;
                            }
                            consulta4.exec("update cohortes set cant_actual='"+tr("%1").arg(actual)+"' where id='"+consulta3.value(0).toString()+"'");
                            consulta4.exec("commit");
                        }
                    }
                    evento=consulta2.value(0).toString();
                }
                consulta.exec("delete ficha_pago_cfp where id_fact='"+factura+"' and matricula='"+matricula+"'");
                consulta2.exec("commit");
            }
            else
            {
                consulta2.exec("select id_evento from ficha_pago where id_fact='"+factura+"' and matricula='"+matricula+"'");
                while(consulta2.next())
                {
                    if(consulta2.value(0).toString()=="2")
                    {
                        int actual;
                        consulta3.exec("select id_seccion,id_curso from ficha_academica where id_evento='"+consulta2.value(0).toString()+"' and matricula='"+matricula+"' and fecha='"+consulta.value(1).toString()+"'");
                        while(consulta3.next())
                        {
                            consulta4.exec("select cant_actual from secciones where id_curso='"+consulta3.value(1).toString()+"' and id_seccion='"+consulta3.value(0).toString()+"'");
                            while(consulta4.next())
                            {
                                actual=consulta4.value(0).toInt()-1;
                            }
                            if(!consulta4.exec("update secciones set cant_actual='"+tr("%1").arg(actual)+"' where id_curso='"+consulta3.value(1).toString()+"' and id_seccion='"+consulta3.value(0).toString()+"'"))
                                QMessageBox::critical(0,"Error Update Seccion",consulta.lastError().text());
                            else
                                consulta.exec("commit");
                        }
                    }
                    evento=consulta2.value(0).toString();
                }
                consulta.exec("delete ficha_pago where id_fact='"+factura+"' and matricula='"+matricula+"'");
                consulta2.exec("commit");
            }
            consulta2.exec("delete ficha_academica where id_evento='"+evento+"' and matricula='"+matricula+"' and fecha='"+consulta.value(1).toString()+"'");
            consulta2.exec("commit");
        }
        consulta.exec("select referencia from factura_deposito where id_fact='"+factura+"'");
        while(consulta.next())
        {
            consulta2.exec("delete from documentos_trf where dc_numero='"+consulta.value(0).toString()+"'");
            consulta2.exec("delete from deposito where referencia='"+consulta.value(0).toString()+"'");
            consulta2.exec("commit");
        }
        consulta.exec("delete from cuentas_por_cobrar where id_fact='"+factura+"'");
        consulta.exec("delete from factura_deposito where id_fact='"+factura+"'");
        consulta.exec("update factura set status='A' where id_fact='"+factura+"'");
        consulta.exec("commit");
        reg_factura.r_tabla->removeRow(row);
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


/**
 *
 */

void procesos_caja::quitarItem()
{
    float precio,iva,total;
    QString tiva,ttotal,subtotal;
    int row= factura.f_tabla->currentRow();

    if(row>=0)
    {
        QString item = factura.f_tabla->item(row,1)->text();

        precio=factura.f_tabla->item(row,4)->text().toFloat();
        if(factura.f_subtotal_2->text().toDouble()>0)
        {
            subtotal.setNum(factura.f_subtotal_2->text().toDouble()-precio,'g',10);
            if(!subtotal.contains(".",Qt::CaseInsensitive)&&!subtotal.contains(",",Qt::CaseInsensitive))
                subtotal= subtotal+".00";
            factura.f_subtotal_2->setText(subtotal);
        }
        iva = (factura.f_subtotal_2->text().toFloat()*factura.f_iva_2->text().toFloat())/100;
        total = factura.f_subtotal_2->text().toFloat() + iva;
        tiva.setNum(iva,'g',10);
        if(!tiva.contains(".",Qt::CaseInsensitive)&&!tiva.contains(",",Qt::CaseInsensitive))
            tiva= tiva+".00";
        ttotal.setNum(total,'g',10);
        if(!ttotal.contains(".",Qt::CaseInsensitive)&&!ttotal.contains(",",Qt::CaseInsensitive))
            ttotal= ttotal+".00";
        factura.f_iva_2->setText(tiva);
        factura.f_total_2->setText(ttotal);
        factura.f_tabla->removeRow(row);
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un item");
}


void procesos_caja::quitarItem2()
{
    int row= factura.f_tabla0->currentRow();

    if(row>=0)
        factura.f_tabla0->removeRow(row);
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un item");
}


void procesos_caja::registroBancos()
{
    frame = new QFrame();
    reg_bancos.setupUi(frame);
    container.workspace->setWidget(frame);

    disconnect(container.botonNuevo,SIGNAL(clicked()),0,0);
    disconnect(container.botonAnular,SIGNAL(clicked()),0,0);
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoBanco()));
    container.botonNuevo->setEnabled(true);
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarBanco()));
    container.botonAnular->setEnabled(true);
    connect(reg_bancos.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarBanco(int,int)));

    reg_bancos.tabla->setColumnWidth(0,50);
    reg_bancos.tabla->setColumnWidth(1,200);
    reg_bancos.tabla->setColumnWidth(2,50);
    reg_bancos.tabla->setColumnWidth(3,50);
    reg_bancos.tabla->setColumnWidth(4,50);
    reg_bancos.tabla->setColumnWidth(5,100);

    llenarBancos();
}

void procesos_caja::llenarBancos()
{
    QSqlQuery consulta;
    QTableWidgetItem *ni;
    int row;

    consulta.exec("select * from bancos order by id_banco");
    while(consulta.next())
    {
        row = reg_bancos.tabla->rowCount();
        reg_bancos.tabla->insertRow(row);
        ni = new QTableWidgetItem(consulta.value(0).toString());
        reg_bancos.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(consulta.value(1).toString());
        reg_bancos.tabla->setItem(row,1,ni);
        ni = new QTableWidgetItem(consulta.value(3).toString());
        reg_bancos.tabla->setItem(row,2,ni);
        ni = new QTableWidgetItem(consulta.value(4).toString());
        reg_bancos.tabla->setItem(row,3,ni);
        ni = new QTableWidgetItem(consulta.value(5).toString());
        reg_bancos.tabla->setItem(row,4,ni);
        ni = new QTableWidgetItem(consulta.value(6).toString());
        reg_bancos.tabla->setItem(row,5,ni);
    }
}


void procesos_caja::nuevoBanco()
{
    QComboBox *aux;
    int row = reg_bancos.tabla->rowCount();
    reg_bancos.tabla->insertRow(row);

    lines = new QList<QLineEdit*>();
    combos = new QList<QComboBox*>();

    lines->append(new QLineEdit());
    reg_bancos.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit());
    reg_bancos.tabla->setCellWidget(row,1,lines->last());
    aux=new QComboBox();
    aux->addItem("S");
    aux->addItem("N");
    combos->append(aux);
    reg_bancos.tabla->setCellWidget(row,2,combos->last());
    aux=new QComboBox();
    aux->addItem("S");
    aux->addItem("N");
    combos->append(aux);
    reg_bancos.tabla->setCellWidget(row,3,combos->last());
    aux=new QComboBox();
    aux->addItem("S");
    aux->addItem("N");
    combos->append(aux);
    reg_bancos.tabla->setCellWidget(row,4,combos->last());
    lines->append(new QLineEdit());
    reg_bancos.tabla->setCellWidget(row,5,lines->last());

    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarBanco()));
    container.botonGuardar->setEnabled(true);
    connect(reg_bancos.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_caja::editarBanco(int row,int column)
{
    QComboBox *aux;

    lines = new QList<QLineEdit*>();
    combos = new QList<QComboBox*>();
    updating=reg_bancos.tabla->item(row,0)->text();

    lines->append(new QLineEdit(reg_bancos.tabla->item(row,0)->text()));
    reg_bancos.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit(reg_bancos.tabla->item(row,1)->text()));
    reg_bancos.tabla->setCellWidget(row,1,lines->last());
    aux=new QComboBox();
    aux->addItem("S");
    aux->addItem("N");
    aux->setCurrentIndex(aux->findText(reg_bancos.tabla->item(row,2)->text()));
    combos->append(aux);
    reg_bancos.tabla->setCellWidget(row,2,combos->last());
    aux=new QComboBox();
    aux->addItem("S");
    aux->addItem("N");
    aux->setCurrentIndex(aux->findText(reg_bancos.tabla->item(row,3)->text()));
    combos->append(aux);
    reg_bancos.tabla->setCellWidget(row,3,combos->last());
    aux=new QComboBox();
    aux->addItem("S");
    aux->addItem("N");
    aux->setCurrentIndex(aux->findText(reg_bancos.tabla->item(row,4)->text()));
    combos->append(aux);
    reg_bancos.tabla->setCellWidget(row,4,combos->last());
    lines->append(new QLineEdit(reg_bancos.tabla->item(row,5)->text()));
    reg_bancos.tabla->setCellWidget(row,5,lines->last());

    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarBanco()));
    container.botonGuardar->setEnabled(true);
    connect(reg_bancos.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_caja::guardarBanco()
{
    QSqlQuery consulta;

    if(!consulta.exec("insert into bancos values ('"+lines->at(0)->text()+"','"+lines->at(1)->text()+"','','"+combos->at(0)->currentText()+"','"+combos->at(1)->currentText()+"','"+combos->at(2)->currentText()+"','"+lines->at(2)->text()+"')"))
        QMessageBox::critical(0,"Error Guardar Banco",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        llenarBancos();
        container.botonGuardar->setEnabled(false);
    }

}


void procesos_caja::actualizarBanco()
{
    QSqlQuery consulta;

    if(!consulta.exec("update bancos set id_banco='"+lines->at(0)->text()+"',nombre= '"+lines->at(1)->text()+"',debito='"+combos->at(0)->currentText()+"',deposito='"+combos->at(1)->currentText()+"',credito='"+combos->at(2)->currentText()+"',ctabco='"+lines->at(2)->text()+"' where id_banco='"+updating+"'"))
        QMessageBox::critical(0,"Error Actualizar Banco",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        llenarBancos();
        container.botonGuardar->setEnabled(false);
    }
}


void procesos_caja::registroEmpresas()
{
    frame = new QFrame();
    reg_empresas.setupUi(frame);
    container.workspace->setWidget(frame);

    reg_empresas.tabla->setColumnWidth(0,100);
    reg_empresas.tabla->setColumnWidth(1,300);
    reg_empresas.tabla->setColumnWidth(2,500);
    reg_empresas.tabla->setColumnWidth(3,100);
    llenarEmpresas();
}


void procesos_caja::llenarEmpresas()
{
    QSqlQuery consulta;
    QTableWidgetItem *ni;
    int row,i;

    for(i=reg_empresas.tabla->rowCount()-1;i>=0;i--)
        reg_empresas.tabla->removeRow(i);

    consulta.exec("select * from empresas order by razon");
    while(consulta.next())
    {
        row=reg_empresas.tabla->rowCount();
        reg_empresas.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_empresas.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_empresas.tabla->setItem(row,1,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        reg_empresas.tabla->setItem(row,2,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        reg_empresas.tabla->setItem(row,3,ni);
    }
    connect(reg_empresas.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarEmpresa(int,int)));
}


void procesos_caja::editarEmpresa(int row, int column)
{
    updating= reg_empresas.tabla->item(row,0)->text();
    //llenarCerti();
    lines = new QList<QLineEdit*>();

    lines->append(new QLineEdit(reg_empresas.tabla->item(row,0)->text()));
    reg_empresas.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit(reg_empresas.tabla->item(row,1)->text()));
    reg_empresas.tabla->setCellWidget(row,1,lines->last());
    lines->append(new QLineEdit(reg_empresas.tabla->item(row,2)->text()));
    reg_empresas.tabla->setCellWidget(row,2,lines->last());
    lines->append(new QLineEdit(reg_empresas.tabla->item(row,3)->text()));
    reg_empresas.tabla->setCellWidget(row,3,lines->last());

    connect(reg_empresas.tabla->cellWidget(row,3),SIGNAL(returnPressed()),this,SLOT(actualizarEmpresa()));
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarEmpresa()));
    container.botonGuardar->setEnabled(true);

    connect(reg_empresas.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_empresas.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_empresas.tabla->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_caja::actualizarEmpresa()
{
    QSqlQuery consulta;

    if(!consulta.exec("update empresas set rif='"+lines->at(0)->text()+"',razon='"+lines->at(1)->text()+"',direccion='"+lines->at(2)->text()+"',telefono='"+lines->at(3)->text()+"' where rif='"+updating+"'"))
        QMessageBox::critical(0,"Error",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        llenarEmpresas();
    }
}


void procesos_caja::registroPrecios()
{
    frame = new QFrame();
    reg_precios.setupUi(frame);
    container.workspace->setWidget(frame);

    connect(reg_precios.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarPrecio(int,int)));
    connect(reg_precios.p_arancel,SIGNAL(stateChanged(int)),this,SLOT(arancelChecked(int)));
    connect(reg_precios.p_curso,SIGNAL(stateChanged(int)),this,SLOT(cursoChecked(int)));
    connect(reg_precios.p_libro,SIGNAL(stateChanged(int)),this,SLOT(libroChecked(int)));
    connect(reg_precios.p_guia,SIGNAL(stateChanged(int)),this,SLOT(guiaChecked(int)));
    connect(reg_precios.p_cd,SIGNAL(stateChanged(int)),this,SLOT(cdChecked(int)));
    connect(reg_precios.p_examen,SIGNAL(stateChanged(int)),this,SLOT(examenChecked(int)));
    connect(reg_precios.p_matricula,SIGNAL(stateChanged(int)),this,SLOT(matriculaChecked(int)));
    connect(reg_precios.p_otro,SIGNAL(stateChanged(int)),this,SLOT(otroChecked(int)));
    connect(reg_precios.p_descuento,SIGNAL(stateChanged(int)),this,SLOT(descuentoChecked(int)));
    connect(reg_precios.p_constancia,SIGNAL(stateChanged(int)),this,SLOT(constanciaChecked(int)));
    connect(reg_precios.p_boleta,SIGNAL(stateChanged(int)),this,SLOT(boletaChecked(int)));
    connect(reg_precios.p_factura,SIGNAL(stateChanged(int)),this,SLOT(facturaChecked(int)));
    //connect(reg_precios.tabla,SIGNAL(itemChanged(QTableWidgetItem)),this,SLOT(actualizarPrecio(QTableWidgetItem)));
    reg_precios.tabla->setColumnWidth(0,80);
    reg_precios.tabla->setColumnWidth(1,300);
    reg_precios.tabla->setColumnWidth(2,80);
    reg_precios.tabla->setColumnWidth(3,80);
    reg_precios.tabla->setColumnWidth(4,100);
}


void procesos_caja::actualizarPrecio()
{
    QSqlQuery consulta;

    if(reg_precios.p_curso->isChecked())
    {
        if(consulta.exec("update precios set precio1='"+lines->at(0)->text()+"',precio2='"+lines->at(1)->text()+"',precio3='"+lines->at(2)->text()+"' where item='"+updating+"'"))
        {
            consulta.exec("commit");
            cursoChecked(2);
            container.botonGuardar->setEnabled(false);
        }
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
    else
    {
        if(consulta.exec("update precios set precio1='"+lines->at(0)->text()+"' where item='"+updating+"'"))
        {
            container.botonGuardar->setEnabled(false);
            consulta.exec("commit");
            if(reg_precios.p_libro->isChecked())
                libroChecked(2);
            else if(reg_precios.p_guia->isChecked())
                guiaChecked(2);
            else if(reg_precios.p_otro->isChecked())
                otroChecked(2);
            else if(reg_precios.p_cd->isChecked())
                cdChecked(2);
            else if(reg_precios.p_descuento->isChecked())
                descuentoChecked(2);
            else if(reg_precios.p_examen->isChecked())
                examenChecked(2);
            else if(reg_precios.p_matricula->isChecked())
                matriculaChecked(2);
            else if(reg_precios.p_arancel->isChecked())
                arancelChecked(2);
            else if(reg_precios.p_constancia->isChecked())
                constanciaChecked(2);
            else if(reg_precios.p_boleta->isChecked())
                boletaChecked(2);
            else if(reg_precios.p_factura->isChecked())
                facturaChecked(2);
        }
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
}


void procesos_caja::editarPrecio(int row,int column)
{
    updating = reg_precios.tabla->item(row,0)->text();
    lines = new QList<QLineEdit*>();

    if(reg_precios.p_curso->isChecked())
        cursoChecked(2);
    else if(reg_precios.p_libro->isChecked())
        libroChecked(2);
    else if(reg_precios.p_guia->isChecked())
        guiaChecked(2);
    else if(reg_precios.p_otro->isChecked())
        otroChecked(2);
    else if(reg_precios.p_cd->isChecked())
        cdChecked(2);
    else if(reg_precios.p_descuento->isChecked())
        descuentoChecked(2);
    else if(reg_precios.p_examen->isChecked())
        examenChecked(2);
    else if(reg_precios.p_matricula->isChecked())
        matriculaChecked(2);
    else if(reg_precios.p_arancel->isChecked())
        arancelChecked(2);
    else if(reg_precios.p_constancia->isChecked())
        constanciaChecked(2);
    else if(reg_precios.p_boleta->isChecked())
        boletaChecked(2);
    else if(reg_precios.p_factura->isChecked())
        facturaChecked(2);

    lines->append(new QLineEdit(reg_precios.tabla->item(row,2)->text()));
    reg_precios.tabla->setCellWidget(row,2,lines->last());
    if(reg_precios.p_curso->isChecked())
    {
        lines->append(new QLineEdit(reg_precios.tabla->item(row,3)->text()));
        reg_precios.tabla->setCellWidget(row,3,lines->last());
        lines->append(new QLineEdit(reg_precios.tabla->item(row,4)->text()));
        reg_precios.tabla->setCellWidget(row,4,lines->last());
    }
    connect(reg_precios.tabla->cellWidget(row,2),SIGNAL(returnPressed()),this,SLOT(actualizarPrecio()));
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarPrecio()));
    container.botonGuardar->setEnabled(true);
}


void procesos_caja::cursoChecked(int state)
{
    QSqlQuery consulta,consulta2;
    QTableWidgetItem *ni;
    int row,i;

    row=reg_precios.tabla->rowCount();
    for(i=row-1;i>=0;i--)
    {
        reg_precios.tabla->removeRow(i);
    }
    if(state==2)
    {
        reg_precios.p_guia->setChecked(false);
        reg_precios.p_cd->setChecked(false);
        reg_precios.p_descuento->setChecked(false);
        reg_precios.p_examen->setChecked(false);
        reg_precios.p_matricula->setChecked(false);
        reg_precios.p_libro->setChecked(false);
        reg_precios.p_otro->setChecked(false);
        reg_precios.p_arancel->setChecked(false);

        reg_precios.p_constancia->setChecked(false);
        reg_precios.p_boleta->setChecked(false);
        reg_precios.p_factura->setChecked(false);

        consulta.exec("select item,fecha,precio1,precio2,precio3 from precios where tipo_item='C'");
        while(consulta.next())
        {
            row = reg_precios.tabla->rowCount();
            reg_precios.tabla->insertRow(row);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
            reg_precios.tabla->setItem(row,0,ni);
            consulta2.exec("select descripcion from metodos where id_metodo='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
                reg_precios.tabla->setItem(row,1,ni);
            }
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
            reg_precios.tabla->setItem(row,2,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
            reg_precios.tabla->setItem(row,3,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(4).toString()));
            reg_precios.tabla->setItem(row,4,ni);
        }
    }
}


void procesos_caja::libroChecked(int state)
{
    QSqlQuery consulta,consulta2;
    QTableWidgetItem *ni;
    int row,i;

    row=reg_precios.tabla->rowCount();
    for(i=row-1;i>=0;i--)
    {
        reg_precios.tabla->removeRow(i);
    }
    if(state==2)
    {
        reg_precios.p_curso->setChecked(false);
        reg_precios.p_guia->setChecked(false);
        reg_precios.p_cd->setChecked(false);
        reg_precios.p_descuento->setChecked(false);
        reg_precios.p_examen->setChecked(false);
        reg_precios.p_matricula->setChecked(false);
        reg_precios.p_otro->setChecked(false);
        reg_precios.p_arancel->setChecked(false);
        reg_precios.p_constancia->setChecked(false);
        reg_precios.p_boleta->setChecked(false);
        reg_precios.p_factura->setChecked(false);

        consulta.exec("select item,fecha,precio1 from precios where tipo_item='L'");
        while(consulta.next())
        {
            row = reg_precios.tabla->rowCount();
            reg_precios.tabla->insertRow(row);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
            reg_precios.tabla->setItem(row,0,ni);
            consulta2.exec("select descripcion from materiales where id_mat='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
                reg_precios.tabla->setItem(row,1,ni);
            }
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
            reg_precios.tabla->setItem(row,2,ni);
        }
    }
}


void procesos_caja::guiaChecked(int state)
{
        QSqlQuery consulta,consulta2;
        QTableWidgetItem *ni;
        int row,i;

        row=reg_precios.tabla->rowCount();
        for(i=row-1;i>=0;i--)
        {
                reg_precios.tabla->removeRow(i);
        }
        if(state==2)
        {
                reg_precios.p_cd->setChecked(false);
                reg_precios.p_descuento->setChecked(false);
                reg_precios.p_examen->setChecked(false);
                reg_precios.p_matricula->setChecked(false);
                reg_precios.p_curso->setChecked(false);
                reg_precios.p_libro->setChecked(false);
                reg_precios.p_otro->setChecked(false);
                reg_precios.p_arancel->setChecked(false);
                reg_precios.p_constancia->setChecked(false);
                reg_precios.p_boleta->setChecked(false);
                reg_precios.p_factura->setChecked(false);

                consulta.exec("select item,fecha,precio1 from precios where tipo_item='G'");
                while(consulta.next())
                {
                        row = reg_precios.tabla->rowCount();
                        reg_precios.tabla->insertRow(row);
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
                        reg_precios.tabla->setItem(row,0,ni);
                        consulta2.exec("select descripcion from materiales where id_mat='"+consulta.value(0).toString()+"'");
                        while(consulta2.next())
                        {
                                ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
                                reg_precios.tabla->setItem(row,1,ni);
                        }
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
                        reg_precios.tabla->setItem(row,2,ni);
                }
        }
}


void procesos_caja::cdChecked(int state)
{
        QSqlQuery consulta,consulta2;
        QTableWidgetItem *ni;
        int row,i;

        row=reg_precios.tabla->rowCount();
        for(i=row-1;i>=0;i--)
        {
                reg_precios.tabla->removeRow(i);
        }
        if(state==2)
        {
                reg_precios.p_curso->setChecked(false);
                reg_precios.p_libro->setChecked(false);
                reg_precios.p_otro->setChecked(false);
                reg_precios.p_guia->setChecked(false);
                reg_precios.p_descuento->setChecked(false);
                reg_precios.p_examen->setChecked(false);
                reg_precios.p_matricula->setChecked(false);
                reg_precios.p_arancel->setChecked(false);
                reg_precios.p_constancia->setChecked(false);
                reg_precios.p_boleta->setChecked(false);
                reg_precios.p_factura->setChecked(false);

                consulta.exec("select item,fecha,precio1 from precios where tipo_item='CD'");
                while(consulta.next())
                {
                        row = reg_precios.tabla->rowCount();
                        reg_precios.tabla->insertRow(row);
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
                        reg_precios.tabla->setItem(row,0,ni);
                        consulta2.exec("select descripcion from materiales where id_mat='"+consulta.value(0).toString()+"'");
                        while(consulta2.next())
                        {
                                ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
                                reg_precios.tabla->setItem(row,1,ni);
                        }
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
                        reg_precios.tabla->setItem(row,2,ni);
                }
        }
}


void procesos_caja::descuentoChecked(int state)
{
        QSqlQuery consulta,consulta2;
        QTableWidgetItem *ni;
        int row,i;

        row=reg_precios.tabla->rowCount();
        for(i=row-1;i>=0;i--)
        {
                reg_precios.tabla->removeRow(i);
        }
        if(state==2)
        {
                reg_precios.p_curso->setChecked(false);
                reg_precios.p_libro->setChecked(false);
                reg_precios.p_guia->setChecked(false);
                reg_precios.p_cd->setChecked(false);
                reg_precios.p_examen->setChecked(false);
                reg_precios.p_matricula->setChecked(false);
                reg_precios.p_otro->setChecked(false);
                reg_precios.p_arancel->setChecked(false);
                reg_precios.p_constancia->setChecked(false);
                reg_precios.p_boleta->setChecked(false);
                reg_precios.p_factura->setChecked(false);

                consulta.exec("select item,fecha,precio1 from precios where tipo_item='D'");
                while(consulta.next())
                {
                        row = reg_precios.tabla->rowCount();
                        reg_precios.tabla->insertRow(row);
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
                        reg_precios.tabla->setItem(row,0,ni);
                        consulta2.exec("select descripcion from materiales where id_mat='"+consulta.value(0).toString()+"'");
                        while(consulta2.next())
                        {
                                ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
                                reg_precios.tabla->setItem(row,1,ni);
                        }
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
                        reg_precios.tabla->setItem(row,2,ni);
                }
        }
}


void procesos_caja::examenChecked(int state)
{
        QSqlQuery consulta,consulta2;
        QTableWidgetItem *ni;
        int row,i;

        row=reg_precios.tabla->rowCount();
        for(i=row-1;i>=0;i--)
        {
                reg_precios.tabla->removeRow(i);
        }
        if(state==2)
        {
                reg_precios.p_curso->setChecked(false);
                reg_precios.p_libro->setChecked(false);
                reg_precios.p_otro->setChecked(false);
                reg_precios.p_guia->setChecked(false);
                reg_precios.p_cd->setChecked(false);
                reg_precios.p_descuento->setChecked(false);
                reg_precios.p_matricula->setChecked(false);
                reg_precios.p_arancel->setChecked(false);
                reg_precios.p_constancia->setChecked(false);
                reg_precios.p_boleta->setChecked(false);
                reg_precios.p_factura->setChecked(false);

                consulta.exec("select item,fecha,precio1 from precios where tipo_item='E'");
                while(consulta.next())
                {
                        row = reg_precios.tabla->rowCount();
                        reg_precios.tabla->insertRow(row);
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
                        reg_precios.tabla->setItem(row,0,ni);
                        consulta2.exec("select descripcion from materiales where id_mat='"+consulta.value(0).toString()+"'");
                        while(consulta2.next())
                        {
                                ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
                                reg_precios.tabla->setItem(row,1,ni);
                        }
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
                        reg_precios.tabla->setItem(row,2,ni);
                }
        }
}


void procesos_caja::matriculaChecked(int state)
{
        QSqlQuery consulta,consulta2;
        QTableWidgetItem *ni;
        int row,i;

        row=reg_precios.tabla->rowCount();
        for(i=row-1;i>=0;i--)
        {
                reg_precios.tabla->removeRow(i);
        }
        if(state==2)
        {
                reg_precios.p_curso->setChecked(false);
                reg_precios.p_libro->setChecked(false);
                reg_precios.p_otro->setChecked(false);
                reg_precios.p_guia->setChecked(false);
                reg_precios.p_cd->setChecked(false);
                reg_precios.p_descuento->setChecked(false);
                reg_precios.p_examen->setChecked(false);
                reg_precios.p_arancel->setChecked(false);
                reg_precios.p_constancia->setChecked(false);
                reg_precios.p_boleta->setChecked(false);
                reg_precios.p_factura->setChecked(false);

                consulta.exec("select item,fecha,precio1 from precios where tipo_item='M'");
                while(consulta.next())
                {
                        row = reg_precios.tabla->rowCount();
                        reg_precios.tabla->insertRow(row);
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
                        reg_precios.tabla->setItem(row,0,ni);
                        consulta2.exec("select descripcion from materiales where id_mat='"+consulta.value(0).toString()+"'");
                        while(consulta2.next())
                        {
                                ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
                                reg_precios.tabla->setItem(row,1,ni);
                        }
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
                        reg_precios.tabla->setItem(row,2,ni);
                }
        }
}


void procesos_caja::arancelChecked(int state)
{
        QSqlQuery consulta,consulta2;
        QTableWidgetItem *ni;
        int row,i;

        row=reg_precios.tabla->rowCount();
        for(i=row-1;i>=0;i--)
        {
                reg_precios.tabla->removeRow(i);
        }
        if(state==2)
        {
                reg_precios.p_curso->setChecked(false);
                reg_precios.p_libro->setChecked(false);
                reg_precios.p_guia->setChecked(false);
                reg_precios.p_cd->setChecked(false);
                reg_precios.p_descuento->setChecked(false);
                reg_precios.p_examen->setChecked(false);
                reg_precios.p_matricula->setChecked(false);
                reg_precios.p_otro->setChecked(false);
                reg_precios.p_constancia->setChecked(false);
                reg_precios.p_boleta->setChecked(false);
                reg_precios.p_factura->setChecked(false);

                consulta.exec("select item,fecha,precio1 from precios where tipo_item='A'");
                while(consulta.next())
                {
                        row = reg_precios.tabla->rowCount();
                        reg_precios.tabla->insertRow(row);
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
                        reg_precios.tabla->setItem(row,0,ni);
                        consulta2.exec("select descripcion from materiales where id_mat='"+consulta.value(0).toString()+"'");
                        while(consulta2.next())
                        {
                                ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
                                reg_precios.tabla->setItem(row,1,ni);
                        }
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
                        reg_precios.tabla->setItem(row,2,ni);
                }
        }
}


void procesos_caja::constanciaChecked(int state)
{
        QSqlQuery consulta,consulta2;
        QTableWidgetItem *ni;
        int row,i;

        row=reg_precios.tabla->rowCount();
        for(i=row-1;i>=0;i--)
        {
                reg_precios.tabla->removeRow(i);
        }
        if(state==2)
        {
                reg_precios.p_curso->setChecked(false);
                reg_precios.p_libro->setChecked(false);
                reg_precios.p_guia->setChecked(false);
                reg_precios.p_cd->setChecked(false);
                reg_precios.p_descuento->setChecked(false);
                reg_precios.p_examen->setChecked(false);
                reg_precios.p_matricula->setChecked(false);
                reg_precios.p_otro->setChecked(false);
                reg_precios.p_arancel->setChecked(false);
                reg_precios.p_boleta->setChecked(false);
                reg_precios.p_factura->setChecked(false);

                consulta.exec("select item,fecha,precio1 from precios where tipo_item='CO'");
                while(consulta.next())
                {
                        row = reg_precios.tabla->rowCount();
                        reg_precios.tabla->insertRow(row);
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
                        reg_precios.tabla->setItem(row,0,ni);
                        consulta2.exec("select descripcion from materiales where id_mat='"+consulta.value(0).toString()+"'");
                        while(consulta2.next())
                        {
                                ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
                                reg_precios.tabla->setItem(row,1,ni);
                        }
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
                        reg_precios.tabla->setItem(row,2,ni);
                }
        }
}


void procesos_caja::boletaChecked(int state)
{
        QSqlQuery consulta,consulta2;
        QTableWidgetItem *ni;
        int row,i;

        row=reg_precios.tabla->rowCount();
        for(i=row-1;i>=0;i--)
        {
                reg_precios.tabla->removeRow(i);
        }
        if(state==2)
        {
                reg_precios.p_curso->setChecked(false);
                reg_precios.p_libro->setChecked(false);
                reg_precios.p_guia->setChecked(false);
                reg_precios.p_cd->setChecked(false);
                reg_precios.p_descuento->setChecked(false);
                reg_precios.p_examen->setChecked(false);
                reg_precios.p_matricula->setChecked(false);
                reg_precios.p_otro->setChecked(false);
                reg_precios.p_arancel->setChecked(false);
                reg_precios.p_constancia->setChecked(false);
                reg_precios.p_factura->setChecked(false);

                consulta.exec("select item,fecha,precio1 from precios where tipo_item='B'");
                while(consulta.next())
                {
                        row = reg_precios.tabla->rowCount();
                        reg_precios.tabla->insertRow(row);
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
                        reg_precios.tabla->setItem(row,0,ni);
                        consulta2.exec("select descripcion from materiales where id_mat='"+consulta.value(0).toString()+"'");
                        while(consulta2.next())
                        {
                                ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
                                reg_precios.tabla->setItem(row,1,ni);
                        }
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
                        reg_precios.tabla->setItem(row,2,ni);
                }
        }
}

void procesos_caja::facturaChecked(int state)
{
        QSqlQuery consulta,consulta2;
        QTableWidgetItem *ni;
        int row,i;

        row=reg_precios.tabla->rowCount();
        for(i=row-1;i>=0;i--)
        {
                reg_precios.tabla->removeRow(i);
        }
        if(state==2)
        {
                reg_precios.p_curso->setChecked(false);
                reg_precios.p_libro->setChecked(false);
                reg_precios.p_guia->setChecked(false);
                reg_precios.p_cd->setChecked(false);
                reg_precios.p_descuento->setChecked(false);
                reg_precios.p_examen->setChecked(false);
                reg_precios.p_matricula->setChecked(false);
                reg_precios.p_otro->setChecked(false);
                reg_precios.p_arancel->setChecked(false);
                reg_precios.p_constancia->setChecked(false);
                reg_precios.p_boleta->setChecked(false);

                consulta.exec("select item,fecha,precio1 from precios where tipo_item='F'");
                while(consulta.next())
                {
                        row = reg_precios.tabla->rowCount();
                        reg_precios.tabla->insertRow(row);
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
                        reg_precios.tabla->setItem(row,0,ni);
                        consulta2.exec("select descripcion from materiales where id_mat='"+consulta.value(0).toString()+"'");
                        while(consulta2.next())
                        {
                                ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
                                reg_precios.tabla->setItem(row,1,ni);
                        }
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
                        reg_precios.tabla->setItem(row,2,ni);
                }
        }
}

void procesos_caja::otroChecked(int state)
{
        QSqlQuery consulta,consulta2;
        QTableWidgetItem *ni;
        int row,i;

        row=reg_precios.tabla->rowCount();
        for(i=row-1;i>=0;i--)
        {
                reg_precios.tabla->removeRow(i);
        }
        if(state==2)
        {
                reg_precios.p_curso->setChecked(false);
                reg_precios.p_libro->setChecked(false);
                reg_precios.p_guia->setChecked(false);
                reg_precios.p_cd->setChecked(false);
                reg_precios.p_descuento->setChecked(false);
                reg_precios.p_examen->setChecked(false);
                reg_precios.p_matricula->setChecked(false);
                reg_precios.p_arancel->setChecked(false);
                reg_precios.p_constancia->setChecked(false);
                reg_precios.p_boleta->setChecked(false);
                reg_precios.p_factura->setChecked(false);

                consulta.exec("select item,fecha,precio1 from precios where tipo_item='O' or tipo_item='R' or tipo_item='CT'");
                while(consulta.next())
                {
                        row = reg_precios.tabla->rowCount();
                        reg_precios.tabla->insertRow(row);
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
                        reg_precios.tabla->setItem(row,0,ni);
                        consulta2.exec("select descripcion from materiales where id_mat='"+consulta.value(0).toString()+"'");
                        while(consulta2.next())
                        {
                                ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
                                reg_precios.tabla->setItem(row,1,ni);
                        }
                        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
                        reg_precios.tabla->setItem(row,2,ni);
                }
        }
}


void procesos_caja::registroCodigos()
{
    frame = new QFrame();
    reg_codigo.setupUi(frame);
    container.workspace->setWidget(frame);

    disconnect(container.botonAnular,SIGNAL(clicked()),0,0);
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarCodigo()));
    container.botonAnular->setEnabled(true);
    reg_codigo.tabla->setColumnWidth(0,400);
    reg_codigo.tabla->setColumnWidth(1,150);
    reg_codigo.tabla->setColumnWidth(2,150);

    reg_codigo.programa->addItem("IDIOMAS Y COMPUTACION");
    reg_codigo.programa->addItem("CAPACITACION Y FORMACION PROFESIONAL");
    connect(reg_codigo.programa,SIGNAL(currentIndexChanged(const QString)),this,SLOT(llenarCodigosContables(const QString)));
    llenarCodigosContables("");
}


void procesos_caja::llenarCodigosContables(QString s)
{
    QSqlQuery consulta,consulta2;
    int row,i;
    QTableWidgetItem *ni;
    QStringList sl;

    for(i=reg_codigo.tabla->rowCount()-1;i>=0;i--)
        reg_codigo.tabla->removeRow(i);

    if(reg_codigo.programa->currentIndex()==0)
    {
        sl <<"Concepto"<<"Codigo Contable"<<"Tipo Material";
        reg_codigo.tabla->setHorizontalHeaderLabels(sl);
        consulta.exec("select * from codigo_concepto");
        while(consulta.next())
        {
            row = reg_codigo.tabla->rowCount();
            reg_codigo.tabla->insertRow(row);
            ni = new QTableWidgetItem(consulta.value(1).toString());
            reg_codigo.tabla->setItem(row,0,ni);
            ni = new QTableWidgetItem(consulta.value(0).toString());
            reg_codigo.tabla->setItem(row,1,ni);
            ni = new QTableWidgetItem(consulta.value(2).toString());
            reg_codigo.tabla->setItem(row,2,ni);
        }
        disconnect(container.botonNuevo,SIGNAL(clicked()),0,0);
        connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoCodigoContable()));
        container.botonNuevo->setEnabled(true);
    }
    else
    {
        sl <<"Diplomado"<<"Codigo Contable"<<"Codigo Descuento";
        reg_codigo.tabla->setHorizontalHeaderLabels(sl);
        consulta.exec("select descripcion,cod_contable,cod_descuento from diplo_temp order by descripcion");
        while(consulta.next())
        {
            row = reg_codigo.tabla->rowCount();
            reg_codigo.tabla->insertRow(row);
            ni = new QTableWidgetItem(consulta.value(0).toString());
            reg_codigo.tabla->setItem(row,0,ni);
            ni = new QTableWidgetItem(consulta.value(1).toString());
            reg_codigo.tabla->setItem(row,1,ni);
            ni = new QTableWidgetItem(consulta.value(2).toString());
            reg_codigo.tabla->setItem(row,2,ni);
        }
        container.botonNuevo->setEnabled(false);
    }
    connect(reg_codigo.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarCodigoContable(int,int)));
}


void procesos_caja::guardarCodigo()//Redefinir para todos los programas_academicos
{
    QSqlQuery consulta;

    if(consulta.exec("insert into codigo_concepto values('"+lines->at(1)->text()+"','"+lines->at(0)->text()+"','"+lines->at(2)->text()+"')"))
    {
        consulta.exec("commit");
        llenarCodigosContables("");
        container.botonGuardar->setEnabled(false);
    }
    else
        QMessageBox::critical(0,"Error Guardar Codigo",consulta.lastError().text());

    //Saldos diarios por codigo contable - Idiomas Niños
    if(consulta.exec("insert into saldo_acum_conceptos values('"+lines->at(1)->text()+"','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0')"))
        consulta.exec("commit");
    else
        QMessageBox::critical(0,"Error Guardar Saldo Concepto",consulta.lastError().text());

    //Saldos diarios por codigo contable - Idiomas Modernos
    if(consulta.exec("insert into saldo_acum_conceptos values('"+lines->at(1)->text()+"','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','2','0')"))
        consulta.exec("commit");
    else
        QMessageBox::critical(0,"Error Guardar Saldo Concepto",consulta.lastError().text());
}


void procesos_caja::nuevoCodigoContable()
{
    QSqlQuery consulta;
    int row = reg_codigo.tabla->rowCount();
    reg_codigo.tabla->insertRow(row);

    lines = new QList<QLineEdit*>();
    lines->append(new QLineEdit());
    reg_codigo.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit());
    reg_codigo.tabla->setCellWidget(row,1,lines->last());
    lines->append(new QLineEdit());
    reg_codigo.tabla->setCellWidget(row,2,lines->last());

    connect(reg_codigo.tabla->cellWidget(row,2),SIGNAL(returnPressed()),this,SLOT(guardarCodigo()));
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarCodigo()));
    container.botonGuardar->setEnabled(true);
    connect(reg_codigo.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_codigo.tabla->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_caja::actualizarCodigoContable()
{
    QSqlQuery consulta;
    QString diplo;
    if(reg_codigo.programa->currentIndex()==0)
    {
        if(consulta.exec("update codigo_concepto set cod_contable='"+lines->at(1)->text()+"', concepto='"+lines->at(0)->text()+"',tipo='"+lines->at(2)->text()+"' where cod_contable='"+updating+"'"))
        {
            consulta.exec("commit");
            llenarCodigosContables("");
            container.botonGuardar->setEnabled(false);
        }
        else
            QMessageBox::critical(0,"Error Actualizar Codigo",consulta.lastError().text());
        if(consulta.exec("update saldo_acum_conceptos set cod_contable='"+lines->at(1)->text()+"' where cod_contable='"+updating+"'"))
            consulta.exec("commit");
        else
            QMessageBox::critical(0,"Error Actualizar Saldo Concepto",consulta.lastError().text());
    }
    else
    {
        bool found=false;
        consulta.exec("select id_diplomado from diplo_temp where descripcion='"+reg_codigo.tabla->item(updating.toInt(),0)->text()+"'");
        while(consulta.next())
        {
            diplo=consulta.value(0).toString();
        }
        if(consulta.exec("update diplo_temp set cod_contable='"+lines->at(0)->text()+"', cod_descuento='"+lines->at(1)->text()+"' where id_diplomado='"+diplo+"'"))
        {
            consulta.exec("commit");
            llenarCodigosContables("");
            container.botonGuardar->setEnabled(false);
        }
        else
            QMessageBox::critical(0,"Error Actualizar Codigo",consulta.lastError().text());

        consulta.exec("select dia_1 from saldo_acum_conceptos where cod_contable='"+reg_codigo.tabla->item(updating.toInt(),1)->text()+"'");
        while(consulta.next())
        {
            found=true; //Busco que exista el codigo contable en la tabla de saldos
        }
        if(found) //Si existe se actualiza al nuevo codigo
        {
            if(consulta.exec("update saldo_acum_conceptos set cod_contable='"+lines->at(0)->text()+"' where cod_contable='"+reg_codigo.tabla->item(updating.toInt(),1)->text()+"'"))
                consulta.exec("commit");
            else
                QMessageBox::critical(0,"Error Actualizar Saldo Concepto",consulta.lastError().text());
            found=false;
        }
        else //Sino, se crea el nuevo registro
        {
            if(consulta.exec("insert into saldo_acum_conceptos values ('"+lines->at(0)->text()+"','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','3','0')"))
                consulta.exec("commit");
            else
                QMessageBox::critical(0,"Error Actualizar Saldo Concepto",consulta.lastError().text());
        }

        consulta.exec("select dia_1 from saldo_acum_conceptos where cod_contable='"+reg_codigo.tabla->item(updating.toInt(),2)->text()+"'");
        while(consulta.next())
        {
            found=true; //Busco que exista el codigo contable del descuento en la tabla de saldos
        }
        if(found)
        {
            if(consulta.exec("update saldo_acum_conceptos set cod_contable='"+lines->at(1)->text()+"' where cod_contable='"+reg_codigo.tabla->item(updating.toInt(),2)->text()+"'"))
                consulta.exec("commit");
            else
                QMessageBox::critical(0,"Error Actualizar Saldo Concepto",consulta.lastError().text());
        }
        else
        {
            if(consulta.exec("insert into saldo_acum_conceptos values ('"+lines->at(1)->text()+"','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','3','0')"))
                consulta.exec("commit");
            else
                QMessageBox::critical(0,"Error Actualizar Saldo Concepto",consulta.lastError().text());
        }
    }
    lines->~QList();
}


void procesos_caja::editarCodigoContable(int row,int column)
{
    QSqlQuery consulta;
    llenarCodigosContables("");
    lines = new QList<QLineEdit*>();

    if(reg_codigo.programa->currentIndex()==0)
    {
        updating = reg_codigo.tabla->item(row,1)->text();
        lines->append(new QLineEdit(reg_codigo.tabla->item(row,0)->text()));
        reg_codigo.tabla->setCellWidget(row,0,lines->last());
        lines->append(new QLineEdit(reg_codigo.tabla->item(row,1)->text()));
        reg_codigo.tabla->setCellWidget(row,1,lines->last());
        lines->append(new QLineEdit(reg_codigo.tabla->item(row,2)->text()));
        reg_codigo.tabla->setCellWidget(row,2,lines->last());
    }
    else
    {
        updating.setNum(row);
        lines->append(new QLineEdit(reg_codigo.tabla->item(row,1)->text()));
        reg_codigo.tabla->setCellWidget(row,1,lines->last());
        lines->append(new QLineEdit(reg_codigo.tabla->item(row,2)->text()));
        reg_codigo.tabla->setCellWidget(row,2,lines->last());
    }
    connect(reg_codigo.tabla->cellWidget(row,2),SIGNAL(returnPressed()),this,SLOT(actualizarCodigoContable()));
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarCodigoContable()));
    container.botonGuardar->setEnabled(true);
    connect(reg_codigo.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_codigo.tabla->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_caja::borrarCodigo()
{
    int row= reg_codigo.tabla->currentRow();
    if(row>=0)
    {
        QSqlQuery consulta;
        QString diplo;
        if(reg_codigo.programa->currentIndex()==0)
        {
            if(consulta.exec("delete from codigo_concepto where cod_contable='"+reg_codigo.tabla->item(row,0)->text()+"'"))
            {
                consulta.exec("commit");
                reg_codigo.tabla->removeRow(row);
            }
            else
                QMessageBox::critical(0,"Error",consulta.lastError().text());
        }
        else
        {
            consulta.exec("select id_diplomado from diplo_temp where descripcion='"+reg_codigo.tabla->item(row,0)->text()+"'");
            while(consulta.next())
            {
                diplo=consulta.value(0).toString();
            }
            if(consulta.exec("update diplo_temp set cod_contable='',cod_descuento='' where id_diplomado='"+diplo+"'"))
            {
                consulta.exec("commit");
                llenarCodigosContables("");
            }
            else
                QMessageBox::critical(0,"Error",consulta.lastError().text());
        }
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


void procesos_caja::setupComercializables()
{
    dialogo = new QWidget();
    ced_dialog.setupUi(dialogo);
    ced_dialog.programa->addItem("-");
    QSqlQuery consulta("select descripcion from programa_academico order by id");
    while(consulta.next())
    {
        ced_dialog.programa->addItem(consulta.value(0).toString());
    }

    ced_dialog.salida->addItem("PANTALLA");
    ced_dialog.salida->addItem("IMPRESORA");

    ced_dialog.titulo->setText("Cuadre de Comercializables");
    ced_dialog.inicio->setDate(QDate::fromString(tr("%1-%2-%3").arg(QDate::currentDate().daysInMonth()).arg(QDate::currentDate().month()).arg(QDate::currentDate().year()),"dd-M-yyyy"));
    ced_dialog.inicio->setEnabled(true);
    ced_dialog.fin->setDate(QDate::fromString(tr("%1-%2-%3").arg(QDate::currentDate().daysInMonth()).arg(QDate::currentDate().month()).arg(QDate::currentDate().year()),"dd-M-yyyy"));
    ced_dialog.fin->setEnabled(true);

    connect(ced_dialog.programa,SIGNAL(currentIndexChanged(QString)),this,SLOT(programaChanged(QString)));
    dialogo->show();
}

void procesos_caja::programaChanged(QString s)
{
    QSqlQuery consulta,consulta2;
    consulta.exec("select id from programa_academico where descripcion ='"+s+"'");
    while(consulta.next())
    {
        ced_dialog.metodo->addItem("TODOS");
        consulta2.exec("select descripcion from metodos where prog_academico='"+consulta.value(0).toString()+"' order by descripcion");
        while(consulta2.next())
        {
            ced_dialog.metodo->addItem(consulta2.value(0).toString());
        }
    }
    connect(ced_dialog.aceptar,SIGNAL(clicked()),this,SLOT(cuadreComercializables()));
}


void procesos_caja::cuadreComercializables()
{
    QSqlQuery consulta,consulta2,consulta3,consulta4;
    QStandardItemModel *model=new QStandardItemModel(0,24);
    QStandardItem *item;
    QString academico,primero,ultimo,seccion,metodo,mat;
    QString tipo[3];
    tipo[0]="L";
    tipo[1]="G";
    tipo[2]="CD";
    int i,j,x,total,nivel,sin;
    bool found=false;

    primero=ced_dialog.inicio->date().toString("dd-MM-yyyy");
    ultimo=ced_dialog.fin->date().toString("dd-MM-yyyy");

    report->reset();
    report->addParameter("prog",ced_dialog.programa->currentText());
    report->addParameter("metodo",ced_dialog.metodo->currentText());
    report->addParameter("inicio",primero);
    report->addParameter("fin",ultimo);

    consulta.exec("select id from programa_academico where descripcion='"+ced_dialog.programa->currentText()+"'");
    while(consulta.next())
    {
        academico=consulta.value(0).toString();
    }

    j=-1;
    if(ced_dialog.metodo->currentText()=="TODOS")
        consulta.exec("select id_metodo,niveles from metodos where prog_academico='"+academico+"' order by descripcion");
    else
        consulta.exec("select id_metodo,niveles from metodos where descripcion='"+ced_dialog.metodo->currentText()+"'");
    while(consulta.next())
    {
        metodo=consulta.value(0).toString();
        nivel=consulta.value(1).toInt();;

        for(x=0;x<3;x++)
        {
            for(i=1;i<=nivel;i++)
            {
                consulta2.exec("select id_mat,descripcion from materiales where tipo='"+tipo[x]+"' and id_curso='"+metodo+"' and nivel='"+tr("%1").arg(i)+"'");
                while(consulta2.next())
                {
                    j++;
                    model->insertRow(j);
                    item = new QStandardItem();
                    item->setData(consulta2.value(1).toString(),Qt::EditRole);
                    model->setItem(j,0,item);
                    mat=consulta2.value(0).toString();
                    found=true;
                }

                if(found)
                {
                    total=0;
                    sin=0;
                    consulta2.exec("select cantidad,id_fact from detalle_factura where item='"+mat+"' and id_fact in(select id_fact from factura where fecha_emi between to_date('"+primero+"','dd-mm-yyyy') and to_date('"+ultimo+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
                    while(consulta2.next())
                    {
                        total+=consulta2.value(0).toInt();
                    }

                    consulta2.exec("select id_seccion from secciones where id_metodo='"+metodo+"' and nivel='"+tr("%1").arg(i)+"'");
                    while(consulta2.next())
                    {
                        consulta3.exec("select cantidad,id_fact from detalle_factura where item='"+consulta2.value(0).toString()+"' and id_fact in (select id_fact from factura where fecha_emi between to_date('"+primero+"','dd-mm-yyyy') and to_date('"+ultimo+"','dd-mm-yyyy') and status='V' and prog_academico='"+academico+"')");
                        while(consulta3.next())
                        {
                            //Arreglar (filtrar por bd, no forzar en codigo nombre de metodo)
                            if((consulta2.value(0).toString()=="AEC")||(consulta2.value(0).toString()=="SF")||(consulta2.value(0).toString()=="EAD")||(consulta2.value(0).toString()=="CAV"))
                                total+=consulta3.value(0).toInt();
                            if(tipo[x]=="L")
                                consulta4.exec("select cantidad from detalle_factura where id_fact='"+consulta3.value(1).toString()+"' and item='DL'");
                            else if(tipo[x]=="CD")
                                consulta4.exec("select cantidad from detalle_factura where id_fact='"+consulta3.value(1).toString()+"' and item='DCD'");
                            while(consulta4.next())
                            {
                                sin+=consulta4.value(0).toInt();
                            }
                        }
                    }
                    item = new QStandardItem();
                    item->setData(tr("%1").arg(total-sin),Qt::EditRole);
                    model->setItem(j,1,item);
                    found=false;
                }
            }
        }
        //j++;
        //model->insertRow(j);
    }

    report->addItemModel(model,"model");
    report->setReportFile("reportes/cuadre_comercializable.xml");
    report->runReportToPDF("test.pdf");
    if (!report->hasError())
    {
        ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
    }
    if (!report->hasError())
    {
        if(ced_dialog.salida->currentIndex()==1)
            ShellExecuteA(NULL,"print",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        else
            ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
    }
    else
        QMessageBox::information(0,"Error",report->lastErrorMsg());

    dialogo->close();
}


bool procesos_caja::duplicarCohorte(QString s)
{
    QString nuevo_id,numero;
    QSqlQuery consulta,consulta2;
    consulta.exec("select id,id_diplomado,id_horario,id_modalidad,cohorte,cant_actual,to_char(fecha_ini,'dd-mm-yyyy'),to_char(fecha_fin,'dd-mm-yyyy'),costo,inicial,costo_cuota from cohortes where id='"+s+"'");
    while(consulta.next())
    {
        numero.setNum(consulta.value(4).toInt()+1);
        nuevo_id=consulta.value(1).toString()+numero+"-"+consulta.value(0).toString().right(2);
        if(consulta2.exec("insert into cohortes values('"+nuevo_id+"','"+consulta.value(1).toString()+"','"+consulta.value(2).toString()+"','"+consulta.value(3).toString()+"','"+numero+"','0',to_date('"+consulta.value(6).toString()+"','dd-mm-yyyy'),to_date('"+consulta.value(7).toString()+"','dd-mm-yyyy'),'"+consulta.value(8).toString()+"','"+consulta.value(9).toString()+"','"+consulta.value(10).toString()+"')"))
        {
            consulta2.exec("commit");
            return true;
        }
        else
        {
            QMessageBox::critical(0,"Error",consulta2.lastError().text());
            return false;
        }
    }
}




/**
 *
 */

void procesos_caja::printFile(QTextDocument *d)
{
    #ifndef QT_NO_PRINTER

    QPrinter printer;
    QSizeF size(242,185);
    printer.setPaperSize(size,QPrinter::Millimeter);

    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    dialog->setWindowTitle(tr("Print Document"));

    if (dialog->exec() != QDialog::Accepted)
        return;
    d->print(&printer);
    #endif
}

procesos_caja::~procesos_caja()
{

}


