#include"widget.h"
#include <QDate>
#include <QDateTime>
#include <QTableView>
#include <QStandardItemModel>
void Widget::InitTableView()
{
    //QStandardItemModel 映射行列模型
    QStandardItemModel *pStandItemModel = new QStandardItemModel(0, 3);
    //setHeaderData函数指定列名
    pStandItemModel->setHeaderData(0,Qt::Horizontal,QObject::tr("Subject"));
    pStandItemModel->setHeaderData(1,Qt::Horizontal,QObject::tr("Description"));
    pStandItemModel->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));

    //setVerticalHeaderItem行标题
    pStandItemModel->setVerticalHeaderItem(0,new QStandardItem("Col 1"));
    pStandItemModel->setVerticalHeaderItem(1,new QStandardItem("Col 2"));
    pStandItemModel->setVerticalHeaderItem(2,new QStandardItem("Col 3"));

    //SetData:指定标题行
    pStandItemModel->setData(pStandItemModel->index(0,0),"Monitor");
    pStandItemModel->setData(pStandItemModel->index(0,1),"LCD 24 inch");
    pStandItemModel->setData(pStandItemModel->index(0,2),QDateTime(QDate(2011,10,4)));
    pStandItemModel->setData(pStandItemModel->index(1,0),"CPU");
    pStandItemModel->setData(pStandItemModel->index(1,1),"Intel core 2 duo");
    pStandItemModel->setData(pStandItemModel->index(1,2),QDateTime(QDate(2011,12,5)));
    pStandItemModel->setData(pStandItemModel->index(2,0),"Keyboard");
    pStandItemModel->setData(pStandItemModel->index(2,1),"104 Key USB Keyboard");
    pStandItemModel->setData(pStandItemModel->index(2,2),QDateTime(QDate(2011,12,6)));

    QTableView *pTable = new QTableView();
    pTable->setModel(pStandItemModel);
    vLayout->addWidget(pTable);
}
