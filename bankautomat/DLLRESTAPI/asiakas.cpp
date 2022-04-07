#include "asiakas.h"


asiakas::asiakas(QString url)
{
    base_url = url + "/asiakas/1";
}

void asiakas::haeAsiakasTiedotRestilta()
{

    QNetworkRequest request((base_url));

    getManager = new QNetworkAccessManager(this);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getAsiakasSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void asiakas::getAsiakasSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    qDebug() << json_array[0];
    QString tiedot;

    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       tiedot+=QString::number(json_obj["id_asiakas"].toInt())+", "+json_obj["nimi"].toString()+", "+json_obj["lähiosoite"].toString()+"\r";
    }
}

