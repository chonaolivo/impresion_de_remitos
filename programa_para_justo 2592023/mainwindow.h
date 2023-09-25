#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>  // Incluye la definición de la clase QDialog
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void recibirDatos(QString operador,QString emp,QString vehiculo,QString marca,QString color,QString patente,QString telefono,QString modelo);

private slots:
    // Declaración de funciones (slots)


    void on_guardar_clicked();  // Declaración de la función on_guardar_clicked. Esta función se ejecuta cuando se hace clic en el botón "guardar".

    void on_imprimir_clicked();  // Declaración de la función on_imprimir_clicked. Esta función se ejecuta cuando se hace clic en el botón "imprimir".

    void on_bbuscar_clicked();  // Declaración de la función on_bbuscar_clicked. Esta función se ejecuta cuando se hace clic en el botón "bbuscar".

    void on_btrazabilidad_clicked();  // Declaración de la función on_btrazabilidad_clicked. Esta función se ejecuta cuando se hace clic en el botón "btrazabilidad".



private:
    Ui::MainWindow *ui;  // Puntero a la interfaz de usuario de la ventana principal.
};

#endif // MAINWINDOW_H
