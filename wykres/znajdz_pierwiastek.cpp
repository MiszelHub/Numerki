#include "znajdz_pierwiastek.h"
#include "ui_znajdz_pierwiastek.h"

Znajdz_pierwiastek::Znajdz_pierwiastek(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Znajdz_pierwiastek)
{
    ui->setupUi(this);
}

Znajdz_pierwiastek::~Znajdz_pierwiastek()
{
    delete ui;
}

double Znajdz_pierwiastek::power(double a, double b)
{
    double pow=1;
    for(int i=0;i<b;i++)
    {
       pow*=a;
    }
    return pow;
}

double Znajdz_pierwiastek::horner(double wsp[], double st, double x)
{
    double wynik = wsp[0];

    for(int i=1.0;i<=st;i++)
      wynik = wynik*x + wsp[i];

    return wynik;
}

void Znajdz_pierwiastek::GenerujWykres()
{

}
