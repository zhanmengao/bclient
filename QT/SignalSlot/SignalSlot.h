#ifndef SIGNALSLOT_H
#define SIGNALSLOT_H
#include<QObject>

class SignalSlot:public QObject
{
    Q_OBJECT
public:
    SignalSlot():mVal(0)
    {
    }
    inline int Value() const
    {
        return mVal;
    }
    //定义槽函数
public slots:
    void SetValue(int val)
    {
        mVal = val;
        emit ValueChanged(mVal);            //发信号
    }
    //定义信号函数
signals:
    void ValueChanged(int newValue);
private:
    int mVal;
};

#endif // SIGNALSLOT_H
