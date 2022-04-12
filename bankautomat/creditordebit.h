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
    explicit creditOrDebit(QWidget *parent = nullptr);
    ~creditOrDebit();


signals:
    void tilinValinta(QString);
    void kirjauduUlosSignal();

private slots:
    void on_debit_btn_clicked();

    void on_credit_btn_clicked();

    void on_kirjauduUlos_btn_clicked();

private:
    Ui::creditOrDebit *ui;
};

#endif // CREDITORDEBIT_H
