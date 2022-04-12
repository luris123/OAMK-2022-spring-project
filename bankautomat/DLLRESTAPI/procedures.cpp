#include "procedures.h"

procedures::procedures(QString url)
{
    base_url = url + "/procedures";
}

void procedures::suoritaDebitNosto(QString id, QString tilinumero, QString kortinnumero, QString debitSaldo, QString nostoSumma)
{
    QNetworkRequest request((base_url + "/" + id + "/" + tilinumero + "/" + kortinnumero + "/" + debitSaldo + "/" + nostoSumma));
    qDebug() << base_url + "/" + id + "/" + tilinumero + "/" + kortinnumero + "/" + debitSaldo + "/" + nostoSumma;
    getDebitManager = new QNetworkAccessManager(this);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    connect(getDebitManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getDebitNostoSlot(QNetworkReply*)));

    reply = getDebitManager->get(request);
}

void procedures::getDebitNostoSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();

    qDebug() << response_data;

    //emit tiedotListSignal(tiedotList);
}

void procedures::suoritaCreditNosto(QString id, QString tilinumero, QString kortinnumero, QString creditSaldo, QString nostoSumma, QString luottoraja)
{
    QNetworkRequest request((base_url + "/" + id + "/" + tilinumero + "/" + kortinnumero + "/" + ("-")+creditSaldo + "/" + nostoSumma + "/" + ("-")+luottoraja));

    getCreditManager = new QNetworkAccessManager(this);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    connect(getCreditManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getCreditNostoSlot(QNetworkReply*)));

    reply = getCreditManager->get(request);
}

void procedures::getCreditNostoSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();

    qDebug() << response_data;

    //emit tiedotListSignal(tiedotList);
}
