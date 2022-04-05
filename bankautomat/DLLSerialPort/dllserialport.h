#ifndef DLLSERIALPORT_H
#define DLLSERIALPORT_H

#include "DLLSerialPort_global.h"
#include <QObject>

#include "serialportengine.h"

class DLLSERIALPORT_EXPORT DLLSerialPort : public QObject
{
    Q_OBJECT

public:
    DLLSerialPort(QObject *parent = nullptr);
    ~DLLSerialPort();

public slots:
    void kortinVastaanottoSlot(QString);

signals:
    void kortinNumeroSignal(QString);

private:
    SerialPortEngine *objectSerialPortEngine;
};

#endif // DLLSERIALPORT_H
