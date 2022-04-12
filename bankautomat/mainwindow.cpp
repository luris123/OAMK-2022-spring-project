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

    objectpaakayttoliittyma = new paakayttoliittyma;
    objectCreditOrDebit = new creditOrDebit;
    objectNostaRahaa = new NostaRahaa;
    objectTalletaRahaa = new TalletaRahaa;

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

    connect(objectpaakayttoliittyma, SIGNAL(nostaRahaaValittu()),
            this, SLOT(nostaRahaaValittuSlot()));

    connect(objectNostaRahaa, SIGNAL(nostaRahaa(QString)),
            this, SLOT(nostaRahaaSlot(QString)));

    connect(objectTalletaRahaa, SIGNAL(talletaRahaaValittu()),
            this, SLOT(talletaRahaaValittuSlot()));

    connect(objectCreditOrDebit, SIGNAL(kirjauduUlosSignal()),
            this, SLOT(kirjauduUlosSlot()));

    connect(objectpaakayttoliittyma, SIGNAL(kirjauduUlosSignal()),
            this, SLOT(kirjauduUlosSlot()));

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
    objectDLLRESTAPI->login("0600064972", pinkoodiDLL);
}

void MainWindow::loginSlot(QString login)
{
    qDebug() << "login: " << login;
    if(login == "true")
      {       
        objectDLLRESTAPI->haeAsiakkaanTiedot("0600064972");
      }
      else if(login == "false")
      {
        objectDLLPinCode->pinkoodiVaarin();
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
    luottoraja = tiedotLista[7];

    QString str;
    foreach(str, tiedotLista)
    {
        qDebug() << str;
    };

    if(creditTilinumero == NULL)
    {
        valinta = "debit";
        objectpaakayttoliittyma->asetaTiedot(valinta, nimi, debitSaldo);
        objectpaakayttoliittyma->show();
    }
    else if(creditTilinumero != NULL)
    {
        objectCreditOrDebit->show();
    }
}

void MainWindow::tiliValittuSlot(QString tilinValinta)
{
    qDebug() << tilinValinta;
    if(tilinValinta == "debit")
    {
        valinta = tilinValinta;
        qDebug() << "debit valittu";
        objectpaakayttoliittyma->asetaTiedot(valinta, nimi, debitSaldo);
        objectpaakayttoliittyma->show();
    }
    else if(tilinValinta == "credit")
    {
        valinta = tilinValinta;
        qDebug() << "credit valittu";
        objectpaakayttoliittyma->asetaTiedot(valinta, nimi, creditSaldo);
        objectpaakayttoliittyma->show();
    }
}

void MainWindow::nostaRahaaValittuSlot()
{
    objectNostaRahaa->show();
}

void MainWindow::nostaRahaaSlot(QString nostoSumma)
{
    if(valinta == "debit")
    {
        qDebug() << "Nostetaan debit tililtä: " << nostoSumma;
        objectDLLRESTAPI->suoritaDebitNosto(id_Tili, debitTilinumero, "0600064972", debitSaldo, nostoSumma);

        debitSaldo = QString::number(debitSaldo.toFloat() - nostoSumma.toFloat());
        objectpaakayttoliittyma->asetaTiedot(valinta, nimi, debitSaldo);

    }
    else if(valinta == "credit")
    {
       qDebug() << "Nostetaan credit tililtä: " << nostoSumma;
       objectDLLRESTAPI->suoritaCreditNosto(id_Tili, creditTilinumero, "0600064972", creditSaldo, nostoSumma, luottoraja);

       creditSaldo = QString::number(creditSaldo.toFloat() - nostoSumma.toFloat());
       objectpaakayttoliittyma->asetaTiedot(valinta, nimi, creditSaldo);

    }
}

void MainWindow::talletaRahaaValittuSlot()
{
    objectTalletaRahaa->show();
}

void MainWindow::kirjauduUlosSlot()
{
    kortinnumero = nullptr;
    id_Tili = nullptr;
    id_Asiakas = nullptr;
    nimi = nullptr;
    debitTilinumero = nullptr;
    creditTilinumero = nullptr;
    debitSaldo = nullptr;
    creditSaldo = nullptr;
    valinta = nullptr;
    luottoraja = nullptr;

    delete this;
}

