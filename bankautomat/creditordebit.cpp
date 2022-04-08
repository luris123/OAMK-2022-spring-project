#include "creditordebit.h"
#include "ui_creditordebit.h"

creditOrDebit::creditOrDebit(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::creditOrDebit)
{
    ui->setupUi(this);
}

creditOrDebit::~creditOrDebit()
{
    delete ui;
    ui = nullptr;
}

void creditOrDebit::on_debit_btn_clicked()
{
    emit tilinValinta("debit");
}


void creditOrDebit::on_credit_btn_clicked()
{
    emit tilinValinta("credit");
}


void creditOrDebit::on_kirjauduUlos_btn_clicked()
{
    this->close();
}

