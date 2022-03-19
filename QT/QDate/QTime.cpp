#include"widget.h"

void Widget::InitTime()
{

    QTime ti (6,24,55,432);  //hour min sec millsecond
    mTimeEd[0] = new  QTimeEdit(ti,this);
    mTimeEd[0]->setGeometry(550,30,150,30);

    mTimeEd[1] = new QTimeEdit(ti.addMSecs(20000),this);
    mTimeEd[1]->setGeometry(550,70,150,30);

    mTimeEd[2] = new QTimeEdit(ti.addSecs(90),this);
    mTimeEd[2]->setGeometry(550,110,150,30);

    QTime nTime = QTime::currentTime();
    mTimeEd[3] = new QTimeEdit(nTime,this);
    mTimeEd[3]->setGeometry(550,190,150,30);

    QTime ti3;
    ti3.start();    //开始计时
    for(int i = 0;i<10000;i++)
    {
        for(int j = 0;j<10000;j++)
        {

        }
    }
    qDebug("Elapsed Time %d",ti3.elapsed());     //停止计时，拿到过了多久

    QTime ti4 = QTime::fromString("03:32","hh:mm");

    lb[7] = new QLabel(ti4.toString(),this);
    lb[7]->setGeometry(550,250,150,30);

    qDebug("Now Hour:%d  Min:%d  Sec:%d  mesc:%d ",nTime.hour(),nTime.minute(),nTime.second(),nTime.msec());
    QLabel *lb2 = new QLabel(nTime.toString("AP hh:mm:ss:zzz"),this);
    lb2->setGeometry(550,280,200,80);
}
