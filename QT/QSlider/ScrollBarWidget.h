#ifndef SCROLLBARWIDGET_H
#define SCROLLBARWIDGET_H

#include <QWidget>
#include <QScrollBar>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class ScrollBarWidget : public QWidget
{
    Q_OBJECT

public:
    ScrollBarWidget(QWidget *parent)
        : QWidget(parent)
    {
    }
    ~ScrollBarWidget()
    {
    }
    void InitScrollBar();
private:
    QScrollBar *vscrollbar[3];
    QScrollBar *hscrollbar[3];
    QLabel     *lb[3];
};
#endif // DIALWIDGET_H
