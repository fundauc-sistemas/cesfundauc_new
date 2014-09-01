/*
 * procesos_admin.h
 *
 *  Created on: 26/08/2009
 *      Author: Sistemas
 */

#ifndef PROCESOS_ADMIN_H_
#define PROCESOS_ADMIN_H_
#ifdef WIN32
# include <windows.h>
#endif


#include <QtGui>
#include <QtSql>
#include <shellapi.h>
#include "ui_usuarios.h"
#include "ui_programas.h"
#include "ui_ces.h"


class QTableWidget;
class QTextEdit;
class QMessageBox;
class QDateEdit;
class QTextEdit;
class QPushButton;

class procesos_admin : public QWidget
{
    Q_OBJECT

    public:
        procesos_admin(QWidget *parent = 0);
        ~procesos_admin();

        Ui::usuarios reg_usuarios;
        Ui::ces container;
        Ui::programa programas;

        QFrame *frame;

        void registroUsuarios();
        void registroProgramas();
        void respaldo();

    private slots:
        void nuevoUsuario();
                void llenarUsuario();
        void guardarUsuario();
                void editarUsuario(int row,int column);
        void actualizarUsuario();
                void borrarUsuario();
        void toUpper(QString s);
        void llenarProgramas();
        void nuevoPrograma();
        void guardarPrograma();
        void actualizarPrograma();
        void editarPrograma(int row,int column);
        void eliminarPrograma();

    private:
        QString updating;
        QList<QLineEdit*> *lines;
                QList<QComboBox*> *combos;

};

#endif /* PROCESOS_ADMIN_H_ */
