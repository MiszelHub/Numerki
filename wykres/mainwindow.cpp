#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qmath.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    for(double i=0;i<100.0;i++)
//    {
//        x.push_back(i/20.0);
//        y.push_back(qTan(i));
//    }

//    ui->widget->addGraph();
//    ui->widget->graph(0)->setData(x,y);
//    ui->widget->xAxis->setRange(0,1);
//    ui->widget->yAxis->setRange(-1,1);
//    ui->widget->xAxis->setLabel("x");
//    ui->widget->yAxis->setLabel("y");
//    ui->widget->replot();
    // add two new graphs and set their look:
    ui->widget->addGraph();
    ui->widget->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    //ui->widget->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
    ui->widget->addGraph();
    ui->widget->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
    // generate some points of data (y0 for first, y1 for second graph):
   // QVector<double> x1, y0, y1(250);
    for (int i=0; i<250; ++i)
    {
//      x[i] = i;
//      y0[i] = qCos(i/10.0);
      x.push_back(i);
      y0.push_back(qCos(i/10.0));
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

MainWindow::~MainWindow()
{
    QVector<double>::iterator itx;
    for(itx=x.begin();itx=x.end();++itx)
    {
        delete itx;
    }
    QVector<double>::iterator ity;
    for(ity=y0.begin();ity=y0.end();++ity)
    {
        delete ity;
    }
    delete ui;
}

double MainWindow::power(double a, double b)
{
    double pow=0;
    for(int i=0;i<b;i++)
    {
       pow+=a*a;
    }
}
