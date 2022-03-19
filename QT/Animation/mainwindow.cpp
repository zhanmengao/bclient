#include "mainwindow.h"
#include<QMenu>
#include<QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800,600);
    btn = new QPushButton("Button",this);
    btn2 = new QPushButton("Button2",this);
    btn->setGeometry(10,50,100,30);
    btn2->setGeometry(50,95,100,30);

    InitAnimation();
    InitGroup();
    InitStateMachine();
    //菜单
    QMenu *fileMenu = menuBar()->addMenu(tr("Animation"));          //给窗口添加菜单
    {
        QAction *openAct = new QAction(tr("Linear"),this);
        connect(openAct,SIGNAL(triggered()),this,SLOT(OnClickLinear()));
        fileMenu->addAction(openAct);
    }
    {
        QAction *openAct = new QAction(tr("InOutQuad"),this);
        connect(openAct,SIGNAL(triggered()),this,SLOT(OnClickInOutQuad()));
        fileMenu->addAction(openAct);
    }
    {
        QAction *openAct = new QAction(tr("SequentialGroup"),this);
        connect(openAct,SIGNAL(triggered()),this,SLOT(OnClickSequentialGroup()));
        fileMenu->addAction(openAct);
    }
    {
        QAction *openAct = new QAction(tr("ParallelGroup"),this);
        connect(openAct,SIGNAL(triggered()),this,SLOT(OnClickParallelGroup()));
        fileMenu->addAction(openAct);
    }
}

MainWindow::~MainWindow()
{
}


