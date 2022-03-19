#include"widget.h"
#include <QPainter>
#include"Pixmap.hpp"
//QPixmap在操作和显示图片效果好
//QImage在直接访问像素和连续使用IO速度快
void Widget::DrawPixmap()
{
    image2 = PixmapTools::ScreenSharing();                  //截屏保存到pixmap

    QPainter painter(this);
    painter.drawPixmap(300,0,image1.width()/2,image1.height()/2,image1);

    //ICON
    QIcon icon("../resources/open.png");
    QPixmap pixmap = icon.pixmap(QSize(22,22),QIcon::Active,QIcon::On);
    painter.drawPixmap(230,0,pixmap.width(),pixmap.height(),pixmap);

    //Image
    QImage image = image1.toImage();
    painter.drawImage(300 + image1.width()/2,0,image);

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

    qDebug("image.sizeInBytes: %d",image2.toImage().sizeInBytes());
    image.save("a.tga");
    painter.drawPixmap(500,image1.height(),image2.width(),image2.height(),image2);





    painter.end();
}
