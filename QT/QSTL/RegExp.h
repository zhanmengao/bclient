#ifndef REGEXP_H
#define REGEXP_H
#include<QRegExp>
#include<stdio.h>

//使用正则表达式进行模式匹配
void QRegExpMain()
{
    QRegExp rx("^\\d\\d?$");                    //查找0-99的int值
    printf("%d rx.indexIn(123) \n",rx.indexIn("123"));                     //查找与模式匹配的单词
    printf("%d rx.indexIn(6) \n",rx.indexIn("6"));
}
#endif // REGEXP_H
