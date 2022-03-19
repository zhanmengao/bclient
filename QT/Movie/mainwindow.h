#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void hideEvent(QHideEvent *event) override;
    void showEvent(QShowEvent *event) override;
private slots:
    void OnTimeOut();
private:
    QTimer *timer;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
