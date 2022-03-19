#include <QApplication>
#include "widget.h"
#include"dialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Dialog dlg;
    if(dlg.exec() == QDialog::Accepted)
    {
        w.resize(300, 200);

        w.show();
    }
    else
    {
        return 0;
    }

    return a.exec();
}
