#ifndef SCHEME_H
#define SCHEME_H

#include <math.h>
#include <vector>

#define M_PI		3.14159265358979323846

using namespace std;

class Scheme
{
public:


private:
    double t0;
    double t1;
    double h;
    int steps;

    double E_m;
    double BETA;
    double OMEGA;
    double U;
    double R;
    double L;
    double TETA;

public:
    Scheme(double t0, double t1, double E_m, double BETA, double OMEGA, double U, double R, double L, double TETA, int steps);

    double e(double t);
    double derivative_I(double t, double i, double g);
    double derivative_G(double i, double g);

    vector<vector<double> > getValuesWithRungeKutty();
    vector<vector<double> > getValuesWithRalston();

    // -----------------------------------------------------

    double f1(double y);
    double f2(double t, double x);

    vector<vector<double> > RK();
    vector<vector<double> > Ralston();

};

#endif // SCHEME_H
