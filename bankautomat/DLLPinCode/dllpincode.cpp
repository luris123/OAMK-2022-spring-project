#include "dllpincode.h"

void DLLPinCode::openDLLPinCode()
{
    objectPinDialog = new PinDialog;
    objectPinDialog -> exec();
    DLLValue = objectPinDialog -> getPinDialogValue();

}

QString DLLPinCode::returnPinCode()
{
    return DLLValue;
}
