#include "Funkcje.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>


using namespace std;


Funkcje::Funkcje()
{
}
Funkcje::~Funkcje()
{
}

double Funkcje::horner(double variable, double polynomialCoefficients[], int polynomialDegree)
{
	if (polynomialDegree == 0)
		return polynomialCoefficients[0];
	else
		return variable*horner(variable, polynomialCoefficients, polynomialDegree - 1) + polynomialCoefficients[polynomialDegree];
}

double Funkcje::linear(double variable)
{
	double coefficients[2] = { 4, 6 };
	int degree = 1;
	return horner(variable, coefficients, degree);
}

double Funkcje::absolute(double variable)
{
	return fabs(2*variable);
}

double Funkcje::polynomial(double variable)
{
	double coefficients[5] = { 6, 9, 13, 2, 7 };
	double degree = 4;
	return horner(variable, coefficients, degree);
}

double Funkcje::cosinus(double variable)
{
	return cos(variable);
}

double Funkcje::cosPol(double variable)
{
    return cos(polynomial(variable));
}

double Funkcje::absCos(double variable)
{

    return fabs(sin(variable*M_PI));
}

double Funkcje::absPol(double variable)
{

    return absolute(polynomial(variable));
}

double Funkcje::laguerrePolynomial(int stopien, double variable){
    if(stopien==0) {
                    double coefficients[1] = {1};
                    double degree = 0;
                    return horner(variable, coefficients, degree);
                    }
    else if(stopien==1) {
                    double coefficients[2] = { -1,1};
                    double degree = 1;
                    return horner(variable, coefficients, degree);
                    }
    else if(stopien>1)
                  return (2*(stopien-1)+1-variable)*laguerrePolynomial(stopien-1,variable)-(((stopien-1)*(stopien-1))*laguerrePolynomial(stopien-2,variable));
				 // return (2 * (stopien + 1) - variable)*laguerrePolynomial(stopien, variable) - (((stopien))*laguerrePolynomial(stopien - 1, variable));


}


