#ifndef QDRAW_HPP
#define QDRAW_HPP

#include"widget.h"
#include<QPainter>
#include<QKeySequence>
#include<QMargins>
#include<QPropertyAnimation>
#include<QMatrix>
#include<QMatrix4x4>
#include<QVector3D>
#include<QQuaternion>
void Widget::DrawType()
{
    {
        QFont selfFont("Times",10,QFont::Bold);
        QFont sansFont("Helvetica",20);
        QFont font;//实例化QFont对象
        //font.setFamily("微软雅黑");//字体
        //font.setPixelSize(25);//文字像素大小
        //font.setPointSize(20);//文字大小
        //font.setUnderline(true);//下划线
        //font.setStrikeOut(true);//中划线
        //font.setOverline(true);//上划线
        //font.setItalic(true);//斜体
        //font.setBold(true);//粗体
        // font.setStyle(QFont::StyleOblique);
        // font.setCapitalization(QFont::Capitalize);//首字母大写
        // font.setLetterSpacing(QFont::PercentageSpacing,200);//间距
    }
    {
        QKeySequence(tr("Ctrl+P"));                              //菜单快捷键
        QKeySequence(Qt::CTRL + Qt::Key_P);
    }
    {
        QMargins marg;                                       //指定矩形四个区域的边距值
    }
    {
        QPropertyAnimation animation;                           //表现动画在应用程序动画框架中的移动
        animation.setStartValue(0);
        animation.setEndValue(1000);
        animation.setDuration(1000);
        animation.setEasingCurve(QEasingCurve::InOutQuad);
    }
    {
        QPen pen(Qt::green,3,Qt::DashDotLine,Qt::RoundCap,Qt::RoundJoin);           //指定Pen风格，端点风格，连接风格
    }
    //矩阵，四元数，向量
    {
        QMatrix mat;                                            //矩阵类
        QMatrix4x4 mat4;
        QQuaternion q;                                      //四元数，表示X,Y,Z坐标和旋转角度
        QVector3D vec3;                                     //三维向量
        QVector3D result = (q*QQuaternion(0,vec3)*q.conjugate().vector());
        QTransform tr;                      //在2D里定义Pos,Scale,Rotate
    }
    {
        //坐标指针：int,int
        QPoint p;
        p.setX(p.x()+1);
        p+=QPoint(1,0);
        p.rx()++;
        QPoint p2(3,7);
        QPoint q(-1,4);
        p += q;
    }
    {
        //矩形
        QRect r1(100,200,11,16);
        QRect r2(QPoint(100,200),QSize(11,16));
    }
    {
        QSize size(100,10);
        size.rwidth()+=20;              //120,10.rwidth::拿到宽度的引用

        QSize t1(10,12);
        t1.scale(60,60,Qt::IgnoreAspectRatio);                  //缩放到60，60

        QSize t2(10,12);
        t2.scale(60,60,Qt::KeepAspectRatio);                    //50，60：保证高度，等比拉伸

        QSize t3(10,12);
        t3.scale(60,60,Qt::KeepAspectRatioByExpanding);             //60,72:保证宽度，等比拉伸
    }
}
#endif // QDRAW_HPP
