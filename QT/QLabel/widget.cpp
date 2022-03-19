#include "widget.h"
#include "ui_widget.h"
#include<QInputDialog>
#include<string>
#include<QDir>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    pLabel = new LabelWidget(this);
    pLabel->InitLabel();

    pInput = new InputWidget(this);
    pInput->setGeometry(10,300,500,400);
    pInput->InitLineEdit();

    pSpin = new SpinBoxWidget(this);
    pSpin->setGeometry(500,0,500,400);
    pSpin->InitSpinBox();
}

Widget::~Widget()
{
    delete ui;
}

