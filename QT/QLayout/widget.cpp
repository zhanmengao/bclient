#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QTableWidget>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    tw = new QTabWidget(this);
    tw->setGeometry(0,0,size().width(),size().height());

    InitLayout();
    InitSplitter();
    InitBtnLayout();
    OnSplitterBtnClick();
}
void Widget::InitLayout()
{
    QWidget *w1 = new QWidget(tw);
    w1->setGeometry(0,0,size().width(),size().height());
    tw->addTab(w1,"Layout");

    QHBoxLayout *hboxLayout = new QHBoxLayout();
    QPushButton *btn[6];

    QString btnStr[6] = {"Monday", "Tuesday", "Wednesday",
                         "Thursday", "Friday", "Saturday"};

    for(int i = 0 ; i < 6 ; i++)
    {
        btn[i] = new QPushButton(btnStr[i]);
        hboxLayout->addWidget(btn[i]);
    }


    QVBoxLayout *vboxLayout = new QVBoxLayout();
    QPushButton *vbtn[6];

    QString vbtnStr[3] = {"Movie", "Drama", "Animation"};

    for(int i = 0 ; i < 3 ; i++)
    {
        vbtn[i] = new QPushButton(vbtnStr[i]);
        vboxLayout->addWidget(vbtn[i]);
    }

    QGridLayout *gridLayout = new QGridLayout();
    QPushButton *gbtn[5];

    QString gbtnStr[6] = {"Monday", "Tuesday", "Wednesday",
                          "Thursday", "Friday", "Saturday"};


    for(int i = 0 ; i < 5 ; i++)
    {
        gbtn[i] = new QPushButton(gbtnStr[i]);
    }

    gridLayout->addWidget(gbtn[0], 0, 0);
    gridLayout->addWidget(gbtn[1], 0, 1);
    gridLayout->addWidget(gbtn[2], 1, 0, 1, 2);
    gridLayout->addWidget(gbtn[3], 2, 0);
    gridLayout->addWidget(gbtn[4], 2, 1);

    QVBoxLayout *defaultLayout = new QVBoxLayout();

    //嵌套
    defaultLayout->addLayout(hboxLayout);
    defaultLayout->addLayout(vboxLayout);
    defaultLayout->addLayout(gridLayout);

    w1->setLayout(defaultLayout);
}
void Widget::InitSplitter()
{
    QWidget *w2 = new QWidget(tw);
    sp = new QSplitter(w2);
    sp->setGeometry(0,0,600,80);
    tw->addTab(w2,"Splitter");
}
void Widget::InitBtnLayout()
{
    QWidget *w3 = new QWidget(tw);
    vl = new QVBoxLayout(w3);
    tw->addTab(w3,"Layout2");
}
void Widget::OnSplitterBtnClick()
{
    QPushButton *btn1 = new QPushButton("btn1");
    QPushButton *btn2 = new QPushButton("btn2");
    QPushButton *btn3 = new QPushButton("btn3");
    sp->addWidget(btn1);
    sp->addWidget(btn2);
    sp->addWidget(btn3);
    connect(btn1,&QPushButton::clicked,this,&Widget::OnSplitterBtnClick);
    connect(btn2,&QPushButton::clicked,this,&Widget::OnSplitterBtnClick);
    connect(btn3,&QPushButton::clicked,this,&Widget::OnSplitterBtnClick);

    QPushButton *btn4 = new QPushButton("btn1");
    QPushButton *btn5 = new QPushButton("btn2");
    QPushButton *btn6 = new QPushButton("btn3");
    vl->addWidget(btn4);
    vl->addWidget(btn5);
    vl->addWidget(btn6);
    connect(btn4,&QPushButton::clicked,this,&Widget::OnSplitterBtnClick);
    connect(btn5,&QPushButton::clicked,this,&Widget::OnSplitterBtnClick);
    connect(btn6,&QPushButton::clicked,this,&Widget::OnSplitterBtnClick);
}
Widget::~Widget()
{
    delete ui;
}
void Widget::InitHLayout()
{
    hLayout = new QHBoxLayout(this);
    QPushButton *btn[6];
    QString hLayStr[6] = {"Map","Set","Vector","List","Queue","Array"};
    for(int i = 0;i<6;i++)
    {
        btn[i] = new QPushButton(hLayStr[i]);
        hLayout->addWidget(btn[i]);       //向layout添加控件
    }
    setLayout(hLayout);      //设为默认布局
}
void Widget::InitVLayout()
{
    vLayout = new QVBoxLayout(this);
    QPushButton *vBtn[3];
    QString vbtnStr[3] = {"Movie","Game","MakeLove"};
    for(int i = 0;i<3;i++)
    {
        vBtn[i] = new QPushButton(vbtnStr[i]);
        vLayout->addWidget(vBtn[i]);
    }
    setLayout(vLayout);
}
void Widget::InitGLayout()
{
    gLayout = new QGridLayout(this);
    QPushButton *btn[5];
    QString btnStr[5] = {"Monday","Tuesday","Wednesday","Thuesday","Friday"};
    for(int i = 0;i<5;i++)
    {
        btn[i] = new QPushButton(btnStr[i]);
    }
    gLayout->addWidget(btn[0],0,0);
    gLayout->addWidget(btn[1],0,1);
    gLayout->addWidget(btn[2],1,0,1,2);    //将第1行0和第1行2合并
    gLayout->addWidget(btn[3],2,0);
    gLayout->addWidget(btn[4],2,1);
    /*
     *
layout->addWidget(&TestBtn1, 0, 0, 2, 1);//坐标（0，0）的组件占用两行一列
layout->addWidget(&TestBtn2, 0, 1, 2, 1);//坐标（0，1）的组件占用两行一列
layout->addWidget(&TestBtn3, 2, 0, 1, 2);//坐标（2，0）的组件占用一行两列
layout->addWidget(&TestBtn4, 3, 0, 1, 2);//坐标（3，0）的组件占用一行两列
     */
}
