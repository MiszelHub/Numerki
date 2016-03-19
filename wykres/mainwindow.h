#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qcustomplot.h>
#include<QVector>

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

private:
    Ui::MainWindow *ui;
//     QVector<double>x[250], y0[250];


};

#endif // MAINWINDOW_H
