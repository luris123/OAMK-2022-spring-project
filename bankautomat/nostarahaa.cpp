#include "nostarahaa.h"
#include "ui_nostarahaa.h"
#include <QDebug>

NostaRahaa::NostaRahaa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NostaRahaa)
{
    ui->setupUi(this);

    objectTimerNosta = new QTimer;
    objectTimerNosta->start(10000);

    connect(objectTimerNosta, SIGNAL(timeout()),
            this, SLOT(timer_slot_nosta()));
}

NostaRahaa::~NostaRahaa()
{
    delete ui;
    delete objectTimerNosta;
}

void NostaRahaa::timer_slot_nosta()
{
    this->close();
}

void NostaRahaa::on_A1_clicked()
{
    ui -> lineEdit ->setText(nosto+"1");
    nosto = ui -> lineEdit -> text();
    objectTimerNosta->start(10000);
}


void NostaRahaa::on_A2_clicked()
{
    ui -> lineEdit ->setText(nosto+"2");
    nosto = ui -> lineEdit -> text();
    objectTimerNosta->start(10000);
}


void NostaRahaa::on_A3_clicked()
{
    ui -> lineEdit ->setText(nosto+"3");
    nosto = ui -> lineEdit -> text();
    objectTimerNosta->start(10000);
}


void NostaRahaa::on_A4_clicked()
{
    ui -> lineEdit ->setText(nosto+"4");
    nosto = ui -> lineEdit -> text();
    objectTimerNosta->start(10000);
}


void NostaRahaa::on_A5_clicked()
{
    ui -> lineEdit ->setText(nosto+"5");
    nosto = ui -> lineEdit -> text();
    objectTimerNosta->start(10000);
}


void NostaRahaa::on_A6_clicked()
{
    ui -> lineEdit ->setText(nosto+"6");
    nosto = ui -> lineEdit -> text();
    objectTimerNosta->start(10000);
}


void NostaRahaa::on_A7_clicked()
{
    ui -> lineEdit ->setText(nosto+"7");
    nosto = ui -> lineEdit -> text();
    objectTimerNosta->start(10000);
}


void NostaRahaa::on_A8_clicked()
{
    ui -> lineEdit ->setText(nosto+"8");
    nosto = ui -> lineEdit -> text();
    objectTimerNosta->start(10000);
}


void NostaRahaa::on_A9_clicked()
{
    ui -> lineEdit ->setText(nosto+"9");
    nosto = ui -> lineEdit -> text();
    objectTimerNosta->start(10000);
}


void NostaRahaa::on_clearBtn_clicked()
{
    ui -> lineEdit ->setText("");
    nosto = ui -> lineEdit -> text();
    objectTimerNosta->start(10000);
}


void NostaRahaa::on_A0_clicked()
{
    ui -> lineEdit ->setText(nosto+"0");
    nosto = ui -> lineEdit -> text();
    objectTimerNosta->start(10000);
}


void NostaRahaa::on_enterBtn_clicked()
{
    nosto = ui -> lineEdit -> text();
    nostoValue = nosto.toFloat();
    qDebug() << nostoValue;
    emit nostaRahaa(nostoValue);

    objectTimerNosta->start(10000);
}


void NostaRahaa::on_closeBtn_clicked()
{
     this->close();
}


void NostaRahaa::on_twentyBtn_clicked()
{
    ui -> lineEdit ->setText("20");
    nosto = ui -> lineEdit -> text();
    objectTimerNosta->start(10000);
}


void NostaRahaa::on_fortyBtn_clicked()
{
    ui -> lineEdit ->setText("40");
    nosto = ui -> lineEdit -> text();
    objectTimerNosta->start(10000);
}


void NostaRahaa::on_sixtyBtn_clicked()
{
    ui -> lineEdit ->setText("60");
    nosto = ui -> lineEdit -> text();
    objectTimerNosta->start(10000);
}


void NostaRahaa::on_hundredBtn_clicked()
{
    ui -> lineEdit ->setText("100");
    nosto = ui -> lineEdit -> text();
    objectTimerNosta->start(10000);
}

