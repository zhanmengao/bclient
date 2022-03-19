#include"SliderWidget.h"


void SliderWidget::InitSlider()
{
    int xPos = 20, yPos = 20,labXPos = 20;;
    for(int i = 0;i<3;i++)
    {
        sliV[i] = new QSlider(Qt::Vertical,this);
        sliV[i]->setGeometry(xPos,20,30,80);
        xPos+=30;
        sliV[i]->setRange(0, 100);
        sliV[i]->setValue(10*i);

        lbl[i] = new QLabel(QString("%1").arg(sliV[i]->value()), this);
        lbl[i]->setGeometry(labXPos+10, 100, 30, 40);
        labXPos += 30;
    }
    for(int i = 0;i<3;i++)
    {
        sliH[i] = new QSlider(Qt::Horizontal,this);
        sliH[i]->setGeometry(130,yPos,80,30);
        yPos+=30;
        sliH[i]->setRange(0, 100);
        sliH[i]->setValue(20*i);
    }
    connect(sliV[0], SIGNAL(valueChanged(int)), this,
                       SLOT(valueChanged1(int)));

    connect(sliV[1], SIGNAL(valueChanged(int)), this,
                       SLOT(valueChanged2(int)));

    connect(sliV[2], SIGNAL(valueChanged(int)), this,
                       SLOT(valueChanged3(int)));
}
void SliderWidget::valueChanged1(int value)
{
    lbl[0]->setText(QString("%1").arg(value));
    sliH[0]->setValue(100-sliV[0]->value());
}

void SliderWidget::valueChanged2(int value)
{
    lbl[1]->setText(QString("%1").arg(value));
    sliH[1]->setValue(100-sliV[1]->value());
}

void SliderWidget::valueChanged3(int value)
{
    lbl[2]->setText(QString("%1").arg(value));
    sliH[2]->setValue(100-sliV[2]->value());
}
