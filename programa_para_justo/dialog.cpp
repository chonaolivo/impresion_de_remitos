#include "dialog.h"
#include "ui_dialog.h"
#include <fstream>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QListWidget>
#include <QStringList>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);
    setWindowTitle("Operadores");
    std::ifstream archivo;
    QString qauxOpe;
    std::string auxOpe,indiceOpe;//,auxOperadores[9999];
    int cont = 1;
    archivo.open("operador.txt");
    if(archivo.fail()){
        QMessageBox::warning(this,"ERROR","Error al abrir el archivo");
    }else{
        while(std::getline(archivo,auxOpe)){
                qauxOpe = QString::fromStdString(auxOpe);
                ui->listaOperador->addItem(qauxOpe);
                cont ++;
        }
    }
    archivo.close();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_seleccionarOpera_clicked()
{
    QListWidgetItem* item = ui->listaOperador->currentItem();//Obtiene el item seleccionado
    QString QnomOpe = item->text(),QindiceOpe;
    QString qNom;

    //dividir el id y nombre
    QStringList partes = QnomOpe.split(' '); // divide la cadena en partes cada que encuentre un espacio

    ///Guardar operador
    if(partes.size() == 3 ){
        qNom =  partes[1] + " " + partes [2];
        QindiceOpe = partes[0];
    }else if(partes.size() == 4){
        //solucionar esto
        qNom = partes[1] + " " + partes [2] + " " +partes[3];
        QindiceOpe = partes[0];
    }else if(partes.size() == 5){
        qNom = partes[1] + " " + partes [2] + " " +partes[3] + " " + partes[4];
        QindiceOpe = partes[0];
    }




    std::ifstream arch;QString Qemp[9999],QindiceEmp;QStringList partesEmp;QString qIndiceEmp,qAuxemp;
    QListWidgetItem *itemEmp;// = new (QListWidget);
    QListWidget listaEmp;
    int cont = 1;
    ///Guarda empresa
    std::string emp;
    arch.open("empresa.txt");
    if(!arch.fail()){
        while(std::getline(arch,emp)){
            Qemp[cont] = QString::fromStdString(emp);
            partesEmp = Qemp[cont].split(' ');

            ///Guardo en vector cada emp pero solo nombre sin idw

            if(partesEmp.size() == 2){
                Qemp[cont] == partesEmp[1];
                qIndiceEmp = partesEmp [0];
            }else if(partesEmp.size() == 3){
                Qemp[cont] == partesEmp[1] + " " + partesEmp[2];
                qIndiceEmp = partesEmp [0];
            }else if(partesEmp.size() == 4){
                Qemp[cont] == partesEmp[1] + " " + partesEmp[2] + " " + partesEmp[3];
                qIndiceEmp = partesEmp [0];
            }
            /*if(QindiceOpe == qIndiceEmp){

            }*/

            cont++;
        }
    }
    arch.close();

    ///Guarda telefono
    QString qTel;QStringList partesTel;std::string tel;
    arch.open("telefono.txt");
    if(!arch.fail()){
        while(!arch.eof()){
            std::getline(arch,tel);
            qTel = QString::fromStdString(tel);
            partesTel = qTel.split(' ');

            QString qIndice = partesTel[0];
            if(QindiceOpe == qIndice){
                qTel = partesTel[1];
            }

        }
    }
    arch.close();

    QString qVehiculo;QStringList partesVehiculo;std::string vehiculo;
    arch.open("vehiculo.txt");
    if(!arch.fail()){
        while(!arch.eof()){
            std::getline(arch,vehiculo);
            qVehiculo = QString::fromStdString(vehiculo);
            partesVehiculo = qVehiculo.split(' ');
            if(partesVehiculo.size() == 2){
                QString qIndice = partesVehiculo[0];
                if(qIndice == QindiceOpe){
                    qVehiculo = partesVehiculo[1];
                }
            }
        }
    }
    arch.close();
    qDebug() << qIndiceEmp << "" <<QindiceOpe;
    emit enviarDatos(qNom,Qemp[1],qTel,qVehiculo);
    accept();

}
