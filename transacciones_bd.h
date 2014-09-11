#ifndef TRANSACCIONES_BD_H
#define TRANSACCIONES_BD_H
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

QSqlDatabase db;
QSqlDatabase db2;

static bool crearConexionOracle()
{
    db = QSqlDatabase();
    db = QSqlDatabase::addDatabase("QOpenOCCI");
    db.setPort(1521);

    //db.setHostName("servidor");//ingresando nombre de host
    db.setHostName("localhost");
    //db.setDatabaseName("cesdata");//ingresando nombre de base de datos
    db.setDatabaseName("ceslocal");
    db.setUserName("ces");//ingresando nombre de usuario
    db.setPassword("fundauc");//ingresando contraseña
    if (!db.open())
    {
        QMessageBox::critical(0, qApp->tr("Error"),qApp->tr("Incapaz de establecer conexión. ("+db.lastError().text()+")"), QMessageBox::Cancel);
        return false;
    }
    return true;
}

static bool crearConexionMysql()
{
    db2 = QSqlDatabase();
    db2 = QSqlDatabase::addDatabase("QMYSQL","mysql_conn");
    db2.setPort(3306);
    db2.setHostName("Aplicaciones");
    db2.setDatabaseName("sge0001");
    db2.setUserName("root");
    db2.setPassword("");
    if(!db2.open())
    {
        QMessageBox::critical(0, qApp->tr("Error"),qApp->tr("Incapaz de establecer conexión. ("+db2.lastError().text()+")"), QMessageBox::Cancel);
        return false;
    }
    return true;
}

void closeconexion(QSqlDatabase db)
{
    QString nombre = db.databaseName();
    db.close();
    QSqlDatabase::removeDatabase(nombre);
}




#endif /* TRANSACCIONES_BD_H */

