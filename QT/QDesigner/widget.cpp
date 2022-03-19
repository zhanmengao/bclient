#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider,&QAbstractSlider::valueChanged,this,&Widget::slider1_valuechanged);
    connect(ui->horizontalSlider_2,&QAbstractSlider::valueChanged,this,&Widget::slider2_valuechanged);
    connect(ui->horizontalSlider_3,&QAbstractSlider::valueChanged,this,&Widget::slider3_valuechanged);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::slider1_valuechanged(int value)
{
    ui->spinBox->setValue(value);
}
void Widget::slider2_valuechanged(int value)
{
    ui->spinBox_2->setValue(value);
}
void Widget::slider3_valuechanged(int value)
{
    ui->spinBox_3->setValue(value);
}
void Widget::on_inputSpinBox1_valueChanged(int value)
{
    ui->spinBox->setValue(value);
}
void Widget::on_inputSpinBox2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
}
void Widget::on_inputSpinBox3_valueChanged(int value)
{
    ui->spinBox_3->setValue(value);
}

