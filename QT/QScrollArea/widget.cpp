#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    pLabel = new QLabel(this);
    QImage image("../resources/fish.png");
    if(image.isNull())
    {
        qDebug("load image error!");
    }
    pLabel->setPixmap(QPixmap::fromImage(image));

    pArea = new QScrollArea(this);
    pArea ->setWidget(pLabel);        //将Label包含到滚动条
    pArea ->setBackgroundRole(QPalette::Dark);
    pArea->setGeometry(0,0,image.width()+20,image.height()-200);
}

Widget::~Widget()
{
    delete ui;
}

