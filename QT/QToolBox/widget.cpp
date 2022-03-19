#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    pTB = new QToolBox(this);
    pLay = new QHBoxLayout(this);

    btn[0] = new QPushButton("MySQL",this);
    btn[1] = new QPushButton("Oracle",this);
    btn[2] = new QPushButton("SQL Server",this);
    btn[3] = new QPushButton("IPv4",this);
    btn[4] = new QPushButton("IPv6",this);
    btn[5] = new QPushButton("OpenGL",this);
    btn[6] = new QPushButton("DirectX",this);

    pTB->addItem(btn[0],"DataBase");
    pTB->addItem(btn[1],"DataBase");
    pTB->addItem(btn[2],"DataBase");

    pTB->addItem(btn[3],"NetWork");
    pTB->addItem(btn[4],"NetWork");

    pTB->addItem(btn[5],"Griphics");
    pTB->addItem(btn[6],"Griphics");
    pLay->addWidget(pTB);
    setLayout(pLay);
}

Widget::~Widget()
{
    delete ui;
}

