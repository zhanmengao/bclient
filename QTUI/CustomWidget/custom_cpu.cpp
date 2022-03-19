#include"custom_cpu.h"
#include<QPainter>

custom_cpu::custom_cpu(QWidget* parent):QWidget(parent),mWidth(80),mHeight(100)
{
    resize(mWidth,mHeight);
    setFixedSize(mWidth,mHeight);           //通过绝对坐标设x0，y0
    cpu_use = 10;
}
void custom_cpu::set_use(int cpuUse)
{
    cpu_use = cpuUse;
    repaint();                      //重绘
}

//重写重绘事件逻辑
void custom_cpu::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setPen(QColor(0,0,0));          //图形外轮廓线颜色
    painter.setBrush(QColor(0,0,0));        //图形内部填充颜色
    painter.drawRect(0,0,mWidth,mHeight);       //利用高度和宽度绘制矩形

    for(int i = 21;i>=0;i--)
    {
        if(cpu_use> i)
        {
            painter.setBrush(QColor(153,255,0));       //已使用的CPU用绿色矩形表示
        }
        else
        {
            painter.setBrush(QColor(51,102,0));         //未使用的CPU用深绿色矩形表示
        }
        painter.drawRect(6,mHeight-8-i*4,30,3);
        painter.drawRect(43,mHeight-8-i*4,30,3);
    }
}

