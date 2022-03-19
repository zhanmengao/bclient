#include "systemtrayicon.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SystemTrayIcon w;
    w.show();
    return a.exec();
}
