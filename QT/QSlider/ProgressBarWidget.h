#ifndef PROGRESSBARWIDGET_H
#define PROGRESSBARWIDGET_H


#include <QWidget>
#include<QProgressBar>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class ProgressBarWidget : public QWidget
{
    Q_OBJECT

public:
    ProgressBarWidget(QWidget *parent = nullptr):QWidget(parent)
    {
    }
    ~ProgressBarWidget()
    {
    }
    void InitProgressBar();
private:
    QProgressBar *pBar[4];
};
#endif // PROGRESSBARWIDGET_H
