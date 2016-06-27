#include "scheme.h"

Scheme::Scheme(double t0, double t1, double E_m, double BETA, double OMEGA, double U, double R, double L, double TETA, int steps)
{
    this->steps = steps;
    this->t0 = t0;
    this->t1 = t1;
    this->h = (t1 - t0) / this->steps;

    this->E_m = E_m;
    this->BETA = BETA;
    this->OMEGA = OMEGA;
    this->U = U;
    this->R = R;
    this->L = L;
    this->TETA = TETA;
}

// ----------------------------------------------------------------------------------------------

double Scheme::e(double t)
{
    return E_m * sin(OMEGA * t + BETA);
}

// ----------------------------------------------------------------------------------------------

double Scheme::derivative_I(double t, double i, double g)
{
    return (e(t) - R * i - (i/g)) / L;
}

// ----------------------------------------------------------------------------------------------

double Scheme::derivative_G(double i, double g)
{
    return (((i / U) * (i / U)) / g - g) / TETA;
}

// ----------------------------------------------------------------------------------------------

double Scheme::f1(double y)
{
    return y;
}

// ----------------------------------------------------------------------------------------------

double Scheme::f2(double t, double x)
{
    return -x + 4 * exp(t);
}

// ----------------------------------------------------------------------------------------------

vector<vector<double> > Scheme::RK()
{
    vector<double> time;
    vector<double> x;
    vector<double> y;

    time.push_back(0);
    x.push_back(0.0);
    y.push_back(0.0);

    double k1_x, k2_x, k3_x, k4_x;
    double k1_y, k2_y, k3_y, k4_y;
    for(int i = 0; i < steps; i++)
    {
        time.push_back(i * h);

        k1_x = h * f1(y[i]);
        k1_y = h * f2(time[i], x[i]);

        k2_x = h * f1(y[i] + (k1_y * 0.5));
        k2_y = h * f2(time[i]  + (h * 0.5), x[i] + (k1_x * 0.5));

        k3_x = h * f1(y[i] + (k2_y * 0.5));
        k3_y = h * f2(time[i]  + (h * 0.5), x[i] + (k2_x * 0.5));

        k4_x = h * f1(y[i] + k3_y);
        k4_y = h * f2(time[i]  + h, x[i] + k3_x);

        x.push_back(x[i] + (1.0/6.0) * (k1_x + 2 * k2_x + 2.0 * k3_x + k4_x));
        y.push_back(y[i] + (1.0/6.0) * (k1_y + 2 * k2_y + 2.0 * k3_y + k4_y));
    }

    return {time, x, y};
}

// ----------------------------------------------------------------------------------------------

vector<vector<double> > Scheme::getValuesWithRungeKutty()
{
    vector<double> time;
    vector<double> valuesOfDerivative_I;
    vector<double> valuesOfDerivative_G;

    time.push_back(0);
    valuesOfDerivative_I.push_back(0.0);
    valuesOfDerivative_G.push_back(3.5);

    double k1_I, k2_I, k3_I, k4_I;
    double k1_G, k2_G, k3_G, k4_G;
    for(int i = 0; i < steps; i++)
    {
        time.push_back(i * h);

        k1_I = h * derivative_I(time[i], valuesOfDerivative_I[i], valuesOfDerivative_G[i]);
        k1_G = h * derivative_G(valuesOfDerivative_I[i], valuesOfDerivative_G[i]);

        k2_I = h * derivative_I(time[i] + (h * 0.5), valuesOfDerivative_I[i] + (k1_I * 0.5), valuesOfDerivative_G[i] + (k1_G * 0.5));
        k2_G = h * derivative_G(valuesOfDerivative_I[i] + (k1_I * 0.5), valuesOfDerivative_G[i] + (k1_G * 0.5));

        k3_I = h * derivative_I(time[i] + (h * 0.5), valuesOfDerivative_I[i] + (k2_I * 0.5), valuesOfDerivative_G[i] + (k2_G * 0.5));
        k3_G = h * derivative_G(valuesOfDerivative_I[i] + (k2_I * 0.5), valuesOfDerivative_G[i] + (k2_G * 0.5));

        k4_I = h * derivative_I(time[i], valuesOfDerivative_I[i] + k3_I, valuesOfDerivative_G[i] + k3_G);
        k4_G = h * derivative_G(valuesOfDerivative_I[i] + k3_I, valuesOfDerivative_G[i] + k3_G);

        valuesOfDerivative_I.push_back(valuesOfDerivative_I[i] + (1.0/6.0) * (k1_I + 2 * k2_I + 2.0 * k3_I + k4_I));
        valuesOfDerivative_G.push_back(valuesOfDerivative_G[i] + (1.0/6.0) * (k1_G + 2 * k2_G + 2.0 * k3_G + k4_G));
    }

    return {time, valuesOfDerivative_I, valuesOfDerivative_G};
}

vector<vector<double> > Scheme::getValuesWithRalston()
{
    vector<double> time;
    vector<double> valuesOfDerivative_I;
    vector<double> valuesOfDerivative_G;

    time.push_back(0);
    valuesOfDerivative_I.push_back(0.0);
    valuesOfDerivative_G.push_back(3.5);

    double k1_I, k2_I, k3_I, k4_I;
    double k1_G, k2_G, k3_G, k4_G;
    for(int i = 0; i < steps; i++)
    {
        time.push_back(i * h);

        k1_I = h * derivative_I(time[i], valuesOfDerivative_I[i], valuesOfDerivative_G[i]);
        k1_G = h * derivative_G(valuesOfDerivative_I[i], valuesOfDerivative_G[i]);

        k2_I = h * derivative_I(time[i] + (h * 0.4), valuesOfDerivative_I[i] + (k1_I * 0.4), valuesOfDerivative_G[i] + (k1_G * 0.4));
        k2_G = h * derivative_G(valuesOfDerivative_I[i] + (k1_I * 0.4), valuesOfDerivative_G[i] + (k1_G * 0.4));

        k3_I = h * derivative_I(time[i] + (h * 0.45573726), valuesOfDerivative_I[i] + (k1_I * 0.2969770) + (k2_I * 0.15875966), valuesOfDerivative_G[i] + (k1_G * 0.2969770) + (k2_G * 0.15875966));
        k3_G = h * derivative_G(valuesOfDerivative_I[i] + (k1_I * 0.2969770) + (k2_I * 0.15875966), valuesOfDerivative_G[i] + (k1_G * 0.2969770) + (k2_G * 0.15875966));

        k4_I = h * derivative_I(time[i] + h, valuesOfDerivative_I[i] + (k1_I * 0.21810038) - (k2_I * 3.05096470) + (k3_I * 3.83286432), valuesOfDerivative_G[i] + (k1_G * 0.21810038) - (k2_G * 3.05096470) + (k3_G * 3.83286432));
        k4_G = h * derivative_G(valuesOfDerivative_I[i] + k3_I, valuesOfDerivative_G[i] + k3_G);

        valuesOfDerivative_I.push_back(valuesOfDerivative_I[i] + (k1_I * 0.17476028 - k2_I * 0.55148053 + k3_I * 1.20553547 + k4_I * 0.17118478) / 6.0);
        valuesOfDerivative_G.push_back(valuesOfDerivative_G[i] + (k1_G * 0.17476028 - k2_G * 0.55148053 + k3_G * 1.20553547 + k4_G * 0.17118478) / 6.0);
    }

    return {time, valuesOfDerivative_I, valuesOfDerivative_G};
}
