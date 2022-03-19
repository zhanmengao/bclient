#include"SpinBox.h"

void SpinBoxWidget::InitSpinBox()
{
    int xPos = 10;
    int yPos = 30;

    int val[3] = {50,100,200};
    double dVal[3] = {50.5,127.32,171.342};

    for(int i = 0;i<3;i++)
    {
        pIBox[i] = new QSpinBox(this);
        pIBox[i]->setMinimum(10);
        pIBox[i]->setMaximum(300);
        pIBox[i]->setValue(val[i]);      //设默认值
        pIBox[i]->setGeometry(xPos,yPos,100,30);

        pDBox[i] = new QDoubleSpinBox(this);
        pDBox[i]->setMinimum(10.0);
        pDBox[i]->setMaximum(300.0);
        pDBox[i]->setValue(dVal[i]);
        pDBox[i]->setGeometry(xPos + 110,yPos,100,30);

        yPos+=40;

        //connect(pIBox[i], &QSpinBox::valueChanged, this, &(this->valueChange));
        //connect(pDBox[i], &QDoubleSpinBox::valueChanged, this, &(this->doubleChange));
    }

    pIBox[0]->setPrefix("$ ");     //$ 50
    pDBox[0]->setSuffix(" mm");    //50 mm

    connect(pIBox[0], SIGNAL(valueChanged(int)), this,
                     SLOT(valueChange(int)));

    connect(pDBox[0], SIGNAL(valueChanged(double)), this,
                           SLOT(double_valueChange(double)));
}
void SpinBoxWidget::valueChange(int val)
{
    qDebug("input val %u",val);
}
void SpinBoxWidget::double_valueChange(double val)
{
    qDebug("input val %3.2f",val);
}
