#include "wykres.h"
#include "ui_wykres.h"
#include"qcustomplot.h"
#include<qmath.h>
#include<QVector>
#include<string>
using namespace std;
Wykres::Wykres(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Wykres)
{
    ui->setupUi(this);

}

Wykres::~Wykres()
{

    delete ui;
    delete pierwiastek;
}

double Wykres::power(double a, double b)
{
    double pow=1;
    for(int i=0;i<b;i++)
    {
       pow*=a;
    }
    return pow;
}

double Wykres::horner(double wsp[], double st, double x)
{
    double wynik = wsp[0];

    for(int i=1.0;i<=st;i++)
      wynik = wynik*x + wsp[i];

    return wynik;
}

void Wykres::GenerujWykres()
{
    ui->widget->addGraph();
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::blue);
    ui->widget->graph(0)->setPen(pen);
    //ui->widget->addGraph();

    QVector<double> x(250), y0(250);
    for (double i=0.0,j=-125; i<250;++j, ++i)
    {
      x[i] = j;
      y0[i] = funkcje(j);
    }
    // configure right and top axis to show ticks but no labels:

    ui->widget->xAxis2->setVisible(true);
    ui->widget->xAxis2->setTickLabels(false);
    ui->widget->yAxis2->setVisible(true);
    ui->widget->yAxis2->setTickLabels(false);

    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis2, SLOT(setRange(QCPRange)));
    // pass data points to graphs:
    ui->widget->graph(0)->setData(x, y0);
    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:

    ui->widget->graph(0)->rescaleAxes();

    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

}

void Wykres::UstawWspolczynniki()
{

    stopien = ui->lineEdit->text().toDouble();
    wspo = new double[stopien+1];
   for(int i=0;i<stopien+1;i++)
   {
     wspo[i] = i;
   }
//   string orbits;
//   orbits = ui->wspolczynniki->text().toStdString();
//   string::size_type  offset; // alias of size_t
//  //size_t rozmiar=4;
//  //double *wspolczynniki = new double[rozmiar];
//  wspo[0] = std::stod (&orbits[0],&offset);
//  for(size_t i=1;i<stopien;i++)
//  {
//      wspo[i] = std::stod (orbits.substr(i*offset));
//  }



}

double Wykres::funkcje(int j) // j - argument dziedziny funkcji
{
    if(ui->comboBox->currentIndex() == 0)
    {
        funkcja = qExp(-j/150.0)*qCos(horner(wspo,stopien,j/10.0));
    }
    if(ui->comboBox->currentIndex() == 1)
    {
        funkcja = qTan(horner(wspo,stopien,j/5.0));
    }
    if(ui->comboBox->currentIndex() == 2)
    {
        funkcja = power(qSin(j),horner(wspo,stopien,j/50.0));
    }
    return funkcja;
}

void Wykres::on_pushButton_clicked()
{

    UstawWspolczynniki();
    GenerujWykres();
    ui->widget->show();
    ui->widget->replot();
}

void Wykres::on_comboBox_activated(int index)
{


}

void Wykres::on_pushButton_2_clicked()
{
    pierwiastek = new Znajdz_pierwiastek;
    pierwiastek->setWsk(this);
    pierwiastek->show();
}

Znajdz_pierwiastek *Wykres::getPierwiastek() const
{
    return pierwiastek;
}

void Wykres::setPierwiastek(Znajdz_pierwiastek *value)
{
    pierwiastek = value;
}

double *Wykres::getWspo() const
{
    return wspo;
}

void Wykres::setWspo(double *value)
{
    wspo = value;
}

int Wykres::getStopien() const
{
    return stopien;
}

void Wykres::setStopien(int value)
{
    stopien = value;
}

