#include "interfaz.h"
#include <QMessageBox>
#include "transacciones_bd.h"


/*! Constructor de la clase
 *
 */

interfaz::interfaz(QMainWindow *parent): QMainWindow(parent)
{
    conexion();
    sesion = new QWidget();
    dialog.setupUi(sesion);
    connect(dialog.usuario,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(dialog.password,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(dialog.password,SIGNAL(returnPressed()),this,SLOT(inicioSesion()));
    connect(dialog.box,SIGNAL(accepted()),this,SLOT(inicioSesion()));
    connect(dialog.box,SIGNAL(rejected()),this,SLOT(close()));
    setCentralWidget(sesion);
    move(300,50);
}

void interfaz::conexion()
{
    if(!crearconexion())
        close();
}

void interfaz::toUpper(QString s)
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    if (!le)
        return;
    le->setText(s.toUpper());
}


void interfaz::actionsCaja()
{
    ui.menuProcesos->clear();
    ui.menuBasicas->clear();
    ui.menuRegistros->clear();
    ui.menuReportes->clear();

    QAction *actionNueva_Factura= new QAction("Nueva Factura",this);
    QAction *actionCierre_Mensual= new QAction("Cierre Mensual",this);
    QAction *actionValija_de_Ingresos= new QAction("Valija de Ingresos",this);
    QAction *actionCuentas_por_Cobrar= new QAction("Cuentas por Cobrar",this);
    connect(actionNueva_Factura,SIGNAL(triggered()),this,SLOT(formFactura()));
    connect(actionCierre_Mensual,SIGNAL(triggered()),this,SLOT(cierreMensual()));
    connect(actionValija_de_Ingresos,SIGNAL(triggered()),this,SLOT(valija()));
    connect(actionCuentas_por_Cobrar,SIGNAL(triggered()),this,SLOT(cuentasCobro()));
    if(rol==3)
    {
        QAction *actionIngresos= new QAction("Ingresos por periodo",this);
        connect(actionIngresos,SIGNAL(triggered()),this,SLOT(ingresos()));
        ui.menuProcesos->addAction(actionIngresos);
    }
    ui.menuProcesos->addAction(actionNueva_Factura);
    ui.menuProcesos->addAction(actionCierre_Mensual);
    ui.menuProcesos->addAction(actionValija_de_Ingresos);
    ui.menuProcesos->addAction(actionCuentas_por_Cobrar);
    ui.menuProcesos->setEnabled(true);

    QAction *actionBancos= new QAction("Bancos",this);
    QAction *actionCorrelativos= new QAction("Correlativos",this);
    QAction *actionCuentasContables= new QAction("Cuentas Contables",this);
    connect(actionBancos,SIGNAL(triggered()),this,SLOT(regBancos()));
    connect(actionCuentasContables,SIGNAL(triggered()),this,SLOT(setCodigoContable()));
    ui.menuBasicas->addAction(actionBancos);
    ui.menuBasicas->addAction(actionCorrelativos);
    ui.menuBasicas->addAction(actionCuentasContables);
    ui.menuBasicas->setEnabled(true);

    QAction *actionDepositos= new QAction("Depositos",this);
    QAction *actionFacturas= new QAction("Facturas",this);
    QAction *actionPrecios= new QAction("Precios",this);
    QAction *actionEmpresas= new QAction("Empresas",this);
    connect(actionDepositos,SIGNAL(triggered()),this,SLOT(regDeposito()));
    connect(actionFacturas,SIGNAL(triggered()),this,SLOT(regFactura()));
    connect(actionPrecios,SIGNAL(triggered()),this,SLOT(regPrecios()));
    connect(actionEmpresas,SIGNAL(triggered()),this,SLOT(regEmpresas()));
    ui.menuRegistros->addAction(actionDepositos);
    ui.menuRegistros->addAction(actionFacturas);
    ui.menuRegistros->addAction(actionPrecios);
    ui.menuRegistros->addAction(actionEmpresas);
    ui.menuRegistros->setEnabled(true);

    QAction *actionCierre_Diario= new QAction("Cierre Diario",this);
    QAction *actionCedula_de_Ingresos= new QAction("Cedula de Ingresos",this);
    QAction *actionCierre_Comercializables= new QAction("Cierre Comercializables",this);
    connect(actionCierre_Diario,SIGNAL(triggered()),this,SLOT(cuadreDiario()));
    connect(actionCedula_de_Ingresos,SIGNAL(triggered()),this,SLOT(cedulaMensual()));
    connect(actionCierre_Comercializables,SIGNAL(triggered()),this,SLOT(comercializables()));
    ui.menuReportes->addAction(actionCierre_Diario);
    ui.menuReportes->addAction(actionCedula_de_Ingresos);
    ui.menuReportes->addAction(actionCierre_Comercializables);
    ui.menuReportes->setEnabled(true);


}


void interfaz::actionsCtrlEst()
{
    ui.menuProcesos->clear();
    ui.menuBasicas->clear();
    ui.menuRegistros->clear();
    ui.menuReportes->clear();

    QAction *actionFicha_Academica= new QAction("Ficha Academica",this);
    QAction *actionCrear_Carnet=new QAction("Crear Carnet",this);
    QAction *actionHistorico= new QAction("Egresados a Historico",this);
    QAction *actionRetiro_Suspension= new QAction("Retiro/Suspension",this);
    connect(actionFicha_Academica,SIGNAL(triggered()),this,SLOT(fichaAcademica()));
    connect(actionCrear_Carnet,SIGNAL(triggered()),this,SLOT(crearCarnet()));
    connect(actionHistorico,SIGNAL(triggered()),this,SLOT(historico()));
    connect(actionRetiro_Suspension,SIGNAL(triggered()),this,SLOT(setRetiro()));
    ui.menuProcesos->addAction(actionFicha_Academica);
    ui.menuProcesos->addAction(actionCrear_Carnet);
    ui.menuProcesos->addAction(actionHistorico);
    ui.menuProcesos->addAction(actionRetiro_Suspension);

    QAction *actionLibros_y_Materiales= new QAction("Libros y Materiales",this);
    QAction *actionTipoEst= new QAction("Tipo Estudiante",this);
    QAction *actionCondiciones= new QAction("Condiciones Especiales",this);
    QAction *actionSalones= new QAction("Salones",this);
    QAction *actionEventos= new QAction("Eventos",this);
    connect(actionLibros_y_Materiales,SIGNAL(triggered()),this,SLOT(regMateriales()));
    connect(actionTipoEst,SIGNAL(triggered()),this,SLOT(regTipoEst()));
    connect(actionCondiciones,SIGNAL(triggered()),this,SLOT(regCondiciones()));
    connect(actionSalones,SIGNAL(triggered()),this,SLOT(regSalones()));
    connect(actionEventos,SIGNAL(triggered()),this,SLOT(regEventos()));
    ui.menuBasicas->addAction(actionLibros_y_Materiales);
    ui.menuBasicas->addAction(actionTipoEst);
    ui.menuBasicas->addAction(actionCondiciones);
    ui.menuBasicas->addAction(actionSalones);
    ui.menuBasicas->addAction(actionEventos);

    QAction *actionEstudiantes= new QAction("Estudiantes",this);
    QAction *actionProfesores= new QAction("Profesores",this);
    QAction *actionHorarios= new QAction("Horarios",this);
    QAction *actionModalidad= new QAction("Modalidades",this);
    QAction *actionCalendario= new QAction("Calendario",this);
    connect(actionProfesores,SIGNAL(triggered()),this,SLOT(regProfesor()));
    connect(actionEstudiantes,SIGNAL(triggered()),this,SLOT(regEstudiante()));
    connect(actionHorarios,SIGNAL(triggered()),this,SLOT(regHorarios()));
    connect(actionModalidad,SIGNAL(triggered()),this,SLOT(regModalidades()));
    ui.menuRegistros->addAction(actionEstudiantes);
    ui.menuRegistros->addAction(actionProfesores);
    ui.menuRegistros->addAction(actionHorarios);
    ui.menuRegistros->addAction(actionModalidad);
    ui.menuRegistros->addAction(actionCalendario);

    QMenu *menuEstadisticas= new QMenu("Estadisticas",this);
    QMenu *menuConstancias= new QMenu("Constancias",this);
    QAction *actionCon_notas2= new QAction("Culminacion con notas",menuConstancias);
    QAction *actionSin_notas= new QAction("Estudios",menuConstancias);
    QAction *actionSin_notas2= new QAction("Culminacion",menuConstancias);
    connect(actionCon_notas2,SIGNAL(triggered()),this,SLOT(consAproNota()));
    connect(actionSin_notas,SIGNAL(triggered()),this,SLOT(consEstSinNota()));
    connect(actionSin_notas2,SIGNAL(triggered()),this,SLOT(consAproSinNota()));
    menuConstancias->addAction(actionSin_notas2);
    menuConstancias->addAction(actionCon_notas2);
    menuConstancias->addAction(actionSin_notas);

    QMenu *menuListados= new QMenu("Listados",this);
    QAction *actionProfesores2= new QAction("Profesores",menuListados);
    QAction *actionCursos2= new QAction("Cursos",menuListados);
    QAction *actionPrecios2= new QAction("Precios",menuListados);
    QAction *actionGraduandos= new QAction("Graduandos",menuListados);
    QAction *actionAulas= new QAction("Aulas",menuListados);
    QAction *actionAlumnos= new QAction("Participantes",menuListados);
    QAction *actionAlumnos2= new QAction("Participantes (txt)",menuListados);
    connect(actionProfesores2,SIGNAL(triggered()),this,SLOT(listadoProfesores()));
    connect(actionPrecios2,SIGNAL(triggered()),this,SLOT(listadoPrecios()));
    connect(actionAlumnos2,SIGNAL(triggered()),this,SLOT(listadoAlumnos()));
    //menuListados->addAction(actionProfesores2);
    menuListados->addAction(actionCursos2);
    menuListados->addAction(actionPrecios2);
    menuListados->addAction(actionGraduandos);
    menuListados->addAction(actionAlumnos2);

    if(programa_academico=="3")
    {
        QAction *actionCambio_de_Diplo= new QAction("Cambio de Diplomado",this);
        QAction *actionControl_de_Asistencia= new QAction("Control de Asistencia",this);
        QAction *actionControl_de_Evaluacion= new QAction("Control de Evaluacion",this);
        QAction *actionFicha_Pago_CFP= new QAction("Ficha de Pago CFP",this);
        connect(actionCambio_de_Diplo,SIGNAL(triggered()),this,SLOT(setCambioDiplomado()));
        connect(actionControl_de_Asistencia,SIGNAL(triggered()),this,SLOT(controlAsistenciaCFP()));
        connect(actionControl_de_Evaluacion,SIGNAL(triggered()),this,SLOT(controlEvaluacionCFP()));
        connect(actionFicha_Pago_CFP,SIGNAL(triggered()),this,SLOT(fichaPagoCFP()));
        ui.menuProcesos->addAction(actionCambio_de_Diplo);
        ui.menuProcesos->addAction(actionControl_de_Asistencia);
        ui.menuProcesos->addAction(actionControl_de_Evaluacion);
        ui.menuProcesos->addAction(actionFicha_Pago_CFP);

        QAction *actionModulos= new QAction("Modulos Diplomados",this);
        connect(actionModulos,SIGNAL(triggered()),this,SLOT(regModulos()));
        connect(actionCalendario,SIGNAL(triggered()),this,SLOT(regCal2()));
        ui.menuRegistros->addAction(actionModulos);

        QAction *actionDiplomados1= new QAction("Participantes Diplomados (Contacto)",menuListados);//Cambiar nombre
        QAction *actionDiplomados2= new QAction("Participantes Diplomados",menuListados);//Cambiar nombre
        QAction *actionDiplomados3= new QAction("Lista de Asistencia (formato)",menuListados);
        QAction *actionDiplomados4= new QAction("Control de Evaluacion (formato)",menuListados);
        QAction *actionDiplomados5= new QAction("Graduandos No Solventes",menuListados);
        QAction *actionResumen_Inscritos= new QAction("Resumen de Inscritos/Preinscritos",menuListados);
        actionCursos2->setText("Diplomados y Talleres");
        connect(actionDiplomados1,SIGNAL(triggered()),this,SLOT(contactoCFP()));
        connect(actionDiplomados2,SIGNAL(triggered()),this,SLOT(participantesCFP()));
        connect(actionDiplomados3,SIGNAL(triggered()),this,SLOT(asistenciaCFP()));
        connect(actionDiplomados4,SIGNAL(triggered()),this,SLOT(evaluacionCFP()));
        connect(actionResumen_Inscritos,SIGNAL(triggered()),this,SLOT(inscritosCFP()));
        connect(actionGraduandos,SIGNAL(triggered()),this,SLOT(graduandosCFP()));
        connect(actionDiplomados5,SIGNAL(triggered()),this,SLOT(morososCFP()));
        connect(actionCursos2,SIGNAL(triggered()),this,SLOT(listadoDiplos()));
        menuListados->addAction(actionDiplomados5);
        menuListados->addAction(actionDiplomados2);
        menuListados->addAction(actionDiplomados3);
        menuListados->addAction(actionDiplomados4);
        menuListados->addAction(actionDiplomados1);
        menuListados->addAction(actionResumen_Inscritos);
        menuEstadisticas->addAction(actionResumen_Inscritos);

        if(rol==3)
        {
            QAction *actionDiplomados= new QAction("Diplomados",this);
            QAction *actionCertificacion= new QAction("Programas de Certificacion",this);
            QAction *actionCohortesD= new QAction("Diplomados",this);
            QAction *actionCohortesC= new QAction("Programas de Certificacion",this);
            QMenu *menuCohortes = new QMenu("Cohortes",this);
            connect(actionDiplomados,SIGNAL(triggered()),this,SLOT(regDiplo()));
            connect(actionCohortesD,SIGNAL(triggered()),this,SLOT(regCohortes()));
            connect(actionCertificacion,SIGNAL(triggered()),this,SLOT(regCerti()));
            connect(actionCohortesC,SIGNAL(triggered()),this,SLOT(regCohortesC()));
            ui.menuRegistros->addAction(actionDiplomados);
            ui.menuRegistros->addAction(actionCertificacion);
            menuCohortes->addAction(actionCohortesD);
            menuCohortes->addAction(actionCohortesC);
            ui.menuRegistros->addMenu(menuCohortes);

        }
    }
    else//(programa_academico==1 ó 2)
    {
        QAction *actionControl_de_Evaluacion= new QAction("Control de Evaluacion",this);
        connect(actionControl_de_Evaluacion,SIGNAL(triggered()),this,SLOT(controlEvaluacion()));
        ui.menuProcesos->addAction(actionControl_de_Evaluacion);

        QAction *actionCambio_de_Seccion= new QAction("Cambio de Seccion",this);
        QAction *actionCambio_de_Metodo= new QAction("Cambio de Metodologia",this);
        QAction *actionFusion_de_Secciones= new QAction("Fusion de Secciones",this);
        //QAction *actionRetiro_Suspension= new QAction("Retiro/Suspension",this);
        QAction *actionCarga_Academica= new QAction("Carga Academica",this);
        QAction *actionFicha_Pago= new QAction("Ficha de Pago",this);
        connect(actionCarga_Academica,SIGNAL(triggered()),this,SLOT(cargaAcademica()));
        connect(actionFicha_Pago,SIGNAL(triggered()),this,SLOT(fichaPago()));
        connect(actionCambio_de_Seccion,SIGNAL(triggered()),this,SLOT(setCambioSeccion()));
        connect(actionCambio_de_Metodo,SIGNAL(triggered()),this,SLOT(setCambioMetodo()));
        connect(actionFusion_de_Secciones,SIGNAL(triggered()),this,SLOT(setFusionSeccion()));
        //connect(actionRetiro_Suspension,SIGNAL(triggered()),this,SLOT(setRetiro()));

        ui.menuProcesos->addAction(actionCambio_de_Seccion);
        ui.menuProcesos->addAction(actionCambio_de_Metodo);
        ui.menuProcesos->addAction(actionFusion_de_Secciones);
        //ui.menuProcesos->addAction(actionRetiro_Suspension);
        ui.menuProcesos->addAction(actionCarga_Academica);
        ui.menuProcesos->addAction(actionFicha_Pago);

        //QAction *actionIdiomas= new QAction("Idiomas y Computacion",menuCalendarios);
        QAction *actionSecciones= new QAction("Secciones",this);
        QAction *actionMetodos= new QAction("Metodos y Cursos",this);
        QAction *actionNiveles= new QAction("Niveles",this);
        connect(actionCalendario,SIGNAL(triggered()),this,SLOT(regCal()));
        connect(actionSecciones,SIGNAL(triggered()),this,SLOT(regSecciones()));
        connect(actionMetodos,SIGNAL(triggered()),this,SLOT(regCurso()));
        connect(actionNiveles,SIGNAL(triggered()),this,SLOT(regNivel()));
        ui.menuRegistros->addAction(actionSecciones);
        //menuCalendarios->addAction(actionIdiomas);
        ui.menuRegistros->addAction(actionMetodos);
        ui.menuRegistros->addAction(actionNiveles);

        QAction *actionIdiomas2= new QAction("Control de Evaluacion (formato)",menuListados);
        QAction *actionIdiomas3= new QAction("Control de Asistencia (formato)",menuListados);
        QAction *actionIdiomas1= new QAction("Alumnos por Seccion",menuListados);
        QAction *actionSecciones2= new QAction("Secciones",menuListados);
        QAction *actionBookA= new QAction("Schedule and Book Assignment",ui.menuReportes);
        connect(actionIdiomas2,SIGNAL(triggered()),this,SLOT(listadoIdiomas()));
        connect(actionIdiomas3,SIGNAL(triggered()),this,SLOT(listadoIdiomas2()));
        connect(actionIdiomas1,SIGNAL(triggered()),this,SLOT(listadoIdiomas3()));
        connect(actionSecciones2,SIGNAL(triggered()),this,SLOT(listadoSecciones()));
        connect(actionGraduandos,SIGNAL(triggered()),this,SLOT(listadoGraduandos()));
        connect(actionBookA,SIGNAL(triggered()),this,SLOT(listadoBookA()));
        connect(actionCursos2,SIGNAL(triggered()),this,SLOT(listadoCursos()));
        menuListados->addAction(actionIdiomas1);
        menuListados->addAction(actionIdiomas2);
        menuListados->addAction(actionIdiomas3);
        menuListados->addAction(actionSecciones2);
        ui.menuReportes->addAction(actionBookA);

        QAction *actionCon_notas= new QAction("Estudios con notas",menuConstancias);
        QAction *actionActo_de_Grado= new QAction("Acto de Grado",menuConstancias);
        //QAction *actionBeca_Trabajo= new QAction("Beca Trabajo",menuConstancias);
        QAction *actionCon_notas_en_ingles= new QAction("Estudios con notas (Ingles)",menuConstancias);
        QAction *actionCon_notas_en_ingles2= new QAction("Culminacion con notas (Ingles)",menuConstancias);
        QAction *actionSin_notas_en_ingles= new QAction("Estudios (Ingles)",menuConstancias);
        QAction *actionSin_notas_en_ingles2= new QAction("Culminacion sin notas (Ingles)",menuConstancias);
        QAction *actionInicio_de_Curso= new QAction("Inicio de Curso",menuConstancias);
        connect(actionCon_notas,SIGNAL(triggered()),this,SLOT(consEstNota()));
        connect(actionSin_notas_en_ingles,SIGNAL(triggered()),this,SLOT(consEstIngSinNota()));
        connect(actionActo_de_Grado,SIGNAL(triggered()),this,SLOT(consActoGrado()));
        //connect(actionBeca_Trabajo,SIGNAL(triggered()),this,SLOT(consBecaTrabajo()));
        connect(actionCon_notas_en_ingles,SIGNAL(triggered()),this,SLOT(consEstIngNota()));
        connect(actionCon_notas_en_ingles2,SIGNAL(triggered()),this,SLOT(consAproIngNota()));
        connect(actionInicio_de_Curso,SIGNAL(triggered()),this,SLOT(consInicio()));
        connect(actionSin_notas_en_ingles2,SIGNAL(triggered()),this,SLOT(consAproIngSinNota()));
        menuConstancias->addAction(actionCon_notas);
        menuConstancias->addAction(actionSin_notas_en_ingles);
        menuConstancias->addAction(actionCon_notas_en_ingles);
        menuConstancias->addAction(actionCon_notas_en_ingles2);
        menuConstancias->addAction(actionSin_notas_en_ingles2);
        menuConstancias->addAction(actionInicio_de_Curso);
        //menuConstancias->addAction(actionBeca_Trabajo);
        menuConstancias->addAction(actionActo_de_Grado);
    }
    ui.menuProcesos->setEnabled(true);
    ui.menuBasicas->setEnabled(true);
    ui.menuRegistros->setEnabled(true);
    ui.menuReportes->addMenu(menuConstancias);
    ui.menuReportes->addMenu(menuListados);
    ui.menuReportes->addMenu(menuEstadisticas);
    ui.menuReportes->setEnabled(true);
}


void interfaz::actionsAdmin()
{
    ui.menuProcesos->clear();
    ui.menuRegistros->clear();
    ui.menuReportes->clear();
    ui.menuReportes->setEnabled(false);
    QAction *actionUsuario= new QAction("Usuarios",this);
    QAction *actionPrograma= new QAction("Programas",this);
    QAction *actionRespaldo= new QAction("Respaldo",this);

    ui.menuProcesos->addAction(actionRespaldo);
    ui.menuProcesos->setEnabled(true);
    ui.menuRegistros->addAction(actionUsuario);
    ui.menuRegistros->addAction(actionPrograma);
    ui.menuRegistros->setEnabled(true);
    connect(actionUsuario,SIGNAL(triggered()),this,SLOT(regUsuarios()));
    connect(actionPrograma,SIGNAL(triggered()),this,SLOT(regProgramas()));
    connect(actionRespaldo,SIGNAL(triggered()),this,SLOT(respaldo()));
}

void interfaz::actionsMercadeo()
{
    ui.menuProcesos->clear();
    ui.menuRegistros->clear();
    ui.menuReportes->clear();
    ui.menuRegistros->setEnabled(false);
    ui.menuReportes->setEnabled(false);
    QMenu *menuExportar= new QMenu("Exportar Estudiantes",this);
    QAction *actionIdiomas= new QAction("Idiomas",menuExportar);
    QAction *actionCfp= new QAction("Diplomados",this);
    menuExportar->addAction(actionIdiomas);
    menuExportar->addAction(actionCfp);
    ui.menuProcesos->addMenu(menuExportar);
    ui.menuProcesos->setEnabled(true);
    connect(actionIdiomas,SIGNAL(triggered()),this,SLOT(regMercadeo1()));
    connect(actionCfp,SIGNAL(triggered()),this,SLOT(regMercadeo2()));

}

void interfaz::crearActions()
{
    connect(ui.actionCaja,SIGNAL(triggered()),this,SLOT(actionsCaja()));
    connect(ui.actionControl_de_Estudios,SIGNAL(triggered()),this,SLOT(actionsCtrlEst()));
    connect(ui.actionAdministracion,SIGNAL(triggered()),this,SLOT(actionsAdmin()));
    connect(ui.actionMercadeo,SIGNAL(triggered()),this,SLOT(actionsMercadeo()));
    connect(ui.actionSalir_2,SIGNAL(triggered()),this,SLOT(cerrar()));
    connect(ui.actionCambio_de_Usuario,SIGNAL(triggered()),this,SLOT(cierreSesion()));
    connect(ui.actionUsuario_2,SIGNAL(triggered()),this,SLOT(adminUsuario()));
}

void interfaz::cerrar()
{
    closeconexion();
    close();
}


void interfaz::adminUsuario()
{
    QSqlQuery consulta;
    sesion = new QWidget();
    user_dialog.setupUi(sesion);
    sesion->show();

    user_dialog.username->setText(username);
    user_dialog.nombre->setText(nombre);

    consulta.exec("select cedula,email,contrasena from usuarios where nombre_usuario='"+username+"'");
    while(consulta.next())
    {
        user_dialog.cedula->setText(consulta.value(0).toString());
        user_dialog.email->setText(consulta.value(1).toString());
        user_dialog.passwd->setText(consulta.value(2).toString());
    }
    connect(user_dialog.guardar,SIGNAL(clicked()),this,SLOT(actualizarUsuario()));
}

void interfaz::actualizarUsuario()
{
    QSqlQuery consulta;
    if(!consulta.exec("update usuarios set nombre_usuario='"+user_dialog.username->text()+"', contrasena='"+user_dialog.passwd->text()+"' where cedula='"+user_dialog.cedula->text()+"'"))
        QMessageBox::critical(0,"Error",consulta.lastError().text());
    else
    {
        consulta.exec("commit");
        sesion->close();
    }

}

void interfaz::cierreSesion()
{
    ui.menuMacros->setEnabled(false);
    ui.menuModulos->setEnabled(false);
    sesion = new QWidget();
    dialog.setupUi(sesion);
    sesion->setWindowModality(Qt::WindowModal);
    connect(dialog.usuario,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(dialog.password,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));
    connect(dialog.password,SIGNAL(returnPressed()),this,SLOT(inicioSesion()));
    connect(dialog.box,SIGNAL(accepted()),this,SLOT(inicioSesion()));
    connect(dialog.box,SIGNAL(rejected()),this,SLOT(cerrar()));
    sesion->show();
}

void interfaz::inicioSesion()
{
    QString usuario,password,compania;
    QSqlQuery consulta;
    bool user=false;
    usuario = dialog.usuario->text();
    password = dialog.password->text();

    if(usuario.isEmpty()||password.isEmpty())
    {
        QMessageBox::information(0,"Error","Ambos campos deben estar llenos");
    }
    else
    {
        consulta.exec("select cia,id_rol,nombre,prog_academico from usuarios where nombre_usuario='"+usuario+"' and contrasena='"+password+"'");
        while(consulta.next())
        {
            programa=consulta.value(0).toString();
            rol= consulta.value(1).toInt();
            nombre=consulta.value(2).toString();
            username=usuario;
            programa_academico=consulta.value(3).toString();
            user=true;
        }
        if(user==false)
        {
            QMessageBox::information(0,"Error","Nombre de Usuario o Contraseña Incorrectos");
        }
        else
        {
            ui.setupUi(this);
            showMaximized();

            consulta.exec("select descripcion from companias where id='"+programa+"'");
            while(consulta.next())
            {
                compania=consulta.value(0).toString();
            }
            switch(rol)
            {
                case 0:
                    ui.actionAdministracion->setEnabled(true);
                break;
                case 1:
                    ui.actionCaja->setEnabled(true);
                break;
                case 2:
                    ui.actionControl_de_Estudios->setEnabled(true);
                    ui.actionCaja->setEnabled(true);
                break;
                case 3:
                    ui.actionCaja->setEnabled(true);
                    ui.actionControl_de_Estudios->setEnabled(true);
                    ui.actionAdministracion->setEnabled(true);
                break;
                case 4:
                    ui.actionControl_de_Estudios->setEnabled(true);
                    consulta.exec("select cedula from usuarios where nombre_usuario='"+usuario+"' and contrasena='"+password+"'");
                    while(consulta.next())
                    {
                        cedula=consulta.value(0).toString();
                    }
                break;
                case 5:
                    ui.actionMercadeo->setEnabled(true);
                break;
            }
            crearActions();
            sesion->close();
        }
    }
}

void interfaz::formFactura()
{
    caja = new procesos_caja(programa,username,db,this);
    ui.frame->setWidget(caja);
    caja->nuevaFactura();
    disconnect(ui.actionImprimir,SIGNAL(triggered()),0,0);
    connect(ui.actionImprimir,SIGNAL(triggered()),caja,SLOT(imprimirFactura()));
}


void interfaz::regFactura()
{
    caja = new procesos_caja(programa,username,db,this);
    ui.frame->setWidget(caja);
    caja->registroFacturas();
    disconnect(ui.actionImprimir,SIGNAL(triggered()),0,0);
    connect(ui.actionImprimir,SIGNAL(triggered()),caja,SLOT(cierreFacturas()));

}

void interfaz::regDeposito()
{
    caja = new procesos_caja(programa,username,db,this);
    ui.frame->setWidget(caja);
    caja->registroDepositos();
    disconnect(ui.actionImprimir,SIGNAL(triggered()),0,0);
    connect(ui.actionImprimir,SIGNAL(triggered()),caja,SLOT(cierreDepositos()));
}

void interfaz::regBancos()
{
    caja = new procesos_caja(programa,username,db,this);
    ui.frame->setWidget(caja);
    caja->registroBancos();
}

void interfaz::regPrecios()
{
    caja = new procesos_caja(programa,username,db,this);
    ui.frame->setWidget(caja);
    caja->registroPrecios();
}

void interfaz::regEmpresas()
{
    caja = new procesos_caja(programa,username,db,this);
    ui.frame->setWidget(caja);
    caja->registroEmpresas();
}

void interfaz::valija()
{
    caja = new procesos_caja(programa,username,db,this);
    //ui.frame->setWidget(caja);
    caja->mesValija();
}

void interfaz::ingresos()
{
    caja = new procesos_caja(programa,username,db,this);
    caja->ingresosPeriodo();
}

void interfaz::cuadreDiario()
{
    caja = new procesos_caja(programa,username,db,this);
    caja->setupCierre();
}

void interfaz::cedulaMensual()
{
    caja = new procesos_caja(programa,username,db,this);
    caja->setupCedula();
}


void interfaz::cierreMensual()
{
    caja = new procesos_caja(programa,username,db,this);
    caja->cierreMensual();
}

void interfaz::comercializables()
{
    caja = new procesos_caja(programa,username,db,this);
    caja->setupComercializables();
}

void interfaz::cuentasCobro()
{
    caja= new procesos_caja(programa,username,db,this);
    ui.frame->setWidget(caja);
    caja->cuentasPorCobrar();
}

void interfaz::setCodigoContable()
{
    caja= new procesos_caja(programa,username,db,this);
    ui.frame->setWidget(caja);
    caja->registroCodigos();
}


void interfaz::crearCarnet() //Está en la clase caja, pero se accede desde el modulo de control de estudios. Arreglar
{
    caja = new procesos_caja(programa,username,db,this);
    ui.frame->setWidget(caja);
    caja->crearCarnet();
}


void interfaz::regEstudiante()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->registroEstudiantes2();

}

void interfaz::regProfesor()
{
        ces = new procesos_ces(programa,programa_academico,db,this);
        ui.frame->setWidget(ces);
        ces->registroProfesores();
}

void interfaz::regCurso()
{
        ces = new procesos_ces(programa,programa_academico,db,this);
        ui.frame->setWidget(ces);
        ces->registroMetodos();
}

void interfaz::regNivel()
{
        ces = new procesos_ces(programa,programa_academico,db,this);
        ui.frame->setWidget(ces);
        ces->registroNiveles();
}


void interfaz::regMateriales()
{
        ces = new procesos_ces(programa,programa_academico,db,this);
        ui.frame->setWidget(ces);
        ces->registroMat();
}

void interfaz::regTipoEst()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->registroTipoEst();
}

void interfaz::regCondiciones()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->registroCondiciones();
}

void interfaz::regEventos()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->registroEventos();
}

void interfaz::regCal()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->registroCalendario();
}

void interfaz::regCal2()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->registroCalendarioPago();
}


void interfaz::regSalones()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->registroSalones();
}

void interfaz::regSecciones()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->registroSecciones();
}

void interfaz::regDiplo()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->registroDiplomados();
}

void interfaz::regCerti()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->registroCertificacion();
}

void interfaz::regModulos()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->registroModulos();
}

void interfaz::regCohortes()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->registroCohortes();
}

void interfaz::regCohortesC()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->registroCohortesCerti();
}

void interfaz::regHorarios()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->registroHorarios();
}

void interfaz::regModalidades()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->registroModalidades();
}

void interfaz::fichaAcademica()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setFichaAcademica();
}

void interfaz::fichaPago()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setFichaPago();
}

void interfaz::fichaPagoCFP()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setFichaPagoCFP();
}

void interfaz::controlEvaluacion()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setControlEvaluacion();
}

void interfaz::controlEvaluacionCFP()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setControlEvalCFP();
}

void interfaz::controlAsistenciaCFP()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setControlAsistCFP();
}

void interfaz::cargaAcademica()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    //ces->setCargaAcademica();
}


void interfaz::listadoCursos()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setListados(1);
}

void interfaz::listadoDiplos()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setListados(2);
}

void interfaz::listadoIdiomas()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setListadoIdiomas(1);
}

void interfaz::listadoIdiomas2()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setListadoIdiomas(2);
}

void interfaz::listadoIdiomas3()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setListadoIdiomas(3);
}


void interfaz::listadoGraduandos()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setGraduandos();
}

void interfaz::listadoBookA()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ces->setSchedule();
}

void interfaz::historico()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setHistorico();
}

void interfaz::inscritosCFP()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ces->setListadoInscritos();
}

void interfaz::asistenciaCFP()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setListadosCFP(2);
}

void interfaz::evaluacionCFP()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setListadosCFP(1);
}

void interfaz::participantesCFP()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setListadosCFP(3);
}

void interfaz::contactoCFP()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setListadosCFP(6);
}

void interfaz::graduandosCFP()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setListadosCFP(4);
}

void interfaz::morososCFP()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setListadosCFP(5);
}

void interfaz::listadoProfesores()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setListadosCFP(6);
}

void interfaz::regUsuarios()
{
    admin = new procesos_admin(this);
    ui.frame->setWidget(admin);
    admin->registroUsuarios();
}


void interfaz::respaldo()
{
    admin = new procesos_admin(this);
    admin->respaldo();
}

void interfaz::regProgramas()
{
    admin = new procesos_admin(this);
    ui.frame->setWidget(admin);
    admin->registroProgramas();
}

void interfaz::consActoGrado()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ces->constancias(0);
}

void interfaz::consBecaTrabajo()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ces->constancias(1);
}

void interfaz::consEstNota()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ces->constancias(2);
}

void interfaz::consAproNota()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ces->constancias(3);
}

void interfaz::consEstIngNota()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ces->constancias(4);
}

void interfaz::consAproIngNota()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ces->constancias(5);
}

void interfaz::consInicio()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ces->constancias(6);
}

void interfaz::consEstSinNota()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ces->constancias(7);
}

void interfaz::consAproSinNota()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ces->constancias(8);
}

void interfaz::consEstIngSinNota()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ces->constancias(9);
}

void interfaz::consAproIngSinNota()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ces->constancias(10);
}

void interfaz::setCambioSeccion()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setCambioSeccion();
}

void interfaz::setCambioMetodo()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setCambioMetodo();
}

void interfaz::setCambioDiplomado()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setCambioDiplo();
}

void interfaz::setFusionSeccion()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setFusionSeccion();
}

void interfaz::setRetiro()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setRetiro();
}

void interfaz::listadoAlumnos()
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ces->setMercadeo(1);
}

void interfaz::regMercadeo1()//Idiomas
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setMercadeo(2);
}

void interfaz::regMercadeo2()//Diplomados
{
    ces = new procesos_ces(programa,programa_academico,db,this);
    ui.frame->setWidget(ces);
    ces->setMercadeo(3);
}


interfaz::~interfaz()
{

}


