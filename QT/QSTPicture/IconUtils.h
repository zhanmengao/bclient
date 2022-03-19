#ifndef ICONUTILS_H
#define ICONUTILS_H
#include<QPixmap>

class IconUtils
{
public:
    static QPixmap GetIcon(const QString& path,int w, int h)
    {
        QImage image2;
        image2.load(path);
        QImage result2 = image2.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        return QPixmap::fromImage(result2);
    }
};

#endif // ICONUTILS_H
