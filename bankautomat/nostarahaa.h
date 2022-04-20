#ifndef NOSTARAHAA_H
#define NOSTARAHAA_H

#include <QDialog>
#include <QtDebug>
#include <QTimer>

namespace Ui {
class NostaRahaa;
}

class NostaRahaa : public QDialog
{
    Q_OBJECT

public:
    explicit NostaRahaa(QWidget *parent = nullptr);
    ~NostaRahaa();
    void virheIlmoitus();
    QTimer *objectTimerNosta;

signals:
    void nostaRahaa(QString);

private slots:

    void timer_slot_nosta();

    void on_A1_clicked();

    void on_A2_clicked();

    void on_A3_clicked();

    void on_A4_clicked();

    void on_A5_clicked();

    void on_A6_clicked();

    void on_A7_clicked();

    void on_A8_clicked();

    void on_A9_clicked();

    void on_clearBtn_clicked();

    void on_A0_clicked();

    void on_enterBtn_clicked();

    void on_closeBtn_clicked();

    void on_twentyBtn_clicked();

    void on_fortyBtn_clicked();

    void on_sixtyBtn_clicked();

    void on_hundredBtn_clicked();

private:
    Ui::NostaRahaa *ui;

    QString nosto;
};

#endif // NOSTARAHAA_H
