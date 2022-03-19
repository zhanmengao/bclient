#include "widget.h"
#include "ui_widget.h"
#include <QCalendarWidget>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QCalendarWidget *cal = new QCalendarWidget(this);

    cal->setMinimumDate(QDate(1900, 1, 1));
    cal->setMaximumDate(QDate(2200, 12, 31));

    //cal->setGridVisible(true);
    cal->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);

    //cal->setSelectionMode(QCalendarWidget::NoSelection);
}

Widget::~Widget()
{
    delete ui;
}

