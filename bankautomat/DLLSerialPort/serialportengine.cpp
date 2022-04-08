#include "serialportengine.h"

SerialPortEngine::SerialPortEngine()
{

    objectQTimer = new QTimer;
    porttiOlio = new QSerialPort;

    QObject::connect(objectQTimer, SIGNAL(timeout()),
            this, SLOT(readSerialSlot()));

    QString portti = "COM4";

    porttiOlio->setPortName(portti);
    qDebug() << portti << " on auki: " <<  porttiOlio->open(QIODevice::ReadOnly);
    objectQTimer->start(1000);
}

SerialPortEngine::~SerialPortEngine()
{

    delete porttiOlio;
    delete objectQTimer;
    porttiOlio = nullptr;
    objectQTimer = nullptr;
}

void SerialPortEngine::readSerialSlot()
{
    QString kortinnumero = porttiOlio->readAll();
    if(!kortinnumero.isEmpty())
    {
        kortinnumero.remove(0, 3);
        kortinnumero.remove(10, 4);
        emit  kortinnumeroSignal(kortinnumero);
        objectQTimer->stop();
    }

}
