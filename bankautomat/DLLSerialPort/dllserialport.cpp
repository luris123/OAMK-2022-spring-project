#include "dllserialport.h"

DLLSerialPort::DLLSerialPort(QObject *parent) : QObject(parent)
{
    objectSerialPortEngine = new SerialPortEngine;

    connect(objectSerialPortEngine, SIGNAL(kortinnumeroSignal(QString)),
            this, SLOT(kortinVastaanottoSlot(QString)));
}

DLLSerialPort::~DLLSerialPort()
{

}

void DLLSerialPort::kortinVastaanottoSlot(QString kortinNumero)
{
    qDebug() << "interface: " << kortinNumero;
    emit kortinNumeroSignal(kortinNumero);
}
