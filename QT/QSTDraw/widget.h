#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPaintEvent>
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
    void Brush();
    void DrawType();
    virtual void paintEvent(QPaintEvent *);
private:
    Ui::Widget *ui;
    QPixmap image1;
    QPixmap image2;
    QPixmap image3;
    QPixmap image4;
};
#endif // WIDGET_H
