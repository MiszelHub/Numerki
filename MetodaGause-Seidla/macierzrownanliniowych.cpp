#include "macierzrownanliniowych.h"
#include<algorithm>
#include<iostream>

MacierzRownanLiniowych::MacierzRownanLiniowych(int iloscNiewiadomych)
{
    this->iloscNiewiadomych = iloscNiewiadomych;

    wyrazyWolne = new double [iloscNiewiadomych];

    macierzWynikowa = new double [iloscNiewiadomych];
    for(int i=0;i<iloscNiewiadomych;i++)
        macierzWynikowa[i]=0;

    wspolczynniki = new double *[iloscNiewiadomych];
    for(int i=0; i<iloscNiewiadomych;i++)
    {
        wspolczynniki[i] = new double[iloscNiewiadomych];
    }

}

MacierzRownanLiniowych::~MacierzRownanLiniowych()
{
    delete [] macierzWynikowa;
    delete [] wyrazyWolne;
    for(int i=0; i<iloscNiewiadomych;i++)
    {
        delete [] wspolczynniki[i];
    }
    delete [] wspolczynniki;
}

int MacierzRownanLiniowych::getIloscNiewiadomych() const
{
    return iloscNiewiadomych;
}

void MacierzRownanLiniowych::setIloscNiewiadomych(int value)
{
    iloscNiewiadomych = value;
}

double **MacierzRownanLiniowych::getWspolczynniki() const
{
    return wspolczynniki;
}

void MacierzRownanLiniowych::setWspolczynniki(double **value)
{
    wspolczynniki = value;
}

double *MacierzRownanLiniowych::getWyrazyWolne() const
{
    return wyrazyWolne;
}

void MacierzRownanLiniowych::setWyrazyWolne(double *value)
{
    wyrazyWolne = value;
}

double *MacierzRownanLiniowych::getMacierzWynikowa() const
{
    return macierzWynikowa;
}

void MacierzRownanLiniowych::setMacierzWynikowa(double *value)
{
    macierzWynikowa = value;
}

void MacierzRownanLiniowych::RozwiazUkladRownanMetodaGausaSeidla()
{
    int iteracje=0;
    double *poprzedniePrzyblizenie = new double[iloscNiewiadomych];
    std::fill(poprzedniePrzyblizenie,poprzedniePrzyblizenie+iloscNiewiadomych,0);
    bool active =true;

    while(active)
    {
        for(int i=0; i<iloscNiewiadomych;i++)
        {
            double sum = wyrazyWolne[i];
            std::cout<<"suma"<<sum<<std::endl;
            for(int j=0;j< iloscNiewiadomych;j++)
            {
                if(i != j)
                    sum = sum - wspolczynniki[i][j]*macierzWynikowa[j];
                macierzWynikowa[i] = sum/wspolczynniki[i][i];
                std::cout<<"macierz wynikowa: "<<macierzWynikowa[i]<<std::endl;
            }
        }
        if(this->kryterium == 0)
        {
            for(int i=0;i<iloscNiewiadomych;i++)
                if((fabs(macierzWynikowa[i])-poprzedniePrzyblizenie[i])>epsilon)
                    active=false;
        }else
        {
            iteracje++;
            if(iteracje == maxIteracji)
                active=false;
        }


        std::copy(macierzWynikowa,macierzWynikowa+iloscNiewiadomych,poprzedniePrzyblizenie);
    }
}

bool MacierzRownanLiniowych::SprawdzCzyMacierzJestScisleDominujacaDiagonalnie()
{

    bool czyDominujacaDiagonalnie=true;
    for(int i=0;i<iloscNiewiadomych;i++)
    {
        double sum = 0;
        for(int j=0;j<iloscNiewiadomych;j++)
        {
            if(i!=j)
                sum += fabs(wspolczynniki[i][j]);
        }
        if(wspolczynniki[i][i] < sum)
            czyDominujacaDiagonalnie=false;
    }
    return czyDominujacaDiagonalnie;
}

bool MacierzRownanLiniowych::getKryterium() const
{
    return kryterium;
}

void MacierzRownanLiniowych::setKryterium(bool value)
{
    kryterium = value;
}

double MacierzRownanLiniowych::getEpsilon() const
{
    return epsilon;
}

void MacierzRownanLiniowych::setEpsilon(double value)
{
    epsilon = value;
}

double MacierzRownanLiniowych::getMaxIteracji() const
{
    return maxIteracji;
}

void MacierzRownanLiniowych::setMaxIteracji(double value)
{
    maxIteracji = value;
}

int MacierzRownanLiniowych::wybierzKryteriumZatrzymania(double wartoscKryterium)
{
    if(this->kryterium == 0)
    {
       epsilon = wartoscKryterium;
    }
    else
    {
        maxIteracji = static_cast<int>(wartoscKryterium);
    }
}
