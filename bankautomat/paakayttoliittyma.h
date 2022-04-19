#ifndef PAAKAYTTOLIITTYMA_H
#define PAAKAYTTOLIITTYMA_H


#include <QDialog>
#include <QTimer>

#include "talletarahaa.h"
#include "nostarahaa.h"


namespace Ui {
class paakayttoliittyma;
}

class paakayttoliittyma : public QDialog
{
    Q_OBJECT

public:
     explicit paakayttoliittyma(QWidget *parent = nullptr);
    ~paakayttoliittyma();

    void asetaTiedot(QString, QString, QString, QStringList);
    void puhdistaListWidget();
    int tarkistaListWidget();

signals:
    void nostaRahaaValittu();
    void talletaRahaaValittu();
    void tilitapahtumaValinta(QString);
    void kirjauduUlosSignal();

private slots:

    void timer_slot();

    void on_depositBtn_clicked();

    void on_withdrawBtn_clicked();

    void on_logoutBtn_clicked();

    void on_ylos_btn_clicked();

    void on_alas_btn_clicked();

private:
    Ui::paakayttoliittyma *ui;
    TalletaRahaa *objectTalletaRahaa; // Talleta rahaa aloitus
    NostaRahaa *objectNostaRahaa;
    QTimer *objectTimer;

    QString valinta;
};

#endif // PAAKAYTTOLIITTYMA_H
