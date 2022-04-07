#include "asiakas.h"


asiakas::asiakas(QString url)
{
    base_url = url + "/pankkikortti/info/";
}

void asiakas::haeAsiakasTiedotRestilta(QString kortinnumero)
{

    QNetworkRequest request((base_url + kortinnumero));

    getManager = new QNetworkAccessManager(this);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getAsiakasSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void asiakas::getAsiakasSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();

    QStringList tiedotList;

    foreach (const QJsonValue &value, json_array) {

       QJsonObject json_obj = value.toObject();

       tiedotList.insert(0, QString::number(json_obj["id_tili"].toInt()));
       tiedotList.insert(1, QString::number(json_obj["id_asiakas"].toInt()));
       tiedotList.insert(2, json_obj["nimi"].toString());
       tiedotList.insert(3, json_obj["debitTilinumero"].toString());
       tiedotList.insert(4, json_obj["creditTilinumero"].toString());
       tiedotList.insert(5, QString::number(json_obj["debitSaldo"].toDouble()));
       tiedotList.insert(6, QString::number(json_obj["creditSaldo"].toDouble()));
    }
    emit tiedotListSignal(tiedotList);
}

