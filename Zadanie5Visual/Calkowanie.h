#pragma once
#include <vector>
#include "Funkcje.h"

typedef std::vector <double> vectorDouble;

class Calkowanie
{


public:
	Calkowanie();
	~Calkowanie();

    double silniaMianownik(int);
	double expotential(double);
	double approximation(double(double variable), double, int, int);
	double approximationEpsilon(double function(double variable), int stopien, int knotsNumber, double rangeStart, double rangeEnd, double knotsDifference);
	std::vector<double> getWezlyLaguerra() const;
	std::vector<double> getWagi() const;
	double laguerre1(double function(double variable), int stopien, int knotsNumber);
private:
	std::vector<double> wezlyLaguerra;
	std::vector<double> wagi;
};

