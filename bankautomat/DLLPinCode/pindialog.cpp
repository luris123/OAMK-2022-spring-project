#include "pindialog.h"
#include "ui_pindialog.h"
#include <QDebug>
PinDialog::PinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PinDialog)
{
    ui->setupUi(this);
    ui->lineEdit->setMaxLength(4);

    objectTimerPinDialog = new QTimer;

    connect(objectTimerPinDialog, SIGNAL(timeout()),
            this, SLOT(timer_slot_pindialog()));
}

PinDialog::~PinDialog()
{
    delete ui;
    ui = nullptr;
    delete objectTimerPinDialog;
}

void PinDialog::pinkoodiVaarin()
{
    yritys = yritys - 1;
    ui->vaarin_label->setText("Pinkoodi väärin. " + QString::number(yritys) + " yritys(tä) jäljellä");
    if (yritys == 0)
    {
        this->close();
        yritys = 3;
        ui -> vaarin_label -> clear();
        ui -> lineEdit -> clear();
        PinKoodi.clear();
    }
}

void PinDialog::timer_slot_pindialog()
{
    this->close();
}


void PinDialog::on_A1_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"1");
    PinKoodi = ui -> lineEdit -> text();
    objectTimerPinDialog->start(10000);
}


void PinDialog::on_A2_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"2");
    PinKoodi = ui -> lineEdit -> text();
    objectTimerPinDialog->start(10000);
}


void PinDialog::on_A3_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"3");
    PinKoodi = ui -> lineEdit -> text();
    objectTimerPinDialog->start(10000);
}


void PinDialog::on_A4_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"4");
    PinKoodi = ui -> lineEdit -> text();
    objectTimerPinDialog->start(10000);
}


void PinDialog::on_A5_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"5");
    PinKoodi = ui -> lineEdit -> text();
    objectTimerPinDialog->start(10000);
}


void PinDialog::on_A6_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"6");
    PinKoodi = ui -> lineEdit -> text();
    objectTimerPinDialog->start(10000);
}


void PinDialog::on_A7_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"7");
    PinKoodi = ui -> lineEdit -> text();
    objectTimerPinDialog->start(10000);
}


void PinDialog::on_A8_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"8");
    PinKoodi = ui -> lineEdit -> text();
    objectTimerPinDialog->start(10000);
}


void PinDialog::on_A9_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"9");
    PinKoodi = ui -> lineEdit -> text();
    objectTimerPinDialog->start(10000);
}


void PinDialog::on_ClearBtn_clicked()
{
    ui -> lineEdit ->setText("");
    PinKoodi = ui -> lineEdit -> text();
    objectTimerPinDialog->start(10000);
}


void PinDialog::on_A0_clicked()
{
    ui -> lineEdit ->setText(PinKoodi+"0");
    PinKoodi = ui -> lineEdit -> text();
    objectTimerPinDialog->start(10000);
}


void PinDialog::on_EnterBtn_clicked()
{
    emit pinkoodiEngine(PinKoodi);
    objectTimerPinDialog->start(10000);
}
