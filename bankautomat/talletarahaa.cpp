#include "talletarahaa.h"
#include "ui_talletarahaa.h"

TalletaRahaa::TalletaRahaa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TalletaRahaa)
{
    ui->setupUi(this);

    objectTimerTalleta = new QTimer;
    objectTimerTalleta->start(10000);

    connect(objectTimerTalleta, SIGNAL(timeout()),
            this, SLOT(timer_slot_talleta()));
}

TalletaRahaa::~TalletaRahaa()
{
    delete ui;
    delete objectTimerTalleta;

    ui = nullptr;
    objectTimerTalleta = nullptr;

}


void TalletaRahaa::timer_slot_talleta()
{
    emit PaaTimerTSignal();
    this->close();
}

void TalletaRahaa::on_A1_clicked()
{
    ui -> lineEdit ->setText(talletusSumma+"1");
    talletusSumma = ui -> lineEdit -> text();
    objectTimerTalleta->start(10000);
}


void TalletaRahaa::on_A2_clicked()
{
    ui -> lineEdit ->setText(talletusSumma+"2");
    talletusSumma = ui -> lineEdit -> text();
    objectTimerTalleta->start(10000);
}


void TalletaRahaa::on_A3_clicked()
{
    ui -> lineEdit ->setText(talletusSumma+"3");
    talletusSumma = ui -> lineEdit -> text();
    objectTimerTalleta->start(10000);
}


void TalletaRahaa::on_A4_clicked()
{
    ui -> lineEdit ->setText(talletusSumma+"4");
    talletusSumma = ui -> lineEdit -> text();
    objectTimerTalleta->start(10000);
}


void TalletaRahaa::on_A5_clicked()
{
    ui -> lineEdit ->setText(talletusSumma+"5");
    talletusSumma = ui -> lineEdit -> text();
    objectTimerTalleta->start(10000);
}


void TalletaRahaa::on_A6_clicked()
{
    ui -> lineEdit ->setText(talletusSumma+"6");
    talletusSumma = ui -> lineEdit -> text();
    objectTimerTalleta->start(10000);
}


void TalletaRahaa::on_A7_clicked()
{
    ui -> lineEdit ->setText(talletusSumma+"7");
    talletusSumma = ui -> lineEdit -> text();
    objectTimerTalleta->start(10000);
}


void TalletaRahaa::on_A8_clicked()
{
    ui -> lineEdit ->setText(talletusSumma+"8");
    talletusSumma = ui -> lineEdit -> text();
    objectTimerTalleta->start(10000);
}


void TalletaRahaa::on_A9_clicked()
{
    ui -> lineEdit ->setText(talletusSumma+"9");
    talletusSumma = ui -> lineEdit -> text();
    objectTimerTalleta->start(10000);
}


void TalletaRahaa::on_ClearBtn_clicked()
{
    ui -> lineEdit ->setText("");
    talletusSumma = ui -> lineEdit -> text();
    objectTimerTalleta->start(10000);
}


void TalletaRahaa::on_A0_clicked()
{
    ui -> lineEdit ->setText(talletusSumma+"0");
    talletusSumma = ui -> lineEdit -> text();
    objectTimerTalleta->start(10000);
}


void TalletaRahaa::on_EnterBtn_clicked()
{
    talletusSumma = ui -> lineEdit -> text();
    emit talletaRahaa(talletusSumma);
    objectTimerTalleta->start(10000);
    ui->lineEdit->clear();
    talletusSumma.clear();
}

void TalletaRahaa::on_SuljeBtn_clicked()
{
    emit PaaTimerTSignal();
    this->close();
}

void TalletaRahaa::on_DecimalBtn_clicked()
{
    ui -> lineEdit ->setText(talletusSumma+".");
    talletusSumma = ui -> lineEdit -> text();
    objectTimerTalleta->start(10000);
}

void TalletaRahaa::on_BackBtn_clicked()
{
    talletusSumma = talletusSumma.remove(talletusSumma.length()-1, talletusSumma.length());
    ui -> lineEdit ->setText(talletusSumma);
    objectTimerTalleta->start(10000);
}
