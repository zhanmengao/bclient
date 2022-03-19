#include"widget.h"
#include <QSplitter>
#include <QListView>
#include <QStringListModel>
#include <QLabel>
#include <QStandardItemModel>
void Widget::InitStringListModel()
{
    //QStringListModel可以映射QString类型
    QStringList strList;
    strList<<"Monday"<<"Tuesday"<<"Wednesday"<<"Friday";
    QAbstractItemModel *pStrModel = new QStringListModel(strList);
    QListView *pListV2 = new QListView();
    pListV2->setModel(pStrModel);                           //将Model设置给View
    vLayout->addWidget(pListV2);

    QString text = pStrModel->data(pStrModel->index(3,0),Qt::DisplayRole).toString(); //拿到[3,0]的数据
    QLabel *pLB = new QLabel(text);
    vLayout->addWidget(pLB);
}
