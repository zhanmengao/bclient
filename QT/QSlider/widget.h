#ifndef WIDGET_H
#define WIDGET_H

#include"SliderWidget.h"
#include"DialWidget.h"
#include"ScrollBarWidget.h"
#include"ProgressBarWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    Ui::Widget *ui;

    SliderWidget *pSliderWidget;
    DialWidget *pDialWidget;
    ScrollBarWidget *pScrollWidget;
    ProgressBarWidget* pProgressWidget;
};
#endif // WIDGET_H
