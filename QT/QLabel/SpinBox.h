#ifndef SPINBOX_H
#define SPINBOX_H

#include <QWidget>
#include<QSpinBox>
#include<QDoubleSpinBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class SpinBoxWidget : public QWidget
{
    Q_OBJECT

public:
    SpinBoxWidget(QWidget *parent = nullptr):QWidget(parent)
    {
    }
    ~SpinBoxWidget()
    {
    }
    void InitSpinBox();
private slots:
    void valueChange(int val);
    void double_valueChange(double val);
private:
    QSpinBox *pIBox[3];
    QDoubleSpinBox *pDBox[3];
};
#endif // SPINBOX_H
