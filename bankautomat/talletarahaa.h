#ifndef TALLETARAHAA_H
#define TALLETARAHAA_H

#include <QDialog>
#include <QtDebug>
#include <QTimer>

namespace Ui {
class TalletaRahaa;
}

class TalletaRahaa : public QDialog
{
    Q_OBJECT

public:
    explicit TalletaRahaa(QWidget *parent = nullptr);
    ~TalletaRahaa();
    float getTalletaRahaaValue();
    void setRahaValue(float a);

private slots:

    void timer_slot_talleta();

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

    void on_SuljeBtn_clicked();

    void on_DecimalBtn_clicked();

    void on_BackBtn_clicked();

private:
    Ui::TalletaRahaa *ui;
    float RahaValue;
    QString TempText;
    QTimer *objectTimerTalleta;
};

#endif // TALLETARAHAA_H
