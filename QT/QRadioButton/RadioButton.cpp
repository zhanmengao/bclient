#include"widget.h"

void Widget::InitRadioButton()
{

    QString str[6] = {"NetBook","Handset","Tablet","In-Vehicle","Samrt TV","Media Phone"};

    int yPos = 30;
    for(int i = 0;i<3;i++)
    {
        pRdBtn[i] = new QRadioButton(str[i],this);
        pRdBtn[i]->setGeometry(10,yPos,150,30);

        yPos += 40;
    }

    yPos = 30;
    for(int i = 3;i<6;i++)
    {
        pRdBtn[i] = new QRadioButton(str[i],this);
        if( i == 4)
        {
            pRdBtn[i]->setChecked(true);            //设为当前选中
        }
        pRdBtn[i]->setGeometry(180,yPos,150,30);

        yPos += 40;
    }

    //分离
    yPos = 250;
    pGroup[0] = new QButtonGroup(this);
    for(int i = 0;i<3;i++)
    {
        pRdBtn2[i] = new QRadioButton(str[i],this);
        pRdBtn2[i]->setGeometry(10,yPos,150,30);
        pGroup[0]->addButton(pRdBtn2[i]);
        yPos += 40;
    }
    yPos = 250;
    pGroup[1] = new QButtonGroup(this);
    for(int i = 3;i<6;i++)
    {
        pRdBtn2[i] = new QRadioButton(str[i],this);
        if( i == 4)
        {
            pRdBtn[i]->setChecked(true);            //设为当前选中
        }
        pRdBtn2[i]->setGeometry(180,yPos,150,30);
        pGroup[1]->addButton(pRdBtn2[i]);
        yPos += 40;
    }
}
