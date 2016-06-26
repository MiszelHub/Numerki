#include "Funkcje.h"
#include "gnuplot_i.hpp"
#include "Calkowanie.h"
#include <iostream>
#include <iomanip>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>


using namespace std;

double rangeStart, rangeEnd, knotsDifference,epsilon;
int choosenFunction = 0, mode = 1;
int stopien, knotsEpsilon;
int knotsNumber;
double(*ptr)(double);

Calkowanie c;
Funkcje f;

void function(double x)
{
	if (choosenFunction == 1)
	{
		ptr = Funkcje::linear;
	}
	if (choosenFunction == 2)
	{
		ptr = Funkcje::absolute;
	}
	if (choosenFunction == 3)
	{
		ptr = Funkcje::polynomial;
	}
	if (choosenFunction == 4)
	{
		ptr = Funkcje::cosinus;
	}
	if (choosenFunction == 5)
    {
        ptr = Funkcje::cosPol;
    }
    if (choosenFunction == 6)
    {
        ptr = Funkcje::absCos;
    }
    if (choosenFunction == 7)
    {
        ptr = Funkcje::absPol;
    }
}

vector<double> functionX;
vector<double> functionY;
vector<double> approximationY;

double functionValue(int functionNumber, double x)
{
    if(functionNumber==1)
		return f.linear(x);
    else if(functionNumber==2)
		return f.absolute(x);
	else if(functionNumber==3)
		return f.polynomial(x);
    else if(functionNumber==4)
		return f.cosinus(x);
    else if(functionNumber==5)
        return f.cosPol(x);
    else if(functionNumber==6)
        return f.absCos(x);
     else if(functionNumber==7)
        return f.absPol(x);
}

void setFunctionX()
{
    for(double i = rangeStart; i <= rangeEnd; i = i + 0.1)
    {
        functionX.push_back(i);
    }
}

void setFunctionY()
{
    for(int i = 0; i < functionX.size(); i++)
    {
        functionY.push_back(functionValue(choosenFunction, functionX[i]));
    }
}

void setApproximationY()
{
    for(int i = 0; i < functionX.size(); i++)
    {
        approximationY.push_back(c.approximation(ptr, functionX[i], stopien, knotsNumber));
    }
}


void rysuj()
{
    Gnuplot mainPlot;

	mainPlot.set_style("lines");   //styl rysowania wykresu
	mainPlot.set_grid();		   //siatka poprawiająca czytelnosc
	mainPlot.set_xrange(rangeStart, rangeEnd);	//zakres osi x wg. zadanych wartoœci
	mainPlot.plot_xy(functionX, functionY, "Funkcja aproksymowana");

    mainPlot.set_style("lines");   //styl rysowania wykresu
	mainPlot.set_grid();		   //siatka poprawiająca czytelnoœæ
	mainPlot.set_xrange(rangeStart, rangeEnd);	//zakres osi x wg. zadanych wartoœci
	mainPlot.plot_xy(functionX, approximationY, "Funkcja aproksymujaca");


    getchar();

    system("PAUSE");
}


int main()
{
        cout << "Wybierz aproksymowana funkcje: \n"
				"1) Liniowa \n"
				"2) Wartosc bezwzgledna \n"
				"3) Wielomian \n"
				"4) Trygonometryczna \n"
				"5) Zlozenie cosinusa na wielomian \n"
				"6) Zlozenie bezwzglednej na cosinusa \n"
				"7) Zlozenie bezwzglednej na wielomian \n";

        cin >> choosenFunction;
        function(choosenFunction);

        do{
			cout << "Podaj poczatek przedzialu \n";
			cin >> rangeStart;
			cout << "Podaj koniec przedzialu \n";
			cin >> rangeEnd;
			if (rangeEnd <= rangeStart)
			{
				cout << "Wartosc koncowa przedzialu musi byc wieksza od poczatkowej!";
			}
        } while (rangeEnd <= rangeStart);
        mode = 1;
    if(mode == 1)
    {
		cout << "Podaj stopien wielomiau aproksymujacego: \n";
		cin >>  stopien;

		cout << "Podaj liczbe wezlow: (2/3/4/5)" << endl;

		cin >> knotsNumber;
	        knotsDifference = (rangeEnd - rangeStart) / (knotsNumber - 1);

		cout << "Wartosc calki metoda Laguerre'a " << c.laguerre1(ptr, stopien, knotsNumber) << "\n";
		cout << "Blad aproksymacji: " << c.approximationEpsilon(ptr, stopien, knotsNumber, rangeStart, rangeEnd, knotsDifference) << "\n";
    }

        setFunctionX();
        setFunctionY();
        setApproximationY();

		rysuj();

	return 0;
}

