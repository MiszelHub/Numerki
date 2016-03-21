#include "znajdz_pierwiastek.h"
#include "ui_znajdz_pierwiastek.h"

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
