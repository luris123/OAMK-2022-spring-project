#include "paakayttoliittyma.h"
#include "ui_paakayttoliittyma.h"

paakayttoliittyma::paakayttoliittyma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paakayttoliittyma)
{
    ui->setupUi(this);

    objectPaaTimer = new QTimer;

    connect(objectPaaTimer, SIGNAL(timeout()),
            this, SLOT(timer_slot()));
}

paakayttoliittyma::~paakayttoliittyma()
{
    delete ui;
    delete objectPaaTimer;

    ui = nullptr;
    objectPaaTimer = nullptr;
}

void paakayttoliittyma::asetaTiedot(QString tilinValinta, QString nimi, QString saldo, QString luottoraja, QStringList tilitapahtumat)
{
    ui->listWidget->clear();

    if(tilinValinta == "credit")
    {
        ui->ownerLabel->setText(nimi);
        ui->saldoLabel1->setText("Credit Saldo: ");
        ui->saldoLabel2->setText(saldo);
        ui->luottoraja_label1->setText("Luottoraja:");
        ui->luottoraja_label2->setText(luottoraja);
        ui->listWidget->addItems(tilitapahtumat);
    }
    else if(tilinValinta == "debit")
       {
        ui->ownerLabel->setText(nimi);
        ui->saldoLabel1->setText("Debit Saldo: ");
        ui->saldoLabel2->setText(saldo);
        ui->luottoraja_label1->clear();
        ui->luottoraja_label2->clear();
        ui->listWidget->addItems(tilitapahtumat);
    }
}

void paakayttoliittyma::timer_slot()
{
    qDebug() << "Pää aika loppui";
    emit kirjauduUlosSignal();
}

void paakayttoliittyma::on_depositBtn_clicked()
{
    objectPaaTimer->stop();
    emit talletaRahaaValittu();
}

void paakayttoliittyma::on_withdrawBtn_clicked()
{
    objectPaaTimer->stop();
    emit nostaRahaaValittu();
}

void paakayttoliittyma::on_logoutBtn_clicked()
{
    this->close();
    emit kirjauduUlosSignal();
}


void paakayttoliittyma::on_ylos_btn_clicked()
{
    objectPaaTimer->start(30000);
    valinta = "ylos";
    emit tilitapahtumaValinta(valinta);
}


void paakayttoliittyma::on_alas_btn_clicked()
{
    objectPaaTimer->start(30000);
    valinta = "alas";
    emit tilitapahtumaValinta(valinta);
}

