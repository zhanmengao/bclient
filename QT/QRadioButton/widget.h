#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QRadioButton>
#include<QButtonGroup>
#include <QCheckBox>
#include<QButtonGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void InitCheckBox();
    void InitRadioButton();
private slots:
    void chkChanged();

private:
    Ui::Widget *ui;

    QRadioButton *pRdBtn[6];
    QRadioButton *pRdBtn2[6];
    QButtonGroup *pGroup[2];


    QButtonGroup *chk_group[2];
    QCheckBox *exclusive[3];
    QCheckBox *non_exclusive[3];
};
#endif // WIDGET_H
