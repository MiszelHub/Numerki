#include "wykres.h"
#include "ui_wykres.h"
#include"qcustomplot.h"
#include<qmath.h>
#include<QVector>

Wykres::Wykres(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Wykres)
{
    ui->setupUi(this);
   // pierwiastek->setWsk(this);

    ui->widget->hide();
}

Wykres::~Wykres()
{
    delete ui;
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
    ui->widget->graph(0)->setPen(pen); // line color blue for first graphw
    //ui->widget->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
    ui->widget->addGraph();
   // ui->widget->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
    // generate some points of data (y0 for first, y1 for second graph):
    QVector<double> x(250), y0(250);
    for (double i=0.0,j=-125; i<250;++j, ++i)
    {
      x[i] = j;
      y0[i] = funkcje(j);
      //y0[i] = qExp(-2*j/150.0)*horner(wspo,stopien,j);
      //y0[i] = power(qSin(j),horner(wspo,stopien,j/50.0));
      //y0[i] = qTan(horner(wspo,2.0,j/5.0));
    // y0[i] = qExp(-j/150.0)*qCos(horner(wspo,stopien,j/10.0));// exponentially decaying cosine
      // x.push_back(i);
//      y0.push_back(qCos(i/10.0));

      //y1[i] = qExp(-i/150.0);              // exponential envelope
    }
    // configure right and top axis to show ticks but no labels:
    // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
    ui->widget->xAxis2->setVisible(true);
    ui->widget->xAxis2->setTickLabels(false);
    ui->widget->yAxis2->setVisible(true);
    ui->widget->yAxis2->setTickLabels(false);

    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis2, SLOT(setRange(QCPRange)));
    // pass data points to graphs:
    ui->widget->graph(0)->setData(x, y0);
    //ui->widget->graph(1)->setData(x, y1);
    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:

    ui->widget->graph(0)->rescaleAxes();
    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
    ui->widget->graph(1)->rescaleAxes(true);
    // Note: we could have also just called ui->widget->rescaleAxes(); instead
    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

}

void Wykres::Wspolczynniki()
{

    stopien = ui->lineEdit->text().toInt();
    wspo = new double[stopien+1];
   for(int i=0;i<stopien+1;i++)
   {
     wspo[i] = 1;
   }


}

double Wykres::funkcje(int j) //i - index tablicy j - argument dziedziny funkcji
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

    Wspolczynniki();
    GenerujWykres();
    ui->widget->show();
    ui->widget->replot();
}

void Wykres::on_comboBox_activated(int index)
{


}

void Wykres::on_pushButton_2_clicked()
{
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

