#ifndef WIDGET_H
#define WIDGET_H

#include"LabelWidget.h"
#include"UIInput.h"
#include"SpinBox.h"

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

    LabelWidget *pLabel;
    InputWidget *pInput;
    SpinBoxWidget *pSpin;
};
#endif // WIDGET_H
