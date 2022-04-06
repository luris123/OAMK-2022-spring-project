#ifndef DLLPINCODE_H
#define DLLPINCODE_H

#include "pindialog.h"
#include "DLLPinCode_global.h"

#include <QDebug>
#include <QObject>

class DLLPINCODE_EXPORT DLLPinCode : public QObject
{
    Q_OBJECT
public:
    DLLPinCode();
    ~DLLPinCode();

    void naytaPinkoodiKayttoliittyma();


private:
    PinDialog *objectPinDialog;

public slots:
    void pinkoodiSlot(QString);

signals:
    void pinkoodiInterface(QString);
};

#endif // DLLPINCODE_H
