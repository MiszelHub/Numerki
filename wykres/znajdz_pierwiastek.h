#ifndef ZNAJDZ_PIERWIASTEK_H
#define ZNAJDZ_PIERWIASTEK_H


#include <QDialog>

namespace Ui {
class Znajdz_pierwiastek;
}

class Znajdz_pierwiastek : public QDialog
{
    Q_OBJECT

public:
    explicit Znajdz_pierwiastek(QWidget *parent = 0);
    ~Znajdz_pierwiastek();
    double power(double a, double b);
    double horner(double wsp[], double st, double x);
    void GenerujWykres();
    void reloadWykres();

private:
    Ui::Znajdz_pierwiastek *ui;
};

#endif // ZNAJDZ_PIERWIASTEK_H
