#include"LabelWidget.h"


void LabelWidget::InitLabel()
{
    lb[0] = new QLabel("I love Ju Ju",this);
    lb[0]->setGeometry(10,30,200,40);

    QPixmap pix("resources/browser.png");
    lb[1] = new QLabel(this);
    lb[1]->setPixmap(pix);
    lb[1]->setGeometry(10,70,100,100);

    lcd[0] = new QLCDNumber(2,this);     //显示的数字个数
    lcd[0]->display(24);                 //显示的内容
    lcd[0]->setGeometry(150,30,200,100);
    lcd[0]->setSegmentStyle(QLCDNumber::Outline);

    lcd[1] = new QLCDNumber(5,this);
    lcd[1]->display("10:34");
    lcd[1]->setGeometry(150,140,200,100);
    lcd[1]->setSegmentStyle(QLCDNumber::Filled);
}
