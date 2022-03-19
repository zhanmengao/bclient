#include "widget.h"
#include "ui_widget.h"
#include<QBitmap>
#include<string>

//FramelessWindowHint:不显示窗口标题栏
Widget::Widget(QWidget *parent)
    : QWidget(NULL,Qt::FramelessWindowHint),mEnbedded(false)
{
    Q_UNUSED(parent);
    UpdateBackground();
    setWindowTitle(tr("Custom Widget"));

    mSlider = new custom_slider(this);
    mSlider->SliderResize(24,100);
    mSlider->SetMax(22);
    mSlider->SetMin(0);
    mSlider->SetValue(12);
    mSlider->setGeometry(130,100,24,100);

    mCPU = new custom_cpu(this);
    mCPU->set_use(mSlider->Current());
    mCPU->setGeometry(40, 100, 80, 100);
    //关联自己的回调函数
    connect(mSlider,&custom_slider::valuechanged,this,&Widget::SliderChanged);
}
void Widget::UpdateBackground()
{
    mDevice = QPixmap("../resources/background.png","png");
    QBitmap bitmap = mDevice.createHeuristicMask();         //返回位图
    setFixedSize(mDevice.size());
    setMask(bitmap);                        //对控件实现Mask
    update();
}
void Widget::paintEvent(QPaintEvent *event)
{

}
void Widget::SliderChanged(int value)
{
    mCPU->set_use(value);
    qDebug(("value:" + std::to_string(value)).c_str());
}
Widget::~Widget()
{
}

