#include "interfaz.h"

#include <QtGui>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Carga el estilo de la aplicaci�n
    QFile styleFile( "prototipo.qss" );
    QIcon icono( "iconos/esfera48.png" );
    styleFile.open( QFile::ReadOnly );

    // Aplica el estilo
    a.setStyleSheet(styleFile.readAll());

    //Crea la aplicaci�n
    interfaz w;
    w.setWindowTitle("FUNDAUC");
    w.setWindowIcon(icono);
    w.show();
    return a.exec();
}
