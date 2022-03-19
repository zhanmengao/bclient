#include "mainwindow.h"
#include<QToolBar>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
    //数据
    QStandardItemModel *model = new QStandardItemModel(7,4,this);
    for(int row = 0;row<7;row++)
    {
        for(int column = 0;column<4;column++)
        {
            QStandardItem *item = new QStandardItem(QString("%1").arg(row*4 + column));
            model->setItem(row,column,item);
        }
    }

    tableView = new QTableView(this);
    tableView->setModel(model);
    setCentralWidget(tableView);

    //获取视图的项目选择模型
    QItemSelectionModel *selectionModel = tableView->selectionModel();

    //定义左上角和右下角的索引
    QModelIndex topLeft;
    QModelIndex bottomRight;
    topLeft = model->index(1,1,QModelIndex());
    bottomRight = model->index(5,2,QModelIndex());

    //使用这两个索引，创建项目选择块（会框选从1,1到5,2的项）
    QItemSelection selection(topLeft,bottomRight);

    //使用指定的选择模式来选择项目：可以有多个被选择的项目
    selectionModel->select(selection,QItemSelectionModel::Select);
    //QItemSelectionModel::Select 指定的元素都将被选择
    //QItemSelectionModel::Toggle   逆操作

    QToolBar *mainToolbar = addToolBar(tr("Tool"));
    mainToolbar->addAction(tr("当前项目"),this,&MainWindow::getCurrentItemData);
    mainToolbar->addAction(tr("切换选择"),this,&MainWindow::toggleSelection);

    //选择改变信号
    connect(selectionModel,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this,SLOT(updateSelection(QItemSelection,QItemSelection)));

    //当前改变信号
    connect(selectionModel,&QItemSelectionModel::currentChanged,this,&MainWindow::changeCurrent);

    treeView = new QTreeView();
    treeView->setWindowTitle("tableView2");
    treeView->resize(400,300);
    treeView->setModel(model);            //调用同一个model
    treeView->setSelectionModel(selectionModel);
    treeView->show();
}
MainWindow::~MainWindow()
{
    delete treeView;
}
//获取当前项目：只能有一个当前项目
void MainWindow::getCurrentItemData()
{
    qDebug()<<tr("当前项目的内容:")<<tableView->selectionModel()->currentIndex().data().toString();
}
//切换选的的项目
void MainWindow::toggleSelection()
{
    QModelIndex topLeft = tableView->model()->index(0,0,QModelIndex());
    QModelIndex bottomRight = tableView->model()->index(
                tableView->model()->rowCount(QModelIndex())-1,
                tableView->model()->columnCount(QModelIndex()) - 1,
                QModelIndex());

    QItemSelection curSelection(topLeft,bottomRight);           //将全部加到集合
    tableView->selectionModel()->select(curSelection,QItemSelectionModel::Toggle);              //对全部进行反选中
}
//参数：本次选择，上次选择
void MainWindow::updateSelection(const QItemSelection& selected,const QItemSelection& deselected)
{
    QModelIndex index;
    QModelIndexList list = selected.indexes();          //获取当前所有选择的项目的索引

    //为现在选择的项目填值
    foreach(index,list)
    {
        QString text = QString("(%1,%2)").arg(index.row()).arg(index.column());
        tableView->model()->setData(index,text);
    }
    list = deselected.indexes();
    //清空上一次选择的项的内容
    foreach(index,list)
    {
        tableView->model()->setData(index,"");
    }
}
//当前项目改变时
void MainWindow::changeCurrent(const QModelIndex& current,const QModelIndex& previous)
{
    qDebug()<<tr("move(%1,%2) to (%3,%4)").arg(previous.row()).arg(previous.column()).arg(current.row()).arg(current.column());
}

