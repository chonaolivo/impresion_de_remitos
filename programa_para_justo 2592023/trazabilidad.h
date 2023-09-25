#ifndef TRAZABILIDAD_H
#define TRAZABILIDAD_H

#include <QDialog>

namespace Ui {
class trazabilidad;
}

class trazabilidad : public QDialog
{
    Q_OBJECT

public:
    explicit trazabilidad(QWidget *parent = nullptr);
    ~trazabilidad();

private:
    Ui::trazabilidad *ui;
};

#endif // TRAZABILIDAD_H
