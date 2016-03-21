#include "mainwindow.h"
#include "wykres.h"
#include"znajdz_pierwiastek.h"
#include <QApplication>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Wykres w;

    w.show();

    return a.exec();
}
