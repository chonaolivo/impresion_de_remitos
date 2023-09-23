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
    void enviarDatos(QString operador,QString emp,QString tel,QString vehiculo);//,QString,QString,QString,QString,QString,QString,QString);

public slots:
    void on_seleccionarOpera_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
