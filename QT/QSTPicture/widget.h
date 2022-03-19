#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPaintEvent>
#include<QIcon>
#include<QToolButton>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    void DrawPixmap();
    void ImageMain();
    void IconMain();
    virtual void paintEvent(QPaintEvent *);
private:
    Ui::Widget *ui;
    QPixmap image1;
    QPixmap image2;
    QPixmap image3;
    QPixmap image4;
    QIcon* mIco;
};
#endif // WIDGET_H
