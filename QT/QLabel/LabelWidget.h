#ifndef LABELWIDGET_H
#define LABELWIDGET_H

#include <QWidget>
#include<QLabel>
#include<QLCDNumber>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class LabelWidget : public QWidget
{
    Q_OBJECT

public:
    LabelWidget(QWidget *parent = nullptr):QWidget(parent)
    {
    }
    ~LabelWidget()
    {
    }
    void InitLabel();
private:
    QLabel *lb[2];
    QLCDNumber *lcd[2];
};
#endif // LABELWIDGET_H
