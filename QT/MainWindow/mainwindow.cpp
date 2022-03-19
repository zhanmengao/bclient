#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMenu>
#include<QAction>
#include<QToolBar>
#include<QDockWidget>
#include<QListWidget>
#include<QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //菜单栏
    QAction *newAct = new QAction(QIcon("../resources/new.png"),tr("&New"),this);
    newAct->setShortcut(QKeySequence::New);       //快捷键
    newAct->setStatusTip(tr("Create New file"));
    connect(newAct,&QAction::triggered,this,&MainWindow::newFile);

    QAction *openAct = new QAction(QIcon("../resources/open.png"),tr("&Open"),this);
    openAct->setStatusTip(tr("Open an existing file"));
    newAct->setShortcut(QKeySequence::Open);
    connect(openAct,&QAction::triggered,this,&MainWindow::open);

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));          //给窗口添加菜单
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);

    //工具栏
    QToolBar *fileToolbar = addToolBar(tr("File"));
    fileToolbar->addAction(newAct);
    fileToolbar->addAction(openAct);

    //主窗口锚接空间
    QDockWidget *dock = new QDockWidget(tr("Target"),this);
    dock->setAllowedAreas(Qt::RightDockWidgetArea);         //以实际设定为准
    QListWidget *customerList = new QListWidget(dock);
    customerList->addItems(QStringList() << "One" <<"Two" <<"Three" <<"Four" <<"Five");
    dock->setWidget(customerList);
    addDockWidget(Qt::LeftDockWidgetArea,dock);            //给窗口添加Dock

    //中心控件
    QTextEdit *textEdit = new QTextEdit();
    setCentralWidget(textEdit);                     //给窗口添加中心控件

    //状态栏
    statusBar()->showMessage(tr("Ready"));              //设置底部状态栏显示文字
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::newFile()
{

}
void MainWindow::open()
{

}

