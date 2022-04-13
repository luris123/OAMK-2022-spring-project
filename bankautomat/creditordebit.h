#ifndef CREDITORDEBIT_H
#define CREDITORDEBIT_H

#include <QDialog>
#include <QTimer>
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

    void timer_slot_CredDeb();

    void on_debit_btn_clicked();

    void on_credit_btn_clicked();

    void on_kirjauduUlos_btn_clicked();

private:
    Ui::creditOrDebit *ui;
    QTimer *objectTimerCredDeb;
};

#endif // CREDITORDEBIT_H
