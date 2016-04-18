#include <iostream>
#include "macierzrownanliniowych.h"
#include<fstream>
#include<string>
using namespace std;
void WypelnijMaciezRownanLiniowychZpliku(MacierzRownanLiniowych *macierz)
{
    ifstream plikWspolczynnikow;
    plikWspolczynnikow.open("wspolczynniki.txt",ios_base::in);
    if(!plikWspolczynnikow.is_open())
        throw "Nie otworzono pliku";

        for(int i=0;i<macierz->getIloscNiewiadomych();i++)
        {
            for(int j=0;j<macierz->getIloscNiewiadomych();j++)
            {
                string tmp;
                plikWspolczynnikow >> tmp;
                macierz->getWspolczynniki()[i][j] = stod(tmp);


            }
        }
    plikWspolczynnikow.close();

    if(!macierz->SprawdzCzyMacierzJestScisleDominujacaDiagonalnie())
        throw "Macierz nie jest diagonalnie dominujaca";

    cout<<"Podaj wyrazywolne"<<endl;
    for(int i=0;i<macierz->getIloscNiewiadomych();i++)
    {
        cout<<"Podaj element : ["<<i<<"] ";
        cin>>macierz->getWyrazyWolne()[i];
    }
}

void WypelnijMaciezRownanLiniowych(MacierzRownanLiniowych *macierz)
{
    cout<<"Podaj wspolczynniki przyniewiadomych"<<endl;
    for(int i=0;i<macierz->getIloscNiewiadomych();i++)
    {
        for(int j=0;j<macierz->getIloscNiewiadomych();j++)
        {
            cout<<"Podaj element : ["<<i<<"]""["<<j<<"]"<<" ";
            cin>>macierz->getWspolczynniki()[i][j];
            cout<<endl;

        }
    }
    if(!macierz->SprawdzCzyMacierzJestScisleDominujacaDiagonalnie())
        throw "Macierz nie jest diagonalnie dominujaca";

    cout<<"Podaj wyrazywolne"<<endl;
    for(int i=0;i<macierz->getIloscNiewiadomych();i++)
    {
        cout<<"Podaj element : ["<<i<<"] ";
        cin>>macierz->getWyrazyWolne()[i];
    }
}

void WyswietlMAcierz(MacierzRownanLiniowych *macierz)
{
    cout<<"maciez wspolczynnikow"<<endl;
    for(int i=0;i<macierz->getIloscNiewiadomych();i++)
    {
        for(int j=0;j<macierz->getIloscNiewiadomych();j++)
        {
          cout<<macierz->getWspolczynniki()[i][j]<<" ";

        }
        cout<<endl;
    }
    cout<<"maciez wyrazow wolnych"<<endl;
    for(int i=0;i<macierz->getIloscNiewiadomych();i++)
    {
        cout<<macierz->getWyrazyWolne()[i]<<endl;
    }
}

int main(int argc, char *argv[])
{

    int iloscNiewiadomych;
    bool wyborKryteriumZatrzymania;
    double kryterium;

    cout<<"Podaj ilosc niewiadomych "<<endl;
    cin>>iloscNiewiadomych;

    MacierzRownanLiniowych *macierz = new MacierzRownanLiniowych(iloscNiewiadomych);

    cout<<"Czy chcesz wczytac wspolczynniki z plku"<<endl;
    cout<<"Tak - 1"<<endl<<"Nie - 0"<<endl;
    bool czyWczytacZPliku;
    cin>>czyWczytacZPliku;

    if(!czyWczytacZPliku)
    {
        try
        {
        WypelnijMaciezRownanLiniowych(macierz);
        }
        catch(const char* msg)
        {
            cerr<<msg<<endl;
            return 0;
        }
    }else
    {
        try
        {
        WypelnijMaciezRownanLiniowychZpliku(macierz);
        }
        catch(const char* msg)
        {
            cerr<<msg<<endl;
            return 0;
        }
    }

    WyswietlMAcierz(macierz);
    do
    {
        cout<<"Wybierz kryteriumzatrzymania"<<endl;
        cout<<"0.Dokladnosc do epsilon"<<endl;
        cout<<"1.Maksymalnailosciteracji"<<endl;
        cin.sync();
        cin>>wyborKryteriumZatrzymania;
        cout<<wyborKryteriumZatrzymania;
    }while((wyborKryteriumZatrzymania !=0) && (wyborKryteriumZatrzymania !=1));

    cout<<"Podaj wartosc kryterium"<<endl;
    cin>>kryterium;
    macierz->setKryterium(wyborKryteriumZatrzymania);
    macierz->wybierzKryteriumZatrzymania(kryterium);
    macierz->RozwiazUkladRownanMetodaGausaSeidla();

    cout<<"Obliczone Pierwiastki"<<endl;
    for(int i=0;i<iloscNiewiadomych;i++)
        cout<<macierz->getMacierzWynikowa()[i]<<endl;
    return 0;
}
