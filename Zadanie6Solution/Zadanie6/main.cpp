#include <iostream>
#include "gnuplot_i.hpp"
#include "scheme.h"
#include<memory>
using namespace std;

#define timeBegin 0
#define timeEnd 0.04
#define E_M 120
#define BETA 0
#define OMEGA 100.0*M_PI
#define U 70
#define R 0.05
#define L 1/OMEGA
#define TETA 0.0005

void rysuj(double rangeStart, double rangeEnd, vector<vector<double>> &data)
{
	Gnuplot mainPlot;

	mainPlot.set_style("lines");   //styl rysowania wykresu
	mainPlot.set_grid();		   //siatka poprawiająca czytelnosc
	mainPlot.set_xrange(rangeStart, rangeEnd);	//zakres osi x wg. zadanych wartoœci
	mainPlot.plot_xy(data.at(0), data.at(1), "Pochodna I");

	mainPlot.set_style("lines");   //styl rysowania wykresu
	mainPlot.set_grid();		   //siatka poprawiająca czytelnosc
	mainPlot.set_xrange(rangeStart, rangeEnd);	//zakres osi x wg. zadanych wartoœci
	mainPlot.plot_xy(data.at(0), data.at(2), "Pochodna G");


	getchar();

	system("PAUSE");
}
int main()
{
	double steps;
	cout << "Podaj liczbe krokow" << endl;
	cin >> steps;
	auto sch = make_unique<Scheme>(timeBegin, timeEnd, E_M, BETA, OMEGA, U, R, L, TETA, steps);
	//Scheme *sch = new Scheme(timeBegin, timeEnd, E_M, BETA, OMEGA, U, R, L, TETA, steps);
	
	int wyborMetody;
	bool wykonujProgram = true;
	while (wykonujProgram)
	{
		cout << "wybor metody: \n[1] Metota Runego-Kutty\n[2] Metoda Ralsona\n[3] Koniec Programu" << endl;
		cin >> wyborMetody;
		if (wyborMetody == 1)
			rysuj(timeBegin, timeEnd, sch->getValuesWithRungeKutty());
		else if (wyborMetody == 2)
			rysuj(timeBegin, timeEnd, sch->getValuesWithRalston());
		else
			wykonujProgram = false;
	}
	

	//delete sch;
	return 0;
}