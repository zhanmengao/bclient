#include"widget.h"

void Widget::InitCheckBox()
{
    QString str1[3] = {"Game","Office","Develop"};
    QString str2[3] = {"P&rogramming","Q&T","O&S"};

    int xPos = 500;
    int yPos = 30;

    chk_group[0] = new QButtonGroup(this);
    chk_group[1] = new QButtonGroup(this);

    for(int i = 0;i<3;i++)
    {
        //第一组
        exclusive[i] = new QCheckBox(str1[i],this);
        exclusive[i]->setGeometry(xPos,yPos,100,30);
        chk_group[0]->addButton(exclusive[i]);

        //第二组
        non_exclusive[i] = new QCheckBox(str2[i],this);
        non_exclusive[i]->setGeometry(xPos+120,yPos,100,30);
        chk_group[1]->addButton(non_exclusive[i]);

        connect(exclusive[i],SIGNAL(clicked()),
                this,SLOT(chkChanged()));
        yPos+=40;

    }

    exclusive[0]->setIcon(QIcon("../resources/browser.png"));
    exclusive[1]->setIcon(QIcon("../resources/calendar.png"));
    exclusive[2]->setIcon(QIcon("../resources/chat.png"));

    non_exclusive[0]->setIcon(QIcon("../resources/editor.png"));
    non_exclusive[1]->setIcon(QIcon("../resources/mail.png"));
    non_exclusive[2]->setIcon(QIcon("../resources/users.png"));

    chk_group[0]->setExclusive(false);
    chk_group[1]->setExclusive(true);
}
//选择第一组的复选框，或者未被激活时，运行槽函数的成员函数chkChanged
void Widget::chkChanged()
{
    for(int i = 0 ; i < 3 ; i++)
    {
        //被激活则返回true
        if(exclusive[i]->checkState())
        {
            qDebug("checkbox %d selected ", i+1);
        }
    }
}
