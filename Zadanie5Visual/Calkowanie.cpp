#include "Funkcje.h"
#include <iostream>
#include <iomanip>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Calkowanie.h"
//#include <boost\math\special_functions\laguerre.hpp>

using namespace std;

Funkcje fun;

Calkowanie::Calkowanie()
{
}


Calkowanie::~Calkowanie()
{
}

double Calkowanie::silniaMianownik(int k)
{
    int wynik = 1;
    int tmp;
    if (k == 0 || k==1) return 1;
    else
    {
        while (k > 0)
        {
            wynik *= k;
            k--;
        }
    }
    tmp=wynik*wynik;
    return tmp;
}
unsigned long int silnia(int n) {
	unsigned long int s = 1;
	for (int i = 1; i <= n; i++) s *= i;
	return s;
}

double potega(double x, int n) {
	if (n == 0) return 1;
	int p = x;
	for (int i = 1; i < n; i++) p *= x;
	return p;
}

double Calkowanie::approximation(double function(double variable), double x, int stopien, int knotsNumber)
{
    double(*ptr)(double);
    ptr = function;
    double result = 0;

    for(int i = 0; i <= stopien; i++)
    {
		//result += ((boost::math::laguerre(i, x)* laguerre1(ptr, i, knotsNumber))) / (silnia(i));
		result += ((fun.laguerrePolynomial(i, x)*laguerre1(ptr, i, knotsNumber)))/ silniaMianownik(i);
    }
    return result;
}

double Calkowanie::approximationEpsilon(double function(double variable), int stopien, int knotsNumber, double rangeStart, double rangeEnd, double knotsDifference)
{
    double(*ptr)(double);
    ptr = function;
    double result = 0;

    for(double i = rangeStart; i < rangeEnd; i+= knotsDifference)
    {
        result += (function(i) - this->approximation(ptr, i, stopien, knotsNumber)) * (function(i) - this->approximation(ptr, i, stopien, knotsNumber));
    }
    result = sqrt(result);
    return result;
}
std::vector<double> Calkowanie::getWezlyLaguerra() const
{
	return wezlyLaguerra;
}
std::vector<double> Calkowanie::getWagi() const
{
	return wagi;
}
double simpsons(double(*f)(double x), double a, double b, int n) {
	double h = (b - a) / n;
	double x;
	double r;
	char m = 0;
	double s = 0.0;

	for (x = a; x <= b; x += h) {
		r = f(x);
		if (x == a || x == b) {
			s += r;
		}
		else {
			m = !m;
			s += r * (m + 1) * 2.0;
		}
	}
	return s * (h / 3.0);
}
double Calkowanie::laguerre1(double function(double variable), int stopien, int knotsNumber)
{
	cout << setprecision(4)		// dokladnosc do epsilona
		<< fixed;

	double result = 0;

    // 1 kolumna - wêz³y, 2 kolumna - wagi z tabelki z wyk³adu

 //   double knots2[2][2] = {  { 0.585786, 0.853553 },
 //                           { 3.414214, 0.146447 } };


	//double knots3[3][2] = {  { 0.415775, 0.711093 },
 //                           { 2.294280, 0.278518 },
 //                           { 6.289945, 0.010389 } };


	//double knots4[4][2] = {  { 0.322548, 0.603154 },
 //                           { 1.745761, 0.357419 },
 //                           { 4.536620, 0.038888 },
 //                           { 9.395071, 0.000539 } };


	//double knots5[5][2] = {  { 0.263560, 0.521756 },
 //                           { 1.413403, 0.398667 },
 //                           { 3.596426, 0.075942 },
 //                           { 7.085810, 0.003612 },
 //                           { 12.640801, 0.000032 } };




	//for (int i = 0; i < knotsNumber; i++)       //waga*wartosc fcji w wezle*wartosc wielomianu laguerrea w wezle
	//{
	//    if(knotsNumber==2)
	//	result += knots2[i][1] * function(knots2[i][0]) * fun.laguerrePolynomial(stopien, knots2[i][0]);
	//	else if(knotsNumber==3)
 //       result += knots3[i][1] * function(knots3[i][0]) * fun.laguerrePolynomial(stopien, knots3[i][0]);
 //       else if(knotsNumber==4)
 //       result += knots4[i][1] * function(knots4[i][0]) * fun.laguerrePolynomial(stopien, knots4[i][0]);
 //       else if(knotsNumber==5)
	//	result += knots5[i][1] * function(knots5[i][0]) * fun.laguerrePolynomial(stopien, knots5[i][0]);
	//}
	if (knotsNumber == 2)
	{
		wezlyLaguerra.push_back(0.585786);
		wezlyLaguerra.push_back(3.41421);
		wagi.push_back(0.853553);
		wagi.push_back(0.146447);
	}
	if (knotsNumber == 3)
	{
		wezlyLaguerra.push_back(0.415775);
		wezlyLaguerra.push_back(2.29428);
		wezlyLaguerra.push_back(6.28995);
		wagi.push_back(0.711093);
		wagi.push_back(0.278518);
		wagi.push_back(0.0103893);
	}
	if (knotsNumber == 4)
	{
		wezlyLaguerra.push_back(0.322548);
		wezlyLaguerra.push_back(1.74576);
		wezlyLaguerra.push_back(4.53662);
		wezlyLaguerra.push_back(9.39507);
		wagi.push_back(0.603154);
		wagi.push_back(0.357419);
		wagi.push_back(0.0388879);
		wagi.push_back(0.000539295);
	}
	if (knotsNumber == 5)
	{
		wezlyLaguerra.push_back(0.26356);
		wezlyLaguerra.push_back(1.4134);
		wezlyLaguerra.push_back(3.59643);
		wezlyLaguerra.push_back(7.08581);
		wezlyLaguerra.push_back(12.6408);
		wagi.push_back(0.521756);
		wagi.push_back(0.398667);
		wagi.push_back(0.0759424);
		wagi.push_back(0.00361176);
		wagi.push_back(0.00002337);
	}
	for (size_t i = 0; i < knotsNumber; i++)
	{
		result += getWagi().at(i)*function(getWezlyLaguerra().at(i)); 
	}

	return result;


}

