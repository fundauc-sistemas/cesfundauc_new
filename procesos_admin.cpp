/*
 * procesos_admin.cpp
 *
 *  Created on: 26/08/2009
 *      Author: Sistemas
 */
#include "procesos_admin.h"

procesos_admin::procesos_admin(QWidget *parent): QWidget(parent)
{
    container.setupUi(this);
}


void procesos_admin::toUpper(QString s)
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    if (!le)
        return;
    le->setText(s.toUpper());
}


void procesos_admin::registroUsuarios()
{
    frame = new QFrame();
    reg_usuarios.setupUi(frame);
    container.workspace->setWidget(frame);

    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(borrarUsuario()));
    container.botonAnular->setEnabled(true);
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoUsuario()));
    container.botonNuevo->setEnabled(true);
    connect(reg_usuarios.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarUsuario(int,int)));

    reg_usuarios.tabla->setColumnWidth(0,100);
    reg_usuarios.tabla->setColumnWidth(1,70);
    reg_usuarios.tabla->setColumnWidth(2,180);
    reg_usuarios.tabla->setColumnWidth(3,250);
    reg_usuarios.tabla->setColumnWidth(4,80);
    reg_usuarios.tabla->setColumnWidth(5,380);
    reg_usuarios.tabla->setColumnWidth(6,180);
    reg_usuarios.tabla->setColumnWidth(7,120);

    llenarUsuario();
}


void procesos_admin::llenarUsuario()
{
    QSqlQuery consulta,consulta2;
    int i,row;
    QTableWidgetItem *ni;
    for(i=reg_usuarios.tabla->rowCount()-1;i>=0;i--)
        reg_usuarios.tabla->removeRow(i);

    consulta.exec("select nombre_usuario,cedula,nombre,email,contrasena,cia,prog_academico,id_rol from usuarios order by nombre_usuario");
    while(consulta.next())
    {
        row = reg_usuarios.tabla->rowCount();
        reg_usuarios.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        reg_usuarios.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        reg_usuarios.tabla->setItem(row,1,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        reg_usuarios.tabla->setItem(row,2,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        reg_usuarios.tabla->setItem(row,3,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(4).toString()));
        reg_usuarios.tabla->setItem(row,4,ni);
        consulta2.exec("select descripcion from companias where id='"+consulta.value(5).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_usuarios.tabla->setItem(row,5,ni);
        }
        consulta2.exec("select descripcion from programa_academico where id='"+consulta.value(6).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_usuarios.tabla->setItem(row,6,ni);
        }
        consulta2.exec("select descripcion from roles where id_rol='"+consulta.value(7).toString()+"'");
        while(consulta2.next())
        {
            ni = new QTableWidgetItem(tr("%1").arg(consulta2.value(0).toString()));
            reg_usuarios.tabla->setItem(row,7,ni);
        }
    }
}


void procesos_admin::nuevoUsuario()
{
    QComboBox *aux;
    QSqlQuery consulta;
    int row = reg_usuarios.tabla->rowCount();
    reg_usuarios.tabla->insertRow(row);

    lines = new QList<QLineEdit*>();
    combos = new QList<QComboBox*>();

    lines->append(new QLineEdit());
    reg_usuarios.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit());
    reg_usuarios.tabla->setCellWidget(row,1,lines->last());
    lines->append(new QLineEdit());
    reg_usuarios.tabla->setCellWidget(row,2,lines->last());
    lines->append(new QLineEdit());
    reg_usuarios.tabla->setCellWidget(row,3,lines->last());
    lines->append(new QLineEdit());
    reg_usuarios.tabla->setCellWidget(row,4,lines->last());
    aux = new QComboBox();
    consulta.exec("select descripcion from companias order by id");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    combos->append(aux);
    reg_usuarios.tabla->setCellWidget(row,5,combos->last());
    aux = new QComboBox();
    consulta.exec("select descripcion from programa_academico");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    combos->append(aux);
    reg_usuarios.tabla->setCellWidget(row,6,combos->last());
    aux = new QComboBox();
    consulta.exec("select descripcion from roles order by id_rol");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    combos->append(aux);
    reg_usuarios.tabla->setCellWidget(row,7,combos->last());
    //reg_usuarios.tabla->scrollToItem(reg_usuarios.tabla->item(row,0),QAbstractItemView::EnsureVisible);
    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarUsuario()));
    container.botonGuardar->setEnabled(true);
    connect(reg_usuarios.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_usuarios.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_usuarios.tabla->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_usuarios.tabla->cellWidget(row,3),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_usuarios.tabla->cellWidget(row,4),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    reg_usuarios.tabla->setCurrentCell(row,0);
}

void procesos_admin::guardarUsuario()
{
    QSqlQuery consulta;
    QString cia,rol,prog;

    consulta.exec("select id from companias where descripcion='"+combos->at(0)->currentText()+"'");
    while(consulta.next())
    {
        cia=consulta.value(0).toString();
    }
    consulta.exec("select id from programa_academico where descripcion='"+combos->at(1)->currentText()+"'");
    while(consulta.next())
    {
        prog=consulta.value(0).toString();
    }
    consulta.exec("select id_rol from roles where descripcion='"+combos->at(2)->currentText()+"'");
    while(consulta.next())
    {
        rol=consulta.value(0).toString();
    }

    if(!consulta.exec("insert into usuarios values('"+lines->at(1)->text()+"','"+lines->at(0)->text()+"','"+lines->at(4)->text()+"','"+rol+"','"+lines->at(3)->text()+"','"+lines->at(2)->text()+"','"+cia+"','"+prog+"')"))
        QMessageBox::critical(0,"Error",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        llenarUsuario();
    }
}

void procesos_admin::editarUsuario(int row,int column)
{
    QComboBox *aux;
    QSqlQuery consulta;
    lines = new QList<QLineEdit*>();
    combos = new QList<QComboBox*>();

    updating = reg_usuarios.tabla->item(row,0)->text();
    lines->append(new QLineEdit(reg_usuarios.tabla->item(row,0)->text()));
    reg_usuarios.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit(reg_usuarios.tabla->item(row,1)->text()));
    reg_usuarios.tabla->setCellWidget(row,1,lines->last());
    lines->append(new QLineEdit(reg_usuarios.tabla->item(row,2)->text()));
    reg_usuarios.tabla->setCellWidget(row,2,lines->last());
    lines->append(new QLineEdit(reg_usuarios.tabla->item(row,3)->text()));
    reg_usuarios.tabla->setCellWidget(row,3,lines->last());
    lines->append(new QLineEdit(reg_usuarios.tabla->item(row,4)->text()));
    reg_usuarios.tabla->setCellWidget(row,4,lines->last());

    aux = new QComboBox();
    consulta.exec("select descripcion from companias order by id");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    aux->setCurrentIndex(aux->findText(reg_usuarios.tabla->item(row,5)->text()));
    combos->append(aux);
    reg_usuarios.tabla->setCellWidget(row,5,combos->last());

    aux = new QComboBox();
    consulta.exec("select descripcion from programa_academico");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    aux->setCurrentIndex(aux->findText(reg_usuarios.tabla->item(row,6)->text()));
    combos->append(aux);
    reg_usuarios.tabla->setCellWidget(row,6,combos->last());

    aux = new QComboBox();
    consulta.exec("select descripcion from roles order by id_rol");
    while(consulta.next())
    {
        aux->addItem(consulta.value(0).toString());
    }
    aux->setCurrentIndex(aux->findText(reg_usuarios.tabla->item(row,7)->text()));
    combos->append(aux);
    reg_usuarios.tabla->setCellWidget(row,7,combos->last());

    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarUsuario()));
    container.botonGuardar->setEnabled(true);
    connect(reg_usuarios.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_usuarios.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_usuarios.tabla->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_usuarios.tabla->cellWidget(row,3),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(reg_usuarios.tabla->cellWidget(row,4),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_admin::actualizarUsuario()
{
    QSqlQuery consulta;
    QString cia,rol,prog;

    consulta.exec("select id from companias where descripcion='"+combos->at(0)->currentText()+"'");
    while(consulta.next())
    {
        cia=consulta.value(0).toString();
    }
    consulta.exec("select id from programa_academico where descripcion='"+combos->at(1)->currentText()+"'");
    while(consulta.next())
    {
        prog=consulta.value(0).toString();
    }
    consulta.exec("select id_rol from roles where descripcion='"+combos->at(2)->currentText()+"'");
    while(consulta.next())
    {
        rol=consulta.value(0).toString();
    }

    if(!consulta.exec("update usuarios set cedula='"+lines->at(1)->text()+"',contrasena='"+lines->at(4)->text()+"',id_rol='"+rol+"',email='"+lines->at(3)->text()+"',nombre='"+lines->at(2)->text()+"',cia='"+cia+"',prog_academico='"+prog+"' where nombre_usuario='"+updating+"'"))
        QMessageBox::critical(0,"Error",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        llenarUsuario();
    }
}

void procesos_admin::borrarUsuario()
{
    int row= reg_usuarios.tabla->currentRow();
    if(row>=0)
    {
        QSqlQuery consulta;
        if(consulta.exec("delete from usuarios where nombre_usuario='"+reg_usuarios.tabla->item(row,0)->text()+"'"))
        {
            reg_usuarios.tabla->removeRow(row);
            consulta.exec("commit");
        }
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}

void procesos_admin::respaldo()
{
    system("exportar.bat");
}


void procesos_admin::registroProgramas()
{
    frame = new QFrame();
    programas.setupUi(frame);
    container.workspace->setWidget(frame);

    programas.tabla->setColumnWidth(2,300);
    programas.tabla->setColumnWidth(3,100);
    programas.tabla->setColumnWidth(4,250);
    programas.tabla->setColumnWidth(5,400);
    programas.tabla->setColumnWidth(6,200);

    llenarProgramas();
    disconnect(container.botonNuevo,SIGNAL(clicked()),0,0);
    disconnect(container.botonAnular,SIGNAL(clicked()),0,0);
    connect(container.botonNuevo,SIGNAL(clicked()),this,SLOT(nuevoPrograma()));
    connect(programas.tabla,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(editarPrograma(int,int)));
    connect(container.botonAnular,SIGNAL(clicked()),this,SLOT(eliminarPrograma()));

    container.botonNuevo->setEnabled(true);
    container.botonAnular->setEnabled(true);
}


void procesos_admin::llenarProgramas()
{
    int row,i;
    QTableWidgetItem *ni;

    for(i=programas.tabla->rowCount()-1;i>=0;i--)
        programas.tabla->removeRow(i);

    QSqlQuery consulta("select * from companias");
    while(consulta.next())
    {
        row = programas.tabla->rowCount();
        programas.tabla->insertRow(row);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(2).toString()));
        programas.tabla->setItem(row,0,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(0).toString()));
        programas.tabla->setItem(row,1,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(1).toString()));
        programas.tabla->setItem(row,2,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(4).toString()));
        programas.tabla->setItem(row,3,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(6).toString()));
        programas.tabla->setItem(row,4,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(3).toString()));
        programas.tabla->setItem(row,5,ni);
        ni = new QTableWidgetItem(tr("%1").arg(consulta.value(5).toString()));
        programas.tabla->setItem(row,6,ni);
    }
}


void procesos_admin::nuevoPrograma()
{
    int row = programas.tabla->rowCount();
    programas.tabla->insertRow(row);

    lines = new QList<QLineEdit*>();

    lines->append(new QLineEdit());
    programas.tabla->setCellWidget(row,0,lines->last());
    lines->append(new QLineEdit());
    programas.tabla->setCellWidget(row,1,lines->last());
    lines->append(new QLineEdit());
    programas.tabla->setCellWidget(row,2,lines->last());
    lines->append(new QLineEdit());
    programas.tabla->setCellWidget(row,3,lines->last());
    lines->append(new QLineEdit());
    programas.tabla->setCellWidget(row,4,lines->last());
    lines->append(new QLineEdit());
    programas.tabla->setCellWidget(row,5,lines->last());
    lines->append(new QLineEdit());
    programas.tabla->setCellWidget(row,6,lines->last());

    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(guardarPrograma()));
    container.botonGuardar->setEnabled(true);

    connect(programas.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(programas.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(programas.tabla->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(programas.tabla->cellWidget(row,3),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(programas.tabla->cellWidget(row,4),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(programas.tabla->cellWidget(row,5),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(programas.tabla->cellWidget(row,6),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_admin::editarPrograma(int row,int column)
{
    lines = new QList<QLineEdit*>();
    llenarProgramas();

    updating=programas.tabla->item(row,0)->text();

    lines->append(new QLineEdit(programas.tabla->item(row,1)->text()));
    programas.tabla->setCellWidget(row,1,lines->last());
    lines->append(new QLineEdit(programas.tabla->item(row,2)->text()));
    programas.tabla->setCellWidget(row,2,lines->last());
    lines->append(new QLineEdit(programas.tabla->item(row,3)->text()));
    programas.tabla->setCellWidget(row,3,lines->last());
    lines->append(new QLineEdit(programas.tabla->item(row,4)->text()));
    programas.tabla->setCellWidget(row,4,lines->last());
    lines->append(new QLineEdit(programas.tabla->item(row,5)->text()));
    programas.tabla->setCellWidget(row,5,lines->last());
    lines->append(new QLineEdit(programas.tabla->item(row,6)->text()));
    programas.tabla->setCellWidget(row,6,lines->last());

    disconnect(container.botonGuardar,SIGNAL(clicked()),0,0);
    connect(container.botonGuardar,SIGNAL(clicked()),this,SLOT(actualizarPrograma()));
    container.botonGuardar->setEnabled(true);

    connect(programas.tabla->cellWidget(row,0),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(programas.tabla->cellWidget(row,1),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(programas.tabla->cellWidget(row,2),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(programas.tabla->cellWidget(row,3),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(programas.tabla->cellWidget(row,4),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(programas.tabla->cellWidget(row,5),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(programas.tabla->cellWidget(row,6),SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
}


void procesos_admin::guardarPrograma()
{
    QSqlQuery consulta;

    if(!consulta.exec("insert into companias values('"+lines->at(1)->text()+"','"+lines->at(2)->text()+"','"+lines->at(0)->text()+"','"+lines->at(5)->text()+"','"+lines->at(3)->text()+"','"+lines->at(6)->text()+"','"+lines->at(4)->text()+"')"))
        QMessageBox::critical(0,"Error",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        llenarProgramas();
        container.botonGuardar->setEnabled(false);
    }
}


void procesos_admin::actualizarPrograma()
{
    QSqlQuery consulta;

    if(!consulta.exec("update companias set codigo='"+lines->at(0)->text()+"',descripcion='"+lines->at(1)->text()+"',direccion='"+lines->at(4)->text()+"',telefono='"+lines->at(2)->text()+"',email='"+lines->at(5)->text()+"',director='"+lines->at(3)->text()+"' where id='"+updating+"'"))
        QMessageBox::critical(0,"Error",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        llenarProgramas();
        container.botonGuardar->setEnabled(false);
    }
}


void procesos_admin::eliminarPrograma()
{
    int row= programas.tabla->currentRow();
    if(row>=0)
    {
        QSqlQuery consulta;
        if(consulta.exec("delete from companias where id='"+programas.tabla->item(row,0)->text()+"'"))
            programas.tabla->removeRow(row);
        else
            QMessageBox::critical(0,"Error",consulta.lastError().text());
    }
    else
        QMessageBox::information(0,"Aviso","Debe seleccionar un registro");
}

//importar respaldo

procesos_admin::~procesos_admin()
{

}

