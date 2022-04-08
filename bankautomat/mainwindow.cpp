#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    objectDLLSerialPort = new DLLSerialPort;
    objectDLLPinCode = new DLLPinCode;
    objectDLLRESTAPI = new DLLRESTAPI;

   // objectNostaRahaa = new NostaRahaa;
    objectCreditOrDebit = new creditOrDebit();

    connect(objectDLLSerialPort, SIGNAL(kortinNumeroSignal(QString)),
            this, SLOT(kortinNumeroSlot(QString)));

    connect(objectDLLPinCode, SIGNAL(pinkoodiInterface(QString)),
           this, SLOT(pinkoodiSlot(QString)));

    connect(objectDLLRESTAPI, SIGNAL(loginSignalToExe(QString)),
            this, SLOT(loginSlot(QString)));

    connect(objectDLLRESTAPI, SIGNAL(tiedotListToExe(QStringList)),
            this, SLOT(asiakasTiedotSlot(QStringList)));

    connect(objectCreditOrDebit, SIGNAL(tilinValinta(QString)),
            this, SLOT(tiliValittuSlot(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectDLLSerialPort;
    delete objectDLLPinCode;
    delete objectDLLRESTAPI;

    ui = nullptr;
    objectDLLSerialPort = nullptr;
    objectDLLPinCode = nullptr;
    objectDLLRESTAPI = nullptr;
}


void MainWindow::on_pushButton_clicked()
{
   objectDLLPinCode->naytaPinkoodiKayttoliittyma();
}

void MainWindow::kortinNumeroSlot(QString kortinnumeroDLL)
{
    qDebug() << "Kortinnumero exessä: " << kortinnumeroDLL;
    kortinnumero = kortinnumeroDLL;
    objectDLLPinCode->naytaPinkoodiKayttoliittyma();
}

void MainWindow::pinkoodiSlot(QString pinkoodiDLL)
{
    qDebug() << "syötetty pinkoodi exessä: " << pinkoodiDLL;
    objectDLLRESTAPI->login(kortinnumero, pinkoodiDLL);
}

void MainWindow::loginSlot(QString login)
{
    qDebug() << "login: " << login;
    if(login == "true")
      {       
        objectDLLRESTAPI->haeAsiakkaanTiedot(kortinnumero);
      }
      else if(login == "false")
      {

      }
}

void MainWindow::asiakasTiedotSlot(QStringList tiedotLista)
{
    id_Tili = tiedotLista[0];
    id_Asiakas= tiedotLista[1];
    nimi = tiedotLista[2];
    debitTilinumero = tiedotLista[3];
    creditTilinumero = tiedotLista[4];
    debitSaldo = tiedotLista[5];
    creditSaldo = tiedotLista[6];

    QString str;
    foreach(str, tiedotLista)
    {
        qDebug() << str;
    };

    if(creditTilinumero == NULL)
    {
        valinta = "debit";
        objectpaakayttoliittyma = new paakayttoliittyma(NULL, "debit", nimi, debitSaldo, id_Tili);

        connect(objectpaakayttoliittyma, SIGNAL(nostaRahaaSignal(float)),
                this, SLOT(nostaRahaaSlot(float)));

        objectpaakayttoliittyma->show();
    }
    else if(creditTilinumero != NULL)
    {
        objectCreditOrDebit->show();
    }
}

void MainWindow::tiliValittuSlot(QString tilinValinta)
{
    if(tilinValinta == "debit")
    {
        valinta = tilinValinta;
        objectpaakayttoliittyma = new paakayttoliittyma(NULL, "debit", nimi, debitSaldo, id_Tili);

        connect(objectpaakayttoliittyma, SIGNAL(nostaRahaaSignal(float)),
                this, SLOT(nostaRahaaSlot(float)));

        objectpaakayttoliittyma->show();
    }
    else if(tilinValinta == "credit")
    {
        valinta = tilinValinta;
        objectpaakayttoliittyma = new paakayttoliittyma(NULL, "credit", nimi, creditSaldo, id_Tili);

        connect(objectpaakayttoliittyma, SIGNAL(nostaRahaaSignal(float)),
                this, SLOT(nostaRahaaSlot(float)));

        objectpaakayttoliittyma->show();
    }
}

void MainWindow::nostaRahaaSlot(float nostoSumma)
{
    if(valinta == "debit")
    {
        QString strNostoSumma = QString::number(nostoSumma);
        objectDLLRESTAPI->suoritaDebitNosto(id_Tili, debitTilinumero, kortinnumero, debitSaldo, strNostoSumma);

        qDebug() << "Nostetaan debit tililtä: " << nostoSumma;
    }
    else if(valinta == "credit")
    {
       qDebug() << "Nostetaan credit tililtä: " << nostoSumma;
    }
}

