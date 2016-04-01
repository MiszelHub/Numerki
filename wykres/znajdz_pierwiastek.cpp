#include "znajdz_pierwiastek.h"
#include "ui_znajdz_pierwiastek.h"
#include "wykres.h"

Znajdz_pierwiastek::Znajdz_pierwiastek(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Znajdz_pierwiastek)
{
    ui->setupUi(this);
}

Znajdz_pierwiastek::~Znajdz_pierwiastek()
{
    delete ui;
}

double Znajdz_pierwiastek::power(double a, double b)
{
    double pow=1;
    for(int i=0;i<b;i++)
    {
       pow*=a;
    }
    return pow;
}

double Znajdz_pierwiastek::horner(double wsp[], double st, double x)
{
    double wynik = wsp[0];

    for(int i=1.0;i<=st;i++)
      wynik = wynik*x + wsp[i];

    return wynik;
}

double Znajdz_pierwiastek::MetodaBisekcji(double a, double b, double epsilon)
{
    double x1;
    bool sprawdz=true;
    while(abs(b-a) > epsilon && sprawdz == true)
    {
        x1=(a+b)/2;
        if(wsk->funkcje(x1)==0)
        {
           sprawdz == false;
        }
        else if(wsk->funkcje(x1)*wsk->funkcje(a) <0)
        {
            b = x1;
        }
        else
        {
            a = x1;
        }
    }
    return x1;
}
double Znajdz_pierwiastek::MetodaBisekcji(double a, double b, size_t max_iteracji)
{
    double x1;

    for(size_t i=0; i<max_iteracji;i++)
    {
        x1=(a+b)/2.0;

        if(wsk->funkcje(x1)*wsk->funkcje(a) < 0)
        {
            b = x1;
        }
        else
        {
            a = x1;
        }
    }
    return x1;
}

void Znajdz_pierwiastek::WyswietlPierwiastek()
{
    ui->pierwiastek->setText(QString::number(pierwiastek));
}

bool Znajdz_pierwiastek::WybierzMetode()
{
   if(ui->comboBox->currentIndex() == 1)
   {
       return 1;
   }
   else return 0;
}

void Znajdz_pierwiastek::WybierzDokladnosc()
{
    if(WybierzMetode() == 1)
    {
        if(ui->comboBox_2->currentIndex() == 2)
        {
            this->pierwiastek = MetodaBisekcji(ui->a->text().toDouble(),ui->b->text().toDouble(),ui->dokladnosc->text().toDouble());
        }
            else if(ui->comboBox_2->currentIndex() == 1)
        {
            this->pierwiastek = MetodaBisekcji(ui->a->text().toDouble(),ui->b->text().toDouble(),ui->dokladnosc->text().toUInt());
        }
    }
    else
    {
        //MetodaSiecznych();

    }
}


void Znajdz_pierwiastek::on_pushButton_clicked()
{

//    if(ui->comboBox_2->currentIndex() == 1)
//    {
//        this->pierwiastek = MetodaBisekcji(ui->a->text().toDouble(),ui->b->text().toDouble(),ui->dokladnosc->text().toDouble());
//    }
//    else if(ui->comboBox_2->currentIndex() == 2)
//    {
//        this->pierwiastek = MetodaBisekcji(ui->a->text().toDouble(),ui->b->text().toDouble(),ui->dokladnosc->text().toUInt());
//    }
    WybierzDokladnosc();
    WyswietlPierwiastek();
}

Wykres *Znajdz_pierwiastek::getWsk() const
{
    return wsk;
}

void Znajdz_pierwiastek::setWsk(Wykres *value)
{
    wsk = value;
}

double Znajdz_pierwiastek::getPierwiastek() const
{
    return pierwiastek;
}

void Znajdz_pierwiastek::setPierwiastek(double value)
{
    pierwiastek = value;
}
