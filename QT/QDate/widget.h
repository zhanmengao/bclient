#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QDate>
#include<QDateEdit>
#include<QLabel>
#include<QTime>
#include<QTimeEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void InitDate();
    void InitDameTime();
    void InitTime();
private:
    Ui::Widget *ui;

    QDateEdit *dateEdit[4];
    QLabel *lb[8];

    QDateTimeEdit *mQTE[4];

    QTimeEdit *mTimeEd[4];
};
#endif // WIDGET_H
