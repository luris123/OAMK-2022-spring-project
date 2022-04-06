#include "paakayttoliittyma.h"
#include "ui_paakayttoliittyma.h"

paakayttoliittyma::paakayttoliittyma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paakayttoliittyma)
{
    ui->setupUi(this);
}

paakayttoliittyma::~paakayttoliittyma()
{
    delete ui;
}

void paakayttoliittyma::on_withdrawBtn_clicked()
{

}

