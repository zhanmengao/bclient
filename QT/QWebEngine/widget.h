#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QWebEngineView>
#include"MWebEngineView.h"
#include<QPushButton>

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QMainWindow *parent = nullptr);
    ~Widget();
protected:
    void resizeEvent(QResizeEvent *);
private slots:
    void onBackBtnClicked();
private:
    QWebEngineView *pWebView;
    MWebEngineView* m_view = Q_NULLPTR;
    QPushButton* m_backBtn = Q_NULLPTR;
};
#endif // WIDGET_H
