#ifndef QDRAW_HPP
#define QDRAW_HPP

#include"widget.h"
#include<QPainter>
#include<QKeySequence>
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
    QFont selfFont("Times",10,QFont::Bold);
    QFont sansFont("Helvetica",20);
    QKeySequence(tr("Ctrl+P"));                              //菜单快捷键
    QKeySequence(Qt::CTRL + Qt::Key_P);
    {
        QPainter painter(this);
        painter.setPen(QPen(Qt::blue,1,Qt::DashLine));                  //Pen的风格
        painter.drawRect(0,100,100,100);
        painter.rotate(45);
        painter.setFont(sansFont);
        painter.setPen(QPen(Qt::black,1));
        painter.drawText(100,100,"QMatrix");
        painter.end();
    }


}
#endif // QDRAW_HPP
