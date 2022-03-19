#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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
private slots:
    void slider1_valuechanged(int value);
    void slider2_valuechanged(int value);
    void slider3_valuechanged(int value);
    void on_inputSpinBox1_valueChanged(int value);
    void on_inputSpinBox2_valueChanged(int value);
    void on_inputSpinBox3_valueChanged(int value);
};
#endif // WIDGET_H
