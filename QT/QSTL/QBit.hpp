#ifndef QARRAY_H
#define QARRAY_H
#include<QBitArray>
void mainArray()
{
    //位数组：0/1
    QBitArray ba(5);            //长度为5
    ba.resize(3);
    ba[0] = true;
    ba[1] = false;
    ba[2] = true;

    QBitArray x(5);
    x.setBit(3,true);       //设置index为3的位为1     x:[0,0,0,1,0]
    QBitArray y(5);
    y.setBit(4,true);
    x|= y;          //x和y做位或    x:[0,0,0,1,1]

    //区分数组特定位置的NULL和EMPTY数组变量
    printf("QBitArray().isNull() %u \n",QBitArray().isNull());
    printf("QBitArray().isEmpty() %u \n",QBitArray().isEmpty());
    printf("QBitArray(0).isNull() %u \n",QBitArray(0).isNull());
    printf("QBitArray(0).isEmpty() %u \n",QBitArray(0).isEmpty());
    printf("QBitArray(3).isNull() %u \n",QBitArray(3).isNull());
    printf("QBitArray(3).isEmpty() %u \n",QBitArray(3).isEmpty());

    ba.fill(true);                  //ba[1,1,1,1,1,]

    ba.fill(false,2);               //ba[0,0]
}
#endif // QARRAY_H
