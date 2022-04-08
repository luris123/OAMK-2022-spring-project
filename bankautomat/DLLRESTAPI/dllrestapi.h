#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H

#include "DLLRESTAPI_global.h"

#include <QObject>

#include "asiakas.h"
#include "login.h"
#include "procedures.h"

class DLLRESTAPI_EXPORT DLLRESTAPI : public QObject
{
    Q_OBJECT
public:
    DLLRESTAPI();
    ~DLLRESTAPI();

    void login(QString, QString);
    void haeAsiakkaanTiedot(QString);
    void suoritaDebitNosto(QString, QString, QString, QString, QString);

private:
    asiakas *objectAsiakas;
    class login *objectLogin;
    procedures *objectProcedures;

    QString base_url;

signals:
    void loginSignalToExe(QString);
    void tiedotListToExe(QStringList);

private slots:
    void interfaceLoginSlot(QString);
    void tiedotListFromEngine(QStringList);
};

#endif // DLLRESTAPI_H
