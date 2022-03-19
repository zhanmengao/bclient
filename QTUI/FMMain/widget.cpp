#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    _Ins = this;
    InitTab();
}
void Widget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    qDebug("width : %d, height : %d", this->width(), this->height());
    if(pMainTab!=nullptr)
    {
        pMainTab->setGeometry(20, 20, this->width(), this->height());
    }
    /*
    if(pArea!=nullptr)
    {
        pArea->setGeometry(0,0,this->width(), this->height());
    }
    */
}
Widget::~Widget()
{
    _Ins = nullptr;
    delete ui;
}

Widget* Widget::_Ins = nullptr;


