#ifndef PIXMAP_HPP
#define PIXMAP_HPP
#include <QPixmap>
#include<QApplication>
#include<QDesktopWidget>
#include<QScreen>
#include<QWindow>
#include<QImage>
#include<QImageReader>
#include<QPainter>
#include <QFile>
#include<QBuffer>
#include<QList>
#include<string>
class PixmapTools
{
public:
    static  bool ScreenSharing(QList<QList<QPixmap>>& pix,int widthCount,int HeightCount)
    {
        QList<QScreen*> screens = QGuiApplication::screens();
        //显示器
        for(int i = 0;i<screens.size();i++)
        {
            QList<QPixmap> pixlist;
            ScreenSharing(screens[i],pixlist,widthCount,HeightCount);
            pix.push_back(pixlist);
        }
        return true;
    }
    static  bool ScreenSharing(QScreen* s,QList<QPixmap>& pixlist, int widthCount, int HeightCount)
    {
        int w = s->size().width();
        int h = s->size().height();
        //行
        for(int i = 0;i<widthCount;i++)
        {
            //列
            for(int j = 0;j<HeightCount;j++)
            {
                QPixmap pix = ScreenSharing(0,j*w/ widthCount,i*h/ HeightCount,w/ widthCount,h/ HeightCount);
                pixlist.push_back(pix);
            }
        }
        return true;
    }
    static QPixmap ScreenSharing(WId wid = 0,int x = 0,int y = 0, int w = -1,int h = -1)
    {
        //return QPixmap::grabWindow(w);                //已过时
        QScreen *screen = QGuiApplication::primaryScreen();
        return screen->grabWindow(wid,x,y,w,h);
    }
    static QImage ReSize(const char* picPath,unsigned width,unsigned height)
    {
        QImageReader imgReader(picPath);
        imgReader.setScaledSize(QSize(width, height));
        return imgReader.read();
    }
    static QImage ReSize(const QImage& img, unsigned width = 0, unsigned height = 0, Qt::TransformationMode mode = Qt::SmoothTransformation)
    {
        if (width == 0)
        {
            width = img.width() / 2;
        }
        if (height == 0)
        {
            height = img.height() / 2;
        }
        return img.scaled(width, height, Qt::KeepAspectRatio, mode);
    }

    //scaled，用参数指定”快速缩放(FastTransformation)”还是”平滑缩放(SmoothTransformation)”
    static bool compressImg(QImage& img,Qt::TransformationMode mode = Qt::SmoothTransformation,
                            int quality = -1,unsigned width = 0,unsigned height = 0)
    {
        img = ReSize(img, width, height, mode);
        img = img.convertToFormat(QImage::Format_Grayscale8);
        img.save("out.png", "PNG", quality);
        return img.load("out.png");
    }

    //转化为灰度图
    static QImage * greyScale(QImage * origin)
    {
        QImage * newImage = new QImage(origin->width(), origin->height(), QImage::Format_ARGB32);

        QColor oldColor;

        for(int x = 0; x<newImage->width(); x++)
        {
            for(int y = 0; y<newImage->height(); y++)
            {
                oldColor = QColor(origin->pixel(x,y));
                int average = (oldColor.red()+oldColor.green()+oldColor.blue())/3;
                newImage->setPixel(x,y,qRgb(average,average,average));
            }
        }
        return newImage;
    }

    static QImage* brightness(QImage* Img, int iBrightValue = 30)
    {
        int red, green, blue;
        int pixels = Img->width() * Img->height();
        unsigned int *data = (unsigned int *)Img->bits();

        for (int i = 0; i < pixels; ++i)
        {
            red= qRed(data[i])+ iBrightValue;
            red = (red < 0x00) ? 0x00 : (red > 0xff) ? 0xff : red;
            green= qGreen(data[i]) + iBrightValue;
            green = (green < 0x00) ? 0x00 : (green > 0xff) ? 0xff : green;
            blue= qBlue(data[i]) + iBrightValue;
            blue =  (blue  < 0x00) ? 0x00 : (blue  > 0xff) ? 0xff : blue ;
            data[i] = qRgba(red, green, blue, qAlpha(data[i]));
        }

        return Img;
    }
    //暖色调
    static QImage * warm(QImage * origin,int delta = 30)
    {
        QImage *newImage = new QImage(origin->width(), origin->height(), QImage::Format_ARGB32);
        QColor oldColor;
        int r,g,b;
        for(int x=0; x<newImage->width(); x++)
        {
            for(int y=0; y<newImage->height(); y++)
            {
                oldColor = QColor(origin->pixel(x,y));
                r = oldColor.red() + delta;
                g = oldColor.green() + delta;
                b = oldColor.blue();
                //we check if the new values are between 0 and 255
                r = qBound(0, r, 255);
                g = qBound(0, g, 255);
                newImage->setPixel(x,y, qRgb(r,g,b));
            }
        }

        return newImage;
    }
    //冷色调
    static QImage * cool(QImage * origin,int delta = 30)
    {
        QImage *newImage = new QImage(origin->width(), origin->height(), QImage::Format_ARGB32);

        QColor oldColor;
        int r,g,b;

        for(int x=0; x<newImage->width(); x++)
        {
            for(int y=0; y<newImage->height(); y++)
            {
                oldColor = QColor(origin->pixel(x,y));

                r = oldColor.red();
                g = oldColor.green();
                b = oldColor.blue()+delta;

                //we check if the new value is between 0 and 255
                b = qBound(0, b, 255);

                newImage->setPixel(x,y, qRgb(r,g,b));
            }
        }

        return newImage;
    }
    //饱和度
    static QImage * saturation(QImage * origin,int delta = 30)
    {
        QImage * newImage = new QImage(origin->width(), origin->height(), QImage::Format_ARGB32);

        QColor oldColor;
        QColor newColor;
        int h,s,l;

        for(int x=0; x<newImage->width(); x++)
        {
            for(int y=0; y<newImage->height(); y++)
            {
                oldColor = QColor(origin->pixel(x,y));

                newColor = oldColor.toHsl();
                h = newColor.hue();
                s = newColor.saturation()+delta;
                l = newColor.lightness();

                //we check if the new value is between 0 and 255
                s = qBound(0, s, 255);

                newColor.setHsl(h, s, l);

                newImage->setPixel(x, y, qRgb(newColor.red(), newColor.green(), newColor.blue()));
            }
        }

        return newImage;
    }
    //模糊
    static QImage * blur(QImage * origin)
    {
        QImage * newImage = new QImage(*origin);

        int kernel [5][5]= {{0,0,1,0,0},
                            {0,1,3,1,0},
                            {1,3,7,3,1},
                            {0,1,3,1,0},
                            {0,0,1,0,0}};
        int kernelSize = 5;
        int sumKernel = 27;
        int r,g,b;
        QColor color;

        for(int x=kernelSize/2; x<newImage->width()-(kernelSize/2); x++)
        {
            for(int y=kernelSize/2; y<newImage->height()-(kernelSize/2); y++)
            {

                r = 0;
                g = 0;
                b = 0;

                for(int i = -kernelSize/2; i<= kernelSize/2; i++)
                {
                    for(int j = -kernelSize/2; j<= kernelSize/2; j++)
                    {
                        color = QColor(origin->pixel(x+i, y+j));
                        r += color.red()*kernel[kernelSize/2+i][kernelSize/2+j];
                        g += color.green()*kernel[kernelSize/2+i][kernelSize/2+j];
                        b += color.blue()*kernel[kernelSize/2+i][kernelSize/2+j];
                    }
                }

                r = qBound(0, r/sumKernel, 255);
                g = qBound(0, g/sumKernel, 255);
                b = qBound(0, b/sumKernel, 255);

                newImage->setPixel(x,y, qRgb(r,g,b));

            }
        }
        return newImage;
    }
    //锐化
    static QImage * sharpen(QImage * origin)
    {
        QImage * newImage = new QImage(* origin);

        int kernel [3][3]= {{0,-1,0},
                            {-1,5,-1},
                            {0,-1,0}};
        int kernelSize = 3;
        int sumKernel = 1;
        int r,g,b;
        QColor color;

        for(int x=kernelSize/2; x<newImage->width()-(kernelSize/2); x++)
        {
            for(int y=kernelSize/2; y<newImage->height()-(kernelSize/2); y++)
            {

                r = 0;
                g = 0;
                b = 0;

                for(int i = -kernelSize/2; i<= kernelSize/2; i++)
                {
                    for(int j = -kernelSize/2; j<= kernelSize/2; j++)
                    {
                        color = QColor(origin->pixel(x+i, y+j));
                        r += color.red()*kernel[kernelSize/2+i][kernelSize/2+j];
                        g += color.green()*kernel[kernelSize/2+i][kernelSize/2+j];
                        b += color.blue()*kernel[kernelSize/2+i][kernelSize/2+j];
                    }
                }

                r = qBound(0, r/sumKernel, 255);
                g = qBound(0, g/sumKernel, 255);
                b = qBound(0, b/sumKernel, 255);

                newImage->setPixel(x,y, qRgb(r,g,b));

            }
        }
        return newImage;
    }
    //添加相框
    static QImage * drawFrame(QImage * origin)
    {
        QImage * newImage = new QImage(* origin);
        QPainter painter;

        painter.begin(newImage);

        painter.drawImage(0,0, QImage("../resources/frame.png"));

        painter.end();

        return newImage;
    }

    //金属效果
    static QImage * metal(QImage * origin)
    {
        QImage * newImage = new QImage(":images/metal.png");
        QImage * darkImage = brightness(origin,-100);      //调整亮度
        QImage * greyImage = greyScale(darkImage);
        QPainter painter;

        painter.begin(newImage);

        painter.setOpacity(0.5);
        painter.drawImage(0, 0, * greyImage);

        painter.end();

        delete greyImage;
        delete darkImage;

        return newImage;
    }
    //模糊的边框
    static QImage * blurFrame(QImage * origin)
    {
        QImage * newImage = new QImage(* origin);
        QImage * blurredImage = blur(newImage);
        QImage * mask = new QImage(":images/mask.png");
        QPainter painter;

        //Using the composition mode SourceAtop we get a blurred frame stored in QImage mask
        painter.begin(mask);

        painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
        painter.drawImage(0, 0, * blurredImage);

        painter.end();

        //With our new frame we simply draw it over the original image
        painter.begin(newImage);

        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
        painter.drawImage(0, 0, * mask);

        painter.end();

        delete mask;
        delete blurredImage;

        return newImage;
    }
    static QByteArray getImageData(const QImage &image)
    {
        QByteArray imageData;
        QBuffer buffer(&imageData);
        buffer.open(QIODevice::WriteOnly);
        image.save(&buffer, "png");
        //imageData = imageData.toBase64();
        return imageData;
    }
    static QImage getImage(const QByteArray &data)
    {
        // QByteArray imageData = QByteArray::fromBase64(data);
        QImage image;
        image.loadFromData(data,"png");
        return image;
    }
    static QImage ToImage(const QPixmap& pix)
    {
        return pix.toImage();
    }
    static QPixmap ToPixmap(const QImage& img,QPixmap* pix = nullptr)
    {
        if (pix != nullptr)
        {
            *pix = QPixmap::fromImage(img);
            return *pix;
        }
        else
        {
            return QPixmap::fromImage(img);
        }
    }
};
#endif // PIXMAP_HPP
