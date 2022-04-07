#include "paakayttoliittyma.h"
#include "ui_paakayttoliittyma.h"

paakayttoliittyma::paakayttoliittyma(bool credit, QString nimi, QString saldo) :
    ui(new Ui::paakayttoliittyma)
{
    ui->setupUi(this);

    if(credit == true)
    {
        ui->ownerLabel->setText(nimi);
        ui->saldoLabel1->setText("Credit Saldo: ");
        ui->saldoLabel2->setText(saldo);
    }
    else if(credit == false)
       {
        ui->ownerLabel->setText(nimi);
        ui->saldoLabel1->setText("Debit Saldo: ");
        ui->saldoLabel2->setText(saldo);
       }

    objectTalletaRahaa = new TalletaRahaa;
    objectNostaRahaa = new NostaRahaa;
    objectTimer = new QTimer;
    objectTimer->start(30000);
    qDebug() << "Pää aika aloitettu";

    connect(objectTimer, SIGNAL(timeout()),
            this, SLOT(timer_slot()));

}

paakayttoliittyma::~paakayttoliittyma()
{
    delete ui;
    delete objectTalletaRahaa;
    delete objectNostaRahaa;
    delete objectTimer;
}

void paakayttoliittyma::timer_slot()
{
    qDebug() << "Pää aika loppui";
    this->close();
}

void paakayttoliittyma::on_depositBtn_clicked()
{
    objectTimer->stop();
    objectTalletaRahaa -> exec();
    objectTimer->start(30000);
}

void paakayttoliittyma::on_withdrawBtn_clicked()
{
    objectTimer->stop();
    objectNostaRahaa -> exec();
    objectTimer->start(30000);
}

void paakayttoliittyma::on_logoutBtn_clicked()
{
    this->close();
}


