#include "stringListModel.h"

#include <QApplication>
#include<QListView>
#include<QTableView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStringList list;
    list<<"a"<<"b"<<"c";
    StringListModel model(list);

    QListView listView;
    listView.setModel(&model);
    listView.show();

    QTableView tabView;
    model.insertRows(3,2);
    model.removeRows(0,1);
    tabView.setModel(&model);
    tabView.show();
    return a.exec();
}
