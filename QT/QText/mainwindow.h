#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTextBrowser>
#include<QTextEdit>
#include<QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void Emoji();
    void OnEnter();
    void OnRecv();

private:
    Ui::MainWindow *ui;
    QTextBrowser *browser;
    QTextEdit *edit;
};
#endif // MAINWINDOW_H
