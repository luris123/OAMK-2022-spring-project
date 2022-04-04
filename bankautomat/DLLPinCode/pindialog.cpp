#include "pindialog.h"
#include "ui_pindialog.h"

PinDialog::PinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PinDialog)
{
    ui->setupUi(this);
}

PinDialog::~PinDialog()
{
    delete ui;
}

QString PinDialog::getPinDialogValue()
{
    return dialogValue;
}

void PinDialog::setDialogValue(QString a)
{
    dialogValue = a;
}

void PinDialog::on_A1_clicked()
{
    ui -> lineEdit ->setText("1");

}


void PinDialog::on_A2_clicked()
{

}


void PinDialog::on_A3_clicked()
{

}


void PinDialog::on_A4_clicked()
{

}


void PinDialog::on_A5_clicked()
{

}


void PinDialog::on_A6_clicked()
{

}


void PinDialog::on_A7_clicked()
{

}


void PinDialog::on_A8_clicked()
{

}


void PinDialog::on_A9_clicked()
{

}


void PinDialog::on_ClearBtn_clicked()
{

}


void PinDialog::on_A0_clicked()
{

}


void PinDialog::on_EnterBtn_clicked()
{
    QString a = ui -> lineEdit -> text();
    setDialogValue(a);
}
