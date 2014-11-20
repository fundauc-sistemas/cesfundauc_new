/*
 * procesos_caja.h
 *
 *  Created on: 12/03/2009
 *      Author: Oriana Gómez.
 */

#ifdef WIN32
# include <windows.h>
#endif
#ifndef PROCESOS_CAJA_H_
#define PROCESOS_CAJA_H_

#include <QtGui>
#include <QtSql>
#include <shellapi.h>
#include "ui_factura.h"
#include "ui_registro_deposito.h"
#include "ui_registro_facturas.h"
#include "ui_estudiante.h"
#include "procesos_ces.h"
#include "ui_ces.h"
#include "ui_cont_dialog.h"
#include "ui_ced_ingreso_dialog.h"
#include "ui_periodo_ingreso.h"
#include "ui_carnet.h"
#include "ui_cuentas_cobro.h"
#include "ui_codigos.h"
#include "ui_bancos.h"
#include "ncreport.h"
#include "ncreportoutput.h"
#include "ncreportpreviewoutput.h"
#include "ncreportpreviewwindow.h"
#include "ui_busqueda.h"
#include "ui_precios.h"
#include "ui_empresa.h"
#include "ui_nuevo_deposito.h"


class QTableWidget;
class QTextEdit;
class QMessageBox;
class QDateEdit;
class QTextEdit;
class QPushButton;

class procesos_caja : public QWidget
{
    Q_OBJECT

    public:
        procesos_caja(QString prog, QString user, QSqlDatabase db, QSqlDatabase db2, QWidget *parent = 0);
        ~procesos_caja();

        Ui::ces container;
        Ui::form factura;
        Ui::reg_factura reg_factura;
        Ui::reg_deposito reg_deposito;
        Ui::precios reg_precios;
        Ui::empresas reg_empresas;
        Ui::contingencia cont_dialog;
        Ui::ced_ingreso ced_dialog;
        Ui::periodo_ingreso per_dialog;
        Ui::carnet_form carnet_dialog;
        Ui::cuentas cuentas_cobro;
        Ui::codigos reg_codigo;
        Ui::bancos reg_bancos;
        Ui::busqueda busqueda_dialog;
        Ui::nuevodeposito new_deposito;

        QFrame *frame;

        void registroFacturas();
        void registroDepositos();
        void registroCodigos();
        void registroBancos();
        void registroPrecios();
        void registroEmpresas();
        void mesValija();
        void ingresosPeriodo();
        void seleccionProgramaAcademico();
        void seleccionTipoFactura();
        void setupCierre();
        void setupCedula();
        void cierreMensual();
        void crearCarnet();
        void cuentasPorCobrar();
        void setupComercializables();
        //bool crearConexionMysql();

    public slots:
        void nuevaFactura();

    private slots:
        void cuadreCaja();
        void cedulaMensual();
        void cuadreComercializables();
        void toUpper(QString s);
        void descripcionChanged();
        void nombreChanged();
        void cedulaChanged();
        void matriculaChanged();
        void cedulaChanged2();
        void matriculaChanged2();
        void imprimirCarnet();
        void rifChanged();
        void razonChanged();
        void chequeoEstudiante(QString matricula);
        void sameAsParticipant(bool checked);
        void facturaProforma(bool checked);
        void pagoChanged(const QString);
        void pagoChanged2(const QString);
        void ivaChanged(const QString);
        void agregarDeposito();
        void agregarDeposito2();
        void agregarItem();
        void verificarTipoItem(const QString);
        void llenarCurso(const QString);
        void llenarDiplomado(const QString);
        void llenarPreDiplomado(const QString);
        void llenarCerti(const QString);
        void llenarHorario(const QString);
        void precioChanged(const QString);
        void cantidadChanged(const QString);
        void imprimirFactura();
        void rifSelect(bool checked);
        void facturaSelect(bool checked);
        void referenciaSelect(bool checked);
        void yearSelect(bool checked);
        void yearSelect2(bool checked);
        void filtrarFact();
        void filtrarFecha();
        void filtrarEmpresa();
        void filtrarRef();
        void filtrarFecha_Bancos();
        void printFile(QTextDocument *documento);
        void cierreDepositos();
        void cierreFacturas();
        void anularFactura();
        void seleccionPA();
        void seleccionTF();
        void descuento(const QString);
        void quitarItem();
        void quitarItem2();
        void setPrecioCuota(const QString);
        void setPrecioCuota2(const QString);
        void setPrecioMaterial(const QString);
        void generarValija();
        void guardarFactura(QList<QList<QString> > items,QString factura,QString cedula,QString nombre,QString monto,QString piva,QString iva,QString dir,QString cedula2,QString nombre2,QString matricula,QString recibo);
        void buscarCuenta();
        void procesarCuenta();
        void guardarCodigo();
        void nuevoCodigoContable();
        void actualizarCodigoContable();
        void editarCodigoContable(int row,int column);
        void borrarCodigo();
        void llenarCodigosContables(const QString);
        void nuevoBanco();
        void editarBanco(int row,int column);
        void guardarBanco();
        void actualizarBanco();
        void rowSelected(int row,int column);
        void recargoNivelacion(QString s);
        void llenarEstudiante(int row,int column);
        void buscarDiplo(int row,int column);
        void buscarEmpresa(int row,int column);
        void programaChanged(QString s);
        void programaChanged2(QString s);
        void actualizarPrecio();
        void editarPrecio(int row,int column);
        void cursoChecked(int state);
        void libroChecked(int state);
        void guiaChecked(int state);
        void otroChecked(int state);
        void cdChecked(int state);
        void descuentoChecked(int state);
        void examenChecked(int state);
        void matriculaChecked(int state);
        void arancelChecked(int state);
        void constanciaChecked(int state);
        void boletaChecked(int state);
        void facturaChecked(int state);
        void nuevoDeposito();
        void guardarDeposito();
        void periodoChanged();
        void editarEmpresa(int row, int column);
        void actualizarEmpresa();

    private:

        QStringList tipo_item;
        QStringList years;
        QStringList meses;
        bool proforma;
        QWidget *dialogo;
        QWidget *dialogo2;
        QComboBox *d_curso;
        QComboBox *d_horario;
        QLineEdit *d_texto;
        QLabel *d_a;
        QLabel *d_b;
        QLabel *d_c;
        QPushButton *d_ok;
        QWidget *printFrame;
        QString f_seccion;
        QString f_curso;
        QString f_curso_desc;
        QString f_costo;
        QString f_fecha;
        QString programa;
        QString compania;
        QString usuario;
        QString prog_academico;
        QString updating;
        QString updating2;
        QString cuota_actual;
        int tipo_factura;
        QComboBox *sel_programa;
        QComboBox *sel_tipo;
        QDateEdit *top;
        QDateEdit *bottom;
        QList<QList<QString> > *detalle_paquete;
        QList<QLineEdit*> *lines;
        QList<QComboBox*> *combos;
        QList<QDateEdit*> *fechas;
        QList<int> *rows;
        QSqlDatabase database;
        NCReport *report;
        QSqlDatabase mysql;

        void facturaSetup();
        void depositoSetup();
        void prontoPago(QString cuota,QString diplo);
        QStringList listaBancos();
        //QStringList listaConceptos();
        QList<QList<QString> > pagoItems();
        QList<QList<QString> > orderItems();
        QList<QList<QString> > depositoItems();
        QList<QList<QString> > facturaItems();
        QList<QList<QString> > facturaConceptoItems();
        void seleccionPIdiomas();
        int determinarClaseDoc();
        void saldoDiferido(QString tabla);
        void llenarBancos();
        void llenarEmpresas();
        int totalDia(QList<QString> *items,QString fecha,QString academico);
        bool duplicarCohorte(QString s);


        QList<QString> paginate(QList<QList<QString> > items,QList<QList<QString> > pago_items,QString razon, QString rif, QString telefono, QString dir, QString iva, QString piva, int fact, QString cedula_est, QString nombre_est, QString matricula, QString condicion, int recibo);
        void crearFactura(QList<QList<QString> > items,QList<QList<QString> > pago_items,int pagina, QString nombre, QString cedula, QString telefono, QString dir, QString subtotal, QString iva, QString total, QString fact, bool copia, QString cedula_est, QString nombre_est, QString condicion);
};

#endif /* PROCESOS_CAJA_H_ */
