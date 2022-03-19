#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mCLB = new QCommandLinkButton("Vision","Vision Project",this);
    mCLB->setGeometry(50,300,200,100);
    mCLB->setFlat(true);
    connect(mCLB,SIGNAL(clicked()),this,SLOT(clickFunc()));


    int yPos = 30;
    for(int i = 0;i<3;i++)
    {
        btn[i] = new QPushButton(QString("Frame's button %1").arg(i),this);
        btn[i]->setGeometry(10,yPos,300,40);

        yPos+=50;
    }
    //f1
    connect(btn[0], SIGNAL(pressed()), this,SLOT(btn_pressed()));
    //f2
    connect(btn[0], &QPushButton::released,this,&this->btn_released);
    //这是因为我们自定义的 Button 中存在两个重载信号，然后用这种 connect 的方式会无法识别到底想要连接哪个信号。
    //所以，如果信号是重载的话，需要用下面的写法来替换：
    connect(btn[1], static_cast<void (QPushButton::*)(bool)>(&QPushButton::clicked), this, &this->btn_click);
    connect(btn[0], static_cast<void (QPushButton::*)(void)>(&QPushButton::pressed), this, &this->btn_pressed);
    connect(btn[0], static_cast<void (QPushButton::*)(void)>(&QPushButton::released), this, &this->btn_released);
    //f3
    connect(btn[1], QOverload<bool>::of(&QPushButton::clicked),this,&this->btn_click);
    //connect(btn[1], QOverload<void>::of(&QPushButton::released),this,&this->btn_released);

    btnFrame = new QFocusFrame(this);
}
void Widget::btn_click()
{
    qDebug("btn click");
    btnFrame->setWidget(btn[1]);
    btnFrame->setAutoFillBackground(true);
}
void Widget::btn_pressed()
{
    qDebug("btn pressed");
    btnFrame->setWidget(btn[0]);
    btnFrame->setAutoFillBackground(true);
}
void Widget::btn_released()
{
    qDebug("btn released");
}
void Widget::clickFunc()
{
    qDebug("QCommandLinkButton Click.");
}
Widget::~Widget()
{
    delete ui;
}

