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
    ///AÑADIR OPERADORES A LA LISTA DE EL .UI
    ui->setupUi(this);
    setWindowTitle("Operadores");
    std::ifstream archivo;
    QString qauxOpe;
    std::string auxOpe,indiceOpe;
    archivo.open("operador.txt");
    if(archivo.fail()){
        qDebug() << "Error";
    }else{
        while(std::getline(archivo,auxOpe)){
            qauxOpe = QString::fromStdString(auxOpe);
            ui->listaOperador->addItem(qauxOpe);
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
    std::ifstream archivo;
    std::string auxOperador,vecOpe[999];
    int cont = 1;
    archivo.open("operador.txt");
    if(archivo.fail()){
        QMessageBox::warning(this,"ERROR","Error al abrir el archivo");
    }else{
        while(!archivo.eof()){
            std::getline(archivo,auxOperador);//en auxope guarda una linea
            vecOpe[cont] = auxOperador;//GUARDA TODA LA FILA
            cont++;
        }
    }
    archivo.close();
    //Pasar el vector Operadores a solo nombre para settearlos
    QString qOperador,qIndiceOperador; // auxiliares para guardar operadores e indices
    QStringList parteOperador;
    QListWidgetItem *item = ui->listaOperador->currentItem();
    QString opeActual = item->text();
    parteOperador = opeActual.split(' ');
    if(parteOperador.size() == 2){
        qOperador = parteOperador[1];
        qIndiceOperador = parteOperador[0];
    }else if(parteOperador.size() == 3){
        qOperador = parteOperador[1] + " " + parteOperador[2];
        qIndiceOperador = parteOperador[0];
    }else if(parteOperador.size() == 4){
        qOperador = parteOperador[1] + " " + parteOperador[2] + " " + parteOperador[3];
        qIndiceOperador = parteOperador[0];
    }else if(parteOperador.size() == 5){
        qOperador = parteOperador[1] + " " + parteOperador[2] + " " + parteOperador[3] + " " + parteOperador[4];
        qIndiceOperador = parteOperador[0];
    }
    ///Conseguire la empresa del operador
    archivo.open("empresa.txt");
    std::string empresa,vecEmpresas[999];
    int contEmp = 1;
    if(archivo.fail()){
        QMessageBox::warning(this,"ERROR","Error al abrir el archivo");
    }else{
        while(!archivo.eof()){
            std::getline(archivo,empresa);
            vecEmpresas[contEmp] = empresa;
            contEmp++;
        }
    }
    archivo.close();
    QString qEmp,qIndiceEmp = qIndiceOperador,qEmpActual;
    QStringList parteEmp;
    int idAc = qIndiceEmp.toInt();
    for (int i = 1; i < contEmp+1; i++) {
        if(i == idAc){
            qEmp = QString::fromStdString(vecEmpresas[i]);
            i = cont+1;
        }
    }
    parteEmp = qEmp.split(' ');
    if(parteEmp.size() == 2){
        qEmpActual = parteEmp[1];
    }else if(parteEmp.size() == 3){
        qEmpActual = parteEmp[1] + " " + parteEmp[2];
    }else if(parteEmp.size() == 4){
        qEmpActual = parteEmp[1] + " " + parteEmp[2] + " " + parteEmp[3];
    }else if(parteEmp.size() == 5){
        qEmpActual = parteEmp[1] + " " + parteEmp[2] + " " + parteEmp[3] + " " + parteEmp[4];
    }
    archivo.open("marca.txt");
    std::string marca,vecMarca[99];
    int contMarca = 1;
    if(archivo.fail()){
        QMessageBox::warning(this,"ERROR","Error al abrir el archivo");
    }else{
        while(!archivo.eof()){
            std::getline(archivo,marca);
            vecMarca[contMarca] = marca;
            contMarca++;
        }
    }
    archivo.close();
    QString qMarca,qIndiceMarca = qIndiceOperador,qMarcaActual;
    int indiceMarcaActual = qIndiceMarca.toInt();
    QStringList partesMarca;
    for(int i = 1; i < contMarca+1; i++){
        if(i == indiceMarcaActual){
            qMarca = QString::fromStdString(vecMarca[i]);
            i = contMarca+1;
        }
    }
    partesMarca = qMarca.split(' ');
    if(partesMarca.size() == 2){
        qMarcaActual = partesMarca[1];
    }else if(partesMarca.size() == 3){
        qMarcaActual = partesMarca[1] + " " + partesMarca[2];
    }else if(partesMarca.size() == 4){
        qMarcaActual = partesMarca[1] + " " + partesMarca[2] + " " + partesMarca[3];
    }else if(partesMarca.size() == 5){
        qMarcaActual = partesMarca[1] + " " + partesMarca[2] + " " + partesMarca[3] + " " + partesMarca[4];
    }
    archivo.open("colorvehiculo.txt");
    std::string color,vecColor[999];
    int contColor = 1;
    if(archivo.fail()){
        QMessageBox::warning(this,"ERROR","Error al abrir el archivo");
    }else{
        while(!archivo.eof()){
            std::getline(archivo,color);
            vecColor[contColor] = color;
            contColor++;
        }
    }
    archivo.close();
    QString qColor,qIndiceColor = qIndiceOperador,qColorActual;
    QStringList partesColor;int indiceColorActual = qIndiceColor.toInt();
    for(int i = 1; i < contColor+1; i++){
        if(i == indiceColorActual){
            qColor = QString::fromStdString(vecColor[i]);
            i = contColor + 1;
        }
    }
    partesColor = qColor.split(' ');
    if(partesColor.size() == 2){
        qColorActual = partesColor[1];
    }else if(partesColor.size() == 3){
        qColorActual = partesColor[1] + " " + partesColor[2];
    }else if(partesColor.size() == 4){
        qColorActual = partesColor[1] + " " + partesColor[2] + " " + partesColor[3];
    }else if(partesColor.size() == 4){
        qColorActual = partesColor[1] + " " + partesColor[2] + " " + partesColor[3] + " " + partesColor[4];
    }
    std::string modelo,vecModelo[999];
    int contModelo = 1;
    archivo.open("modelo.txt");
    if(archivo.fail()){
        QMessageBox::warning(this,"ERROR","Error al abrir el archivo");
    }else{
        while(!archivo.eof()){
            std::getline(archivo,modelo);
            vecModelo[contModelo] = modelo;
            contModelo++;
        }
    }
    archivo.close();
    QString qModelo,qIndiceModelo = qIndiceOperador,qModeloActual;
    int indiceActualModelo = qIndiceModelo.toInt();
    QStringList partesModelo;
    for(int i = 1; i < contModelo+1; i++){
        if(i == indiceActualModelo){
            qModelo = QString::fromStdString(vecModelo[i]);
            i = contModelo+1;
        }
    }
    partesModelo = qModelo.split(' ');
    if(partesModelo.size() == 2){
        qModeloActual = partesModelo[1];
    }else if(partesModelo.size() == 3){
        qModeloActual = partesModelo[1] + " " +partesModelo[2];
    }else if(partesModelo.size() == 4){
        qModeloActual = partesModelo[1] + " " +partesModelo[2] + " " +partesModelo[3];
    }else if(partesModelo.size() == 5){
        qModeloActual = partesModelo[1] + " " +partesModelo[2] + " " +partesModelo[3]+ " " + partesModelo[4];
    }
    archivo.open("vehiculo.txt");
    std::string vehiculo,vecVehiculo[999];
    int contVe = 1;
    if(archivo.fail()){
        QMessageBox::warning(this,"ERROR","Error al abrir el archivo");
    }else{
        while(!archivo.eof()){
            std::getline(archivo,vehiculo);
            vecVehiculo[contVe] = vehiculo;
            contVe ++;
        }
    }
    archivo.close();
    QString qVehiculo,qIndiceVehiculo = qIndiceOperador,qVehiculoActual;
    QStringList parteVe;
    int idVehiculoAc = qIndiceVehiculo.toInt();
    for(int i = 1; i < contVe+1; i++){
        if(i == idVehiculoAc){
            qVehiculo = QString::fromStdString(vecVehiculo[i]);
        }
    }
    parteVe = qVehiculo.split(' ');
    if(parteVe.size() == 2){
        qVehiculoActual = parteVe[1];
    }else if(parteVe.size() == 3){
        qVehiculoActual = parteVe[1] + " " + parteVe[2];
    }else if(parteVe.size() == 4){
        qVehiculoActual = parteVe[1] + " " + parteVe[2] + " " + parteVe[3];
    }else if(parteVe.size() == 5){
        qVehiculoActual = parteVe[1] + " " + parteVe[2] + " " + parteVe[3] + " " +parteVe[4];
    }
    archivo.open("patente.txt");
    std::string patente,vecPatentes[999];
    int contPatentes = 1;
    if(archivo.fail()){
        QMessageBox::warning(this,"ERROR","Error al abrir el archivo");
    }else{
        while(!archivo.eof()){
            std::getline(archivo,patente);
            vecPatentes[contPatentes] = patente;
            contPatentes++;
        }
    }
    archivo.close();
    QString qPatente,qIndicePatente = qIndiceOperador,qPatenteActual;
    int indicePatenteActual = qIndicePatente.toInt();
    QStringList partesPatente;
    for(int i = 1; i < contPatentes+1; i++){
        if(i == indicePatenteActual){
            qPatente = QString::fromStdString(vecPatentes[i]);
            i = contPatentes+1;
        }
    }
    partesPatente = qPatente.split(' ');
    if(partesPatente.size() == 2){
        qPatenteActual = partesPatente[1];
    }else if(partesPatente.size() == 3){
        qPatenteActual = partesPatente[1] + " " + partesPatente[2];
    }else if(partesPatente.size() == 4){
        qPatenteActual = partesPatente[1] + " " + partesPatente[2] + " " + partesPatente[3];
    }else if(partesPatente.size() == 5){
        qPatenteActual = partesPatente[1] + " " + partesPatente[2] + " " + partesPatente[3] + " " + partesPatente[4];
    }
    archivo.open("telefono.txt");
    std::string telefono, vecTelefono[999];
    int contTel = 1;
    if(archivo.fail()){
        QMessageBox::warning(this,"ERROR","Error al abrir el archivo");
    }else{
        while(!archivo.eof()){
            std::getline(archivo,telefono);
            vecTelefono[contTel] = telefono;
            contTel++;
        }
    }
    QString qTel,qIndiceTel = qIndiceOperador,qTelActual;
    QStringList partesTel;
    int indiceActualTel = qIndiceTel.toInt();
    for(int i = 1; i < contTel+1; i++){
        if(i == indiceActualTel){
            qTel = QString::fromStdString(vecTelefono[i]);
            i = contTel+1;
        }
    }
    partesTel = qTel.split(' ');
    if(partesTel.size() == 2){
        qTelActual = partesTel[1];
    }else if(partesTel.size() == 3){
        qTelActual = partesTel[1] + " " + partesTel[2];
    }else if(partesTel.size() == 4){
        qTelActual = partesTel[1] + " " + partesTel[2] + " " + partesTel[3];
    }
    emit enviarDatos(qOperador,qEmpActual,qVehiculoActual,qMarcaActual,qColorActual,qPatenteActual,qTelActual,qModeloActual);
    accept();
}
