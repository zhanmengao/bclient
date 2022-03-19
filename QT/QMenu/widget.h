#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QMenu>
#include<QMenuBar>
#include<QLabel>

#include<QToolBar>
#include<QAction>

#include<QToolButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void InitMenu();
    void InitToolBar();
    void InitToolButton();
private slots:
    void trigerMenu(QAction* action);

    void trigger1();
    void trigger2();
    void trigger3();
    void trigger4();
    void trigger5();
private:
    Ui::Widget *ui;

    QMenu       *menu[3];
    QMenuBar    *menuBar;
    QLabel      *lbl;
    QAction     *act[2];
};
#endif // WIDGET_H
