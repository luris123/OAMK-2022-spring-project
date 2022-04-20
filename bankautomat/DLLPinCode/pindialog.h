#ifndef PINDIALOG_H
#define PINDIALOG_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class PinDialog;
}

class PinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PinDialog(QWidget *parent = nullptr);
    ~PinDialog();

    void pinkoodiVaarin();
    QTimer *objectTimerPinDialog;


private slots:

    void timer_slot_pindialog();

    void on_A1_clicked();

    void on_A2_clicked();

    void on_A3_clicked();

    void on_A4_clicked();

    void on_A5_clicked();

    void on_A6_clicked();

    void on_A7_clicked();

    void on_A8_clicked();

    void on_A9_clicked();

    void on_ClearBtn_clicked();

    void on_A0_clicked();

    void on_EnterBtn_clicked();

private:
    Ui::PinDialog *ui;
    QString PinKoodi;
    int yritys = 3;

signals:
    void pinkoodiEngine(QString);
};

#endif // PINDIALOG_H
