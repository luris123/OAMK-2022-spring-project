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
    void suoritaTalletus(QString, QString, QString, QString, QString);
    void haeTilitapahtumat(QString, QString, QString);
private:
    QString base_url;

    QNetworkAccessManager *getManager;

    QNetworkReply *reply;
    QByteArray response_data;

signals:
     void tilitapahtumaSignal(QStringList);

private slots:
    void getSlot(QNetworkReply *reply);
    void getTilitapahtumatSlot(QNetworkReply *reply);
};

#endif // PROCEDURES_H
