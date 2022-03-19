#include"ClientItem.h"
#include"widget.h"

void ClientItem::btn_File()
{
    if(Widget::Instance()!=nullptr)
    {
        Widget::Instance()->OnEnterFile(this);
    }
}
void ClientItem::btn_CMD()
{
    if(Widget::Instance()!=nullptr)
    {
        Widget::Instance()->OnEnterCmd(this);
    }
}

ClientItem::ClientItem(QWidget* parent,unsigned int xPos,unsigned int yPos):QWidget(parent)
{
    this->setGeometry(xPos,yPos,800,50);
    pLab = new QLabel(this);
    pLab->setText("127.0.0.1:8888 C://Win32");
    pLab->setGeometry(0,0,400,50);
    pCmdbtn = new QPushButton("CMD",this);
    connect(pCmdbtn, &QPushButton::clicked, this,&ClientItem::btn_CMD);
    pCmdbtn->setGeometry(450,0,100,50);
    pFilebtn = new QPushButton("File",this);
    connect(pFilebtn, &QPushButton::clicked, this,&ClientItem::btn_File);
    pFilebtn->setGeometry(550,0,100,50);
}
