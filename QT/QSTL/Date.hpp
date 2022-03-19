#ifndef DATE_HPP
#define DATE_HPP
#include<QTime>
#include<stdio.h>
#include<QDateTime>
void DateMain()
{
    //QData 日期
    {
        QDate d1(1995,11,21);
        QDate d2(1996,07,02);
        printf("d1 : %u %u %u \n",d1.year(),d1.month(),d1.day());
        printf("d1.daysTo(d2) %ld \n",d1.daysTo(d2));            //打印d1比d2早多少天
        printf("d1.daysTo(d2) %ld \n",d2.daysTo(d1));            //-224
    }
    {
        QDate nDate = QDate::currentDate();                     //获取当前日期
        printf("nDate : %u %u %u \n",nDate.year(),nDate.month(),nDate.day());
        printf("nDate.dayOfWeek() %d \n",nDate.dayOfWeek());                //1-7
        printf("nDate.dayOfYear() %d \n",nDate.dayOfYear());                //今年过去了多少天
        printf("nDate.daysInMonth() %d \n",nDate.daysInMonth());            //这个月有多少天
        printf("nDate.daysInYear() %d \n",nDate.daysInYear());            //今年有多少天
    }

    {
        QDate d1 = QDate::fromString("02.25","MM.dd");                  //默认1900年
        QDate d2 = QDate::fromString("2013.02.25","yyyy.MM.dd");
        d2 = d2.addYears(1);                  //加年
        d2 = d2.addMonths(10);
        d2 = d2.addDays(11);
        QString s1 = d1.toString("yyyy.MMMM.dddd");
        qDebug("d1: %s",s1.toStdString().c_str());
        qDebug("d2 : %s",d2.toString("yy.MM.dd").toStdString().c_str());
        printf("d2 : %d %d %d \n",d2.year(),d2.month(),d2.day());
    }

    //QDateTime操纵日期和时间
    {
        QDateTime time2 = QDateTime::fromString("M1d1y9800:01:02","'M'M'd'd'y'yyhh:mm:ss");         //1月1日1900+98年，1分2秒
        printf("date2 : %d %d %d \n",time2.date().year(),time2.date().month(),time2.date().day());
        printf("time2 : %d %d %d \n",time2.time().hour(),time2.time().minute(),time2.time().second());
        qDebug("datetime %s ",time2.toString("yy.MMM.ddd.ahh:mm:ss:zzz").toStdString().c_str());
    }

    {
        QTime time1 = QTime::fromString("13","HH");
        printf("time1 : %d %d %d \n",time1.hour(),time1.minute(),time1.second());
        time1 = QTime::currentTime();
        qDebug("time %s ",time1.toString("Ahh:m:s:z").toStdString().c_str());

        QTime n(14,0,0);                //14:00:00
        qDebug("n %s ",n.toString("HH:m:s:z").toStdString().c_str());
        QTime t;                        //00:00:00
        t = n.addSecs(70);
        qDebug("T %s ",t.toString("HH:m:s").toStdString().c_str());
        t = n.addSecs(-70);
        qDebug("T %s ",t.toString("HH:m:s").toStdString().c_str());
        t = n.addSecs(10*60*60+5);
        qDebug("T %s ",t.toString("HH:m:s").toStdString().c_str());
        t = n.addSecs(-15*60*60);
        qDebug("T %s ",t.toString("HH:m:s").toStdString().c_str());
    }
}
#endif // DATE_HPP
