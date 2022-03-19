#include"mainwindow.h"

void MainWindow::InitAnimation()
{
    //指定要成为动画目标的按钮，指定做位移动画。不指定easingCurve，则默认Linear
    btnLinear = new QPropertyAnimation(btn,"geometry",this);
    btnInOutQuad = new QPropertyAnimation(btn,"geometry");

    btn1InSine = new QPropertyAnimation(btn,"geometry");
    btn2OutSine = new QPropertyAnimation(btn2,"geometry");
    btn1InSine->setDuration(1500);                                   //动画持续时间,继承自QAbstractAnimation
    btn1InSine->setStartValue(QRect(10,50,100,30));                  //设置起始坐标
    btn1InSine->setEndValue(QRect(200,150,100,30));                  //设置结束坐标
    btn2OutSine->setDuration(1500);                                   //动画持续时间,继承自QAbstractAnimation
    btn2OutSine->setStartValue(QRect(50,95,100,30));                  //设置起始坐标
    btn2OutSine->setEndValue(QRect(240,195,100,30));                  //设置结束坐标

    btn1InElastic = new QPropertyAnimation(btn,"geometry");
    btn2OuElastic= new QPropertyAnimation(btn,"geometry");
    btn1InElastic->setDuration(1500);                                   //动画持续时间,继承自QAbstractAnimation
    btn2OuElastic->setDuration(1500);                                   //动画持续时间,继承自QAbstractAnimation
    btn2OuElastic->setStartValue(QRect(50,95,100,30));                  //设置起始坐标
    btn2OuElastic->setEndValue(QRect(240,195,100,30));                  //设置结束坐标

    QEasingCurve easing(QEasingCurve::InOutQuad);
    for(qreal t = 0.0;t<1.0;t+=0.1)
    {
        //返回动作时长
        qDebug("Effective progress %lf is %lf",t,easing.valueForProgress(t));
    }

    //指定easingCurve（动画插值方式）
    btnInOutQuad->setEasingCurve(easing);
    btn1InSine->setEasingCurve(QEasingCurve::InSine);
    btn2OutSine->setEasingCurve(QEasingCurve::OutSine);
    btn1InElastic->setEasingCurve(QEasingCurve::InElastic);
    btn2OuElastic->setEasingCurve(QEasingCurve::OutElastic);
}
void MainWindow::OnClickLinear()
{
    if(btnLinear->state() == QPropertyAnimation::Stopped)
    {
        btnLinear->setDuration(1500);                                   //动画持续时间,继承自QAbstractAnimation
        btnLinear->setStartValue(QRect(10,50,100,30));                  //设置起始坐标
        btnLinear->setEndValue(QRect(200,150,100,30));                  //设置结束坐标
        btnLinear->start();
    }
}
void MainWindow::OnClickInOutQuad()
{
    if(btnInOutQuad->state() == QPropertyAnimation::Stopped)
    {
        btnInOutQuad->setDuration(1500);                                   //动画持续时间,继承自QAbstractAnimation
        btnInOutQuad->setStartValue(QRect(10,50,100,30));                  //设置起始坐标
        btnInOutQuad->setEndValue(QRect(200,150,100,30));                  //设置结束坐标
        btnInOutQuad->start();
    }
}
