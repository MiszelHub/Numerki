#ifndef CALKAZFUNKCJI_H
#define CALKAZFUNKCJI_H
#include <vector>
#include "laguerre.h"

class CalkaZFunkcji
{
public:
    CalkaZFunkcji(Laguerre *wielomianLaguerra);
    double funckjeDoCalkowanie(int ktoraFunkcja);
    double power(double a, double b);
    double sinus(double x);
    double wykladnicza(double x);
    double dwarazyx(double x);
    double obliczKwadratureGausaNaWielomianieLaguerra();
private:
    int wyborFunkcjil;
    Laguerre *wielomianLaguerra;
};

#endif // CALKAZFUNKCJI_H
