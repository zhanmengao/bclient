#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPropertyAnimation>
#include<QSequentialAnimationGroup>
#include<QParallelAnimationGroup>
#include<QStateMachine>
#include<QPushButton>
#include<QSignalTransition>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void InitAnimation();
    void InitGroup();
    void InitStateMachine();
private slots:
    void OnClickLinear();
    void OnClickInOutQuad();
    void OnClickSequentialGroup();
    void OnClickParallelGroup();
private:
    QPushButton *btn;
    QPushButton *btn2;

    QPropertyAnimation *btnLinear;
    QPropertyAnimation *btnInOutQuad;
    QPropertyAnimation *btn1InSine;
    QPropertyAnimation *btn2OutSine;
    QPropertyAnimation *btn1InElastic;
    QPropertyAnimation *btn2OuElastic;

    QSequentialAnimationGroup *sequenGroup;
    QParallelAnimationGroup *parallGroup;

    QStateMachine *machine;
};
#endif // MAINWINDOW_H
