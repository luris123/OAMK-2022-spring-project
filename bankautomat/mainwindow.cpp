#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //objectpaakayttoliittyma = new paakayttoliittyma;
    //objectpaakayttoliittyma -> exec();

    //objectTalletaRahaa = new TalletaRahaa;
    //objectTalletaRahaa->exec();

    //objectNostaRahaa = new NostaRahaa;
    //objectNostaRahaa -> exec();

    objectDLLPinCode = new DLLPinCode;


    objectDLLSerialPort = new DLLSerialPort;




}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
     objectDLLPinCode->openDLLPinCode();
}

