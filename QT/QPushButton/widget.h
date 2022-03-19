#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPushButton>
#include<QFocusFrame>
#include<QCommandLinkButton>

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
    void btn_click();
    void btn_pressed();
    void btn_released();

    void clickFunc();
private:
    Ui::Widget *ui;

    QPushButton *btn[3];
    QFocusFrame *btnFrame;
    QCommandLinkButton *mCLB;
};
#endif // WIDGET_H
