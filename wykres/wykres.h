#ifndef WYKRES_H
#define WYKRES_H

#include <QMainWindow>
#include "znajdz_pierwiastek.h"


namespace Ui {
class Wykres;
}

class Wykres : public QMainWindow
{
    Q_OBJECT

public:
    explicit Wykres(QWidget *parent = 0);
    ~Wykres();
    double power(double a, double b);
    double horner(double wsp[], double st, double x);
    void GenerujWykres();
    void UstawWspolczynniki();
    double funkcje(int j);




    int getStopien() const;
    void setStopien(int value);

    double *getWspo() const;
    void setWspo(double *value);

    Znajdz_pierwiastek *getPierwiastek() const;
    void setPierwiastek(Znajdz_pierwiastek *value);

private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(int index);

    void on_pushButton_2_clicked();

private:
    Ui::Wykres *ui;
    double funkcja;
    double *wspo;
    Znajdz_pierwiastek *pierwiastek;
    int stopien;

};

#endif // WYKRES_H
