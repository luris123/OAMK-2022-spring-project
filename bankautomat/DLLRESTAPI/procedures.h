#ifndef PROCEDURES_H
#define PROCEDURES_H


#include <QObject>
#include <QString>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


class procedures : public QObject
{
    Q_OBJECT
public:
    procedures(QString);

    void suoritaDebitNosto(QString, QString, QString, QString, QString);

    void suoritaCreditNosto(QString, QString, QString, QString, QString, QString);
private:
    QString base_url;

    QNetworkAccessManager *getDebitManager;
    QNetworkAccessManager *getCreditManager;

    QNetworkReply *reply;
    QByteArray response_data;

signals:
    //void tiedotListSignal(QStringList);

private slots:
    void getDebitNostoSlot(QNetworkReply *reply);
    void getCreditNostoSlot(QNetworkReply *reply);
};

#endif // PROCEDURES_H
