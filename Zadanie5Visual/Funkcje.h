#pragma once
#include "Calkowanie.h"

class Funkcje
{
	friend class Calkowanie;

public:
	Funkcje();
	~Funkcje();


	static double horner(double, double[], int);

	//FUNCKJE

	static double linear(double);

	static double absolute(double);

	static double polynomial(double);

	static double cosinus(double);


	static double cosPol(double);

	static double absCos(double);

	static double absPol(double);


	static double laguerrePolynomial(int, double);


};

