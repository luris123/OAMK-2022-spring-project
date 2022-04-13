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

    connect(objectDLLRESTAPI, SIGNAL(tilitapahtumatToExe(QStringList)),
            this, SLOT(tilitapahtumatSlot(QStringList)));

    connect(objectCreditOrDebit, SIGNAL(tilinValinta(QString)),
            this, SLOT(tiliValittuSlot(QString)));

    connect(objectpaakayttoliittyma, SIGNAL(nostaRahaaValittu()),
            this, SLOT(nostaRahaaValittuSlot()));

    connect(objectNostaRahaa, SIGNAL(nostaRahaa(QString)),
            this, SLOT(nostaRahaaSlot(QString)));

    connect(objectpaakayttoliittyma, SIGNAL(talletaRahaaValittu()),
            this, SLOT(talletaRahaaValittuSlot()));

    connect(objectTalletaRahaa, SIGNAL(talletaRahaa(QString)),
            this, SLOT(talletaRahaaSlot(QString)));

    connect(objectCreditOrDebit, SIGNAL(kirjauduUlosSignal()),
            this, SLOT(kirjauduUlosSlot()));

    connect(objectpaakayttoliittyma, SIGNAL(tilitapahtumaValinta(QString)),
            this, SLOT(tilitapahtumaValintaSlot(QString)));

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

    objectDLLRESTAPI->haeTilitapahtumat(id_Tili, "5", "0");

    if(creditTilinumero == NULL)
    {
        valinta = "debit";
        objectpaakayttoliittyma->show();
    }
    else if(creditTilinumero != NULL)
    {
        objectCreditOrDebit->show();
    }

}

void MainWindow::tilitapahtumatSlot(QStringList paramTilitapahtumat)
{
    objectpaakayttoliittyma->puhdistaListWidget();
    qDebug() << "on taalla";

    tilitapahtumat = paramTilitapahtumat;
    objectpaakayttoliittyma->asetaTiedot(valinta, nimi, debitSaldo, tilitapahtumat);

}

void MainWindow::tiliValittuSlot(QString tilinValinta)
{
    qDebug() << tilinValinta;
    if(tilinValinta == "debit")
    {
        valinta = tilinValinta;
        qDebug() << "debit valittu";
        objectpaakayttoliittyma->asetaTiedot(valinta, nimi, debitSaldo, tilitapahtumat);
        objectpaakayttoliittyma->show();
    }
    else if(tilinValinta == "credit")
    {
        valinta = tilinValinta;
        qDebug() << "credit valittu";
        objectpaakayttoliittyma->asetaTiedot(valinta, nimi, creditSaldo, tilitapahtumat);
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
        objectDLLRESTAPI->haeTilitapahtumat(id_Tili, "10", "0");


    }
    else if(valinta == "credit")
    {
       qDebug() << "Nostetaan credit tililtä: " << nostoSumma;
       objectDLLRESTAPI->suoritaCreditNosto(id_Tili, creditTilinumero, "0600064972", creditSaldo, nostoSumma, luottoraja);

       creditSaldo = QString::number(creditSaldo.toFloat() - nostoSumma.toFloat());
       objectDLLRESTAPI->haeTilitapahtumat(id_Tili, "10", "0");


    }
}

void MainWindow::talletaRahaaValittuSlot()
{
    objectTalletaRahaa->show();
}


void MainWindow::talletaRahaaSlot(QString talletusSumma)
{
    if(valinta == "debit")
    {
        qDebug() << "Talletetaan Debit tilille " + talletusSumma;

        objectDLLRESTAPI->suoritaTalletus(valinta, id_Tili, debitTilinumero, "0600064972", talletusSumma);

        debitSaldo = QString::number(debitSaldo.toFloat() + talletusSumma.toFloat());
        objectDLLRESTAPI->haeTilitapahtumat(id_Tili, "10", QString::number(kiinteaHakuMaara));

    }
    else if(valinta == "credit")
    {
       qDebug() << "Talletetaan Credit tilille " + talletusSumma;

       objectDLLRESTAPI->suoritaTalletus(valinta, id_Tili, creditTilinumero, "0600064972", talletusSumma);

       creditSaldo = QString::number(creditSaldo.toFloat() + talletusSumma.toFloat());
       objectDLLRESTAPI->haeTilitapahtumat(id_Tili, "10", QString::number(kiinteaHakuMaara));


    }
}

void MainWindow::tilitapahtumaValintaSlot(QString valinta)
{
    qDebug() << kiinteaHakuMaara;

    if(valinta == "ylos")
    {

      if(kiinteaHakuMaara >= 0)
        {
        kiinteaHakuMaara = kiinteaHakuMaara - 10;
        objectDLLRESTAPI->haeTilitapahtumat(id_Tili, "10", QString::number(kiinteaHakuMaara));
        }
      else kiinteaHakuMaara = 0;
    }
    else if(valinta == "alas")
    {
        kiinteaHakuMaara = kiinteaHakuMaara + 10;
        objectDLLRESTAPI->haeTilitapahtumat(id_Tili, "10", QString::number(kiinteaHakuMaara));
    }

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

    delete objectDLLPinCode;
    delete objectCreditOrDebit;

    objectDLLPinCode = new DLLPinCode;
    objectCreditOrDebit = new creditOrDebit;

    connect(objectDLLPinCode, SIGNAL(pinkoodiInterface(QString)),
           this, SLOT(pinkoodiSlot(QString)));
    connect(objectCreditOrDebit, SIGNAL(tilinValinta(QString)),
            this, SLOT(tiliValittuSlot(QString)));
}

