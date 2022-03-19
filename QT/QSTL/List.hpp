#ifndef LIST_HPP
#define LIST_HPP
#include<QList>
#include<QDate>
#include<QLinkedList>
#include<QVector>

//QList::双链表
//QLinkedList：单链表
//QVector:可变长数组

void ListMain()
{
    {
        QList<int> integerList;
        QList<QDate> dateList;
        QList<QString> list;

        //插入
        list<<"One"<<"Two"<<"Three";

        //读写值
        if(list[0] == "One")
        {
            list[0] = "Robert";
        }

        for(int i = 0;i<list.size();i++)
        {
            if(list.at(i) == "Two")
            {
                qDebug("Fount Jane at position %d",i);
            }
        }
    }
    {
        QLinkedList<int> integerList;
        QLinkedList<QTime> timeList;
        //插入
        QLinkedList<QString> list;
        list<<"One"<<"Two"<<"Three";
    }

}

void VectorMain()
{
    QVector<int> integerVector;
    QVector<QString> stringVector;

    //声明时分配大小
    QVector<QString> vector(200);
    //声明时分配大小并实现初始化
    QVector<QString> vector2(200,"Pass");

    //读写值
    vector[0] = "Liz";
    if(vector[0] == "Liz")
    {
        vector[0] = "Elizabeth";
    }
    //遍历和at
    for(auto it = vector.begin();it!=vector.end();it++)
    {
        if(*it == "Alfonso")
        {
            qDebug("Fount Alfonso at vector0");
        }
    }
}

#endif // LIST_HPP













