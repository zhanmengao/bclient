#include"widget.h"
#include<QPainter>
#include"Pixmap.hpp"
/*
QImage::Format_RGB32，存入格式为B,G,R,A 对应 0,1,2,3
QImage::Format_RGB888，存入格式为R, G, B 对应 0,1,2
QImage::Format_Indexed8，需要设定颜色表，QVector<QRgb>
*/
void Widget::ImageMain()
{
    QImage image(3,3,QImage::Format_RGB32);     //根据图像宽高来构造一幅图像，程序会自动根据图像格式对齐图像数据

    //如果图像本身是32、24位的，程序中图像是32位的，
    //如果图像本身是8位、1位的，程序中对应为8位、1位。
    QImage image1 = QImage("../resources/browser.png");
    image = image.scaled(300, 300);         //图片尺寸调整
    QImage image2 = PixmapTools::ScreenSharing().toImage();

    QRgb value = qRgb(189,149,39);          //oxff bd 95 27
    image.setPixel(1,1,value);              //32位图像使用setPixel操作ARGB

    value = qRgb(122,163,39);               //创建rgb值
    image.setPixel(0,1,value);
    image.setPixel(1,0,value);

    value = qRgb(237,187,51);
    image.setPixel(2,1,value);

    qDebug("image2.sizeInBytes():%d,bytesPerLine():%d,width:%d,height:%d",
           image2.sizeInBytes(),image2.bytesPerLine(),image2.width(),image2.height());       //图片字节大小

    QImage pi3= image.convertToFormat(QImage::Format_Grayscale8); 	//转换为灰度图
    QImage pi4= pi3.rgbSwapped();   							//交换红色和蓝色通道
    pi4.invertPixels();    //反转所有像素的颜色，注意，该函数会破坏pi4(但不会破坏原始文件1z.png)

    //先转格式
    QImage smallImage = image2.convertToFormat(QImage::Format::Format_RGB888);
    qDebug("smallImage.sizeInBytes():%d,bytesPerLine():%d,width:%d,height:%d",
           smallImage.sizeInBytes(),smallImage.bytesPerLine(),smallImage.width(),smallImage.height());
    PixmapTools::compressImg(smallImage,Qt::SmoothTransformation,0,0,8196);
    //尝试存储转为网络
    auto pData = PixmapTools::getImageData(smallImage);
    smallImage = PixmapTools::getImage(pData);
    smallImage = PixmapTools::ReSize(smallImage);
    QPixmap tempPixmap = QPixmap::fromImage(smallImage);
    QPainter painter(this);
    painter.drawPixmap(0,200,tempPixmap);
    qDebug("smallImage.sizeInBytes():%d,pData.size():%d,width:%d,height:%d",
           smallImage.sizeInBytes(),pData.size(),smallImage.width(),smallImage.height());
    painter.end();
    qDebug("\n");
}
