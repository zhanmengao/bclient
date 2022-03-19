#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTabWidget>
#include<QString>
#include<QPushButton>
#include<QTabBar>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void currentTab(int index);
private:
    Ui::Widget *ui;
    QTabWidget *tab;
    QTabBar *tBar;
    QWidget *browser;
    QWidget *users;
};
#endif // WIDGET_H
