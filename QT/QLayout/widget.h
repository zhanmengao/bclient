#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QTabWidget>
#include<QSplitter>

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
    void InitSplitter();
    void InitBtnLayout();
private slots:
    void OnSplitterBtnClick();
private:
    void InitLayout();
    void InitHLayout();
    void InitVLayout();
    void InitGLayout();
private:
    Ui::Widget *ui;

    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;
    QGridLayout *gLayout;
    QTabWidget *tw;
    QSplitter *sp;
    QVBoxLayout *vl;
};
#endif // WIDGET_H
