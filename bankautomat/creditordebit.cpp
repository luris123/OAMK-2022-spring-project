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
}
