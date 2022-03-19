#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    pSliderWidget = new SliderWidget(this);
    pSliderWidget->InitSlider();

    pScrollWidget = new ScrollBarWidget(this);
    pScrollWidget->setGeometry(300,0,500,200);
    pScrollWidget->InitScrollBar();

    pDialWidget = new DialWidget(this);
    pDialWidget->setGeometry(0,200,500,200);
    pDialWidget->InitDial();

    pProgressWidget = new ProgressBarWidget(this);
    pProgressWidget->setGeometry(400,200,500,200);
    pProgressWidget->InitProgressBar();
}
Widget::~Widget()
{
    delete ui;
}

