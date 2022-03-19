#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    bool eventFilter(QObject *obj, QEvent *event);
protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
private slots:
    void update();
private:
    Ui::Widget *ui;
    QLabel *label;
};
#endif // WIDGET_H
