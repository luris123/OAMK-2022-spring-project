#include "dllrestapi.h"

DLLRESTAPI::DLLRESTAPI()
{
    base_url = "https://banksimul-app.herokuapp.com";

    objectAsiakas = new asiakas(base_url);
    objectLogin = new class login(base_url);

    connect(objectLogin, SIGNAL(loginSignalToInterface(QString)),
            this, SLOT(interfaceLoginSlot(QString)));

}

DLLRESTAPI::~DLLRESTAPI()
{
    delete objectAsiakas;
    delete objectLogin;

    objectAsiakas = nullptr;
    objectLogin = nullptr;
}

void DLLRESTAPI::haeAsiakkaanTiedot()
{
    objectAsiakas->haeAsiakasTiedotRestilta();
}

void DLLRESTAPI::login(QString kortinnumero, QString pinnkoodi)
{
    objectLogin->yritaKirjautua(kortinnumero, pinnkoodi);
}

void DLLRESTAPI::interfaceLoginSlot(QString signalFromLogin)
{
    emit loginSignalToExe(signalFromLogin);
}

