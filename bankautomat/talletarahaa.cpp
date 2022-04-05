#include "talletarahaa.h"
#include "ui_talletarahaa.h"

TalletaRahaa::TalletaRahaa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TalletaRahaa)
{
    ui->setupUi(this);
}

TalletaRahaa::~TalletaRahaa()
{
    delete ui;
}

float TalletaRahaa::getTalletaRahaaValue()    // testaamista varten osa
{
    return RahaValue;
}

void TalletaRahaa::setRahaValue(float a)
{
    RahaValue = RahaValue + a;
    qDebug() << getTalletaRahaaValue();
}

void TalletaRahaa::on_A1_clicked()
{
    ui -> lineEdit ->setText(TempText+"1");
    TempText = ui -> lineEdit -> text();
}


void TalletaRahaa::on_A2_clicked()
{
    ui -> lineEdit ->setText(TempText+"2");
    TempText = ui -> lineEdit -> text();
}


void TalletaRahaa::on_A3_clicked()
{
    ui -> lineEdit ->setText(TempText+"3");
    TempText = ui -> lineEdit -> text();
}


void TalletaRahaa::on_A4_clicked()
{
    ui -> lineEdit ->setText(TempText+"4");
    TempText = ui -> lineEdit -> text();
}


void TalletaRahaa::on_A5_clicked()
{
    ui -> lineEdit ->setText(TempText+"5");
    TempText = ui -> lineEdit -> text();
}


void TalletaRahaa::on_A6_clicked()
{
    ui -> lineEdit ->setText(TempText+"6");
    TempText = ui -> lineEdit -> text();
}


void TalletaRahaa::on_A7_clicked()
{
    ui -> lineEdit ->setText(TempText+"7");
    TempText = ui -> lineEdit -> text();
}


void TalletaRahaa::on_A8_clicked()
{
    ui -> lineEdit ->setText(TempText+"8");
    TempText = ui -> lineEdit -> text();
}


void TalletaRahaa::on_A9_clicked()
{
    ui -> lineEdit ->setText(TempText+"9");
    TempText = ui -> lineEdit -> text();
}


void TalletaRahaa::on_ClearBtn_clicked()
{
    ui -> lineEdit ->setText("");
    TempText = ui -> lineEdit -> text();
}


void TalletaRahaa::on_A0_clicked()
{
    ui -> lineEdit ->setText(TempText+"0");
    TempText = ui -> lineEdit -> text();
}


void TalletaRahaa::on_EnterBtn_clicked()
{
    TempText = ui -> lineEdit -> text();
    qDebug() << TempText;
    setRahaValue(TempText.toDouble());
}

void TalletaRahaa::on_SuljeBtn_clicked()
{
    this->close();
}

void TalletaRahaa::on_DecimalBtn_clicked()
{
    ui -> lineEdit ->setText(TempText+".");
    TempText = ui -> lineEdit -> text();
}

void TalletaRahaa::on_BackBtn_clicked()
{
    TempText = TempText.remove(TempText.length()-1, TempText.length());
    ui -> lineEdit ->setText(TempText);
}
