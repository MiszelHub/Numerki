#ifndef WYKRES_H
#define WYKRES_H

#include <QMainWindow>

namespace Ui {
class Wykres;
}

class Wykres : public QMainWindow
{
    Q_OBJECT

public:
    explicit Wykres(QWidget *parent = 0);
    ~Wykres();

private:
    Ui::Wykres *ui;
};

#endif // WYKRES_H
