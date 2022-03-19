#include "mainwindow.h"
#include"Item.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(1080,760);
    area = new QScrollArea(this);
    QWidget *mainWidget = new QWidget(this);

    setCentralWidget(mainWidget);

    layout = new QGridLayout(mainWidget);
    mainWidget->setLayout(layout);
    //添加
    mainWidget->resize(250,2000);
    for(int i = 0;i<200;i++)
    {
        Item *item = new Item("../resources/QQ.png");
        int row = i/5;
        int col = i%5;
        layout->setRowMinimumHeight(row,30);
        layout->addWidget(item,row,col);
    }
    area->setWidget(mainWidget);
    area->setGeometry(0,0,mainWidget->width()+20,400);
}

MainWindow::~MainWindow()
{
}

