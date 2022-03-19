#include"widget.h"

void Widget::InitDate()
{
    QDate dt1(2013,11,7);
    QDate dt2 = QDate::currentDate();

    dateEdit[0] = new QDateEdit(dt1.addYears(2),this);
    dateEdit[0]->setGeometry(10,10,140,40);

    dateEdit[1] = new QDateEdit(dt1.addMonths(3),this);
    dateEdit[1]->setGeometry(160,10,140,40);

    dateEdit[2] = new QDateEdit(dt1.addDays(10),this);
    dateEdit[2]->setGeometry(310,10,140,40);

    dateEdit[3] = new QDateEdit(dt2,this);
    dateEdit[3]->setGeometry(10,60,140,40);

    // 1:mon, 2:tue, 3:wed, 4:thur, 5:fri, 6:sat, 7:sun
    qDebug("Day of year : %d", dt1.dayOfYear());
    qDebug("End Day : %d", dt1.daysInMonth());
    qDebug("End Day : %d", dt1.daysInYear());

    switch(dt2.dayOfWeek())
    {
        case 1: qDebug("Monday");break;
        case 2: qDebug("Tuesday");break;
        case 3: qDebug("Wednesday");break;
        case 4: qDebug("Thursday");break;
        case 5: qDebug("Friday");break;
        case 6: qDebug("Saturday");break;
        case 7: qDebug("Sunday");break;
    }

    QDate dt3 = QDate::fromString("2020.07.02","yyyy.MM.dd");
    QDate dt4 = QDate::fromString("06.26","MM.dd");

    lb[0] = new QLabel(dt3.toString(),this);
    lb[0]->setGeometry(10,110,150,30);

    lb[1] = new QLabel(dt4.toString(),this);
    lb[1]->setGeometry(10,150,150,30);

    if(QDate::isValid(2011,6,37))
    {
        qDebug("2011 6 37 is true");
    }
    else
    {
        qDebug("2011 6 37 is false");
    }

    QDate dt5(2020,4,30);

    QString longWeek = dt5.longDayName(dt5.dayOfWeek());
    QString longMonth = dt5.longMonthName(dt5.month());
    QString strDateLong = QString("%1 %2").arg(longWeek).arg(longMonth);

    QString shortWeek = dt5.shortDayName(dt5.dayOfWeek());
    QString shortMonth = dt5.shortMonthName(dt5.month());
    QString strDateShort = QString("%1 %2").arg(shortWeek).arg(shortMonth);

    lb[2] = new QLabel(QString("Long: %1,Short : %2").arg(strDateLong).arg(strDateShort),this);
    lb[2]->setGeometry(10,190,250,30);

    QDate dt6(1995,11,21);
    lb[3] = new QLabel(dt6.toString(Qt::TextDate),this);
    lb[3]->setGeometry(10,240,250,30);
    QDate dt7(1996,7,2);
    lb[4] = new QLabel(dt7.toString(Qt::TextDate),this);
    lb[4]->setGeometry(10,270,250,30);

    lb[5] = new QLabel(dt6.toString(Qt::ISODate),this);
    lb[5]->setGeometry(10,300,250,30);

    lb[6] = new QLabel(dt6.toString(Qt::SystemLocaleDate),this);
    lb[6]->setGeometry(10,330,250,30);
}
