#ifndef SERIALPORTENGINE_H
#define SERIALPORTENGINE_H

#include <QObject>

#include <QSerialPort>
#include <QTimer>
#include <QString>
#include <QList>
#include <QDebug>

class SerialPortEngine : public QObject
{
    Q_OBJECT
public:
    SerialPortEngine();
    ~SerialPortEngine();

signals:
    void kortinnumeroSignal(QString);

public slots:
    void readSerialSlot();
private:
    QSerialPort *porttiOlio;
    QTimer *objectQTimer;
};

#endif // SERIALPORTENGINE_H

