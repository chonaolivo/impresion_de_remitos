#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    //QStringList obtenerIndice();
signals:
    void enviarDatos(QString operador,QString emp,QString vehiculo,QString marca,QString color,QString patente,QString telefono,QString modelo);

public slots:
    void on_seleccionarOpera_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
