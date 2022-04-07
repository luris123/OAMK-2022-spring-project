#ifndef LOGIN_H
#define LOGIN_H

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class login : public QObject
{
    Q_OBJECT
public:
    login(QString);

    void yritaKirjautua(QString, QString);


private:
    QString base_url;
    QString dataAsString;

    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;

signals:
    void loginSignalToInterface(QString);

private slots:
    void loginSlot(QNetworkReply *reply);
};

#endif // LOGIN_H
