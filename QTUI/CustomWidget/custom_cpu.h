#ifndef CUSTOM_CPU_H
#define CUSTOM_CPU_H
#include<QWidget>

class custom_cpu:public QWidget
{
    Q_OBJECT
public:
    custom_cpu(QWidget* parent = NULL);
    void set_use(int cpuUse);
private:
    int mWidth;
    int mHeight;
    int cpu_use;
protected:
    virtual void paintEvent(QPaintEvent *event);
};

#endif // CUSTOM_CPU_H
