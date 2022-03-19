#include "widget.h"

#include <QApplication>
#include"dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Dialog dia;
    if(dia.exec() == QDialog::Accepted)
    {
        w.show();
    }
    else
    {
        return 0;
    }

    return a.exec();
}
