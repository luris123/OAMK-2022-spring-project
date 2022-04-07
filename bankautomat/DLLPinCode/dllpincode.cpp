#include "dllpincode.h"

DLLPinCode::DLLPinCode()
{
    objectPinDialog = new PinDialog;

    connect(objectPinDialog, SIGNAL(pinkoodiEngine(QString)),
            this, SLOT(pinkoodiSlot(QString)));

}

DLLPinCode::~DLLPinCode()
{
    delete objectPinDialog;
    objectPinDialog = nullptr;
}

void DLLPinCode::naytaPinkoodiKayttoliittyma()
{
    objectPinDialog->show();
}



void DLLPinCode::pinkoodiSlot(QString pinkoodiEnginelta)
{
   emit pinkoodiInterface(pinkoodiEnginelta);
}
