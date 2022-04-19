#include "paakayttoliittyma.h"
#include "ui_paakayttoliittyma.h"

paakayttoliittyma::paakayttoliittyma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paakayttoliittyma)
{
    ui->setupUi(this);
  /*
    objectTimer = new QTimer;
    objectTimer->start(30000);
    qDebug() << "Pää aika aloitettu";

     connect(objectTimer, SIGNAL(timeout()),
            this, SLOT(timer_slot())); */

}

paakayttoliittyma::~paakayttoliittyma()
{
    delete ui;
    delete objectTimer;
}

void paakayttoliittyma::asetaTiedot(QString tilinValinta, QString nimi, QString saldo, QStringList tilitapahtumat)
{

    if(tilinValinta == "credit")
    {
        ui->ownerLabel->setText(nimi);
        ui->saldoLabel1->setText("Credit Saldo: ");
        ui->saldoLabel2->setText(saldo);
        ui->listWidget->addItems(tilitapahtumat);
    }
    else if(tilinValinta == "debit")
       {
        ui->ownerLabel->setText(nimi);
        ui->saldoLabel1->setText("Debit Saldo: ");
        ui->saldoLabel2->setText(saldo);
        ui->listWidget->addItems(tilitapahtumat);
    }
}

void paakayttoliittyma::puhdistaListWidget()
{
    ui->listWidget->clear();
}

int paakayttoliittyma::tarkistaListWidget()
{
    return ui->listWidget->count();
}


void paakayttoliittyma::timer_slot()
{
   // qDebug() << "Pää aika loppui";
  //  this->close();
}

void paakayttoliittyma::on_depositBtn_clicked()
{

   emit talletaRahaaValittu();
}

void paakayttoliittyma::on_withdrawBtn_clicked()
{
    emit nostaRahaaValittu();
}

void paakayttoliittyma::on_logoutBtn_clicked()
{
    this->close();
    emit kirjauduUlosSignal();
}


void paakayttoliittyma::on_ylos_btn_clicked()
{
    valinta = "ylos";
    emit tilitapahtumaValinta(valinta);
    ui->listWidget->count();
}


void paakayttoliittyma::on_alas_btn_clicked()
{
    valinta = "alas";
    emit tilitapahtumaValinta(valinta);
}

