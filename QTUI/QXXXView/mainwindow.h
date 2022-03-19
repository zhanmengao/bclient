#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QLabel>
#include <QComboBox>
#include <QMessageBox>
#include <QDialog>
#include <QListWidget>
#include<QStandardItemModel>
#include<QTableView>
#include<QDebug>
#include<QTreeView>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = NULL);
    ~MainWindow();
private slots:
    void getCurrentItemData();
    void toggleSelection();
    void updateSelection(const QItemSelection& selected,const QItemSelection& deselected);
    void changeCurrent(const QModelIndex& current,const QModelIndex& previous);
private:
    QTableView* tableView;

    QTreeView* treeView;
};
#endif // MAINWINDOW_H
