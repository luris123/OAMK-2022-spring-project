#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    objectDLLSerialPort = new DLLSerialPort;
    objectDLLPinCode = new DLLPinCode;
    //objectpaakayttoliittyma = new paakayttoliittyma;
    //objectpaakayttoliittyma -> exec();

    //objectTalletaRahaa = new TalletaRahaa;
    //objectTalletaRahaa->exec();

    //objectNostaRahaa = new NostaRahaa;
    //objectNostaRahaa -> exec();

    connect(objectDLLSerialPort, SIGNAL(kortinNumeroSignal(QString)),
            this, SLOT(kortinNumeroSlot(QString)));

    connect(objectDLLPinCode, SIGNAL(pinkoodiInterface(QString)),
           this, SLOT(pinkoodiSlot(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   objectDLLPinCode->naytaPinkoodiKayttoliittyma();
}

void MainWindow::kortinNumeroSlot(QString kortinnumeroDLL)
{
    qDebug() << "kortintiedot saatu dllSerialPortilta...avataan pincode käyttöliittymä";
    qDebug() << "Kortinnumero exessä: " << kortinnumeroDLL;
    //QString kortinnumero = kortinnumeroDLL??
    objectDLLPinCode->naytaPinkoodiKayttoliittyma();
}

void MainWindow::pinkoodiSlot(QString pinkoodiDLL)
{
    //restiltä joko false tai true ja tarkistetaan onko credit tiliä
    qDebug() << "pinkoodi dllPinkoodilta: " << pinkoodiDLL;
    /*if(jos pinkoodi oikein)
     * {
     * //objectDLLPinCode->suljeKayttoliittyma???
     *  if(kysytään onko credit tiliä)
     *  {
     *     Jos ei ole niin, avataan valise tili käyttöliittymä
     *  }
     * }
     * else if(pinkoodi väärin)
     * {
     *      kerrotaan dllpinkoodille että pinkoodi väärin
     *      emit pinkoodiVaarin();
     * }
     * */
}

//objectDLLRESTAPI->annaAsiakkaanTiedot();
//objectDLLRESTAPI->annaTilinTiedot();
