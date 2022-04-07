#ifndef CREDITORDEBIT_H
#define CREDITORDEBIT_H

#include <QDialog>

namespace Ui {
class creditOrDebit;
}

class creditOrDebit : public QDialog
{
    Q_OBJECT

public:
    explicit creditOrDebit(QWidget *parent = nullptr);
    ~creditOrDebit();

private:
    Ui::creditOrDebit *ui;
};

#endif // CREDITORDEBIT_H
