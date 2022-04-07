#ifndef ASIAKAS_H
#define ASIAKAS_H

#include <QObject>
#include <QString>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class asiakas : public QObject
{
    Q_OBJECT

public:
    asiakas(QString);

    void haeAsiakasTiedotRestilta();

private:
    QString base_url;
    QString dataAsString;

    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;

private slots:
    void getAsiakasSlot(QNetworkReply *reply);
};

#endif // ASIAKAS_H
