#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mComBox = new QComboBox(this);
    mComBox->setGeometry(50,50,200,30);
    mComBox->addItem(QIcon("resources/browser.png"),"Application",QString("123435566") + "&" + "123456456");
    mComBox->addItem(QIcon("resources/calendar.png"),"Graphics",QString("123435566") + "&" + "123456456");
    mComBox->addItem("Database",QString("123435566") + "&" + "123456456");
    mComBox->addItem("NetWork",QString("123435566") + "&" + "123456456");

    connect(mComBox,SIGNAL(currentIndexChanged(int)),this,
            SLOT(valueChanged()));

}

MainWindow::~MainWindow()
{
    delete ui;

}
//选择第一组的复选框，或者未被激活时，运行槽函数的成员函数chkChanged
void MainWindow::valueChanged()
{
    int curIndex = mComBox->currentIndex();
    qDebug("Current Index = %d %s",curIndex,mComBox->currentData().toString().toLocal8Bit().data());
}
