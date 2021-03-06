#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QScrollArea>
#include<QLabel>
#include<QImage>
#include<QTabWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    QScrollArea *pArea;
    QLabel *pLabel;
};
#endif // WIDGET_H
