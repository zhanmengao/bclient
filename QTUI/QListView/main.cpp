#include <QApplication>
#include <QDialog>
#include"mainwindow.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow* main = new MainWindow();
    main->show();

    return a.exec();
}
