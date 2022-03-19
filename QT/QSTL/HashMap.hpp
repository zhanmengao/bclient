#ifndef HASHMAP_H
#define HASHMAP_H

#include<QMultiHash>
#include<QMultiMap>
#include<QSet>
//QHash：散列表，Key不重复
//QMultiHash 散列，可重复
//QMap:红黑树，Key不重复
//QMultiMap：红黑树 Key可重复
//QSet:只有Key的QHash
template<class K,class V>
QPair<K,V> GetPair(const K& key,const V& val)
{
    QPair<K,V> pair;
    pair.first = key;
    pair.second = val;
    return pair;
}
void HashMain()
{
    QHash<QString,int> hash;
    //通过[]插入值或者修改值
    hash["one"] = 1;
    hash["two"] = 2;
    hash["three"] = 3;
    //insert插入
    hash.insert("twelve",12);
    hash.insertMulti("twelve",12);                  //重复插入
    //获得值
    int num1 = hash["twelve"];
    int num2 = hash.value("twelve");
    printf("-----------------------QHash-------------------------\n");
    for(auto it = hash.begin();it!=hash.end();it++)
    {
        qDebug("key %s val %d",it.key().toStdString().c_str(),it.value());
    }


    //可插入同Key项
    QMultiHash<QString,int> mulHash1,mulHash2,mulHash3;
    mulHash1.insert("plenty",100);
    mulHash1.insert("plenty",100);
    mulHash2.insert("plenty",5000);
    mulHash3 = mulHash1 + mulHash2;
    printf("-----------------------QMultiHash-------------------------\n");
    for(auto it = mulHash3.begin();it!=mulHash3.end();it++)
    {
        qDebug("key %s val %d",it.key().toStdString().c_str(),it.value());
    }
    //获得值，是一个List
    QList<int> values = mulHash3.values("plenty");
    for(int i = 0;i<values.size();i++)
    {
        qDebug("listval[%d] %d",i,values[i]);
    }
}

void MapMain()
{
    QMap<QString,int> map;
    //通过[]插入值或者修改值
    map["one"] = 1;
    map["two"] = 2;
    map["three"] = 3;
    //insert插入
    map.insert("twelve",12);
    //获得值
    int num1 = map["twelve"];
    int num2 = map.value("twelve");
    map.insertMulti("twelve",12);                  //重复插入
    printf("-----------------------QMap-------------------------\n");
    for(auto it = map.begin();it!=map.end();it++)
    {
        qDebug("key %s val %d",it.key().toStdString().c_str(),it.value());
    }

    //可插入同Key项
    QMultiMap<QString,int> mulMap1,mulMap2,mulMap3;
    mulMap1.insert("plenty",100);
    mulMap1.insert("plenty",100);
    mulMap2.insert("plenty",5000);
    mulMap3 = mulMap1 + mulMap2;
    printf("-----------------------QMultiMap-------------------------\n");
    for(auto it = mulMap3.begin();it!=mulMap3.end();it++)
    {
        qDebug("key %s val %d",it.key().toStdString().c_str(),it.value());
    }
    //获得值，是一个List
    QList<int> values = mulMap3.values("plenty");
    for(int i = 0;i<values.size();i++)
    {
        qDebug("listval[%d] %d",i,values[i]);
    }
}

void SetMain()
{
    QSet<QString> set;
    set.insert("One");
    set.insert("Two");
    set.insert("Three");
    set<<"twelve"<<"fifteen"<<"nineteen";
}
#endif // HASHMAP_H
