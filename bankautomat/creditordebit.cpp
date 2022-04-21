#include "creditordebit.h"
#include "ui_creditordebit.h"

creditOrDebit::creditOrDebit(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::creditOrDebit)
{
    ui->setupUi(this);

    objectTimerCredDeb = new QTimer;

    connect(objectTimerCredDeb, SIGNAL(timeout()),
            this, SLOT(timer_slot_CredDeb()));
}

creditOrDebit::~creditOrDebit()
{
    delete ui;
    delete objectTimerCredDeb;

    ui = nullptr;
    objectTimerCredDeb = nullptr;
}

void creditOrDebit::timer_slot_CredDeb()
{
    this->close();
}

void creditOrDebit::on_debit_btn_clicked()
{
    emit tilinValinta("debit");
    objectTimerCredDeb->start(10000);
}

void creditOrDebit::on_credit_btn_clicked()
{
    emit tilinValinta("credit");
    objectTimerCredDeb->start(10000);
}

void creditOrDebit::on_kirjauduUlos_btn_clicked()
{
    this->close();
    emit kirjauduUlosSignal();
}
