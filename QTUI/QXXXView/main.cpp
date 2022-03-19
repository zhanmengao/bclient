#include "mainwindow.h"

#include <QApplication>
#include<QListView>
#include<QTreeView>
#include<QFileSystemModel>
#include<QStandardItemModel>
#include<QStandardItem>
#include<QDebug>

#define EX1
void initFileSystem()
{

}
int main1(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFileSystemModel model;
    model.setRootPath(QDir::currentPath());

    //创建树型视图
    QTreeView tree;
    tree.setWindowTitle("tree");
    tree.setModel(&model);          //为视图指定模型
    tree.setRootIndex(model.index(QDir::currentPath()));            //指定根索引

    //创建列表视图
    QListView list;
    list.setWindowTitle("list");
    list.setModel(&model);
    list.setRootIndex(model.index(QDir::currentPath()));

    tree.show();
    list.show();

    MainWindow mainWindow;
    mainWindow.resize(800,600);
    mainWindow.setWindowTitle(QWidget::tr("Qt View"));
    mainWindow.show();
    return a.exec();
}
int main2(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //创建标准项模型
    QStandardItemModel model;

    //获取模型的根项
    QStandardItem *parentItem = model.invisibleRootItem();

    //创建标准项item0
    QStandardItem *item0 = new QStandardItem();
    item0->setText("A");
    QPixmap pixmap0(50,50);
    pixmap0.fill("red");
    item0->setIcon(QIcon(pixmap0));
    item0->setToolTip("indexA");

    //将创建的标准项作为根项的子项
    parentItem->appendRow(item0);

    //将创建的标准项作为新的父项
    parentItem = item0;

    //创建新的标准项，将它作为item0的子项
    QStandardItem *item1 = new QStandardItem();
    item1->setText("B");
    QPixmap pixmap1(50,50);
    pixmap1.fill("blue");
    item1->setIcon(QIcon(pixmap1));
    item1->setToolTip("iconB");
    parentItem->appendRow(item1);

    //创建新的标准项，指定文本、图标、工具提示（都是属性）
    QStandardItem* item2 = new QStandardItem();
    item2->setText("B");
    QPixmap pixmap2(50,50);
    pixmap2.fill("green");
    item2->setData("C",Qt::EditRole);
    item2->setData("indexC",Qt::ToolTipRole);
    item2->setData(QIcon(pixmap2),Qt::DecorationRole);
    parentItem->appendRow(item2);

    QTreeView view;
    view.setModel(&model);
    view.show();

    //获取item0项的模型索引,QModelIndex()表示使用父项索引
    QModelIndex indexA = model.index(0,0,QModelIndex());
    qDebug()<<"index A row count: "<<model.rowCount(indexA);

    //获取indexA的0，0号索引：B
    QModelIndex indexB = model.index(0,0,indexA);
    //获取b的属性
    qDebug()<<"indexB text : "<<model.data(indexB,Qt::EditRole).toString();
    qDebug()<<"indexB toolTip : "<<model.data(indexB,Qt::ToolTipRole).toString();
    return a.exec();
}

int main(int argc, char *argv[])
{
    return main1(argc,argv);
}
