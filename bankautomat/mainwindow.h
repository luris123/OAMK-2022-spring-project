#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dllpincode.h"

#include "talletarahaa.h"

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


private:
    Ui::MainWindow *ui;
    DLLPinCode *objectDLLPinCode;

    TalletaRahaa *objectTalletaRahaa; // Talleta rahaa aloitus

    DLLSerialPort *objectDLLSerialPort;

};
#endif // MAINWINDOW_H
