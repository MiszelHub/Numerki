#ifndef LAGUERRE_H
#define LAGUERRE_H
#include"vector"


class Laguerre
{
public:
    Laguerre(int iloscWezlow);
    ~Laguerre();
    std::vector<double> getWezlyLaguerra() const;
    void setWezlyLaguerra(const std::vector<double> &value);

    std::vector<double> getWagi() const;
    void setWagi(const std::vector<double> &value);

private:
    std::vector<double> wezlyLaguerra;
    std::vector<double> wagi;
};

#endif // LAGUERRE_H
