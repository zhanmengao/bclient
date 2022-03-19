#ifndef UILABEL_H
#define UILABEL_H
#include<QLabel>
#include<QMouseEvent>
class UILabel:public QLabel
{
    Q_OBJECT
public:
    UILabel(QWidget *parent=nullptr);
    UILabel(const QString &text, QWidget *parent=nullptr);

Q_SIGNALS:
    void Click(UILabel* object);
private:
    virtual void mousePressEvent(QMouseEvent *event);
};

#endif // UILABEL_H
