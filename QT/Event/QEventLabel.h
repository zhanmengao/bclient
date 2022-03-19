#ifndef QEVENTLABEL_H
#define QEVENTLABEL_H
#include<QLabel>
#include<QMouseEvent>

class QEventLabel:public QLabel
{
public:
    QEventLabel(const QString & text,QWidget *parent);
    QEventLabel(QWidget *parent);
    void mousePressEvent(QMouseEvent *event);
    bool event(QEvent *e);
};

#endif // QEVENTLABEL_H
