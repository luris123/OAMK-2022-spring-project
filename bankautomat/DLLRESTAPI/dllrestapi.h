#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H

#include "DLLRESTAPI_global.h"

#include <QObject>

#include "asiakas.h"
#include "login.h"

class DLLRESTAPI_EXPORT DLLRESTAPI : public QObject
{
    Q_OBJECT
public:
    DLLRESTAPI();
    ~DLLRESTAPI();

    void haeAsiakkaanTiedot();

    void login(QString, QString);

private:
    asiakas *objectAsiakas;
    class login *objectLogin;

    QString base_url;


signals:
    void loginSignalToExe(QString);

private slots:
    void interfaceLoginSlot(QString);
};

#endif // DLLRESTAPI_H
