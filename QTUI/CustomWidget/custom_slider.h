#ifndef CUSTOM_SLIDER_H
#define CUSTOM_SLIDER_H
#include<QWidget>
#include<QMouseEvent>
class custom_slider:public QWidget
{
    Q_OBJECT
public:
    custom_slider(QWidget* parent = NULL);
    void SliderResize(int width,int height);        //控件大小
    void SetMax(float val);
    void SetMin(float val);
    void SetValue(float val);
    int Current() const;
signals:
    void valuechanged(int value);
private:
    int mWidth;
    int mHeight;
    float mMax;
    float mMin;
    float mCurrentVal;

    float yPos;
    float mSliderWidth,mSliderHeight;
protected:
    virtual void paintEvent(QPaintEvent *event);            //重绘
    virtual void mouseMoveEvent(QMouseEvent* event);        //碰撞检测
};
#endif // CUSTOM_SLIDER_H
