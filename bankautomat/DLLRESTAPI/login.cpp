#include "login.h"

login::login(QString url)
{
    base_url = url+"/login";
}


void login::yritaKirjautua(QString kortinnumero,QString pinkoodi)
{
    QJsonObject jsonObj;
    jsonObj.insert("kortinnumero",kortinnumero);
    jsonObj.insert("pinkoodi",pinkoodi);

    QNetworkRequest request((base_url));


    loginManager = new QNetworkAccessManager(this);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}


void login::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    dataAsString = QString(response_data);

    emit loginSignalToInterface(dataAsString);

    reply->deleteLater();
    loginManager->deleteLater();
}

