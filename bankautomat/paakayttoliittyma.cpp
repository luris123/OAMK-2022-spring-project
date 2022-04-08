#include "paakayttoliittyma.h"
#include "ui_paakayttoliittyma.h"

paakayttoliittyma::paakayttoliittyma(QWidget *parent, QString tilinValinta, QString nimi, QString saldo, QString paramId_tili) :
    QDialog(parent),
    ui(new Ui::paakayttoliittyma)
{
    ui->setupUi(this);

    id_tili = paramId_tili;

    if(tilinValinta == "credit")
    {
        ui->ownerLabel->setText(nimi);
        ui->saldoLabel1->setText("Credit Saldo: ");
        ui->saldoLabel2->setText(saldo);
    }
    else if(tilinValinta == "debit")
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

    connect(objectNostaRahaa, SIGNAL(nostaRahaa(float)),
            this, SLOT(nostaRahaaSlot(float)));

}

paakayttoliittyma::~paakayttoliittyma()
{
    delete ui;
    delete objectTalletaRahaa;
    delete objectNostaRahaa;
    delete objectTimer;
}

void paakayttoliittyma::nostaRahaaSlot(float nostoValue)
{
    emit nostaRahaaSignal(nostoValue);
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
    objectNostaRahaa -> show();
    objectTimer->start(30000);
}

void paakayttoliittyma::on_logoutBtn_clicked()
{
    this->close();
}


void paakayttoliittyma::on_ylos_btn_clicked()
{

}


void paakayttoliittyma::on_alas_btn_clicked()
{

}

