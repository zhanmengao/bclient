#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"custom_cpu.h"
#include"custom_slider.h"
#include<QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void SliderChanged(int value);
private:
    custom_cpu *mCPU;
    custom_slider *mSlider;

    bool mEnbedded;
    QPixmap mDevice;        //mask窗口区域的背景图片资源
protected:
    void UpdateBackground();            //更改窗口样式
    virtual void paintEvent(QPaintEvent *event);
};
#endif // WIDGET_H
