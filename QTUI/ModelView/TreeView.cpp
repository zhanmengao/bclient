#include"widget.h"
#include <QSplitter>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
void Widget::InitFileSystemModel()
{
    QSplitter *splitter = new QSplitter(this);              //提供可以调整控件大小的GUI
    //Model 数据集
    //QFileSystemModel:从文件系统映射到模型类的实例
    QFileSystemModel *pFModel = new QFileSystemModel();
    pFModel->setRootPath(QDir::currentPath());

    //View控件
    //树状
    QTreeView *pTreeV = new QTreeView(splitter);
    pTreeV->setModel(pFModel);
    pTreeV->setRootIndex(pFModel->index(QDir::currentPath()));
    //列表
    QListView *pListV = new QListView(splitter);
    pListV->setModel(pFModel);
    pListV->setRootIndex(pFModel->index(QDir::rootPath()));
    vLayout->addWidget(splitter);
}
