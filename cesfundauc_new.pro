#-------------------------------------------------
#
# Project created by QtCreator 2012-05-25T16:35:59
#
#-------------------------------------------------

QT       += core gui script sql xml qt3support module QtSvg

TARGET = cesfundauc_new
TEMPLATE = app


SOURCES += main.cpp \
    procesos_ces.cpp \
    procesos_caja.cpp \
    procesos_admin.cpp \
    interfaz.cpp

HEADERS  += \
    transacciones_bd.h \
    procesos_ces.h \
    procesos_caja.h \
    procesos_admin.h \
    interfaz.h

FORMS    += \
    usuarios.ui \
    usuario.ui \
    tipo_estudiante.ui \
    sesion.ui \
    secciones.ui \
    seccion.ui \
    schedule_dialog.ui \
    salones.ui \
    retiro_suspension.ui \
    registro_facturas.ui \
    registro_deposito.ui \
    prototipo.ui \
    programas.ui \
    precios.ui \
    niveles.ui \
    modalidades.ui \
    materiales.ui \
    listado_seccion.ui \
    listado_cfp.ui \
    horarios.ui \
    horario_cfp.ui \
    historico.ui \
    fusion_secciones.ui \
    ficha_pago.ui \
    ficha_academica.ui \
    factura.ui \
    eventos.ui \
    estudiantes.ui \
    estudiante.ui \
    empresas.ui \
    edificios.ui \
    diplomados.ui \
    dialog_gen.ui \
    cursos.ui \
    cuentas_cobro.ui \
    correlativos.ui \
    control_evaluacion_cfp.ui \
    cont_dialog.ui \
    condiciones.ui \
    codigos.ui \
    ces.ui \
    ced_ingreso_dialog.ui \
    carnet.ui \
    carga_academica.ui \
    cambio_seccion.ui \
    cambio_diplo.ui \
    calendarios.ui \
    calendario_cfp.ui \
    calendario.ui \
    busqueda.ui \
    bancos.ui \
    asigna_salones.ui \
    actividades_cfp.ui \
    nuevo_deposito.ui \
    control_evaluacion_2.ui \
    mercadeo.ui \
    periodo_ingreso.ui \
    empresa.ui

RESOURCES += \
    icons.qrc
INCLUDEPATH += C:\NCReport\2.8.1.mingw.eval\include
LIBS += C:\NCReport\2.8.1.mingw.eval\bin\ncreport2.dll
QMAKE_LFLAGS = -static-libgcc -static-libstdc++

OTHER_FILES += \
    prototipo.qss
