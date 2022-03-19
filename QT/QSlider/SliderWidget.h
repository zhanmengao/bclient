#ifndef SLIDERWIDGET_H
#define SLIDERWIDGET_H
#include <QWidget>
#include<QSlider>
#include<QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class SliderWidget : public QWidget
{
    Q_OBJECT

public:
    SliderWidget(QWidget *parent = nullptr): QWidget(parent)
    {
    }
    ~SliderWidget()
    {
    }
    void InitSlider();
private slots:
    void valueChanged1(int value);
    void valueChanged2(int value);
    void valueChanged3(int value);
private:
    QSlider *sliV[3];
    QSlider *sliH[3];
    QLabel *lbl[3];
};
#endif // SLIDERWIDGET_H
