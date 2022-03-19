#include"custom_slider.h"
#include<QPainter>


custom_slider::custom_slider(QWidget* parent):QWidget(parent)
{
}
void custom_slider::SliderResize(int width,int height)
{
    mWidth = width;
    mHeight = height;
    resize(width,height);
    setFixedSize(width,height);
    yPos = 0;
    mSliderWidth = 24;
    mSliderHeight = 16;
}
void custom_slider::SetMax(float val)
{
    mMax = val;
}
void custom_slider::SetMin(float val)
{
    mMin = val;
}
void custom_slider::SetValue(float val)
{
    mCurrentVal = val;
    float percent = (100.0f) / mMax;           //百分之多少
    yPos = percent * mCurrentVal;
    yPos = abs(yPos- mHeight - mSliderHeight/2);
}
int custom_slider::Current() const
{
    return mCurrentVal;
}
void custom_slider::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QColor(255,255,255));
    painter.setBrush(QColor(255,255,255));
    painter.drawRect(12,0,0,mHeight);

    QImage image("../resources/slider-handle.png");
    painter.drawImage(0,yPos,image);
}
void custom_slider::mouseMoveEvent(QMouseEvent* event)
{
    //如果用鼠标拖拽刻度区域，则会计算刻度的Y坐标，发送信号
    Q_UNUSED(event);
    if(event->buttons() & Qt::LeftButton)
    {
        if(event->pos().x() >=0 && event->pos().x() <= mWidth &&
                event->pos().y() >= 0 && event->pos().y() <= mHeight)
        {
            if((event->pos().y() - mSliderHeight/2) >= 0 &&
                    (event->pos().y() + mSliderHeight/2 <=mHeight ))
            {

                yPos = event->pos().y() - mSliderHeight/2;
                float percent1 = yPos / 84 *100;
                float percent2 = (100 / mMax);
                int percent3 = percent1 /percent2;
                percent3 = abs(percent3 - mMax);

                emit valuechanged(percent3);        //发送信号
                repaint();
            }
        }
    }
}
