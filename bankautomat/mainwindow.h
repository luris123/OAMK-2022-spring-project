#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dllpincode.h"

#include "dllserialport.h"
#include "dllrestapi.h"


#include "paakayttoliittyma.h"



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
    void loginSlot(QString);

private:
    Ui::MainWindow *ui;

    DLLPinCode *objectDLLPinCode;
    DLLSerialPort *objectDLLSerialPort;
    DLLRESTAPI *objectDLLRESTAPI;

    paakayttoliittyma *objectpaakayttoliittyma;


    QString kortinnumero;
    QString asiakkaanNimi;

};
#endif // MAINWINDOW_H
