#ifndef QBYTE_H
#define QBYTE_H
#include<QByteArray>
#include<stdio.h>
#include<QByteArrayMatcher>
#include<QString>

//QByteArray:字节(char)数组（8位）
//QByteArrayMatcher:在字节数组里查找匹配的模式
void mainQByteArr()
{
    QByteArray ba("hello");
    for(int i = 0;i<ba.size();i++)
    {
        printf("%c",ba.at(i));          //数据访问用at
    }
    printf("\n");
    ba.resize(5);
    ba[0] = 0x3c;
    ba[1] = 0xb8;
    ba[2] = 0x64;
    ba[3] = 0x18;
    ba[4] = 0xca;
    for(int i = 0;i<ba.size();i++)
    {
        if(ba.at(i) >= 'a' && ba.at(i) <='f')
        {
            printf("Found character %c\n",ba.at(i));
        }
    }

    QByteArray ba1("ca\0r\0t");
    //size返回长度,constData返回C风格字符串
    printf("ba1 size: %u,data: %s \n",ba1.size(),ba1.constData());

    //手动指定大小去构造
    QByteArray ba2("ca\0r\0t",3);
    printf("ba2 size: %u,data: %s \n",ba2.size(),ba2.constData());

    //通过字节数组构造
    const char cart[] = {'c','a','\0','r','\0','t'};
    QByteArray ba3(cart,6);
    printf("ba3 size: %u,data: %s \n",ba3.size(),ba3.constData());
    QByteArray ba4 = QByteArray::fromRawData(cart,6);
    printf("ba4 size: %u,data: %s \n",ba4.size(),ba4.constData());

    //添加和替换
    QByteArray ba5("QAQ1234567",6);
    //在头部添加
    ba5.prepend("rock");
    //在尾部添加
    ba5.append("roll");
    printf("ba5 size: %u,data: %s \n",ba5.size(),ba5.constData());
    //将index 2开始的后5个下标替换为*
    ba5.replace(2,5,"*****");
    printf("ba5 size: %u,data: %s \n",ba5.size(),ba5.constData());

    //删除从第5开始的4个字节
    ba5.remove(5,4);
    printf("ba5 size: %u,data: %s \n",ba5.size(),ba5.constData());

    QByteArray ba6("We must be <b>bold</b>,very <b>bold</b>");
    int j = 0;
    //indexof:从头开始找
    while((j = ba6.indexOf("<b>",j))!=-1)
    {
        printf("Found <b> tag at index: %u\n",j);
        j++;
    }

    j = ba6.size();
    //lastIndexOf从末尾开始找
    while((j = ba6.lastIndexOf("<b>",j))!=-1)
    {
        printf("Found <b> tag at index: %u\n",j);
        j--;
    }
    printf("ba3 == ba4 %u\n",ba3 == ba4);
    printf("ba6.isEmpty() %u and ba6.isNull %u \n",ba6.isEmpty(),ba6.isNull());
    printf("QByteArray().isEmpty() %u and QByteArray().isNull %u \n",QByteArray("\0").isEmpty(),QByteArray("\0").isNull());

    //填充和截断
    QByteArray ba7("STARTTLS");
    //切断末两位
    ba7.chop(2);
    printf("ba7 size: %u,data: %s \n",ba7.size(),ba7.constData());
    //全部替换为0
    ba1.fill('0');
    printf("ba1 size: %u,data: %s \n",ba1.size(),ba1.constData());
    //替换为一个X
    ba2.fill('X',1);
    printf("ba2 size: %u,data: %s \n",ba2.size(),ba2.constData());

    //解码Base 64格式数据
    printf("fromBase64 data: %s \n",QByteArray::fromBase64("UXQgaXMgZ3JlYXQh").data());
    //从16进制数字转
    printf("fromHex data: %s \n",QByteArray::fromHex("517420697320677265617421").data());
    //从URL/URI编码转
    printf("fromPercentEncoding data: %s \n",QByteArray::fromPercentEncoding("Qt%20is%20great%33").data());

    QByteArray ba8("apple");
    printf("ba8.left(4) data: %s \n",ba8.left(4).constData());          //从左数
    printf("ba8.right(4) data: %s \n",ba8.right(4).constData());        //从右数
    printf("ba8.mid(4) data: %s \n",ba8.mid(4).constData());            //从中间数
    printf("ba8.leftJustified(4,'.') data: %s \n",ba8.leftJustified(8,'.').constData());


    QByteArray x("Say yea"),y("no");
    printf("ba8.replace(4,3,y) data: %s \n",x.replace(4,3,y).constData());      //替换

    //将str视为16进制转
    QByteArray str("FF");
    bool bOK;
    printf("str.toInt: %d \n",str.toInt(&bOK,16));                      //0xff
    printf("str.toLong: %d \n",str.toLong(&bOK,16));
    //将str视为10进制数转换
    str = "99";
    printf("str.toInt: %d \n",str.toInt(&bOK,10));                      //99 相当于atoi
    printf("str.toLong: %d \n",str.toLong(&bOK,10));                    //99

    //大小写
    printf("str.toLower() data: %s \n",str.toLower().constData());

    //QByteArray转QString
    QByteArray bytes("hello world");
    QString string = bytes;   // QByteArray转QString方法1
    string.prepend(bytes);// QByteArray转QString方法2
}


void ByteArrayMatcherMain()
{
    QByteArray x("hello Qt,nice to meet you.");
    QByteArray y("Qt");

    //在x里匹配y，从x的0索引开始找
    QByteArrayMatcher matcher(y);
    int index = matcher.indexIn(x,0);

    qDebug("index :%d ",index);
    qDebug("QByte :%c %c ",x.at(index),x.at(index+1));
}
#endif // QBYTE_H
