#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"SignalSlot.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pLB = new QLabel();
    pSpBox = new QSpinBox();
    setCentralWidget(pSpBox);

    SignalSlot *pS1 = new SignalSlot();
    SignalSlot *pS2 = new SignalSlot();
    connect(pSpBox, SIGNAL(valueChanged(int)), pS1,SLOT(SetValue(int)));
    connect(pS1,&SignalSlot::ValueChanged,pS2,&SignalSlot::SetValue);
    connect(pS2,&SignalSlot::ValueChanged,this,&MainWindow::OnS2ValueChanged);
    pSpBox->setValue(50);
    pSpBox->setRange(0,100000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::OnS2ValueChanged(int val)
{
    pLB->setNum(val);
    statusBar()->showMessage(pLB->text());
}
