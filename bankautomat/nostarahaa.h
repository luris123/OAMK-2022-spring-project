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
    float getNostaRahaaValue();
    void setNostaValue(float a);

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

    void on_backBtn_clicked();

    void on_dotBtn_clicked();

    void on_closeBtn_clicked();

private:
    Ui::NostaRahaa *ui;
    float NostaValue;
    QString nosto;
    QTimer *objectTimerNosta;
};

#endif // NOSTARAHAA_H
