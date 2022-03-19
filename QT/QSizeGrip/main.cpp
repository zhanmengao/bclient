#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(800,600);
    SubWindow sw(&w);
    sw.move(200,180);

    w.show();
    return a.exec();
}
