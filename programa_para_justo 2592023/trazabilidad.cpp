#include "trazabilidad.h"
#include "ui_trazabilidad.h"
#include <fstream>
#include <iostream>
#include <string>
trazabilidad::trazabilidad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trazabilidad)
{
    ui->setupUi(this);
    std::ifstream archi;
    std::string basura,palabra,vectorpalabra[99];
    QString Qpalabra;
    int cont=0,aux=0;
    for(int i=0;i<11;i++){
        ui->tabla->insertColumn(i);
    }
    QStringList headers; // Lista de nombres/títulos de las columnas
    headers << "operador" << "Marca" << "Km" << "patente" << "Color" << "modelo" << "Ingreso" << "Salida" << "Tipo" << "Nota" << "Usado";
    // Establece los nombres/títulos de las columnas
    ui->tabla->setHorizontalHeaderLabels(headers);
    archi.open("operador.txt");
    if(archi.fail()){
        std::cout<<"fallo al abrir el archivo operador"<<std::endl;
    }
    else{
        while(std::getline(archi,palabra)){

            ui->tabla->insertRow(cont);
            aux=palabra.size();
            aux-=1;
            palabra=palabra.substr(1,aux);
            Qpalabra=QString::fromStdString(palabra);

            ui->tabla->setItem(cont,0,new QTableWidgetItem(Qpalabra));
            cont++;
        }
    }
    archi.close();
    aux=cont;
    cont=0;
    archi.open("ingreso-salida.txt");
    if(archi.fail()){
        std::cout<<"fallo al abrir el archivo ingreso-salida"<<std::endl;
    }
    else{
        while(cont<aux){
            std::getline(archi,basura,' ');
            for(int i=1;i<8;i++){
                std::getline(archi,palabra,' ');
                Qpalabra=QString::fromStdString(palabra);
                ui->tabla->setItem(cont,i,new QTableWidgetItem(Qpalabra));
            }

            cont++;
        }
    }
    archi.close();
    cont=0;
    archi.open("vehiculo.txt");
    if(archi.fail()){
        std::cout<<"fallo al abrir el archivo vehiculo"<<std::endl;
    }
    else{
        while(std::getline(archi,palabra)){
            aux=palabra.size();
            aux-=1;
            palabra=palabra.substr(1,aux);
            Qpalabra=QString::fromStdString(palabra);
            ui->tabla->setItem(cont,8,new QTableWidgetItem(Qpalabra));
            cont++;
        }
    }
    archi.close();
    cont=0;
    archi.open("comentario.txt");
    if(archi.fail()){
        std::cout<<"fallo al abrir el archivo comentario"<<std::endl;
    }
    else{

    }
    archi.close();


}

trazabilidad::~trazabilidad()
{
    delete ui;
}
