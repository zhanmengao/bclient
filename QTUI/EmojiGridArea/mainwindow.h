#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGridLayout>
#include<QScrollArea>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QGridLayout *layout;
    QScrollArea* area;
};
#endif // MAINWINDOW_H
