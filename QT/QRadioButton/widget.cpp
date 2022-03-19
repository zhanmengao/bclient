#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    InitCheckBox();
    InitRadioButton();
}

Widget::~Widget()
{
    delete ui;
}

