#include "systemtrayicon.h"
#include <QSystemTrayIcon>
#include<QAction>
#include<QApplication>
#include<QDesktopServices>

//源文件（1.创建上下文菜单 2.创建系统托盘，实现相关功能）
SystemTrayIcon::SystemTrayIcon(QWidget *parent) : QMainWindow(parent)
{
    resize(800,600);
    CreatTrayIcon();
}

SystemTrayIcon::~SystemTrayIcon()
{
}

void SystemTrayIcon::CreatTrayMenu()
{
    miniSizeAction = new QAction("最小化(&N)",this);
    maxSizeAction = new QAction("最大化(&X)",this);
    restoreWinAction = new QAction("还 原(&R)",this);
    quitAction = new QAction("退出(&Q)",this);

    this->connect(miniSizeAction,SIGNAL(triggered()),this,SLOT(hide()));
    this->connect(maxSizeAction,SIGNAL(triggered()),this,SLOT(showMaximized()));
    this->connect(restoreWinAction,SIGNAL(triggered()),this,SLOT(showNormal()));
    this->connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));

    myMenu = new QMenu((QWidget*)QApplication::desktop());

    myMenu->addAction(miniSizeAction);
    myMenu->addAction(maxSizeAction);
    myMenu->addAction(restoreWinAction);
    myMenu->addSeparator();     //加入一个分离符
    myMenu->addAction(quitAction);
}

void SystemTrayIcon::CreatTrayIcon()
{
    CreatTrayMenu();

    if (!QSystemTrayIcon::isSystemTrayAvailable())      //判断系统是否支持系统托盘图标
    {
        return;
    }

    myTrayIcon = new QSystemTrayIcon(this);

    myTrayIcon->setIcon(QIcon("../resources/users.png"));   //设置图标图片
    setWindowIcon(QIcon("../resources/users.png"));  //把图片设置到窗口上

    myTrayIcon->setToolTip("ToolTip");    //托盘时，鼠标放上去的提示信息

    myTrayIcon->showMessage("showMessage","showMessage",QSystemTrayIcon::Information,10000);



    myTrayIcon->setContextMenu(myMenu);     //设置托盘上下文菜单

    myTrayIcon->show();
    this->connect(myTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
    this->connect(myTrayIcon,SIGNAL(messageClicked()),this,SLOT(OnClickBubble()));
}

void SystemTrayIcon::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Trigger:

    case QSystemTrayIcon::DoubleClick:
        showNormal();
        break;
    case QSystemTrayIcon::MiddleClick:
        myTrayIcon->showMessage("showMessage","showMessage iconActivated",QSystemTrayIcon::Information,10000);
        break;

    default:
        break;
    }
}

void SystemTrayIcon::closeEvent(QCloseEvent *event)
{
    if (myTrayIcon->isVisible())
    {
        myTrayIcon->showMessage("SystemTrayIcon","QT实现的系统托盘 closeEvent",QSystemTrayIcon::Information,5000);

        hide();     //最小化
        event->ignore();
    }
    else
        event->accept();
}
void SystemTrayIcon::OnClickBubble()
{
    QDesktopServices::openUrl(QUrl("file:///C:/Documents and Settings/All Users", QUrl::TolerantMode));
}

