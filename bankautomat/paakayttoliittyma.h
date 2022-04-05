#ifndef PAAKAYTTOLIITTYMA_H
#define PAAKAYTTOLIITTYMA_H

#include <QDialog>

namespace Ui {
class paakayttoliittyma;
}

class paakayttoliittyma : public QDialog
{
    Q_OBJECT

public:
    explicit paakayttoliittyma(QWidget *parent = nullptr);
    ~paakayttoliittyma();

private:
    Ui::paakayttoliittyma *ui;
};

#endif // PAAKAYTTOLIITTYMA_H
