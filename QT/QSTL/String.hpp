#ifndef STRING_HPP
#define STRING_HPP
#include<QString>
#include<QLatin1String>
#include<QLocale>
#include<QStringList>
//QString:16位QChar字符串(UTF16),QChar:Unicode4.0
//QChar:16位Unicode
//QLatin1String：US_ASCII/Latin-1编码的类
//QLocale将数字和字符转换为多种语言
//QStringList继承自QList<QString>
void StringMain()
{
    QString str = "Hello";

    const QChar data[4] = {0x0055,0x006e,0x10e3,0x03a3};

    QString str2(data,4);
    qDebug("str2: %s",str2.toStdString().c_str());

    //使用fromUtf8替换const char常量
    const char* data2 = "qaq123456564";
    QString str3 = QString::fromUtf8(data2,strlen(data2));
    qDebug("str3: %s",str3.toStdString().c_str());

    //将QChar存储到数组的特定位置
    QString str4;
    str4.resize(2);
    str4[0] = QChar('U');
    str4[1] = QChar('n');
    qDebug("str4: %s",str4.toStdString().c_str());

    //比较字符串
    if(str4 == "SSS" || str4 == "Un")
    {
        qDebug("str4 == SSS || str4 == Un");
    }

    //字符串拼接
    str4.prepend("Begin");
    str4.append("End");
    //改变特定位置的字符串
    str4.replace(5,3,"&");
    qDebug("str4: %s",str4.toStdString().c_str());

    QString str5 = "We must be <b>bold</b>,very <b>bold</b>";
    int j = 0;
    //indexof:从头开始找
    while((j = str5.indexOf("<b>",j))!=-1)
    {
        printf("Found <b> tag at index: %u\n",j);
        j++;
    }

    //字符串长度，返回字符，比较字符
    for(int i = 0;i<str5.size();i++)
    {
        if(str5.at(i) >= 'a' && str5.at(i) <='f')
        {
            printf("Found character %c\n",str5.at(i));
        }
    }

    //判断
    qDebug("\" \" is isNull %u",QString(" ").isNull());
    qDebug("\" \" is isEmpty %u",QString(" ").isEmpty());
    qDebug("\"\" is isNull %u",QString("").isNull());
    qDebug("\"\" is isEmpty %u",QString("").isEmpty());

    //范围显示
    QString si = "10";
    QString total = "25";
    QString fileName = "test.cpp";
    QString status = QString("Processing file %1 of %2 : %3").arg(si).arg(total).arg(fileName);
    qDebug("status = %s",status.toStdString().c_str());

    //转QByteArray
    QByteArray bytes = str.toUtf8(); // QString转QByteArray方法1
    QByteArray bytes2 = str.toLatin1();  // QString转QByteArray方法2
}

void substrMain()
{
    QString appclusterid = "1234567&7654321";
    int pos = appclusterid.indexOf('&');
    qDebug("%s",appclusterid.mid(0,pos).toLocal8Bit().data());
    qDebug("%s",appclusterid.mid(pos + 1,appclusterid.size()).toLocal8Bit().data());
}

void QCharMain()
{
    QString str = "Hello Qt";
    QChar *data = str.data();
    QString str_display;
    while(!data->isNull())
    {
        //返回字符Unicode表示
        str_display.append(data->unicode());
        ++data;
    }
    qDebug("str_display.toStdString().data() = %s",str_display.toStdString().data());
}

void QLatin1StringMain()
{
    QLatin1String latin("Qt");
    QString str = QString("Qt");
    if(str == latin)
    {
        qDebug("str == latin");
    }
    else
    {
        qDebug("str != latin");
    }

    if(latin == str)
    {
        qDebug("latin == str");
    }
    else
    {
        qDebug("latin != str");
    }
}
#define CHECK_D(ok,d) if(ok) \
{\
    qDebug("val = %lf",d); \
    }\
    else\
{\
    qDebug("toDouble Fail");\
    }
void QLocaleMain()
{
    double d;
    bool ok;
    QLocale::setDefault(QLocale::C);
    //尝试将String转换为Double
    d = QString("1234,56").toDouble(&ok);                //false
    CHECK_D(ok,d);
    d = QString("1234.56").toDouble(&ok);               //ok,d = 1234.56
    CHECK_D(ok,d);

    QLocale::setDefault(QLocale::German);
    d = QString("1234,56").toDouble(&ok);               //ok,d = 1234.56
    CHECK_D(ok,d);
    d = QString("1234.56").toDouble(&ok);               //ok,d = 1234.56
    CHECK_D(ok,d);
}

void QStringListMain()
{
    QStringList strList;
    strList<<"Monday"<<"Tuesday"<<"Wednesday";

    //在每个数字间隔append一个,返回一个QString
    QString str;
    str = strList.join(",");
    qDebug("strList.join(\",\") %s",str.toStdString().c_str());
}

void QStringMatcherMain()
{
    QString x("hello Qt,nice to meet you");
    QString y("Qt");

    //在x里匹配y，从x的0索引开始找
    QStringMatcher matcher(y);
    int index = matcher.indexIn(x,0);
    qDebug("index :%d ",index);
    qDebug("QStringMatcher :%c %c ",x.at(index),x.at(index+1));
}

void QstringSprit()
{
    QString path = "/home/a.txt";
    QString expand;
    int idx = path.indexOf('.');
    if(idx>=0)
    {
        expand = path.right(path.size() - idx -1);
    }
    qDebug("expand %s",expand.toStdString().c_str());
}
#endif // STRING_HPP
