#ifndef WIDGET_H
#define WIDGET_H

#include <QPainter>
#include <QtEvents>
#include <QLineEdit>
#include<QPushButton>
#include<dialog.h>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QLineEdit *edit;
    QPushButton *btn;
    Dialog mDialog;
private slots:
    void OnBtnClick();
protected:
    virtual void paintEvent(QPaintEvent *event);            //发生绘制事件
    virtual void resizeEvent(QResizeEvent *event);          //窗口大小变化事件

    virtual void mousePressEvent(QMouseEvent *event);       //鼠标按下事件
    virtual void mouseReleaseEvent(QMouseEvent *event);     //鼠标弹起事件
    virtual void mouseDoubleClickEvent(QMouseEvent *event);    //鼠标双击s
    virtual void mouseMoveEvent(QMouseEvent *event);          //鼠标移动

    virtual void keyPressEvent(QKeyEvent *event);             //键盘按下
    virtual void keyReleaseEvent(QKeyEvent *event);           //键盘弹起
    virtual void focusInEvent(QFocusEvent *event);             //激活程序
    virtual void focusOutEvent(QFocusEvent *event);             //焦点离开程序

};

#endif // WIDGET_H
