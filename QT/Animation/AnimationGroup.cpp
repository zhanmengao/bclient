#include"mainwindow.h"

void MainWindow::InitGroup()
{
    //动画组
    sequenGroup = new QSequentialAnimationGroup();
    parallGroup = new QParallelAnimationGroup();
}

void MainWindow::OnClickSequentialGroup()
{
    //动画加组
    sequenGroup->addAnimation(btn1InSine);
    sequenGroup->addAnimation(btn2OutSine);
    sequenGroup->start();
}
void MainWindow::OnClickParallelGroup()
{
    //动画加组
    parallGroup->addAnimation(btn1InSine);
    parallGroup->addAnimation(btn2OutSine);
    parallGroup->start();
}
