#ifndef VARIANT_H
#define VARIANT_H
#include<QObject>
#include<QVariant>
#include<stdio.h>
//QVariant联合体包含所有常用QT数据类型
void VariantMain()
{
    QVariant v(123);
    int x = v.toInt();
    printf("x:%d \n",v.toInt());
    v = QVariant("hello");                      //QByteArray
    printf("x:%s \n",v.toByteArray().constData());
    v = QVariant(QObject::tr("hello"));         //QString
    qDebug("x %s ",v.toString().toStdString().c_str());
    int y = v.toInt();
    printf("x:%d \n",v.toInt());
    QString s = v.toString();

    qDebug("Type is %s",v.typeName());
    v = v.toInt() + 100;
    v = QVariant(QStringList());
}
#endif // VARIANT_H
