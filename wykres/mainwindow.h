#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qcustomplot.h>
#include<QVector>
#include"znajdz_pierwiastek.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double power(double a, double b);
    double horner(double wsp[], double st, double x);
    void GenerujWykres();
    void reloadWykres();
    void setPierwiastek(Znajdz_pierwiastek &pierwiastek);
private slots:
    void on_pushButton_clicked();



private:
    Ui::MainWindow *ui;
    double *wspo;
    Znajdz_pierwiastek pierwiastek;
//     QVector<double>x[250], y0[250];


};

#endif // MAINWINDOW_H
