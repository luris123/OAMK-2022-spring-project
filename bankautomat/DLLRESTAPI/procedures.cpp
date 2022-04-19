#include "procedures.h"

procedures::procedures(QString url)
{
    base_url = url + "/procedures";
}

void procedures::suoritaDebitNosto(QString id, QString tilinumero, QString kortinnumero, QString debitSaldo, QString Summa)
{
    QNetworkRequest request((base_url + "/nosto" + "/" + id + "/" + tilinumero + "/" + kortinnumero + "/" + debitSaldo + "/" + Summa));
    qDebug() << base_url + "/" + id + "/" + tilinumero + "/" + kortinnumero + "/" + debitSaldo + "/" + Summa;
    getManager = new QNetworkAccessManager(this);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void procedures::suoritaCreditNosto(QString id, QString tilinumero, QString kortinnumero, QString creditSaldo, QString Summa, QString luottoraja)
{
    QNetworkRequest request((base_url + "/nosto" + "/" + id + "/" + tilinumero + "/" + kortinnumero + "/" + ("-")+creditSaldo + "/" + Summa + "/" + ("-")+luottoraja));

    getManager = new QNetworkAccessManager(this);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void procedures::getSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();

    qDebug() << response_data;

}

void procedures::getTilitapahtumatSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();

    QStringList tiedotList;

    int i = 0;
    foreach (const QJsonValue &value, json_array) {

       QJsonObject json_obj = value.toObject();
       tiedotList.insert(i, QString(json_obj["pvm_ja_aika"].toString().replace("T", " ").replace(19, 5, "")) + ", " + QString(json_obj["tilinumero"].toString()) + ", " + QString(json_obj["kortinnumero"].toString()) + ", " + QString(json_obj["tapahtuma"].toString()) + ", " + QString::number(json_obj["summa"].toInt()));

       i++;
    }

    for(int j = 0; j < tiedotList.length(); j++)
    {
        qDebug() << tiedotList[j];
    }

     emit tilitapahtumaSignal(tiedotList);
}

void procedures::suoritaTalletus(QString tilityyppi, QString id, QString tilinumero, QString kortinnumero, QString talletussumma)
{
    QNetworkRequest request((base_url + "/talletus" + "/" + tilityyppi + "/" + id + "/" + tilinumero + "/" + kortinnumero + "/" + talletussumma));
    qDebug() << (base_url + "/talletus" + "/" + tilityyppi + "/" + id + "/" + tilinumero + "/" + kortinnumero + "/" + talletussumma);

    getManager = new QNetworkAccessManager(this);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getSlot(QNetworkReply*)));

    reply = getManager->get(request);

}

void procedures::haeTilitapahtumat(QString id, QString maara, QString hakumaara)
{
    QNetworkRequest request((base_url + "/selaa" + "/" + id + "/" + maara + "/" + hakumaara));

    getManager = new QNetworkAccessManager(this);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getTilitapahtumatSlot(QNetworkReply*)));

    reply = getManager->get(request);
}
