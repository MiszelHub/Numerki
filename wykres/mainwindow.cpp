#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qmath.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widget->hide();
    pierwiastek.show();
    ui->lineEdit->setText(QString::number(11.0));


}


MainWindow::~MainWindow()
{

    delete ui;
}

double MainWindow::power(double a, double b)
{
    double pow=1;
    for(int i=0;i<b;i++)
    {
       pow*=a;
    }
    return pow;
}

double MainWindow::horner(double wsp[], double st, double x)
{
    double wynik = wsp[0];

    for(int i=1.0;i<=st;i++)
      wynik = wynik*x + wsp[i];

    return wynik;
}

void MainWindow::GenerujWykres()
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
    for (double i=0.0; i<250.0; ++i)
    {
      x[i] = i;
      //y0[i] = power(qSin(i),horner(wspo,2.0,i/50.0));
       y0[i] = qTan(horner(wspo,2.0,i));
//      x.push_back(i);
//      y0.push_back(qCos(i/10.0));
      //y0[i] = qExp(-i/150.0)*qCos(i/10.0);// exponentially decaying cosine
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

void MainWindow::reloadWykres()
{

        ui->widget->hide();
        ui->widget->show();

}

void MainWindow::setPierwiastek(Znajdz_pierwiastek &pierwiastek)
{

}

void MainWindow::on_pushButton_clicked()
{
    pierwiastek.show();
    int stopien = ui->lineEdit->text().toInt();
    wspo = new double[stopien];
   for(int i=0;i<stopien;i++)
   {
     wspo[i] = 1;
   }

    GenerujWykres();
    reloadWykres();
}

