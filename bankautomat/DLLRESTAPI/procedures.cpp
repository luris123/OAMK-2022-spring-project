#include "procedures.h"

procedures::procedures(QString url)
{
    base_url = url + "/procedures";
}

void procedures::suoritaDebitNosto(QString id, QString tilinumero, QString kortinnumero, QString debitSaldo, QString nostoSumma)
{
    QNetworkRequest request((base_url + "/" + id + "/" + tilinumero + "/" + kortinnumero + "/" + debitSaldo + "/" + nostoSumma));

    getManager = new QNetworkAccessManager(this);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getDebitNostoSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void procedures::getDebitNostoSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();

    qDebug() << response_data;

    //emit tiedotListSignal(tiedotList);
}
