#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dllpincode.h"
#include "paakayttoliittyma.h"
#include "dllserialport.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

public slots:
    void kortinNumeroSlot(QString);
    void pinkoodiSlot(QString);

private:
    Ui::MainWindow *ui;

    DLLPinCode *objectDLLPinCode;
    DLLSerialPort *objectDLLSerialPort;

    paakayttoliittyma *objectpaakayttoliittyma;

};
#endif // MAINWINDOW_H
