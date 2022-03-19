#ifndef QDRAW_HPP
#define QDRAW_HPP

#include"widget.h"
#include<QPainter>
void Widget::Brush()
{
    {
        //QBrush用于定义QPainter图形填充模式，可以表现风格、颜色、斜度、质地
        QPainter painter(this);
        painter.setBrush(Qt::blue);
        painter.setPen(Qt::darkRed);
        painter.drawRect(0,0,100,100);

        painter.setBrush(Qt::NoBrush);
        painter.setPen(Qt::darkGreen);
        painter.drawRect(100,0,100,100);
        painter.end();
    }
    {
        QPainter painter(this);
        painter.setPen(QPen(Qt::blue,1,Qt::DashLine));                  //Pen的风格
        painter.drawRect(0,100,100,100);
        painter.rotate(45);
        painter.setFont(QFont("Helvetica",20));
        painter.setPen(QPen(Qt::black,1));
        painter.drawText(100,100,"QMatrix");
        painter.drawEllipse(200,50,80,70);               //画个圆
        painter.end();
    }
    {
        QRegion r1(QRect(100,100,200,80),QRegion::Ellipse);                      //定义圆形剪切板区域
        QRegion r2(QRect(100,200,90,30));
        QRegion r3 = r1.intersected(r2);

        QPainter painter(this);
        painter.setClipRegion(r3);
        painter.end();
    }
    {
        QPainter painter(this);
        painter.setPen(QPen(Qt::blue,1,Qt::DashLine));
        painter.drawRect(100,100,100,100);
        painter.rotate(45);
        painter.setFont(QFont("Helvetica",24));
        painter.setPen(QPen(Qt::black,1));
        painter.drawText(20,10,"QTransform");
    }
}
#endif // QDRAW_HPP
