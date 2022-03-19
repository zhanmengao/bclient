#include"widget.h"
#include <QPainter>
#include<QPicture>
#include"Pixmap.hpp"
//QPixmap在操作和显示图片效果好
//QImage在直接访问像素和连续使用IO速度快
//QPicture类使用独立于平台的IO设备实现序列化状态
void Widget::DrawPixmap()
{
    {
        QPainter painter(this);
        painter.drawPixmap(300,0,image1.width()/2,image1.height()/2,image1);

        //ICON
        QIcon icon("../resources/open.png");
        QPixmap pixmap = icon.pixmap(QSize(22,22),QIcon::Active,QIcon::On);
        painter.drawPixmap(230,0,pixmap.width(),pixmap.height(),pixmap);

        mIco = new QIcon(QString("/home/zhanmengao/VEAPPICO/ehjjmtngjcxksaeg.ico"));
        pixmap = mIco->pixmap(QSize(22,22),QIcon::Active,QIcon::On);
        painter.drawPixmap(230,30,pixmap.width(),pixmap.height(),pixmap);

        //Image
        QImage image = image1.toImage();
        painter.drawImage(300 + image1.width()/2,0,image);
        image.save("a.tga");


        //QImage操作像素
        QImage img(3,3,QImage::Format_RGB32);
        QRgb value = qRgb(189,149,39);
        img.setPixel(1,1,value);
        value = qRgb(122,163,39);
        image.setPixel(0,1,value);
        image.setPixel(1,0,value);
        value = qRgb(237,187,51);
        image.setPixel(2,1,value);
        painter.drawImage(230+pixmap.width(),0,img);

        image2 = PixmapTools::ScreenSharing();                  //截屏保存到pixmap
        qDebug("image.sizeInBytes: %d",image2.toImage().sizeInBytes());
        painter.drawPixmap(500,image1.height(),image2.width(),image2.height(),image2);
        painter.end();
    }
    //Picture
    {
        QPicture picture;
        QPainter painter;
        painter.begin(&picture);                        //绘制到picture上
        painter.drawEllipse(10,20,80,70);               //在pic上画个圆
        painter.end();
        picture.save("Drawing.pic");
    }
    {
        QPicture picture;
        picture.load("Drawing.pic");
        QPainter painter(this);
        painter.drawPicture(0,0,picture);
        painter.end();
    }


}
