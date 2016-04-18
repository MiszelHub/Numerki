#ifndef MACIERZROWNANLINIOWYCH_H
#define MACIERZROWNANLINIOWYCH_H


class MacierzRownanLiniowych
{
public:
    MacierzRownanLiniowych(int iloscNiewiadomych);
    ~MacierzRownanLiniowych();
    int getIloscNiewiadomych() const;
    void setIloscNiewiadomych(int value);

    double **getWspolczynniki() const;
    void setWspolczynniki(double **value);

    double *getWyrazyWolne() const;
    void setWyrazyWolne(double *value);


    double *getMacierzWynikowa() const;
    void setMacierzWynikowa(double *value);


    double getEpsilon() const;
    void setEpsilon(double value);

    double getMaxIteracji() const;
    void setMaxIteracji(double value);

    int wybierzKryteriumZatrzymania(double wartoscKryterium);
    void RozwiazUkladRownanMetodaGausaSeidla();
    bool SprawdzMocneKryteriumSumyWierszy();
    bool SprawdzMocneKryteriumSumyKolumn();
    bool SprawdzCzyMacierzJestScisleDominujacaDiagonalnie();


    bool getKryterium() const;
    void setKryterium(bool value);

private:
    double **wspolczynniki;
    double *wyrazyWolne;
    int iloscNiewiadomych;
    double *macierzWynikowa;
    double epsilon;
    double maxIteracji;
    bool kryterium;
};

#endif // MACIERZROWNANLINIOWYCH_H
