/*
 * procesos_ces.h
 *
 *  Created on: 15/05/2009
 *      Author: Oriana Gómez.
 */

#ifdef WIN32
#include <windows.h>
#endif
#ifndef PROCESOS_CES_H_
#define PROCESOS_CES_H_

#include <QtGui>
#include <QtSql>
#include <shellapi.h>
#include "ui_estudiante.h"
#include "ui_estudiantes.h"
#include "ui_cursos.h"
#include "ui_niveles.h"
#include "ui_condiciones.h"
#include "ui_tipo_estudiante.h"
#include "ui_materiales.h"
#include "ui_eventos.h"
#include "ui_calendarios.h"
#include "ui_horarios.h"
#include "ui_modalidades.h"
#include "ui_salones.h"
#include "ui_secciones.h"
#include "ui_seccion.h"
#include "ui_ficha_academica.h"
#include "ui_ficha_pago.h"
#include "ui_diplomados.h"
#include "ui_calendario_cfp.h"
#include "ui_carga_academica.h"
#include "ui_control_evaluacion_2.h"
#include "ui_control_evaluacion_cfp.h"
#include "ui_listado_seccion.h"
#include "ui_listado_cfp.h"
#include "ui_dialog_gen.h"
#include "ui_cambio_seccion.h"
#include "ui_cambio_diplo.h"
#include "ui_fusion_secciones.h"
#include "ui_retiro_suspension.h"
#include "ui_empresas.h"
#include "ui_ces.h"
#include "ui_calendario.h"
#include "ui_horario_cfp.h"
#include "ui_edificios.h"
#include "ui_actividades_cfp.h"
#include "ui_schedule_dialog.h"
#include "ui_asigna_salones.h"
#include "ui_historico.h"
#include "ui_mercadeo.h"

#include "ncreport.h"
#include "ncreportoutput.h"
#include "ncreportpreviewoutput.h"
#include "ncreportpreviewwindow.h"
#include "utils.h"
#include "info.h"


class QTableWidget;
class QTextEdit;
class QMessageBox;
class QDateEdit;
class QTextEdit;
class QPushButton;

class procesos_ces : public QWidget
{
    Q_OBJECT

    public:
        procesos_ces(QString programa,QString academico,QSqlDatabase db, QWidget *parent = 0);
        ~procesos_ces();

        Ui::ces container;
        Ui::estudiante reg_estudiante;
        Ui::estudiantes reg_estudiante2;
        Ui::cursos reg_curso;
        Ui::niveles reg_niveles;
        Ui::condiciones reg_condiciones;
        Ui::tipo_estudiante reg_tipoest;
        Ui::materiales reg_mat;
        Ui::eventos reg_eventos;
        Ui::calendario reg_cal;
        Ui::calendarioPago reg_cal2;
        Ui::calendarios reg_cals;
        Ui::horario reg_horario;
        Ui::salon reg_salones;
        Ui::asigna_salon asigna_salones;
        Ui::secciones reg_secciones;
        Ui::seccion new_seccion;
        Ui::academica ficha_academica;
        Ui::pago ficha_pago;
        Ui::diplomados reg_diplomado;
        Ui::ca carga_academica;
        Ui::evaluacion control_evaluacion;
        Ui::evaluacion_cfp control_eval_cfp;
        Ui::listado_seccion lista_dialog;
        Ui::listado_cfp lista_dialog2;
        Ui::dialogo gen_dialog;
        Ui::cambio_seccion c_seccion_dialog;
        Ui::cambio_diplo c_diplo_dialog;
        Ui::fusion_secciones f_seccion_dialog;
        Ui::retiro retiro_dialog;
        Ui::empresa reg_empresas;
        Ui::modalidad reg_modalidad;
        Ui::edificio reg_edificio;
        Ui::cohortes reg_cohorte;
        Ui::act_cfp reg_modulos;
        Ui::schedules book_dialog;
        Ui::historico reg_historico;
        Ui::mercadeo reg_mercadeo;

        QFrame *frame;

        void registroEmpresas(QString rif, QString matricula);
        void registroEstudiantes2();
        void registroProfesores();
        void registroMetodos();
        void registroNiveles();
        void registroCondiciones();
        void registroTipoEst();
        void registroDiplomados();
        void registroCertificacion();
        void registroModulos();
        void registroMat();
        void registroEventos();
        void registroSalones();
        void registroCalendario();
        void registroCalendarioPago();
        void registroSecciones();
        void registroCohortes();
        void registroCohortesCerti();
        void setFichaAcademica();
        void setFichaPago();
        void setFichaPagoCFP();
        void setControlEvaluacion();
        void setControlEvalCFP();
        void setControlAsistCFP();
        void setCargaAcademica();
        void setListados(int tipo);
        void setListadoIdiomas(int tipo);
        void setListadoDiplo();
        void setListadoProf();
        void constancias(int tipo);
        void setCambioSeccion();
        void setCambioMetodo();
        void setCambioDiplo();
        void setFusionSeccion();
        void setRetiro();
        void setGraduandos();
        void registroHorarios();
        void registroModalidades();
        void setListadoInscritos();
        void setListadosCFP(int tipo);
        void setMercadeo(int tipo);
        void setSchedule();
        void setHistorico();

    public slots:
        void nuevoEstudiante();
        void nuevoProfesor();
        void registroEstudiantes(QString cedula);

    private slots:

        void asignacionSalones();
        void setNuevoEstudiante();
        void llenarEstudiantes();
        void llenarProfesores();
        //void llenarCiudades(QString s);
        //void llenarZonas(QString s);
        void llenarMetodos();
        void llenarNiveles(QString s);
        void llenarCondiciones();
        void llenarTipoEst();
        void llenarDiplomados();
        void llenarCerti();
        void llenarMateriales();
        void llenarEventos();
        void llenarHorarios();
        void llenarSalones();
        void llenarSecciones(QString s);
        void llenarCohortes(QString s);
        void llenarCohortesC(QString s);
        //void llenarCargaAcademica(QString s);
        void llenarControlEvaluacion(QString s);
        void llenarControlEvalCFP(QString s);
        void llenarControlAsistCFP(QString s);
        void llenarModalidad();
        void llenarModalidades(QString s);
        void editarMetodo(int ,int column);
        void editarNivel(int row,int column);
        void editarCondicion(int row,int column);
        void editarTipoEst(int row,int column);
        void editarModalidad(int row,int column);
        void editarDiplomado(int row,int column);
        void editarCertificacion(int row,int column);
        void guardarDiplomado();
        void guardarCertificacion();
        void guardarModalidad();
        void editarMaterial(int row,int column);
        void guardarMaterial();
        void editarEvento(int row,int column);
        void guardarEvento();
        void editarHorario(int row,int column);
        void guardarHorario();
        void editarSalon(int row,int column);
        void guardarSalon();
        void editarSeccion(int row,int column);
        void editarCohorte(int row,int column);
        void editarCohorteC(int row,int column);
        //void editarCarga(int row,int column);
        //void guardarCarga();
        void editarEstudiante(int row,int column);
        void editarProfesor(int row,int column);
        void guardarProfesor();
        void editarEventoAcademico(int row,int column);
        void guardarEventoAcademico();
        void editarColEvaluacion(int row,int column);
        void actualizarColEvaluacion();
        void actualizarColEvaluacion2();
        void guardarCalendario();
        void editarCalendario();
        void actualizarCalendario2();
        void nuevoMetodo();
        void nuevoNivel();
        void nuevaCondicion();
        void nuevoTipoEst();
        void guardarMetodo();
        void guardarNivel();
        void guardarCondicion();
        void guardarTipoEst();
        void nuevoDiplomado();
        void nuevaCertificacion();
        void nuevoEvento();
        void nuevoMaterial();
        void nuevoHorario();
        void nuevaModalidad();
        void nuevoSalon();
        void nuevaSeccion();
        void nuevaCohorte();
        void nuevaCohorteC();
        //void nuevaCarga();
        void nuevoEventoAcademico();
        void nuevoCalendario();
        void actualizarModalidad();
        void actualizarMetodo();
        void actualizarNivel();
        void actualizarCondicion();
        void actualizarTipoEst();
        void actualizarDiplomados();
        void actualizarCertificacion();
        void actualizarMaterial();
        void actualizarEvento();
        void actualizarEventoAcademico();
        void actualizarCalendario();
        void actualizarCalendarioPago();
        void actualizarHorario();
        void actualizarSalon();
        //void actualizarCarga();
        void actualizarEstudiante();
        void actualizarProfesor();
        void borrarHorario();
        void borrarMetodo();
        void borrarDiplomado();
        void borrarCertificacion();
        void borrarMat();
        void borrarEvento();
        void borrarEventoAcademico();
        void borrarSeccion();
        void borrarSalon();
        void borrarModalidad();
        void borrarProfesor();
        void borrarCondicion();
        void borrarTipoEst();
        void borrarCohorte();
        void borrarCohorteC();
        void metodoChanged(QString s);
        void metodoChanged2(QString s);
        void metodoChanged3(QString s);
        void metodoChanged4(QString s);
        void metodoChanged5(QString s);
        void metodoChanged6(QString s);
        void calendarioChanged(QString s);
        void diplomadoChanged(QString s);
        void diplomadoChanged2(QString s);
        void diplomadoChanged3(QString s);
        void diplomadoChanged4(QString s);
        void diplomadoChanged5(QString s);
        void moduloChanged(QString s);
        void edificioChanged(QString s);
        void edificioChanged2(QString s);
        void salonChanged(QString s);
        void salonChanged2(QString s);
        void periodoChanged(QString s);
        void periodoChanged2(QString s);
        void cedulaChanged();
        void cedulaPagoChanged();
        void matriculaChanged();
        void matriculaPagoChanged();
        void llenarFichaAcademica(QString s);
        void llenarFichaPago(QString s);
        void guardarSeccion();
        void guardarCohorte();
        void guardarCohorteC();
        void actualizarSeccion();
        void actualizarCohorte();
        void actualizarCohorteC();
        void toUpper(QString s);
        void nivelChanged2(QString s);
        void nivelChanged3(QString s);
        void nivelChanged4(QString s);
        void seccionChanged(QString s);
        void seccionChanged2(QString s);
        void modalidadChanged(QString s);
        void modalidadChanged2(QString s);
        void modalidadChanged3(QString s);
        void modalidadChanged4(QString s);
        void modalidadChanged5(QString s);
        void descEvento(QString s);
        void generarListados();
        void generarListadoIdiomas();
        //void generarListadoDiplo();
        void imprimirFichaAcademica();
        void imprimirControlEvaluacion();
        void generarConstancias();
        void cambiarSeccion();
        void cambiarDiplo();
        void fusionarSeccion();
        void retiro_suspension();
        void llenarCambioSeccion();
        void llenarCambioDiplo();
        void diploToggled(bool checked);
        void horarioToggled(bool checked);
        void llenarCant(QString s);
        void llenarCant2(QString s);
        void llenarRetiro();
        void llenarRetiro2();
        void llenarEdificio();
        void retiroChecked(int check);
        void suspensionChecked(int check);
        void listaGraduandos();
        void llenarCalPago();
        void nuevaEmpresa();
        void registroEdificio();
        void nuevoEdificio();
        void borrarEdificio();
        void actualizarEdificio();
        void editarEdificio(int row,int column);
        void guardarEdificio();
        //void horarioDiplomado();
        //void agregarHorario();
        //void quitarHorario();
        //void llenarHorariosCFP();
        void cerrarDiplomado();
        //void horaChanged(QString s);
        //void modalidadCargaChanged(QString s);
        //void metodoCargaChanged(QString s);
        void modalidadesCalendario(int state);
        void agregarModCalendario();
        void quitarModCalendario();
        void modCalendarioChanged(QString s);
        void listadoInscritosCFP();
        void listaEvalCFP();
        void indicadores();
        void guardarModulo();
        void actualizarModulo();
        void claseChanged(QString s);
        void nuevoEventoPago();
        void guardarEventoPago();
        void editarEventoPago(int row,int column);
        void actualizarEventoPago();
        void repChecked(bool checked);
        void guardarNotaCFP();
        void guardarAsistCFP();
        void llenarModulos(QString s);
        void imprimirControlEvalCFP();
        void imprimirControlAsistCFP();
        void listadoMercadeo();
        void cohorteChanged(QString s);
        void cohorteChanged2(QString s);
        void generarSchedule();
        void programaChanged(QString s);
        void egresado_Historico();
        void cursoChanged(QString s);
        void mod_nivelChanged(QString s);
        void horarioChanged(QString s);
        void llenarNivel();

    private:
        QSqlDatabase database;
        QWidget *estudianteFrame;
        QList<QDateEdit*> *inicios;
        QList<QDateEdit*> *fines;
        QList<QDateEdit*> *inicios2;
        QList<QDateEdit*> *fines2;
        QList<QLineEdit*> *lines;
        QList<QCheckBox*> *checks;
        QList<QComboBox*> *combos;
        QList<QTimeEdit*> *times;
        QDateEdit *fecha_pago;
        QString updating;
        QString updating2;
        int actual_row;
        QString prog;
        QString prog_academico;
        bool acop;
        bool cfp;
        NCReport *report;

};
#endif /* PROCESOS_CES_H_ */

