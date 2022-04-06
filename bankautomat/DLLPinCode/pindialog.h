#ifndef PINDIALOG_H
#define PINDIALOG_H

#include <QDialog>

namespace Ui {
class PinDialog;
}

class PinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PinDialog(QWidget *parent = nullptr);
    ~PinDialog();
    QString getPinDialogValue();
    void setDialogValue(QString a);

private slots:
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
    QString dialogValue;
    QString PinKoodi;
};

#endif // PINDIALOG_H
