#include "wykres.h"
#include "ui_wykres.h"

Wykres::Wykres(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Wykres)
{
    ui->setupUi(this);
}

Wykres::~Wykres()
{
    delete ui;
}
