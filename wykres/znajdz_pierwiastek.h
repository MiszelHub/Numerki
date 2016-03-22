#ifndef ZNAJDZ_PIERWIASTEK_H
#define ZNAJDZ_PIERWIASTEK_H
class Wykres;

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
    double MetodaBisekcji(double a,double b, double epsilon);
    void WyswietlPierwiastek();
    double getPierwiastek() const;
    void setPierwiastek(double value);

    Wykres *getWsk() const;
    void setWsk(Wykres *value);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Znajdz_pierwiastek *ui;
    Wykres *wsk;
    double pierwiastek;

};

#endif // ZNAJDZ_PIERWIASTEK_H
