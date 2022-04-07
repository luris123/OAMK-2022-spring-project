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

    void haeAsiakkaanTiedot(QString);
    void login(QString, QString);

private:
    asiakas *objectAsiakas;
    class login *objectLogin;

    QString base_url;

signals:
    void loginSignalToExe(QString);
    void tiedotListToExe(QStringList);

private slots:
    void interfaceLoginSlot(QString);
    void tiedotListFromEngine(QStringList);
};

#endif // DLLRESTAPI_H
