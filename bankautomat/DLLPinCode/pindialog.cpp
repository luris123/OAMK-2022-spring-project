#include "pindialog.h"
#include "ui_pindialog.h"
#include <QDebug>
PinDialog::PinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PinDialog)
{
    ui->setupUi(this);
    ui->lineEdit->setMaxLength(4);
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
    ui -> lineEdit ->setText(PinKoodi+"1");
    PinKoodi = ui -> lineEdit -> text();
}


void PinDialog::on_A2_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"2");
    PinKoodi = ui -> lineEdit -> text();
}


void PinDialog::on_A3_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"3");
    PinKoodi = ui -> lineEdit -> text();
}


void PinDialog::on_A4_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"4");
    PinKoodi = ui -> lineEdit -> text();
}


void PinDialog::on_A5_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"5");
    PinKoodi = ui -> lineEdit -> text();
}


void PinDialog::on_A6_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"6");
    PinKoodi = ui -> lineEdit -> text();
}


void PinDialog::on_A7_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"7");
    PinKoodi = ui -> lineEdit -> text();
}


void PinDialog::on_A8_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"8");
    PinKoodi = ui -> lineEdit -> text();;
}


void PinDialog::on_A9_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"9");
    PinKoodi = ui -> lineEdit -> text();
}


void PinDialog::on_ClearBtn_clicked()
{
    ui -> lineEdit ->setText("");
    PinKoodi = ui -> lineEdit -> text();
}


void PinDialog::on_A0_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"0");
    PinKoodi = ui -> lineEdit -> text();
}


void PinDialog::on_EnterBtn_clicked()
{
    setDialogValue(PinKoodi);
    qDebug() << PinKoodi;
}
