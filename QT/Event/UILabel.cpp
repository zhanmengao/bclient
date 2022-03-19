#include"UILabel.h"


UILabel::UILabel(QWidget *parent):QLabel(parent)
{
}
UILabel::UILabel(const QString &text, QWidget *parent):QLabel(text,parent)
{
}


void UILabel::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    if(event->button()== Qt::LeftButton)
    {
        emit Click(this);
    }
}
