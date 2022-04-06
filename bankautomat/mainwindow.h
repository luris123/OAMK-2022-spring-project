#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dllpincode.h"
#include "talletarahaa.h"
#include "paakayttoliittyma.h"
#include "dllserialport.h"
#include "nostarahaa.h"


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

private:
    Ui::MainWindow *ui;

    DLLPinCode *objectDLLPinCode;
    DLLSerialPort *objectDLLSerialPort;

    paakayttoliittyma *objectpaakayttoliittyma;
    TalletaRahaa *objectTalletaRahaa; // Talleta rahaa aloitus
    NostaRahaa *objectNostaRahaa;


};
#endif // MAINWINDOW_H
