
#include "QEventLabel.h"
#include<QMessageBox>
QEventLabel::QEventLabel(const QString & text,QWidget *parent) : QLabel(parent)
{
    setText(text);
}

QEventLabel::QEventLabel(QWidget *parent) : QLabel(parent)
{

}
//第二种方法
//使用继承QLabel，重写事件处理的回调函数mousePressEvent
void QEventLabel::mousePressEvent(QMouseEvent *event)
{
    //Qt::LeftButton
    //Qt::RightButton
    if(event->button()== Qt::LeftButton)
    {
        QMessageBox::information(NULL,"单击","单击了我",
                                 QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
    }
}

//第三种方法 重写 event()函数
bool QEventLabel::event(QEvent *e)
{
    if (e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(e);
        if(mouseEvent->button() == Qt::LeftButton)
        {
            QMessageBox::information(NULL,"单击","单击了我",
                                     QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
            return true;
        }
    }
    return QLabel::event(e);
}
