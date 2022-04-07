#ifndef ASIAKAS_H
#define ASIAKAS_H

#include <QObject>
#include <QString>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QStringList>

class asiakas : public QObject
{
    Q_OBJECT

public:
    asiakas(QString);

    void haeAsiakasTiedotRestilta(QString);

private:
    QString base_url;

    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;

signals:
    void tiedotListSignal(QStringList);

private slots:
    void getAsiakasSlot(QNetworkReply *reply);
};

#endif // ASIAKAS_H
