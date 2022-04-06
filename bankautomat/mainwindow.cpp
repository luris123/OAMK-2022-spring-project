#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    objectDLLSerialPort = new DLLSerialPort;
    //objectpaakayttoliittyma = new paakayttoliittyma;
    //objectpaakayttoliittyma -> exec();

    //objectTalletaRahaa = new TalletaRahaa;
    //objectTalletaRahaa->exec();

    objectDLLPinCode = new DLLPinCode;

    connect(objectDLLSerialPort, SIGNAL(kortinNumeroSignal(QString)),
            this, SLOT(kortinNumeroSlot(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    objectDLLPinCode->openDLLPinCode();
}

void MainWindow::kortinNumeroSlot(QString kortinnumeroDLL)
{
    qDebug() << "kortintiedot saatu dllSerialPortilta...avataan pincode käyttöliittymä";
    qDebug() << "Kortinnumero exessä: " << kortinnumeroDLL;
    //QString kortinnumero = kortinnumeroDLL??
    //asiakkaanSalasana = restistä asiakaan pinkoodi???
    objectDLLPinCode->openDLLPinCode();
}

