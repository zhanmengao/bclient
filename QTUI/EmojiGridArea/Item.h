#ifndef ITEM_H
#define ITEM_H
#include<QWidget>
#include<QLabel>
class Item:public QWidget
{
    Q_OBJECT
public:
    explicit Item(const QString& icon,QWidget *parent = NULL);
    ~Item();
private:
    QLabel* lab;
};

#endif // ITEM_H
