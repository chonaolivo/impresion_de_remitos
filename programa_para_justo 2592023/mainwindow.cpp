#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <QPainter>
#include <QMessageBox>
#include <QProcess>
#include <QMainWindow>
#include <vector>
#include <QDebug>
#include <QPrinter>
#include <QPageSize>
#include <qpagesize.h>
#include "dialog.h"
#include "trazabilidad.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QStringList>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QApplication::setStyle("Fusion");
    ui->setupUi(this);
    setWindowTitle("Registro de maquinaria");

}

MainWindow::~MainWindow()
{
    delete ui;
}




///Prueba de signals

void MainWindow::on_guardar_clicked()
{
    int aux=1;
    QString Qpalabra;
    std::string palabra,extractor[9999],extractor2[9999][5];
    std::ifstream archivo;
    std::ofstream archi;
    archivo.open("operador.txt");
    if(archivo.fail()){
        qDebug() << "ERROR";
    }
    else{
        while(std::getline(archivo,extractor[aux])){
            if(extractor[aux]==" " && extractor[aux]==""){}
            else{aux++;}
        }
    }
    archivo.close();
    //guardar operador
    Qpalabra=ui->textoo->text();
    palabra=Qpalabra.toStdString();
    archi.open("operador.txt", std::ios::app);
    if(archi.fail())QMessageBox::warning(this,"Error","Error al abrir el archivo");
    else{
        //ignorar el espacio a sacar el dato
        archi<<aux<<" "<<palabra<<std::endl;
    }
    archi.close();

    //guardar empresa
    archi.open("empresa.txt", std::ios::app);
    Qpalabra=ui->textoe->text();
    palabra=Qpalabra.toStdString();
    if(archi.fail())QMessageBox::warning(this,"Error","Error al abrir el archivo");
    else{
        //ignorar el espacio a sacar el dato
        archi<<aux<<" "<<palabra<<std::endl;
    }
    archi.close();

    //guardar telefono
    archi.open("telefono.txt", std::ios::app);
    Qpalabra=ui->textotelefono->text();
    palabra=Qpalabra.toStdString();
    if(archi.fail())QMessageBox::warning(this,"Error","Error al abrir el archivo");
    else{
        //ignorar el espacio a sacar el dato
        archi<<aux<<" "<<palabra<<std::endl;
    }
    archi.close();
    //GUARDAR PATENTEN
    archi.open("patente.txt");
    Qpalabra = ui->textop->text();
    palabra = Qpalabra.toStdString();
    if(archi.fail())QMessageBox::warning(this,"Error","Error al abrir el archivo");
    else{
        //ignorar el espacio a sacar el dato
        archi<<aux<<" "<<palabra<<std::endl;
    }
    archi.close();
    //guardar km
    archi.open("kilometros.txt");
    Qpalabra = ui->textokm->text();
    palabra = Qpalabra.toStdString();
    if(archi.fail())QMessageBox::warning(this,"Error","Error al abrir el archivo");
    else{
        //ignorar el espacio a sacar el dato
        archi<<aux<<" "<<palabra<<std::endl;
    }
    archi.close();
    //gaurdar modelo
    archi.open("modelo.txt");
    Qpalabra = ui->textomodelo->text();
    palabra = Qpalabra.toStdString();
    if(archi.fail())QMessageBox::warning(this,"Error","Error al abrir el archivo");
    else{
        //ignorar el espacio a sacar el dato
        archi<<aux<<" "<<palabra<<std::endl;
    }
    archi.close();
    //gaurdar color
    archi.open("colorvehiculo.txt");
    Qpalabra = ui->textoc->text();
    palabra = Qpalabra.toStdString();
    if(archi.fail())QMessageBox::warning(this,"Error","Error al abrir el archivo");
    else{
        //ignorar el espacio a sacar el dato
        archi<<aux<<" "<<palabra<<std::endl;
    }
    archi.close();
    //guardar vehiculo
    archi.open("vehiculo.txt", std::ios::app);
    Qpalabra=ui->textot->text();
    palabra=Qpalabra.toStdString();
    if(archi.fail())QMessageBox::warning(this,"Error","Error al abrir el archivo");
    else{
        //ignorar el espacio a sacar el dato
        archi<<aux<<" "<<palabra<<std::endl;
    }
    archi.close();
    //guardar marca
    archi.open("marca.txt",std::ios::app);
    Qpalabra = ui->textom->text();
    palabra = Qpalabra.toStdString();
    if(archi.fail())QMessageBox::warning(this,"Error","Error al abrir el archivo");
    else{
        archi<<aux<<" "<<palabra<<std::endl;
    }
    archi.close();
    //guardar ingreso-salida
    archi.open("ingreso-salida.txt", std::ios::app);
    //crea el string para guardar en el archivo
    Qpalabra=ui->textom->text();Qpalabra+=" ";Qpalabra+=ui->textokm->text();Qpalabra+=" ";Qpalabra+=ui->textop->text();Qpalabra+=" ";Qpalabra+=ui->textoc->text();Qpalabra+=" ";Qpalabra+=ui->textomodelo->text();Qpalabra+=" ";Qpalabra+=ui->textoi->text();Qpalabra+=" ";Qpalabra+=ui->textos->text();Qpalabra+=" ";
    palabra=Qpalabra.toStdString();
    if(archi.fail())QMessageBox::warning(this,"Error","Error al abrir el archivo");
    else{
        //ignorar el espacio a sacar el dato
        archi<<aux<<" "<<palabra<<std::endl;
    }
    archi.close();

    //guardar comentario
    archi.open("comentario.txt", std::ios::app);
    //crea el string para guardar en el archivo
    Qpalabra=ui->comentario->toPlainText();
    palabra=Qpalabra.toStdString();
    if(archi.fail())QMessageBox::warning(this,"Error","Error al abrir el archivo");
    else{
        //ignorar el espacio a sacar el dato
        archi<<aux<<std::endl;
        archi<<palabra<<std::endl;
    }
    QMessageBox::information(this,"Mensaje","Datos guardados correctamente");

    archi.close();
}

void MainWindow::recibirDatos(QString operador, QString emp,QString vehiculo,QString marca,QString color,QString patente,QString telefono,QString modelo)
{

    QString auxOpe = operador;
    QString auxModelo = modelo;
    QString auxTel = telefono;
    QString auxEmp = emp;
    QString auxVehi = vehiculo;
    QString auxMarca = marca;
    QString auxColor = color;
    QString auxPatente = patente;
    ui->textoo->setText(auxOpe);
    ui->textoc->setText(auxColor);
    ui->textoe->setText(emp);
    ui->textom->setText(auxMarca);
    ui->textotelefono->setText(auxTel);
    ui->textop->setText(auxPatente);
    ui->textot->setText(auxVehi);
    ui->textomodelo->setText(auxModelo);
    ui->textokm->setText("XX");
    ui->textoi->setText("XX/XX/XXXX");
    ui->textos->setText("XX/XX/XXXX");
}

void MainWindow::on_imprimir_clicked()
{
    QString palabra;
    // Carga la imagen base desde la ruta especificada
    QImage baseImage("imagenbase.png");
    // Crea una nueva imagen con el mismo tamaño que la imagen base
    QImage resultImage(baseImage.size(), QImage::Format_RGB32);
    resultImage.fill(Qt::white);  // Llena la imagen con color blanco
    QPainter painter(&resultImage);  // Crea un pintor para dibujar en la imagen

    // Dibuja la imagen base en las coordenadas (0, 0)
    painter.drawImage(0, 0, baseImage);
    QFont font = painter.font();  // Obtiene la fuente actual del pintor
    // Cambia la fuente y el tamaño aquí
    font.setFamily("georgia");  // Cambia "Arial" a la fuente que desees
    font.setPointSize(55);    // Cambia el tamaño de la fuente a tu preferencia
    painter.setFont(font);  // Establece la fuente actual del pintor

    QFontMetrics fm(font);  // Obtiene métricas de la fuente para el cálculo del tamaño del texto
    int textWidth; //= fm.horizontalAdvance(text[aux]);  // Calcula el ancho del texto
    int textHeight = fm.height();  // Obtiene la altura de la fuente

    // Calcula las coordenadas para centrar el texto en la imagen
    int x = (resultImage.width() - textWidth) / 2;
    int y = (resultImage.height() - textHeight) / 2;

    //escribe lo que ingresa en operator
    y-=1035;
    palabra=ui->textoo->text();
    x-=922;
    painter.drawText(x, y, palabra);

    //escribe lo que ingresa en marca
    y+=83;
    palabra=ui->textom->text();
    painter.drawText(x, y, palabra);

    //escribe lo que ingresa en Km
    y+=84;
    palabra=ui->textokm->text();
    painter.drawText(x, y, palabra);

    //escribe lo que ingresa en patente
    y+=84;
    palabra=ui->textop->text();
    painter.drawText(x, y, palabra);

    //escribe lo que ingresa en color
    y+=84;
    palabra=ui->textoc->text();
    painter.drawText(x, y, palabra);

    //escribe lo que ingresa en tipo de vehiculo
    y+=84;
    palabra=ui->textot->text();
    painter.drawText(x, y, palabra);

    //escribe lo que ingresa em ingreso
    y-=419;
    x+=1000;
    palabra=ui->textoi->text();
    painter.drawText(x, y, palabra);

    //escribe lo que ingresa en modelo
    y+=84;
    palabra=ui->textomodelo->text();
    painter.drawText(x, y, palabra);

    //escribe lo que ingresa en empresa
    y+=84;
    palabra=ui->textoe->text();
    painter.drawText(x, y, palabra);

    //escribe lo que ingresa en telefono
    y+=84;
    palabra=ui->textotelefono->text();
    painter.drawText(x, y, palabra);

    //escribe lo que ingresa en salida
    y+=84;
    palabra=ui->textos->text();
    painter.drawText(x, y, palabra);

    //escribe lo que ingresa en comentario
    y+=328;
    x-=940;

    // Obtener el texto del QPlainTextEdit como un QString
    QString text = ui->comentario->toPlainText();

    // Dividir el texto en líneas y almacenarlas en un vector constante de strings
    QStringList lines = text.split('\n');
    // Mostrar los elementos del QStringList usando un bucle for
    for (const QString& line : lines)
    {
        painter.drawText(x, y, line);
        y+=84;
    }


    painter.end();  // Finaliza el dibujo en la imagen
    // Ruta donde se guardará la imagen generada
    QString savePath = "imagen_generada.jpg";
    resultImage.save(savePath);  // Guarda la imagen generada en la ruta especificada

    // Crear una instancia de QPrinter
    QPrinter printer;

    // Configurar las opciones de impresión (por ejemplo, el nombre de la impresora)
    printer.setPrinterName("Canon G3010 series");

    // Crear una página de tamaño A4
    QPageSize pageSize(QPageSize::A4);
    printer.setPageSize(pageSize);

    // Cargar la imagen que deseas imprimir
    QImage image("imagen_generada.jpg");

    // Crear un QPainter para pintar en la impresora
    QPainter painter1(&printer);

    if (!image.isNull()) {
        // Redimensionar la imagen a un tamaño específico (por ejemplo, 50% del tamaño original)
        QSize newSize = image.size() * 0.5;// * 0.5; // Cambia 0.5 al factor de escala deseado (0.5 sería el 50%)
        image = image.scaled(newSize, Qt::KeepAspectRatio);

        // Dibujar la imagen en el contexto de impresión
        painter1.drawImage(QPoint(14, -20), image);

        // Finalizar la pintura en la impresora
        painter1.end();
    } else {
        qDebug() << "No se pudo cargar la imagen.";
    }
}


void MainWindow::on_bbuscar_clicked()
{
    Dialog *ventana = new Dialog(this);


    connect(ventana, SIGNAL(enviarDatos(QString,QString,QString,QString,QString,QString,QString,QString)), this, SLOT(recibirDatos(QString,QString,QString,QString,QString,QString,QString,QString)));
    ventana->exec();


    delete ventana;
}

void MainWindow::on_btrazabilidad_clicked()
{
    trazabilidad pd(this);
    pd.exec();
}
