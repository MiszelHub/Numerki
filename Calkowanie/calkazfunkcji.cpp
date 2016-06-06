#include "calkazfunkcji.h"
#include<math.h>
CalkaZFunkcji::CalkaZFunkcji(Laguerre *wielomianLaguerra)
{
    this->wielomianLaguerra = wielomianLaguerra;
}

double CalkaZFunkcji::funckjeDoCalkowanie(int ktoraFunkcja)
{
    this->wyborFunkcjil = ktoraFunkcja;
}
double CalkaZFunkcji::power(double a, double b)
{
    double pow=1.0;
    for(int i=0;i<b;i++)
    {
       pow*=a;
    }
    return pow;
}

double CalkaZFunkcji::sinus(double x)
{
    return sin(x);
}

double CalkaZFunkcji::obliczKwadratureGausaNaWielomianieLaguerra()
{
    double wynik;
    if(wyborFunkcjil == 1)
    {
        for(size_t i=0; i < wielomianLaguerra->getWezlyLaguerra().size();i++)
        {
            wynik+=wielomianLaguerra->getWagi().at(i)*sinus(wielomianLaguerra->getWezlyLaguerra().at(i)); //sin(x)
        }
    }
    else if(wyborFunkcjil == 2)
    {
        for(size_t i=0; i < wielomianLaguerra->getWezlyLaguerra().size();i++)
        {
            wynik+=wielomianLaguerra->getWagi().at(i)*pow(2,wielomianLaguerra->getWezlyLaguerra().at(i)); //2^x
        }
    }
    else if(wyborFunkcjil == 3)
    {
        for(size_t i=0; i < wielomianLaguerra->getWezlyLaguerra().size();i++)
        {
            wynik+=wielomianLaguerra->getWagi().at(i)*dwarazyx(wielomianLaguerra->getWezlyLaguerra().at(i)); //2x
        }
    }

    return wynik;
}
double CalkaZFunkcji::wykladnicza(double x)
{
    return exp(-x)*power(2,x);
}

double CalkaZFunkcji::dwarazyx(double x)
{
    return 2*x;
}

