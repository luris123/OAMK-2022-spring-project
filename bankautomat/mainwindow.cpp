#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    objectDLLPinCode = new DLLPinCode;
    objectDLLPinCode->openDLLPinCode();
}

MainWindow::~MainWindow()
{
    delete ui;
}



