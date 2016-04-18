#include <iostream>
#include "macierzrownanliniowych.h"

using namespace std;

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

    WypelnijMaciezRownanLiniowych(macierz);
    WyswietlMAcierz(macierz);
    do
    {
        cout<<"Wybierz kryteriumzatrzymania"<<endl;
        cout<<"0.Dokladnosc do epsilon"<<endl;
        cout<<"1.Maksymalnailosciteracji"<<endl;
        cin.sync();
        cin>>wyborKryteriumZatrzymania;
        cout<<wyborKryteriumZatrzymania;
    }while((wyborKryteriumZatrzymania !=1) && (wyborKryteriumZatrzymania !=2));

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
