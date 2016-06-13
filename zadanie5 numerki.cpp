#include <iostream>
#define GNUPLOT_PATH "C:/gnuplot/bin"
#include "gnuplot_i.hpp"

#include "cmath"
using namespace std;

//FUNKCJE MATEMATYCZNE
unsigned long long silnia(int n);
unsigned long long dwumianNewtona(double n, double k);
//FUNKCJE WEJŚCIOWE
double horner(std::vector<double> wspolczynniki, int stopien, double x);
double f2(double x);
double f3(double x);
double f1(double x);
double f4(double x);
double f5(double x);
double f6(double x);
double f7(double x);
int f = podajFunkcje();
int stopien = podaj("stopien wielomianu");
int wezly = podaj("ilosc wezlow");
double **macierz = wypelnij(wezly);

//FUNKCJE WYKONUJĄCE ZAŁOŻENIA PROGRAMU
void wyznaczWspolczynniki(std::vector<double> &w, int stopien);
double iloczyn(double(*func)(double), std::vector<double> w, int stopien, double x);
double calka(double A, double B, std::vector<double> wielomian, int stopien, double(*fun)(double), double epsilon);

double(*fun[])(double) = { f1, f2, f3, f4, f5, f6, f7 };

double f1(double x){
    return x+2;
}
double f2(double x)
{
    vector<double> wspolczynniki = { 1,0,2};
    return horner(wspolczynniki, 2, x);
}
double f3(double x)
{
    vector<double> wspolczynniki = { 0.25, 4.0, 0.0, 8.0 };
    return horner(wspolczynniki, 3, x);
}
double f4(double x)
{
    return exp(-2 * x);
}
double f5(double x)
{
    return fabs(x);
}
double f6(double x)
{
    return sin(x);
}
double f7(double x)
{
    return sin(fabs(x));
}
unsigned long long dwumianNewtona(double n, double k)
{
    double wynik = 1;
    if (k == 0 || k == n)
        return (unsigned long long)wynik;
    else
    {
        for (unsigned int i = 1; i <= k; i++)
        {
            wynik *= (n - i + 1) / i;
        }
        return (unsigned long long)wynik;
    }
}
unsigned long long silnia(int n)
{
    unsigned long long wynik = 1;
    for (int i = 2; i <= n; i++)
    {
        wynik *= i;
    }
    return wynik;
}

void wyznaczWspolczynniki(vector<double> &w, int stopien)
{
    double y = 1;
    if (stopien == 0) w[0] = 1;
    for (int i = 0; i < stopien+1; i++)
    {
        y = pow(-1, i) * dwumianNewtona(stopien, i) / silnia(i);
        w[i] = y;
    }
}

double horner(vector<double> wspolczynniki, int stopien, double x)
{
    double wynik = wspolczynniki[stopien];
    for (int i = stopien - 1; i >= 0; i--)
    {
        wynik = wynik*x + wspolczynniki[i];
    }

    return wynik;
}
double iloczyn(double(*func)(double), vector<double> w, int stopien, double x)
{
    return func(x)*horner(w, stopien, x)*exp(-x);
}


double calka(double A, double B, vector<double> wielomian, int stopien, double(*fun)(double), double epsilon)
{
    vector<double> wyniki;
    double n = 2.0;
    int iteracje = 0;
    double roznica;
    do
    {
        double wynik = 0.0;
        double h = (B - A) / n;
        double xa = A;
        for (int i = 0; i < n / 2; i++)
        {
            wynik = wynik + (h / 3.0)*(iloczyn(fun, wielomian, stopien, xa) + 4 * iloczyn(fun, wielomian, stopien, xa + h) + iloczyn(fun, wielomian, stopien, xa + h + h));
            xa = xa + h + h;
        }

        wyniki.push_back(wynik);

        if (iteracje == 0)
        {
            roznica = wynik;
        }
        else
        {
            roznica = wynik - wyniki[iteracje - 1];
        }

        if (abs(roznica) < epsilon)
        {
            break;
        }

        n *= 2.0;
        iteracje += 1;
    } while (true);

    return wyniki[wyniki.size() - 1];
}
//loool
void wyczyscWektor(vector<double> &w)
{
    for (int i = 0; i < w.size(); i++)
    {
        w[i] = 0;
    }
}
void aproksymacja(double A, vector<double> &xApr, vector<double> &yApr, int stopien, double(*func)(double))
{
    vector<double> lambdy(stopien + 1);
    vector<double> wspolczynniki(stopien + 1);
    double blad = 0;
    for (int i = 0; i <= stopien; i++)
    {
        wyczyscWektor(wspolczynniki);
        wyznaczWspolczynniki(wspolczynniki, i);
        lambdy[i] = Gauss(func, wspolczynniki, i, wezly, macierz);
        cout << lambdy[i] << endl;
    }

    cout << endl;

    vector<double> wspol_apr(stopien + 1);						//Liczenie współczynników wielomianiu aproksymującego
    for (int i = 0; i < stopien + 1; i++)
    {
        for (int j = 0; j < stopien + 1; j++)
        {
            wyczyscWektor(wspolczynniki);
            wyznaczWspolczynniki(wspolczynniki, j);
            wspol_apr[i] += lambdy[j] * wspolczynniki[i];
        }
    }

    for (double x = 0; x <= A; x += 0.1)
    {
        xApr.push_back(x);
        double y = 0;
        y = horner(wspol_apr, stopien, x);
        cout << "x= " << x << " y= " << y << endl;
        yApr.push_back(y);
    }

    for (int k = 0; k < stopien + 1; k++)
    {
        cout << "wielomian aprox[" << k << "]= " << wspol_apr[k] << endl;
    }
    blad = Gauss_blad(func, wspol_apr, stopien, wezly, macierz);
    cout << "Blad aproksymacji wynosi: " << blad << endl;
}

int main(int argc, char* argv[])
{
    int f;
    cout <<"\\\\\\\\\\\\\\\\\\\\\\\\Kozlowicz Ordon\\\\\\\\\\\\\\\\\\\\\\\\"<<endl;
    cout << "\\ Aproksymacja -wielomiany Laguerrea \\"<<endl;
    cout <<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"<<endl;
    cout << "Wybierz funkcje:\n";
    cout << "[1] Funkcja liniowa f(x) =x+2\n";
    cout << "[2] Wielomian f(x) = x^3 + 2\n";
    cout<<  "[3] Wielomian f(x)= 8x^3 +4x + 0.25\n";
    cout<<  "[4] Exponent e^(-2*x)\n";
    cout << "[5] Funkcja f(x) = |x|\n";
    cout << "[6] Funkcja trygonometryczna f(x) = sin(x)\n";
    cout << "[7] Zlozenie f(x) = sin(|x|)\n";

    cout << "wybor: ";
    cin >> f;

    int stopien;
    cout << "Podaj stopien wielomianu" << endl;
    cin >> stopien;

    double przedzial;
    cout << "Podaj kraniec przedzialu aproksymacji: " << endl;
    cin >> przedzial;

    Gnuplot::set_GNUPlotPath(GNUPLOT_PATH);
    Gnuplot myPlot;

    myPlot.set_title("Aproksymacja");
    myPlot.set_xlabel("X");
    myPlot.set_ylabel("Y");

    myPlot.set_style("lines");
    myPlot.set_grid();
    myPlot.set_xrange(0, przedzial);
    double zasieg = 100 * abs(przedzial);

    vector<double> x(zasieg);
    vector<double> xApr;
    vector<double> y(zasieg);
    vector<double> yApr;


    for (double i = 0.0; i < zasieg; i += 1.0)
        {
            x_func[i] = a*(zasieg - i) / zasieg;
            y_func[i] = func[f-1](x_func[i]);							//przykładowa funkcja
        }

    aproksymacja(przedzial, xApr, yApr, stopien, fun[f-1]);

    myPlot.plot_xy(x, y, "Funkcja wejsciowa");
    myPlot.plot_xy(xApr, yApr, "Wielomian aproksymacyjny");

    myPlot.set_style("points");
    myPlot.set_pointsize(2.0);


    system("PAUSE");
    return 0;
}

