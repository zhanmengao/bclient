#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    tab = new QTabWidget(this);
    browser = new QWidget();
    users = new QWidget();
    tab->addTab(browser,QIcon("../resources/browser.png"),"Browser");
    tab->addTab(users,QIcon("../resources/users.png"),"Users");
    tab->setGeometry(20, 20, 800, 600);
    QString btn_str[3] = {"btn1","btn2","btn3"};
    QPushButton *btn[3];
    int yPos = 30;
    for(int i = 0;i<3;i++)
    {
        btn[0] = new QPushButton(btn_str[i],browser);
        btn[0]->setGeometry(10,yPos+=50,100,40);
    }
    connect(tab,SIGNAL(currentChanged(int)),this,SLOT(currentTab(int)));

    tBar = new QTabBar(users);
    tBar->addTab("Brower");
    tBar->addTab(QIcon("../resources/users.png"),"User");
    tBar->addTab("Application");
    tBar->setGeometry(0,0,800,600);
    tBar->setShape(QTabBar::RoundedSouth);
    connect(tBar,SIGNAL(currentChanged(int)),this,SLOT(currentTab(int)));
}
void Widget::currentTab(int index)
{
    qDebug("Current Tab: %i ",index);
}
Widget::~Widget()
{
    delete ui;
}

