#include "procedures.h"

procedures::procedures(QString url)
{
    base_url = url + "/procedures";
}

void procedures::suoritaDebitNosto(QString id, QString tilinumero, QString kortinnumero, QString debitSaldo, QString Summa)
{
    QNetworkRequest request((base_url + "/" +  "/" + id + "/" + tilinumero + "/" + kortinnumero + "/" + debitSaldo + "/" + Summa));
    qDebug() << base_url + "/" + id + "/" + tilinumero + "/" + kortinnumero + "/" + debitSaldo + "/" + Summa;
    getManager = new QNetworkAccessManager(this);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getDebitSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void procedures::suoritaCreditNosto(QString id, QString tilinumero, QString kortinnumero, QString creditSaldo, QString Summa, QString luottoraja)
{
    QNetworkRequest request((base_url + "/" +  "/" + id + "/" + tilinumero + "/" + kortinnumero + "/" + ("-")+creditSaldo + "/" + Summa + "/" + ("-")+luottoraja));

    getManager = new QNetworkAccessManager(this);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void procedures::getSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();

    qDebug() << response_data;

    //emit tiedotListSignal(tiedotList);
}

void procedures::suoritaTalletus(QString id, QString tilityyppi, QString tilinumero, QString kortinnumero, QString talletussumma)
{
    QNetworkRequest request((base_url + "/talletus" + "/" + id + "/" + tilityyppi + "/" + tilinumero + "/" + kortinnumero + "/" + talletussumma));

    getManager = new QNetworkAccessManager(this);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getSlot(QNetworkReply*)));

    reply = getManager->get(request);

}
