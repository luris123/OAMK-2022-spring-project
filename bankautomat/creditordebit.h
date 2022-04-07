#ifndef CREDITORDEBIT_H
#define CREDITORDEBIT_H

#include <QDialog>
#include "paakayttoliittyma.h"

namespace Ui {
class creditOrDebit;
}

class creditOrDebit : public QDialog
{
    Q_OBJECT

public:
    creditOrDebit(QString, QString, QString);
    ~creditOrDebit();

private slots:
    void on_debit_btn_clicked();

    void on_credit_btn_clicked();

    void on_kirjauduUlos_btn_clicked();

private:
    Ui::creditOrDebit *ui;
    paakayttoliittyma *objectPaakayttoliittyma;

    QString nimi;
    QString debitSaldo;
    QString creditSaldo;
};

#endif // CREDITORDEBIT_H
