#include"ProgressBarWidget.h"

void ProgressBarWidget::InitProgressBar()
{
    pBar[0] = new QProgressBar(this);
    pBar[0]->setMinimum(0);
    pBar[0]->setMaximum(100);
    pBar[0]->setValue(50);
    pBar[0]->setOrientation(Qt::Horizontal);    //水平
    pBar[0]->setGeometry(10,30,200,50);

    pBar[1] = new QProgressBar(this);
    pBar[1]->setMinimum(0);
    pBar[1]->setMaximum(100);
    pBar[1]->setValue(60);
    pBar[1]->setOrientation(Qt::Horizontal);    //水平
    pBar[1]->setInvertedAppearance(true);       //进度条行进方向,true为反方向
    pBar[1]->setGeometry(10,100,200,50);

    pBar[2] = new QProgressBar(this);
    pBar[2]->setMinimum(0);
    pBar[2]->setMaximum(100);
    pBar[2]->setValue(70);
    pBar[2]->setOrientation(Qt::Vertical);    //竖直
    pBar[2]->setGeometry(300,30,50,200);

    pBar[3] = new QProgressBar(this);
    pBar[3]->setMinimum(0);
    pBar[3]->setMaximum(100);
    pBar[3]->setValue(80);
    pBar[3]->setOrientation(Qt::Vertical);    //竖直
    pBar[3]->setInvertedAppearance(true);       //进度条行进方向
    pBar[3]->setGeometry(400,30,50,200);
}
