#include <iostream>
#include "laguerre.h"
#include "calkazfunkcji.h"
using namespace std;

int main()
{
    int funkcja=0, wezly=0;
    cout<<"wybierz funkcje do calkowania 1-3"<<endl;
    cin>>funkcja;
    cout<<"podaj ilosc Wezlow weilomianu Laguerra 2-5"<<endl;
    cin>>wezly;
    Laguerre *l = new Laguerre(wezly);
    CalkaZFunkcji *calka = new CalkaZFunkcji(l);
    calka->funckjeDoCalkowanie(funkcja);
    double d =calka->obliczKwadratureGausaNaWielomianieLaguerra();
    delete l;
    cout << "wynik" << d << endl;

    return 0;
}

