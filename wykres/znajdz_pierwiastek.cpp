#include "znajdz_pierwiastek.h"
#include "ui_znajdz_pierwiastek.h"
#include "wykres.h"
#include<qexception.h>
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

void newMethod()
{

}
double Znajdz_pierwiastek::MetodaBisekcji(double a, double b, double epsilon)
{
    double x1;
    bool sprawdz=true;
    qDebug("MetodaBisekcji");
    while(abs(b-a) > epsilon && sprawdz == true)
    {
        x1=(a+b)/2;
        qDebug(QString::number(x1).toStdString().c_str());
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
    qDebug("MetodaBisekcji");
    for(size_t i=0; i<max_iteracji;i++)
    {
        x1=(a+b)/2.0;
        qDebug(QString::number(x1).toStdString().c_str());

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

double Znajdz_pierwiastek::MetodaSiecznych(double a, double b, double epsilon)
{
    bool sprawdz=true;
    double x0;// = a - wsk->funkcje(a)*((b - a)/(wsk->funkcje(b) - wsk->funkcje(a)));
    double f0;
    double fA = wsk->funkcje(a);
    double fB =  wsk->funkcje(b);
qDebug("MetodaSiecznych");
    if(fA * fB < 0)
    {
        while(sprawdz == true)
        {
            x0 = a - fA * (b - a) / (fB - fA);
            f0 = wsk->funkcje(x0);
            qDebug(QString::number(x0).toStdString().c_str());
            if(fabs(b - a) < epsilon)
            {
                sprawdz = false;
            }
            else if(f0 * fA < 0)
            {
                b = x0;
                fB = f0;
            }
            else
            {
                a = x0;
                fA = f0;
            }

        }
        return x0;
    }

}

double Znajdz_pierwiastek::MetodaSiecznych(double a, double b, size_t max_iteracji)
{
    double x0;// = a - wsk->funkcje(a)*((b - a)/(wsk->funkcje(b) - wsk->funkcje(a)));
    double f0;// = wsk->funkcje(x0);
    double fA = wsk->funkcje(a);
    double fB =  wsk->funkcje(b);
qDebug("MetodaSiecznych");
    if(fA * fB < 0)
    {
        for(size_t i = 1; i <=max_iteracji; i++)
        {
            x0 = a - fA * (b - a) / (fB - fA);
            qDebug(QString::number(x0).toStdString().c_str());

            f0 = wsk->funkcje(x0);
            if(f0 * fA < 0)
            {
                b = x0;
                fB = f0;
            }
            else
            {
                a = x0;
                fA = f0;
            }

        }
        return x0;
    }
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
        if(ui->comboBox_2->currentIndex() == 2)
        {
            this->pierwiastek = MetodaSiecznych(ui->a->text().toDouble(),ui->b->text().toDouble(),ui->dokladnosc->text().toDouble());
        }
            else if(ui->comboBox_2->currentIndex() == 1)
        {
            this->pierwiastek = MetodaSiecznych(ui->a->text().toDouble(),ui->b->text().toDouble(),ui->dokladnosc->text().toUInt());
        }

    }
}


void Znajdz_pierwiastek::on_pushButton_clicked()
{


    WybierzDokladnosc();
    WyswietlPierwiastek();
    wsk->setMiejsce_zerowe(pierwiastek);
    wsk->GenerujWykres(true);
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
