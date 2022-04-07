#include "dllrestapi.h"

DLLRESTAPI::DLLRESTAPI()
{
    base_url = "https://banksimul-app.herokuapp.com";

    objectAsiakas = new asiakas(base_url);
    objectLogin = new class login(base_url);

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

