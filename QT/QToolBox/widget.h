#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QToolBox>
#include<QHBoxLayout>
#include<QPushButton>

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

    QToolBox *pTB;
    QHBoxLayout *pLay;
    QPushButton *btn[7];
};
#endif // WIDGET_H
