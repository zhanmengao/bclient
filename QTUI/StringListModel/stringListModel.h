#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QAbstractListModel>

class StringListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    StringListModel(const QStringList& strings,QObject* parent = NULL);
    ~StringListModel();
public:
    //因为是一列平行文本，所以只有row
    int rowCount(const QModelIndex& parent = QModelIndex()) const;

    //返回数据
    QVariant data(const QModelIndex& index,int role) const;

    //
    Qt::ItemFlags flags(const QModelIndex& index) const;

    //为委托想模型中设置数据提供一条途径
    bool setData(const QModelIndex& index,const QVariant& value,int role = Qt::EditRole);

    //插入和删除行
    bool insertRows(int position,int rows,const QModelIndex& index = QModelIndex());
    bool removeRows(int position,int rows,const QModelIndex& index = QModelIndex());

    //返回表头
    QVariant headerData(int section,Qt::Orientation orientation,int role = Qt::DisplayRole) const;          //DisplayRole QString数据被渲染为文本
private:
    QStringList stringList;
};
#endif // WIDGET_H
