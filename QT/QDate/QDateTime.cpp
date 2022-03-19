#include"widget.h"

void Widget::InitDameTime()
{
    //now
    mQTE[3] = new QDateTimeEdit(QDateTime::currentDateTime(),this);
    mQTE[3]->setDisplayFormat("yyyy-MM-dd hh:mm:ss:zzz");
    mQTE[3]->setGeometry(250,150,250,50);

    //year
    mQTE[0] = new QDateTimeEdit(QDateTime::currentDateTime(),this);
    mQTE[0]->setMinimumDate(QDate::currentDate().addYears(-3));
    mQTE[0]->setMaximumDate(QDate::currentDate().addYears(3));
    mQTE[0]->setDisplayFormat("yyyy");
    mQTE[0]->setGeometry(250,250,100,50);

    //Month
    mQTE[1] = new QDateTimeEdit(QDateTime::currentDateTime(),this);
    mQTE[1]->setMinimumDate(QDate::currentDate().addYears(-2));
    mQTE[1]->setMaximumDate(QDate::currentDate().addYears(2));
    mQTE[1]->setDisplayFormat("MM");
    mQTE[1]->setGeometry(250,350,100,50);

    //day
    mQTE[2] = new QDateTimeEdit(QDateTime::currentDateTime(),this);
    mQTE[2]->setMinimumDate(QDate::currentDate().addDays(-20));
    mQTE[2]->setMaximumDate(QDate::currentDate().addDays(20));
    mQTE[2]->setDisplayFormat("dd");
    mQTE[2]->setGeometry(250,450,100,50);
}
