#include "dllserialport.h"

DLLSerialPort::DLLSerialPort()
{
    objectSerialPortEngine = new SerialPortEngine;

    connect(objectSerialPortEngine, SIGNAL(kortinnumeroSignal(QString)),
            this, SLOT(kortinVastaanottoSlot(QString)));
}

DLLSerialPort::~DLLSerialPort()
{
    delete objectSerialPortEngine;

    objectSerialPortEngine = nullptr;
}

void DLLSerialPort::kortinVastaanottoSlot(QString kortinNumero)
{
    emit kortinNumeroSignal(kortinNumero);
}
