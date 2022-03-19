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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = NULL);

private:
    QListWidget *listWidget;
    QLineEdit *edt, *edt_add;

private slots:
    void itemSelectionChanged();

    void on_add();

    void on_del();


};
#endif // MAINWINDOW_H
