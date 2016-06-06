#include "laguerre.h"

Laguerre::Laguerre(int iloscWezlow)
{
    if(iloscWezlow == 2)
    {
      wezlyLaguerra.push_back(0.585786);
      wezlyLaguerra.push_back(3.41421);
      wagi.push_back(0.853553);
      wagi.push_back(0.146447);
    }
    if(iloscWezlow == 3)
    {
      wezlyLaguerra.push_back(0.415775);
      wezlyLaguerra.push_back(2.29428);
      wezlyLaguerra.push_back(6.28995);
      wagi.push_back(0.711093);
      wagi.push_back(0.278518);
      wagi.push_back(0.0103893);
    }
    if(iloscWezlow == 4)
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
    if(iloscWezlow == 5)
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
}

Laguerre::~Laguerre()
{
    wezlyLaguerra.clear();
    wagi.clear();
}

std::vector<double> Laguerre::getWezlyLaguerra() const
{
    return wezlyLaguerra;
}

void Laguerre::setWezlyLaguerra(const std::vector<double> &value)
{
    wezlyLaguerra = value;
}

std::vector<double> Laguerre::getWagi() const
{
    return wagi;
}

void Laguerre::setWagi(const std::vector<double> &value)
{
    wagi = value;
}

