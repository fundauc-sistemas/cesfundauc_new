/*
 * procesos_ces.cpp
 *
 *  Created on: 15/05/2009
 *      Author: Oriana Gómez.
 */
#include "procesos_ces.h"


procesos_ces::procesos_ces(QString programa,QString academico,QString user,QSqlDatabase db,QWidget *parent): QWidget(parent)
{
    container.setupUi(this);
    prog=programa;
    usuario=user;
    report= new NCReport();
    prog_academico=academico;
}


void procesos_ces::registroEstudiantes2()
{
    frame = new QFrame();
    reg_estudiante2.setupUi(frame);
    container.workspace->setWidget(frame);
    llenarEstudiantes();
    reg_estudiante2.tabla->setColumnWidth(1,200);
    reg_estudiante2.tabla->setColumnWidth(2,200);
    reg_estudiante2.tabla->setColumnWidth(5,100);
    reg_estudiante2.tabla->setColumnWidth(6,60);
    reg_estudiante2.tabla->setColumnWidth(7,120);
    reg_estudiante2.tabla->setColumnWidth(8,140);
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(setNuevoEstudiante()));
    connect(reg_estudiante2.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarEstudiante(int,int)));
    connect(reg_estudiante2.cedula,SIGNAL(returnPressed()),this,SLOT(llenarEstudiantes()));
    connect(reg_estudiante2.matricula,SIGNAL(returnPressed()),this,SLOT(llenarEstudiantes()));
    connect(reg_estudiante2.nombre,SIGNAL(returnPressed()),this,SLOT(llenarEstudiantes()));
    connect(reg_estudiante2.nombre,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    container.botonNuevo->setEnabled(true);
}


void procesos_ces::setNuevoEstudiante()
{
    registroEstudiantes(" ");
}


void procesos_ces::registroEstudiantes(QString cedula)
{
    QStringList edo_civil,instruccion;
    QString matricula;
    int aux=0;
    QSqlQuery consulta;

    consulta.exec("select max(matricula) from estudiante");
    while(consulta.next())
    {
        aux=consulta.value(0).toInt();
        aux++;
    }

    matricula.setNum(aux);
    estudianteFrame = new QWidget();
    reg_estudiante.setupUi(estudianteFrame);
    estudianteFrame->setWindowTitle("Registro de Estudiantes");

    reg_estudiante.e_matricula->setText(matricula);
    reg_estudiante.e_cedula->setText(cedula);
    edo_civil << "SOLTERO" << "CASADO" << "DIVORCIADO" << "VIUDO";
    instruccion << "PRIMARIA" << "SECUNDARIA" << "T.S.U." << "UNIVERSITARIA" << "POST UNIVERSITARIA";

    reg_estudiante.e_ocupacion->addItem("-");
    consulta.exec("select nombre from ocupaciones order by nombre");
    while(consulta.next())
    {
        reg_estudiante.e_ocupacion->addItem(consulta.value(0).toString());
    }

    reg_estudiante.e_tipo->addItem("-");
    consulta.exec("select descripcion from tipo_estudiante order by id_tipo_est");
    while(consulta.next())
    {
        reg_estudiante.e_tipo->addItem(consulta.value(0).toString());
    }

    reg_estudiante.e_condicion->addItem("-");
    consulta.exec("select descripcion from condiciones_especiales order by id_condicion");
    while(consulta.next())
    {
        reg_estudiante.e_condicion->addItem(consulta.value(0).toString());
    }

    reg_estudiante.e_sede->addItem("-");
    consulta.exec("select descripcion from companias order by descripcion");
    while(consulta.next())
    {
        reg_estudiante.e_sede->addItem(consulta.value(0).toString());
    }

    reg_estudiante.e_civil->addItems(edo_civil);
    reg_estudiante.e_instruccion->addItems(instruccion);
    connect(reg_estudiante.e_nombre,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.e_apellido,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.e_email,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.estado,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.ciudad,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.zona,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.e_guardar,SIGNAL(clicked()),this,SLOT(nuevoEstudiante()));
    //connect(reg_estudiante.e_representante,SIGNAL(clicked(bool)),this,SLOT(repChecked(bool)));
    estudianteFrame->show();
}


void procesos_ces::repChecked(bool checked)
{
    if(checked)
    {
        reg_estudiante.e_cedula2->setEnabled(true);
        reg_estudiante.e_nombre2->setEnabled(true);
        reg_estudiante.e_telefono2->setEnabled(true);
        connect(reg_estudiante.e_nombre2,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    }
    else
    {
        reg_estudiante.e_cedula2->setEnabled(false);
        reg_estudiante.e_nombre2->setEnabled(false);
        reg_estudiante.e_telefono2->setEnabled(false);
    }
}


void procesos_ces::llenarEstudiantes()
{
    QSqlQuery consulta,consulta2;
    QTableWidgetItem *ni;
    QString cia;
    int i,row;
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    for(i=reg_estudiante2.tabla->rowCount()-1;i>=0;i--)
        reg_estudiante2.tabla->removeRow(i);

    consulta.exec("select codigo from companias where id='"+prog+"'");
    while(consulta.next())
    {
        cia=consulta.value(0).toString();
    }

    if(reg_estudiante2.nombre->text()!="")
        consulta.exec("select cedula_est,nombre,apellido,telf_hab,telf_cel,matricula,sede,id_tipo_est,condicion_especial from estudiante where sede='"+cia+"' and (nombre like '%"+le->text()+"%' or apellido like '%"+le->text()+"%') order by matricula");
    else if((reg_estudiante2.cedula->text()=="")&&(reg_estudiante2.matricula->text()==""))
        consulta.exec("select cedula_est,nombre,apellido,telf_hab,telf_cel,matricula,sede,id_tipo_est,condicion_especial from estudiante where sede='"+cia+"' order by matricula");
    else
        consulta.exec("select cedula_est,nombre,apellido,telf_hab,telf_cel,matricula,sede,id_tipo_est,condicion_especial from estudiante where sede='"+cia+"' and (cedula_est='"+le->text()+"' or matricula='"+le->text()+"') order by matricula");

    while(consulta.next())
    {
        row = reg_estudiante2.tabla->rowCount();
        reg_estudiante2.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_estudiante2.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_estudiante2.tabla->setItem(row,1,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        reg_estudiante2.tabla->setItem(row,2,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        reg_estudiante2.tabla->setItem(row,3,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(4).toString()));
        reg_estudiante2.tabla->setItem(row,4,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(5).toString()));
        reg_estudiante2.tabla->setItem(row,5,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(6).toString()));
        reg_estudiante2.tabla->setItem(row,6,ni);
        consulta2.exec("select descripcion from tipo_estudiante where id_tipo_est='"+consulta.value(7).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_estudiante2.tabla->setItem(row,7,ni);
        }

        consulta2.exec("select descripcion from condiciones_especiales where id_condicion='"+consulta.value(8).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_estudiante2.tabla->setItem(row,8,ni);
        }
    }
    reg_estudiante2.cedula->setText("");
    reg_estudiante2.matricula->setText("");
    reg_estudiante2.nombre->setText("");
}


void procesos_ces::nuevoEstudiante()
{
    QString sexo,status,fecha,tipo,pais,zona,sede,condicion,matricula;
    QSqlQuery consulta;
    int aux=0;

    consulta.exec("select max(matricula) from estudiante");
    while(consulta.next())
    {
        aux=consulta.value(0).toInt();
        aux++;
    }
    matricula.setNum(aux);

    if(reg_estudiante.e_masculino->isChecked())
        sexo = 'M';
    else
        sexo = 'F';

    fecha = reg_estudiante.e_fecha->date().toString("dd-MM-yyyy");
    consulta.exec("select id_tipo_est from tipo_estudiante where descripcion='"+reg_estudiante.e_tipo->currentText()+"'");
    while(consulta.next())
    {
       tipo=consulta.value(0).toString();
    }

    consulta.exec("select id_condicion from condiciones_especiales where descripcion='"+reg_estudiante.e_condicion->currentText()+"'");
    while(consulta.next())
    {
        condicion=consulta.value(0).toString();
    }

    if(reg_estudiante.e_venezolano->isChecked())
        pais ='V';
    else
        pais ='E';

    status = 'A';

    consulta.exec("select codigo from companias where descripcion='"+reg_estudiante.e_sede->currentText()+"'");
    while(consulta.next())
    {
        sede=consulta.value(0).toString();
    }
    if(consulta.exec("INSERT INTO ESTUDIANTE VALUES('"+reg_estudiante.e_cedula->text()+"','"+pais+"','"+reg_estudiante.e_nombre->text()+"',"
                                        "'"+reg_estudiante.e_codigo->text()+"-"+reg_estudiante.e_telefono->text()+"','"+reg_estudiante.e_codigo2->text()+"-"+reg_estudiante.e_celular->text()+"','"+reg_estudiante.ciudad->text()+"',"
                                        "'"+reg_estudiante.estado->text()+"','"+reg_estudiante.e_email->text()+"','"+sexo+"','"+reg_estudiante.e_civil->currentText()+"','"+reg_estudiante.e_instruccion->currentText()+""
                                        "','"+reg_estudiante.e_ocupacion->currentText()+"',to_date('"+fecha+"','dd-mm-yyyy'),'"+status+"','"+tipo+"','0',"
                         "'"+matricula+"','"+sede+"','"+condicion+"','"+reg_estudiante.e_apellido->text()+"','"+reg_estudiante.e_cedula2->text()+"','"+reg_estudiante.zona->text()+"')"))
    {
        consulta.exec("commit");
        estudianteFrame->close();
    }
    else
        QMessageBox::critical(0,"Error Nuevo Estudiante",consulta.lastError().text());
}


void procesos_ces::editarEstudiante(int row,int column)
{
    QSqlQuery consulta,consulta2;
    QStringList edo_civil,instruccion;
    estudianteFrame = new QWidget();
    reg_estudiante.setupUi(estudianteFrame);
    estudianteFrame->setWindowTitle("Registro de Estudiantes");

    edo_civil << "SOLTERO" << "CASADO" << "DIVORCIADO" << "VIUDO";
    instruccion << "PRIMARIA" << "SECUNDARIA" << "T.S.U." << "UNIVERSITARIA" << "POST UNIVERSITARIA";

    consulta.exec("select nombre from ocupaciones order by nombre");
    while(consulta.next())
    {
        reg_estudiante.e_ocupacion->addItem(consulta.value(0).toString());
    }
    consulta.exec("select descripcion from tipo_estudiante order by id_tipo_est");
    while(consulta.next())
    {
        reg_estudiante.e_tipo->addItem(consulta.value(0).toString());
    }
    consulta.exec("select descripcion from condiciones_especiales order by id_condicion");
    while(consulta.next())
    {
        reg_estudiante.e_condicion->addItem(consulta.value(0).toString());
    }
    consulta.exec("select descripcion from companias order by descripcion");
    while(consulta.next())
    {
        reg_estudiante.e_sede->addItem(consulta.value(0).toString());
    }
    reg_estudiante.e_civil->addItems(edo_civil);
    reg_estudiante.e_instruccion->addItems(instruccion);

    reg_estudiante.e_cedula->setText(reg_estudiante2.tabla->item(row,0)->text());
    consulta.exec("select * from estudiante where cedula_est='"+reg_estudiante2.tabla->item(row,0)->text()+"'");
    while(consulta.next())
    {
        reg_estudiante.e_matricula->setText(consulta.value(16).toString());
        reg_estudiante.e_nombre->setText(consulta.value(2).toString());
        reg_estudiante.e_apellido->setText(consulta.value(19).toString());
        reg_estudiante.e_codigo->setText(consulta.value(3).toString().left(4));
        reg_estudiante.e_telefono->setText(consulta.value(3).toString().remove(0,5));
        reg_estudiante.e_codigo2->setText(consulta.value(4).toString().left(4));
        reg_estudiante.e_celular->setText(consulta.value(4).toString().remove(0,5));
        reg_estudiante.e_email->setText(consulta.value(7).toString());
        reg_estudiante.e_civil->setCurrentIndex(reg_estudiante.e_civil->findText(consulta.value(9).toString()));
        reg_estudiante.e_tipo->setCurrentIndex(reg_estudiante.e_tipo->findText(reg_estudiante2.tabla->item(row,7)->text()));
        reg_estudiante.e_instruccion->setCurrentIndex(reg_estudiante.e_instruccion->findText(consulta.value(10).toString()));
        reg_estudiante.estado->setText(consulta.value(6).toString());
        reg_estudiante.ciudad->setText(consulta.value(5).toString());
        reg_estudiante.zona->setText(consulta.value(21).toString());
        reg_estudiante.e_condicion->setCurrentIndex(reg_estudiante.e_condicion->findText(reg_estudiante2.tabla->item(row,8)->text()));

        consulta2.exec("select descripcion from companias where codigo='"+consulta.value(17).toString()+"'");
        while(consulta2.next())
        {
            reg_estudiante.e_sede->setCurrentIndex(reg_estudiante.e_sede->findText(consulta2.value(0).toString()));
        }

        reg_estudiante.e_ocupacion->setCurrentIndex(reg_estudiante.e_ocupacion->findText(consulta.value(11).toString()));
        reg_estudiante.e_fecha->setDate(consulta.value(12).toDate());

        if(consulta.value(8).toString()=="M")
            reg_estudiante.e_masculino->setChecked(true);
        else
            reg_estudiante.e_femenino->setChecked(true);

        if(consulta.value(1).toString()=="V")
            reg_estudiante.e_venezolano->setChecked(true);
        else
            reg_estudiante.e_extranjero->setChecked(true);
    }
    disconnect(reg_estudiante.e_guardar,SIGNAL(clicked()),0,0);
    connect(reg_estudiante.e_guardar,SIGNAL(clicked()),this,SLOT(actualizarEstudiante()));
    connect(reg_estudiante.e_nombre,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.e_apellido,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.e_email,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.estado,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.ciudad,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.zona,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    estudianteFrame->show();
}


void procesos_ces::actualizarEstudiante()
{
    QString sexo,status,fecha,tipo,pais,zona,sede,condicion;
    QSqlQuery consulta;

    if(reg_estudiante.e_masculino->isChecked())
        sexo = 'M';
    else
        sexo = 'F';

    fecha = reg_estudiante.e_fecha->date().toString("dd-MM-yyyy");
    consulta.exec("select id_tipo_est from tipo_estudiante where descripcion='"+reg_estudiante.e_tipo->currentText()+"'");
    while(consulta.next())
    {
       tipo=consulta.value(0).toString();
    }
    consulta.exec("select id_condicion from condiciones_especiales where descripcion='"+reg_estudiante.e_condicion->currentText()+"'");
    while(consulta.next())
    {
        condicion=consulta.value(0).toString();
    }
    if(reg_estudiante.e_venezolano->isChecked())
        pais ='V';
    else
        pais ='E';

    status = 'A';

    consulta.exec("select codigo from companias where descripcion='"+reg_estudiante.e_sede->currentText()+"'");
    while(consulta.next())
    {
        sede=consulta.value(0).toString();
    }

    if(consulta.exec("Update ESTUDIANTE set cedula_est='"+reg_estudiante.e_cedula->text()+"',nacionalidad='"+pais+"',nombre='"+reg_estudiante.e_nombre->text()+"',"
                                    "telf_hab='"+reg_estudiante.e_codigo->text()+"-"+reg_estudiante.e_telefono->text()+"',telf_cel='"+reg_estudiante.e_codigo2->text()+"-"+reg_estudiante.e_celular->text()+"',ciudad='"+reg_estudiante.ciudad->text()+"',"
                                    "estado='"+reg_estudiante.estado->text()+"',email='"+reg_estudiante.e_email->text()+"',sexo='"+sexo+"',edo_civil='"+reg_estudiante.e_civil->currentText()+"',grado_ins='"+reg_estudiante.e_instruccion->currentText()+""
                                    "',profesion='"+reg_estudiante.e_ocupacion->currentText()+"',fecha_nac=to_date('"+fecha+"','dd-mm-yyyy'),status='"+status+"',id_tipo_est='"+tipo+"',rif='0',sede='"+sede+"',condicion_especial='"+condicion+"',"
                                    "apellido='"+reg_estudiante.e_apellido->text()+"',zona='"+reg_estudiante.zona->text()+"' where matricula='"+reg_estudiante.e_matricula->text()+"'"))
    {
        consulta.exec("commit");
        estudianteFrame->close();
        llenarEstudiantes();
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::registroEmpresas(QString rif, QString matricula)
{
    estudianteFrame= new QWidget();
    reg_empresas.setupUi(estudianteFrame);
    estudianteFrame->setWindowTitle("Registro de Empresas");
    reg_empresas.rif->setText(rif);
    reg_empresas.matricula->setText(matricula);
    connect(reg_empresas.rif,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_empresas.razon,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_empresas.dir,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_empresas.aceptar,SIGNAL(pressed()),this,SLOT(nuevaEmpresa()));
    estudianteFrame->show();
}


void procesos_ces::nuevaEmpresa()
{
    QSqlQuery consulta,query;
    //QSqlQuery query(db2);


    //if(!consulta.exec("insert into empresas values('"+reg_empresas.rif->text()+"','"+reg_empresas.razon->text()+"','"+reg_empresas.dir->text()+"','"+reg_empresas.telefono->text()+"')"))
    if(!query.exec("insert into dpclientes values('','1','','E','','','','0','1','','"+reg_empresas.rif->text()+"','','','','','N','N','','','"+reg_empresas.dir->text()+"','"+reg_empresas.dir2->text()+"','','','"+reg_empresas.email->text()+"','N','-Indefinido','','','','','A','0','N','','','-Indefinido','"+reg_empresas.razon->text()+"','','','Venezuela','-Indefinido','N','','S','','A','"+reg_empresas.telefono->text()+"','','','','','','N','N','"+usuario+"','','N','','','currentdate','','','','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0')"))
        QMessageBox::critical(0,"Error Nuevo Cliente",consulta.lastError().text());
    else
    {
        if(!consulta.exec("update estudiante set cedula_rep='"+reg_empresas.rif->text()+"' where matricula='"+reg_empresas.matricula->text()+"'"))
            QMessageBox::critical(0,"Error",consulta.lastError().text());
        else
        {
            consulta.exec("commit");
            estudianteFrame->close();
        }
    }
}


void procesos_ces::registroProfesores()
{
    QStringList labels;
    frame = new QFrame();
    reg_estudiante2.setupUi(frame);
    container.workspace->setWidget(frame);
    reg_estudiante2.tabla->setColumnCount(7);
    labels << "Cedula "<< "Nombre" << "Apellido" << "Telefono" << "Telefono Celular" << "RIF" << "Sede";
    reg_estudiante2.tabla->setHorizontalHeaderLabels(labels);
    reg_estudiante2.label->setText("Profesores");
    llenarProfesores();
    reg_estudiante2.tabla->setColumnWidth(1,200);
    reg_estudiante2.tabla->setColumnWidth(2,200);
    reg_estudiante2.tabla->setColumnWidth(8,140);
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoProfesor()));
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarProfesor()));
    connect(reg_estudiante2.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarProfesor(int,int)));
    connect(reg_estudiante2.cedula,SIGNAL(returnPressed()),this,SLOT(llenarProfesores()));
    connect(reg_estudiante2.matricula,SIGNAL(returnPressed()),this,SLOT(llenarProfesores()));
    connect(reg_estudiante2.nombre,SIGNAL(returnPressed()),this,SLOT(llenarProfesores()));
    connect(reg_estudiante2.nombre,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    container.botonNuevo->setEnabled(true);
    container.botonAnular->setEnabled(true);
}


void procesos_ces::llenarProfesores()
{
    QSqlQuery consulta;
    QTableWidgetItem *ni;
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    int i,row;

    for(i=reg_estudiante2.tabla->rowCount()-1;i>=0;i--)
        reg_estudiante2.tabla->removeRow(i);

    if(reg_estudiante2.nombre->text()!="")
        consulta.exec("select cedula_prof,nombre,apellido,telf_hab,telf_cel,rif,sede from profesor where nombre like '%"+le->text()+"%' or apellido like '%"+le->text()+"%' order by apellido");
    else if((reg_estudiante2.cedula->text()=="")&&(reg_estudiante2.matricula->text()==""))
        consulta.exec("select cedula_prof,nombre,apellido,telf_hab,telf_cel,rif,sede from profesor order by apellido");
    else
        consulta.exec("select cedula_prof,nombre,apellido,telf_hab,telf_cel,rif,sede from profesor where cedula_prof='"+le->text()+"' or rif='"+le->text()+"' order by apellido");
    while(consulta.next())
    {
        row = reg_estudiante2.tabla->rowCount();
        reg_estudiante2.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_estudiante2.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_estudiante2.tabla->setItem(row,1,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        reg_estudiante2.tabla->setItem(row,2,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        reg_estudiante2.tabla->setItem(row,3,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(4).toString()));
        reg_estudiante2.tabla->setItem(row,4,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(5).toString()));
        reg_estudiante2.tabla->setItem(row,5,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(6).toString()));
        reg_estudiante2.tabla->setItem(row,6,ni);
    }
}

void procesos_ces::nuevoProfesor()
{
    QStringList edo_civil,instruccion;
    QSqlQuery consulta;
    estudianteFrame = new QWidget();
    reg_estudiante.setupUi(estudianteFrame);
    estudianteFrame->setWindowTitle("Registro de Profesores");
    reg_estudiante.mat_rif->setText("RIF");
    reg_estudiante.e_condicion->setEnabled(false);

    edo_civil << "SOLTERO" << "CASADO" << "DIVORCIADO" << "VIUDO";
    instruccion << "PRIMARIA" << "SECUNDARIA" << "T.S.U." << "UNIVERSITARIO" << "POST UNIVERSITARIO";

    consulta.exec("select nombre from ocupaciones order by nombre");
    while(consulta.next())
    {
        reg_estudiante.e_ocupacion->addItem(consulta.value(0).toString());
    }

    consulta.exec("select * from tipo_profesor order by id_tipo_prof");
    while(consulta.next())
    {
        reg_estudiante.e_tipo->addItem(consulta.value(0).toString()+"-"+consulta.value(1).toString());
    }

    consulta.exec("select descripcion from companias order by descripcion");
    while(consulta.next())
    {
        reg_estudiante.e_sede->addItem(consulta.value(0).toString());
    }

    reg_estudiante.e_civil->addItems(edo_civil);
    reg_estudiante.e_instruccion->addItems(instruccion);
    reg_estudiante.e_matricula->setEnabled(true);
    connect(reg_estudiante.e_nombre,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.e_apellido,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.e_email,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.e_matricula,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.estado,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.ciudad,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.zona,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    disconnect(reg_estudiante.e_guardar,SIGNAL(clicked()),0,0);
    connect(reg_estudiante.e_guardar,SIGNAL(clicked()),this,SLOT(guardarProfesor()));
    estudianteFrame->show();
}


void procesos_ces::guardarProfesor()
{
    QString sexo,status,fecha,tipo,edo_civil,grado,pais,zona,sede;
    QSqlQuery consulta;

    if(reg_estudiante.e_masculino->isChecked())
        sexo = 'M';
    else
        sexo = 'F';

    fecha = reg_estudiante.e_fecha->date().toString("dd-MM-yyyy");
    tipo = reg_estudiante.e_tipo->currentText().left(1);
    grado = reg_estudiante.e_instruccion->currentText().left(1);
    edo_civil = reg_estudiante.e_civil->currentText().left(1);

    if(reg_estudiante.e_venezolano->isChecked())
        pais ='V';
    else
        pais ='E';

    status = 'A';
    consulta.exec("select codigo from companias where descripcion='"+reg_estudiante.e_sede->currentText()+"'");
    while(consulta.next())
    {
        sede=consulta.value(0).toString();
    }
    //Cambiar primero la tabla, acorde a la de estudiantes

    if(consulta.exec("insert into profesor values('"+reg_estudiante.e_cedula->text()+"','"+pais+"','"+reg_estudiante.e_nombre->text()+"'"
                    ",'"+reg_estudiante.e_codigo->text()+"-"+reg_estudiante.e_telefono->text()+"','"+reg_estudiante.e_codigo2->text()+"-"+reg_estudiante.e_celular->text()+"','"+reg_estudiante.ciudad->text()+"',"
                    "'"+reg_estudiante.estado->text()+"','"+reg_estudiante.e_email->text()+"','"+sexo+"','"+edo_civil+"','"+grado+"',"
                     "'"+reg_estudiante.e_ocupacion->currentText()+"',to_date('"+fecha+"','dd-mm-yyyy'),'"+status+"','"+tipo+"','"+reg_estudiante.e_matricula->text()+"','"+sede+"','"+reg_estudiante.e_apellido->text()+"','"+reg_estudiante.zona->text()+"')"))
    {
        consulta.exec("commit");
        llenarProfesores();
        estudianteFrame->close();
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::editarProfesor(int row,int column)
{
    QSqlQuery consulta,consulta2;
    estudianteFrame = new QWidget();
    reg_estudiante.setupUi(estudianteFrame);
    estudianteFrame->setWindowTitle("Registro de Profesores");
    reg_estudiante.mat_rif->setText("RIF");

    consulta.exec("select nombre from ocupaciones order by nombre");
    while(consulta.next())
    {
        reg_estudiante.e_ocupacion->addItem(consulta.value(0).toString());
    }
    consulta.exec("select * from tipo_profesor order by id_tipo_prof");
    while(consulta.next())
    {
        reg_estudiante.e_tipo->addItem(consulta.value(0).toString()+"-"+consulta.value(1).toString());
    }
    consulta.exec("select descripcion from companias order by descripcion");
    while(consulta.next())
    {
        reg_estudiante.e_sede->addItem(consulta.value(0).toString());
    }
    //reg_estudiante.e_representante->setEnabled(false);
    reg_estudiante.e_cedula->setText(reg_estudiante2.tabla->item(row,0)->text());
    consulta.exec("select * from profesor where cedula_prof='"+reg_estudiante2.tabla->item(row,0)->text()+"'");
    while(consulta.next())
    {
        reg_estudiante.e_matricula->setText(consulta.value(15).toString());
        reg_estudiante.e_nombre->setText(consulta.value(2).toString());
        reg_estudiante.e_apellido->setText(consulta.value(17).toString());
        reg_estudiante.e_codigo->setText(consulta.value(3).toString().left(4));
        reg_estudiante.e_telefono->setText(consulta.value(3).toString().remove(0,5));
        reg_estudiante.e_codigo2->setText(consulta.value(4).toString().left(4));
        reg_estudiante.e_celular->setText(consulta.value(4).toString().remove(0,5));
        reg_estudiante.e_email->setText(consulta.value(7).toString());
        reg_estudiante.e_civil->setCurrentIndex(reg_estudiante.e_civil->findText(consulta.value(9).toString()));
        reg_estudiante.e_tipo->setCurrentIndex(consulta.value(14).toInt()-1);
        reg_estudiante.e_instruccion->setCurrentIndex(reg_estudiante.e_instruccion->findText(consulta.value(10).toString()));
        reg_estudiante.estado->setText(consulta.value(6).toString());
        reg_estudiante.ciudad->setText(consulta.value(5).toString());
        reg_estudiante.zona->setText(consulta.value(18).toString());

        consulta2.exec("select descripcion from companias where codigo='"+consulta.value(16).toString()+"'");
        while(consulta2.next())
        {
            reg_estudiante.e_sede->setCurrentIndex(reg_estudiante.e_sede->findText(consulta2.value(0).toString()));
        }

        reg_estudiante.e_ocupacion->setCurrentIndex(reg_estudiante.e_ocupacion->findText(consulta.value(11).toString()));
        reg_estudiante.e_fecha->setDate(consulta.value(12).toDate());

        if(consulta.value(8).toString()=="M")
            reg_estudiante.e_masculino->setChecked(true);
        else
            reg_estudiante.e_femenino->setChecked(true);

        if(consulta.value(1).toString()=="V")
            reg_estudiante.e_venezolano->setChecked(true);
        else
            reg_estudiante.e_extranjero->setChecked(true);
    }
    disconnect(reg_estudiante.e_guardar,SIGNAL(clicked()),0,0);
    connect(reg_estudiante.e_guardar,SIGNAL(clicked()),this,SLOT(actualizarProfesor()));
    connect(reg_estudiante.e_nombre,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.e_apellido,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.e_email,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.e_matricula,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.estado,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.ciudad,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_estudiante.zona,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));

    estudianteFrame->show();
}


void procesos_ces::actualizarProfesor()
{
    QString sexo,status,fecha,tipo,pais,zona,sede;
    QSqlQuery consulta;

    if(reg_estudiante.e_masculino->isChecked())
        sexo = 'M';
    else
        sexo = 'F';

    fecha = reg_estudiante.e_fecha->date().toString("dd-MM-yyyy");
    tipo = reg_estudiante.e_tipo->currentText().left(1);

    if(reg_estudiante.e_venezolano->isChecked())
        pais ='V';
    else
        pais ='E';

    status = 'A';

    consulta.exec("select codigo from companias where descripcion='"+reg_estudiante.e_sede->currentText()+"'");
    while(consulta.next())
    {
        sede=consulta.value(0).toString();
    }

    if(consulta.exec("Update profesor set nacionalidad='"+pais+"',nombre='"+reg_estudiante.e_nombre->text()+"',"
                                    "telf_hab='"+reg_estudiante.e_codigo->text()+"-"+reg_estudiante.e_telefono->text()+"',telf_cel='"+reg_estudiante.e_codigo2->text()+"-"+reg_estudiante.e_celular->text()+"',ciudad='"+reg_estudiante.ciudad->text()+"',"
                                    "estado='"+reg_estudiante.estado->text()+"',email='"+reg_estudiante.e_email->text()+"',sexo='"+sexo+"',edo_civil='"+reg_estudiante.e_civil->currentText()+"',grado_ins='"+reg_estudiante.e_instruccion->currentText()+""
                     "',profesion='"+reg_estudiante.e_ocupacion->currentText()+"',fecha_nac=to_date('"+fecha+"','dd-mm-yyyy'),status='"+status+"',id_tipo_prof='"+tipo+"',rif='"+reg_estudiante.e_matricula->text()+"',sede='"+sede+"',apellido='"+reg_estudiante.e_apellido->text()+"',zona='"+reg_estudiante.zona->text()+"' where cedula_prof='"+reg_estudiante.e_cedula->text()+"'"))
    {
        consulta.exec("commit");
        llenarProfesores();
        estudianteFrame->close();
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::borrarProfesor()
{
    int row= reg_estudiante2.tabla->currentRow();
    if(row>=0)
    {
        QSqlQuery consulta;
        if(consulta.exec("delete from profesor where cedula_prof='"+reg_estudiante2.tabla->item(row,0)->text()+"'"))
        {
            reg_estudiante2.tabla->removeRow(row);
            consulta.exec("commit");
        }
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


void procesos_ces::registroModulos()
{
    QSqlQuery consulta;
    frame = new QFrame();
    reg_modulos.setupUi(frame);
    container.workspace->setWidget(frame);
    reg_modulos.diplomado->addItem("-");
    consulta.exec("select descripcion from diplo_temp order by descripcion");
    while(consulta.next())
    {
        reg_modulos.diplomado->addItem(consulta.value(0).toString());
    }

    connect(reg_modulos.diplomado,SIGNAL(currentIndexChanged(QString)),this,SLOT(diplomadoChanged2(QString)));
    connect(reg_modulos.nombre,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_modulos.facilitador,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_ces::diplomadoChanged2(QString s)
{
    QSqlQuery consulta,consulta2,consulta3;
    int i;

    reg_modulos.modulo->clear();
    reg_modulos.cohorte->clear();
    reg_modulos.nombre->clear();
    reg_modulos.facilitador->clear();
    reg_modulos.duracion->clear();
    reg_modulos.clases->clear();
    reg_modulos.modulo->addItem("-");
    reg_modulos.cohorte->addItem("-");

    consulta.exec("select id_diplomado,modulos from diplo_temp where descripcion='"+s+"' order by id_diplomado");
    while(consulta.next())
    {
        for(i=0;i<consulta.value(1).toInt();i++)
        {
            reg_modulos.modulo->addItem(tr("%1").arg(i+1));
        }
        consulta2.exec("select id from cohortes where id_diplomado='"+consulta.value(0).toString()+"' and status='V' order by id");
        while(consulta2.next())
        {
            reg_modulos.cohorte->addItem(consulta2.value(0).toString());
        }
    }
    connect(reg_modulos.modulo,SIGNAL(currentIndexChanged(QString)),this,SLOT(moduloChanged(QString)));
    reg_modulos.modulo->setEnabled(true);
}


void procesos_ces::moduloChanged(QString s)
{
    QSqlQuery consulta;
    QString diplo;
    reg_modulos.cohorte->setEnabled(true);
    reg_modulos.nombre->clear();
    reg_modulos.facilitador->clear();
    reg_modulos.duracion->clear();
    reg_modulos.clases->clear();
    reg_modulos.cohorte->setCurrentIndex(0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarModulo()));

    consulta.exec("select id_diplomado from diplo_temp where descripcion='"+reg_modulos.diplomado->currentText()+"'");
    while(consulta.next())
    {
        diplo=consulta.value(0).toString();
    }

    consulta.exec("select * from modulos_diplomado where id_diplomado='"+diplo+"' and modulo='"+reg_modulos.modulo->currentText()+"'");
    while(consulta.next())
    {
        reg_modulos.nombre->setText(consulta.value(2).toString());
        reg_modulos.facilitador->setText(consulta.value(3).toString());
        reg_modulos.duracion->setText(consulta.value(4).toString());
        reg_modulos.clases->setText(consulta.value(5).toString());
        disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
        connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarModulo()));
    }

    reg_modulos.nombre->setEnabled(true);
    reg_modulos.facilitador->setEnabled(true);
    reg_modulos.duracion->setEnabled(true);
    connect(reg_modulos.cohorte,SIGNAL(currentIndexChanged(QString)),this,SLOT(modalidadChanged3(QString)));
}


void procesos_ces::modalidadChanged3(QString s)
{
    QSqlQuery consulta;
    bool full=false;
    QString diplo,mod;
    int row,i;

    for(i=reg_modulos.fechas->rowCount()-1;i>=0;i--)
        reg_modulos.fechas->removeRow(i);

    inicios=new QList<QDateEdit*>();
    consulta.exec("select id_diplomado from diplo_temp where descripcion='"+reg_modulos.diplomado->currentText()+"'");
    while(consulta.next())
    {
        diplo=consulta.value(0).toString();
    }

    consulta.exec("select to_char(fecha,'dd-mm-yyyy') from calendario_modulos where id_diplomado='"+diplo+"' and modulo='"+reg_modulos.modulo->currentText()+"' and id_cohorte='"+s+"'");
    while(consulta.next())
    {
        row = reg_modulos.fechas->rowCount();
        reg_modulos.fechas->insertRow(row);
        inicios->append(new QDateEdit(QDate::fromString(consulta.value(0).toString(),"dd-MM-yyyy")));
        reg_modulos.fechas->setCellWidget(row,0,inicios->last());
    }
    reg_modulos.clases->setEnabled(true);
    connect(reg_modulos.clases,SIGNAL(textEdited(QString)),this,SLOT(claseChanged(QString)));
}


void procesos_ces::claseChanged(QString s)
{
    int i;
    QSqlQuery consulta;
    inicios = new QList<QDateEdit*>();

    for(i=reg_modulos.fechas->rowCount()-1;i>=0;i--)
        reg_modulos.fechas->removeRow(i);

    for(i=0;i<s.toInt();i++)
    {
        reg_modulos.fechas->insertRow(i);
        inicios->append(new QDateEdit());
        reg_modulos.fechas->setCellWidget(i,0,inicios->last());
    }
    container.botonGuardar->setEnabled(true);
}


void procesos_ces::guardarModulo()
{
    QSqlQuery consulta,consulta2;
    QString diplo,modalidad;
    int i;

    consulta.exec("select id_diplomado from diplo_temp where descripcion='"+reg_modulos.diplomado->currentText()+"'");
    while(consulta.next())
    {
        diplo=consulta.value(0).toString();
    }

    if(!consulta.exec("insert into modulos_diplomado values('"+diplo+"','"+reg_modulos.modulo->currentText()+"','"+reg_modulos.nombre->text()+"','"+reg_modulos.facilitador->text()+"','"+reg_modulos.duracion->text()+"','"+reg_modulos.clases->text()+"')"))
        QMessageBox::critical(0,"Error Guardar Modulo",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        for(i=0;i<reg_modulos.clases->text().toInt();i++)
        {
            if(!consulta2.exec("insert into calendario_modulos values('"+reg_modulos.modulo->currentText()+"','"+diplo+"','"+reg_modulos.cohorte->currentText()+"',to_date('"+inicios->at(i)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'))"))//Fechas de la tabla
                QMessageBox::critical(0,"Error Fechas Modulo 1",consulta.lastError().text());
            else
                consulta2.exec("commit");
        }
    }
}


void procesos_ces::actualizarModulo()
{
    QSqlQuery consulta,consulta2;
    QString diplo,modalidad;
    int i;

    consulta.exec("select id_diplomado from diplo_temp where descripcion='"+reg_modulos.diplomado->currentText()+"'");
    while(consulta.next())
    {
        diplo=consulta.value(0).toString();
    }

    if(!consulta.exec("update modulos_diplomado set descripcion='"+reg_modulos.nombre->text()+"',facilitador='"+reg_modulos.facilitador->text()+"',duracion='"+reg_modulos.duracion->text()+"',num_clases='"+reg_modulos.clases->text()+"' where id_diplomado='"+diplo+"' and modulo='"+reg_modulos.modulo->currentText()+"'"))
        QMessageBox::critical(0,"Error Actualizar Modulo",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        if(consulta2.exec("delete from calendario_modulos where id_diplomado='"+diplo+"' and id_cohorte='"+reg_modulos.cohorte->currentText()+"'"))
        {
            for(i=0;i<reg_modulos.clases->text().toInt();i++)
            {
                if(!consulta2.exec("insert into calendario_modulos values('"+reg_modulos.modulo->currentText()+"','"+diplo+"','"+reg_modulos.cohorte->currentText()+"',to_date('"+inicios->at(i)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'))"))//Fechas de la tabla
                    QMessageBox::critical(0,"Error Fechas Modulo 2",consulta.lastError().text());
                else
                    consulta2.exec("commit");
            }
        }
        else
            QMessageBox::information(0,"Error Actualizar Fechas",consulta2.lastError().text());
    }
}


void procesos_ces::registroCertificacion()
{
    frame = new QFrame();
    reg_diplomado.setupUi(frame);
    container.workspace->setWidget(frame);

    disconnect(container.botonNuevo,SIGNAL(clicked()),0,0);
    disconnect(container.botonAnular,SIGNAL(clicked()),0,0);
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevaCertificacion()));
    container.botonNuevo->setEnabled(true);
    connect(reg_diplomado.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarCertificacion(int,int)));
    reg_diplomado.label->setText("Programas de Certificación");
    reg_diplomado.tabla->clear();
    reg_diplomado.tabla->setColumnCount(4);
    reg_diplomado.tabla->setColumnWidth(0,100);
    reg_diplomado.tabla->setColumnWidth(1,400);
    reg_diplomado.tabla->setColumnWidth(2,40);
    reg_diplomado.tabla->setColumnWidth(3,400);
    reg_diplomado.tabla->setHorizontalHeaderLabels(QStringList() << "Codigo "<< "Programa"<< "Horas"<< "Coordinador");

    llenarCerti();
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarCertificacion()));
    container.botonAnular->setEnabled(true);
}

void procesos_ces::llenarCerti()
{
    QSqlQuery consulta;
    int row,i;
    QTableWidgetItem *ni;

    for(i=reg_diplomado.tabla->rowCount()-1;i>=0;i--)
        reg_diplomado.tabla->removeRow(i);

    consulta.exec("select id_certi,descripcion,horas,coordinador from diplo_certi order by descripcion");
    while(consulta.next())
    {
        row = reg_diplomado.tabla->rowCount();
        reg_diplomado.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_diplomado.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_diplomado.tabla->setItem(row,1,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        reg_diplomado.tabla->setItem(row,2,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        reg_diplomado.tabla->setItem(row,3,ni);
    }
}

void procesos_ces::nuevaCertificacion()
{
    int row = reg_diplomado.tabla->rowCount();
    reg_diplomado.tabla->insertRow(row);

    lines = new QList<QLineEdit*>();
    lines->append(new QLineEdit());
    reg_diplomado.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit());
    reg_diplomado.tabla->setCellWidget(row,1,lines->last());
    lines->append(new QLineEdit());
    reg_diplomado.tabla->setCellWidget(row,2,lines->last());
    lines->append(new QLineEdit());
    reg_diplomado.tabla->setCellWidget(row,3,lines->last());

    reg_diplomado.tabla->scrollToItem(reg_diplomado.tabla->item(row,0),QAbstractItemView::EnsureVisible);
    connect(reg_diplomado.tabla->cellWidget(row,3),SIGNAL(returnPressed()),this,SLOT(guardarCertificacion()));
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarCertificacion()));
    container.botonGuardar->setEnabled(true);
    connect(reg_diplomado.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_diplomado.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_diplomado.tabla->cellWidget(row,3),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    reg_diplomado.tabla->setCurrentCell(row,0);
}


void procesos_ces::guardarCertificacion()
{
    QSqlQuery consulta,consulta2;
    QString cuota;
    int i;
    if(consulta.exec("insert into diplo_certi values('"+lines->at(0)->text()+"','"+lines->at(1)->text()+"','"+lines->at(2)->text()+"','"+lines->at(3)->text()+"','','')"))
    {
        container.botonGuardar->setEnabled(false);
        consulta.exec("commit");
        llenarCerti();
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::editarCertificacion(int row, int column)
{
    updating= reg_diplomado.tabla->item(row,0)->text();
    llenarCerti();
    lines = new QList<QLineEdit*>();

    lines->append(new QLineEdit(reg_diplomado.tabla->item(row,0)->text()));
    reg_diplomado.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit(reg_diplomado.tabla->item(row,1)->text()));
    reg_diplomado.tabla->setCellWidget(row,1,lines->last());
    lines->append(new QLineEdit(reg_diplomado.tabla->item(row,2)->text()));
    reg_diplomado.tabla->setCellWidget(row,2,lines->last());
    lines->append(new QLineEdit(reg_diplomado.tabla->item(row,3)->text()));
    reg_diplomado.tabla->setCellWidget(row,3,lines->last());

    connect(reg_diplomado.tabla->cellWidget(row,6),SIGNAL(returnPressed()),this,SLOT(actualizarCertificacion()));
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarCertificacion()));
    container.botonGuardar->setEnabled(true);

    connect(reg_diplomado.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_diplomado.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_diplomado.tabla->cellWidget(row,3),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}

void procesos_ces::actualizarCertificacion()
{
    QSqlQuery consulta;

    if(consulta.exec("update diplo_certi set id_certi='"+lines->at(0)->text()+"', descripcion='"+lines->at(1)->text()+"',horas='"+lines->at(2)->text()+"',coordinador='"+lines->at(3)->text()+"' where id_certi='"+updating+"'"))
    {
        consulta.exec("commit");
        container.botonGuardar->setEnabled(false);
        llenarCerti();
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}

void procesos_ces::borrarCertificacion()
{
    int row= reg_diplomado.tabla->currentRow();
    if(row>=0)
    {
        QSqlQuery consulta;
        if(consulta.exec("delete from diplo_certi where id_certi='"+reg_diplomado.tabla->item(row,0)->text()+"'"))
        {
            reg_diplomado.tabla->removeRow(row);
            consulta.exec("commit");
        }
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");

}

void procesos_ces::registroCohortesCerti()
{
    QSqlQuery consulta;
    frame = new QFrame();
    reg_cohorte.setupUi(frame);
    container.workspace->setWidget(frame);
    reg_cohorte.tabla->clear();
    reg_cohorte.tabla->setColumnCount(8);
    reg_cohorte.tabla->setHorizontalHeaderLabels(QStringList() << "Codigo "<< "Horas"<< "Participantes"<< "Inversion"<< "Cancelado"<< "Restante"<< "Ciudad"<< "Status");
    reg_cohorte.tabla->setColumnWidth(0,100);
    reg_cohorte.tabla->setColumnWidth(1,90);
    reg_cohorte.tabla->setColumnWidth(2,90);
    reg_cohorte.tabla->setColumnWidth(3,100);
    reg_cohorte.tabla->setColumnWidth(4,100);
    reg_cohorte.tabla->setColumnWidth(5,100);
    reg_cohorte.tabla->setColumnWidth(6,100);
    reg_cohorte.tabla->setColumnWidth(7,80);

    reg_cohorte.diplomado->addItem("-");
    reg_cohorte.label_2->setText("Código Programa");
    consulta.exec("select descripcion from diplo_certi order by descripcion");
    while(consulta.next())
    {
        reg_cohorte.diplomado->addItem(consulta.value(0).toString());
    }
    connect(reg_cohorte.diplomado,SIGNAL(currentIndexChanged(QString)),this,SLOT(llenarCohortesC(QString)));
    connect(reg_cohorte.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarCohorteC(int,int)));
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevaCohorteC()));
    container.botonNuevo->setEnabled(true);
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarCohorteC()));
    container.botonAnular->setEnabled(true);
}


void procesos_ces::llenarCohortesC(QString s)
{
    QSqlQuery consulta,consulta2,consulta3;
    int i,row;
    QTableWidgetItem *ni;
    for(i=reg_cohorte.tabla->rowCount()-1;i>=0;i--)
        reg_cohorte.tabla->removeRow(i);

    consulta.exec("select id_certi,horas from diplo_certi where descripcion='"+s+"'");
    while(consulta.next())
    {
        reg_cohorte.codigo->setText(consulta.value(0).toString());
        consulta2.exec("select id,cant,monto,pagado,restante,status,ciudad from cohorte_certi where id_certi='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            row = reg_cohorte.tabla->rowCount();
            reg_cohorte.tabla->insertRow(row);
            ni = new QTableWidgetItem(consulta2.value(0).toString());
            reg_cohorte.tabla->setItem(row,0,ni);
            ni = new QTableWidgetItem(consulta.value(1).toString());
            reg_cohorte.tabla->setItem(row,1,ni);
            ni = new QTableWidgetItem(consulta2.value(1).toString());
            reg_cohorte.tabla->setItem(row,2,ni);
            ni = new QTableWidgetItem(consulta2.value(2).toString());
            reg_cohorte.tabla->setItem(row,3,ni);
            ni = new QTableWidgetItem(consulta2.value(3).toString());
            reg_cohorte.tabla->setItem(row,4,ni);
            ni = new QTableWidgetItem(consulta2.value(4).toString());
            reg_cohorte.tabla->setItem(row,5,ni);
            ni = new QTableWidgetItem(consulta2.value(6).toString());
            reg_cohorte.tabla->setItem(row,6,ni);
            consulta3.exec("select descripcion from status where id='"+consulta2.value(5).toString()+"'");
            while(consulta3.next())
            {
                ni = new QTableWidgetItem(consulta3.value(0).toString());
                reg_cohorte.tabla->setItem(row,7,ni);
            }
        }
    }
    reg_cohorte.tabla->scrollToItem(reg_cohorte.tabla->item(row,0),QAbstractItemView::EnsureVisible);
}

void procesos_ces::nuevaCohorteC()
{
    QComboBox *aux;
    //QSqlQuery consulta;
    lines = new QList<QLineEdit*>();
    combos = new QList<QComboBox*>();
    int row = reg_cohorte.tabla->rowCount();
    reg_cohorte.tabla->insertRow(row);
    lines->append(new QLineEdit());
    reg_cohorte.tabla->setCellWidget(row,0,lines->last()); //0
    lines->append(new QLineEdit());
    reg_cohorte.tabla->setCellWidget(row,2,lines->last()); //1
    lines->append(new QLineEdit());
    reg_cohorte.tabla->setCellWidget(row,3,lines->last()); //2
    //lines->append(new QLineEdit());
    //reg_cohorte.tabla->setCellWidget(row,4,lines->last());
    lines->append(new QLineEdit());
    reg_cohorte.tabla->setCellWidget(row,6,lines->last()); //3
    aux= new QComboBox();
    aux->addItem("ABIERTA");
    aux->addItem("EN PROCESO");
    aux->addItem("HISTORICO");
    combos->append(aux);
    reg_cohorte.tabla->setCellWidget(row,7,combos->last());
    connect(reg_cohorte.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_cohorte.tabla->cellWidget(row,6),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarCohorteC()));
    container.botonGuardar->setEnabled(true);
    reg_cohorte.tabla->setCurrentCell(row,0);
}


void procesos_ces::guardarCohorteC()
{
    QSqlQuery consulta;
    QString certi,status;

    consulta.exec("select id from status where descripcion='"+combos->at(0)->currentText()+"'");
    while(consulta.next())
    {
        status=consulta.value(0).toString();
    }

    consulta.exec("select id_certi from diplo_certi where descripcion='"+reg_cohorte.diplomado->currentText()+"'");
    while(consulta.next())
    {
        certi=consulta.value(0).toString();
    }

    if(consulta.exec("insert into cohorte_certi values('"+lines->at(0)->text()+"','"+certi+"','"+lines->at(1)->text()+"','"+lines->at(2)->text()+"','0','"+lines->at(2)->text()+"','"+status+"','"+lines->at(3)->text()+"')"))
    {
        llenarCohortesC(reg_cohorte.diplomado->currentText());
        consulta.exec("commit");
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::editarCohorteC(int row, int column) //aqui martes
{
    QComboBox *aux;
    QSqlQuery consulta;

    lines = new QList<QLineEdit*>();
    combos = new QList<QComboBox*>();
    updating = reg_cohorte.tabla->item(row,0)->text();
    actual_row = row;

    lines->append(new QLineEdit(reg_cohorte.tabla->item(row,0)->text()));
    reg_cohorte.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit(reg_cohorte.tabla->item(row,2)->text()));
    reg_cohorte.tabla->setCellWidget(row,2,lines->last());
    lines->append(new QLineEdit(reg_cohorte.tabla->item(row,3)->text()));
    reg_cohorte.tabla->setCellWidget(row,3,lines->last());
    lines->append(new QLineEdit(reg_cohorte.tabla->item(row,4)->text()));
    reg_cohorte.tabla->setCellWidget(row,4,lines->last());
    lines->append(new QLineEdit(reg_cohorte.tabla->item(row,6)->text()));
    reg_cohorte.tabla->setCellWidget(row,6,lines->last());
    aux= new QComboBox();
    aux->addItem("ABIERTA");
    aux->addItem("EN PROCESO");
    aux->addItem("HISTORICO");
    aux->setCurrentIndex(aux->findText(reg_cohorte.tabla->item(row,7)->text()));
    combos->append(aux);
    reg_cohorte.tabla->setCellWidget(row,7,combos->last());

    connect(reg_cohorte.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_cohorte.tabla->cellWidget(row,6),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarCohorteC()));
    container.botonGuardar->setEnabled(true);
}

void procesos_ces::actualizarCohorteC()
{
    QSqlQuery consulta;
    QString diplo,status;

    consulta.exec("select id from status where descripcion='"+combos->at(0)->currentText()+"'");
    while(consulta.next())
    {
        status=consulta.value(0).toString();
    }

    consulta.exec("select id_certi from diplo_certi where descripcion='"+reg_cohorte.diplomado->currentText()+"'");
    while(consulta.next())
    {
        diplo=consulta.value(0).toString();
    }

    //QMessageBox::information(0,"","update cohorte_certi set id='"+lines->at(0)->text()+"', id_certi='"+diplo+"',cant='"+lines->at(1)->text()+"',monto='"+lines->at(2)->text()+"',restante='"+tr("%1").arg(reg_cohorte.tabla->item(actual_row,3)->text().toDouble()-lines->at(3)->text().toDouble())+"', status='"+status+"',ciudad='"+lines->at(4)->text()+"' where id='"+updating+"'");
    if(consulta.exec("update cohorte_certi set id='"+lines->at(0)->text()+"', id_certi='"+diplo+"',cant='"+lines->at(1)->text()+"',monto='"+lines->at(2)->text()+"',restante='"+tr("%1").arg(reg_cohorte.tabla->item(actual_row,3)->text().toDouble()-lines->at(3)->text().toDouble())+"',pagado='"+lines->at(3)->text()+"', status='"+status+"',ciudad='"+lines->at(4)->text()+"' where id='"+updating+"'"))
    {
        consulta.exec("commit");
        llenarCohortesC(reg_cohorte.diplomado->currentText());
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::borrarCohorteC()
{
    int row= reg_cohorte.tabla->currentRow();
    if(row>=0)
    {
        QSqlQuery consulta;
        if(consulta.exec("delete from cohorte_certi where id='"+reg_cohorte.tabla->item(row,0)->text()+"'"))
        {
            reg_cohorte.tabla->removeRow(row);
            consulta.exec("commit");
        }
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


void procesos_ces::registroDiplomados()
{
    frame = new QFrame();
    reg_diplomado.setupUi(frame);
    container.workspace->setWidget(frame);

    disconnect(container.botonNuevo,SIGNAL(clicked()),0,0);
    disconnect(container.botonAnular,SIGNAL(clicked()),0,0);
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoDiplomado()));
    container.botonNuevo->setEnabled(true);
    connect(reg_diplomado.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarDiplomado(int,int)));

    reg_diplomado.tabla->setColumnWidth(0,90);
    reg_diplomado.tabla->setColumnWidth(1,400);
    reg_diplomado.tabla->setColumnWidth(2,200);
    reg_diplomado.tabla->setColumnWidth(3,40);
    reg_diplomado.tabla->setColumnWidth(4,80);
    reg_diplomado.tabla->setColumnWidth(5,90);
    reg_diplomado.tabla->setColumnWidth(6,90);

    llenarDiplomados();
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarDiplomado()));
    container.botonAnular->setEnabled(true);
}


void procesos_ces::llenarDiplomados()
{
    QSqlQuery consulta;
    int row,i;
    QTableWidgetItem *ni;

    for(i=reg_diplomado.tabla->rowCount()-1;i>=0;i--)
        reg_diplomado.tabla->removeRow(i);

    consulta.exec("select id_diplomado,descripcion,coordinador,horas,modulos,minimo,maximo from diplo_temp order by descripcion");
    while(consulta.next())
    {
        row = reg_diplomado.tabla->rowCount();
        reg_diplomado.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_diplomado.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_diplomado.tabla->setItem(row,1,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        reg_diplomado.tabla->setItem(row,2,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        reg_diplomado.tabla->setItem(row,3,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(4).toString()));
        reg_diplomado.tabla->setItem(row,4,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(5).toString()));
        reg_diplomado.tabla->setItem(row,5,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(6).toString()));
        reg_diplomado.tabla->setItem(row,6,ni);
    }
}


void procesos_ces::nuevoDiplomado()
{
    int row = reg_diplomado.tabla->rowCount();
    reg_diplomado.tabla->insertRow(row);

    lines = new QList<QLineEdit*>();

    lines->append(new QLineEdit());
    reg_diplomado.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit());
    reg_diplomado.tabla->setCellWidget(row,1,lines->last());
    lines->append(new QLineEdit());
    reg_diplomado.tabla->setCellWidget(row,2,lines->last());
    lines->append(new QLineEdit());
    reg_diplomado.tabla->setCellWidget(row,3,lines->last());
    lines->append(new QLineEdit());
    reg_diplomado.tabla->setCellWidget(row,4,lines->last());
    lines->append(new QLineEdit());
    reg_diplomado.tabla->setCellWidget(row,5,lines->last());
    lines->append(new QLineEdit());
    reg_diplomado.tabla->setCellWidget(row,6,lines->last());

    reg_diplomado.tabla->scrollToItem(reg_diplomado.tabla->item(row,0),QAbstractItemView::EnsureVisible);
    connect(reg_diplomado.tabla->cellWidget(row,6),SIGNAL(returnPressed()),this,SLOT(guardarDiplomado()));
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarDiplomado()));
    container.botonGuardar->setEnabled(true);
    connect(reg_diplomado.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_diplomado.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_diplomado.tabla->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    reg_diplomado.tabla->setCurrentCell(row,0);
}


void procesos_ces::guardarDiplomado()
{
    QSqlQuery consulta,consulta2;
    QString cuota;
    int i;
    if(consulta.exec("insert into diplo_temp values('"+lines->at(0)->text()+"','"+lines->at(1)->text()+"','"+lines->at(3)->text()+"','"+lines->at(2)->text()+"','"+lines->at(4)->text()+"','V','0','"+lines->at(5)->text()+"','"+lines->at(6)->text()+"','','')"))
    {
        container.botonGuardar->setEnabled(false);
        consulta.exec("commit");
        llenarDiplomados();

        for(i=0;i<lines->at(4)->text().toInt();i++)
        {
            if(!consulta2.exec("insert into modulos_diplomado values('"+lines->at(0)->text()+"','"+tr("%1").arg(i+1)+"','','','','')"))
                QMessageBox::critical(0,"Error Modulos Diplomado",consulta2.lastError().text());
            else
                consulta.exec("commit");
        }
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::editarDiplomado(int row,int column)
{
    updating= reg_diplomado.tabla->item(row,0)->text();
    llenarDiplomados();
    QString date;
    lines = new QList<QLineEdit*>();

    lines->append(new QLineEdit(reg_diplomado.tabla->item(row,0)->text()));
    reg_diplomado.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit(reg_diplomado.tabla->item(row,1)->text()));
    reg_diplomado.tabla->setCellWidget(row,1,lines->last());
    lines->append(new QLineEdit(reg_diplomado.tabla->item(row,2)->text()));
    reg_diplomado.tabla->setCellWidget(row,2,lines->last());
    lines->append(new QLineEdit(reg_diplomado.tabla->item(row,3)->text()));
    reg_diplomado.tabla->setCellWidget(row,3,lines->last());
    lines->append(new QLineEdit(reg_diplomado.tabla->item(row,4)->text()));
    reg_diplomado.tabla->setCellWidget(row,4,lines->last());
    lines->append(new QLineEdit(reg_diplomado.tabla->item(row,5)->text()));
    reg_diplomado.tabla->setCellWidget(row,5,lines->last());
    lines->append(new QLineEdit(reg_diplomado.tabla->item(row,6)->text()));
    reg_diplomado.tabla->setCellWidget(row,6,lines->last());

    connect(reg_diplomado.tabla->cellWidget(row,6),SIGNAL(returnPressed()),this,SLOT(actualizarDiplomados()));
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarDiplomados()));
    container.botonGuardar->setEnabled(true);

    connect(reg_diplomado.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_diplomado.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_diplomado.tabla->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_ces::actualizarDiplomados()
{
    QSqlQuery consulta,consulta2;
    QString cuota;

    if(consulta.exec("update diplo_temp set id_diplomado='"+lines->at(0)->text()+"', descripcion='"+lines->at(1)->text()+"',horas='"+lines->at(3)->text()+"',coordinador='"+lines->at(2)->text()+"',modulos='"+lines->at(4)->text()+"',minimo='"+lines->at(5)->text()+"',maximo='"+lines->at(6)->text()+"' where id_diplomado='"+updating+"'"))
    {
        consulta.exec("commit");
        container.botonGuardar->setEnabled(false);
            /*for(i=0;i<lines->at(4)->text().toInt();i++)
            {
                    if(!consulta2.exec("insert into modulos_diplomado values('"+lines->at(0)->text()+"','"+tr("%1").arg(i+1)+"','','','','')"))
                            QMessageBox::critical(0,"Error Modulos Diplomado",consulta2.lastError().text());
                    else
                            consulta.exec("commit");
            }*/
        llenarDiplomados();
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::borrarDiplomado()
{
    int row= reg_diplomado.tabla->currentRow();
    if(row>=0)
    {
        QSqlQuery consulta;
        if(consulta.exec("delete from diplo_temp where id_diplomado='"+reg_diplomado.tabla->item(row,0)->text()+"'"))
        {
            consulta.exec("delete from calendario_cfp where diplomado='"+reg_diplomado.tabla->item(row,0)->text()+"'");
            consulta.exec("delete from modulos_diplomado where diplomado='"+reg_diplomado.tabla->item(row,0)->text()+"'");
            reg_diplomado.tabla->removeRow(row);
            consulta.exec("commit");
        }
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


void procesos_ces::registroCohortes()
{
    QSqlQuery consulta;
    frame = new QFrame();
    reg_cohorte.setupUi(frame);
    container.workspace->setWidget(frame);

    reg_cohorte.tabla->setColumnWidth(1,300);
    reg_cohorte.tabla->setColumnWidth(2,200);
    reg_cohorte.tabla->setColumnWidth(3,100);
    reg_cohorte.tabla->setColumnWidth(4,100);
    reg_cohorte.tabla->setColumnWidth(6,90);
    reg_cohorte.tabla->setColumnWidth(7,90);
    reg_cohorte.tabla->setColumnWidth(8,90);
    reg_cohorte.tabla->setColumnWidth(9,90);
    reg_cohorte.tabla->setColumnWidth(10,90);
    reg_cohorte.tabla->setColumnWidth(11,90);
    reg_cohorte.tabla->setColumnWidth(12,80);
    reg_cohorte.diplomado->addItem("-");
    consulta.exec("select descripcion from diplo_temp order by descripcion");
    while(consulta.next())
    {
        reg_cohorte.diplomado->addItem(consulta.value(0).toString());
    }
    connect(reg_cohorte.diplomado,SIGNAL(currentIndexChanged(QString)),this,SLOT(llenarCohortes(QString)));
    connect(reg_cohorte.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarCohorte(int,int)));
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevaCohorte()));
    container.botonNuevo->setEnabled(true);
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarCohorte()));
    container.botonAnular->setEnabled(true);
}


void procesos_ces::llenarCohortes(QString s)
{
    QSqlQuery consulta,consulta2;
    int i,row;
    QTableWidgetItem *ni;
    for(i=reg_cohorte.tabla->rowCount()-1;i>=0;i--)
        reg_cohorte.tabla->removeRow(i);
    consulta.exec("select id_diplomado from diplo_temp where descripcion='"+s+"'");
    while(consulta.next())
    {
        reg_cohorte.codigo->setText(consulta.value(0).toString());
        consulta.exec("select id,id_horario,id_modalidad,cohorte,cant_actual,costo,inicial,cuotas,costo_cuota,to_char(fecha_ini,'dd-mm-yyyy'),to_char(fecha_fin,'dd-mm-yyyy'),status,ciudad from cohortes where id_diplomado='"+consulta.value(0).toString()+"'");
        while(consulta.next())
        {
            row = reg_cohorte.tabla->rowCount();
            reg_cohorte.tabla->insertRow(row);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
            reg_cohorte.tabla->setItem(row,0,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
            reg_cohorte.tabla->setItem(row,2,ni);
            consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(2).toString()+"'");
            while(consulta2.next())
            {
                ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
                reg_cohorte.tabla->setItem(row,1,ni);
            }
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
            reg_cohorte.tabla->setItem(row,3,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(12).toString()));
            reg_cohorte.tabla->setItem(row,4,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(4).toString()));
            reg_cohorte.tabla->setItem(row,5,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(5).toString()));
            reg_cohorte.tabla->setItem(row,6,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(6).toString()));
            reg_cohorte.tabla->setItem(row,7,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(7).toString()));
            reg_cohorte.tabla->setItem(row,8,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(8).toString()));
            reg_cohorte.tabla->setItem(row,9,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(9).toString()));
            reg_cohorte.tabla->setItem(row,10,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(10).toString()));
            reg_cohorte.tabla->setItem(row,11,ni);
            consulta2.exec("select descripcion from status where id='"+consulta.value(11).toString()+"'");
            while(consulta2.next())
            {
                ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
                reg_cohorte.tabla->setItem(row,12,ni);
            }
        }
    }
    reg_cohorte.tabla->scrollToItem(reg_cohorte.tabla->item(row,0),QAbstractItemView::EnsureVisible);
}


void procesos_ces::nuevaCohorte()
{
    QComboBox *aux;
    QSqlQuery consulta;
    combos = new QList<QComboBox*>();
    lines = new QList<QLineEdit*>();
    inicios = new QList<QDateEdit*>();
    int row = reg_cohorte.tabla->rowCount();
    reg_cohorte.tabla->insertRow(row);
    lines->append(new QLineEdit());
    reg_cohorte.tabla->setCellWidget(row,0,lines->last());//0
    aux=new QComboBox();
    aux->addItem("-");
    consulta.exec("select descripcion from modalidades order by descripcion");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    combos->append(aux);
    reg_cohorte.tabla->setCellWidget(row,1,combos->last()); //0
    lines->append(new QLineEdit());
    reg_cohorte.tabla->setCellWidget(row,3,lines->last()); //1
    lines->append(new QLineEdit());
    reg_cohorte.tabla->setCellWidget(row,4,lines->last()); //2
    lines->append(new QLineEdit());
    reg_cohorte.tabla->setCellWidget(row,6,lines->last()); //3
    lines->append(new QLineEdit());
    reg_cohorte.tabla->setCellWidget(row,7,lines->last()); //4
    lines->append(new QLineEdit());
    reg_cohorte.tabla->setCellWidget(row,8,lines->last()); //5
    lines->append(new QLineEdit());
    reg_cohorte.tabla->setCellWidget(row,9,lines->last()); //6
    inicios->append(new QDateEdit());
    reg_cohorte.tabla->setCellWidget(row,10,inicios->last()); //0
    inicios->append(new QDateEdit());
    reg_cohorte.tabla->setCellWidget(row,11,inicios->last()); //1
    aux=new QComboBox();
    aux->addItem("ABIERTA");
    aux->addItem("EN PROCESO");
    aux->addItem("HISTORICO");
    combos->append(aux);
    reg_cohorte.tabla->setCellWidget(row,12,combos->last()); //1
    connect(reg_cohorte.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_cohorte.tabla->cellWidget(row,1),SIGNAL(currentIndexChanged(QString)),this,SLOT(modalidadChanged2(QString)));
    connect(reg_cohorte.tabla->cellWidget(row,4),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarCohorte()));
    container.botonGuardar->setEnabled(true);
    reg_cohorte.tabla->setCurrentCell(row,0);
}


void procesos_ces::modalidadChanged2(QString s)
{
    QSqlQuery consulta;
    QComboBox *aux;
    QString modalidad;

    int row=reg_cohorte.tabla->currentRow();
    consulta.exec("select id_modalidad from modalidades where descripcion='"+s+"'");
    while(consulta.next())
    {
        modalidad=consulta.value(0).toString();
    }
    aux=new QComboBox();
    aux->addItem("-");

    consulta.exec("select to_char(hora,'HH12:MI AM'),to_char(hora_fin,'HH12:MI AM') from horarios where modalidad='"+modalidad+"'");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString()+"-"+consulta.value(1).toString());
    }

    if(combos->size()==3)
        combos->removeLast();
    combos->append(aux);
    reg_cohorte.tabla->setCellWidget(row,2,combos->last());
}


void procesos_ces::guardarCohorte()
{
    QSqlQuery consulta;
    QString modalidad,diplo,cuota,status;
    int i;

    consulta.exec("select id from status where descripcion='"+combos->at(1)->currentText()+"'");
    while(consulta.next())
    {
        status=consulta.value(0).toString();
    }

    consulta.exec("select id_diplomado from diplo_temp where descripcion='"+reg_cohorte.diplomado->currentText()+"'");
    while(consulta.next())
    {
        diplo=consulta.value(0).toString();
    }

    consulta.exec("select id_modalidad from modalidades where descripcion='"+combos->at(0)->currentText()+"'");
    while(consulta.next())
    {
        modalidad=consulta.value(0).toString();
    }

    if(consulta.exec("insert into cohortes values('"+lines->at(0)->text()+"','"+diplo+"','"+combos->at(2)->currentText()+"','"+modalidad+"','"+lines->at(1)->text()+"','0',to_date('"+inicios->at(0)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),to_date('"+inicios->at(1)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+lines->at(3)->text()+"','"+lines->at(4)->text()+"','"+lines->at(6)->text()+"','"+lines->at(5)->text()+"','"+status+"','"+lines->at(2)->text()+"')"))
    {
        llenarCohortes(reg_cohorte.diplomado->currentText());
        consulta.exec("commit");
        for(i=0;i<lines->at(5)->text().toInt();i++)
        {
            cuota.setNum(i+1);
            if(!consulta.exec("insert into calendario_cfp values('"+diplo+"',to_date('01-01-2000','dd-mm-yyyy'),'"+cuota+"','"+lines->at(0)->text()+"')"))
                QMessageBox::critical(0,"Error Calendario Pago",consulta.lastError().text());
            else
                consulta.exec("commit");
        }
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::editarCohorte(int row,int column)
{
    QComboBox *aux;
    QSqlQuery consulta;
    combos = new QList<QComboBox*>();
    lines = new QList<QLineEdit*>();
    inicios = new QList<QDateEdit*>();
    updating = reg_cohorte.tabla->item(row,0)->text();

    lines->append(new QLineEdit(reg_cohorte.tabla->item(row,0)->text()));
    reg_cohorte.tabla->setCellWidget(row,0,lines->last());
    aux=new QComboBox();
    consulta.exec("select descripcion from modalidades order by descripcion");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }

    aux->setCurrentIndex(aux->findText(reg_cohorte.tabla->item(row,1)->text()));
    combos->append(aux);
    reg_cohorte.tabla->setCellWidget(row,1,combos->last());
    lines->append(new QLineEdit(reg_cohorte.tabla->item(row,3)->text()));
    reg_cohorte.tabla->setCellWidget(row,3,lines->last());
    lines->append(new QLineEdit(reg_cohorte.tabla->item(row,4)->text()));
    reg_cohorte.tabla->setCellWidget(row,4,lines->last());
    lines->append(new QLineEdit(reg_cohorte.tabla->item(row,6)->text()));
    reg_cohorte.tabla->setCellWidget(row,6,lines->last());
    lines->append(new QLineEdit(reg_cohorte.tabla->item(row,7)->text()));
    reg_cohorte.tabla->setCellWidget(row,7,lines->last());
    lines->append(new QLineEdit(reg_cohorte.tabla->item(row,8)->text()));
    reg_cohorte.tabla->setCellWidget(row,8,lines->last());
    lines->append(new QLineEdit(reg_cohorte.tabla->item(row,9)->text()));
    reg_cohorte.tabla->setCellWidget(row,9,lines->last());
    inicios->append(new QDateEdit(QDate::fromString(reg_cohorte.tabla->item(row,10)->text(),"dd-MM-yyyy")));
    reg_cohorte.tabla->setCellWidget(row,10,inicios->last());
    inicios->append(new QDateEdit(QDate::fromString(reg_cohorte.tabla->item(row,11)->text(),"dd-MM-yyyy")));
    reg_cohorte.tabla->setCellWidget(row,11,inicios->last());
    aux=new QComboBox();
    aux->addItem("ABIERTA");
    aux->addItem("EN PROCESO");
    aux->addItem("HISTORICO");
    aux->setCurrentIndex(aux->findText(reg_cohorte.tabla->item(row,12)->text()));
    combos->append(aux);
    reg_cohorte.tabla->setCellWidget(row,12,combos->last());
    connect(reg_cohorte.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_cohorte.tabla->cellWidget(row,1),SIGNAL(currentIndexChanged(QString)),this,SLOT(modalidadChanged2(QString)));
    connect(reg_cohorte.tabla->cellWidget(row,4),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarCohorte()));
    container.botonGuardar->setEnabled(true);
}


void procesos_ces::actualizarCohorte()
{
    QSqlQuery consulta;
    QString modalidad,diplo,cuota,status;
    int cuotas,i;
    cuotas=0;

    consulta.exec("select id from status where descripcion='"+combos->at(1)->currentText()+"'");
    while(consulta.next())
    {
        status=consulta.value(0).toString();
    }
    consulta.exec("select cuotas from cohortes where id='"+updating+"'");
    while(consulta.next())
    {
        cuotas=consulta.value(0).toInt();
    }
    consulta.exec("select id_diplomado from diplo_temp where descripcion='"+reg_cohorte.diplomado->currentText()+"'");
    while(consulta.next())
    {
        diplo=consulta.value(0).toString();
    }
    consulta.exec("select id_modalidad from modalidades where descripcion='"+combos->at(0)->currentText()+"'");
    while(consulta.next())
    {
        modalidad=consulta.value(0).toString();
    }
    if(combos->size()<3)
        consulta.prepare("update cohortes set id='"+lines->at(0)->text()+"', id_diplomado='"+diplo+"',id_modalidad='"+modalidad+"',cohorte='"+lines->at(1)->text()+"',fecha_ini=to_date('"+inicios->at(0)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),fecha_fin=to_date('"+inicios->at(1)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),costo='"+lines->at(3)->text()+"',inicial='"+lines->at(4)->text()+"',costo_cuota='"+lines->at(6)->text()+"',cuotas='"+lines->at(5)->text()+"',status='"+status+"',ciudad='"+lines->at(2)->text()+"' where id='"+updating+"'");
    else
        consulta.prepare("update cohortes set id='"+lines->at(0)->text()+"', id_diplomado='"+diplo+"',id_modalidad='"+modalidad+"',id_horario='"+combos->at(2)->currentText()+"',cohorte='"+lines->at(1)->text()+"',fecha_ini=to_date('"+inicios->at(0)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),fecha_fin=to_date('"+inicios->at(1)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),costo='"+lines->at(3)->text()+"',inicial='"+lines->at(4)->text()+"',costo_cuota='"+lines->at(6)->text()+"',cuotas='"+lines->at(5)->text()+"',status='"+status+"',ciudad='"+lines->at(2)->text()+"' where id='"+updating+"'");
    if(consulta.exec())
    {
        llenarCohortes(reg_cohorte.diplomado->currentText());
        consulta.exec("commit");
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());

    if(lines->at(5)->text().toInt()>cuotas)
    {
        for(i=cuotas;i<lines->at(5)->text().toInt();i++)
        {
            cuota.setNum(i+1);
            if(!consulta.exec("insert into calendario_cfp values('"+diplo+"',to_date('01-01-2000','dd-mm-yyyy'),'"+cuota+"','"+lines->at(0)->text()+"')"))
                QMessageBox::critical(0,"Error Calendario Pago",consulta.lastError().text());
            else
                consulta.exec("commit");
        }
    }
    else// if(cuotas>lines->at(4)->text().toInt())
    {
        for(i=cuotas;i>lines->at(5)->text().toInt();i--)
        {
            cuota.setNum(i);
            if(!consulta.exec("delete calendario_cfp where cuota='"+cuota+"' and diplomado='"+diplo+"' and cohorte='"+lines->at(0)->text()+"'"))
                QMessageBox::critical(0,"Error Calendario Pago",consulta.lastError().text());
            else
                consulta.exec("commit");
        }
    }
}


void procesos_ces::borrarCohorte()
{
    int row= reg_cohorte.tabla->currentRow();
    if(row>=0)
    {
        QSqlQuery consulta;
        if(consulta.exec("delete from cohortes where id='"+reg_cohorte.tabla->item(row,0)->text()+"'"))
        {
            reg_cohorte.tabla->removeRow(row);
            consulta.exec("commit");
        }
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


void procesos_ces::cerrarDiplomado()
{
    estudianteFrame->close();
}


void procesos_ces::registroModalidades()
{
    frame = new QFrame();
    reg_modalidad.setupUi(frame);
    container.workspace->setWidget(frame);
    connect(reg_modalidad.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarModalidad(int,int)));
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevaModalidad()));
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarModalidad()));
    container.botonGuardar->setEnabled(false);
    container.botonAnular->setEnabled(true);
    container.botonNuevo->setEnabled(true);
    reg_modalidad.tabla->setColumnWidth(0,60);
    reg_modalidad.tabla->setColumnWidth(1,150);

    llenarModalidad();
}


void procesos_ces::llenarModalidad()
{
    QSqlQuery consulta;
    QTableWidgetItem *ni;
    int i,row;
    for(i=reg_modalidad.tabla->rowCount()-1;i>=0;i--)
        reg_modalidad.tabla->removeRow(i);

    consulta.exec("select * from modalidades order by id_modalidad");
    while(consulta.next())
    {
        row = reg_modalidad.tabla->rowCount();
        reg_modalidad.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_modalidad.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_modalidad.tabla->setItem(row,1,ni);
    }
}


void procesos_ces::nuevaModalidad()
{
    int row;
    row=reg_modalidad.tabla->rowCount();
    reg_modalidad.tabla->insertRow(row);

    lines= new QList<QLineEdit*>();
    lines->append(new QLineEdit());
    reg_modalidad.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit());
    reg_modalidad.tabla->setCellWidget(row,1,lines->last());

    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarModalidad()));
    container.botonGuardar->setEnabled(true);
    connect(reg_modalidad.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_modalidad.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    reg_modalidad.tabla->setCurrentCell(row,0);
}


void procesos_ces::borrarModalidad()
{
    QSqlQuery consulta;
    int row= reg_modalidad.tabla->currentRow();
    if(row>=0)
    {
        if(!consulta.exec("delete from horarios where modalidad='"+reg_modalidad.tabla->item(row,0)->text()+"'"))
            QMessageBox::critical(0,"Error Borrar Horarios",consulta.lastError().text());
        else
        {
            consulta.exec("commit");
            llenarHorarios();
        }
        if(!consulta.exec("delete from modalidades where id_modalidad='"+reg_modalidad.tabla->item(row,0)->text()+"'"))
            QMessageBox::critical(0,"Error Borrar Modalidad",consulta.lastError().text());
        else
        {
            consulta.exec("commit");
            llenarModalidad();
        }
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


void procesos_ces::editarModalidad(int row,int column)
{
    updating=reg_modalidad.tabla->item(row,0)->text();
    lines= new QList<QLineEdit*>();
    lines->append(new QLineEdit(reg_modalidad.tabla->item(row,0)->text()));
    reg_modalidad.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit(reg_modalidad.tabla->item(row,1)->text()));
    reg_modalidad.tabla->setCellWidget(row,1,lines->last());

    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarModalidad()));
    container.botonGuardar->setEnabled(true);
    connect(reg_modalidad.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_modalidad.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_ces::guardarModalidad()
{
    QSqlQuery consulta;
    if(consulta.exec("insert into modalidades values('"+lines->at(0)->text()+"','"+lines->at(1)->text()+"')"))
    {
        consulta.exec("commit");
        llenarModalidad();
        container.botonGuardar->setEnabled(false);
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::actualizarModalidad()
{
    QSqlQuery consulta;
    if(consulta.exec("update modalidades set id_modalidad='"+lines->at(0)->text()+"',descripcion='"+lines->at(1)->text()+"' where id_modalidad='"+updating+"'"))
    {
        consulta.exec("commit");
        llenarModalidad();
        container.botonGuardar->setEnabled(false);
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::registroHorarios()
{
    frame = new QFrame();
    reg_horario.setupUi(frame);
    container.workspace->setWidget(frame);
    connect(reg_horario.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarHorario(int,int)));
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoHorario()));
    container.botonNuevo->setEnabled(true);
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarHorario()));
    container.botonAnular->setEnabled(true);
    //connect(reg_horario.modalidades,SIGNAL(clicked()),this,SLOT(registroModalidades()));
    reg_horario.tabla->setColumnWidth(0,150);
    reg_horario.tabla->setColumnWidth(1,90);
    reg_horario.tabla->setColumnWidth(2,90);
    reg_horario.tabla->setColumnWidth(3,60);
    llenarHorarios();
}


void procesos_ces::llenarHorarios()
{
    QSqlQuery consulta,consulta2;
    QTableWidgetItem *ni;
    int i,row;

    for(i=reg_horario.tabla->rowCount()-1;i>=0;i--)
        reg_horario.tabla->removeRow(i);

    consulta.exec("select id_horario,to_char(hora,'HH12:MI AM'),modalidad,to_char(hora_fin,'HH12:MI AM') from horarios order by modalidad,id_horario");
    while(consulta.next())
    {
        row = reg_horario.tabla->rowCount();
        reg_horario.tabla->insertRow(row);
        consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(2).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_horario.tabla->setItem(row,0,ni);
        }
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_horario.tabla->setItem(row,1,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        reg_horario.tabla->setItem(row,2,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_horario.tabla->setItem(row,3,ni);
    }
}


void procesos_ces::editarHorario(int row,int column)
{
    QString hora;
    QComboBox *aux;
    QSqlQuery consulta;

    combos = new QList<QComboBox*>();
    lines= new QList<QLineEdit*>();
    times= new QList<QTimeEdit*>();
    aux= new QComboBox();
    consulta.exec("select descripcion from modalidades order by descripcion");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    aux->setCurrentIndex(aux->findText(reg_horario.tabla->item(row,0)->text()));
    combos->append(aux);
    reg_horario.tabla->setCellWidget(row,0,combos->last());
    times->append(new QTimeEdit(QTime::fromString(reg_horario.tabla->item(row,1)->text(),"hh:mm AP")));
    times->last()->setDisplayFormat("hh:mm AP");
    reg_horario.tabla->setCellWidget(row,1,times->last());
    times->append(new QTimeEdit(QTime::fromString(reg_horario.tabla->item(row,2)->text(),"hh:mm AP")));
    times->last()->setDisplayFormat("hh:mm AP");
    reg_horario.tabla->setCellWidget(row,2,times->last());
    lines->append(new QLineEdit(reg_horario.tabla->item(row,3)->text()));
    reg_horario.tabla->setCellWidget(row,3,lines->last());

    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarHorario()));
    container.botonGuardar->setEnabled(true);
    updating = reg_horario.tabla->item(row,3)->text();
    updating2 = reg_horario.tabla->item(row,0)->text();
    connect(reg_horario.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_horario.tabla->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_ces::nuevoHorario()
{
    QString hora;
    QComboBox *aux;
    QSqlQuery consulta;
    int row;

    row=reg_horario.tabla->rowCount();
    reg_horario.tabla->insertRow(row);

    combos = new QList<QComboBox*>();
    lines= new QList<QLineEdit*>();
    times= new QList<QTimeEdit*>();
    aux= new QComboBox();
    consulta.exec("select descripcion from modalidades order by descripcion");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    combos->append(aux);
    reg_horario.tabla->setCellWidget(row,0,combos->last());
    times->append(new QTimeEdit());
    times->last()->setDisplayFormat("hh:mm AP");
    reg_horario.tabla->setCellWidget(row,1,times->last());
    times->append(new QTimeEdit());
    times->last()->setDisplayFormat("hh:mm AP");
    reg_horario.tabla->setCellWidget(row,2,times->last());
    lines->append(new QLineEdit());
    reg_horario.tabla->setCellWidget(row,3,lines->last());

    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarHorario()));
    container.botonGuardar->setEnabled(true);
    connect(reg_horario.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_horario.tabla->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    reg_horario.tabla->setCurrentCell(row,0);
}


void procesos_ces::guardarHorario()
{
    QSqlQuery consulta;
    QString modalidad;
    consulta.exec("select id_modalidad from modalidades where descripcion ='"+combos->at(0)->currentText()+"'");
    while(consulta.next())
    {
        modalidad=consulta.value(0).toString();
    }
    if(consulta.exec("insert into horarios values('"+lines->at(0)->text()+"',to_date('"+times->at(0)->time().toString("hh:mm")+"','HH24:MI'),'"+modalidad+"',to_date('"+times->at(1)->time().toString("hh:mm")+"','HH24:MI'))"))
    {
        consulta.exec("commit");
        llenarHorarios();
        container.botonGuardar->setEnabled(false);
    }
    else
        QMessageBox::critical(0,"Error Horario",consulta.lastError().text());
}


void procesos_ces::actualizarHorario()
{
    QSqlQuery consulta;
    QString modalidad;
    consulta.exec("select id_modalidad from modalidades where descripcion ='"+updating2+"'");
    while(consulta.next())
    {
        updating2=consulta.value(0).toString();
    }
    consulta.exec("select id_modalidad from modalidades where descripcion ='"+combos->at(0)->currentText()+"'");
    while(consulta.next())
    {
        modalidad=consulta.value(0).toString();
    }
    if(consulta.exec("update horarios set id_horario='"+lines->at(0)->text()+"',hora=to_date('"+times->at(0)->time().toString("hh:mm")+"','HH24:MI'),modalidad='"+modalidad+"',hora_fin=to_date('"+times->at(1)->time().toString("hh:mm")+"','HH24:MI') where id_horario='"+updating+"' and modalidad='"+updating2+"'"))
    {
        consulta.exec("commit");
        llenarHorarios();
        container.botonGuardar->setEnabled(false);
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}

void procesos_ces::borrarHorario()
{
    int row= reg_horario.tabla->currentRow();
    QString modalidad;
    if(row>=0)
    {
        QSqlQuery consulta;
        consulta.exec("select id_modalidad from modalidades where descripcion='"+reg_horario.tabla->item(row,0)->text()+"'");
        while(consulta.next())
        {
            modalidad=consulta.value(0).toString();
        }
        if(consulta.exec("delete from horarios where modalidad='"+modalidad+"' and id_horario='"+reg_horario.tabla->item(row,3)->text()+"'"))
        {
            reg_horario.tabla->removeRow(row);
        }
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


void procesos_ces::registroMetodos()
{
    frame = new QFrame();
    reg_curso.setupUi(frame);
    container.workspace->setWidget(frame);

    QStringList programas;

    disconnect(container.botonNuevo,SIGNAL(clicked()),0,0);
    disconnect(container.botonAnular,SIGNAL(clicked()),0,0);
    disconnect(container.botonModificar,SIGNAL(clicked()),0,0);
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoMetodo()));
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarMetodo()));
    connect(container.botonModificar,SIGNAL(clicked()),this,SLOT(editarNiveles()));
    connect(reg_curso.tabla_metodo,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarMetodo(int,int)));
    container.botonNuevo->setEnabled(true);
    container.botonAnular->setEnabled(true);
    container.botonModificar->setEnabled(true);

    reg_curso.tabla_metodo->setColumnWidth(0,200);
    reg_curso.tabla_metodo->setColumnWidth(1,60);
    reg_curso.tabla_metodo->setColumnWidth(2,250);
    reg_curso.tabla_metodo->setColumnWidth(3,100);
    reg_curso.tabla_metodo->setColumnWidth(4,50);
    reg_curso.tabla_metodo->setColumnWidth(5,100);
    reg_curso.tabla_metodo->setColumnWidth(6,250);
    reg_curso.tabla_metodo->setColumnWidth(7,50);
    llenarMetodos();
}


void procesos_ces::llenarMetodos()
{
    QSqlQuery consulta,consulta2;
    int row,i;
    QTableWidgetItem *ni;

    for(i=reg_curso.tabla_metodo->rowCount()-1;i>=0;i--)
        reg_curso.tabla_metodo->removeRow(i);

    consulta.exec("select * from metodos order by id_metodo");
    while(consulta.next())
    {
        row = reg_curso.tabla_metodo->rowCount();
        reg_curso.tabla_metodo->insertRow(row);
        consulta2.exec("select descripcion from programa_academico where id='"+consulta.value(9).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_curso.tabla_metodo->setItem(row,0,ni);
        }
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_curso.tabla_metodo->setItem(row,1,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_curso.tabla_metodo->setItem(row,2,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        reg_curso.tabla_metodo->setItem(row,3,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        reg_curso.tabla_metodo->setItem(row,4,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(4).toString()));
        reg_curso.tabla_metodo->setItem(row,5,ni);
        consulta2.exec("select descripcion from calendarios where id_calendario='"+consulta.value(8).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_curso.tabla_metodo->setItem(row,6,ni);
        }
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(10).toString()));
        reg_curso.tabla_metodo->setItem(row,7,ni);
    }
}


void procesos_ces::nuevoMetodo()
{
    QSqlQuery consulta;
    QComboBox *aux;
    QStringList idiomas;
    idiomas << "N/A" << "INGLES" << "FRANCES" << "ITALIANO" << "PORTUGUES" << "ALEMAN" << "JAPONES";
    int row = reg_curso.tabla_metodo->rowCount();
    reg_curso.tabla_metodo->insertRow(row);

    lines = new QList<QLineEdit*>();
    combos = new QList<QComboBox*>();

    aux = new QComboBox();
    consulta.exec("select descripcion from programa_academico order by id");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    combos->append(aux);
    reg_curso.tabla_metodo->setCellWidget(row,0,combos->last());
    lines->append(new QLineEdit());
    reg_curso.tabla_metodo->setCellWidget(row,1,lines->last());
    lines->append(new QLineEdit());
    reg_curso.tabla_metodo->setCellWidget(row,2,lines->last());
    aux = new QComboBox();
    aux->addItems(idiomas);
    combos->append(aux);
    reg_curso.tabla_metodo->setCellWidget(row,3,combos->last());
    lines->append(new QLineEdit());
    reg_curso.tabla_metodo->setCellWidget(row,4,lines->last());
    lines->append(new QLineEdit());
    reg_curso.tabla_metodo->setCellWidget(row,5,lines->last());
    aux = new QComboBox();
    consulta.exec("select descripcion from calendarios order by descripcion");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    combos->append(aux);
    reg_curso.tabla_metodo->setCellWidget(row,6,combos->last());
    lines->append(new QLineEdit());
    reg_curso.tabla_metodo->setCellWidget(row,7,lines->last());

    connect(reg_curso.tabla_metodo->cellWidget(row,4),SIGNAL(returnPressed()),this,SLOT(guardarMetodo()));
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarMetodo()));
    container.botonGuardar->setEnabled(true);

    connect(reg_curso.tabla_metodo->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_curso.tabla_metodo->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_curso.tabla_metodo->cellWidget(row,4),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_curso.tabla_metodo->cellWidget(row,5),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    reg_curso.tabla_metodo->setCurrentCell(row,0);
}


void procesos_ces::editarMetodo(int row,int column)
{
    updating= reg_curso.tabla_metodo->item(row,1)->text();
    llenarMetodos();
    QComboBox *aux;
    QStringList idiomas;
    QSqlQuery consulta;
    idiomas << "N/A" << "INGLES" << "FRANCES" << "ITALIANO" << "JAPONES" << "ALEMAN";

    lines = new QList<QLineEdit*>();
    combos = new QList<QComboBox*>();
    aux = new QComboBox();
    consulta.exec("select descripcion from programa_academico order by id");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    aux->setCurrentIndex(aux->findText(reg_curso.tabla_metodo->item(row,0)->text()));
    combos->append(aux);
    reg_curso.tabla_metodo->setCellWidget(row,0,combos->last());
    lines->append(new QLineEdit(reg_curso.tabla_metodo->item(row,1)->text()));
    reg_curso.tabla_metodo->setCellWidget(row,1,lines->last());
    lines->append(new QLineEdit(reg_curso.tabla_metodo->item(row,2)->text()));
    reg_curso.tabla_metodo->setCellWidget(row,2,lines->last());
    aux = new QComboBox();
    aux->addItems(idiomas);
    aux->setCurrentIndex(aux->findText(reg_curso.tabla_metodo->item(row,3)->text()));
    combos->append(aux);
    reg_curso.tabla_metodo->setCellWidget(row,3,combos->last());
    lines->append(new QLineEdit(reg_curso.tabla_metodo->item(row,4)->text()));
    reg_curso.tabla_metodo->setCellWidget(row,4,lines->last());
    lines->append(new QLineEdit(reg_curso.tabla_metodo->item(row,5)->text()));
    reg_curso.tabla_metodo->setCellWidget(row,5,lines->last());
    consulta.exec("select descripcion from calendarios order by descripcion");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    aux->setCurrentIndex(aux->findText(reg_curso.tabla_metodo->item(row,6)->text()));
    combos->append(aux);
    reg_curso.tabla_metodo->setCellWidget(row,6,combos->last());
    lines->append(new QLineEdit(reg_curso.tabla_metodo->item(row,7)->text()));
    reg_curso.tabla_metodo->setCellWidget(row,7,lines->last());

    connect(reg_curso.tabla_metodo->cellWidget(row,4),SIGNAL(returnPressed()),this,SLOT(actualizarMetodo()));
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarMetodo()));
    container.botonGuardar->setEnabled(true);
    connect(reg_curso.tabla_metodo->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_curso.tabla_metodo->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_curso.tabla_metodo->cellWidget(row,4),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_curso.tabla_metodo->cellWidget(row,5),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_ces::actualizarMetodo()
{
    QSqlQuery consulta;
    QString cal,prog;
    consulta.exec("select id_calendario from calendarios where descripcion='"+combos->at(1)->currentText()+"'");
    while(consulta.next())
    {
        cal=consulta.value(0).toString();
    }
    consulta.exec("select id from programa_academico where descripcion='"+combos->at(0)->currentText()+"'");
    while(consulta.next())
    {
        prog=consulta.value(0).toString();
    }
    if(!consulta.exec("update metodos set id_metodo='"+lines->at(0)->text()+"', descripcion='"+lines->at(1)->text()+"',niveles='"+lines->at(2)->text()+"',evaluaciones='"+lines->at(3)->text()+"',id_calendario='"+cal+"',prog_academico='"+prog+"',cuotas='"+lines->at(4)->text()+"' where id_metodo='"+updating+"'"))
        QMessageBox::critical(0,"Error",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        if(!consulta.exec("update precios set item ='"+lines->at(0)->text()+"',fecha=to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy') where item='"+updating+"'"))
            QMessageBox::critical(0,"Error",consulta.lastError().text());
        else
            consulta.exec("commit");
        llenarMetodos();
        container.botonGuardar->setEnabled(false);
    }
}


void procesos_ces::guardarMetodo()
{
    QSqlQuery consulta;
    int niveles=lines->at(2)->text().toInt();
    QString nivel,cal,prog;
    consulta.exec("select id_calendario from calendarios where descripcion='"+combos->at(2)->currentText()+"'");
    while(consulta.next())
    {
        cal=consulta.value(0).toString();
    }
    consulta.exec("select id from programa_academico where descripcion='"+combos->at(0)->currentText()+"'");
    while(consulta.next())
    {
        prog=consulta.value(0).toString();
    }
    if(!consulta.exec("insert into metodos values ('"+lines->at(0)->text()+"','"+lines->at(1)->text()+"','"+combos->at(1)->currentText()+"','"+lines->at(2)->text()+"','"+lines->at(3)->text()+"','X','X','X','"+cal+"','"+prog+"','"+lines->at(4)->text()+"')"))
            QMessageBox::critical(0,"Error Metodo",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        for(int i=0;i<niveles;i++)
        {
            nivel.setNum(i+1);
            if(!consulta.exec("insert into niveles values('"+lines->at(0)->text()+"','"+nivel+"','0','0','')"))
                QMessageBox::critical(0,"Error Nivel",consulta.lastError().text());
            else
                consulta.exec("commit");
        }
        if(!consulta.exec("insert into precios values('"+lines->at(0)->text()+"','C',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'0','0','0','V')"))
            QMessageBox::critical(0,"Error Precio",consulta.lastError().text());
        else
            consulta.exec("commit");

        llenarMetodos();
        //editarNiveles();
        container.botonGuardar->setEnabled(false);
    }
}


void procesos_ces::borrarMetodo()
{
    int row= reg_curso.tabla_metodo->currentRow();
    if(row>=0)
    {
        QSqlQuery consulta;
        if(consulta.exec("delete from metodos where id_metodo='"+reg_curso.tabla_metodo->item(row,1)->text()+"'"))
        {
            consulta.exec("delete from precios where item='"+reg_curso.tabla_metodo->item(row,1)->text()+"'");
            reg_curso.tabla_metodo->removeRow(row);
        }
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


void procesos_ces::registroNiveles()
{
    frame = new QFrame();
    reg_niveles.setupUi(frame);
    container.workspace->setWidget(frame);

    QSqlQuery consulta;
    reg_niveles.metodo->addItem("-");
    consulta.exec("select descripcion from metodos order by descripcion");
    while(consulta.next())
    {
        reg_niveles.metodo->addItem(consulta.value(0).toString());
    }
    connect(reg_niveles.metodo,SIGNAL(currentIndexChanged(QString)),this,SLOT(llenarNiveles(QString)));
    disconnect(container.botonNuevo,SIGNAL(clicked()),0,0);
    disconnect(container.botonAnular,SIGNAL(clicked()),0,0);
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoNivel()));
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarNivel()));
    connect(reg_niveles.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarNivel(int,int)));
    container.botonNuevo->setEnabled(true);
    container.botonAnular->setEnabled(true);
    //container.botonModificar->setEnabled(true);

    reg_niveles.tabla->setColumnWidth(0,160);
    reg_niveles.tabla->setColumnWidth(1,160);
    reg_niveles.tabla->setColumnWidth(2,160);
}

void procesos_ces::llenarNiveles(QString s)
{
    QSqlQuery consulta;
    QString metodo;
    int row,i;
    QTableWidgetItem *ni;

    for(i=reg_niveles.tabla->rowCount()-1;i>=0;i--)
        reg_niveles.tabla->removeRow(i);

    consulta.exec("select id_metodo from metodos where descripcion='"+s+"'");
    while(consulta.next())
    {
        metodo=consulta.value(0).toString();
    }

    consulta.exec("select nivel,horas,nota_minima from niveles where id_metodo='"+metodo+"' order by nivel");
    while(consulta.next())
    {
        row = reg_niveles.tabla->rowCount();
        reg_niveles.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_niveles.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_niveles.tabla->setItem(row,1,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        reg_niveles.tabla->setItem(row,2,ni);
    }
}


void procesos_ces::nuevoNivel()
{
    int row = reg_niveles.tabla->rowCount();
    reg_niveles.tabla->insertRow(row);

    lines = new QList<QLineEdit*>();

    lines->append(new QLineEdit());
    reg_niveles.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit());
    reg_niveles.tabla->setCellWidget(row,1,lines->last());
    lines->append(new QLineEdit());
    reg_niveles.tabla->setCellWidget(row,2,lines->last());

    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarNivel()));
    container.botonGuardar->setEnabled(true);
    connect(reg_niveles.tabla->cellWidget(row,2),SIGNAL(returnPressed()),this,SLOT(guardarNivel()));
    reg_niveles.tabla->setCurrentCell(row,0);
}


void procesos_ces::guardarNivel()
{
    QString metodo;
    QSqlQuery consulta;

    consulta.exec("select id_metodo from metodos where descripcion='"+reg_niveles.metodo->currentText()+"'");
    while(consulta.next())
    {
        metodo=consulta.value(0).toString();
    }
    if(!consulta.exec("insert into niveles values('"+metodo+"','"+lines->at(0)->text()+"','"+lines->at(1)->text()+"','"+lines->at(2)->text()+"','')"))
        QMessageBox::critical(0,"Error Nuevo Nivel",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        container.botonGuardar->setEnabled(false);
        llenarNiveles(reg_niveles.metodo->currentText());
    }
}


void procesos_ces::editarNivel(int row,int column)
{
    updating= reg_niveles.tabla->item(row,0)->text();
    lines = new QList<QLineEdit*>();

    lines->append(new QLineEdit(reg_niveles.tabla->item(row,1)->text()));
    reg_niveles.tabla->setCellWidget(row,1,lines->last());
    lines->append(new QLineEdit(reg_niveles.tabla->item(row,2)->text()));
    reg_niveles.tabla->setCellWidget(row,2,lines->last());

    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarNivel()));
    container.botonGuardar->setEnabled(true);
    connect(reg_niveles.tabla->cellWidget(row,2),SIGNAL(returnPressed()),this,SLOT(actualizarNivel()));
}


void procesos_ces::actualizarNivel()
{
    QString metodo;
    QSqlQuery consulta;

    consulta.exec("select id_metodo from metodos where descripcion='"+reg_niveles.metodo->currentText()+"'");
    while(consulta.next())
    {
        metodo=consulta.value(0).toString();
    }
    if(!consulta.exec("update niveles set horas ='"+lines->at(0)->text()+"',nota_minima='"+lines->at(1)->text()+"' where id_metodo='"+metodo+"' and nivel='"+updating+"'"))
        QMessageBox::critical(0,"Error Actualizar Nivel",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        container.botonGuardar->setEnabled(false);
        llenarNiveles(reg_niveles.metodo->currentText());
    }
}





void procesos_ces::registroMat()
{
    frame = new QFrame();
    reg_mat.setupUi(frame);
    container.workspace->setWidget(frame);

    disconnect(container.botonNuevo,SIGNAL(clicked()),0,0);
    disconnect(container.botonAnular,SIGNAL(clicked()),0,0);
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoMaterial()));
    container.botonNuevo->setEnabled(true);
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarMat()));
    container.botonAnular->setEnabled(true);
    connect(reg_mat.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarMaterial(int,int)));

    reg_mat.tabla->setColumnWidth(0,80);
    reg_mat.tabla->setColumnWidth(1,50);
    reg_mat.tabla->setColumnWidth(2,300);
    reg_mat.tabla->setColumnWidth(3,80);
    reg_mat.tabla->setColumnWidth(4,60);
    reg_mat.tabla->setColumnWidth(5,60);
    llenarMateriales();
}


void procesos_ces::llenarMateriales()
{
    QSqlQuery consulta;
    int row,i;
    QTableWidgetItem *ni;

    for(i=reg_mat.tabla->rowCount()-1;i>=0;i--)
        reg_mat.tabla->removeRow(i);

    consulta.exec("select * from materiales order by id_mat");
    while(consulta.next())
    {
        row = reg_mat.tabla->rowCount();
        reg_mat.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_mat.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_mat.tabla->setItem(row,1,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        reg_mat.tabla->setItem(row,2,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        reg_mat.tabla->setItem(row,3,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(4).toString()));
        reg_mat.tabla->setItem(row,4,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(5).toString()));
        reg_mat.tabla->setItem(row,5,ni);
    }
}


void procesos_ces::guardarMaterial()
{
    QSqlQuery consulta;

    if(consulta.exec("insert into materiales values('"+lines->at(0)->text()+"','"+combos->at(0)->currentText()+"','"+lines->at(1)->text()+"','"+combos->at(1)->currentText()+"','"+lines->at(2)->text()+"','"+lines->at(3)->text()+"')"))
    {
        consulta.exec("commit");
        llenarMateriales();
        container.botonGuardar->setEnabled(false);
        if(!consulta.exec("insert into precios values('"+lines->at(0)->text()+"','"+combos->at(0)->currentText()+"',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'0','0','0','V')"))
            QMessageBox::critical(0,"Error",consulta.lastError().text());
        else
            consulta.exec("commit");
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::nuevoMaterial()
{
    QComboBox *aux;
    QSqlQuery consulta;
    int row = reg_mat.tabla->rowCount();
    reg_mat.tabla->insertRow(row);

    lines = new QList<QLineEdit*>();
    combos = new QList<QComboBox*>();

    lines->append(new QLineEdit());
    reg_mat.tabla->setCellWidget(row,0,lines->last());

    lines->append(new QLineEdit());
    reg_mat.tabla->setCellWidget(row,2,lines->last());

    aux=new QComboBox();
    consulta.exec("select abrev from tipo_material order by abrev");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    combos->append(aux);
    reg_mat.tabla->setCellWidget(row,1,combos->last());

    aux=new QComboBox();
    aux->addItem("-");
    consulta.exec("select id_metodo from metodos order by id_metodo");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    combos->append(aux);
    reg_mat.tabla->setCellWidget(row,3,combos->last());

    lines->append(new QLineEdit());
    reg_mat.tabla->setCellWidget(row,4,lines->last());

    lines->append(new QLineEdit());
    reg_mat.tabla->setCellWidget(row,5,lines->last());

    connect(reg_mat.tabla->cellWidget(row,2),SIGNAL(returnPressed()),this,SLOT(guardarMaterial()));
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarMaterial()));
    container.botonGuardar->setEnabled(true);

    connect(reg_mat.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_mat.tabla->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    reg_mat.tabla->setCurrentCell(row,0);
}


void procesos_ces::actualizarMaterial()
{
    QSqlQuery consulta;

    if(consulta.exec("update materiales set id_mat='"+lines->at(0)->text()+"',tipo='"+combos->at(0)->currentText()+"',descripcion='"+lines->at(1)->text()+"',id_curso='"+combos->at(1)->currentText()+"',evento='"+lines->at(2)->text()+"',nivel='"+lines->at(3)->text()+"' where id_mat='"+updating+"'"))
    {
        consulta.exec("commit");
        llenarMateriales();
        container.botonGuardar->setEnabled(false);
        if(!consulta.exec("update precios set item='"+lines->at(0)->text()+"',tipo_item='"+combos->at(0)->currentText()+"',fecha=to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy') where item='"+updating+"'"))
            QMessageBox::critical(0,"Error",consulta.lastError().text());
        else
            consulta.exec("commit");
    }
    else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::editarMaterial(int row,int column)
{
    QComboBox *aux;
    QSqlQuery consulta;
    int index;

    llenarMateriales();
    updating = reg_mat.tabla->item(row,0)->text();
    lines = new QList<QLineEdit*>();
    combos = new QList<QComboBox*>();

    lines->append(new QLineEdit(reg_mat.tabla->item(row,0)->text()));
    reg_mat.tabla->setCellWidget(row,0,lines->last());

    lines->append(new QLineEdit(reg_mat.tabla->item(row,2)->text()));
    reg_mat.tabla->setCellWidget(row,2,lines->last());

    aux=new QComboBox();
    consulta.exec("select abrev from tipo_material order by abrev");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    index = aux->findText(reg_mat.tabla->item(row,1)->text());
    aux->setCurrentIndex(index);
    combos->append(aux);
    reg_mat.tabla->setCellWidget(row,1,combos->last());

    aux=new QComboBox();
    aux->addItem("-");
    consulta.exec("select id_metodo from metodos order by id_metodo");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    index = aux->findText(reg_mat.tabla->item(row,3)->text());
    aux->setCurrentIndex(index);
    combos->append(aux);
    reg_mat.tabla->setCellWidget(row,3,combos->last());

    lines->append(new QLineEdit(reg_mat.tabla->item(row,4)->text()));
    reg_mat.tabla->setCellWidget(row,4,lines->last());

    lines->append(new QLineEdit(reg_mat.tabla->item(row,5)->text()));
    reg_mat.tabla->setCellWidget(row,5,lines->last());

    connect(reg_mat.tabla->cellWidget(row,2),SIGNAL(returnPressed()),this,SLOT(actualizarMaterial()));
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarMaterial()));
    container.botonGuardar->setEnabled(true);
    connect(reg_mat.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_mat.tabla->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_ces::borrarMat()
{
    int row= reg_mat.tabla->currentRow();
    if(row>=0)
    {
        QSqlQuery consulta;
        if(consulta.exec("delete from materiales where id_mat='"+reg_mat.tabla->item(row,0)->text()+"'"))
        {
            reg_mat.tabla->removeRow(row);
            consulta.exec("delete from precios where id_mat='"+reg_mat.tabla->item(row,0)->text()+"'");
        }
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


void procesos_ces::registroSecciones()
{
    frame = new QFrame();
    reg_secciones.setupUi(frame);
    container.workspace->setWidget(frame);

    QSqlQuery consulta;
    reg_secciones.tabla->setColumnWidth(0,65);
    reg_secciones.tabla->setColumnWidth(1,55);
    reg_secciones.tabla->setColumnWidth(2,110);
    reg_secciones.tabla->setColumnWidth(3,200);
    reg_secciones.tabla->setColumnWidth(4,55);
    reg_secciones.tabla->setColumnWidth(5,55);
    reg_secciones.tabla->setColumnWidth(6,130);
    reg_secciones.tabla->setColumnWidth(7,200);
    reg_secciones.tabla->setColumnWidth(8,200);
    reg_secciones.tabla->setColumnWidth(9,100);
    reg_secciones.tabla->setColumnWidth(10,100);

    connect(reg_secciones.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarSeccion(int,int)));

    reg_secciones.curso->addItem("-");
    consulta.exec("select descripcion from metodos order by descripcion");
    while(consulta.next())
    {
        reg_secciones.curso->addItem(consulta.value(0).toString());
    }
    connect(reg_secciones.curso,SIGNAL(currentIndexChanged(QString)),this,SLOT(llenarModalidades(QString)));
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevaSeccion()));
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarSeccion()));
    container.botonNuevo->setEnabled(true);
    container.botonAnular->setEnabled(true);
}


void procesos_ces::llenarModalidades(QString s)
{
    QSqlQuery consulta,consulta2,consulta3;
    reg_secciones.modalidad->clear();
    reg_secciones.modalidad->addItem("-");

    consulta.exec("select id_metodo from metodos where descripcion='"+s+"'");
    while(consulta.next())
    {
        consulta2.exec("select distinct(modalidad) from secciones where id_metodo='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            consulta3.exec("select descripcion from modalidades where id_modalidad='"+consulta2.value(0).toString()+"'");
            while(consulta3.next())
            {
                reg_secciones.modalidad->addItem(consulta3.value(0).toString());
            }
        }
    }
    connect(reg_secciones.modalidad,SIGNAL(currentIndexChanged(QString)),this,SLOT(llenarSecciones(QString)));
}


void procesos_ces::nuevaSeccion()
{
    QSqlQuery consulta;
    QString aux;

    estudianteFrame = new QWidget();
    new_seccion.setupUi(estudianteFrame);
    new_seccion.curso->addItem("-");
    consulta.exec("select descripcion from metodos order by descripcion");
    while(consulta.next())
    {
        new_seccion.curso->addItem(consulta.value(0).toString());
    }
    connect(new_seccion.curso,SIGNAL(currentIndexChanged(QString)),this,SLOT(metodoChanged(QString)));
    new_seccion.modalidad->addItem("-");
    consulta.exec("select descripcion from modalidades order by id_modalidad");
    while(consulta.next())
    {
        new_seccion.modalidad->addItem(consulta.value(0).toString());
    }
    connect(new_seccion.modalidad,SIGNAL(currentIndexChanged(QString)),this,SLOT(modalidadChanged(QString)));
    new_seccion.profesor->addItem("-");
    consulta.exec("select nombre,apellido from profesor order by apellido");//Modificar: permitir escoger solo los profesores de ese metodo (carga_academica)
    while(consulta.next())
    {
        new_seccion.profesor->addItem(consulta.value(1).toString()+", "+consulta.value(0).toString());
    }
    new_seccion.edif->addItem("-");
    consulta.exec("select descripcion from edificios order by descripcion");
    while(consulta.next())
    {
        new_seccion.edif->addItem(consulta.value(0).toString());
    }

    new_seccion.status->addItem("ABIERTA");
    new_seccion.status->addItem("CERRADA");

    connect(new_seccion.edif,SIGNAL(currentIndexChanged(QString)),this,SLOT(edificioChanged(QString)));
    connect(new_seccion.guardar,SIGNAL(clicked()),this,SLOT(guardarSeccion()));
    connect(new_seccion.codigo,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    estudianteFrame->show();

}


void procesos_ces::toUpper(QString s)
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    if (!le)
        return;
    le->setText(s.toUpper());
}


void procesos_ces::metodoChanged(QString s)
{
    QSqlQuery consulta;
    int i,niveles;

    new_seccion.nivel->clear();
    consulta.exec("select niveles from metodos where descripcion='"+s+"'");
    while(consulta.next())
    {
        niveles=consulta.value(0).toInt();
        for(i=0;i<niveles;i++)
            new_seccion.nivel->addItem(tr("%1").arg(i+1));
    }
}


void procesos_ces::edificioChanged(QString s)
{
    QSqlQuery consulta;
    QString edif;

    consulta.exec("select id_edif from edificios where descripcion='"+s+"'");
    while(consulta.next())
    {
        edif=consulta.value(0).toString();
    }
    new_seccion.salon->clear();
    new_seccion.salon->addItem("SIN ASIGNAR");
    consulta.exec("select descripcion from salones where edificio='"+edif+"' order by id_salon");
    while(consulta.next())
    {
        new_seccion.salon->addItem(consulta.value(0).toString());
    }
    connect(new_seccion.salon,SIGNAL(currentIndexChanged(QString)),this,SLOT(salonChanged(QString)));
    //new_seccion.salon->setCurrentIndex(new_seccion.salon->findText(reg_secciones.tabla->item(actual_row,2)->text()));
}


void procesos_ces::salonChanged(QString s)
{
    QSqlQuery consulta;
    QString edif;

    consulta.exec("select id_edif from edificios where descripcion='"+new_seccion.edif->currentText()+"'");
    while(consulta.next())
    {
        edif=consulta.value(0).toString();
    }
    consulta.exec("select capacidad from salones where edificio='"+edif+"' and descripcion='"+s+"'");
    while(consulta.next())
    {
        new_seccion.tope->setText(consulta.value(0).toString());
    }
}

void procesos_ces::modalidadChanged(QString s)
{
    QSqlQuery consulta;
    QString mod,calend;
    consulta.exec("select id_modalidad from modalidades where descripcion='"+s+"'");
    while(consulta.next())
    {
        mod=consulta.value(0).toString();
    }
    consulta.exec("select id_calendario from metodos where descripcion='"+new_seccion.curso->currentText()+"'");
    while(consulta.next())
    {
        calend=consulta.value(0).toString();
    }

    new_seccion.hora_ini->clear();
    new_seccion.hora_ini->addItem("-");
    consulta.exec("select to_char(hora,'HH12:MI AM'),to_char(hora_fin,'HH12:MI AM') from horarios where modalidad='"+mod+"'");
    while(consulta.next())
    {
        new_seccion.hora_ini->addItem(consulta.value(0).toString()+"-"+consulta.value(1).toString());
    }
    new_seccion.periodo->clear();
    new_seccion.periodo->addItem("-");

    if(mod=="19")//En san felipe es 20 cambiar!!
        consulta.exec("select periodo from calendarios_detalle where id_calendario='"+calend+"' and modalidad='1' order by periodo");
    else
        consulta.exec("select periodo from calendarios_detalle where id_calendario='"+calend+"' and modalidad='"+mod+"' order by periodo");
    while(consulta.next())
    {
        new_seccion.periodo->addItem(consulta.value(0).toString());
    }
    connect(new_seccion.periodo,SIGNAL(currentIndexChanged(QString)),this,SLOT(periodoChanged(QString)));
}


void procesos_ces::periodoChanged(QString s)
{
    QSqlQuery consulta;
    QString mod,calend;

    consulta.exec("select id_modalidad from modalidades where descripcion='"+new_seccion.modalidad->currentText()+"'");
    while(consulta.next())
    {
        mod=consulta.value(0).toString();
    }

    consulta.exec("select id_calendario from metodos where descripcion='"+new_seccion.curso->currentText()+"'");
    while(consulta.next())
    {
        calend=consulta.value(0).toString();
    }

    if(mod=="19") //EN SAN FELIPE ES 20
        consulta.exec("select to_char(fecha_ini,'dd-mm-yyyy') from calendarios_detalle where periodo='"+s+"' and id_calendario='"+calend+"' and modalidad='1'");
    else
        consulta.exec("select to_char(fecha_ini,'dd-mm-yyyy') from calendarios_detalle where periodo='"+s+"' and id_calendario='"+calend+"' and modalidad='"+mod+"'");
    while(consulta.next())
    {
        new_seccion.fecha->setDate(QDate::fromString(consulta.value(0).toString(),"dd-MM-yyyy"));
    }

}


void procesos_ces::guardarSeccion()
{
    QSqlQuery consulta;
    QString curso,profesor,edificio,modalidad,apellido,nombre,salon,status;

    consulta.exec("select id_metodo from metodos where descripcion='"+new_seccion.curso->currentText()+"'");
    while(consulta.next())
    {
        curso=consulta.value(0).toString();
    }

    consulta.exec("select id_modalidad from modalidades where descripcion='"+new_seccion.modalidad->currentText()+"'");
    while(consulta.next())
    {
        modalidad=consulta.value(0).toString();
    }

    apellido= new_seccion.profesor->currentText().left(new_seccion.profesor->currentText().indexOf(","));
    nombre= new_seccion.profesor->currentText().remove(apellido+", ",Qt::CaseInsensitive);
    consulta.exec("select cedula_prof from profesor where nombre='"+nombre+"' and apellido='"+apellido+"'");
    while(consulta.next())
    {
        profesor=consulta.value(0).toString();
    }

    consulta.exec("select id_edif from edificios where descripcion='"+new_seccion.edif->currentText()+"'");
    while(consulta.next())
    {
        edificio=consulta.value(0).toString();
    }

    consulta.exec("select id_salon from salones where descripcion='"+new_seccion.salon->currentText()+"' and edificio='"+edificio+"'");
    while(consulta.next())
    {
        salon=consulta.value(0).toString();
    }

    consulta.exec("select id from status where descripcion='"+new_seccion.status->currentText()+"'");
    while(consulta.next())
    {
        status=consulta.value(0).toString();
    }

    if(consulta.exec("insert into secciones values('"+new_seccion.codigo->text()+"','"+curso+"','"+new_seccion.nivel->currentText()+"','"+salon+"','"+new_seccion.tope->text()+"','"+status+"','0','"+edificio+"','"+new_seccion.hora_ini->currentText()+"','"+profesor+"','"+modalidad+"',to_date('"+new_seccion.fecha->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+new_seccion.periodo->currentText()+"')"))
    {
        consulta.exec("commit");
        llenarSecciones(new_seccion.modalidad->currentText());
        new_seccion.codigo->clear();
        new_seccion.curso->setCurrentIndex(0);
        new_seccion.nivel->setCurrentIndex(0);
        new_seccion.hora_ini->setCurrentIndex(0);
        new_seccion.salon->setCurrentIndex(0);
        new_seccion.edif->setCurrentIndex(0);
        new_seccion.profesor->setCurrentIndex(0);
        new_seccion.modalidad->setCurrentIndex(0);
        //new_seccion.periodo->setCurrentIndex(0);
        new_seccion.tope->clear();
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::actualizarSeccion()
{
    QSqlQuery consulta;
    QString curso1,curso,profesor,edificio,modalidad,nombre,apellido,salon,status;
    int periodo;

    consulta.exec("select id_metodo from metodos where descripcion='"+reg_secciones.curso->currentText()+"'");
    while(consulta.next())
    {
        curso1=consulta.value(0).toString();
    }
    consulta.exec("select id_metodo from metodos where descripcion='"+new_seccion.curso->currentText()+"'");
    while(consulta.next())
    {
        curso=consulta.value(0).toString();
    }
    consulta.exec("select id_modalidad from modalidades where descripcion='"+new_seccion.modalidad->currentText()+"'");
    while(consulta.next())
    {
        modalidad=consulta.value(0).toString();
    }
    apellido= new_seccion.profesor->currentText().left(new_seccion.profesor->currentText().indexOf(","));
    nombre= new_seccion.profesor->currentText().remove(apellido+", ",Qt::CaseInsensitive);

    consulta.exec("select cedula_prof from profesor where nombre='"+nombre+"' and apellido='"+apellido+"'");
    while(consulta.next())
    {
        profesor=consulta.value(0).toString();
    }
    consulta.exec("select id_edif from edificios where descripcion='"+new_seccion.edif->currentText()+"'");
    while(consulta.next())
    {
        edificio=consulta.value(0).toString();
    }

    consulta.exec("select id_salon from salones where descripcion='"+new_seccion.salon->currentText()+"' and edificio='"+edificio+"'");
    while(consulta.next())
    {
        salon=consulta.value(0).toString();
    }
    consulta.exec("select periodo from secciones where id_seccion='"+updating+"' and id_metodo='"+curso+"'");
    while(consulta.next())
    {
        periodo=consulta.value(0).toInt();
    }
    consulta.exec("select id from status where descripcion='"+new_seccion.status->currentText()+"'");
    while(consulta.next())
    {
        status=consulta.value(0).toString();
    }

    if(new_seccion.periodo->currentText().toInt()!=periodo)
    {
        if(consulta.exec("update secciones set id_metodo='"+curso+"',id_seccion='"+new_seccion.codigo->text()+"',nivel='"+new_seccion.nivel->currentText()+"',id_salon='"+salon+"',tope='"+new_seccion.tope->text()+"',cant_actual=0,id_edif='"+edificio+"',horario='"+new_seccion.hora_ini->currentText()+"',cedula_prof='"+profesor+"',modalidad='"+modalidad+"',fec_inicio=to_date('"+new_seccion.fecha->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),periodo='"+new_seccion.periodo->currentText()+"',status='"+status+"' where id_seccion='"+updating+"' and id_metodo='"+curso1+"'"))
        {
            consulta.exec("commit");
            llenarSecciones(new_seccion.modalidad->currentText());
            estudianteFrame->close();
        }
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
    else
    {
        if(consulta.exec("update secciones set id_metodo='"+curso+"',id_seccion='"+new_seccion.codigo->text()+"',nivel='"+new_seccion.nivel->currentText()+"',id_salon='"+salon+"',tope='"+new_seccion.tope->text()+"',id_edif='"+edificio+"',horario='"+new_seccion.hora_ini->currentText()+"',cedula_prof='"+profesor+"',modalidad='"+modalidad+"',fec_inicio=to_date('"+new_seccion.fecha->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'), periodo='"+new_seccion.periodo->currentText()+"',status='"+status+"' where id_seccion='"+updating+"' and id_metodo='"+curso1+"'"))
        {
            consulta.exec("commit");
            llenarSecciones(new_seccion.modalidad->currentText());
            estudianteFrame->close();
        }
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
}


void procesos_ces::editarSeccion(int row,int column)
{
    estudianteFrame = new QWidget();
    new_seccion.setupUi(estudianteFrame);
    QSqlQuery consulta;
    QString mod,calend,status;
    actual_row=row;

    new_seccion.status->addItem("ABIERTA");
    new_seccion.status->addItem("CERRADA");
    new_seccion.status->setCurrentIndex(new_seccion.status->findText(reg_secciones.tabla->item(row,11)->text()));

    new_seccion.curso->addItem("-");
    consulta.exec("select descripcion from metodos order by descripcion");
    while(consulta.next())
    {
        new_seccion.curso->addItem(consulta.value(0).toString());
    }

    new_seccion.curso->setCurrentIndex(new_seccion.curso->findText(reg_secciones.curso->currentText()));
    metodoChanged(reg_secciones.curso->currentText());
    new_seccion.nivel->setCurrentIndex(new_seccion.nivel->findText(reg_secciones.tabla->item(row,1)->text()));

    new_seccion.modalidad->addItem("-");
    consulta.exec("select descripcion from modalidades order by descripcion");
    while(consulta.next())
    {
        new_seccion.modalidad->addItem(consulta.value(0).toString());
    }
    new_seccion.modalidad->setCurrentIndex(new_seccion.modalidad->findText(reg_secciones.tabla->item(row,8)->text()));
    modalidadChanged(reg_secciones.modalidad->currentText());
    new_seccion.periodo->setCurrentIndex(new_seccion.periodo->findText(reg_secciones.tabla->item(row,10)->text()));

    consulta.exec("select id_modalidad from modalidades where descripcion='"+new_seccion.modalidad->currentText()+"'");
    while(consulta.next())
    {
        mod=consulta.value(0).toString();
    }

    new_seccion.hora_ini->clear();
    new_seccion.hora_ini->addItem("-");
    consulta.exec("select to_char(hora,'HH12:MI AM'),to_char(hora_fin,'HH12:MI AM') from horarios where modalidad='"+mod+"'");
    while(consulta.next())
    {
        new_seccion.hora_ini->addItem(consulta.value(0).toString()+"-"+consulta.value(1).toString());
    }

    new_seccion.hora_ini->setCurrentIndex(new_seccion.hora_ini->findText(reg_secciones.tabla->item(row,6)->text()));
    new_seccion.profesor->addItem("-");
    consulta.exec("select nombre,apellido from profesor order by apellido");
    while(consulta.next())
    {
        new_seccion.profesor->addItem(consulta.value(1).toString()+", "+consulta.value(0).toString());
    }

    new_seccion.profesor->setCurrentIndex(new_seccion.profesor->findText(reg_secciones.tabla->item(row,7)->text()));

    new_seccion.edif->addItem("-");
    consulta.exec("select descripcion from edificios order by descripcion");
    while(consulta.next())
    {
        new_seccion.edif->addItem(consulta.value(0).toString());
    }

    new_seccion.edif->setCurrentIndex(new_seccion.edif->findText(reg_secciones.tabla->item(row,3)->text()));
    edificioChanged(new_seccion.edif->currentText());
    new_seccion.salon->setCurrentIndex(new_seccion.salon->findText(reg_secciones.tabla->item(row,2)->text()));
    new_seccion.codigo->setText(reg_secciones.tabla->item(row,0)->text());
    updating=reg_secciones.tabla->item(row,0)->text();
    new_seccion.tope->setText(reg_secciones.tabla->item(row,4)->text());
    new_seccion.fecha->setDate(QDate::fromString(reg_secciones.tabla->item(row,9)->text(),"dd-MM-yyyy"));
    new_seccion.periodo->setCurrentIndex(new_seccion.periodo->findText(reg_secciones.tabla->item(row,10)->text()));
    connect(new_seccion.edif,SIGNAL(currentIndexChanged(QString)),this,SLOT(edificioChanged(QString)));
    connect(new_seccion.modalidad,SIGNAL(currentIndexChanged(QString)),this,SLOT(modalidadChanged(QString)));
    connect(new_seccion.guardar,SIGNAL(clicked()),this,SLOT(actualizarSeccion()));
    connect(new_seccion.codigo,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));

    estudianteFrame->show();
}


void procesos_ces::llenarSecciones(QString s)
{
    QSqlQuery consulta,consulta2;
    QComboBox *aux;
    QTableWidgetItem *ni;
    QString curso,modalidad,status;
    int row,i;

    for(i=reg_secciones.tabla->rowCount()-1;i>=0;i--)
        reg_secciones.tabla->removeRow(i);

    consulta.exec("select id_metodo from metodos where descripcion='"+reg_secciones.curso->currentText()+"'");
    while(consulta.next())
    {
        curso=consulta.value(0).toString();
    }
    consulta.exec("select id_modalidad from modalidades where descripcion='"+s+"'");
    while(consulta.next())
    {
        modalidad=consulta.value(0).toString();
    }

    consulta.exec("select id_seccion,nivel,id_salon,tope,cant_actual,id_edif,horario,cedula_prof,modalidad,to_char(fec_inicio,'dd-mm-yyyy'),periodo,status from secciones where id_metodo='"+curso+"' and modalidad='"+modalidad+"' order by nivel");
    while(consulta.next())
    {
        row = reg_secciones.tabla->rowCount();
        reg_secciones.tabla->insertRow(row);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_secciones.tabla->setItem(row,0,ni);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_secciones.tabla->setItem(row,1,ni);

        consulta2.exec("select descripcion from salones where id_salon='"+consulta.value(2).toString()+"' and edificio='"+consulta.value(5).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_secciones.tabla->setItem(row,2,ni);
        }

        consulta2.exec("select descripcion from edificios where id_edif='"+consulta.value(5).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_secciones.tabla->setItem(row,3,ni);
        }

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        reg_secciones.tabla->setItem(row,4,ni);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(4).toString()));
        reg_secciones.tabla->setItem(row,5,ni);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(6).toString()));
        reg_secciones.tabla->setItem(row,6,ni);

        consulta2.exec("select nombre,apellido from profesor where cedula_prof='"+consulta.value(7).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(1).toString()+", "+consulta2.value(0).toString()));
            reg_secciones.tabla->setItem(row,7,ni);
        }

        consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(8).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_secciones.tabla->setItem(row,8,ni);
        }

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(9).toString()));
        reg_secciones.tabla->setItem(row,9,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(10).toString()));
        reg_secciones.tabla->setItem(row,10,ni);

        consulta2.exec("select descripcion from status where id='"+consulta.value(11).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(consulta2.value(0).toString());
            reg_secciones.tabla->setItem(row,11,ni);
        }
    }
}

void procesos_ces::borrarSeccion()
{
    int row= reg_secciones.tabla->currentRow();

    if(row>=0)
    {
        QSqlQuery consulta;
        if(consulta.exec("delete from secciones where id_seccion='"+reg_secciones.tabla->item(row,0)->text()+"'"))
        {
            consulta.exec("commit");
            reg_secciones.tabla->removeRow(row);
        }
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


void procesos_ces::registroEdificio()
{
    estudianteFrame = new QWidget();
    reg_edificio.setupUi(estudianteFrame);
    connect(reg_edificio.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarEdificio(int,int)));
    connect(reg_edificio.nuevo,SIGNAL(clicked()),this,SLOT(nuevoEdificio()));
    connect(reg_edificio.quitar,SIGNAL(clicked()),this,SLOT(borrarEdificio()));
    reg_edificio.guardar->setEnabled(false);
    reg_edificio.tabla->setColumnWidth(0,60);
    reg_edificio.tabla->setColumnWidth(1,150);
    estudianteFrame->show();
    llenarEdificio();
}


void procesos_ces::llenarEdificio()
{
    QSqlQuery consulta;
    QTableWidgetItem *ni;
    int i,row;
    for(i=reg_edificio.tabla->rowCount()-1;i>=0;i--)
        reg_edificio.tabla->removeRow(i);

    consulta.exec("select * from edificios");
    while(consulta.next())
    {
        row = reg_edificio.tabla->rowCount();
        reg_edificio.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_edificio.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_edificio.tabla->setItem(row,1,ni);
    }
}


void procesos_ces::nuevoEdificio()
{
    int row;
    row=reg_edificio.tabla->rowCount();
    reg_edificio.tabla->insertRow(row);

    lines= new QList<QLineEdit*>();
    lines->append(new QLineEdit());
    reg_edificio.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit());
    reg_edificio.tabla->setCellWidget(row,1,lines->last());

    disconnect(reg_edificio.guardar,SIGNAL(clicked()),0,0);
    connect(reg_edificio.guardar,SIGNAL(clicked()),this,SLOT(guardarEdificio()));
    reg_edificio.guardar->setEnabled(true);
    connect(reg_edificio.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_edificio.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    reg_edificio.tabla->setCurrentCell(row,0);
}


void procesos_ces::borrarEdificio()
{
    QSqlQuery consulta;
    int row= reg_edificio.tabla->currentRow();
    if(row>=0)
    {
        if(!consulta.exec("delete from salones where edificio='"+reg_edificio.tabla->item(row,0)->text()+"'"))
            QMessageBox::critical(0,"Error Borrar Salones",consulta.lastError().text());
        else
        {
            if(!consulta.exec("delete from edificios where id_edif='"+reg_edificio.tabla->item(row,0)->text()+"'"))
                QMessageBox::critical(0,"Error Borrar Edificio",consulta.lastError().text());
            else
            {
                consulta.exec("commit");
                llenarEdificio();
                llenarSalones();
            }
        }
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


void procesos_ces::editarEdificio(int row,int column)
{
    updating=reg_edificio.tabla->item(row,0)->text();
    lines= new QList<QLineEdit*>();
    lines->append(new QLineEdit(reg_edificio.tabla->item(row,0)->text()));
    reg_edificio.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit(reg_edificio.tabla->item(row,1)->text()));
    reg_edificio.tabla->setCellWidget(row,1,lines->last());

    disconnect(reg_edificio.guardar,SIGNAL(clicked()),0,0);
    connect(reg_edificio.guardar,SIGNAL(clicked()),this,SLOT(actualizarEdificio()));
    reg_edificio.guardar->setEnabled(true);
    connect(reg_edificio.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_edificio.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_ces::guardarEdificio()
{
    QSqlQuery consulta;
    if(consulta.exec("insert into edificios values('"+lines->at(0)->text()+"','"+lines->at(1)->text()+"')"))
    {
        consulta.exec("commit");
        llenarEdificio();
        reg_edificio.guardar->setEnabled(false);
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::actualizarEdificio()
{
    QSqlQuery consulta;
    if(consulta.exec("update edificios set id_edif='"+lines->at(0)->text()+"',descripcion='"+lines->at(1)->text()+"' where id_edif='"+updating+"'"))
    {
        consulta.exec("commit");
        llenarEdificio();
        reg_edificio.guardar->setEnabled(false);
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::registroSalones()
{
    frame = new QFrame();
    reg_salones.setupUi(frame);
    container.workspace->setWidget(frame);

    reg_salones.tabla->setColumnWidth(0,200);
    reg_salones.tabla->setColumnWidth(1,50);
    reg_salones.tabla->setColumnWidth(2,100);
    reg_salones.tabla->setColumnWidth(3,100);

    connect(reg_salones.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarSalon(int,int)));
    disconnect(container.botonNuevo,SIGNAL(clicked()),0,0);
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoSalon()));
    container.botonNuevo->setEnabled(true);
    disconnect(container.botonAnular,SIGNAL(clicked()),0,0);
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarSalon()));
    connect(reg_salones.edificios,SIGNAL(clicked()),this,SLOT(registroEdificio()));
    //connect(reg_salones.disponible,SIGNAL(clicked()),this,SLOT(asignacionSalones()));
    container.botonAnular->setEnabled(true);
    llenarSalones();
}


void procesos_ces::llenarSalones()
{
    QSqlQuery consulta,consulta2;
    QTableWidgetItem *ni;
    int row,i;

    for(i=reg_salones.tabla->rowCount()-1;i>=0;i--)
        reg_salones.tabla->removeRow(i);

    consulta.exec("select * from salones order by edificio,id_salon");
    while(consulta.next())
    {
        row = reg_salones.tabla->rowCount();
        reg_salones.tabla->insertRow(row);
        consulta2.exec("select descripcion from edificios where id_edif='"+consulta.value(1).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_salones.tabla->setItem(row,0,ni);
        }
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_salones.tabla->setItem(row,1,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        reg_salones.tabla->setItem(row,2,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        reg_salones.tabla->setItem(row,3,ni);
    }
}

void procesos_ces::nuevoSalon()
{
        int row= reg_salones.tabla->rowCount();
        reg_salones.tabla->insertRow(row);

        lines = new QList<QLineEdit*>();
        combos = new QList<QComboBox*>();

        QComboBox *aux = new QComboBox();
        QSqlQuery consulta("select descripcion from edificios order by descripcion");
        while(consulta.next())
        {
                aux->addItem(consulta.value(0).toString());
        }
        combos->append(aux);
        reg_salones.tabla->setCellWidget(row,0,combos->last());
        lines->append(new QLineEdit());
        reg_salones.tabla->setCellWidget(row,1,lines->last());
        lines->append(new QLineEdit());
        reg_salones.tabla->setCellWidget(row,2,lines->last());
        lines->append(new QLineEdit());
        reg_salones.tabla->setCellWidget(row,3,lines->last());
        lines->append(new QLineEdit());
        aux = new QComboBox();
        aux->addItem("S");
        aux->addItem("N");
        combos->append(aux);
        reg_salones.tabla->setCellWidget(row,6,combos->last());
        disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
        connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarSalon()));
        connect(reg_salones.tabla->cellWidget(row,3),SIGNAL(returnPressed()),this,SLOT(guardarSalon()));
        container.botonGuardar->setEnabled(true);
        connect(reg_salones.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
        connect(reg_salones.tabla->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
        reg_salones.tabla->setCurrentCell(row,0);
}


void procesos_ces::actualizarSalon()
{
        QSqlQuery consulta;
        QString edif;
        consulta.exec("select id_edif from edificios where descripcion='"+combos->at(0)->currentText()+"'");
        while(consulta.next())
        {
                edif=consulta.value(0).toString();
        }
        if(consulta.exec("update salones set id_salon='"+lines->at(0)->text()+"',edificio='"+edif+"',descripcion='"+lines->at(1)->text()+"',capacidad='"+lines->at(2)->text()+"' where id_salon='"+updating+"'"))
        {
                consulta.exec("commit");
                llenarSalones();
                container.botonGuardar->setEnabled(false);
        }
        else
                QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::guardarSalon()
{
        QSqlQuery consulta;
        QString edif;
        consulta.exec("select id_edif from edificios where descripcion='"+combos->at(0)->currentText()+"'");
        while(consulta.next())
        {
                edif=consulta.value(0).toString();
        }
        if(consulta.exec("insert into salones values('"+lines->at(0)->text()+"','"+edif+"','"+lines->at(1)->text()+"','"+lines->at(2)->text()+"','','')"))
        {
                consulta.exec("commit");
                llenarSalones();
                container.botonGuardar->setEnabled(false);
        }
        else
                QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::editarSalon(int row,int column)
{
        updating=reg_salones.tabla->item(row,1)->text();
        llenarSalones();
        lines = new QList<QLineEdit*>();
        combos = new QList<QComboBox*>();

        QComboBox *aux = new QComboBox();
        QSqlQuery consulta("select descripcion from edificios order by descripcion");
        while(consulta.next())
        {
                aux->addItem(consulta.value(0).toString());
        }
        aux->setCurrentIndex(aux->findText(reg_salones.tabla->item(row,0)->text()));
        combos->append(aux);
        reg_salones.tabla->setCellWidget(row,0,combos->last());
        lines->append(new QLineEdit(reg_salones.tabla->item(row,1)->text()));
        reg_salones.tabla->setCellWidget(row,1,lines->last());
        lines->append(new QLineEdit(reg_salones.tabla->item(row,2)->text()));
        reg_salones.tabla->setCellWidget(row,2,lines->last());
        lines->append(new QLineEdit(reg_salones.tabla->item(row,3)->text()));
        reg_salones.tabla->setCellWidget(row,3,lines->last());
        aux = new QComboBox();
        aux->addItem("S");
        aux->addItem("N");
        aux->setCurrentIndex(aux->findText(reg_salones.tabla->item(row,6)->text()));
        combos->append(aux);
        reg_salones.tabla->setCellWidget(row,6,combos->last());

        disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
        connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarSalon()));
        connect(reg_salones.tabla->cellWidget(row,3),SIGNAL(returnPressed()),this,SLOT(actualizarSalon()));
        container.botonGuardar->setEnabled(true);
        connect(reg_salones.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
        connect(reg_salones.tabla->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));

}


void procesos_ces::borrarSalon()
{
        int row= reg_salones.tabla->currentRow();

        if(row>=0)
        {
                QSqlQuery consulta;
                if(consulta.exec("delete from salones where edificio='"+reg_salones.tabla->item(row,0)->text()+"' and id_salon='"+reg_salones.tabla->item(row,1)->text()+"'"))
                {
                        consulta.exec("commit");
                        reg_salones.tabla->removeRow(row);
                }
                else
                        QMessageBox::critical(0,"Error",consulta.lastError().text());
        }
        else
                QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


void procesos_ces::asignacionSalones()
{
    estudianteFrame = new QWidget();
    reg_salones.setupUi(estudianteFrame);

    QSqlQuery consulta;
    QStringList labels;

    consulta.exec("select descripcion from edificios");
    while(consulta.next())
    {
        asigna_salones.edificio->addItem(consulta.value(0).toString());
    }
    connect(asigna_salones.edificio,SIGNAL(currentIndexChanged(QString)),this,SLOT(edificioChanged3(QString)));
    consulta.exec("select to_char(hora,'HH12:MI AM') from horarios order by hora");
    while(consulta.next())
    {
        labels << consulta.value(0).toString();
    }

    asigna_salones.tabla->setVerticalHeaderLabels(labels);
    estudianteFrame->show();
}


/*
void procesos_ces::edificioChanged3(QString s)
{
    QSqlQuery consulta;
    QString edif;
    consulta.exec("select id_edif from edificios where descripcion='"+s+"'");
    while(consulta.next())
    {
        edif=consulta.value(0).toString();
    }
    consulta.exec("select descripcion from salones where id_edif='"+edif+"'");
    while(consulta.next())
    {
        asigna_salones.salon->addItem(consulta.value(0).toString());
    }
    connect(asigna_salones.salon,SIGNAL(currentIndexChanged(QString)),this,SLOT(llenarAsignaSalones(QString)));
}


void procesos_ces::llenarAsignaSalones(QString)
{
    QSqlQuery consulta;

}
*/


void procesos_ces::registroCalendarioPago()
{
    QSqlQuery consulta;
    frame = new QFrame();
    reg_cal2.setupUi(frame);
    container.workspace->setWidget(frame);

    consulta.exec("select descripcion from diplo_temp order by descripcion");
    reg_cal2.diplomados->addItem("-");
    while(consulta.next())
    {
        reg_cal2.diplomados->addItem(consulta.value(0).toString());
    }
    //connect(reg_cal2.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarFecha(int,int)));
    connect(reg_cal2.diplomados,SIGNAL(currentIndexChanged(const QString)),this,SLOT(diplomadoChanged(const QString)));
}


void procesos_ces::diplomadoChanged(QString s)
{
    QSqlQuery consulta,consulta2;
    //consulta.exec("select id_diplomado,cuotas from diplomados where descripcion='"+s+"'");
    reg_cal2.cohorte->clear();
    reg_cal2.cohorte->addItem("-");
    consulta.exec("select id_diplomado from diplo_temp where descripcion='"+s+"'");
    while(consulta.next())
    {
        consulta2.exec("select id from cohortes where id_diplomado='"+consulta.value(0).toString()+"' and status='V' order by id");
        while(consulta2.next())
        {
            reg_cal2.cohorte->addItem(consulta2.value(0).toString());
        }
    }
    connect(reg_cal2.cohorte,SIGNAL(currentIndexChanged(QString)),this,SLOT(cohorteChanged(QString)));
}


void procesos_ces::cohorteChanged(QString s)
{
    QSqlQuery consulta;

    updating=s;
    consulta.exec("select to_char(fecha_ini,'dd-mm-yyyy') from cohortes where id='"+s+"'");
    while(consulta.next())
    {
        reg_cal2.fecha_ini->setText(consulta.value(0).toString());
    }
    llenarCalPago();
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarCalendarioPago()));
    container.botonGuardar->setEnabled(true);
}


void procesos_ces::llenarCalPago()
{
    QSqlQuery consulta;
    QTableWidgetItem *ni;
    QDateEdit *inicio;
    int i;
    inicios=new QList<QDateEdit*>();
    for(i=reg_cal2.tabla->rowCount()-1;i>=0;i--)
        reg_cal2.tabla->removeRow(i);

    consulta.exec("select cuota,to_char(fecha_corte,'dd-mm-yyyy') from calendario_cfp where cohorte='"+updating+"' order by cuota");
    while(consulta.next())
    {
        reg_cal2.tabla->insertRow(reg_cal2.tabla->rowCount());
        inicio= new QDateEdit();
        inicio->setDate(QDate::fromString(consulta.value(1).toString(),"dd-MM-yyyy"));
        inicios->append(inicio);
        reg_cal2.tabla->setCellWidget(reg_cal2.tabla->rowCount()-1,1,inicio);
        ni = new QTableWidgetItem(consulta.value(0).toString());
        reg_cal2.tabla->setItem(reg_cal2.tabla->rowCount()-1,0,ni);
    }
}



void procesos_ces::actualizarCalendarioPago()
{
    QSqlQuery consulta;
    int i;

    for(i=0;i<inicios->size();i++)
    {
        if(!consulta.exec("update calendario_cfp set fecha_corte=to_date('"+inicios->at(i)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy') where cuota='"+reg_cal2.tabla->item(i,0)->text()+"' and cohorte='"+updating+"'"))
            QMessageBox::critical(0,"Error Fecha Pago",consulta.lastError().text());
        else
            consulta.exec("commit");
    }
}


void procesos_ces::registroCalendario()
{
    QSqlQuery consulta;

    frame = new QFrame();
    reg_cal.setupUi(frame);
    container.workspace->setWidget(frame);

    reg_cal.calendarios->addItem("-");
    consulta.exec("select descripcion from calendarios order by descripcion");
    while(consulta.next())
    {
        reg_cal.calendarios->addItem(consulta.value(0).toString());
    }

    connect(reg_cal.calendarios,SIGNAL(currentIndexChanged(const QString)),this,SLOT(calendarioChanged(const QString)));
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarCalendario()));
    container.botonGuardar->setEnabled(true);
    disconnect(container.botonNuevo,SIGNAL(clicked()),0,0);
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoCalendario()));
    container.botonNuevo->setEnabled(true);
    reg_cal.tabla->setColumnWidth(0,50);
    reg_cal.tabla->setColumnWidth(1,100);
    reg_cal.tabla->setColumnWidth(2,100);

    reg_cal.tabla2->setColumnWidth(0,50);
    reg_cal.tabla2->setColumnWidth(1,100);
    reg_cal.tabla2->setColumnWidth(2,100);
    acop=false;
}


void procesos_ces::modalidadesCalendario(int state)
{
    QSqlQuery consulta;
    if(state==2)
    {
        consulta.exec("select descripcion from modalidades order by descripcion");
        while(consulta.next())
        {
            reg_cals.modalidad->addItem(consulta.value(0).toString());
        }
        connect(reg_cals.agregar,SIGNAL(clicked()),this,SLOT(agregarModCalendario()));
        connect(reg_cals.quitar,SIGNAL(clicked()),this,SLOT(quitarModCalendario()));
        reg_cals.agregar->setEnabled(true);
        reg_cals.quitar->setEnabled(true);
        reg_cals.periodos2->setEnabled(true);
        reg_cals.modalidad->setEnabled(true);
        reg_cals.tabla->setEnabled(true);
    }
    else
    {
        reg_cals.agregar->setEnabled(false);
        reg_cals.quitar->setEnabled(false);
        reg_cals.periodos2->setEnabled(false);
        reg_cals.modalidad->setEnabled(false);
        reg_cals.tabla->setEnabled(false);
    }
}


void procesos_ces::agregarModCalendario()
{
    QTableWidgetItem *ni;

    reg_cals.tabla->insertRow(reg_cals.tabla->rowCount());
    ni = new QTableWidgetItem(tr("%1").arg(reg_cals.modalidad->currentText()));
    reg_cals.tabla->setItem(reg_cals.tabla->rowCount()-1,0,ni);
    ni = new QTableWidgetItem(tr("%1").arg(reg_cals.periodos2->text()));
    reg_cals.tabla->setItem(reg_cals.tabla->rowCount()-1,1,ni);
}


void procesos_ces::quitarModCalendario()
{
    int row= reg_cals.tabla->currentRow();

    if(row>=0)
        reg_cals.tabla->removeRow(row);
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


void procesos_ces::nuevoCalendario()
{
    QSqlQuery consulta;
    estudianteFrame = new QWidget();
    reg_cals.setupUi(estudianteFrame);
    connect(reg_cals.aceptar,SIGNAL(clicked()),this,SLOT(guardarCalendario()));
    connect(reg_cals.otra_mod,SIGNAL(stateChanged(int)),this,SLOT(modalidadesCalendario(int)));
    connect(reg_cals.id_calendario,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_cals.descripcion,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    consulta.exec("select max(id_calendario) from calendarios");
    while(consulta.next())
    {
        reg_cals.id_calendario->setText(tr("%1").arg(consulta.value(0).toInt()+1));
    }

    reg_cals.tabla->setColumnWidth(0,240);
    estudianteFrame->show();
}


void procesos_ces::guardarCalendario()
{
    QSqlQuery consulta,consulta2;
    QString modalidad;

    if(!consulta.exec("insert into calendarios values('"+reg_cals.id_calendario->text()+"','"+reg_cals.descripcion->text()+"','"+reg_cals.periodos->text()+"')"))
        QMessageBox::critical(0,"Error Nuevo Calendario",consulta.lastError().text());
    else
    {
        for(int i=0;i<reg_cals.periodos->text().toInt();i++)
        {
            if(!consulta.exec("insert into calendarios_detalle values('"+reg_cals.id_calendario->text()+"','"+tr("%1").arg(i+1)+"','','','','1')"))
            {
                QMessageBox::critical(0,tr("Error Calendario - Periodo %1").arg(i+1),consulta.lastError().text());
                return;
            }
        }
        for(int i=0;i<reg_cals.tabla->rowCount();i++)
        {
            consulta.exec("select id_modalidad from modalidades where descripcion='"+reg_cals.tabla->item(i,0)->text()+"'");
            while(consulta.next())
            {
                modalidad=consulta.value(0).toString();
            }
            for(int j=0;j<reg_cals.tabla->item(i,1)->text().toInt();j++)
            {
                if(!consulta.exec("insert into calendarios_detalle values('"+reg_cals.id_calendario->text()+"','"+tr("%1").arg(j+1)+"','','','','"+modalidad+"')"))
                {
                    QMessageBox::critical(0,tr("Error Calendario - Periodo %1").arg(i+1),consulta.lastError().text());
                    return;
                }
            }
        }
        consulta.exec("commit");
        reg_cal.calendarios->clear();
        reg_cal.calendarios->addItem("-");
        reg_cal.modalidad->clear();
        reg_cal.modalidad->addItem("-");
        consulta.exec("select descripcion from calendarios order descripcion");
        while(consulta.next())
        {
            reg_cal.calendarios->addItem(consulta.value(0).toString());
        }
        consulta.exec("select distinct(modalidad) from calendarios_detalle where id_calendario='"+updating+"' and modalidad <>'1'");
        while(consulta.next())
        {
            consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                reg_cal.modalidad->addItem(consulta2.value(0).toString());
            }
        }
        estudianteFrame->close();
    }
}


void procesos_ces::editarCalendario()
{
    QSqlQuery consulta,consulta2;
    estudianteFrame = new QWidget();
    reg_cals.setupUi(estudianteFrame);
    reg_cals.id_calendario->setText(updating);
    consulta.exec("select descripcion,periodos from calendarios where id_calendario='"+updating+"'");
    while(consulta.next())
    {
        reg_cals.descripcion->setText(consulta.value(0).toString());
        reg_cals.periodos->setText(consulta.value(1).toString());
    }
    consulta.exec("select distinct(modalidad) from calendarios_detalle where id_calendario='"+updating+"' and modalidad <>'1'");
    while(consulta.next())
    {
        QTableWidgetItem *ni;
        reg_cals.tabla->insertRow(reg_cals.tabla->rowCount());
        consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_cals.tabla->setItem(reg_cals.tabla->rowCount()-1,0,ni);
        }
        consulta2.exec("select count(periodo) from calendarios_detalle where id_calendario='"+updating+"' and modalidad='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_cals.tabla->setItem(reg_cals.tabla->rowCount()-1,1,ni);
        }
    }
    connect(reg_cals.aceptar,SIGNAL(clicked()),this,SLOT(actualizarCalendario2()));
    connect(reg_cals.otra_mod,SIGNAL(stateChanged(int)),this,SLOT(modalidadesCalendario(int)));
    connect(reg_cals.id_calendario,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_cals.descripcion,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    reg_cals.tabla->setColumnWidth(0,240);
    estudianteFrame->show();
}


void procesos_ces::actualizarCalendario2()
{
    QSqlQuery consulta,consulta2;
    QString modalidad;
    if(!consulta.exec("update calendarios set descripcion='"+reg_cals.descripcion->text()+"',periodos='"+reg_cals.periodos->text()+"' where id_calendario='"+updating+"'"))
    {
        QMessageBox::critical(0,"Error Editar Calendario",consulta.lastError().text());
        return;
    }
    else
    {
        consulta.exec("delete from calendarios_detalle where id_calendario='"+updating+"'");
        consulta.exec("commit");
        for(int i=0;i<reg_cals.periodos->text().toInt();i++)
        {
            if(!consulta.exec("insert into calendarios_detalle values('"+reg_cals.id_calendario->text()+"','"+tr("%1").arg(i+1)+"','','','','1')"))
            {
                QMessageBox::critical(0,tr("Error Calendario - Periodo %1").arg(i+1),consulta.lastError().text());
                return;
            }
        }
        for(int i=0;i<reg_cals.tabla->rowCount();i++)
        {
            consulta.exec("select id_modalidad from modalidades where descripcion='"+reg_cals.tabla->item(i,0)->text()+"'");
            while(consulta.next())
            {
                modalidad=consulta.value(0).toString();
            }
            for(int j=0;j<reg_cals.tabla->item(i,1)->text().toInt();j++)
            {
                if(!consulta.exec("insert into calendarios_detalle values('"+reg_cals.id_calendario->text()+"','"+tr("%1").arg(j+1)+"','','','','"+modalidad+"')"))
                {
                    QMessageBox::critical(0,tr("Error Calendario - Periodo %1").arg(i+1),consulta.lastError().text());
                    return;
                }
            }
        }
        consulta.exec("commit");
        reg_cal.calendarios->clear();
        reg_cal.calendarios->addItem("-");
        reg_cal.modalidad->clear();
        reg_cal.modalidad->addItem("-");
        consulta.exec("select descripcion from calendarios order by descripcion");
        while(consulta.next())
        {
            reg_cal.calendarios->addItem(consulta.value(0).toString());
        }
        consulta.exec("select distinct(modalidad) from calendarios_detalle where id_calendario='"+updating+"' and modalidad <>'1'");
        while(consulta.next())
        {
            consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                reg_cal.modalidad->addItem(consulta2.value(0).toString());
            }
        }
        estudianteFrame->close();
    }
}


void procesos_ces::calendarioChanged(QString s)
{
    QSqlQuery consulta,consulta2,consulta3;
    QTableWidgetItem *ni;
    QDateEdit *inicio,*fin;
    int i;

    disconnect(container.botonModificar,SIGNAL(clicked()),0,0);
    connect(container.botonModificar,SIGNAL(clicked()),this,SLOT(editarCalendario()));
    container.botonModificar->setEnabled(true);
    consulta.exec("select id_calendario from calendarios where descripcion='"+s+"'");
    while(consulta.next())
    {
        updating=consulta.value(0).toString();
        inicios = new QList<QDateEdit*>();
        fines = new QList<QDateEdit*>();

        for(i=reg_cal.tabla->rowCount()-1;i>=0;i--)
            reg_cal.tabla->removeRow(i);

        consulta2.exec("select periodo,to_char(fecha_ini,'dd-mm-yyyy'),to_char(fecha_fin,'dd-mm-yyyy') from calendarios_detalle where id_calendario='"+updating+"' and modalidad='1' order by periodo");
        while(consulta2.next())
        {
            reg_cal.tabla->insertRow(reg_cal.tabla->rowCount());
            inicio= new QDateEdit(QDate::fromString(consulta2.value(1).toString(),"dd-MM-yyyy"));
            inicios->append(inicio);
            reg_cal.tabla->setCellWidget(reg_cal.tabla->rowCount()-1,1,inicio);

            fin= new QDateEdit(QDate::fromString(consulta2.value(2).toString(),"dd-MM-yyyy"));
            fines->append(fin);
            reg_cal.tabla->setCellWidget(reg_cal.tabla->rowCount()-1,2,fin);

            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_cal.tabla->setItem(reg_cal.tabla->rowCount()-1,0,ni);
        }

        reg_cal.modalidad->clear();
        reg_cal.modalidad->addItem("-");
        consulta2.exec("select distinct(modalidad) from calendarios_detalle where id_calendario='"+updating+"' and modalidad <>'1'");
        while(consulta2.next())
        {
            consulta3.exec("select descripcion from modalidades where id_modalidad='"+consulta2.value(0).toString()+"'");
            while(consulta3.next())
            {
                reg_cal.modalidad->addItem(consulta3.value(0).toString());
            }
        }
        connect(reg_cal.modalidad,SIGNAL(currentIndexChanged(QString)),this,SLOT(modCalendarioChanged(QString)));
    }
}


void procesos_ces::modCalendarioChanged(QString s)
{
    QString modalidad;
    QDateEdit *inicio,*fin;
    QTableWidgetItem *ni;
    int i;
    inicios2 = new QList<QDateEdit*>();
    fines2 = new QList<QDateEdit*>();

    QSqlQuery consulta("select id_modalidad from modalidades where descripcion='"+s+"'");
    while(consulta.next())
    {
        modalidad=consulta.value(0).toString();
    }

    for(i=reg_cal.tabla2->rowCount()-1;i>=0;i--)
        reg_cal.tabla2->removeRow(i);

    consulta.exec("select periodo,to_char(fecha_ini,'dd-mm-yyyy'),to_char(fecha_fin,'dd-mm-yyyy') from calendarios_detalle where id_calendario='"+updating+"' and modalidad='"+modalidad+"' order by periodo");
    while(consulta.next())
    {
        reg_cal.tabla2->insertRow(reg_cal.tabla2->rowCount());
        inicio= new QDateEdit(QDate::fromString(consulta.value(1).toString(),"dd-MM-yyyy"));
        inicios2->append(inicio);
        reg_cal.tabla2->setCellWidget(reg_cal.tabla2->rowCount()-1,1,inicio);

        fin= new QDateEdit(QDate::fromString(consulta.value(2).toString(),"dd-MM-yyyy"));
        fines2->append(fin);
        reg_cal.tabla2->setCellWidget(reg_cal.tabla2->rowCount()-1,2,fin);

        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_cal.tabla2->setItem(reg_cal.tabla2->rowCount()-1,0,ni);
    }
    acop=true;
}


void procesos_ces::actualizarCalendario()
{
    int i;
    QSqlQuery consulta;
    QString periodo,modalidad;

    for(i=0;i<inicios->size();i++)
    {
        periodo.setNum(i+1);
        if(consulta.exec("update calendarios_detalle set fecha_ini= to_date('"+inicios->at(i)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'), fecha_fin=to_date('"+fines->at(i)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'), vigencia=to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy') where modalidad='1' and periodo='"+periodo+"' and id_calendario='"+updating+"'"))
        {
            consulta.exec("commit");
        }
        else
        {
            QMessageBox::critical(0,"Error",consulta.lastError().text());
            return;
        }
    }
    QMessageBox::information(0,"","Calendario actualizado exitosamente");
    consulta.exec("select id_modalidad from modalidades where descripcion='"+reg_cal.modalidad->currentText()+"'");
    while(consulta.next())
    {
        modalidad=consulta.value(0).toString();
    }

    if(acop)
    {
        for(i=0;i<inicios2->size();i++)
        {
            periodo.setNum(i+1);
            if(consulta.exec("update calendarios_detalle set fecha_ini= to_date('"+inicios2->at(i)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'), fecha_fin=to_date('"+fines2->at(i)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'), vigencia=to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy') where modalidad='"+modalidad+"' and periodo='"+periodo+"' and id_calendario='"+updating+"'"))
            {
                consulta.exec("commit");
            }
            else
            {
                QMessageBox::critical(0,"Error",consulta.lastError().text());
                return;
            }
        }
        acop=false;
    }
}


void procesos_ces::registroEventos()
{
    frame = new QFrame();
    reg_eventos.setupUi(frame);
    container.workspace->setWidget(frame);

    connect(reg_eventos.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarEvento(int,int)));
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoEvento()));
    container.botonNuevo->setEnabled(true);
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarEvento()));
    container.botonAnular->setEnabled(true);

    reg_eventos.tabla->setColumnWidth(0,50);
    reg_eventos.tabla->setColumnWidth(6,300);
    reg_eventos.tabla->setColumnWidth(2,35);
    reg_eventos.tabla->setColumnWidth(3,35);
    reg_eventos.tabla->setColumnWidth(4,35);
    reg_eventos.tabla->setColumnWidth(5,35);
    reg_eventos.tabla->setColumnWidth(1,35);

    llenarEventos();
}


void procesos_ces::editarEvento(int row,int column)
{
    updating = reg_eventos.tabla->item(row,0)->text();
    llenarEventos();

    lines = new QList<QLineEdit*>();
    combos = new QList<QComboBox*>();

    lines->append(new QLineEdit(reg_eventos.tabla->item(row,0)->text()));
    reg_eventos.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit(reg_eventos.tabla->item(row,6)->text()));
    reg_eventos.tabla->setCellWidget(row,6,lines->last());

    QComboBox *aux = new QComboBox();
    aux->addItem("S");
    aux->addItem("N");
    aux->setCurrentIndex(aux->findText(reg_eventos.tabla->item(row,1)->text()));
    combos->append(aux);
    reg_eventos.tabla->setCellWidget(row,1,combos->last());
    aux = new QComboBox();
    aux->addItem("S");
    aux->addItem("N");
    aux->setCurrentIndex(aux->findText(reg_eventos.tabla->item(row,2)->text()));
    combos->append(aux);
    reg_eventos.tabla->setCellWidget(row,2,combos->last());
    aux = new QComboBox();
    aux->addItem("S");
    aux->addItem("N");
    aux->setCurrentIndex(aux->findText(reg_eventos.tabla->item(row,3)->text()));
    combos->append(aux);
    reg_eventos.tabla->setCellWidget(row,3,combos->last());
    aux = new QComboBox();
    aux->addItem("S");
    aux->addItem("N");
    aux->setCurrentIndex(aux->findText(reg_eventos.tabla->item(row,4)->text()));
    combos->append(aux);
    reg_eventos.tabla->setCellWidget(row,4,combos->last());
    aux = new QComboBox();
    aux->addItem("S");
    aux->addItem("N");
    aux->setCurrentIndex(aux->findText(reg_eventos.tabla->item(row,5)->text()));
    combos->append(aux);
    reg_eventos.tabla->setCellWidget(row,5,combos->last());

    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarEvento()));
    container.botonGuardar->setEnabled(true);
    connect(reg_eventos.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_eventos.tabla->cellWidget(row,6),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_ces::actualizarEvento()
{
    QSqlQuery consulta;

    if(consulta.exec("update eventos set id_evento='"+lines->at(0)->text()+"', descripcion='"+lines->at(1)->text()+"',in_curso='"+combos->at(0)->currentText()+"',in_seccion='"+combos->at(1)->currentText()+"',in_monto='"+combos->at(2)->currentText()+"',in_cantidad='"+combos->at(3)->currentText()+"',in_evaluacion='"+combos->at(4)->currentText()+"' where id_evento='"+updating+"'"))
    {
        consulta.exec("commit");
        llenarEventos();
        container.botonGuardar->setEnabled(false);
    }
    else
        QMessageBox::critical(0,"Error",consulta.lastError().text());
}


void procesos_ces::llenarEventos()
{
        QSqlQuery consulta;
        QTableWidgetItem *ni;
        int row,i;

        for(i=reg_eventos.tabla->rowCount()-1;i>=0;i--)
                reg_eventos.tabla->removeRow(i);

        consulta.exec("select * from eventos");
        while(consulta.next())
        {
                row = reg_eventos.tabla->rowCount();
                reg_eventos.tabla->insertRow(row);
                ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
                reg_eventos.tabla->setItem(row,0,ni);
                ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
                reg_eventos.tabla->setItem(row,1,ni);
                ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
                reg_eventos.tabla->setItem(row,2,ni);
                ni = new QTableWidgetItem(tr("%1").arg(consulta.value(4).toString()));
                reg_eventos.tabla->setItem(row,3,ni);
                ni = new QTableWidgetItem(tr("%1").arg(consulta.value(5).toString()));
                reg_eventos.tabla->setItem(row,4,ni);
                ni = new QTableWidgetItem(tr("%1").arg(consulta.value(6).toString()));
                reg_eventos.tabla->setItem(row,5,ni);
                ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
                reg_eventos.tabla->setItem(row,6,ni);
        }
}


void procesos_ces::nuevoEvento()
{
        QComboBox *aux;
        int row = reg_eventos.tabla->rowCount();
        reg_eventos.tabla->insertRow(row);

        lines = new QList<QLineEdit*>();
        combos = new QList<QComboBox*>();

        lines->append(new QLineEdit());
        reg_eventos.tabla->setCellWidget(row,0,lines->last());
        lines->append(new QLineEdit());
        reg_eventos.tabla->setCellWidget(row,6,lines->last());
        aux = new QComboBox();
        aux->addItem("S");
        aux->addItem("N");
        combos->append(aux);
        reg_eventos.tabla->setCellWidget(row,1,combos->last());
        aux = new QComboBox();
        aux->addItem("S");
        aux->addItem("N");
        combos->append(aux);
        reg_eventos.tabla->setCellWidget(row,2,combos->last());
        aux = new QComboBox();
        aux->addItem("S");
        aux->addItem("N");
        combos->append(aux);
        reg_eventos.tabla->setCellWidget(row,3,combos->last());
        aux = new QComboBox();
        aux->addItem("S");
        aux->addItem("N");
        combos->append(aux);
        reg_eventos.tabla->setCellWidget(row,4,combos->last());
        aux = new QComboBox();
        aux->addItem("S");
        aux->addItem("N");
        combos->append(aux);
        reg_eventos.tabla->setCellWidget(row,5,combos->last());

        disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
        connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarEvento()));
        container.botonGuardar->setEnabled(true);
        connect(reg_eventos.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
        connect(reg_eventos.tabla->cellWidget(row,6),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
        reg_eventos.tabla->setCurrentCell(row,0);
}


void procesos_ces::guardarEvento()
{
        QSqlQuery consulta;

        if(consulta.exec("insert into eventos values('"+lines->at(0)->text()+"','"+lines->at(1)->text()+"','"+combos->at(0)->currentText()+"','"+combos->at(1)->currentText()+"','"+combos->at(2)->currentText()+"','"+combos->at(3)->currentText()+"','"+combos->at(4)->currentText()+"')"))
        {
                consulta.exec("commit");
                llenarEventos();
                container.botonGuardar->setEnabled(false);
        }
        else
                QMessageBox::critical(0,"Error",consulta.lastError().text());


}


void procesos_ces::borrarEvento()
{
        int row= reg_eventos.tabla->currentRow();

        if(row>=0)
        {
                QSqlQuery consulta;
                if(consulta.exec("delete from eventos where id_evento='"+reg_eventos.tabla->item(row,0)->text()+"'"))
                        reg_eventos.tabla->removeRow(row);
                else
                        QMessageBox::critical(0,"Error",consulta.lastError().text());
        }
                else
                        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


void procesos_ces::registroCondiciones()
{
    frame = new QFrame();
    reg_condiciones.setupUi(frame);
    container.workspace->setWidget(frame);

    disconnect(container.botonNuevo,SIGNAL(clicked()),0,0);
    disconnect(container.botonAnular,SIGNAL(clicked()),0,0);
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevaCondicion()));
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarCondicion()));
    connect(reg_condiciones.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarCondicion(int,int)));
    container.botonNuevo->setEnabled(true);
    container.botonAnular->setEnabled(true);

    reg_condiciones.tabla->setColumnWidth(0,40);
    reg_condiciones.tabla->setColumnWidth(1,160);
    reg_condiciones.tabla->setColumnWidth(2,200);
    llenarCondiciones();
}

void procesos_ces::llenarCondiciones()
{
    QSqlQuery consulta,consulta2;
    int row,i;
    QTableWidgetItem *ni;

    for(i=reg_condiciones.tabla->rowCount()-1;i>=0;i--)
        reg_condiciones.tabla->removeRow(i);

    consulta.exec("select * from condiciones_especiales");
    while(consulta.next())
    {
        row = reg_condiciones.tabla->rowCount();
        reg_condiciones.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_condiciones.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_condiciones.tabla->setItem(row,1,ni);
        consulta2.exec("select descripcion from materiales where id_mat='"+consulta.value(2).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_condiciones.tabla->setItem(row,2,ni);
        }
    }
}


void procesos_ces::nuevaCondicion()
{
    QSqlQuery consulta;
    int row = reg_condiciones.tabla->rowCount();
    reg_condiciones.tabla->insertRow(row);
    QComboBox *aux= new QComboBox();

    lines = new QList<QLineEdit*>();
    combos = new QList<QComboBox*>();

    lines->append(new QLineEdit());
    reg_condiciones.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit());
    reg_condiciones.tabla->setCellWidget(row,1,lines->last());
    consulta.exec("select descripcion from materiales where tipo='D' order by descripcion");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    combos->append(aux);
    reg_condiciones.tabla->setCellWidget(row,2,combos->last());

    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarCondicion()));
    container.botonGuardar->setEnabled(true);
    connect(reg_condiciones.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_condiciones.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    reg_condiciones.tabla->setCurrentCell(row,0);
}


void procesos_ces::guardarCondicion()
{
    QString descuento;
    QSqlQuery consulta;

    consulta.exec("select id_mat from materiales where descripcion='"+combos->at(0)->currentText()+"'");
    while(consulta.next())
    {
        descuento=consulta.value(0).toString();
    }
    if(!consulta.exec("insert into condiciones_especiales values('"+lines->at(0)->text()+"','"+lines->at(1)->text()+"','"+descuento+"')"))
        QMessageBox::critical(0,"Error Nueva Condicion",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        container.botonGuardar->setEnabled(false);
        llenarCondiciones();
    }
}


void procesos_ces::editarCondicion(int row,int column)
{
    QSqlQuery consulta;
    updating= reg_condiciones.tabla->item(row,0)->text();
    lines = new QList<QLineEdit*>();
    combos = new QList<QComboBox*>();

    QComboBox *aux = new QComboBox();

    lines->append(new QLineEdit(reg_condiciones.tabla->item(row,0)->text()));
    reg_condiciones.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit(reg_condiciones.tabla->item(row,1)->text()));
    reg_condiciones.tabla->setCellWidget(row,1,lines->last());
    consulta.exec("select descripcion from materiales where tipo='D' order by descripcion");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    aux->setCurrentIndex(aux->findText(reg_condiciones.tabla->item(row,2)->text()));
    combos->append(aux);
    reg_condiciones.tabla->setCellWidget(row,2,combos->last());

    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarCondicion()));
    container.botonGuardar->setEnabled(true);
    connect(reg_condiciones.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_condiciones.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_ces::actualizarCondicion()
{
    QString descuento;
    QSqlQuery consulta;

    consulta.exec("select id_mat from materiales where descripcion='"+combos->at(0)->currentText()+"'");
    while(consulta.next())
    {
        descuento=consulta.value(0).toString();
    }
    if(!consulta.exec("update condiciones_especiales set id_condicion ='"+lines->at(0)->text()+"',descripcion='"+lines->at(1)->text()+"', descuento='"+descuento+"' where id_condicion='"+updating+"'"))
        QMessageBox::critical(0,"Error Actualizar Condicion",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        container.botonGuardar->setEnabled(false);
        llenarCondiciones();
    }
}


void procesos_ces::borrarCondicion()
{
    int row= reg_condiciones.tabla->currentRow();
    if(row>=0)
    {
        QSqlQuery consulta;
        if(consulta.exec("delete from condiciones_especiales where id_condicion='"+reg_condiciones.tabla->item(row,0)->text()+"'"))
            reg_condiciones.tabla->removeRow(row);
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


void procesos_ces::registroTipoEst()
{
    frame = new QFrame();
    reg_tipoest.setupUi(frame);
    container.workspace->setWidget(frame);

    disconnect(container.botonNuevo,SIGNAL(clicked()),0,0);
    disconnect(container.botonAnular,SIGNAL(clicked()),0,0);
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoTipoEst()));
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarTipoEst()));
    connect(reg_tipoest.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarTipoEst(int,int)));
    container.botonNuevo->setEnabled(true);
    container.botonAnular->setEnabled(true);

    reg_tipoest.tabla->setColumnWidth(0,40);
    reg_tipoest.tabla->setColumnWidth(1,160);
    reg_tipoest.tabla->setColumnWidth(2,200);
    llenarTipoEst();
}

void procesos_ces::llenarTipoEst()
{
    QSqlQuery consulta;
    int row,i;
    QTableWidgetItem *ni;

    for(i=reg_tipoest.tabla->rowCount()-1;i>=0;i--)
        reg_tipoest.tabla->removeRow(i);

    consulta.exec("select * from tipo_estudiante");
    while(consulta.next())
    {
        row = reg_tipoest.tabla->rowCount();
        reg_tipoest.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_tipoest.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_tipoest.tabla->setItem(row,1,ni);
    }
}


void procesos_ces::nuevoTipoEst()
{
    int row = reg_tipoest.tabla->rowCount();
    reg_tipoest.tabla->insertRow(row);
    //QComboBox *aux= new QComboBox();

    lines = new QList<QLineEdit*>();

    lines->append(new QLineEdit());
    reg_tipoest.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit());
    reg_tipoest.tabla->setCellWidget(row,1,lines->last());

    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarTipoEst()));
    container.botonGuardar->setEnabled(true);
    connect(reg_tipoest.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_tipoest.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    reg_tipoest.tabla->setCurrentCell(row,0);
}


void procesos_ces::guardarTipoEst()
{
    QSqlQuery consulta;

    if(!consulta.exec("insert into tipo_estudiante values('"+lines->at(0)->text()+"','"+lines->at(1)->text()+"')"))
        QMessageBox::critical(0,"Error Nuevo Tipo Estudiante",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        container.botonGuardar->setEnabled(false);
        llenarTipoEst();
    }
}


void procesos_ces::editarTipoEst(int row,int column)
{
    QSqlQuery consulta;
    updating= reg_tipoest.tabla->item(row,0)->text();
    lines = new QList<QLineEdit*>();

    lines->append(new QLineEdit(reg_tipoest.tabla->item(row,0)->text()));
    reg_tipoest.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit(reg_tipoest.tabla->item(row,1)->text()));
    reg_tipoest.tabla->setCellWidget(row,1,lines->last());

    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarTipoEst()));
    container.botonGuardar->setEnabled(true);
    connect(reg_tipoest.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_tipoest.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_ces::actualizarTipoEst()
{
    QSqlQuery consulta;

    if(!consulta.exec("update tipo_estudiante set id_tipo_est ='"+lines->at(0)->text()+"',descripcion='"+lines->at(1)->text()+"' where id_tipo_est='"+updating+"'"))
        QMessageBox::critical(0,"Error Actualizar Tipo Estudiante",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        container.botonGuardar->setEnabled(false);
        llenarTipoEst();
    }
}


void procesos_ces::borrarTipoEst()
{
    int row= reg_tipoest.tabla->currentRow();
    if(row>=0)
    {
        QSqlQuery consulta;
        if(consulta.exec("delete from tipo_estudiante where id_tipo_est='"+reg_tipoest.tabla->item(row,0)->text()+"'"))
            reg_tipoest.tabla->removeRow(row);
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


void procesos_ces::setFichaAcademica()
{
    frame = new QFrame();
    ficha_academica.setupUi(frame);
    container.workspace->setWidget(frame);
    ficha_academica.tabla->setColumnWidth(0,50);
    ficha_academica.tabla->setColumnWidth(1,50);
    ficha_academica.tabla->setColumnWidth(2,160);
    ficha_academica.tabla->setColumnWidth(3,120);
    ficha_academica.tabla->setColumnWidth(4,120);
    ficha_academica.tabla->setColumnWidth(5,90);
    ficha_academica.tabla->setColumnWidth(6,90);
    ficha_academica.tabla->setColumnWidth(7,50);
    ficha_academica.tabla->setColumnWidth(8,160);
    connect(ficha_academica.matricula,SIGNAL(returnPressed()),this,SLOT(matriculaChanged()));
    connect(ficha_academica.cedula,SIGNAL(returnPressed()),this,SLOT(cedulaChanged()));
    disconnect(container.botonNuevo,SIGNAL(clicked()),0,0);
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoEventoAcademico()));
    disconnect(container.botonAnular,SIGNAL(clicked()),0,0);
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarEventoAcademico()));
    connect(ficha_academica.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarEventoAcademico(int,int)));
    container.botonNuevo->setEnabled(true);
    container.botonAnular->setEnabled(true);
}

void procesos_ces::cedulaChanged()
{
    QSqlQuery consulta;
    ficha_academica.matricula->clear();
    ficha_academica.nombre->clear();
    llenarFichaAcademica("");
    consulta.exec("select nombre,matricula,apellido from estudiante where cedula_est='"+ficha_academica.cedula->text()+"'");
    while(consulta.next())
    {
        ficha_academica.matricula->setText(consulta.value(1).toString());
        ficha_academica.nombre->setText(consulta.value(0).toString()+" "+consulta.value(2).toString());
        llenarFichaAcademica(consulta.value(1).toString());
    }
}


void procesos_ces::matriculaChanged()
{
    QSqlQuery consulta;
    QString matricula;
    ficha_academica.cedula->clear();
    ficha_academica.nombre->clear();
    llenarFichaAcademica("");
    matricula=ficha_academica.matricula->text();
    consulta.exec("select cedula_est,nombre,apellido from estudiante where matricula='"+matricula+"'");
    while(consulta.next())
    {
        ficha_academica.cedula->setText(consulta.value(0).toString());
        ficha_academica.nombre->setText(consulta.value(1).toString()+" "+consulta.value(2).toString());
        llenarFichaAcademica(matricula);
        container.botonImprimir->setEnabled(true);
        connect(container.botonImprimir,SIGNAL(clicked()),this,SLOT(imprimirFichaAcademica()));
    }
}


void procesos_ces::llenarFichaAcademica(QString s)
{
    QSqlQuery consulta,consulta2;
    QTableWidgetItem *ni;
    int row,i;

    for(i=ficha_academica.tabla->rowCount()-1;i>=0;i--)
        ficha_academica.tabla->removeRow(i);

    consulta.exec("select renglon,id_evento,to_char(fecha,'dd-mm-yyyy'),calificacion,observacion,id_seccion,id_curso,matricula,to_char(fec_inicio,'dd-mm-yyyy') from ficha_academica where matricula='"+s+"' order by fecha");
    while(consulta.next())
    {
        row = ficha_academica.tabla->rowCount();
        ficha_academica.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        ficha_academica.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        ficha_academica.tabla->setItem(row,1,ni);
        consulta2.exec("select descripcion from eventos where id_evento='"+consulta.value(1).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            ficha_academica.tabla->setItem(row,2,ni);
        }
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(6).toString()));
        ficha_academica.tabla->setItem(row,3,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(5).toString()));
        ficha_academica.tabla->setItem(row,4,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        ficha_academica.tabla->setItem(row,5,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(8).toString()));
        ficha_academica.tabla->setItem(row,6,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        ficha_academica.tabla->setItem(row,7,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(4).toString()));
        ficha_academica.tabla->setItem(row,8,ni);
    }
}


void procesos_ces::nuevoEventoAcademico()
{
    int row = ficha_academica.tabla->rowCount();
    ficha_academica.tabla->insertRow(row);
    QSqlQuery consulta;
    QComboBox *aux= new QComboBox();
    combos = new QList<QComboBox*>();
    lines = new QList<QLineEdit*>();
    inicios = new QList<QDateEdit*>();

    lines->append(new QLineEdit());
    ficha_academica.tabla->setCellWidget(row,1,lines->last());
    lines->append(new QLineEdit());
    ficha_academica.tabla->setCellWidget(row,2,lines->last());

    if(prog_academico=="3")
    {
        //consulta.exec("select id_diplomado from diplomados");
        consulta.exec("select id_diplomado from diplo_temp order by id_diplomado");
        while(consulta.next())
        {
            aux->addItem(consulta.value(0).toString());
        }
    }
    else
    {
        consulta.exec("select id_metodo from metodos where prog_academico='"+prog_academico+"' order by id_metodo");
        while(consulta.next())
        {
            aux->addItem(consulta.value(0).toString());
        }
    }
    combos->append(aux);
    ficha_academica.tabla->setCellWidget(row,3,combos->last());
    lines->append(new QLineEdit());
    ficha_academica.tabla->setCellWidget(row,4,lines->last());
    lines->append(new QLineEdit());
    ficha_academica.tabla->setCellWidget(row,7,lines->last());
    lines->append(new QLineEdit());
    ficha_academica.tabla->setCellWidget(row,8,lines->last());
    inicios->append(new QDateEdit());
    ficha_academica.tabla->setCellWidget(row,5,inicios->last());
    inicios->append(new QDateEdit());
    ficha_academica.tabla->setCellWidget(row,6,inicios->last());

    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarEventoAcademico()));
    container.botonGuardar->setEnabled(true);
    connect(ficha_academica.tabla->cellWidget(row,1),SIGNAL(textChanged(QString)),this,SLOT(descEvento(QString)));
    connect(ficha_academica.tabla->cellWidget(row,3),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(ficha_academica.tabla->cellWidget(row,4),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(ficha_academica.tabla->cellWidget(row,8),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    ficha_academica.tabla->setCurrentCell(row,0);
}


void procesos_ces::editarEventoAcademico(int row,int column)
{
    updating = ficha_academica.tabla->item(row,0)->text();//Deberia ser el renglon para actualizar mas facil
    llenarFichaAcademica(ficha_academica.matricula->text());
    QSqlQuery consulta;
    lines = new QList<QLineEdit*>();
    inicios = new QList<QDateEdit*>();
    combos = new QList<QComboBox*>();
    QComboBox *aux = new QComboBox;

    lines->append(new QLineEdit(ficha_academica.tabla->item(row,1)->text()));
    ficha_academica.tabla->setCellWidget(row,1,lines->last());
    lines->append(new QLineEdit(ficha_academica.tabla->item(row,2)->text()));
    ficha_academica.tabla->setCellWidget(row,2,lines->last());

    if(prog_academico=="3")
    {
        //consulta.exec("select id_diplomado from diplomados");
        consulta.exec("select id_diplomado from diplo_temp order by id_diplomado");
        while(consulta.next())
        {
            aux->addItem(consulta.value(0).toString());
        }
    }
    else
    {
        consulta.exec("select id_metodo from metodos where prog_academico='"+prog_academico+"' order by id_metodo");
        while(consulta.next())
        {
            aux->addItem(consulta.value(0).toString());
        }
    }
    aux->setCurrentIndex(aux->findText(ficha_academica.tabla->item(row,3)->text()));
    combos->append(aux);
    ficha_academica.tabla->setCellWidget(row,3,combos->last());
    lines->append(new QLineEdit(ficha_academica.tabla->item(row,4)->text()));
    ficha_academica.tabla->setCellWidget(row,4,lines->last());
    lines->append(new QLineEdit(ficha_academica.tabla->item(row,7)->text()));
    ficha_academica.tabla->setCellWidget(row,7,lines->last());
    lines->append(new QLineEdit(ficha_academica.tabla->item(row,8)->text()));
    ficha_academica.tabla->setCellWidget(row,8,lines->last());
    inicios->append(new QDateEdit(QDate::fromString(ficha_academica.tabla->item(row,5)->text(),"dd-MM-yyyy")));
    ficha_academica.tabla->setCellWidget(row,5,inicios->last());
    inicios->append(new QDateEdit(QDate::fromString(ficha_academica.tabla->item(row,6)->text(),"dd-MM-yyyy")));
    ficha_academica.tabla->setCellWidget(row,6,inicios->last());

    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarEventoAcademico()));
    container.botonGuardar->setEnabled(true);
    connect(ficha_academica.tabla->cellWidget(row,1),SIGNAL(textChanged(QString)),this,SLOT(descEvento(QString)));
    connect(ficha_academica.tabla->cellWidget(row,3),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(ficha_academica.tabla->cellWidget(row,4),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(ficha_academica.tabla->cellWidget(row,8),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_ces::descEvento(QString s)
{
    QSqlQuery consulta("select descripcion from eventos where id_evento='"+s+"'");
    while(consulta.next())
    {
        lines->at(1)->setText(consulta.value(0).toString());
        lines->at(1)->setEnabled(false);
    }
}


void procesos_ces::guardarEventoAcademico()
{
    QSqlQuery consulta;

    //if(
    if(!consulta.exec("insert into ficha_academica values(ficha_academica_s.nextval,'"+lines->at(0)->text()+"',to_date('"+inicios->at(0)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+lines->at(3)->text()+"','"+lines->at(4)->text()+"','"+lines->at(2)->text()+"','"+combos->at(0)->currentText()+"','"+ficha_academica.matricula->text()+"','V',to_date('"+inicios->at(1)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'))"))
        QMessageBox::critical(0,"Error",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        container.botonGuardar->setEnabled(false);
        llenarFichaAcademica(ficha_academica.matricula->text());
    }
}


void procesos_ces::actualizarEventoAcademico()
{
    QSqlQuery consulta;

    if(!consulta.exec("update ficha_academica set id_evento='"+lines->at(0)->text()+"',fecha=to_date('"+inicios->at(0)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),calificacion='"+lines->at(3)->text()+"',observacion='"+lines->at(4)->text()+"',id_seccion='"+lines->at(2)->text()+"',id_curso='"+combos->at(0)->currentText()+"',matricula='"+ficha_academica.matricula->text()+"',status='V',fec_inicio=to_date('"+inicios->at(1)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy') where renglon='"+updating+"'"))
        QMessageBox::critical(0,"Error",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        container.botonGuardar->setEnabled(false);
        llenarFichaAcademica(ficha_academica.matricula->text());
    }
}


void procesos_ces::borrarEventoAcademico()
{
    int row= ficha_academica.tabla->currentRow();

    if(row>=0)
    {
        QSqlQuery consulta;
        if(consulta.exec("delete from ficha_academica where renglon='"+ficha_academica.tabla->item(row,0)->text()+"'"))
        {
            consulta.exec("commit");
            ficha_academica.tabla->removeRow(row);
        }
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}


void procesos_ces::imprimirFichaAcademica()
{
        QString dir,query,calendario,metodo,fecha_inicio,modalidad;
        QSqlQuery consulta,consulta2,consulta3;
        QList<QList<QString> > lista;
        QList<QString> fila;
        int i;
        report->reset();
        QStandardItemModel *model = new QStandardItemModel(1,7);
        QStandardItem *item;

        consulta.exec("select telf_hab,telf_cel,ciudad,email,sexo,edo_civil,profesion,to_char(fecha_nac,'dd-mm-yyyy'),id_zona from estudiante where matricula='"+ficha_academica.matricula->text()+"'");
        while(consulta.next())
        {
                consulta2.exec("select descripcion from zonas where id_zona='"+consulta.value(8).toString()+"'");
                while(consulta2.next())
                {
                        dir = consulta2.value(0).toString()+", "+consulta.value(2).toString();
                }
                report->addParameter("nombre",ficha_academica.nombre->text());
                report->addParameter("cedula",ficha_academica.cedula->text());
                report->addParameter("fecha_nac",consulta.value(7).toString());
                report->addParameter("lugar_nac","");
                report->addParameter("edad","");
                report->addParameter("sexo",consulta.value(4).toString());
                report->addParameter("edo_civil",consulta.value(5).toString());
                report->addParameter("profesion",consulta.value(6).toString());
                report->addParameter("telf",consulta.value(0).toString());
                report->addParameter("celular",consulta.value(1).toString());
                report->addParameter("dir",dir);

        }
        consulta.exec("select id_metodo from ficha_academica where matricula='"+ficha_academica.matricula->text()+"' and id_evento='21' and status='V'");
        while(consulta.next())
        {
                metodo=consulta.value(0).toString();
        }
        consulta.exec("select fecha,calificacion,id_seccion from ficha_academica where matricula='"+ficha_academica.matricula->text()+"' and id_evento='21' and id_metodo='"+metodo+"'");
        while(consulta.next())
        {
                fila.clear();
                if(consulta2.exec("select nivel,horario,cedula_prof,modalidad from secciones where id_seccion='"+consulta.value(2).toString()+"'"))
                while(consulta2.next())
                {
                        fila.append(consulta2.value(1).toString());
                        fila.append(consulta2.value(2).toString());
                        modalidad=consulta2.value(3).toString();
                        consulta3.exec("select nombre from profesor where cedula_prof='"+consulta2.value(3).toString()+"'");
                        while(consulta3.next())
                        {
                                fila.append(consulta3.value(0).toString());
                        }
                        consulta3.exec("select id_calendario from metodos where id_metodo='"+metodo+"'");
                        while(consulta3.next())
                        {
                                calendario=consulta3.value(0).toString();
                        }
                }

                fila.append(consulta.value(1).toString());

                consulta2.exec("select periodo,fecha_fin from calendarios_detalle where id_calendario='"+calendario+"' and modalidad ='"+modalidad+"' and fecha_ini<='"+consulta.value(0).toString()+"' and fecha_fin>='"+consulta.value(0).toString()+"'");
                while(consulta2.next())
                {
                        fila.append(consulta2.value(0).toString());
                        fila.append(consulta2.value(1).toString());
                }

                lista.append(fila);
        }

        consulta.exec("select to_char(fecha,'dd-mm-yyyy') from ficha_pago where id_evento=1 and matricula='"+ficha_academica.matricula->text()+"'");//revisar
        while(consulta.next())
        {
                fecha_inicio=consulta.value(0).toString();
        }

        if(metodo=="AEC")
        {
                report->addParameter("i1","x");
                report->addParameter("fec_ini1",fecha_inicio);
                report->addParameter("fec_fin1","");
        }
        //if(metodo=="") todos los metodos de ingles y otros idiomas

        for(i=0;i<lista.count();i++)
        {
                fila=lista[i];
                item = new QStandardItem();
                item->setData(fila[1],Qt::EditRole);
                model->setItem(i,0,item);
                item = new QStandardItem();
                item->setData(fila[3],Qt::EditRole);
                model->setItem(i,1,item);
                item = new QStandardItem();
                item->setData(fila[4],Qt::EditRole);
                model->setItem(i,2,item);
                item = new QStandardItem();
                item->setData(fila[5],Qt::EditRole);
                model->setItem(i,3,item);
                item = new QStandardItem();
                item->setData(fila[1],Qt::EditRole);
                model->setItem(i,4,item);
                item = new QStandardItem();
                item->setData(fila[2],Qt::EditRole);
                model->setItem(i,5,item);
                item = new QStandardItem();
                item->setData("",Qt::EditRole);
                model->setItem(i,6,item);
                //falta la condicion
        }

        report->addItemModel( model, "model" );
        report->setReportFile("reportes/ficha_academica_idiomas.xml");
        report->runReportToPDF("test.pdf");
        if (!report->hasError())
        {
                ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        }
        else
                QMessageBox::information(0,"Error",report->lastErrorMsg());
}


void procesos_ces::llenarNivel()
{
    QString nivel;
    QSqlQuery consulta,consulta2,consulta3;

    consulta.exec("select matricula,to_char(fecha,'dd-mm-yyyy') from ficha_pago order by fecha");
    while(consulta.next())
    {
        //QMessageBox::information(0,"","select id_seccion from ficha_academica where matricula='"+consulta.value(0).toString()+"' and fecha=to_date('"+consulta.value(1).toString()+"','dd-mm-yyyy') and id_evento=2");
        consulta2.exec("select id_seccion from ficha_academica where matricula='"+consulta.value(0).toString()+"' and fecha=to_date('"+consulta.value(1).toString()+"','dd-mm-yyyy') and id_evento=2");
        while(consulta2.next())
        {
            consulta3.exec("select nivel from secciones where id_seccion='"+consulta2.value(0).toString()+"'");
            while(consulta3.next())
            {
                nivel=consulta3.value(0).toString();
            }
        }
        //QMessageBox::information(0,"","update ficha_pago set nivel='"+nivel+"' where matricula='"+consulta.value(0).toString()+"' and fecha=to_date('"+consulta.value(1).toString()+"','dd-mm-yyyy')");
        if(!consulta2.exec("update ficha_pago set nivel='"+nivel+"' where matricula='"+consulta.value(0).toString()+"' and fecha=to_date('"+consulta.value(1).toString()+"','dd-mm-yyyy')"))
        {
            return;
        }

    }
    consulta.exec("commit");
}

void procesos_ces::setFichaPago()
{
    cfp=false;
    frame = new QFrame();
    ficha_pago.setupUi(frame);
    container.workspace->setWidget(frame);
    ficha_pago.tabla->setColumnWidth(0,50);
    ficha_pago.tabla->setColumnWidth(1,50);
    ficha_pago.tabla->setColumnWidth(2,160);
    ficha_pago.tabla->setColumnWidth(3,90);
    ficha_pago.tabla->setColumnWidth(4,60);
    ficha_pago.tabla->setColumnWidth(5,90);
    ficha_pago.tabla->setColumnWidth(6,60);
    ficha_pago.tabla->setColumnWidth(7,90);
    ficha_pago.tabla->setColumnWidth(8,50);
    ficha_pago.tabla->setColumnWidth(9,160);
    connect(ficha_pago.matricula,SIGNAL(returnPressed()),this,SLOT(matriculaPagoChanged()));
    connect(ficha_pago.cedula,SIGNAL(returnPressed()),this,SLOT(cedulaPagoChanged()));
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoEventoPago()));
    connect(ficha_pago.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarEventoPago(int,int)));
    container.botonNuevo->setEnabled(true);
}


void procesos_ces::setFichaPagoCFP()
{
    cfp=true;
    frame = new QFrame();
    ficha_pago.setupUi(frame);
    container.workspace->setWidget(frame);
    ficha_pago.tabla->setColumnCount(9);
    ficha_pago.tabla->setColumnWidth(0,60);
    ficha_pago.tabla->setColumnWidth(1,50);
    ficha_pago.tabla->setColumnWidth(2,160);
    ficha_pago.tabla->setColumnWidth(3,90);
    ficha_pago.tabla->setColumnWidth(4,60);
    ficha_pago.tabla->setColumnWidth(5,90);
    ficha_pago.tabla->setColumnWidth(6,90);
    ficha_pago.tabla->setColumnWidth(7,90);
    ficha_pago.tabla->setColumnWidth(8,90);

    QStringList labels=(QStringList() << "Renglon "<< "Codigo" << "Descripcion" << "Fecha" << "Monto" << "Factura" << "Ultima Cuota" << "Acumulado" << "Diplomado");
    ficha_pago.tabla->setHorizontalHeaderLabels(labels);

    connect(ficha_pago.matricula,SIGNAL(returnPressed()),this,SLOT(matriculaPagoChanged()));
    connect(ficha_pago.cedula,SIGNAL(returnPressed()),this,SLOT(cedulaPagoChanged()));
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoEventoPago()));
    connect(ficha_pago.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarEventoPago(int,int)));

    container.botonNuevo->setEnabled(true);
}


void procesos_ces::matriculaPagoChanged()
{
    QSqlQuery consulta;
    QString matricula;
    ficha_pago.cedula->clear();
    ficha_pago.nombre->clear();
    llenarFichaPago("");
    matricula=ficha_pago.matricula->text();
    consulta.exec("select cedula_est,nombre,apellido from estudiante where matricula='"+matricula+"'");
    while(consulta.next())
    {
        ficha_pago.cedula->setText(consulta.value(0).toString());
        ficha_pago.nombre->setText(consulta.value(1).toString()+" "+consulta.value(2).toString());
        llenarFichaPago(matricula);
    }
}


void procesos_ces::cedulaPagoChanged()
{
    QSqlQuery consulta;
    ficha_pago.matricula->clear();
    ficha_pago.nombre->clear();
    llenarFichaPago("");
    consulta.exec("select nombre,matricula,apellido from estudiante where cedula_est='"+ficha_pago.cedula->text()+"'");
    while(consulta.next())
    {
        ficha_pago.matricula->setText(consulta.value(1).toString());
        ficha_pago.nombre->setText(consulta.value(0).toString()+" "+consulta.value(2).toString());
        llenarFichaPago(consulta.value(1).toString());
    }
}


void procesos_ces::llenarFichaPago(QString s)
{
    QSqlQuery consulta,consulta2,consulta3;
    QTableWidgetItem *ni;
    int row,i;

    for(i=ficha_pago.tabla->rowCount()-1;i>=0;i--)
        ficha_pago.tabla->removeRow(i);

    if(!cfp)
    {
        consulta.exec("select renglon,id_evento,to_char(fecha,'dd-mm-yyyy'),cuota_o_libro,monto,id_fact,observacion,nivel from ficha_pago where matricula='"+s+"' order by fecha,renglon");
        while(consulta.next())
        {
            row = ficha_pago.tabla->rowCount();
            ficha_pago.tabla->insertRow(row);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
            ficha_pago.tabla->setItem(row,0,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
            ficha_pago.tabla->setItem(row,1,ni);
            consulta2.exec("select descripcion from eventos where id_evento='"+consulta.value(1).toString()+"'");
            while(consulta2.next())
            {
                ni = new QTableWidgetItem(consulta2.value(0).toString());
                ficha_pago.tabla->setItem(row,2,ni);
            }
            ni = new QTableWidgetItem(consulta.value(2).toString());
            ficha_pago.tabla->setItem(row,3,ni);

            ni = new QTableWidgetItem(consulta.value(7).toString());
            ficha_pago.tabla->setItem(row,4,ni);

            consulta2.exec("select id_seccion,to_char(fec_inicio,'dd-mm-yyyy') from ficha_academica where matricula='"+s+"' and fecha=to_date('"+consulta.value(2).toString()+"','dd-mm-yyyy') and id_evento=2");
            while(consulta2.next())
            {
                /*consulta3.exec("select nivel from secciones where id_seccion='"+consulta2.value(0).toString()+"'");
                while(consulta3.next())
                {
                    ni = new QTableWidgetItem(consulta3.value(0).toString());
                    ficha_pago.tabla->setItem(row,4,ni);
                }*/
                ni = new QTableWidgetItem(consulta2.value(1).toString());
                ficha_pago.tabla->setItem(row,5,ni);
            }
            ni = new QTableWidgetItem(consulta.value(3).toString());
            ficha_pago.tabla->setItem(row,6,ni);
            ni = new QTableWidgetItem(consulta.value(4).toString());
            ficha_pago.tabla->setItem(row,7,ni);
            ni = new QTableWidgetItem(consulta.value(5).toString());
            ficha_pago.tabla->setItem(row,8,ni);
        }
    }
    else
    {
        consulta.exec("select renglon,id_evento,to_char(fecha,'dd-mm-yyyy'),monto,id_fact,ult_cuota,acumulado,id_diplomado from ficha_pago_cfp where matricula='"+s+"' order by fecha");
        while(consulta.next())
        {
            row = ficha_pago.tabla->rowCount();
            ficha_pago.tabla->insertRow(row);
            ni = new QTableWidgetItem(consulta.value(0).toString());
            ficha_pago.tabla->setItem(row,0,ni);
            ni = new QTableWidgetItem(consulta.value(1).toString());
            ficha_pago.tabla->setItem(row,1,ni);
            consulta2.exec("select descripcion from eventos where id_evento='"+consulta.value(1).toString()+"'");
            while(consulta2.next())
            {
                ni = new QTableWidgetItem(consulta2.value(0).toString());
                ficha_pago.tabla->setItem(row,2,ni);
            }
            ni = new QTableWidgetItem(consulta.value(2).toString());
            ficha_pago.tabla->setItem(row,3,ni);
            ni = new QTableWidgetItem(consulta.value(3).toString());
            ficha_pago.tabla->setItem(row,4,ni);
            ni = new QTableWidgetItem(consulta.value(4).toString());
            ficha_pago.tabla->setItem(row,5,ni);
            ni = new QTableWidgetItem(consulta.value(5).toString());
            ficha_pago.tabla->setItem(row,6,ni);
            ni = new QTableWidgetItem(consulta.value(6).toString());
            ficha_pago.tabla->setItem(row,7,ni);
            ni = new QTableWidgetItem(consulta.value(7).toString());
            ficha_pago.tabla->setItem(row,8,ni);
        }
    }
}


void procesos_ces::nuevoEventoPago()
{
    int row = ficha_pago.tabla->rowCount();
    ficha_pago.tabla->insertRow(row);
    QSqlQuery consulta;

    lines = new QList<QLineEdit*>();
    inicios = new QList<QDateEdit*>();

    if(!cfp)
    {
        lines->append(new QLineEdit());
        ficha_pago.tabla->setCellWidget(row,1,lines->last());
        lines->append(new QLineEdit());
        ficha_pago.tabla->setCellWidget(row,2,lines->last());
        inicios->append(new QDateEdit());
        ficha_pago.tabla->setCellWidget(row,3,inicios->last());
        lines->append(new QLineEdit());
        ficha_pago.tabla->setCellWidget(row,4,lines->last());
        inicios->append(new QDateEdit());
        ficha_pago.tabla->setCellWidget(row,5,inicios->last());
        lines->append(new QLineEdit());
        ficha_pago.tabla->setCellWidget(row,6,lines->last());
        lines->append(new QLineEdit());
        ficha_pago.tabla->setCellWidget(row,7,lines->last());
        lines->append(new QLineEdit());
        ficha_pago.tabla->setCellWidget(row,8,lines->last());
        lines->append(new QLineEdit());
        ficha_pago.tabla->setCellWidget(row,9,lines->last());

        connect(ficha_pago.tabla->cellWidget(row,8),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
        connect(ficha_pago.tabla->cellWidget(row,9),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    }
    else
    {
        lines->append(new QLineEdit());
        ficha_pago.tabla->setCellWidget(row,1,lines->last());
        lines->append(new QLineEdit());
        ficha_pago.tabla->setCellWidget(row,2,lines->last());
        inicios->append(new QDateEdit());
        ficha_pago.tabla->setCellWidget(row,3,inicios->last());
        lines->append(new QLineEdit());
        ficha_pago.tabla->setCellWidget(row,4,lines->last());
        lines->append(new QLineEdit());
        ficha_pago.tabla->setCellWidget(row,5,lines->last());
        lines->append(new QLineEdit());
        ficha_pago.tabla->setCellWidget(row,6,lines->last());
        //lines->append(new QLineEdit());
        //ficha_pago.tabla->setCellWidget(row,7,lines->last());

        connect(ficha_pago.tabla->cellWidget(row,4),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
        connect(ficha_pago.tabla->cellWidget(row,5),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    }

    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarEventoPago()));
    container.botonGuardar->setEnabled(true);
    connect(ficha_pago.tabla->cellWidget(row,1),SIGNAL(textChanged(QString)),this,SLOT(descEvento(QString)));
    connect(ficha_pago.tabla->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(ficha_pago.tabla->cellWidget(row,6),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(ficha_pago.tabla->cellWidget(row,7),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    ficha_pago.tabla->setCurrentCell(row,0);
}


void procesos_ces::editarEventoPago(int row,int column)
{
    QSqlQuery consulta;
    lines = new QList<QLineEdit*>();
    inicios = new QList<QDateEdit*>();

    updating=ficha_pago.tabla->item(row,0)->text();

    if(cfp)
    {
        lines->append(new QLineEdit(ficha_pago.tabla->item(row,4)->text()));
        ficha_pago.tabla->setCellWidget(row,4,lines->last());
        lines->append(new QLineEdit(ficha_pago.tabla->item(row,6)->text()));
        ficha_pago.tabla->setCellWidget(row,6,lines->last());
        lines->append(new QLineEdit(ficha_pago.tabla->item(row,8)->text()));
        ficha_pago.tabla->setCellWidget(row,8,lines->last());
        connect(ficha_pago.tabla->cellWidget(row,8),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    }
    else
    {
        lines->append(new QLineEdit(ficha_pago.tabla->item(row,4)->text()));
        ficha_pago.tabla->setCellWidget(row,4,lines->last());
        lines->append(new QLineEdit(ficha_pago.tabla->item(row,6)->text()));
        ficha_pago.tabla->setCellWidget(row,6,lines->last());
    }
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarEventoPago()));
    container.botonGuardar->setEnabled(true);
}


void procesos_ces::actualizarEventoPago()
{
    QSqlQuery consulta;
    double acumulado=0;

    if(cfp)
    {
        if(lines->at(0)->text() != "2")
        {
            consulta.exec("select acumulado from ficha_pago_cfp where matricula='"+ficha_pago.matricula->text()+"' and renglon=(select max(renglon) from ficha_pago_cfp where matricula='"+ficha_pago.matricula->text()+"' and renglon < '"+updating+"')");
            while(consulta.next())
            {
                acumulado=consulta.value(0).toDouble();
            }
        }
        acumulado+=lines->at(0)->text().toDouble();
        if(!consulta.exec("update ficha_pago_cfp set monto='"+lines->at(0)->text()+"', ult_cuota='"+lines->at(1)->text()+"', acumulado='"+tr("%1").arg(acumulado)+"', id_diplomado='"+lines->at(2)->text()+"' where renglon='"+updating+"'"))
            QMessageBox::critical(0,"Error",consulta.lastError().text());
        else
        {
            consulta.exec("commit");
            container.botonGuardar->setEnabled(false);
            llenarFichaPago(ficha_pago.matricula->text());
        }
    }
    else
    {
        if(!consulta.exec("update ficha_pago set nivel= '"+lines->at(0)->text()+"', cuota_o_libro='"+lines->at(1)->text()+"' where renglon='"+updating+"'"))
            QMessageBox::critical(0,"Error",consulta.lastError().text());
        else
        {
            consulta.exec("commit");
            container.botonGuardar->setEnabled(false);
            llenarFichaPago(ficha_pago.matricula->text());
        }
    }
}


void procesos_ces::guardarEventoPago()
{
    QSqlQuery consulta;
    QString diplo;
    if(cfp)
    {
        //acumulado
        double acumulado=0;

        consulta.exec("select id_curso from ficha_academica where matricula='"+ficha_pago.matricula->text()+"' and (id_evento='2' or id_evento='47') and status='V'");
        while(consulta.next()) //no buscar por fecha - afecta la busqueda de abajo
        {
            diplo=consulta.value(0).toString();
        }

        if(lines->at(0)->text() != "2")
        {
            consulta.exec("select acumulado from ficha_pago_cfp where matricula='"+ficha_pago.matricula->text()+"' and id_diplomado='"+diplo+"' and renglon=(select max(renglon) from ficha_pago_cfp where matricula='"+ficha_pago.matricula->text()+"' and id_diplomado='"+diplo+"')");
            while(consulta.next())
            {
                acumulado=consulta.value(0).toDouble();
            }
        }
        acumulado+=lines->at(2)->text().toDouble();
        if(!consulta.exec("insert into ficha_pago_cfp values(ficha_pago_cfp_s.nextval,'"+lines->at(0)->text()+"',to_date('"+inicios->at(0)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+lines->at(2)->text()+"','CFP','"+lines->at(3)->text()+"','','"+ficha_pago.matricula->text()+"','"+lines->at(4)->text()+"','V','"+tr("%1").arg(acumulado)+"','"+diplo+"')"))
            QMessageBox::critical(0,"Error",consulta.lastError().text());
        else
        {
            consulta.exec("commit");
            container.botonGuardar->setEnabled(false);
            llenarFichaPago(ficha_pago.matricula->text());
        }
    }
    else
    {
        if(!consulta.exec("insert into ficha_pago values(ficha_pago_s.nextval,'"+lines->at(0)->text()+"',to_date('"+inicios->at(0)->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+lines->at(4)->text()+"','"+prog+"','"+lines->at(5)->text()+"','','"+lines->at(3)->text()+"','"+ficha_pago.matricula->text()+"','V','"+lines->at(2)->text()+"')"))
            QMessageBox::critical(0,"Error",consulta.lastError().text());
        else
        {
            consulta.exec("commit");
            container.botonGuardar->setEnabled(false);
            llenarFichaPago(ficha_pago.matricula->text());
        }
    }
}


void procesos_ces::setControlAsistCFP()
{
    QSqlQuery consulta;
    frame = new QFrame();
    control_eval_cfp.setupUi(frame);
    container.workspace->setWidget(frame);
    control_eval_cfp.tabla->setColumnWidth(0,80);
    control_eval_cfp.tabla->setColumnWidth(1,250);
    control_eval_cfp.tabla->setColumnWidth(2,250);
    control_eval_cfp.tabla->setColumnWidth(3,120);

    QStringList labels=(QStringList() << "Matricula"<< "Nombre" << "Apellido" << "Total Asistencias");
    control_eval_cfp.tabla->setHorizontalHeaderLabels(labels);
    control_eval_cfp.titulo->setText("Control Asistencia - CFP");
    control_eval_cfp.diplomado->addItem("-");
    consulta.exec("select descripcion from diplomados order by descripcion");
    while(consulta.next())
    {
            control_eval_cfp.diplomado->addItem(consulta.value(0).toString());
    }
    connect(control_eval_cfp.diplomado,SIGNAL(currentIndexChanged(QString)),this,SLOT(diplomadoChanged4(QString)));
}


void procesos_ces::llenarControlAsistCFP(QString s)
{
    QSqlQuery consulta,consulta2;
    QString diplo,mod,modulo,cohorte;
    QTableWidgetItem *ni;
    int row,i;
    lines = new QList<QLineEdit*>();

    for(i=control_eval_cfp.tabla->rowCount()-1;i>=0;i--)
        control_eval_cfp.tabla->removeRow(i);

    consulta.exec("select id_diplomado from diplomados where descripcion='"+control_eval_cfp.diplomado->currentText()+"'");
    while(consulta.next())
    {
        diplo=consulta.value(0).toString();
    }
    consulta.exec("select id_modalidad from modalidades where descripcion='"+control_eval_cfp.modalidad->currentText().remove(control_eval_cfp.modalidad->currentText().indexOf("-"),3)+"'");
    while(consulta.next())
    {
        mod=consulta.value(0).toString();
    }
    consulta.exec("select id from cohortes where id_diplomado ='"+diplo+"' and id_modalidad='"+mod+"' and cohorte='"+control_eval_cfp.modalidad->currentText().right(2)+"'");
    while(consulta.next())
    {
        cohorte=consulta.value(0).toString();
    }

    consulta.exec("select modulo from modulos_diplomado where descripcion='"+control_eval_cfp.modulo->currentText()+"' and id_diplomado='"+diplo+"'");
    while(consulta.next())
    {
        modulo=consulta.value(0).toString();
    }
    consulta.exec("select matricula from ficha_academica where id_evento='2' and id_curso='"+diplo+"' and id_seccion='"+cohorte+"' and status='V'");
    while(consulta.next())
    {
        consulta2.exec("select nombre,apellido from estudiante where matricula='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            row = control_eval_cfp.tabla->rowCount();
            control_eval_cfp.tabla->insertRow(row);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
            control_eval_cfp.tabla->setItem(row,0,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            control_eval_cfp.tabla->setItem(row,1,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(1).toString()));
            control_eval_cfp.tabla->setItem(row,2,ni);
            lines->append(new QLineEdit());
            control_eval_cfp.tabla->setCellWidget(row,3,lines->last());
        }
        consulta2.exec("select calificacion from ficha_academica where matricula='"+consulta.value(0).toString()+"' and id_evento='55' and observacion='"+modulo+"'");
        while(consulta2.next())
        {
            control_eval_cfp.tabla->removeCellWidget(row,3);
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            control_eval_cfp.tabla->setItem(row,3,ni);
        }
    }
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarAsistCFP()));
    container.botonGuardar->setEnabled(true);
    connect(container.botonImprimir,SIGNAL(clicked()),this,SLOT(imprimirControlAsistCFP()));
    container.botonImprimir->setEnabled(true);
}


void procesos_ces::guardarAsistCFP()
{
    QSqlQuery consulta;
    QTableWidgetItem *ni;
    int i;
    QString diplo,mod,modulo,fecha,cohorte;

    consulta.exec("select id_diplomado from diplomados where descripcion='"+control_eval_cfp.diplomado->currentText()+"'");
    while(consulta.next())
    {
        diplo=consulta.value(0).toString();
    }
    consulta.exec("select id_modalidad from modalidades where descripcion='"+control_eval_cfp.modalidad->currentText().remove(control_eval_cfp.modalidad->currentText().indexOf("-"),3)+"'");
    while(consulta.next())
    {
        mod=consulta.value(0).toString();
    }
    consulta.exec("select id from cohortes where id_diplomado ='"+diplo+"' and id_modalidad='"+mod+"' and cohorte='"+control_eval_cfp.modalidad->currentText().right(2)+"'");
    while(consulta.next())
    {
        cohorte=consulta.value(0).toString();
    }
    consulta.exec("select modulo from modulos_diplomado where descripcion='"+control_eval_cfp.modulo->currentText()+"' and id_diplomado='"+diplo+"'");
    while(consulta.next())
    {
        modulo=consulta.value(0).toString();
    }
    consulta.exec("select to_char(fecha_ini,'dd-mm-yyyy') from diplomados where id_diplomado='"+diplo+"'");
    while(consulta.next())
    {
        fecha=consulta.value(0).toString();
    }
    for(i=0;i<lines->size();i++)
    {
        if(consulta.exec("insert into ficha_academica values(ficha_academica_s.nextval,'55',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+lines->at(i)->text()+"','"+modulo+"','"+cohorte+"','"+diplo+"','"+control_eval_cfp.tabla->item(i,0)->text()+"','V',to_date('"+fecha+"','dd-mm-yyyy'))"))
        {
            consulta.exec("commit");
            control_eval_cfp.tabla->removeCellWidget(i,3);
            ni= new QTableWidgetItem(tr("%1").arg(lines->at(i)->text()));
            control_eval_cfp.tabla->setItem(i,3,ni);
        }
    }
    //lines->~QList();
    lines->clear();
}


void procesos_ces::imprimirControlAsistCFP()
{
    QSqlQuery consulta,consulta2,consulta3;
    QString diplo,mod,modulo,fecha,cohorte;
    int i,j,modulos,suma;
    double porcentaje;
    report->reset();
    QStandardItemModel *model = new QStandardItemModel(0,20);
    QStandardItem *item;
    i=-1;

    report->addParameter("diplomado",control_eval_cfp.diplomado->currentText());
    report->addParameter("modalidad",control_eval_cfp.modalidad->currentText().remove(control_eval_cfp.modalidad->currentText().indexOf("-"),3));

    consulta.exec("select id_diplomado,to_char(fecha_ini,'dd-mm-yyyy'),to_char(fecha_fin,'dd-mm-yyyy'),coordinador from diplomados where descripcion='"+control_eval_cfp.diplomado->currentText()+"'");
    while(consulta.next())
    {
        diplo=consulta.value(0).toString();
        report->addParameter("fecini",consulta.value(1).toString());
        report->addParameter("fecfin",consulta.value(2).toString());
        report->addParameter("coordinador",consulta.value(3).toString());
    }
    consulta.exec("select id_modalidad from modalidades where descripcion='"+control_eval_cfp.modalidad->currentText().remove(control_eval_cfp.modalidad->currentText().indexOf("-"),3)+"'");
    while(consulta.next())
    {
        mod=consulta.value(0).toString();
    }
    consulta.exec("select id from cohortes where id_diplomado='"+diplo+"' and id_modalidad='"+mod+"' and cohorte='"+control_eval_cfp.modalidad->currentText().right(2)+"'");
    while(consulta.next())
    {
        cohorte=consulta.value(0).toString();
    }
    consulta.exec("select matricula from ficha_academica where id_evento='2' and id_curso='"+diplo+"' and id_seccion='"+cohorte+"' and status='V'");
    while(consulta.next())
    {
        modulos=0;
        suma=0;
        consulta2.exec("select nombre,apellido,cedula_est from estudiante where matricula='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            i++;
            model->insertRow(i);
            item = new QStandardItem();
            item->setData(tr("%1").arg(i+1),Qt::EditRole);
            model->setItem(i,0,item);
            item = new QStandardItem();
            item->setData(consulta2.value(0).toString()+" "+consulta2.value(1).toString(),Qt::EditRole);
            model->setItem(i,1,item);
            item = new QStandardItem();
            item->setData(consulta2.value(2).toString(),Qt::EditRole);
            model->setItem(i,2,item);
            item = new QStandardItem();
            item->setData(consulta.value(0).toString(),Qt::EditRole);
            model->setItem(i,3,item);
        }
        j=4;
        consulta2.exec("select modulo,num_clases from modulos_diplomado where id_diplomado='"+diplo+"'");
        while(consulta2.next())
        {
            consulta3.exec("select calificacion from ficha_academica where matricula='"+consulta.value(0).toString()+"' and id_evento='55' and observacion='"+consulta2.value(0).toString()+"'");
            while(consulta3.next())
            {
                porcentaje=consulta3.value(0).toInt()*100/consulta2.value(1).toInt();
                item = new QStandardItem();
                if(porcentaje<80)
                    item->setData(consulta3.value(0).toString()+"/"+consulta2.value(1).toString()+"*",Qt::EditRole);
                else
                    item->setData(consulta3.value(0).toString()+"/"+consulta2.value(1).toString(),Qt::EditRole);
                model->setItem(i,j,item);
                j++;
                suma+=consulta3.value(0).toInt();
                modulos+=consulta2.value(1).toInt();
            }
        }
        item = new QStandardItem();
        item->setData(tr("%1/%2").arg(suma).arg(modulos),Qt::EditRole);
        model->setItem(i,19,item);
    }
    report->addParameter("cohorte",cohorte);
    report->addItemModel(model,"model");
    report->setReportFile("reportes/total_control_asistencia_cfp.xml");
    report->runReportToPDF("test.pdf");
    if (!report->hasError())
    {
        //if(lista_dialog.salida->currentIndex()==0)
                //ShellExecuteA(NULL,"print",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        //else
        ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
    }
    else
        QMessageBox::information(0,"Error",report->lastErrorMsg());
}


void procesos_ces::setControlEvalCFP()
{
    QSqlQuery consulta;
    frame = new QFrame();
    control_eval_cfp.setupUi(frame);
    container.workspace->setWidget(frame);
    control_eval_cfp.tabla->setColumnWidth(0,80);
    control_eval_cfp.tabla->setColumnWidth(1,250);
    control_eval_cfp.tabla->setColumnWidth(2,250);
    control_eval_cfp.tabla->setColumnWidth(3,120);

    control_eval_cfp.diplomado->addItem("-");
    consulta.exec("select descripcion from diplomados order by descripcion");
    while(consulta.next())
    {
        control_eval_cfp.diplomado->addItem(consulta.value(0).toString());
    }
    connect(control_eval_cfp.diplomado,SIGNAL(currentIndexChanged(QString)),this,SLOT(diplomadoChanged4(QString)));
}


void procesos_ces::diplomadoChanged4(QString s)
{
    QSqlQuery consulta,consulta2;
    QString diplo;
    consulta.exec("select id_diplomado from diplomados where descripcion='"+s+"'");
    while(consulta.next())
    {
        diplo=consulta.value(0).toString();
    }
    control_eval_cfp.modalidad->clear();
    control_eval_cfp.modalidad->addItem("-");

    consulta.exec("select id_modalidad,cohorte from cohortes where id_diplomado='"+diplo+"' and status='V' order by cohorte");
    while(consulta.next())
    {
        consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            if(consulta.value(1).toInt()<10)
                control_eval_cfp.modalidad->addItem(consulta2.value(0).toString()+"-0"+consulta.value(1).toString());
            else
                control_eval_cfp.modalidad->addItem(consulta2.value(0).toString()+"-"+consulta.value(1).toString());
            control_eval_cfp.modalidad->setEnabled(true);
        }
    }
    connect(control_eval_cfp.modalidad,SIGNAL(currentIndexChanged(QString)),this,SLOT(llenarModulos(QString)));
    control_eval_cfp.modalidad->setEnabled(true);
}


void procesos_ces::llenarModulos(QString s)
{
    QSqlQuery consulta;
    QString diplo;
    consulta.exec("select id_diplomado from diplomados where descripcion='"+control_eval_cfp.diplomado->currentText()+"'");
    while(consulta.next())
    {
        diplo=consulta.value(0).toString();
    }
    control_eval_cfp.modulo->clear();
    control_eval_cfp.modulo->addItem("-");
    consulta.exec("select descripcion,modulo from modulos_diplomado where id_diplomado='"+diplo+"' order by modulo");
    while(consulta.next())
    {
        control_eval_cfp.modulo->addItem(consulta.value(0).toString());
    }

    if(control_eval_cfp.titulo->text()=="Control Asistencia - CFP")
        connect(control_eval_cfp.modulo,SIGNAL(currentIndexChanged(QString)),this,SLOT(llenarControlAsistCFP(QString)));
    else
        connect(control_eval_cfp.modulo,SIGNAL(currentIndexChanged(QString)),this,SLOT(llenarControlEvalCFP(QString)));
    control_eval_cfp.modulo->setEnabled(true);
}


void procesos_ces::llenarControlEvalCFP(QString s)
{
    QSqlQuery consulta,consulta2;
    QString diplo,mod,modulo,cohorte;
    QTableWidgetItem *ni;
    int row,i;
    lines = new QList<QLineEdit*>();

    for(i=control_eval_cfp.tabla->rowCount()-1;i>=0;i--)
        control_eval_cfp.tabla->removeRow(i);

    consulta.exec("select id_diplomado from diplomados where descripcion='"+control_eval_cfp.diplomado->currentText()+"'");
    while(consulta.next())
    {
        diplo=consulta.value(0).toString();
    }
    consulta.exec("select id_modalidad from modalidades where descripcion='"+control_eval_cfp.modalidad->currentText().remove(control_eval_cfp.modalidad->currentText().indexOf("-"),3)+"'");
    while(consulta.next())
    {
        mod=consulta.value(0).toString();
    }
    consulta.exec("select id from cohortes where id_diplomado='"+diplo+"' and id_modalidad='"+mod+"' and cohorte='"+control_eval_cfp.modalidad->currentText().right(2)+"'");
    while(consulta.next())
    {
        cohorte=consulta.value(0).toString();
    }
    consulta.exec("select modulo from modulos_diplomado where descripcion='"+control_eval_cfp.modulo->currentText()+"' and id_diplomado='"+diplo+"'");
    while(consulta.next())
    {
        modulo=consulta.value(0).toString();
    }
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarNotaCFP()));
    container.botonGuardar->setEnabled(true);
    consulta.exec("select matricula from ficha_academica where id_evento='2' and id_curso='"+diplo+"' and id_seccion='"+cohorte+"' and status='V'");
    while(consulta.next())
    {
        consulta2.exec("select nombre,apellido from estudiante where matricula='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            row = control_eval_cfp.tabla->rowCount();
            control_eval_cfp.tabla->insertRow(row);
            ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
            control_eval_cfp.tabla->setItem(row,0,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            control_eval_cfp.tabla->setItem(row,1,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(1).toString()));
            control_eval_cfp.tabla->setItem(row,2,ni);
            lines->append(new QLineEdit());
            control_eval_cfp.tabla->setCellWidget(row,3,lines->last());
        }
        consulta2.exec("select calificacion from ficha_academica where matricula='"+consulta.value(0).toString()+"' and id_evento='32' and id_curso='"+diplo+"' and id_seccion='"+cohorte+"' and observacion='"+modulo+"'");
        while(consulta2.next())
        {
            control_eval_cfp.tabla->removeCellWidget(row,3);
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            control_eval_cfp.tabla->setItem(row,3,ni);
            container.botonGuardar->setEnabled(false);
        }
    }
    connect(container.botonImprimir,SIGNAL(clicked()),this,SLOT(imprimirControlEvalCFP()));
    container.botonImprimir->setEnabled(true);
}


void procesos_ces::guardarNotaCFP()
{
    QSqlQuery consulta;
    QTableWidgetItem *ni;
    int i;
    double suma;
    QString diplo,mod,modulo,fecha,cohorte,numero,modulos;
    numero=control_eval_cfp.modalidad->currentText().right(2);

    consulta.exec("select id_diplomado,modulos from diplo_temp where descripcion='"+control_eval_cfp.diplomado->currentText()+"'");
    while(consulta.next())
    {
        diplo=consulta.value(0).toString();
        modulos=consulta.value(1).toString();
    }
    consulta.exec("select id_modalidad from modalidades where descripcion='"+control_eval_cfp.modalidad->currentText().remove(control_eval_cfp.modalidad->currentText().indexOf("-"),3)+"'");
    while(consulta.next())
    {
        mod=consulta.value(0).toString();
    }
    consulta.exec("select id,to_char(fecha_ini,'dd-mm-yyyy') from cohortes where id_diplomado='"+diplo+"' and id_modalidad='"+mod+"' and cohorte='"+numero+"'");
    while(consulta.next())
    {
        cohorte=consulta.value(0).toString();
        fecha=consulta.value(1).toString();
    }
    consulta.exec("select modulo from modulos_diplomado where descripcion='"+control_eval_cfp.modulo->currentText()+"' and id_diplomado='"+diplo+"'");
    while(consulta.next())
    {
        modulo=consulta.value(0).toString();
    }

    for(i=0;i<lines->size();i++)
    {
        if(consulta.exec("insert into ficha_academica values(ficha_academica_s.nextval,'32',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+lines->at(i)->text()+"','"+modulo+"','"+cohorte+"','"+diplo+"','"+control_eval_cfp.tabla->item(i,0)->text()+"','V',to_date('"+fecha+"','dd-mm-yyyy'))"))
        {
            consulta.exec("commit");
            control_eval_cfp.tabla->removeCellWidget(i,3);
            ni= new QTableWidgetItem(tr("%1").arg(lines->at(i)->text()));
            control_eval_cfp.tabla->setItem(i,3,ni);
        }
        if(modulo==modulos)
        {
            suma=0;
            consulta.exec("select calificacion from ficha_academica where matricula='"+control_eval_cfp.tabla->item(i,0)->text()+"' and id_evento='32' and id_curso='"+diplo+"' and id_seccion='"+cohorte+"'");
            while(consulta.next())
            {
                suma+=consulta.value(0).toDouble();
            }
            if(consulta.exec("insert into ficha_academica values(ficha_academica_s.nextval,'21',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+tr("%1").arg(suma/modulos.toInt())+"','','"+cohorte+"','"+diplo+"','"+control_eval_cfp.tabla->item(i,0)->text()+"','V',to_date('"+fecha+"','dd-mm-yyyy'))"))
                consulta.exec("commit");
        }
    }
    lines->~QList();
}


void procesos_ces::imprimirControlEvalCFP()
{
    QSqlQuery consulta,consulta2,consulta3;
    QString diplo,mod,modulo,fecha,cohorte;
    int i,j;
    //bool found=false;
    report->reset();
    QStandardItemModel *model = new QStandardItemModel(0,20);
    QStandardItem *item;
    i=-1;

    report->addParameter("diplomado",control_eval_cfp.diplomado->currentText());
    report->addParameter("modalidad",control_eval_cfp.modalidad->currentText().remove(control_eval_cfp.modalidad->currentText().indexOf("-"),3));

    consulta.exec("select id_diplomado,coordinador from diplo_temp where descripcion='"+control_eval_cfp.diplomado->currentText()+"'");
    while(consulta.next())
    {
        diplo=consulta.value(0).toString();
        report->addParameter("coordinador",consulta.value(1).toString());
    }
    consulta.exec("select id_modalidad from modalidades where descripcion='"+control_eval_cfp.modalidad->currentText().remove(control_eval_cfp.modalidad->currentText().indexOf("-"),3)+"'");
    while(consulta.next())
    {
        mod=consulta.value(0).toString();
    }
    consulta.exec("select id,to_char(fecha_ini,'dd-mm-yyyy'),to_char(fecha_fin,'dd-mm-yyyy') from cohortes where id_diplomado='"+diplo+"' and id_modalidad='"+mod+"' and cohorte='"+control_eval_cfp.modalidad->currentText().right(2)+"'");
    while(consulta.next())
    {
        cohorte=consulta.value(0).toString();
        report->addParameter("fecini",consulta.value(1).toString());
        report->addParameter("fecfin",consulta.value(2).toString());
    }
    consulta.exec("select matricula from ficha_academica where id_evento='2' and id_curso='"+diplo+"' and id_seccion='"+cohorte+"' and status='V'");
    while(consulta.next())
    {
        consulta2.exec("select nombre,apellido,cedula_est from estudiante where matricula='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            i++;
            model->insertRow(i);
            item = new QStandardItem();
            item->setData(consulta2.value(0).toString()+" "+consulta2.value(1).toString(),Qt::EditRole);
            model->setItem(i,1,item);
            item = new QStandardItem();
            item->setData(consulta2.value(2).toString(),Qt::EditRole);
            model->setItem(i,2,item);
            item = new QStandardItem();
            item->setData(consulta.value(0).toString()+" "+consulta.value(1).toString(),Qt::EditRole);
            model->setItem(i,3,item);
        }
        j=4;

        consulta2.exec("select modulo from modulos_diplomado where id_diplomado='"+diplo+"' order by modulo");
        while(consulta2.next())
        {
            consulta3.exec("select calificacion from ficha_academica where matricula='"+consulta.value(0).toString()+"' and id_evento='32' and observacion='"+consulta2.value(0).toString()+"'");
            while(consulta3.next())
            {
                item = new QStandardItem();
                item->setData(consulta3.value(0).toString(),Qt::EditRole);
                model->setItem(i,j,item);
                j++;
            }
        }
        consulta2.exec("select calificacion from ficha_academica where matricula='"+consulta.value(0).toString()+"' and id_evento='21'");
        while(consulta2.next())
        {
            item = new QStandardItem();
            item->setData(consulta2.value(0).toString(),Qt::EditRole);
            model->setItem(i,19,item);
        }
    }

    report->addItemModel(model,"model");
    report->setReportFile("reportes/total_control_evaluacion_cfp.xml");
    report->runReportToPDF("test.pdf");
    if (!report->hasError())
    {
        //if(lista_dialog.salida->currentIndex()==0)
                //ShellExecuteA(NULL,"print",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        //else
        ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
    }
    else
        QMessageBox::information(0,"Error",report->lastErrorMsg());
}


void procesos_ces::setControlEvaluacion()
{
    QSqlQuery consulta;
    frame = new QFrame();
    control_evaluacion.setupUi(frame);
    container.workspace->setWidget(frame);
    control_evaluacion.tabla->setColumnWidth(0,300);
    control_evaluacion.tabla->setColumnWidth(1,80);
    control_evaluacion.tabla->setColumnWidth(2,80);
    control_evaluacion.tabla->setColumnWidth(3,80);
    control_evaluacion.tabla->setColumnWidth(4,80);
    //control_evaluacion.tabla->setColumnWidth(5,80);
    //control_evaluacion.tabla->setColumnWidth(6,300);

    control_evaluacion.metodo->addItem("-");
    consulta.exec("select descripcion from metodos order by descripcion");
    while(consulta.next())
    {
        control_evaluacion.metodo->addItem(consulta.value(0).toString());
    }
    connect(control_evaluacion.metodo,SIGNAL(currentIndexChanged(QString)),this,SLOT(metodoChanged2(QString)));
}


void procesos_ces::metodoChanged2(QString s)
{
    QString metodo;
    QSqlQuery consulta,consulta2;
    consulta.exec("select id_metodo,idioma from metodos where descripcion='"+s+"'");
    while(consulta.next())
    {
        control_evaluacion.idioma->setText(consulta.value(1).toString());
        metodo=consulta.value(0).toString();
    }

    control_evaluacion.modalidad_2->clear();
    control_evaluacion.modalidad_2->addItem("-");
    consulta.exec("select distinct(modalidad) from secciones where id_metodo='"+metodo+"'");
    while(consulta.next())
    {
        consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            control_evaluacion.modalidad_2->addItem(consulta2.value(0).toString());
        }
    }
    connect(control_evaluacion.modalidad_2,SIGNAL(currentIndexChanged(QString)),this,SLOT(modalidadChanged4(QString)));
}


void procesos_ces::modalidadChanged4(QString s)
{
    QSqlQuery consulta,consulta2;
    QString metodo,calendario,modalidad;

    consulta.exec("select id_modalidad from modalidades where descripcion='"+s+"'");
    while(consulta.next())
    {
        modalidad=consulta.value(0).toString();
    }
    consulta.exec("select id_metodo,id_calendario from metodos where descripcion='"+control_evaluacion.metodo->currentText()+"'");
    while(consulta.next())
    {
        metodo=consulta.value(0).toString();
        calendario=consulta.value(1).toString();
    }

    control_evaluacion.seccion->clear();
    control_evaluacion.seccion->addItem("-");
    consulta.exec("select id_seccion,horario from secciones where id_metodo='"+metodo+"' and modalidad='"+modalidad+"' order by id_seccion");
    while(consulta.next())
    {
        control_evaluacion.seccion->addItem(consulta.value(0).toString()+" ("+consulta.value(1).toString()+")");
    }

    control_evaluacion.periodo_2->clear();

    if(modalidad=="19")
        consulta.exec("select periodo,to_char(fecha_ini,'dd-mm-yyyy'),to_char(fecha_fin,'dd-mm-yyyy') from calendarios_detalle where id_calendario='"+calendario+"' and modalidad='1' and fecha_ini <= to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy') and fecha_fin >= to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy')");
    else
        consulta.exec("select periodo,to_char(fecha_ini,'dd-mm-yyyy'),to_char(fecha_fin,'dd-mm-yyyy') from calendarios_detalle where id_calendario='"+calendario+"' and modalidad='"+modalidad+"' and fecha_ini <= to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy') and fecha_fin >= to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy')");
    while(consulta.next())
    {
        if(consulta.value(0).toInt()>1)
            control_evaluacion.periodo_2->addItem(tr("%1").arg(consulta.value(0).toInt()-1));
        control_evaluacion.periodo_2->addItem(consulta.value(0).toString());
        control_evaluacion.inicio->setText(consulta.value(1).toString());
        control_evaluacion.fin->setText(consulta.value(2).toString());
    }
    control_evaluacion.periodo_2->setCurrentIndex(1);
    connect(control_evaluacion.seccion,SIGNAL(currentIndexChanged(QString)),this,SLOT(seccionChanged(QString)));
    connect(control_evaluacion.periodo_2,SIGNAL(currentIndexChanged(QString)),this,SLOT(periodoChanged2(QString)));
}


void procesos_ces::periodoChanged2(QString s)
{
    QSqlQuery consulta;
    QString modalidad,calendario;

    consulta.exec("select id_modalidad from modalidades where descripcion='"+control_evaluacion.modalidad_2->currentText()+"'");
    while(consulta.next())
    {
        modalidad=consulta.value(0).toString();
    }
    consulta.exec("select id_calendario from metodos where descripcion='"+control_evaluacion.metodo->currentText()+"'");
    while(consulta.next())
    {
        calendario=consulta.value(0).toString();
    }

    if(modalidad=="19")
        consulta.exec("select to_char(fecha_ini,'dd-mm-yyyy'),to_char(fecha_fin,'dd-mm-yyyy') from calendarios_detalle where id_calendario='"+calendario+"' and modalidad='1' and periodo='"+s+"'");
    else
        consulta.exec("select to_char(fecha_ini,'dd-mm-yyyy'),to_char(fecha_fin,'dd-mm-yyyy') from calendarios_detalle where id_calendario='"+calendario+"' and modalidad='"+modalidad+"' and periodo='"+s+"'");
    while(consulta.next())
    {
        control_evaluacion.inicio->setText(consulta.value(0).toString());
        control_evaluacion.fin->setText(consulta.value(1).toString());
    }

    llenarControlEvaluacion(control_evaluacion.seccion->currentText().left(control_evaluacion.seccion->currentText().indexOf("(")-1));
}


void procesos_ces::seccionChanged(QString s)
{
    QString seccion;
    QSqlQuery consulta,consulta2;
    seccion=s.left(5);
    consulta.exec("select cedula_prof,id_metodo from secciones where id_seccion='"+seccion+"'");
    while(consulta.next())
    {
        consulta2.exec("select nombre,apellido from profesor where cedula_prof='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            control_evaluacion.prof->setText(consulta2.value(0).toString()+" "+consulta2.value(1).toString());
        }
        consulta2.exec("select idioma from metodos where id_metodo='"+consulta.value(1).toString()+"'");
        while(consulta2.next())
        {
            control_evaluacion.idioma->setText(consulta2.value(0).toString());
        }
    }
    llenarControlEvaluacion(seccion);
}


void procesos_ces::llenarControlEvaluacion(QString s)
{
    QSqlQuery consulta,consulta2;
    QTableWidgetItem *ni;
    int row,i;
    lines = new QList<QLineEdit*>();

    for(i=control_evaluacion.tabla->rowCount()-1;i>=0;i--)
        control_evaluacion.tabla->removeRow(i);

    consulta.exec("select matricula from ficha_academica where status='V' and id_evento=2 and id_seccion='"+s+"' and fec_inicio=to_date('"+control_evaluacion.inicio->text()+"','dd-mm-yyyy')");
    while(consulta.next())
    {
        row = control_evaluacion.tabla->rowCount();
        control_evaluacion.tabla->insertRow(row);
        consulta2.exec("select nombre,cedula_est,telf_hab,apellido from estudiante where matricula='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()+" "+consulta2.value(3).toString()));
            control_evaluacion.tabla->setItem(row,0,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(1).toString()));
            control_evaluacion.tabla->setItem(row,1,ni);
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(2).toString()));
            control_evaluacion.tabla->setItem(row,3,ni);
            lines->append(new QLineEdit());
            control_evaluacion.tabla->setCellWidget(row,4,lines->last());
            //lines->append(new QLineEdit());
            //control_evaluacion.tabla->setCellWidget(row,5,lines->last());
        }

        consulta2.exec("select id_fact from ficha_pago where matricula='"+consulta.value(0).toString()+"' and id_evento=2 and status='V'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            control_evaluacion.tabla->setItem(row,2,ni);
        }
        consulta2.exec("select calificacion from ficha_academica where matricula='"+consulta.value(0).toString()+"' and id_evento=21 and status='V'");
        while(consulta2.next())
        {
            control_evaluacion.tabla->removeCellWidget(row,4);
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            control_evaluacion.tabla->setItem(row,4,ni);
        }
    }

    disconnect(container.botonImprimir,SIGNAL(clicked()),0,0);
    connect(control_evaluacion.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarColEvaluacion(int,int)));
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarColEvaluacion()));
    container.botonGuardar->setEnabled(true);
    container.botonImprimir->setEnabled(true);
}


void procesos_ces::editarColEvaluacion(int row,int column)
{
    lines = new QList<QLineEdit*>();
    int i;

    for(i=0;i<control_evaluacion.tabla->rowCount();i++)
    {
        lines->append(new QLineEdit(control_evaluacion.tabla->item(i,4)->text()));
        control_evaluacion.tabla->setCellWidget(i,4,lines->last());
    }
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarColEvaluacion2()));
    container.botonGuardar->setEnabled(true);
}


void procesos_ces::actualizarColEvaluacion()
{
    QString evento,matricula,seccion,curso;
    QSqlQuery consulta;
    int i;

    evento="21";
    seccion=control_evaluacion.seccion->currentText().left(5);
    consulta.exec("select id_metodo from metodos where descripcion='"+control_evaluacion.metodo->currentText()+"'");
    while(consulta.next())
    {
        curso=consulta.value(0).toString();
    }

    for(i=0;i<lines->size();i++)
    {
        consulta.exec("select matricula from estudiante where cedula_est='"+control_evaluacion.tabla->item(i,1)->text()+"'");
        while(consulta.next())
        {
            matricula=consulta.value(0).toString();
        }
        if(!consulta.exec("insert into ficha_academica values(ficha_academica_s.nextval,'"+evento+"',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'"+lines->at(i)->text()+"','N','"+seccion+"','"+curso+"','"+matricula+"','V',to_date('"+control_evaluacion.inicio->text()+"','dd-mm-yyyy'))"))
            QMessageBox::critical(0,"Error Guardar Definitiva",consulta.lastError().text());
        else
        {
            consulta.exec("commit");
            container.botonGuardar->setEnabled(false);
        }
    }
    llenarControlEvaluacion(seccion);
    //Falta guardar estadisticas (area superior-derecha)
}


void procesos_ces::actualizarColEvaluacion2()//Probar
{
    QString evento,matricula,seccion,curso;
    QSqlQuery consulta;
    int i;

    evento="21";
    seccion=control_evaluacion.seccion->currentText().left(5);
    consulta.exec("select id_metodo from metodos where descripcion='"+control_evaluacion.metodo->currentText()+"'");
    while(consulta.next())
    {
        curso=consulta.value(0).toString();
    }

    for(i=0;i<lines->size();i++)
    {
        consulta.exec("select matricula from estudiante where cedula_est='"+control_evaluacion.tabla->item(i,1)->text()+"'");
        while(consulta.next())
        {
            matricula=consulta.value(0).toString();
        }
        if(!consulta.exec("update ficha_academica set calificacion='"+lines->at(i)->text()+"' where matricula='"+matricula+"' and id_evento='"+evento+"' and id_curso='"+curso+"'"))
            QMessageBox::critical(0,"Error Guardar Definitiva",consulta.lastError().text());
        else
        {
            consulta.exec("commit");
            container.botonGuardar->setEnabled(false);
        }
    }
    llenarControlEvaluacion(seccion);
    //Falta guardar estadisticas (area superior-derecha)
}

/*void procesos_ces::setCargaAcademica()
{
        frame = new QFrame();
        carga_academica.setupUi(frame);
        container.workspace->setWidget(frame);

        carga_academica.profesor->addItem("-");
        QSqlQuery consulta("select nombre from profesor order by nombre");
        while(consulta.next())
        {
                carga_academica.profesor->addItem(consulta.value(0).toString());
        }
        carga_academica.tabla->setColumnWidth(0,50);
        carga_academica.tabla->setColumnWidth(1,70);
        carga_academica.tabla->setColumnWidth(4,50);
        carga_academica.tabla->setColumnWidth(2,100);
        carga_academica.tabla->setColumnWidth(3,100);
        carga_academica.tabla->setColumnWidth(5,100);
        connect(carga_academica.profesor,SIGNAL(currentIndexChanged(QString)),this,SLOT(profesorChanged(QString)));
        connect(carga_academica.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarCarga(int,int)));
        disconnect(container.botonNuevo,SIGNAL(clicked()),0,0);
        connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevaCarga()));
        container.botonNuevo->setEnabled(true);

}


void procesos_ces::llenarCargaAcademica(QString prof)
{
        QSqlQuery consulta,consulta2;
        QTableWidgetItem *ni;
        int row,i;

        for(i=carga_academica.tabla->rowCount()-1;i>=0;i--)
                carga_academica.tabla->removeRow(i);

        consulta.exec("select * from carga_academica where cedula_prof='"+prof+"' order by renglon");
        while(consulta.next())
        {
                row = carga_academica.tabla->rowCount();
                carga_academica.tabla->insertRow(row);
                ni = new QTableWidgetItem(tr("%1").arg(consulta.value(5).toString()));
                carga_academica.tabla->setItem(row,0,ni);
                ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
                carga_academica.tabla->setItem(row,1,ni);
                consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(3).toString()+"'");
                while(consulta2.next())
                {
                        ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
                        carga_academica.tabla->setItem(row,2,ni);
                }
                ni = new QTableWidgetItem(tr("%1").arg(consulta.value(4).toString()));
                carga_academica.tabla->setItem(row,3,ni);
                ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
                carga_academica.tabla->setItem(row,4,ni);
                ni = new QTableWidgetItem(tr("%1").arg(consulta.value(6).toString()));
                carga_academica.tabla->setItem(row,5,ni);
        }
}


void procesos_ces::profesorChanged(QString s)
{
        QSqlQuery consulta,consulta2;

        consulta.exec("select cedula_prof from profesor where nombre='"+s+"'");
        while(consulta.next())
        {
                updating=consulta.value(0).toString();
                llenarCargaAcademica(updating);
        }
}


void procesos_ces::nuevaCarga()
{
        QSqlQuery consulta;
        QComboBox *aux = new QComboBox();
        int row= carga_academica.tabla->rowCount();
        carga_academica.tabla->insertRow(row);
        carga_academica.tabla->setCurrentCell(row,0);
        combos = new QList<QComboBox*>();
        lines = new QList<QLineEdit*>();
        aux->addItem("-");
        consulta.exec("select id_metodo from metodos where prog_academico='"+prog_academico+"' order by id_metodo");
        while(consulta.next())
        {
                aux->addItem(consulta.value(0).toString());
        }
        combos->append(aux);
        carga_academica.tabla->setCellWidget(row,1,combos->last());
        lines->append(new QLineEdit());
        carga_academica.tabla->setCellWidget(row,4,lines->last());

        disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
        connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarCarga()));
        connect(carga_academica.tabla->cellWidget(row,1),SIGNAL(currentIndexChanged(QString)),this,SLOT(metodoCargaChanged(QString)));
        container.botonGuardar->setEnabled(true);
        carga_academica.tabla->setCurrentCell(row,0);
}


void procesos_ces::metodoCargaChanged(QString s)
{

        QSqlQuery consulta,consulta2;
        QComboBox *aux = new QComboBox();
        int row=carga_academica.tabla->currentRow();
        //QMessageBox::information(0,"ffff",tr("%1").arg(row));
        aux->addItem("-");
        consulta.exec("select distinct(modalidad) from secciones where id_metodo='"+s+"'");
        while(consulta.next())
        {
                consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(0).toString()+"'");
                while(consulta2.next())
                {
                        aux->addItem(consulta2.value(0).toString());
                }
        }
        combos->append(aux);
        carga_academica.tabla->setCellWidget(row,2,combos->last());
        connect(carga_academica.tabla->cellWidget(row,2),SIGNAL(currentIndexChanged(QString)),this,SLOT(modalidadCargaChanged(QString)));
}


void procesos_ces::modalidadCargaChanged(QString s)
{
        QSqlQuery consulta,consulta2;
        QString modalidad;
        QComboBox *aux = new QComboBox();
        int row=carga_academica.tabla->currentRow();
        consulta.exec("select id_modalidad from modalidades where descripcion='"+s+"'");
        while(consulta.next())
        {
                modalidad=consulta.value(0).toString();
        }
        consulta.exec("select distinct(horario) from secciones where id_metodo='"+combos->at(0)->currentText()+"' and modalidad='"+modalidad+"'");
        while(consulta.next())
        {
                aux->addItem(consulta.value(0).toString());
        }
        consulta.exec("select id_calendario from metodos where id_metodo='"+combos->at(0)->currentText()+"'");
        while(consulta.next())
        {
                consulta2.exec("select to_char(fecha_ini,'dd-mm-yyyy') from calendarios_detalle where modalidad='"+modalidad+"' and id_calendario='"+consulta.value(0).toString()+"'");
                while(consulta.next())
                {

                }
        }
        combos->append(aux);
        carga_academica.tabla->setCellWidget(row,3,combos->last());
}


void procesos_ces::editarCarga(int row,int column)
{
        QSqlQuery consulta,consulta2;
        QComboBox *aux = new QComboBox();
        combos = new QList<QComboBox*>();
        lines = new QList<QLineEdit*>();
        updating=carga_academica.tabla->item(row,0)->text();
        QString mod;

        consulta.exec("select id_metodo from metodos where prog_academico='"+prog_academico+"' order by id_metodo");
        while(consulta.next())
        {
                aux->addItem(consulta.value(0).toString());
        }
        aux->setCurrentIndex(aux->findText(carga_academica.tabla->item(row,1)->text()));
        combos->append(aux);
        carga_academica.tabla->setCellWidget(row,1,combos->last());

        aux= new QComboBox();
        consulta.exec("select distinct(modalidad) from secciones where id_metodo='"+carga_academica.tabla->item(row,1)->text()+"'");
        while(consulta.next())
        {
                mod=consulta.value(0).toString();
                consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(0).toString()+"'");
                while(consulta2.next())
                {
                        aux->addItem(consulta2.value(0).toString());
                }
        }
        aux->setCurrentIndex(aux->findText(carga_academica.tabla->item(row,2)->text()));
        combos->append(aux);
        carga_academica.tabla->setCellWidget(row,2,combos->last());

        aux=new QComboBox();
        consulta.exec("select distinct(horario) from secciones where id_metodo='"+carga_academica.tabla->item(row,1)->text()+"' and modalidad='"+mod+"'");
        while(consulta.next())
        {
                aux->addItem(consulta.value(0).toString());
        }
        aux->setCurrentIndex(aux->findText(carga_academica.tabla->item(row,3)->text()));
        combos->append(aux);
        carga_academica.tabla->setCellWidget(row,3,combos->last());

        lines->append(new QLineEdit(carga_academica.tabla->item(row,4)->text()));
        carga_academica.tabla->setCellWidget(row,4,lines->last());

        disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
        connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarCarga()));
        connect(carga_academica.tabla->cellWidget(row,1),SIGNAL(currentIndexChanged(QString)),this,SLOT(metodoCargaChanged(QString)));
        connect(carga_academica.tabla->cellWidget(row,2),SIGNAL(currentIndexChanged(QString)),this,SLOT(modalidadCargaChanged(QString)));
        container.botonGuardar->setEnabled(true);
}


void procesos_ces::guardarCarga()
{
        QSqlQuery consulta;
        int aux = 0;
        QString renglon,modalidad;

        consulta.exec("select max(renglon) from carga_academica where cedula_prof='"+updating+"'");
        while(consulta.next())
        {
                aux=consulta.value(0).toInt()+1;
        }
        renglon.setNum(aux);
        consulta.exec("select id_modalidad from modalidades where descripcion='"+combos->at(1)->currentText()+"'");
        while(consulta.next())
        {
                modalidad=consulta.value(0).toString();
        }
        if(!consulta.exec("insert into carga_academica values ('"+updating+"','"+combos->at(0)->currentText()+"','"+lines->at(0)->text()+"','"+modalidad+"','"+combos->at(2)->currentText()+"','"+renglon+"','')"))
                QMessageBox::critical(0,"Error Carga Academica",consulta.lastError().text());
        else
        {
                consulta.exec("commit");
                llenarCargaAcademica(updating);
                container.botonGuardar->setEnabled(false);
        }
}


void procesos_ces::actualizarCarga()
{
        QSqlQuery consulta;
        QString mod,prof;
        consulta.exec("select cedula_prof from profesor where nombre='"+carga_academica.profesor->currentText()+"'");
        while(consulta.next())
        {
                prof=consulta.value(0).toString();
        }
        consulta.exec("select id_modalidad from modalidades where descripcion='"+combos->at(1)->currentText()+"'");
        while(consulta.next())
        {
                mod=consulta.value(0).toString();
        }
        if(!consulta.exec("update carga_academica set id_metodo='"+combos->at(0)->currentText()+"', nivel='"+lines->at(0)->text()+"', modalidad='"+mod+"', horario='"+combos->at(2)->currentText()+"' where renglon='"+updating+"'"))
                QMessageBox::critical(0,"Error Carga Academica",consulta.lastError().text());
        else
        {
                consulta.exec("commit");
                llenarCargaAcademica(prof);
                container.botonGuardar->setEnabled(false);
        }
}*/


void procesos_ces::setSchedule()
{
    QSqlQuery consulta;
    estudianteFrame = new QWidget();
    book_dialog.setupUi(estudianteFrame);

    book_dialog.metodo->addItem("-");
    consulta.exec("select descripcion from metodos where prog_academico in ('1','2')");
    while(consulta.next())
    {
        book_dialog.metodo->addItem(consulta.value(0).toString());
    }
    connect(book_dialog.metodo,SIGNAL(currentIndexChanged(QString)),this,SLOT(metodoChanged6(QString)));
    estudianteFrame->show();
}


void procesos_ces::metodoChanged6(QString s)
{
    QSqlQuery consulta,consulta2;
    QString metodo;

    consulta.exec("select id_metodo from metodos where descripcion='"+s+"'");
    while(consulta.next())
    {
        metodo=consulta.value(0).toString();
    }

    book_dialog.modalidad->addItem("-");
    consulta.exec("select distinct(modalidad) from secciones where id_metodo='"+metodo+"'");
    while(consulta.next())
    {
        consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            book_dialog.modalidad->addItem(consulta2.value(0).toString());
        }
    }
    book_dialog.salida->addItem("PANTALLA");
    book_dialog.salida->addItem("IMPRESORA");

    connect(book_dialog.aceptar,SIGNAL(clicked()),this,SLOT(generarSchedule()));
}


void procesos_ces::generarSchedule()
{
    QSqlQuery consulta,consulta2,consulta3;
    QString metodo,cal,mod,fecha;
    QStandardItemModel *model = new QStandardItemModel(0,5);
    QStandardItem *item;
    int periodo,i;
    i=-1;

    consulta.exec("select id_calendario,id_metodo from metodos where descripcion='"+book_dialog.metodo->currentText()+"'");
    while(consulta.next())
    {
        metodo=consulta.value(1).toString();
        cal=consulta.value(0).toString();
    }

    consulta.exec("select id_modalidad from modalidades where descripcion='"+book_dialog.modalidad->currentText()+"'");
    while(consulta.next())
    {
        mod=consulta.value(0).toString();
    }

    consulta.exec("select periodo,to_char(fecha_ini,'dd-MM-yyyy') from calendarios_detalle where id_calendario='"+cal+"' and modalidad='"+mod+"' and fecha_ini <= to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy') and fecha_fin >= to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy')");
    while(consulta.next())
    {
        periodo=consulta.value(0).toInt();
        fecha=consulta.value(1).toString();
    }

    report->reset();
    report->addParameter("periodo",tr("%1").arg(periodo));
    report->addParameter("modalidad",book_dialog.modalidad->currentText());
    consulta.exec("select id_seccion,cedula_prof,id_salon,nivel from secciones where fec_inicio>=to_date('"+fecha+"','dd-MM-yyyy') and id_metodo='"+metodo+"' and modalidad='"+mod+"' order by nivel");
    while(consulta.next())
    {
        i++;
        model->insertRow(i);
        item = new QStandardItem();
        item->setData(consulta.value(3).toString(),Qt::EditRole);
        model->setItem(i,0,item);
        consulta2.exec("select nombre from profesor where cedula_prof='"+consulta.value(3).toString()+"'");
        while(consulta2.next())
        {
            item = new QStandardItem();
            item->setData(consulta2.value(0).toString(),Qt::EditRole);
            model->setItem(i,2,item);
        }
        item = new QStandardItem();
        item->setData(consulta.value(0).toString(),Qt::EditRole);
        model->setItem(i,3,item);
        item = new QStandardItem();
        item->setData(consulta.value(2).toString(),Qt::EditRole);
        model->setItem(i,4,item);

        consulta2.exec("select cedula_prof from secciones where seccion='"+consulta.value(0).toString()+"' and fec_inicio=(select fecha_ini from calendarios_detalle where id_calendario='"+cal+"' and modalidad='"+mod+"' and periodo='"+tr("%1").arg(periodo-1)+"')");
        while(consulta2.next())
        {
            consulta3.exec("select nombre from profesor where cedula_prof='"+consulta.value(0).toString()+"'");
            while(consulta3.next())
            {
                item = new QStandardItem();
                item->setData(consulta3.value(0).toString(),Qt::EditRole);
                model->setItem(i,1,item);
            }
        }
    }
    report->addItemModel(model,"model");
    report->setReportFile("reportes/book_assignment.xml");

    estudianteFrame->close();

    report->runReportToPDF("test.pdf");
    if (!report->hasError())
    {
        if(book_dialog.salida->currentIndex()==1)
            ShellExecuteA(NULL,"print",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        else
            ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
    }
    else
        QMessageBox::information(0,"Error",report->lastErrorMsg());
}


void procesos_ces::setHistorico()
{
    QSqlQuery consulta;
    frame = new QFrame();
    reg_historico.setupUi(frame);
    container.workspace->setWidget(frame);
    reg_historico.prog->addItem("-");
    consulta.exec("select descripcion from programa_academico order by id");
    while(consulta.next())
    {
        reg_historico.prog->addItem(consulta.value(0).toString());
    }
    connect(reg_historico.prog,SIGNAL(currentIndexChanged(QString)),this,SLOT(programaChanged(QString)));
    reg_historico.tabla->setColumnWidth(1,30);
    reg_historico.tabla->setColumnWidth(1,600);
}


void procesos_ces::programaChanged(QString s)
{
    QSqlQuery consulta;
    QTableWidgetItem *ni;
    QString prog;
    int row;
    checks = new QList<QCheckBox*>();

    for(row=reg_historico.tabla->rowCount()-1;row>=0;row--)
        reg_historico.tabla->removeRow(row);

    consulta.exec("select id from programa_academico where descripcion='"+s+"'");
    while(consulta.next())
    {
        prog=consulta.value(0).toString();
    }
    if(prog=="3")
    {
        consulta.exec("select descripcion from diplo_temp order by descripcion");
        while(consulta.next())
        {
            row=reg_historico.tabla->rowCount();
            reg_historico.tabla->insertRow(row);
            checks->append(new QCheckBox());
            reg_historico.tabla->setCellWidget(row,0,checks->last());
            ni = new QTableWidgetItem(consulta.value(0).toString());
            reg_historico.tabla->setItem(row,1,ni);
        }
    }
    else
    {
        consulta.exec("select descripcion from metodos where prog_academico='"+prog+"' order by descripcion");
        while(consulta.next())
        {
            row=reg_historico.tabla->rowCount();
            reg_historico.tabla->insertRow(row);
            checks->append(new QCheckBox());
            reg_historico.tabla->setCellWidget(row,0,checks->last());
            ni = new QTableWidgetItem(consulta.value(0).toString());
            reg_historico.tabla->setItem(row,1,ni);
        }
    }
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(egresado_Historico()));
    container.botonGuardar->setEnabled(true);
}

/*
void procesos_ces::cursoChanged(QString s)
{
    QSqlQuery consulta,consulta2;
    QTableWidgetItem *ni;
    QString curso,nota;
    int row;
    lines= new QList<QLineEdit*>();

    //limpiar la tabla y campos
    for(row=reg_historico.tabla->rowCount()-1;row>=0;row--)
        reg_historico.tabla->removeRow(row);
    reg_historico.fecha->clear();
    reg_historico.promo->clear();

    if(reg_historico.prog->currentText()=="DIPLOMADOS")
    {
        consulta.exec("select id_diplomado from diplomados where from programa_academico where descripcion='"+s+"'");
        while(consulta.next())
        {
            curso=consulta.value(0).toString();
        }
    }
    else
    {
        consulta.exec("select id_metodo from metodos where descripcion='"+s+"'");
        while(consulta.next())
        {
            curso=consulta.value(0).toString();
        }
    }
    if(reg_historico.prog->currentText()=="DIPLOMADOS")
        consulta.exec("select matricula from ficha_academica where id_evento='21' and calificacion > '14' and id_curso='"+curso+"' and status='V' order by matricula");
    else
    {
        consulta.exec("select nota_minima from niveles where id_metodo='"+curso+"' and nivel=(select niveles from metodos where id_metodo='"+curso+"')");
        while(consulta.next())
        {
            nota=consulta.value(0).toString();
        }
        consulta.exec("select distinct(matricula) from ficha_academica where id_evento='21' and calificacion > '"+nota+"' and id_curso='"+curso+"' and status='V' order by matricula");
    }

    while(consulta.next())
    {
        consulta2.exec("select nombre,cedula_est,apellido from estudiante where matricula='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            row=reg_historico.tabla->rowCount();
            reg_historico.tabla->insertRow(row);
            ni = new QTableWidgetItem(consulta.value(0).toString());
            reg_historico.tabla->setItem(row,0,ni);
            ni = new QTableWidgetItem(consulta2.value(0).toString()+" "+consulta2.value(2).toString());
            reg_historico.tabla->setItem(row,1,ni);
            ni = new QTableWidgetItem(consulta2.value(1).toString());
            reg_historico.tabla->setItem(row,2,ni);
            lines->append(new QLineEdit());
            reg_historico.tabla->setCellWidget(row,3,lines->last());
        }
    }
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(egresado_Historico()));
    container.botonGuardar->setEnabled(true);
}
*/

void procesos_ces::egresado_Historico()
{
    QSqlQuery consulta,consulta2,consulta3;
    QTableWidgetItem *ni;
    QString curso,nota,nivel;
    bool copied=false;
    int i;

    if(reg_historico.prog->currentText()!="DIPLOMADOS")
        //reg_historico.tabla->se

    for(i=0;i<reg_historico.tabla->rowCount();i++)
    {
        if(checks->at(i)->isChecked())
        {
            if(reg_historico.prog->currentText()=="DIPLOMADOS")
            {
                nota="14";
                consulta.exec("select id_diplomado from diplo_temp where descripcion='"+reg_historico.tabla->item(i,1)->text()+"'");
                while(consulta.next())
                {
                    curso=consulta.value(0).toString();
                }
                consulta.exec("select matricula from ficha_academica where id_curso='"+curso+"' and id_evento='21' and calificacion >='"+nota+"' and status='V'");
            }
            else
            {
                consulta.exec("select id_metodos from metodos where descripcion='"+reg_historico.tabla->item(i,1)->text()+"'");
                while(consulta.next())
                {
                    curso=consulta.value(0).toString();
                }
                consulta.exec("select nota_minima,nivel from niveles where id_metodo='"+curso+"' and nivel=(select niveles from metodos where id_metodo='"+curso+"')");
                while(consulta.next())
                {
                    nota=consulta.value(0).toString();
                    nivel=consulta.value(1).toString();
                }
                consulta.exec("select matricula from ficha_academica where id_seccion in (select id_seccion from secciones where id_metodo='"+curso+"' and nivel='"+nivel+"') and id_evento='21' and calificacion >='"+nota+"' and status='V'");
            }

            while(consulta.next())
            {
                if(!consulta2.exec("insert into ficha_academica_h select * from ficha_academica where matricula='"+consulta.value(0).toString()+"'"))
                    QMessageBox::critical(0,"Error Ficha Academica",consulta2.lastError().text());
                else
                {
                    //Selecciono los datos del estudiante y agrego el numero de promocion
                    consulta2.exec("select cedula_est,nacionalidad,nombre,telf_hab,telf_cel,ciudad,estado,email,sexo,edo_civil,grado_ins,profesion,fecha_nac,id_tipo_est,rif,matricula,sede,condicion_especial,apellido,cedula_rep,zona from estudiante where matricula='"+consulta.value(0).toString()+"'");
                    while(consulta2.next())
                    {
                        if(!consulta3.exec("insert into estudiante_h values('"+consulta2.value(0).toString()+"','"+consulta2.value(1).toString()+"','"+consulta2.value(2).toString()+"','"+consulta2.value(3).toString()+"','"+consulta2.value(4).toString()+"','"+consulta2.value(5).toString()+"','"+consulta2.value(6).toString()+"','"+consulta2.value(7).toString()+"','"+consulta2.value(8).toString()+"','"+consulta2.value(9).toString()+"','"+consulta2.value(10).toString()+"','"+consulta2.value(11).toString()+"','"+consulta2.value(12).toString()+"','"+consulta2.value(13).toString()+"','"+consulta2.value(14).toString()+"','"+consulta2.value(15).toString()+"','"+consulta2.value(16).toString()+"','"+consulta2.value(17).toString()+"','"+consulta2.value(18).toString()+"','"+consulta2.value(19).toString()+"','"+consulta2.value(20).toString()+"','"+reg_historico.promo->text()+"')"))
                            QMessageBox::critical(0,"Error Estudiante",consulta3.lastError().text());
                        else
                        {
                            copied=true;
                            consulta3.exec("commit");
                        }
                    }
                }
                if(copied)
                {
                    consulta.exec("delete estudiante where matricula='"+consulta.value(0).toString()+"'");
                    consulta.exec("delete ficha_academica where matricula='"+consulta.value(0).toString()+"'");
                }
            }
        }
    }
}


/*
void procesos_ces::setListadoDiplo()
{
        QSqlQuery consulta;
        estudianteFrame = new QWidget();
        lista_dialog.setupUi(estudianteFrame);
        consulta.exec("select descripcion from diplomados order by descripcion");
        lista_dialog.metodo->addItem("-");
        while(consulta.next())  //llenar folio
        {
                lista_dialog.metodo->addItem(consulta.value(0).toString());
        }
        lista_dialog.cursolabel->setText("Diplomado");
        lista_dialog.nivel->setEnabled(false);
        lista_dialog.seccion->setEnabled(false);
        connect(lista_dialog.boton_generar,SIGNAL(clicked()),this,SLOT(generarListadoDiplo()));
        lista_dialog.boton_generar->setEnabled(true);

        lista_dialog.salida->addItem("IMPRESORA");
        lista_dialog.salida->addItem("PANTALLA");

        estudianteFrame->show();
}




void procesos_ces::generarListadoDiplo()
{
        QSqlQuery consulta,consulta2,consulta3;
        QString diplo,profesor,fecha,fecha2;
        QStandardItemModel *model = new QStandardItemModel(0,7);
        QStandardItem *item;
        int i=-1;
        int cuotas;
        float costo;

        consulta.exec("select id_diplomado,costo,cuotas from diplomados where descripcion='"+lista_dialog.metodo->currentText()+"'");
        while(consulta.next())
        {
                diplo=consulta.value(0).toString();
                costo=consulta.value(1).toDouble();
                cuotas=consulta.value(2).toInt();
        }
        consulta.exec("select coordinador,to_char(fecha_ini,'dd-mm-yyyy'),to_char(fecha_fin,'dd-mm-yyyy') from diplomados where id_diplomado='"+diplo+"'");
        while(consulta.next())
        {
                profesor=consulta.value(0).toString();
                fecha=consulta.value(1).toString();
                fecha2=consulta.value(2).toString();
        }
        consulta.exec("select max(cuota) from calendario_cfp where diplomado='"+diplo+"' and fecha_corte<=to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy')");
        while(consulta.next())
        {
                report->addParameter("cuota",consulta.value(0).toString());
        }
        report->reset();
        report->addParameter("diplomado",lista_dialog.metodo->currentText()+" ("+diplo+")");
        report->addParameter("coordinador",profesor);
        report->addParameter("fec_ini",fecha);
        report->addParameter("fec_fin",fecha2);

        consulta.exec("select matricula from ficha_academica where id_evento='2' and id_curso='"+diplo+"' and status='V'");
        while(consulta.next())
        {
                consulta2.exec("select nombre,cedula_est,telf_hab,apellido from estudiante where matricula='"+consulta.value(0).toString()+"'");
                while(consulta2.next())
                {
                        i++;
                        model->insertRow(i);
                        item = new QStandardItem();
                        item->setData(consulta2.value(0).toString()+" "+consulta2.value(3).toString(),Qt::EditRole);
                        model->setItem(i,0,item);
                        item = new QStandardItem();
                        item->setData(consulta2.value(1).toString(),Qt::EditRole);
                        model->setItem(i,1,item);
                        item = new QStandardItem();
                        item->setData(consulta2.value(2).toString(),Qt::EditRole);
                        model->setItem(i,2,item);
                        consulta3.exec("select ult_cuota,acumulado from ficha_pago_cfp where matricula='"+consulta.value(0).toString()+"' and id_diplomado='"+diplo+"' and fecha=(select max(fecha) from ficha_pago_cfp where matricula='"+consulta.value(0).toString()+"' and id_diplomado='"+diplo+"')");
                        while(consulta3.next())
                        {
                                item = new QStandardItem();
                                item->setData(consulta3.value(0).toDouble(),Qt::EditRole);
                                model->setItem(i,3,item);
                                item = new QStandardItem();
                                item->setData(consulta3.value(1).toDouble(),Qt::EditRole);
                                model->setItem(i,4,item);
                                item = new QStandardItem();
                                item->setData(cuotas-consulta3.value(0).toDouble(),Qt::EditRole);
                                model->setItem(i,5,item);
                                item = new QStandardItem();
                                item->setData(costo-consulta3.value(1).toDouble(),Qt::EditRole);
                                model->setItem(i,6,item);
                        }
                }
        }

        report->addItemModel(model,"model");
        report->setReportFile("reportes/listado_cfp.xml");

        estudianteFrame->close();

        report->runReportToPDF("test.pdf");
        if (!report->hasError())
        {
                if(lista_dialog.salida->currentIndex()==0)
                        ShellExecuteA(NULL,"print",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
                else
                        ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        }
        else
                QMessageBox::information(0,"Error",report->lastErrorMsg());
}*/


/*void procesos_ces::setListadoCursos()
{
        QSqlQuery consulta,consulta2,consulta3;
        QString html;

        html="<html><body><div align=\"left\"><font face=\"Verdana\" size=2><b>FUNDACION UNIVERSIDAD DE CARABOBO<br><b>PROGRAMA:</b> ++<br><b>LISTADO DE CURSOS</div><br>";
        consulta.exec("select id_metodo,descripcion,niveles,diurno,nocturno,sabatino from metodos");
        while(consulta.next())
        {
                //html+=
        }

}*/


void procesos_ces::setListadoProf()
{
    QSqlQuery consulta,consulta2,consulta3;
    QStandardItemModel *model = new QStandardItemModel(0,4);
    QStandardItem *item;
    int x=-1;

    report->addParameter("programa","");

    consulta.exec("select id_metodo,descripcion from metodos");
    while(consulta.next())
    {
        report->addParameter("metodo",consulta.value(1).toString());
        consulta2.exec("select cedula_prof from carga_academica where id_metodo='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            consulta3.exec("select nombre,telf_cel,telf_hab from profesor where cedula_prof='"+consulta2.value(0).toString()+"'");
            while(consulta3.next())
            {
                x++;
                model->insertRow(x);
                item = new QStandardItem();
                item->setData(consulta3.value(0).toString(),Qt::EditRole);
                model->setItem(x,0,item);
                item = new QStandardItem();
                item->setData(consulta2.value(0).toString(),Qt::EditRole);
                model->setItem(x,1,item);
                item = new QStandardItem();
                item->setData(consulta3.value(1).toString(),Qt::EditRole);
                model->setItem(x,2,item);
                item = new QStandardItem();
                item->setData(consulta3.value(2).toString(),Qt::EditRole);
                model->setItem(x,3,item);
            }
        }
    }
    report->addItemModel(model,"model");
    report->setReportFile("reportes/lista_profesores.xml");
    report->runReportToPDF("test.pdf");
    if (!report->hasError())
    {
        /*if(salida->currentIndex()==0)
                ShellExecuteA(NULL,"print",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        else*/
                ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
    }
    else
            QMessageBox::information(0,"Error",report->lastErrorMsg());
}


void procesos_ces::setListados(int tipo)
{
    estudianteFrame = new QWidget();
    lista_dialog.setupUi(estudianteFrame);
    lista_dialog.metodo->setEnabled(false);
    lista_dialog.fecfin->setEnabled(false);
    lista_dialog.fecini->setEnabled(false);
    lista_dialog.nivel->setEnabled(false);
    lista_dialog.seccion->setEnabled(false);
    lista_dialog.salida->addItem("PANTALLA");
    lista_dialog.salida->addItem("IMPRESORA");
    connect(lista_dialog.boton_generar,SIGNAL(clicked()),this,SLOT(generarListados()));
    lista_dialog.boton_generar->setEnabled(true);
    actual_row=tipo;
    estudianteFrame->show();
}


void procesos_ces::generarListados()
{
    QSqlQuery consulta;
    QStandardItemModel *model = new QStandardItemModel(0,3);
    QStandardItem *item;
    int i=-1;
    switch(actual_row)
    {
        case 1:
        {
            consulta.exec("select descripcion,idioma,niveles from metodos where prog_academico='"+prog_academico+"' order by idioma");
            while(consulta.next())
            {
                i++;
                model->insertRow(i);
                item=new QStandardItem();
                item->setData(consulta.value(0).toString(),Qt::EditRole);
                model->setItem(i,0,item);
                item=new QStandardItem();
                item->setData(consulta.value(1).toString(),Qt::EditRole);
                model->setItem(i,1,item);
                item=new QStandardItem();
                item->setData(consulta.value(2).toString(),Qt::EditRole);
                model->setItem(i,2,item);
            }
            report->setReportFile("reportes/lista_cursos.xml");
        }
        break;

        case 2:
        {
            consulta.exec("select descripcion,coordinador,modulos from diplo_temp order by descripcion");
            while(consulta.next())
            {
               i++;
                model->insertRow(i);
                item=new QStandardItem();
                item->setData(consulta.value(0).toString(),Qt::EditRole);
                model->setItem(i,0,item);
                item=new QStandardItem();
                item->setData(consulta.value(1).toString(),Qt::EditRole);
                model->setItem(i,1,item);
                item=new QStandardItem();
                item->setData(consulta.value(2).toString(),Qt::EditRole);
                model->setItem(i,2,item);
            }
            report->setReportFile("reportes/lista_diplomados.xml");
        }
        break;
    }
    consulta.exec("select descripcion from companias where id='"+prog+"'");
    while(consulta.next())
    {
        report->addParameter("programa",consulta.value(0).toString());
    }
    report->addItemModel(model,"model");
    report->runReportToPDF("test.pdf");

    if (!report->hasError())
    {
        if(lista_dialog.salida->currentIndex()==1)
            ShellExecuteA(NULL,"print",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        else
            ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
    }
    else
        QMessageBox::information(0,"Error",report->lastErrorMsg());
    estudianteFrame->close();
}


void procesos_ces::setListadoIdiomas(int tipo)
{
    QSqlQuery consulta;
    estudianteFrame = new QWidget();
    lista_dialog.setupUi(estudianteFrame);

    consulta.exec("select descripcion from metodos where prog_academico in ('1','2') order by descripcion");
    lista_dialog.metodo->addItem("-");
    while(consulta.next())
    {
        lista_dialog.metodo->addItem(consulta.value(0).toString());
    }

    lista_dialog.salida->addItem("PANTALLA");
    lista_dialog.salida->addItem("IMPRESORA");
    connect(lista_dialog.metodo,SIGNAL(currentIndexChanged(QString)),this,SLOT(metodoChanged3(QString)));
    actual_row=tipo;
    estudianteFrame->show();
}


void procesos_ces::metodoChanged3(QString s)
{
    int i,niveles;
    lista_dialog.nivel->clear();
    lista_dialog.nivel->addItem("-");
    QSqlQuery consulta("select id_metodo,niveles from metodos where descripcion='"+s+"' order by id_metodo");
    while(consulta.next())
    {
        updating=consulta.value(0).toString();
        niveles=consulta.value(1).toInt();
        for(i=0;i<niveles;i++)
        {
            lista_dialog.nivel->addItem(tr("%1").arg(i+1));
        }
    }
    connect(lista_dialog.nivel,SIGNAL(currentIndexChanged(QString)),this,SLOT(nivelChanged2(QString)));
}


void procesos_ces::nivelChanged2(QString s)
{
    lista_dialog.seccion->clear();
    lista_dialog.seccion->addItem("-");
    QSqlQuery consulta,consulta2;
    int i=1;

    consulta.exec("select id_seccion,modalidad,horario from secciones where id_metodo='"+updating+"' and nivel='"+s+"' order by id_seccion");
    while(consulta.next())
    {
        consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(1).toString()+"'");
        while(consulta2.next())
        {
            lista_dialog.seccion->addItem(consulta2.value(0).toString()+"-"+consulta.value(2).toString()+"-"+consulta.value(0).toString().right(1));
        }
    }
    connect(lista_dialog.seccion,SIGNAL(currentIndexChanged(QString)),this,SLOT(seccionChanged2(QString)));
}


void procesos_ces::seccionChanged2(QString s)
{
    QSqlQuery consulta,consulta2;
    QString modalidad,periodo,horario,salon,aux,mod;

    salon=s.right(1);
    aux=s.remove(s.lastIndexOf("-"),2);
    horario=aux.right(17);
    modalidad=aux.remove("-"+horario,Qt::CaseInsensitive);

    consulta.exec("select id_modalidad from modalidades where descripcion='"+modalidad+"'");
    while(consulta.next())
    {
        mod=consulta.value(0).toString();
    }
    consulta.exec("select periodo from secciones where id_metodo='"+updating+"' and nivel='"+lista_dialog.nivel->currentText()+"' and horario='"+horario+"' and modalidad='"+mod+"' and id_seccion like '%"+salon+"'");
    while(consulta.next())
    {
        periodo=consulta.value(0).toString();
    }

    lista_dialog.fecini->clear();
    lista_dialog.fecfin->clear();
    consulta.exec("select id_calendario from metodos where id_metodo='"+updating+"'"); //buscar periodo de la seccion
    while(consulta.next())
    {
        if(mod=="19")
            consulta2.exec("select to_char(fecha_ini,'dd-mm-yyyy'),to_char(fecha_fin,'dd-mm-yyyy') from calendarios_detalle where id_calendario='"+consulta.value(0).toString()+"' and modalidad='1' and periodo='"+periodo+"'");
        else
            consulta2.exec("select to_char(fecha_ini,'dd-mm-yyyy'),to_char(fecha_fin,'dd-mm-yyyy') from calendarios_detalle where id_calendario='"+consulta.value(0).toString()+"' and modalidad='"+mod+"' and periodo='"+periodo+"'");
        while(consulta2.next())
        {
            lista_dialog.fecini->setDate(QDate::fromString(consulta2.value(0).toString(),"dd-MM-yyyy"));
            lista_dialog.fecfin->setDate(QDate::fromString(consulta2.value(1).toString(),"dd-MM-yyyy"));
        }
    }
    connect(lista_dialog.boton_generar,SIGNAL(clicked()),this,SLOT(generarListadoIdiomas()));
    lista_dialog.boton_generar->setEnabled(true);
}


void procesos_ces::generarListadoIdiomas() //horario nuevo
{
    QSqlQuery consulta,consulta2,consulta3;
    QStandardItemModel *model = new QStandardItemModel(0,6);
    QStandardItem *item;
    QString seccion,factura,aula,profesor,horario,periodo,idioma,modalidad,mod,metodo,aux,salon;

    salon=lista_dialog.seccion->currentText().right(1);
    aux=lista_dialog.seccion->currentText().remove(lista_dialog.seccion->currentText().lastIndexOf("-"),2);
    horario=aux.right(17);
    modalidad=aux.remove("-"+horario,Qt::CaseInsensitive);

    consulta.exec("select id_modalidad from modalidades where descripcion='"+modalidad+"'");
    while(consulta.next())
    {
        mod=consulta.value(0).toString();
    }

    int i=-1;
    report->reset();
    consulta.exec("select id_seccion,cedula_prof from secciones where id_metodo='"+updating+"' and nivel='"+lista_dialog.nivel->currentText()+"' and horario='"+horario+"' and modalidad='"+mod+"' and id_seccion like '%"+salon+"'");
    while(consulta.next())
    {
        seccion=consulta.value(0).toString();
        consulta2.exec("select descripcion from salones where id_salon='"+salon+"'");
        while(consulta2.next())
        {
            aula=consulta2.value(0).toString();
        }

        consulta2.exec("select nombre,apellido from profesor where cedula_prof='"+consulta.value(1).toString()+"'");
        while(consulta2.next())
        {
            profesor=consulta2.value(0).toString()+" "+consulta2.value(1).toString();
        }
    }
    consulta.exec("select id_metodo from metodos where descripcion='"+lista_dialog.metodo->currentText()+"'");
    while(consulta.next())
    {
        metodo=consulta.value(0).toString();
    }

    consulta.exec("select idioma,id_calendario from metodos where id_metodo='"+metodo+"'");
    while(consulta.next())
    {
        idioma=consulta.value(0).toString();
        if(mod=="19")
            consulta2.exec("select periodo from calendarios_detalle where id_calendario='"+consulta.value(1).toString()+"' and modalidad='1' and fecha_ini =to_date('"+lista_dialog.fecini->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy') and fecha_fin=to_date('"+lista_dialog.fecfin->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy')");
        else
            consulta2.exec("select periodo from calendarios_detalle where id_calendario='"+consulta.value(1).toString()+"' and modalidad='"+mod+"' and fecha_ini =to_date('"+lista_dialog.fecini->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy') and fecha_fin=to_date('"+lista_dialog.fecfin->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy')");
        while(consulta2.next())
        {
            periodo=consulta2.value(0).toString();
        }
    }
    switch(actual_row)
    {
        case 1:
        {
            consulta.exec("select nombre,cedula_est,telf_hab,apellido,matricula from estudiante where matricula in (select matricula from ficha_academica where id_evento='2' and id_seccion='"+seccion+"' and fec_inicio = to_date('"+lista_dialog.fecini->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy')) order by apellido");
            while(consulta.next())
            {
                consulta2.exec("select id_fact from ficha_pago where id_evento='2' and matricula='"+consulta.value(4).toString()+"' and renglon=(select max(renglon) from ficha_pago where id_evento='2' and matricula='"+consulta.value(4).toString()+"')");
                while(consulta2.next())
                {
                    factura=consulta2.value(0).toString();
                }
                i++;
                model->insertRow(i);
                item=new QStandardItem();
                item->setData(i+1,Qt::EditRole);
                model->setItem(i,0,item);
                item=new QStandardItem();
                item->setData(consulta.value(3).toString()+", "+consulta.value(0).toString(),Qt::EditRole);
                model->setItem(i,1,item);
                item=new QStandardItem();
                item->setData(consulta.value(1).toString(),Qt::EditRole);
                model->setItem(i,2,item);
                item=new QStandardItem();
                item->setData(factura,Qt::EditRole);
                model->setItem(i,3,item);
                item=new QStandardItem();
                item->setData(consulta.value(2).toString(),Qt::EditRole);
                model->setItem(i,4,item);
            }

            report->addParameter("idioma",idioma);
            report->addParameter("periodo",periodo);
            report->setReportFile("reportes/control_evaluacion_2014.xml");
        }break;
        case 2:
        {
            consulta.exec("select nombre,cedula_est,apellido from estudiante where matricula in (select matricula from ficha_academica where id_evento='2' and id_seccion='"+seccion+"' and status='V' and fec_inicio = to_date('"+lista_dialog.fecini->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy')) order by apellido");
            while(consulta.next())
            {
                i++;
                model->insertRow(i);
                item=new QStandardItem();
                item->setData(i+1,Qt::EditRole);
                model->setItem(i,0,item);
                item=new QStandardItem();
                item->setData(consulta.value(2).toString()+" "+consulta.value(0).toString(),Qt::EditRole);
                model->setItem(i,1,item);
                item=new QStandardItem();
                item->setData(consulta.value(1).toString(),Qt::EditRole);
                model->setItem(i,2,item);
            }
            report->setReportFile("reportes/control_asistencia.xml");
        }break;
        case 3:
        {
            int j;
            QSqlQuery consulta3;

            consulta.exec("select nombre,apellido,cedula_est,matricula,id_tipo_est from estudiante where matricula in (select matricula from ficha_academica where id_evento='2' and id_seccion='"+seccion+"' and fec_inicio = to_date('"+lista_dialog.fecini->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy')) order by apellido");
            while(consulta.next())
            {
                i++;
                model->insertRow(i);
                item=new QStandardItem();
                item->setData(i+1,Qt::EditRole);
                model->setItem(i,0,item);
                item=new QStandardItem();
                item->setData(consulta.value(3).toString(),Qt::EditRole);
                model->setItem(i,1,item);
                item=new QStandardItem();
                item->setData(consulta.value(1).toString()+" "+consulta.value(0).toString(),Qt::EditRole);
                model->setItem(i,2,item);
                item=new QStandardItem();
                item->setData(consulta.value(2).toString(),Qt::EditRole);
                model->setItem(i,3,item);

                consulta2.exec("select id_fact,monto from ficha_pago where id_evento='2' and matricula='"+consulta.value(3).toString()+"' and status='V'");
                while(consulta2.next())
                {
                    item=new QStandardItem();
                    item->setData(consulta2.value(0).toString(),Qt::EditRole);
                    model->setItem(i,4,item);
                }

                if(metodo=="AEC")
                {
                    consulta2.exec("select descripcion from tipo_estudiante where id_tipo_est='"+consulta.value(4).toString()+"'");
                    while(consulta2.next())
                    {
                        item=new QStandardItem();
                        item->setData(consulta2.value(0).toString(),Qt::EditRole);
                        model->setItem(i,5,item);
                    }
                }

                j=5;
                consulta2.exec("select id_fact,cuota_o_libro from ficha_pago where id_evento='18' and matricula='"+consulta.value(3).toString()+"' and status='V' order by cuota_o_libro");
                while(consulta2.next())
                {
                    consulta3.exec("select cantidad from detalle_factura where id_fact='"+consulta2.value(0).toString()+"' and tipo_item='CI'");
                    while(consulta3.next())
                    {
                        item=new QStandardItem();
                        item->setData(consulta2.value(0).toString(),Qt::EditRole);
                        model->setItem(i,j,item);
                        j++;
                    }
                }
            }

            if(prog_academico=="4")
            {
                consulta.exec("select id_edif from secciones where id_seccion='"+seccion+"'");
                while(consulta.next())
                {
                    consulta2.exec("select descripcion from edificios where id_edif='"+consulta.value(0).toString()+"'");
                    while(consulta2.next())
                    {
                        report->addParameter("colegio",consulta2.value(0).toString());
                    }
                }
                report->setReportFile("reportes/alumnos_por_seccion_fvtc.xml");
            }
            else if(metodo=="EAD" || metodo=="SF")
                report->setReportFile("reportes/alumnos_por_seccion.xml");
            else
                report->setReportFile("reportes/alumnos_por_seccion_IV.xml");
        }break;
    }

    report->addParameter("aula",aula);
    report->addParameter("horario",horario);
    report->addParameter("profesor",profesor);
    report->addParameter("seccion",seccion);
    report->addParameter("fecini",lista_dialog.fecini->date().toString("dd-MM-yyyy"));
    report->addParameter("fecfin",lista_dialog.fecfin->date().toString("dd-MM-yyyy"));
    report->addParameter("metodo",lista_dialog.metodo->currentText());
    report->addParameter("nivel",lista_dialog.nivel->currentText());
    report->addParameter("modalidad",modalidad);
    report->addItemModel(model,"model");
    report->runReportToPDF("test.pdf");
    estudianteFrame->close();

    if (!report->hasError())
    {
        if(lista_dialog.salida->currentIndex()==1)
            ShellExecuteA(NULL,"print",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        else
            ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
    }
    else
        QMessageBox::information(0,"Error",report->lastErrorMsg());
}


void procesos_ces::setListadoInscritos()
{
        QSqlQuery consulta;
        estudianteFrame = new QWidget();
        lista_dialog.setupUi(estudianteFrame);
        lista_dialog.cursolabel->setText("Diplomado");
        lista_dialog.nivel->setEnabled(false);
        lista_dialog.seccion->setEnabled(false);
        lista_dialog.metodo->setEnabled(false);
        connect(lista_dialog.boton_generar,SIGNAL(clicked()),this,SLOT(listadoInscritosCFP()));
        lista_dialog.boton_generar->setEnabled(true);
        lista_dialog.salida->addItem("PANTALLA");
        lista_dialog.salida->addItem("IMPRESORA");

        estudianteFrame->show();
}


void procesos_ces::listadoInscritosCFP()
{
    QSqlQuery consulta,consulta2,consulta3;
    QStandardItemModel *model = new QStandardItemModel(0,6);
    QStandardItem *item;
    int pre,insc,i=-1;
    report->reset();
    consulta.exec("select id_diplomado,descripcion,minimo from diplo_temp where id_diplomado in (select distinct(id_diplomado) from cohortes where status='V') order by descripcion");
    while(consulta.next())
    {
        consulta3.exec("select id,cant_actual,cohorte,ciudad from cohortes where id_diplomado='"+consulta.value(0).toString()+"' order by cohorte");
        while(consulta3.next())
        {
            pre=insc=0;
            consulta2.exec("select matricula from ficha_academica where id_seccion='"+consulta3.value(0).toString()+"' and id_evento='47' and status='V'");
            while(consulta2.next())
            {
                pre++;
            }
            insc+=consulta3.value(1).toInt();

            i++;
            model->insertRow(i);
            item = new QStandardItem();
            item->setData(consulta.value(1).toString()+" "+consulta3.value(2).toString()+" "+consulta3.value(3).toString(),Qt::EditRole);
            model->setItem(i,0,item);
            item = new QStandardItem();
            item->setData(consulta.value(2).toInt(),Qt::EditRole);
            model->setItem(i,1,item);
            item = new QStandardItem();
            item->setData(pre,Qt::EditRole);
            model->setItem(i,2,item);
            item = new QStandardItem();
            item->setData(insc,Qt::EditRole);
            model->setItem(i,3,item);
            item = new QStandardItem();
            item->setData(insc+pre,Qt::EditRole);
            model->setItem(i,4,item);
            item = new QStandardItem();
            item->setData(consulta.value(2).toInt()-(insc+pre),Qt::EditRole);
            model->setItem(i,5,item);
        }
    }
    report->addItemModel(model,"model");
    report->setReportFile("reportes/inscritos_cfp.xml");

    estudianteFrame->close();


    report->runReportToPDF("test.pdf");
    if (!report->hasError())
    {
            if(lista_dialog.salida->currentIndex()==1)
                    ShellExecuteA(NULL,"print",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
            else
                    ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
    }
    else
            QMessageBox::information(0,"Error",report->lastErrorMsg());
}


void procesos_ces::setListadosCFP(int tipo)
{
    QSqlQuery consulta;
    estudianteFrame = new QWidget();
    lista_dialog2.setupUi(estudianteFrame);
    consulta.exec("select descripcion from diplo_temp order by descripcion");
    lista_dialog2.metodo->addItem("-");
    while(consulta.next())
    {
        lista_dialog2.metodo->addItem(consulta.value(0).toString());
    }
    lista_dialog2.boton_generar->setEnabled(true);
    lista_dialog2.salida->addItem("PANTALLA");
    lista_dialog2.salida->addItem("IMPRESORA");

    actual_row=tipo;
    connect(lista_dialog2.metodo,SIGNAL(currentIndexChanged(QString)),this,SLOT(diplomadoChanged3(QString)));
    estudianteFrame->show();
}


void procesos_ces::diplomadoChanged3(QString s)
{
    QSqlQuery consulta,consulta2;
    QString diplo;

    consulta.exec("select id_diplomado from diplo_temp where descripcion='"+s+"'");
    while(consulta.next())
    {
         diplo=consulta.value(0).toString();
    }
    lista_dialog2.modulo->clear();
    lista_dialog2.modulo->addItem("-");
    consulta.exec("select descripcion,modulo from modulos_diplomado where id_diplomado='"+diplo+"' order by modulo");
    while(consulta.next())
    {
        lista_dialog2.modulo->addItem(consulta.value(0).toString());
        if((actual_row!=5)&&(actual_row!=4)&&(actual_row!=3))
            lista_dialog2.modulo->setEnabled(true);
    }
    lista_dialog2.modalidad->clear();
    lista_dialog2.modalidad->addItem("-");
    consulta.exec("select id_modalidad,id from cohortes where id_diplomado='"+diplo+"' and status='V' order by id");
    while(consulta.next())
    {
        lista_dialog2.modalidad->addItem(consulta.value(1).toString());
        lista_dialog2.modalidad->setEnabled(true);
    }
        /*consulta.exec("select distinct(id_modalidad) from horario_diplomado where id_diplomado='"+diplo+"'");
        while(consulta.next())
        {
                consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(0).toString()+"'");
                while(consulta2.next())
                {
                        lista_dialog2.modalidad->addItem(consulta2.value(0).toString());
                        lista_dialog2.modalidad->setEnabled(true);
                }
        }
        consulta.exec("select to_char(fecha_ini,'dd-mm-yyyy'),to_char(fecha_fin,'dd-mm-yyyy') from cohortes where id_diplomado='"+diplo+"'");
        while(consulta.next())
        {
                lista_dialog2.fecini->setDate(QDate::fromString(consulta.value(0).toString(),"dd-MM-yyyy"));
                lista_dialog2.fecfin->setDate(QDate::fromString(consulta.value(1).toString(),"dd-MM-yyyy"));
        }*/
    connect(lista_dialog2.modalidad,SIGNAL(currentIndexChanged(QString)),this,SLOT(cohorteChanged2(QString)));
}


void procesos_ces::cohorteChanged2(QString s)
{
    QSqlQuery consulta;
    QString diplo,modalidad,numero;

    consulta.exec("select to_char(fecha_ini,'dd-mm-yyyy'),to_char(fecha_fin,'dd-mm-yyyy') from cohortes where id='"+s+"'");

    while(consulta.next())
    {
        lista_dialog2.fecini->setDate(QDate::fromString(consulta.value(0).toString(),"dd-MM-yyyy"));
        lista_dialog2.fecfin->setDate(QDate::fromString(consulta.value(1).toString(),"dd-MM-yyyy"));
    }

    connect(lista_dialog2.boton_generar,SIGNAL(clicked()),this,SLOT(listaEvalCFP()));
}


void procesos_ces::listaEvalCFP()
{
    QSqlQuery consulta,consulta2,consulta3;
    QString diplo,profesor,modulo,modalidad,cohorte,numero;
    QStandardItemModel *model = new QStandardItemModel(0,8);
    QStandardItem *item;
    float costo;
    int i,cuotas,j,x;

    cohorte=lista_dialog2.modalidad->currentText();
    consulta.exec("select id_diplomado,coordinador from diplo_temp where descripcion='"+lista_dialog2.metodo->currentText()+"'");
    while(consulta.next())
    {
        diplo=consulta.value(0).toString();
        profesor=consulta.value(2).toString();
    }
    consulta.exec("select id_modalidad,costo,cuotas,cohorte from cohortes where id='"+cohorte+"'");
    while(consulta.next())
    {
        consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            modalidad=consulta2.value(0).toString();
        }
        numero=consulta.value(3).toString();
        costo=consulta.value(1).toDouble();
        cuotas=consulta.value(2).toInt();
    }

    report->reset();
    report->addParameter("diplomado",lista_dialog2.metodo->currentText()+" ("+diplo+")");
    report->addParameter("cohorte",numero);
    report->addParameter("modalidad",modalidad);
    //report->addParameter("modalidad",lista_dialog2.modalidad->currentText().remove(lista_dialog2.modalidad->currentText().indexOf("-"),3));
    report->addParameter("coordinador",profesor);
    report->addParameter("fec_ini",lista_dialog2.fecini->date().toString("dd-MM-yyyy"));
    report->addParameter("fec_fin",lista_dialog2.fecfin->date().toString("dd-MM-yyyy"));

    switch(actual_row)
    {
        case 1:
        {
            i=-1;
            consulta.exec("select nombre,cedula_est,apellido from estudiante where matricula in (select matricula from ficha_academica where id_evento='2' and id_curso='"+diplo+"' and id_seccion='"+cohorte+"' and status='V') order by apellido");
            while(consulta.next())
            {
                i++;
                model->insertRow(i);
                item = new QStandardItem();
                item->setData(i+1,Qt::EditRole);
                model->setItem(i,0,item);
                item = new QStandardItem();
                item->setData(consulta.value(2).toString()+" "+consulta.value(0).toString(),Qt::EditRole);
                model->setItem(i,1,item);
                item = new QStandardItem();
                item->setData(consulta.value(1).toString(),Qt::EditRole);
                model->setItem(i,2,item);
            }
            report->setReportFile("reportes/control_evaluacion_cfp.xml");
        }
        break;
        case 2:
        {
            i=-1;
            consulta.exec("select nombre,cedula_est,apellido,matricula from estudiante where matricula in (select matricula from ficha_academica where id_evento='2' and id_curso='"+diplo+"' and id_seccion='"+cohorte+"' and status='V') order by apellido");
            while(consulta.next())
            {
                i++;
                model->insertRow(i);
                item = new QStandardItem();
                item->setData(i+1,Qt::EditRole);
                model->setItem(i,0,item);
                item = new QStandardItem();
                item->setData(consulta.value(2).toString()+" "+consulta.value(0).toString(),Qt::EditRole);
                model->setItem(i,1,item);
                item = new QStandardItem();
                item->setData(consulta.value(1).toString(),Qt::EditRole);
                model->setItem(i,2,item);
                item = new QStandardItem();
                item->setData(consulta.value(3).toString(),Qt::EditRole);
                model->setItem(i,3,item);

            }

            consulta.exec("select modulo from modulos_diplomado where descripcion='"+lista_dialog2.modulo->currentText()+"'");
            while(consulta.next())
            {
                modulo=consulta.value(0).toString();
            }
            i=1;
            consulta.exec("select to_char(fecha,'dd-mm-yyyy') from calendario_modulos where id_diplomado='"+diplo+"' and modulo='"+modulo+"' and id_modalidad='"+modalidad+"' and fecha between to_date('"+lista_dialog2.fecini->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy') and to_date('"+lista_dialog2.fecfin->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy')");
            while(consulta.next())
            {
                QString tag=tr("fecha%1").arg(i);
                report->addParameter(tag,consulta.value(0).toString());
                i++;
            }

            report->setReportFile("reportes/control_asistencia_cfp.xml");
        }
        break;
        case 3:
        {
            float descuento;
            i=-1;

            consulta.exec("select nombre,cedula_est,apellido,telf_hab,matricula from estudiante where matricula in (select matricula from ficha_academica where (id_evento='2' or id_evento='47') and id_curso='"+diplo+"' and id_seccion='"+cohorte+"' and status='V') order by apellido");
            while(consulta.next())
            {
                i++;
                model->insertRow(i);
                item = new QStandardItem();
                item->setData(i+1,Qt::EditRole);
                model->setItem(i,0,item);
                item = new QStandardItem();
                item->setData(consulta.value(2).toString()+" "+consulta.value(0).toString(),Qt::EditRole);
                model->setItem(i,1,item);
                item = new QStandardItem();
                item->setData(consulta.value(1).toString(),Qt::EditRole);
                model->setItem(i,2,item);
                item = new QStandardItem();
                item->setData(consulta.value(3),Qt::EditRole);
                model->setItem(i,3,item);

                consulta2.exec("select monto from ficha_pago_cfp where id_evento='47' and matricula='"+consulta.value(4).toString()+"' and id_diplomado='"+diplo+"'");
                while(consulta2.next())
                {
                    item=new QStandardItem();
                    item->setData(consulta2.value(0).toString(),Qt::EditRole);
                    model->setItem(i,4,item);
                }

                consulta2.exec("select monto from ficha_pago_cfp where id_evento='2' and matricula='"+consulta.value(4).toString()+"' and id_diplomado='"+diplo+"'");
                while(consulta2.next())
                {
                    item=new QStandardItem();
                    item->setData(consulta2.value(0).toString(),Qt::EditRole);
                    model->setItem(i,5,item);
                }
                j=6;
                float descuentos=0;
                consulta2.exec("select monto,id_fact,renglon from ficha_pago_cfp where id_evento='18' and matricula='"+consulta.value(4).toString()+"' and id_diplomado='"+diplo+"' order by fecha");
                while(consulta2.next())
                {
                    descuento=0;
                    consulta3.exec("select monto from ficha_pago_cfp where id_fact='"+consulta2.value(1).toString()+"' and id_evento='53' and renglon='"+tr("%1").arg(consulta2.value(2).toInt()+1)+"'");
                    while(consulta3.next())
                    {
                        descuento=consulta3.value(0).toDouble();
                    }
                    item=new QStandardItem();
                    item->setData(tr("%1").arg(consulta2.value(0).toDouble()+descuento),Qt::EditRole);
                    model->setItem(i,j,item);
                    descuentos-=descuento;
                    j++;
                }
                for(x=cuotas+6;x<18;x++)
                {
                    item = new QStandardItem();
                    item->setData("N/A",Qt::EditRole);
                    model->setItem(i,x,item);
                }

                consulta2.exec("select ult_cuota,acumulado from ficha_pago_cfp where matricula='"+consulta.value(4).toString()+"' and id_diplomado='"+diplo+"' and ult_cuota=(select max(ult_cuota) from ficha_pago_cfp where matricula='"+consulta.value(4).toString()+"' and id_diplomado='"+diplo+"')");
                while(consulta2.next())
                {

                    item = new QStandardItem();
                    item->setData(consulta2.value(1).toDouble(),Qt::EditRole);
                    model->setItem(i,18,item);
                    item = new QStandardItem();
                    item->setData(cuotas-consulta2.value(0).toDouble(),Qt::EditRole);
                    model->setItem(i,19,item);
                    item = new QStandardItem();
                    item->setData(costo-consulta2.value(1).toDouble()-descuentos,Qt::EditRole);//menos acumulado de descuentos
                    model->setItem(i,20,item);
                }
            }
            report->setReportFile("reportes/listado_cfp.xml");
        }
        break;
        case 4: //Graduandos CFP
        {
            i=-1;
            consulta.exec("select nombre,cedula_est,apellido,telf_hab,matricula from estudiante where matricula in (select matricula from ficha_academica where id_evento='21' and id_curso='"+diplo+"' and id_seccion='"+cohorte+"' and status='V') order by apellido");
            while(consulta.next())
            {
                i++;
                model->insertRow(i);
                item = new QStandardItem();
                item->setData(i+1,Qt::EditRole);
                model->setItem(i,0,item);
                item = new QStandardItem();
                item->setData(consulta.value(2).toString()+" "+consulta.value(0).toString(),Qt::EditRole);
                model->setItem(i,1,item);
                item = new QStandardItem();
                item->setData(consulta.value(1).toString(),Qt::EditRole);
                model->setItem(i,2,item);
                item = new QStandardItem();
                item->setData(consulta.value(3).toString(),Qt::EditRole);
                model->setItem(i,3,item);

                //Comparar la nota con la minima aprobatoria. Marcar los no aprobados.
                consulta2.exec("select calificacion from ficha_academica where matricula='"+consulta.value(4).toString()+"' id_evento='21' and id_curso='"+diplo+"' and id_seccion='"+cohorte+"' and status='V'");
                while(consulta2.next())
                {
                    item = new QStandardItem();
                    item->setData(consulta2.value(0).toString(),Qt::EditRole);
                    model->setItem(i,4,item);
                    if(consulta2.value(0).toInt()<14)
                    {
                        item = new QStandardItem();
                        item->setData("No Aprobado",Qt::EditRole);
                        model->setItem(i,5,item);
                    }
                }
            }
            report->setReportFile("reportes/graduandos_cfp.xml");
        }
        break;
        case 5: //Graduandos CFP no solventes
        {
            i=-1;
            int cuota;
            consulta.exec("select nombre,cedula_est,apellido,telf_hab,matricula from estudiante where matricula in (select matricula from ficha_academica where id_evento='21' and id_curso='"+diplo+"' and id_seccion='"+cohorte+"' and status='V') order by apellido");
            while(consulta.next())
            {
                consulta2.exec("select ult_cuota from ficha_pago_cfp where matricula='"+consulta.value(4).toString()+"'");
                while(consulta2.next())
                {
                    cuota=consulta2.value(0).toInt();
                }
                if(cuota<cuotas)
                {
                    i++;
                    model->insertRow(i);
                    item = new QStandardItem();
                    item->setData(i+1,Qt::EditRole);
                    model->setItem(i,0,item);
                    item = new QStandardItem();
                    item->setData(consulta.value(2).toString()+" "+consulta.value(0).toString(),Qt::EditRole);
                    model->setItem(i,1,item);
                    item = new QStandardItem();
                    item->setData(consulta.value(1).toString(),Qt::EditRole);
                    model->setItem(i,2,item);
                    item = new QStandardItem();
                    item->setData(consulta.value(3).toString(),Qt::EditRole);
                    model->setItem(i,3,item);
                    item = new QStandardItem();
                    item->setData(tr("%1").arg(cuotas-cuota),Qt::EditRole);
                    model->setItem(i,4,item);
                }
            }
            report->setReportFile("reportes/insolventes_cfp.xml");
        }
        break;
        case 6:
        {
            i=-1;
            consulta.exec("select nombre,cedula_est,apellido,telf_cel,email from estudiante where matricula in (select matricula from ficha_academica where id_evento='2' and id_curso='"+diplo+"' and id_seccion='"+cohorte+"' and status='V') order by apellido");
            while(consulta.next())
            {
                i++;
                model->insertRow(i);
                item = new QStandardItem();
                item->setData(i+1,Qt::EditRole);
                model->setItem(i,0,item);
                item = new QStandardItem();
                item->setData(consulta.value(2).toString()+" "+consulta.value(0).toString(),Qt::EditRole);
                model->setItem(i,1,item);
                item = new QStandardItem();
                item->setData(consulta.value(1).toString(),Qt::EditRole);
                model->setItem(i,2,item);
                item = new QStandardItem();
                item->setData(consulta.value(3).toString(),Qt::EditRole);
                model->setItem(i,3,item);
                item = new QStandardItem();
                item->setData(consulta.value(4).toString(),Qt::EditRole);
                model->setItem(i,4,item);
            }
            report->setReportFile("reportes/lista_contacto_cfp.xml");
        }
        break;
    }
    report->addItemModel(model,"model");
    report->runReportToPDF("test.pdf");

    if (!report->hasError())
    {
        if(lista_dialog2.salida->currentIndex()==1)
            ShellExecuteA(NULL,"print",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        else
            ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
    }
    else
        QMessageBox::information(0,"Error",report->lastErrorMsg());
    estudianteFrame->close();
}



void procesos_ces::imprimirControlEvaluacion()
{
        /*QStandardItemModel *model1 = new QStandardItemModel(control_evaluacion.tabla->rowCount(),23);
        QStandardItem *item;
        int i;

        report->reset();
        report->addParameter("metodo",control_evaluacion.metodo->currentText());
        report->addParameter("profesor",control_evaluacion.profesor->currentText());
        report->addParameter("idioma",control_evaluacion.idioma->text());
        report->addParameter("nivel",control_evaluacion.nivel->currentText());
        report->addParameter("eval1",control_evaluacion.eval1->text());
        report->addParameter("eval2",control_evaluacion.eval2->text());
        report->addParameter("eval3",control_evaluacion.eval3->text());
        report->addParameter("eval4",control_evaluacion.eval4->text());
        report->addParameter("horario",control_evaluacion.horario->text());
        report->addParameter("aula",control_evaluacion.aula->text());
        report->addParameter("modalidad",control_evaluacion.modalidad->text());
        report->addParameter("periodo",control_evaluacion.periodo->currentText());
        report->addParameter("fecini",control_evaluacion.inicio->text());
        report->addParameter("fecfin",control_evaluacion.fin->text());


        for(i=0;i<control_evaluacion.tabla->rowCount();i++)
        {
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,0)->text(),Qt::EditRole);
                model1->setItem(i,0,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,1)->text(),Qt::EditRole);
                model1->setItem(i,1,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,2)->text(),Qt::EditRole);
                model1->setItem(i,2,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,3)->text(),Qt::EditRole);
                model1->setItem(i,3,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,4)->text(),Qt::EditRole);
                model1->setItem(i,4,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,5)->text(),Qt::EditRole);
                model1->setItem(i,5,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,6)->text(),Qt::EditRole);
                model1->setItem(i,6,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,7)->text(),Qt::EditRole);
                model1->setItem(i,7,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,8)->text(),Qt::EditRole);
                model1->setItem(i,8,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,9)->text(),Qt::EditRole);
                model1->setItem(i,9,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,10)->text(),Qt::EditRole);
                model1->setItem(i,10,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,11)->text(),Qt::EditRole);
                model1->setItem(i,11,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,12)->text(),Qt::EditRole);
                model1->setItem(i,12,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,13)->text(),Qt::EditRole);
                model1->setItem(i,13,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,14)->text(),Qt::EditRole);
                model1->setItem(i,14,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,15)->text(),Qt::EditRole);
                model1->setItem(i,15,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,16)->text(),Qt::EditRole);
                model1->setItem(i,16,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,17)->text(),Qt::EditRole);
                model1->setItem(i,17,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,18)->text(),Qt::EditRole);
                model1->setItem(i,18,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,19)->text(),Qt::EditRole);
                model1->setItem(i,19,item);
                item = new QStandardItem();
                item->setData(control_evaluacion.tabla->item(i,20)->text(),Qt::EditRole);
                model1->setItem(i,20,item);
        }
        report->addItemModel(model1,"model");
        report->setReportFile("reportes/control_evaluacion_2012.xml");
        report->runReportToPDF("test.pdf");
        if (!report->hasError())
        {
                ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        }
        else
                QMessageBox::information(0,"Error",report->lastErrorMsg());*/
}


void procesos_ces::constancias(int tipo)
{
    estudianteFrame = new QWidget();
    gen_dialog.setupUi(estudianteFrame);
    actual_row=tipo;
    gen_dialog.etiqueta2->setVisible(false);
    gen_dialog.combo->setVisible(false);
    connect(gen_dialog.aceptar,SIGNAL(clicked()),this,SLOT(generarConstancias()));
    connect(gen_dialog.cedula,SIGNAL(returnPressed()),this,SLOT(generarConstancias()));
    estudianteFrame->show();

}


void procesos_ces::generarConstancias()
{
    QSqlQuery consulta,consulta2;
    QString director,programa,estudiante,matricula,ciudad,direccion,telefono,niveles_aprobados,total_horas,hora_fin,nivel,curso;
    QStandardItemModel *model=new QStandardItemModel(0,3);
    QStandardItem *item= new QStandardItem();
    int niveles,x;
    report->reset();

    //Pedir matricula o cedula de estudiante
    report->addParameter("cedula",gen_dialog.cedula->text());
    report->addParameter("dia",QDate::currentDate().day());
    report->addParameter("anio",QDate::currentDate().year());
    consulta.exec("select nombre,matricula,apellido from estudiante where cedula_est='"+gen_dialog.cedula->text()+"'");
    while(consulta.next())
    {
        report->addParameter("estudiante",consulta.value(0).toString()+" "+consulta.value(2).toString());
        matricula = consulta.value(1).toString();
    }

    consulta.exec("select descripcion,direccion,telefono,director,ciudad from companias where id='"+prog+"'");
    while(consulta.next())
    {
        report->addParameter("programa",consulta.value(0).toString());
        report->addParameter("direccion",consulta.value(1).toString());
        report->addParameter("telefono",consulta.value(2).toString());
        report->addParameter("director",consulta.value(3).toString());
        report->addParameter("ciudad",consulta.value(4).toString());
    }

    report->addParameter("mes",QDate::currentDate().toString("MMMM"));
    consulta.exec("select id_seccion,id_curso from ficha_academica where matricula='"+matricula+"' and status='V' and id_evento=2");
    if(prog_academico=="3")
    {
        //informacion del diplomado
        while(consulta.next())
        {
            curso=consulta.value(1).toString();
            consulta2.exec("select descripcion from diplo_temp where id_diplomado='"+consulta.value(1).toString()+"'");
            while(consulta2.next())
            {
                report->addParameter("metodo",consulta2.value(0).toString());
            }
            consulta2.exec("select id_modalidad,id_horario,to_char(fecha_ini,'dd-MM-yyyy'),to_char(fecha_fin,'dd-MM-yyyy') from cohortes where id='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                QSqlQuery consulta3("select descripcion from modalidades where id_modalidad='"+consulta2.value(0).toString()+"'");
                while(consulta3.next())
                {
                    report->addParameter("modalidad",consulta3.value(0).toString());
                }
                report->addParameter("hora_ini",consulta2.value(1).toString().left(consulta2.value(1).toString().indexOf("-")));
                report->addParameter("hora_fin",consulta2.value(1).toString().right(consulta2.value(1).toString().indexOf("-")));
                report->addParameter("inicio",consulta2.value(2).toString());
                report->addParameter("fin",consulta2.value(3).toString());
            }
        }
    }
    else
    {
        while(consulta.next())
        {
            curso=consulta.value(1).toString();
            consulta2.exec("select descripcion,niveles from metodos where id_metodo='"+consulta.value(1).toString()+"'");
            while(consulta2.next())
            {
                report->addParameter("metodo",consulta2.value(0).toString());
                report->addParameter("niveles",consulta2.value(1).toString());
                niveles=consulta2.value(1).toInt();
            }
            consulta2.exec("select nivel,horario,modalidad from secciones where id_seccion='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                nivel=consulta2.value(0).toString();
                report->addParameter("nivel",consulta2.value(0).toString());
                report->addParameter("hora_ini",consulta2.value(1).toString().left(8));
                report->addParameter("hora_fin",consulta2.value(1).toString().right(8)); //buscar como resolver
                QSqlQuery consulta3("select descripcion from modalidades where id_modalidad ='"+consulta2.value(2).toString()+"'");
                while(consulta3.next())
                {
                    report->addParameter("modalidad",consulta3.value(0).toString());
                }
            }
            consulta2.exec("select horas from niveles where id_metodo='"+consulta.value(1).toString()+"' and nivel=1");
            while(consulta2.next())
            {
                report->addParameter("horas",consulta2.value(0).toString());
                total_horas.setNum(consulta2.value(0).toInt()*niveles);
                report->addParameter("total_horas",total_horas);
            }

            niveles_aprobados.setNum(1);
            if(nivel.toInt()>2)
            {              
                for(int i=2;i<nivel.toInt()-1;i++)
                {
                     niveles_aprobados.append(tr(", %1").arg(i)); //Preguntar si puede ser "1 al x"
                }
                niveles_aprobados.append(tr(" y %1").arg(nivel.toInt()-1));
            }
            report->addParameter("niveles_aprob",niveles_aprobados);
        }
    }

    switch(actual_row)
    {
        case 2:
        {
            x=-1;
            consulta.exec("select id_seccion,fecha,calificacion from ficha_academica where matricula='"+matricula+"' and id_curso='"+curso+"' and id_evento=21 order by id_seccion");
            while(consulta.next())
            {
                consulta2.exec("select nivel from secciones where id_seccion='"+consulta.value(0).toString()+"'");
                while(consulta2.next())
                {
                    x++;
                    model->insertRow(x);
                    item = new QStandardItem();
                    item->setData(consulta.value(2).toString(),Qt::EditRole);
                    model->setItem(x,0,item);
                    item = new QStandardItem();
                    item->setData(consulta2.value(0).toString(),Qt::EditRole);
                    model->setItem(x,1,item);
                    item = new QStandardItem();
                    item->setData(tr("%1/%2").arg(consulta.value(1).toDate().month()).arg(consulta.value(1).toDate().year()),Qt::EditRole);
                    model->setItem(x,2,item);
                }
            }
            report->setReportFile("reportes/constancias/estudio_con_nota.xml");
        }
        break;
        case 3:
        {
            x=-1;
            if(prog_academico=="3")
            {

                consulta.exec("select observacion,calificacion from ficha_academica where matricula='"+matricula+"' and id_curso='"+curso+"' and id_evento=32 order by observacion");
                while(consulta.next())
                {
                    x++;
                    model->insertRow(x);
                    consulta2.exec("select descripcion,duracion from modulos_diplomado where id_diplomado='"+curso+"' and modulo ='"+consulta.value(0).toString()+"'");
                    while(consulta2.next())
                    {
                        item = new QStandardItem();
                        item->setData(consulta2.value(0).toString(),Qt::EditRole);
                        model->setItem(x,0,item);
                        item = new QStandardItem();
                        item->setData(consulta2.value(1).toString(),Qt::EditRole);
                        model->setItem(x,1,item);
                    }
                    item = new QStandardItem();
                    item->setData(consulta.value(1).toString(),Qt::EditRole);
                    model->setItem(x,2,item);
                }
                report->setReportFile("reportes/constancias/fin_con_nota_cfp.xml");
            }
            else
            {
                consulta.exec("select id_seccion,fecha,calificacion from ficha_academica where matricula='"+matricula+"' and id_curso='"+curso+"' and id_evento=21 order by id_seccion");
                while(consulta.next())
                {
                    consulta2.exec("select nivel from secciones where id_seccion='"+consulta.value(0).toString()+"'");
                    while(consulta2.next())
                    {
                        x++;
                        model->insertRow(x);
                        item = new QStandardItem();
                        item->setData(consulta.value(2).toString(),Qt::EditRole);
                        model->setItem(x,0,item);
                        item = new QStandardItem();
                        item->setData(consulta2.value(0).toString(),Qt::EditRole);
                        model->setItem(x,1,item);
                        item = new QStandardItem();
                        item->setData(tr("%1/%2").arg(consulta.value(1).toDate().month()).arg(consulta.value(1).toDate().year()),Qt::EditRole);
                        model->setItem(x,2,item);
                    }
                }
                report->setReportFile("reportes/constancias/fin_con_nota.xml");
            }
        }
        break;
        case 4:
        {
            switch(QDate::currentDate().month())
            {
                case 1:
                    report->addParameter("mes","January");
                break;
                case 2:
                    report->addParameter("mes","February");
                break;
                case 3:
                    report->addParameter("mes","March");
                break;
                case 4:
                    report->addParameter("mes","April");
                break;
                case 5:
                    report->addParameter("mes","May");
                break;
                case 6:
                    report->addParameter("mes","June");
                break;
                case 7:
                    report->addParameter("mes","July");
                break;
                case 8:
                    report->addParameter("mes","August");
                break;
                case 9:
                    report->addParameter("mes","September");
                break;
                case 10:
                    report->addParameter("mes","October");
                break;
                case 11:
                    report->addParameter("mes","November");
                break;
                case 12:
                    report->addParameter("mes","December");
                break;
            }

            x=-1;
            consulta.exec("select id_seccion,fecha,calificacion from ficha_academica where matricula='"+matricula+"' and id_curso='"+curso+"' and id_evento=21 order by id_seccion");
            while(consulta.next())
            {
                consulta2.exec("select nivel from secciones where id_seccion='"+consulta.value(0).toString()+"'");
                while(consulta2.next())
                {
                    x++;
                    model->insertRow(x);
                    item = new QStandardItem();
                    item->setData(consulta.value(2).toString(),Qt::EditRole);
                    model->setItem(x,0,item);
                    item = new QStandardItem();
                    item->setData(consulta2.value(0).toString(),Qt::EditRole);
                    model->setItem(x,1,item);
                    item = new QStandardItem();
                    item->setData(tr("%1/%2").arg(consulta.value(1).toDate().month()).arg(consulta.value(1).toDate().year()),Qt::EditRole);
                    model->setItem(x,2,item);
                }
            }
            niveles_aprobados.remove(tr(" y %1").arg(nivel.toInt()-1),Qt::CaseSensitive);
            niveles_aprobados.append(tr(" and %1").arg(nivel.toInt()-1));
            report->addParameter("niveles_aprob",niveles_aprobados);
            report->setReportFile("reportes/constancias/estudio_con_nota_ingles.xml");
        }
        break;
        case 5:
        {
            switch(QDate::currentDate().month())
            {
                case 1:
                    report->addParameter("mes","January");
                break;
                case 2:
                    report->addParameter("mes","February");
                break;
                case 3:
                    report->addParameter("mes","March");
                break;
                case 4:
                    report->addParameter("mes","April");
                break;
                case 5:
                    report->addParameter("mes","May");
                break;
                case 6:
                    report->addParameter("mes","June");
                break;
                case 7:
                    report->addParameter("mes","July");
                break;
                case 8:
                    report->addParameter("mes","August");
                break;
                case 9:
                    report->addParameter("mes","September");
                break;
                case 10:
                    report->addParameter("mes","October");
                break;
                case 11:
                    report->addParameter("mes","November");
                break;
                case 12:
                    report->addParameter("mes","December");
                break;
            }

            x=-1;
            consulta.exec("select id_seccion,fecha,calificacion from ficha_academica where matricula='"+matricula+"' and id_curso='"+curso+"' and id_evento=21 order by id_seccion");
            while(consulta.next())
            {
                consulta2.exec("select nivel from secciones where id_seccion='"+consulta.value(0).toString()+"'");
                while(consulta2.next())
                {
                    x++;
                    model->insertRow(x);
                    item = new QStandardItem();
                    item->setData(consulta.value(2).toString(),Qt::EditRole);
                    model->setItem(x,0,item);
                    item = new QStandardItem();
                    item->setData(consulta2.value(0).toString(),Qt::EditRole);
                    model->setItem(x,1,item);
                    item = new QStandardItem();
                    item->setData(tr("%1/%2").arg(consulta.value(1).toDate().month()).arg(consulta.value(1).toDate().year()),Qt::EditRole);
                    model->setItem(x,2,item);
                }
            }
            report->setReportFile("reportes/constancias/fin_con_nota_ingles.xml");
        }
        break;
        case 6:
        {
            //buscar fecha de inicio de nivel inscrito y calcular fecha de fin de los x periodos (dependiendo de la modalidad)
            consulta.exec("select fec_inicio from ficha_academica where matricula='"+matricula+"' and id_curso='"+curso+"' and id_evento=2 and status='V'");
            while(consulta.next())
            {
                report->addParameter("dia_ini",consulta.value(0).toDate().day());
                report->addParameter("mes_ini",QDate::longMonthName(consulta.value(0).toDate().month()));
            }
            report->setReportFile("reportes/constancias/inicio.xml");
        }
        break;
        case 7:
        {
            if(prog_academico=="3")
            {
                report->setReportFile("reportes/constancias/estudio_sin_nota_cfp.xml");
            }
            else
            {
                if(nivel=="1")
                    report->setReportFile("reportes/constancias/estudio_nivel1.xml");
                else
                    report->setReportFile("reportes/constancias/estudio_sin_nota.xml");
            }
        }
        break;
        case 8:
        {
            if(prog_academico=="3")
            {
                report->setReportFile("reportes/constancias/fin_sin_nota_cfp.xml");
            }
            else
            {
                report->setReportFile("reportes/constancias/fin_sin_nota.xml");
            }
        }
        break;
        case 9:
        {
            switch(QDate::currentDate().month())
            {
                case 1:
                    report->addParameter("mes","January");
                break;
                case 2:
                    report->addParameter("mes","February");
                break;
                case 3:
                    report->addParameter("mes","March");
                break;
                case 4:
                    report->addParameter("mes","April");
                break;
                case 5:
                    report->addParameter("mes","May");
                break;
                case 6:
                    report->addParameter("mes","June");
                break;
                case 7:
                    report->addParameter("mes","July");
                break;
                case 8:
                    report->addParameter("mes","August");
                break;
                case 9:
                    report->addParameter("mes","September");
                break;
                case 10:
                    report->addParameter("mes","October");
                break;
                case 11:
                    report->addParameter("mes","November");
                break;
                case 12:
                    report->addParameter("mes","December");
                break;
            }
            if(nivel=="1")
                report->setReportFile("reportes/constancias/estudio_nivel1_ingles.xml");
            else
            {
                niveles_aprobados.remove(tr(" y %1").arg(nivel.toInt()-1),Qt::CaseSensitive);
                niveles_aprobados.append(tr(" and %1").arg(nivel.toInt()-1));
                report->addParameter("niveles_aprob",niveles_aprobados);
                report->setReportFile("reportes/constancias/estudio_sin_nota_ingles.xml");
            }
        }
        break;
        case 10:
        {
            switch(QDate::currentDate().month())
            {
                case 1:
                    report->addParameter("mes","January");
                break;
                case 2:
                    report->addParameter("mes","February");
                break;
                case 3:
                    report->addParameter("mes","March");
                break;
                case 4:
                    report->addParameter("mes","April");
                break;
                case 5:
                    report->addParameter("mes","May");
                break;
                case 6:
                    report->addParameter("mes","June");
                break;
                case 7:
                    report->addParameter("mes","July");
                break;
                case 8:
                    report->addParameter("mes","August");
                break;
                case 9:
                    report->addParameter("mes","September");
                break;
                case 10:
                    report->addParameter("mes","October");
                break;
                case 11:
                    report->addParameter("mes","November");
                break;
                case 12:
                    report->addParameter("mes","December");
                break;
            }
            report->setReportFile("reportes/constancias/fin_sin_nota_ingles.xml");
        }
        break;
    }

    report->addItemModel(model,"model");

    report->runReportToPDF("test.pdf");
    if (!report->hasError())
    {
        ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
    }
    else
        QMessageBox::information(0,"Error",report->lastErrorMsg());
    estudianteFrame->close();
}


void procesos_ces::setCambioDiplo()
{
    estudianteFrame = new QWidget();
    c_diplo_dialog.setupUi(estudianteFrame);
    connect(c_diplo_dialog.matricula,SIGNAL(returnPressed()),this,SLOT(llenarCambioDiplo()));
    connect(c_diplo_dialog.cedula,SIGNAL(returnPressed()),this,SLOT(llenarCambioDiplo()));
    connect(c_diplo_dialog.rhorario,SIGNAL(toggled(bool)),this,SLOT(horarioToggled(bool)));
    connect(c_diplo_dialog.rdiplomado,SIGNAL(toggled(bool)),this,SLOT(diploToggled(bool)));
    estudianteFrame->show();
}


void procesos_ces::horarioToggled(bool checked)
{
    if(checked)
    {
        c_diplo_dialog.seleccion->clear();
        c_diplo_dialog.seleccion->addItem("-");
        QString cohorte;

        QSqlQuery consulta("select id_modalidad,id_horario,cohorte from cohortes where id_diplomado=(select id_diplomado from cohortes where id='"+c_diplo_dialog.cohorte->text()+"')");
        while(consulta.next())
        {
            QSqlQuery consulta2("select descripcion from modalidades where id_modalidad='"+consulta.value(0).toString()+"'");
            while(consulta2.next())
            {
                if(consulta.value(2).toInt()<10)
                    cohorte="0"+consulta.value(2).toString();
                else
                    cohorte=consulta.value(2).toString();
                c_diplo_dialog.seleccion->addItem(cohorte+" ("+consulta2.value(0).toString()+"-"+consulta.value(1).toString()+")");
            }
        }
        disconnect(c_diplo_dialog.seleccion);
        c_diplo_dialog.seleccion->setEnabled(true);
        c_diplo_dialog.seleccion2->setEnabled(false);
    }
}


void procesos_ces::diploToggled(bool checked)
{
    if(checked)
    {
        c_diplo_dialog.seleccion->clear();
        c_diplo_dialog.seleccion->addItem("-");
        //QSqlQuery consulta("select descripcion from diplomados order by descripcion");
        QSqlQuery consulta("select descripcion from diplo_temp order by descripcion");
        while(consulta.next())
        {
            c_diplo_dialog.seleccion->addItem(consulta.value(0).toString());
        }
        c_diplo_dialog.seleccion->setEnabled(true);
        connect(c_diplo_dialog.seleccion,SIGNAL(currentIndexChanged(QString)),this,SLOT(diplomadoChanged5(QString)));
    }
}


void procesos_ces::diplomadoChanged5(QString s)
{
    QString diplo;

    QSqlQuery consulta("select id_diplomado from diplo_temp where descripcion='"+s+"'");
    while(consulta.next())
    {
        diplo=consulta.value(0).toString();
    }

    consulta.exec("select id from cohortes where id_diplomado='"+diplo+"'");
    while(consulta.next())
    {
        c_diplo_dialog.seleccion2->addItem(consulta.value(0).toString());
    }
    c_diplo_dialog.seleccion2->setEnabled(true);
}



void procesos_ces::llenarCambioDiplo()
{
    QSqlQuery consulta,consulta2,consulta3;
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    consulta.exec("select cedula_est,nombre,apellido,matricula from estudiante where matricula='"+le->text()+"' or cedula_est='"+le->text()+"'");
    while(consulta.next())
    {
        c_diplo_dialog.cedula->setText(consulta.value(0).toString());
        c_diplo_dialog.nombre->setText(consulta.value(1).toString()+" "+consulta.value(2).toString());
        c_diplo_dialog.matricula->setText(consulta.value(3).toString());
    }
    c_diplo_dialog.diplomado->setText("");
    c_diplo_dialog.horario->setText("");

    consulta.exec("select id_curso,id_seccion from ficha_academica where matricula='"+c_diplo_dialog.matricula->text()+"' and id_evento='2' and status='V'");
    while(consulta.next())
    {
        c_diplo_dialog.cohorte->setText(consulta.value(1).toString());
        consulta2.exec("select descripcion from diplo_temp where id_diplomado='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            c_diplo_dialog.diplomado->setText(consulta2.value(0).toString());
        }
        consulta2.exec("select id_modalidad,id_horario from cohortes where id='"+consulta.value(1).toString()+"'");
        while(consulta2.next())
        {
            QSqlQuery consulta3("select descripcion from modalidades where id_modalidad='"+consulta2.value(0).toString()+"'");
            while(consulta3.next())
            {
                c_diplo_dialog.horario->setText(consulta3.value(0).toString()+"-"+consulta2.value(1).toString());
            }
        }
    }
    c_diplo_dialog.seleccion->clear();
    c_diplo_dialog.seleccion->setEnabled(false);
    connect(c_diplo_dialog.aceptar,SIGNAL(clicked()),this,SLOT(cambiarDiplo()));
}


void procesos_ces::cambiarDiplo()
{
    QSqlQuery consulta,consulta2;
    QString fecha,num,cohorte,modalidad,mod,diplo,diplold;
    int tope,actual;
    actual=0;
    if(c_diplo_dialog.rhorario->isChecked())
    {
        num=c_diplo_dialog.seleccion->currentText().left(2);
        modalidad=c_diplo_dialog.seleccion->currentText().remove(num+" (");
        modalidad=modalidad.left(modalidad.indexOf("-"));
        consulta.exec("select id_modalidad from modalidades where descripcion='"+modalidad+"'");
        while(consulta.next())
        {
            mod=consulta.value(0).toString();
        }

        consulta.exec("select id from cohortes where id_diplomado=(select id_diplomado from diplo_temp where descripcion='"+c_diplo_dialog.diplomado->text()+"') and cohorte='"+num+"' and id_modalidad='"+mod+"'");
        {
            cohorte=consulta.value(0).toString();
        }

        if(!consulta.exec("update ficha_academica set id_seccion='"+cohorte+"' where matricula='"+c_diplo_dialog.matricula->text()+"' and status='V' and id_seccion='"+c_diplo_dialog.cohorte->text()+"'"))
            QMessageBox::critical(0,"Error",consulta.lastError().text());
        else
        {
            consulta.exec("commit");
            QMessageBox::information(0,"","Información actualizada correctamente");
            estudianteFrame->close();
        }
    }
    else
    {
        consulta.exec("select id_diplomado from diplo_temp where descripcion='"+c_diplo_dialog.diplomado->text()+"'");
        while(consulta.next())
        {
            diplold=consulta.value(0).toString();
        }
        consulta.exec("select id_diplomado,maximo from diplo_temp where descripcion='"+c_diplo_dialog.seleccion->currentText()+"'");
        while(consulta.next())
        {
            diplo=consulta.value(0).toString();
            tope=consulta.value(1).toInt();
        }

        consulta.exec("select cant_actual from cohortes where id_diplomado='"+diplo+"' and id='"+c_diplo_dialog.seleccion2->currentText()+"'");
        while(consulta.next())
        {
            actual=consulta.value(0).toInt();
        }
        if(tope>actual)
        {
            consulta.exec("select cant_actual from cohortes where id='"+c_diplo_dialog.cohorte->text()+"'");
            while(consulta.next())
            {
                if(!consulta2.exec("update cohortes set cant_actual='"+tr("%1").arg(consulta.value(0).toInt()-1)+"' where id='"+c_diplo_dialog.cohorte->text()+"'"))
                    QMessageBox::critical(0,"Error",consulta.lastError().text());
                else
                    consulta.exec("commit");
            }

            if(!consulta.exec("update ficha_academica set id_curso='"+diplo+"',id_seccion='"+c_diplo_dialog.seleccion2->currentText()+"' where matricula='"+c_diplo_dialog.matricula->text()+"' and status='V' and id_curso='"+diplold+"'"))
                QMessageBox::critical(0,"Error 1",consulta.lastError().text());
            else if(!consulta.exec("update ficha_pago_cfp set id_diplomado='"+diplo+"' where matricula='"+c_diplo_dialog.matricula->text()+"' and status='V' and id_diplomado='"+diplold+"'"))
                QMessageBox::critical(0,"Error 2",consulta.lastError().text());
            else
            {
                //consulta.exec("commit");
                actual++;
                if(!consulta.exec("update cohortes set cant_actual='"+tr("%1").arg(actual)+"' where id_diplomado='"+diplo+"' and id='"+c_diplo_dialog.seleccion2->currentText()+"'"))
                    QMessageBox::critical(0,"Error 3",consulta.lastError().text());
                else
                {
                    consulta.exec("commit");
                    QMessageBox::information(0,"","Información actualizada correctamente");
                    estudianteFrame->close();
                }
            }
        }
        else
            QMessageBox::information(0,"","Cohorte Llena");
    }
}

void procesos_ces::setCambioMetodo()//Crear cambio de metodo
{
    estudianteFrame = new QWidget();
    c_seccion_dialog.setupUi(estudianteFrame);
    connect(c_seccion_dialog.matricula,SIGNAL(returnPressed()),this,SLOT(llenarCambioSeccion()));
    connect(c_seccion_dialog.cedula,SIGNAL(returnPressed()),this,SLOT(llenarCambioSeccion()));
    estudianteFrame->show();
    acop=true;
}


void procesos_ces::setCambioSeccion()//Dejar deshabilitados metodo y nivel en cambio de seccion
{
    estudianteFrame = new QWidget();
    c_seccion_dialog.setupUi(estudianteFrame);
    connect(c_seccion_dialog.matricula,SIGNAL(returnPressed()),this,SLOT(llenarCambioSeccion()));
    connect(c_seccion_dialog.cedula,SIGNAL(returnPressed()),this,SLOT(llenarCambioSeccion()));
    estudianteFrame->show();
    acop=false;
}


void procesos_ces::llenarCambioSeccion()
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    QSqlQuery consulta("select cedula_est,nombre,apellido,matricula from estudiante where matricula='"+le->text()+"' or cedula_est='"+le->text()+"'");
    while(consulta.next())
    {
        c_seccion_dialog.cedula->setText(consulta.value(0).toString());
        c_seccion_dialog.nombre->setText(consulta.value(1).toString()+" "+consulta.value(2).toString());
        c_seccion_dialog.matricula->setText(consulta.value(3).toString());
        //c_seccion_dialog.condicion->setText(consulta.value(2).toString());
    }

    consulta.exec("select id_curso,id_seccion from ficha_academica where matricula='"+c_seccion_dialog.matricula->text()+"' and id_evento='2' and status='V'");
    while(consulta.next())
    {
        c_seccion_dialog.curso->setText(consulta.value(0).toString());
        c_seccion_dialog.seccion->setText(consulta.value(1).toString());
        QSqlQuery consulta2("select nivel from secciones where id_seccion='"+consulta.value(1).toString()+"'");
        while(consulta2.next())
        {
            c_seccion_dialog.nivel->setText(consulta2.value(0).toString());
        }
    }
    c_seccion_dialog.nuevo_metodo->clear();
    c_seccion_dialog.nueva_seccion->clear();
    c_seccion_dialog.nuevo_nivel->clear();
    if(!acop)
    {
        consulta.exec("select id_seccion from secciones where id_metodo='"+c_seccion_dialog.curso->text()+"' and nivel='"+c_seccion_dialog.nivel->text()+"' and id_seccion<>'"+c_seccion_dialog.seccion->text()+"' order by id_seccion");
        while(consulta.next())
        {
            c_seccion_dialog.nueva_seccion->addItem(consulta.value(0).toString());
        }
        connect(c_seccion_dialog.aceptar,SIGNAL(clicked()),this,SLOT(cambiarSeccion()));
        c_seccion_dialog.nueva_seccion->setEnabled(true);
        c_seccion_dialog.nuevo_metodo->addItem(c_seccion_dialog.curso->text());
    }
    else
    {
        c_seccion_dialog.nuevo_metodo->addItem("-");
        consulta.exec("select id_metodo from metodos order by id_metodo");
        while(consulta.next())
        {
            c_seccion_dialog.nuevo_metodo->addItem(consulta.value(0).toString());
        }
        connect(c_seccion_dialog.nuevo_metodo,SIGNAL(currentIndexChanged(QString)),this,SLOT(metodoChanged5(QString)));
        c_seccion_dialog.nuevo_metodo->setEnabled(true);
    }
}


void procesos_ces::metodoChanged5(QString s)
{
    int i;
    c_seccion_dialog.nuevo_nivel->addItem("-");
    QSqlQuery consulta("select niveles from metodos where id_metodo='"+s+"'");
    while(consulta.next())
    {
        for(i=1;i<=consulta.value(0).toInt();i++)
            c_seccion_dialog.nuevo_nivel->addItem(tr("%1").arg(i));
    }
    connect(c_seccion_dialog.nuevo_nivel,SIGNAL(currentIndexChanged(QString)),this,SLOT(nivelChanged4(QString)));
    c_seccion_dialog.nuevo_nivel->setEnabled(true);
}


void procesos_ces::nivelChanged4(QString s)
{
    QSqlQuery consulta("select id_seccion from secciones where id_metodo='"+c_seccion_dialog.nuevo_metodo->currentText()+"' and nivel='"+s+"' order by id_seccion");
    while(consulta.next())
    {
        c_seccion_dialog.nueva_seccion->addItem(consulta.value(0).toString());
    }
    c_seccion_dialog.nueva_seccion->setEnabled(true);
    connect(c_seccion_dialog.aceptar,SIGNAL(clicked()),this,SLOT(cambiarSeccion()));
}


void procesos_ces::cambiarSeccion()
{
    QSqlQuery consulta,consulta2;
    QString fecha;
    int tope,actual;
    consulta.exec("select tope,cant_actual,to_char(fec_inicio,'dd-mm-yyyy') from secciones where id_metodo='"+c_seccion_dialog.nuevo_metodo->currentText()+"' and id_seccion='"+c_seccion_dialog.nueva_seccion->currentText()+"'");
    while(consulta.next())
    {
        fecha=consulta.value(2).toString();
        tope=consulta.value(0).toInt();
        actual=consulta.value(1).toInt();
    }
    if(tope>actual)
    {
        consulta.exec("select cant_actual from secciones where id_seccion='"+c_seccion_dialog.seccion->text()+"' and id_metodo='"+c_seccion_dialog.curso->text()+"'");
        while(consulta.next())
        {
            if(!consulta2.exec("update secciones set cant_actual='"+tr("%1").arg(consulta.value(0).toInt()-1)+"' where id_seccion='"+c_seccion_dialog.seccion->text()+"' and id_metodo='"+c_seccion_dialog.curso->text()+"'"))
                QMessageBox::critical(0,"Error",consulta.lastError().text());
        }
        if(!acop)
            consulta.prepare("update ficha_academica set id_seccion='"+c_seccion_dialog.nueva_seccion->currentText()+"',fec_inicio=to_date('"+fecha+"','dd-mm-yyyy') where matricula='"+c_seccion_dialog.matricula->text()+"' and status='V' and id_seccion='"+c_seccion_dialog.seccion->text()+"'");
        else
            consulta.prepare("update ficha_academica set id_curso='"+c_seccion_dialog.nuevo_metodo->currentText()+"',id_seccion='"+c_seccion_dialog.nueva_seccion->currentText()+"',fec_inicio=to_date('"+fecha+"','dd-mm-yyyy') where matricula='"+c_seccion_dialog.matricula->text()+"' and status='V' and id_seccion='"+c_seccion_dialog.seccion->text()+"'");

        if(!consulta.exec())
            QMessageBox::critical(0,"Error",consulta.lastError().text());
        else
        {
            if(!consulta.exec("update secciones set cant_actual='"+tr("%1").arg(actual+1)+"' where id_seccion='"+c_seccion_dialog.nueva_seccion->currentText()+"' and id_metodo='"+c_seccion_dialog.nuevo_metodo->currentText()+"'"))
                QMessageBox::critical(0,"Error",consulta.lastError().text());
            else
            {
                consulta.exec("commit");
                QMessageBox::information(0,"","Información actualizada correctamente");
                estudianteFrame->close();
            }
        }
    }
    else
        QMessageBox::information(0,"","Sección Llena");
}


void procesos_ces::setFusionSeccion()
{
    estudianteFrame = new QWidget();
    f_seccion_dialog.setupUi(estudianteFrame);
    QSqlQuery consulta;

    f_seccion_dialog.metodo->addItem("-");
    consulta.exec("select descripcion from metodos order by descripcion");
    while(consulta.next())
    {
        f_seccion_dialog.metodo->addItem(consulta.value(0).toString());
    }

    f_seccion_dialog.edif->addItem("-");
    consulta.exec("select descripcion from edificios order by descripcion");
    while(consulta.next())
    {
        f_seccion_dialog.edif->addItem(consulta.value(0).toString());
    }

    connect(f_seccion_dialog.aceptar,SIGNAL(clicked()),this,SLOT(fusionarSeccion()));
    connect(f_seccion_dialog.metodo,SIGNAL(currentIndexChanged(QString)),this,SLOT(metodoChanged4(QString)));
    connect(f_seccion_dialog.edif,SIGNAL(currentIndexChanged(QString)),this,SLOT(edificioChanged2(QString)));
    estudianteFrame->show();
}

void procesos_ces::metodoChanged4(QString s)
{
    int i,levels;
    QString metodo;
    QSqlQuery consulta,consulta2;

    consulta.exec("select id_metodo from metodos where descripcion='"+s+"'");
    while(consulta.next())
    {
        metodo=consulta.value(0).toString();
    }
    consulta.exec("select niveles from metodos where id_metodo='"+metodo+"'");
    while(consulta.next())
    {
        levels=consulta.value(0).toInt();
    }

    f_seccion_dialog.modalidad->addItem("-");
    consulta.exec("select distinct(modalidad) from secciones where id_metodo='"+metodo+"'");
    while(consulta.next())
    {
        consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            f_seccion_dialog.modalidad->addItem(consulta2.value(0).toString());
        }
    }

    f_seccion_dialog.nivel->clear();
    f_seccion_dialog.nivel->addItem("-");
    for(i=0;i<levels;i++)
    {
        f_seccion_dialog.nivel->addItem(tr("%1").arg(i+1));
    }
    f_seccion_dialog.profesor->clear();
    f_seccion_dialog.profesor->addItem("-");
    consulta.exec("select distinct(cedula_prof) from secciones where id_metodo='"+metodo+"'");
    while(consulta.next())
    {
        QSqlQuery consulta2("select nombre,apellido from profesor where cedula_prof='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            f_seccion_dialog.profesor->addItem(consulta2.value(1).toString()+", "+consulta2.value(0).toString());
        }
    }
    connect(f_seccion_dialog.nivel,SIGNAL(currentIndexChanged(QString)),this,SLOT(nivelChanged3(QString)));
    //connect(f_seccion_dialog.modalidad,SIGNAL(currentIndexChanged(QString)),this,SLOT(modalidadChanged5(QString)));
    //Al fusionar verificar o dar la opcion de colocar nuevo tope. Eliminar la seccion absorbida. Verificar listados y numero actual.
}

void procesos_ces::nivelChanged3(QString s)
{
    QString metodo,mod,cal;
    QSqlQuery consulta;
    f_seccion_dialog.seccion1->clear();
    f_seccion_dialog.seccion2->clear();
    f_seccion_dialog.seccion1->addItem("-");
    f_seccion_dialog.seccion2->addItem("-");

    consulta.exec("select id_modalidad from modalidades where descripcion='"+f_seccion_dialog.modalidad->currentText()+"'");
    while(consulta.next())
    {
        mod=consulta.value(0).toString();
    }

    consulta.exec("select id_metodo from metodos where descripcion='"+f_seccion_dialog.metodo->currentText()+"'");
    while(consulta.next())
    {
        metodo=consulta.value(0).toString();
    }

    consulta.exec("select id_seccion from secciones where id_metodo='"+metodo+"' and modalidad='"+mod+"' and nivel='"+f_seccion_dialog.nivel->currentText()+"' order by id_seccion");
    while(consulta.next())
    {
        f_seccion_dialog.seccion1->addItem(consulta.value(0).toString());
        f_seccion_dialog.seccion2->addItem(consulta.value(0).toString());
    }

    consulta.exec("select id_calendario from metodos where descripcion='"+f_seccion_dialog.metodo->currentText()+"'");
    while(consulta.next())
    {
        cal=consulta.value(0).toString();
    }
    f_seccion_dialog.horario->clear();
    f_seccion_dialog.horario->addItem("-");
    consulta.exec("select to_char(hora,'HH12:MI AM'),to_char(hora_fin,'HH12:MI AM') from horarios");
    while(consulta.next())
    {
        f_seccion_dialog.horario->addItem(consulta.value(0).toString()+"-"+consulta.value(1).toString());
    }
    f_seccion_dialog.periodo->clear();
    f_seccion_dialog.periodo->addItem("-");
    consulta.exec("select periodo from calendarios_detalle where modalidad='"+mod+"' and id_calendario='"+cal+"' order by periodo");
    while(consulta.next())
    {
        f_seccion_dialog.periodo->addItem(consulta.value(0).toString());
    }
    connect(f_seccion_dialog.seccion1,SIGNAL(currentIndexChanged(QString)),this,SLOT(llenarCant(QString)));
    connect(f_seccion_dialog.seccion2,SIGNAL(currentIndexChanged(QString)),this,SLOT(llenarCant2(QString)));
}

void procesos_ces::llenarCant(QString s)
{
    QSqlQuery consulta("select cant_actual from secciones where id_seccion='"+s+"'");
    while(consulta.next())
    {
        f_seccion_dialog.cantidad1->setText(consulta.value(0).toString());
    }
    f_seccion_dialog.nueva_seccion->clear();
    f_seccion_dialog.nueva_seccion->addItem(s);
}


void procesos_ces::llenarCant2(QString s)
{
    QSqlQuery consulta("select cant_actual from secciones where id_seccion='"+s+"'");
    while(consulta.next())
    {
        f_seccion_dialog.cantidad2->setText(consulta.value(0).toString());
    }
    f_seccion_dialog.nueva_seccion->addItem(s);
}

void procesos_ces::edificioChanged2(QString s)
{
    QString edif;
    QSqlQuery consulta("select id_edif from edificios where descripcion='"+s+"'");
    while(consulta.next())
    {
        edif=consulta.value(0).toString();
    }

    f_seccion_dialog.aula->clear();
    f_seccion_dialog.aula->addItem("-");
    consulta.exec("select descripcion from salones where edificio='"+edif+"' order by id_salon");
    while(consulta.next())
    {
        f_seccion_dialog.aula->addItem(consulta.value(0).toString());
    }
    connect(f_seccion_dialog.aula,SIGNAL(currentIndexChanged(QString)),this,SLOT(salonChanged2(QString)));
}


void procesos_ces::salonChanged2(QString s)
{
    QSqlQuery consulta;
    QString edif;

    consulta.exec("select id_edif from edificios where descripcion='"+f_seccion_dialog.edif->currentText()+"'");
    while(consulta.next())
    {
        edif=consulta.value(0).toString();
    }

    consulta.exec("select capacidad from salones where descripcion='"+s+"' and edificio='"+edif+"'");
    while(consulta.next())
    {
        f_seccion_dialog.tope->setText(consulta.value(0).toString());
    }
    //llenar tope
}

void procesos_ces::modalidadChanged5(QString s)
{
    QSqlQuery consulta;
    QString mod,cal;

    consulta.exec("select id_modalidad from modalidades where descripcion='"+s+"'");
    while(consulta.next())
    {
        mod=consulta.value(0).toString();
    }

    consulta.exec("select id_calendario from metodos where descripcion='"+f_seccion_dialog.metodo->currentText()+"'");
    while(consulta.next())
    {
        cal=consulta.value(0).toString();
    }
    f_seccion_dialog.horario->clear();
    f_seccion_dialog.horario->addItem("-");
    consulta.exec("select to_char(hora,'HH12:MI AM'),to_char(hora_fin,'HH12:MI AM') from horarios");
    while(consulta.next())
    {
        f_seccion_dialog.horario->addItem(consulta.value(0).toString()+"-"+consulta.value(1).toString());
    }
    f_seccion_dialog.periodo->clear();
    f_seccion_dialog.periodo->addItem("-");
    consulta.exec("select periodo from calendarios_detalle where modalidad='"+mod+"' and id_calendario='"+cal+"' order by periodo");
    while(consulta.next())
    {
        f_seccion_dialog.periodo->addItem(consulta.value(0).toString());
    }

}

void procesos_ces::fusionarSeccion() //Revisar y ajustar a cambios de interfaz
{
    QSqlQuery consulta;
    QString cedula,edif,otra,modalidad,aula,apellido,nombre;

    apellido= f_seccion_dialog.profesor->currentText().left(f_seccion_dialog.profesor->currentText().indexOf(","));
    nombre= f_seccion_dialog.profesor->currentText().remove(apellido+", ",Qt::CaseInsensitive);
    consulta.exec("select cedula_prof from profesor where nombre='"+nombre+"' and apellido='"+apellido+"'");
    while(consulta.next())
    {
        cedula=consulta.value(0).toString();
    }

    consulta.exec("select id_edif from edificios where descripcion='"+f_seccion_dialog.edif->currentText()+"'");
    while(consulta.next())
    {
        edif=consulta.value(0).toString();
    }

    consulta.exec("select id_salon from salones where descripcion='"+f_seccion_dialog.aula->currentText()+"' and edificio='"+edif+"'");
    while(consulta.next())
    {
        aula=consulta.value(0).toString();

    }

    if(!consulta.exec("update ficha_academica set id_seccion='"+f_seccion_dialog.nueva_seccion->currentText()+"' where status='V' and (id_seccion='"+f_seccion_dialog.seccion1->currentText()+"' or id_seccion='"+f_seccion_dialog.seccion2->currentText()+"')"))
        QMessageBox::critical(0,"Error",consulta.lastError().text());
    else
        consulta.exec("commit");

    if(!consulta.exec("update secciones set id_salon='"+aula+"',tope='"+f_seccion_dialog.tope->text()+"',cant_actual='"+tr("%1").arg(f_seccion_dialog.cantidad1->text().toInt()+f_seccion_dialog.cantidad2->text().toInt())+"',id_edif='"+edif+"',horario='"+f_seccion_dialog.horario->currentText()+"',cedula_prof='"+cedula+"', periodo='"+f_seccion_dialog.periodo->currentText()+"' where id_seccion='"+f_seccion_dialog.nueva_seccion->currentText()+"'"))
        QMessageBox::critical(0,"Error",consulta.lastError().text());
    else
        consulta.exec("commit");

    if(f_seccion_dialog.nueva_seccion->currentIndex()==0)
        otra=f_seccion_dialog.nueva_seccion->itemText(1);
    else
        otra=f_seccion_dialog.nueva_seccion->itemText(0);


    if(!consulta.exec("delete secciones where id_seccion='"+otra+"'"))
        QMessageBox::critical(0,"Error",consulta.lastError().text());
    else
        consulta.exec("commit");

    estudianteFrame->close();
}


void procesos_ces::setRetiro()
{
    estudianteFrame = new QWidget();
    retiro_dialog.setupUi(estudianteFrame);

    connect(retiro_dialog.matricula,SIGNAL(returnPressed()),this,SLOT(llenarRetiro()));
    connect(retiro_dialog.cedula,SIGNAL(returnPressed()),this,SLOT(llenarRetiro2()));
    connect(retiro_dialog.retiro_check,SIGNAL(stateChanged(int)),this,SLOT(retiroChecked(int)));
    connect(retiro_dialog.suspension_check,SIGNAL(stateChanged(int)),this,SLOT(suspensionChecked(int)));
    connect(retiro_dialog.aceptar,SIGNAL(clicked()),this,SLOT(retiro_suspension()));
    estudianteFrame->show();
}


void procesos_ces::retiroChecked(int check)
{
    if(check==2)
        retiro_dialog.suspension_check->setChecked(false);
    else
        retiro_dialog.suspension_check->setChecked(true);
}


void procesos_ces::suspensionChecked(int check)
{
    if(check==2)
        retiro_dialog.retiro_check->setChecked(false);
    else
        retiro_dialog.retiro_check->setChecked(true);
}


void procesos_ces::llenarRetiro()
{
    QSqlQuery consulta2;
    QSqlQuery consulta("select cedula_est,nombre,apellido from estudiante where matricula='"+retiro_dialog.matricula->text()+"'");
    while(consulta.next())
    {
        retiro_dialog.cedula->setText(consulta.value(0).toString());
        retiro_dialog.nombre->setText(consulta.value(1).toString()+" "+consulta.value(2).toString());
    }

    consulta.exec("select id_curso,id_seccion from ficha_academica where matricula='"+retiro_dialog.matricula->text()+"' and id_evento='2' and status='V'");
    while(consulta.next())
    {
        retiro_dialog.curso->setText(consulta.value(0).toString());

        if(prog_academico=="3")
        {
            retiro_dialog.label_4->setText("Diplomado");
            retiro_dialog.label_5->setText("Cohorte");
            consulta2.exec("select cohorte from cohortes where id='"+consulta.value(1).toString()+"'");
        }
        else
            consulta2.exec("select nivel from secciones where id_seccion='"+consulta.value(1).toString()+"'");
        while(consulta2.next())
        {
            retiro_dialog.nivel->setText(consulta2.value(0).toString());
        }
    }
}


void procesos_ces::llenarRetiro2()//????
{
    QSqlQuery consulta("select matricula,nombre from estudiante where matricula='"+retiro_dialog.cedula->text()+"'");
    while(consulta.next())
    {
        retiro_dialog.matricula->setText(consulta.value(0).toString());
        retiro_dialog.nombre->setText(consulta.value(1).toString());
    }

    consulta.exec("select id_curso,id_seccion from ficha_academica where matricula='"+retiro_dialog.matricula->text()+"' and id_evento='2' and status='V'");
    while(consulta.next())
    {
        retiro_dialog.curso->setText(consulta.value(0).toString());

        QSqlQuery consulta2("select nivel from secciones where id_seccion='"+consulta.value(1).toString()+"'");
        while(consulta2.next())
        {
            retiro_dialog.nivel->setText(consulta2.value(0).toString());
        }
    }
}


void procesos_ces::retiro_suspension()
{
    QSqlQuery consulta;//PENSAR EN FORMA OPTIMA DE CAMBIAR DE TABLA. PROBAR

   if(retiro_dialog.suspension_check->isChecked())
   {
        if(!consulta.exec("update ficha_academica set status='H' where matricula='"+retiro_dialog.matricula->text()+"' and status='V'"))
            QMessageBox::critical(0,"Error",consulta.lastError().text());
        else
        {
            consulta.exec("commit");
            if(!consulta.exec("update estudiante set id_tipo_est='3' where matricula='"+retiro_dialog.matricula->text()+"'"))
                QMessageBox::critical(0,"Error Estudiante",consulta.lastError().text());
            else
            {
                if(!consulta.exec("insert into ficha_academica values(ficha_academica_s.nextval,'51',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'0','N/A','N/A','"+retiro_dialog.curso->text()+"','"+retiro_dialog.matricula->text()+"','V','')"))
                    QMessageBox::critical(0,"Error Ficha Academica",consulta.lastError().text());
                else
                {
                    consulta.exec("commit");
                    QMessageBox::information(0,"","Suspendido");
                    estudianteFrame->close();
                }
            }
        }
   }
   else if(retiro_dialog.retiro_check->isChecked())
   {
        if(!consulta.exec("update ficha_academica set status='H' where matricula='"+retiro_dialog.matricula->text()+"' and status='V'"))
            QMessageBox::critical(0,"Error",consulta.lastError().text());
        else
        {
            consulta.exec("commit");

            if(!consulta.exec("insert into ficha_academica values(ficha_academica_s.nextval,'52',to_date('"+QDate::currentDate().toString("dd-MM-yyyy")+"','dd-mm-yyyy'),'0','N/A','N/A','"+retiro_dialog.curso->text()+"','"+retiro_dialog.matricula->text()+"','H','')"))
                QMessageBox::critical(0,"Error",consulta.lastError().text());
            else
            {
                consulta.exec("commit");
                QMessageBox::information(0,"","Retiro Exitoso");
                estudianteFrame->close();
            }
        }
    }
}


void procesos_ces::setGraduandos()
{
    QSqlQuery consulta;

    estudianteFrame = new QWidget();
    lista_dialog.setupUi(estudianteFrame);

    consulta.exec("select descripcion from metodos order by descripcion");
    while(consulta.next())
    {
        lista_dialog.metodo->addItem(consulta.value(0).toString());
    }

    connect(lista_dialog.boton_generar,SIGNAL(clicked()),this,SLOT(listaGraduandos()));
    lista_dialog.label->setText("Listado Graduandos");
    lista_dialog.nivel->setEnabled(false);
    lista_dialog.seccion->setEnabled(false);
    lista_dialog.salida->addItem("PANTALLA");
    lista_dialog.salida->addItem("IMPRESORA");

    lista_dialog.boton_generar->setEnabled(true);
    estudianteFrame->show();
}


void procesos_ces::listaGraduandos()
{
        QString nivel,s,seccion;
        QSqlQuery consulta,consulta2;
        QStandardItemModel *model=new QStandardItemModel(0,25);
        QStandardItem *item;
        int nota,i,x;
        i=-1;

        report->reset();
        report->addParameter("metodo",lista_dialog.metodo->currentText());
        //report->addParameter("periodo","5");//buscar periodo

        consulta.exec("select id_metodo from metodos where descripcion='"+lista_dialog.metodo->currentText()+"'");
        while(consulta.next())
        {
                s=consulta.value(0).toString();
        }

        consulta.exec("select niveles from metodos where id_metodo='"+s+"'");
        while(consulta.next())
        {
                nivel=consulta.value(0).toString();
        }

        consulta.exec("select nota_minima from niveles where nivel='"+nivel+"' and id_metodo='"+s+"'");
        while(consulta.next())
        {
                nota=consulta.value(0).toInt();
        }

        consulta.exec("select id_seccion,cedula_prof,horario from secciones where id_metodo='"+s+"' and nivel='"+nivel+"'");
        while(consulta.next())
        {
                seccion=consulta.value(0).toString();
                report->addParameter("horario",consulta.value(2).toString());
                consulta2.exec("select nombre from profesor where cedula_prof='"+consulta.value(1).toString()+"'");
                while(consulta2.next())
                {
                        report->addParameter("profesor",consulta2.value(0).toString());
                }
        }

        consulta.exec("select matricula from ficha_academica where id_evento='2' and id_seccion='"+lista_dialog.seccion->currentText()+"' and status='V' and fec_inicio >= to_date('"+lista_dialog.fecini->date().toString("dd-MM-yyyy")+"','dd-mm-yyyy')");
        while(consulta.next())
        {
                if(consulta.value(1).toInt()>=nota)//buscar la minima del nivel y metodo.
                {
                        consulta2.exec("select nombre,cedula_est,apellido,telf_hab from estudiante where matricula='"+consulta.value(0).toString()+"'");
                        while(consulta2.next())
                        {
                                i++;
                                model->insertRow(i);
                                item=new QStandardItem();
                                item->setData(i+1,Qt::EditRole);
                                model->setItem(i,0,item);
                                item=new QStandardItem();
                                item->setData(consulta2.value(0).toString()+" "+consulta2.value(2).toString(),Qt::EditRole);
                                model->setItem(i,1,item);
                                item=new QStandardItem();
                                item->setData(consulta2.value(1).toString(),Qt::EditRole);
                                model->setItem(i,2,item);
                                item=new QStandardItem();
                                item->setData(consulta2.value(3).toString(),Qt::EditRole);
                                model->setItem(i,3,item);
                        }

                        consulta2.exec("select id_fact from ficha_pago where matricula='"+consulta.value(0).toString()+"' and id_evento='16'");
                        while(consulta2.next())
                        {
                                item=new QStandardItem();
                                item->setData(consulta2.value(0).toString(),Qt::EditRole);
                                model->setItem(i,4,item);
                        }
                        x=5;
                        consulta2.exec("select calificacion,to_char(fec_inicio,'dd-mm-yyyy') from ficha_academica where matricula='"+consulta.value(0).toString()+"' and id_evento='21' order by fec_inicio");
                        while(consulta2.next())
                        {
                                item=new QStandardItem();
                                item->setData(consulta2.value(0).toString(),Qt::EditRole);
                                model->setItem(i,x,item);
                                x++;
                                item=new QStandardItem();
                                item->setData(consulta2.value(1).toString(),Qt::EditRole);
                                model->setItem(i,x,item);
                                x++;
                        }
                }
        }
        report->setReportFile("reportes/graduandos_idiomas.xml");
        report->addItemModel(model,"model");
        report->runReportToPDF("test.pdf");
        estudianteFrame->close();
        if (!report->hasError())
        {
                if(lista_dialog.salida->currentIndex()==1)
                        ShellExecuteA(NULL,"print",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
                else
                        ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        }
        else
                QMessageBox::information(0,"Error",report->lastErrorMsg());
}


void procesos_ces::indicadores()
{
        QSqlQuery consulta,consulta2,consulta3,consulta4,consulta5;
        QStandardItem *item;
        QStandardItemModel *model=new QStandardItemModel(1,15);
        int cont,x;
        x=0;
        report->reset();
        bool flag=false;

        consulta.exec("select id_metodo,id_calendario from metodos");
        while(consulta.next())
        {
                item = new QStandardItem();
                item->setData(consulta.value(0).toString(),Qt::EditRole);
                model->setItem(x,0,item);//metodo
                consulta5.exec("select id_modalidad,descripcion from modalidades");
                while(consulta5.next())
                {

                        consulta2.exec("select periodo,to_char(fecha_ini,'dd-mm-yyyy'),to_char(fecha_fin,'dd-mm-yyyy') from calendarios_detalle where id_calendario='"+consulta.value(1).toString()+"' and modalidad='"+consulta5.value(0).toString()+"'");
                        while(consulta2.next())
                        {
                                cont=0;
                                consulta3.exec("select id_seccion from secciones where id_metodo='"+consulta.value(0).toString()+"' and nivel=1 and modalidad='"+consulta2.value(3).toString()+"'");
                                while(consulta3.next())
                                {
                                        consulta4.exec("select matricula from ficha_academica where id_evento=2 and id_seccion='"+consulta3.value(0).toString()+"' and fec_inicio between to_date('"+consulta2.value(1).toString()+"','dd-mm-yyyy') and to_date('"+consulta2.value(2).toString()+"','dd-mm-yyyy')");
                                        while(consulta4.next())
                                        {
                                                cont++;
                                        }
                                }
                                //coloco los periodos conforme van rodando.... pensar donde va la modalidad
                                item = new QStandardItem();
                                item->setData(cont,Qt::EditRole);
                                model->setItem(x,consulta2.value(0).toInt(),item);
                                flag=true;
                        }
                        if(flag)
                        {
                                item = new QStandardItem();
                                item->setData(consulta5.value(1).toString(),Qt::EditRole);
                                model->setItem(x,14,item);
                                flag=false;
                                x++;
                                model->insertRow(x);
                        }
                }
        }
        model->removeRow(x);
        report->addItemModel(model,"model");
        report->setReportFile("reportes/indicador_1.xml");
        report->runReportToPDF("test.pdf");

        if (!report->hasError())
                ShellExecuteA(NULL,"open",tr("test.pdf"),NULL,NULL,SW_SHOWNORMAL);
        else
                QMessageBox::information(0,"Error",report->lastErrorMsg());
}


void procesos_ces::setMercadeo(int tipo)
{
    QSqlQuery consulta;
    switch(tipo)
    {
        case 1:
        {
            estudianteFrame = new QWidget();
            gen_dialog.setupUi(estudianteFrame);
            gen_dialog.etiqueta->setVisible(false);
            gen_dialog.cedula->setVisible(false);
            gen_dialog.titulo->setText("Participantes");

            consulta.exec("select descripcion from companias order by descripcion");
            while(consulta.next())
            {
                gen_dialog.combo->addItem(consulta.value(0).toString());
            }
            connect(gen_dialog.aceptar,SIGNAL(clicked()),this,SLOT(listadoMercadeo()));
            estudianteFrame->show();
        }break;
        case 2:
        {
            frame = new QFrame();
            reg_mercadeo.setupUi(frame);
            container.workspace->setWidget(frame);
            reg_mercadeo.curso->addItem("-");
            consulta.exec("select descripcion from metodos where prog_academico in (1,2) order by descripcion");
            while(consulta.next())
            {
                reg_mercadeo.curso->addItem(consulta.value(0).toString());
            }
            connect(reg_mercadeo.curso,SIGNAL(currentIndexChanged(QString)),this,SLOT(cursoChanged(QString)));
            reg_mercadeo.tabla->setColumnWidth(0,300);
            reg_mercadeo.tabla->setColumnWidth(2,200);
            reg_mercadeo.tabla->setColumnWidth(3,200);

        }break;
        case 3:
        {
            frame = new QFrame();
            reg_mercadeo.setupUi(frame);
            container.workspace->setWidget(frame);
            reg_mercadeo.titulo->setText("Estudiantes Diplomados");
            reg_mercadeo.label_curso->setText("Diplomado");
            reg_mercadeo.label_nivel->setText("Cohorte");
            reg_mercadeo.horario->setEnabled(false);
            reg_mercadeo.modalidad->setEnabled(false);
            reg_mercadeo.tabla->setColumnWidth(0,300);
            reg_mercadeo.tabla->setColumnWidth(2,200);
            reg_mercadeo.tabla->setColumnWidth(3,200);
        }break;
    }
}


void procesos_ces::listadoMercadeo()
{
    int i;
    QSqlQuery consulta;
    QFile file;
    QByteArray ba;
    QString sede;
    FILE *lista = fopen("participantes.txt","ab+");

    if(!file.open(lista,QIODevice::WriteOnly))
        return;

    consulta.exec("select codigo from companias where descripcion='"+gen_dialog.combo->currentText()+"'");
    while(consulta.next())
    {
        sede=consulta.value(0).toString();
    }
    consulta.exec("select apellido,nombre,telf_hab,telf_cel,email from estudiante where sede='"+sede+"' order by apellido");
    while(consulta.next())
    {
        ba=QByteArray();
        for(i=0;i<4;i++)
        {
            ba.append(consulta.value(i).toString());
            ba.append(",");
        }
        ba.append("\n");
        file.write(ba);
    }
    file.close();
    QMessageBox::information(0,"Agregar al archivo","Listo");
    estudianteFrame->close();
}


void procesos_ces::cursoChanged(QString s)
{
    QSqlQuery consulta,consulta2;
    QTableWidgetItem *ni;
    QString metodo;
    int i,row;

    reg_mercadeo.nivel->clear();
    reg_mercadeo.modalidad->clear();
    reg_mercadeo.nivel->addItem("-");
    reg_mercadeo.modalidad->addItem("-");
    consulta.exec("select niveles,id_metodo from metodos where descripcion='"+s+"'");
    while(consulta.next())
    {
        metodo=consulta.value(1).toString();
        for(i=0;i<consulta.value(0).toInt();i++)
            reg_mercadeo.nivel->addItem(tr("%1").arg(i+1));
    }

    consulta.exec("select distinct(modalidad) from secciones where id_metodo='"+metodo+"' order by modalidad");
    while(consulta.next())
    {
        consulta2.exec("select descripcion from modalidades where id_modalidad='"+consulta.value(0).toString()+"'");
        while(consulta2.next())
        {
            reg_mercadeo.modalidad->addItem(consulta2.value(0).toString());
        }
    }
    connect(reg_mercadeo.modalidad,SIGNAL(currentIndexChanged(QString)),this,SLOT(mod_nivelChanged(QString)));

    for(i=reg_mercadeo.tabla->rowCount()-1;i>=0;i--)
        reg_mercadeo.tabla->removeRow(i);

    //estudiantes del curso x - remover suspendidos?

    consulta.exec("select nombre,apellido,cedula_est,email,telf_hab,telf_cel from estudiante where matricula in (select matricula from ficha_academica where id_curso='"+metodo+"') order by apellido");
    while(consulta.next())
    {
        //llenar tabla: Nombre Cedula Telefono Email
        row = reg_mercadeo.tabla->rowCount();
        reg_mercadeo.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()+", "+consulta.value(0).toString()));
        reg_mercadeo.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        reg_mercadeo.tabla->setItem(row,1,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        reg_mercadeo.tabla->setItem(row,2,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(4).toString()+" / "+consulta.value(5).toString()));
        reg_mercadeo.tabla->setItem(row,3,ni);
    }
}


void procesos_ces::mod_nivelChanged(QString s)
{
    QSqlQuery consulta;
    QString mod,metodo;
    QTableWidgetItem *ni;
    int i,row;

    reg_mercadeo.horario->clear();
    reg_mercadeo.horario->addItem("-");
    consulta.exec("select id_modalidad from modalidades where descripcion='"+s+"'");
    while(consulta.next())
    {
        mod=consulta.value(0).toString();
    }

    consulta.exec("select id_metodo from metodos where descripcion='"+reg_mercadeo.curso->currentText()+"'");
    while(consulta.next())
    {
        metodo=consulta.value(0).toString();
    }

    consulta.exec("select distinct(horario) from secciones where id_metodo='"+metodo+"' and modalidad='"+mod+"' and nivel='"+reg_mercadeo.nivel->currentText()+"'");
    while(consulta.next())
    {
        reg_mercadeo.horario->addItem(consulta.value(0).toString());
    }
    connect(reg_mercadeo.horario,SIGNAL(currentIndexChanged(QString)),this,SLOT(horarioChanged(QString)));

    for(i=reg_mercadeo.tabla->rowCount()-1;i>=0;i--)
        reg_mercadeo.tabla->removeRow(i);

    //debe mostrar estudiantes en esa modalidad y nivel del periodo actual - atencion al calendario

    consulta.exec("select nombre,apellido,cedula_est,email,telf_hab,telf_cel from estudiante where matricula in (select matricula from ficha_academica where id_curso='"+metodo+"') order by apellido");
    while(consulta.next())
    {
        //llenar tabla: Nombre Cedula Telefono Email
        row = reg_mercadeo.tabla->rowCount();
        reg_mercadeo.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()+", "+consulta.value(0).toString()));
        reg_mercadeo.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        reg_mercadeo.tabla->setItem(row,1,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        reg_mercadeo.tabla->setItem(row,2,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(4).toString()+" / "+consulta.value(5).toString()));
        reg_mercadeo.tabla->setItem(row,3,ni);
    }
}


void procesos_ces::horarioChanged(QString s)
{

}

/*void procesos_ces::crearCarnet()
{

}*/


procesos_ces::~procesos_ces()
{

}

