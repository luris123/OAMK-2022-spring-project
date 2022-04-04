#ifndef DLLPINCODE_H
#define DLLPINCODE_H

#include "pindialog.h"
#include "DLLPinCode_global.h"

class DLLPINCODE_EXPORT DLLPinCode
{
public:
    void openDLLPinCode();
    QString returnPinCode();

private:
    PinDialog *objectPinDialog;
    QString DLLValue;
};

#endif // DLLPINCODE_H
