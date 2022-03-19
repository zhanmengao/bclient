#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QSizeGrip>
#include<QVBoxLayout>
#include<QTextEdit>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


class SubWindow : public QWidget
{
public:
    SubWindow(QWidget* parent = nullptr):QWidget(parent,Qt::SubWindow)
    {
        QSizeGrip *sg = new QSizeGrip(this);
        sg->setFixedSize(sg->sizeHint());

        this->setLayout(new QVBoxLayout());     //声明SubWindow的布局
        this->layout()->setMargin(0);           //设置空白
        this->layout()->addWidget(new QTextEdit());     //小窗口里有一个编辑框

        sg->setWindowFlag(Qt::WindowStaysOnTopHint);
        sg->raise();
    }
    QSize sizeHit() const
    {
        return QSize(200,100);
    }
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
