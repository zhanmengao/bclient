#include "widget.h"
#include <QStandardItem>
#include <QColumnView>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QStandardItemModel *model = new QStandardItemModel;     //Model

    QStandardItem *name = new QStandardItem("Name");
    QStandardItem *firstName = new QStandardItem("First Name");
    QStandardItem *lastName = new QStandardItem("Last Name");
    name->appendRow(firstName);     //追加到name身上
    name->appendRow(lastName);
    model->appendRow(name);        //name作为Model的一级选项
    QStandardItem *john = new QStandardItem("John");
    QStandardItem *smith = new QStandardItem("Smith");
    firstName->appendRow(john);     //追加在firstname
    lastName->appendRow(smith);

    QStandardItem *address = new QStandardItem("Address");
    QStandardItem *street = new QStandardItem("Street");
    QStandardItem *city = new QStandardItem("City");
    QStandardItem *state = new QStandardItem("State");
    QStandardItem *country = new QStandardItem("Country");
    address->appendRow(street);
    address->appendRow(city);
    address->appendRow(state);
    address->appendRow(country);
    model->appendRow(address);      //一级选项

    QColumnView *columnView = new QColumnView;
    columnView->setModel(model);

    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addWidget(columnView);
}

Widget::~Widget()
{
}
