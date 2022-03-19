#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QLabel>
#include <QMainWindow>
#include<QSpinBox>

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
    void OnS2ValueChanged(int val);
private:
    Ui::MainWindow *ui;
    QLabel* pLB;
    QSpinBox *pSpBox;
};
#endif // MAINWINDOW_H
