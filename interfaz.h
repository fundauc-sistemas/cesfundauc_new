#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QtGui>
#include <QtSql>
#include <QInputDialog>

#include "ui_prototipo.h"
#include "procesos_caja.h"
#include "procesos_ces.h"
#include "procesos_admin.h"
#include "ui_sesion.h"
#include "ui_usuario.h"

class interfaz : public QMainWindow
{
    Q_OBJECT

 public:
    interfaz(QMainWindow *parent = 0);
    ~interfaz();

 private:
    Ui::prototipoClass ui;
    Ui::sesion dialog;
    Ui::usuario user_dialog;

    QWorkspace *space;
    QWidget *sesion;

    char user;
    QString programa,nombre,username,cedula;
    QString programa_academico;
    int rol;
    procesos_caja *caja;
    procesos_ces *ces;
    procesos_admin *admin;
    QFont f;

    void conexion();
    void crearActions();


 private slots:
    void adminUsuario();
    void cerrar();
    void actionsCaja();
    void actionsCtrlEst();
    void actionsAdmin();
    void actionsMercadeo();
    void inicioSesion();
    void cierreSesion();
    void formFactura();
    void crearCarnet();
    void regFactura();
    void regDeposito();
    void valija();
    void ingresos();
    void regEstudiante();
    void regProfesor();
    void regCurso();
    void regNivel();
    void regDiplo();
    void regCerti();
    void regModulos();
    void regMateriales();
    void regPrecios();
    void regEmpresas();
    void regCondiciones();
    void regTipoEst();
    void regEventos();
    void regHorarios();
    void regModalidades();
    void regBancos();
    void regCal();
    void regCal2();
    void regSalones();
    void regSecciones();
    void regCohortes();
    void regCohortesC();
    void fichaAcademica();
    void fichaPago();
    void fichaPagoCFP();
    void controlEvaluacion();
    void controlEvaluacionCFP();
    void controlAsistenciaCFP();
    void cargaAcademica();
    void listadoIdiomas();
    void listadoIdiomas2();
    void listadoIdiomas3();
    void listadoGraduandos();
    void listadoProfesores();
    void listadoCursos();
    void listadoDiplos();
    void regUsuarios();
    void toUpper(QString s);
    void respaldo();
    void regProgramas();
    void consActoGrado();
    void consBecaTrabajo();
    void consEstNota();
    void consAproNota();
    void consEstIngNota();
    void consAproIngNota();
    void consInicio();
    void consEstSinNota();
    void consAproSinNota();
    void consEstIngSinNota();
    void consAproIngSinNota();
    void setCambioSeccion();
    void setCambioMetodo();
    void setCambioDiplomado();
    void setFusionSeccion();
    void setRetiro();
    void cuadreDiario();
    void cedulaMensual();
    void cierreMensual();
    void comercializables();
    void cuentasCobro();
    void inscritosCFP();
    void asistenciaCFP();
    void evaluacionCFP();
    void participantesCFP();
    void graduandosCFP();
    void morososCFP();
    void contactoCFP();
    void setCodigoContable();
    void listadoAlumnos();
    void listadoBookA();
    void historico();
    void actualizarUsuario();
    void regMercadeo1();
    void regMercadeo2();
};

#endif // INTERFAZ_H

