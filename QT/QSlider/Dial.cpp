#include"DialWidget.h"

DialWidget::DialWidget(QWidget *parent)
    : QWidget(parent)
{

}
void DialWidget::InitDial()
{
    unsigned int xPos = 30;
    for(int i = 0;i<3;i++,xPos+=110)
    {
        mDial[i] = new QDial(this);
        mDial[i]->setRange(0,100);     //值的范围
        mDial[i]->setGeometry(xPos,30,100,100);
    }

    mDial[0]->setNotchesVisible(true);     //是否显示刻度

    connect(mDial[0], &QDial::valueChanged, this, &(this->OnVolumeChanged));
}
void DialWidget::OnVolumeChanged()
{
    qDebug("volue:%d",mDial[0]->value());
}
DialWidget::~DialWidget()
{
}
