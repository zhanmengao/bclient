#ifndef ALGORITHM_H
#define ALGORITHM_H
#include<stdio.h>
#include<QtMath>
#include<QFile>



void mainAl()
{
    printf("abs: %d\n",qAbs(-4));                   //绝对值

    printf("qBound: %d \n",qBound(2,10,6));         //求中间值->qMax(min, qMin(max, val))

    printf("qFuzzyCompare %d \n",qFuzzyCompare(0.0,1.0e-200));          //比较浮点数

    printf("qMin: %d \n",qMin(10,6));

    printf("qMax: %d \n",qMax(2,6));

    qreal valA = 42949672960.3;         //typedef double qreal;
    printf("qRound64: %lld \n",qRound64(valA));             //四舍五入，返回long long类型
    printf("qRound: %d \n",qRound(2.7));            //四舍五入，返回int类型

}
#endif // ALGORITHM_H
