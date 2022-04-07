#include "creditordebit.h"
#include "ui_creditordebit.h"

creditOrDebit::creditOrDebit(QString paramNimi, QString paramDebitSaldo, QString paramCreditSaldo) :
    ui(new Ui::creditOrDebit)
{
    ui->setupUi(this);

    nimi = paramNimi;
    debitSaldo = paramDebitSaldo;
    creditSaldo = paramCreditSaldo;
}

creditOrDebit::~creditOrDebit()
{
    delete ui;
}

void creditOrDebit::on_debit_btn_clicked()
{
    objectPaakayttoliittyma = new paakayttoliittyma(false, nimi, debitSaldo);
    objectPaakayttoliittyma->show();
}


void creditOrDebit::on_credit_btn_clicked()
{
    objectPaakayttoliittyma = new paakayttoliittyma(true, nimi, creditSaldo);
    objectPaakayttoliittyma->show();
}


void creditOrDebit::on_kirjauduUlos_btn_clicked()
{

}

