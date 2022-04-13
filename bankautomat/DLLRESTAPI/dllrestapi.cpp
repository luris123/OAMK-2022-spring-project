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

    connect(objectProcedures, SIGNAL(tilitapahtumaSignal(QStringList)),
            this, SLOT(tilitapahtumatFromEngine(QStringList)));

}

DLLRESTAPI::~DLLRESTAPI()
{
    delete objectAsiakas;
    delete objectLogin;
    delete objectProcedures;

    objectAsiakas = nullptr;
    objectLogin = nullptr;
    objectProcedures = nullptr;
}

void DLLRESTAPI::haeAsiakkaanTiedot(QString kortinnumero)
{
    objectAsiakas->haeAsiakasTiedotRestilta(kortinnumero);
}

void DLLRESTAPI::suoritaDebitNosto(QString id, QString tilinumero, QString kortinnumero, QString debitSaldo, QString nostoSumma)
{
    objectProcedures->suoritaDebitNosto(id, tilinumero, kortinnumero, debitSaldo, nostoSumma);
}

void DLLRESTAPI::suoritaCreditNosto(QString id, QString tilinumero, QString kortinnumero, QString creditSaldo, QString nostoSumma, QString luottoraja)
{
    objectProcedures->suoritaCreditNosto(id, tilinumero, kortinnumero, creditSaldo, nostoSumma, luottoraja);
}

void DLLRESTAPI::suoritaTalletus(QString tilityyppi, QString id, QString tilinumero, QString kortinnumero, QString talletussumma)
{
    objectProcedures->suoritaTalletus(tilityyppi, id, tilinumero,kortinnumero,talletussumma);
}

void DLLRESTAPI::haeTilitapahtumat(QString id, QString maara, QString hakumaara)
{
    objectProcedures->haeTilitapahtumat(id, maara, hakumaara);
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

void DLLRESTAPI::tilitapahtumatFromEngine(QStringList tiedot)
{
    emit tilitapahtumatToExe(tiedot);
}

