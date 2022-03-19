#include"ScrollBarWidget.h"

void ScrollBarWidget::InitScrollBar()
{
    int xpos = 10;
    int ypos = 50;
    for(int i = 0 ; i < 3 ; i++)
    {
        vscrollbar[i] = new QScrollBar(Qt::Vertical, this);
        vscrollbar[i]->setRange(0, 100);
        vscrollbar[i]->setGeometry(xpos, 30, 20, 200);

        lb[i] = new QLabel(QString("%1").arg(vscrollbar[i]->value()), this);
        lb[i]->setGeometry(xpos + 2, 220, 30, 30);
        xpos += 50;

        hscrollbar[i] = new QScrollBar(Qt::Horizontal, this);
        hscrollbar[i]->setRange(0, 100);
        hscrollbar[i]->setGeometry(150, ypos, 200, 20);
        ypos += 30;
    }

    connect(vscrollbar[0], SIGNAL(valueChanged(int)), this,
                          SLOT(valueChanged1(int)));

    connect(vscrollbar[1], SIGNAL(valueChanged(int)), this,
                          SLOT(valueChanged2(int)));

    connect(vscrollbar[2], SIGNAL(valueChanged(int)), this,
                          SLOT(valueChanged3(int)));
}
