#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(600,300);
    vLayout = new QVBoxLayout();
    InitTableView();
    InitFileSystemModel();
    InitStringListModel();
    setLayout(vLayout);
}

Widget::~Widget()
{
    delete ui;
}

