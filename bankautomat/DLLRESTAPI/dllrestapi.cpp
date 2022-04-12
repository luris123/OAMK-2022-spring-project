#include "dllrestapi.h"

DLLRESTAPI::DLLRESTAPI()
{
    base_url = "https://banksimul-app.herokuapp.com";

    objectAsiakas = new asiakas(base_url);
    objectLogin = new class login(base_url);
    objectProcedures = new procedures(base_url);

    connect(objectLogin, SIGNAL(loginSignalToInterface(QString)),
            this, SLOT(interfaceLoginSlot(QString)));

    connect(objectAsiakas, SIGNAL(tiedotListSignal(QStringList)),
            this, SLOT(tiedotListFromEngine(QStringList)));

}

DLLRESTAPI::~DLLRESTAPI()
{
    delete objectAsiakas;
    delete objectLogin;

    objectAsiakas = nullptr;
    objectLogin = nullptr;
}

void DLLRESTAPI::haeAsiakkaanTiedot(QString kortinnumero)
{
    objectAsiakas->haeAsiakasTiedotRestilta(kortinnumero);
}

void DLLRESTAPI::suoritaDebitNosto(QString id, QString tilinumero, QString kortinnumero, QString debitSaldo, QString nostoSumma)
{
    qDebug() << "taalla";
    objectProcedures->suoritaDebitNosto(id, tilinumero, kortinnumero, debitSaldo, nostoSumma);
}

void DLLRESTAPI::suoritaCreditNosto(QString id, QString tilinumero, QString kortinnumero, QString creditSaldo, QString nostoSumma, QString luottoraja)
{
    objectProcedures->suoritaCreditNosto(id, tilinumero, kortinnumero, creditSaldo, nostoSumma, luottoraja);
}

void DLLRESTAPI::login(QString kortinnumero, QString pinnkoodi)
{
    objectLogin->yritaKirjautua(kortinnumero, pinnkoodi);
}

void DLLRESTAPI::interfaceLoginSlot(QString signalFromLogin)
{
    emit loginSignalToExe(signalFromLogin);
}

void DLLRESTAPI::tiedotListFromEngine(QStringList tiedotList)
{
    emit tiedotListToExe(tiedotList);
}

