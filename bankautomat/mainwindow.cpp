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

    connect(objectDLLSerialPort, SIGNAL(kortinNumeroSignal(QString)),
            this, SLOT(kortinNumeroSlot(QString)));

    connect(objectDLLPinCode, SIGNAL(pinkoodiInterface(QString)),
           this, SLOT(pinkoodiSlot(QString)));

    connect(objectDLLRESTAPI, SIGNAL(loginSignalToExe(QString)),
            this, SLOT(loginSlot(QString)));
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
    if(login == "true")
      {
        objectDLLRESTAPI->haeAsiakkaanTiedot();

      }
      else if(login == "false")
      {

      }
}

