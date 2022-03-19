#ifndef MYDIAGLOG_H
#define MYDIAGLOG_H
#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
class MyDialog:public QDialog
{
    Q_OBJECT
public:
    MyDialog(QWidget *parent = 0);
    ~MyDialog();
private slots:
    void OnClickOK();
    void OnClickCalcel();
private:
    QLabel* lab;
    QLineEdit* input;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
};

#endif // MYDIAGLOG_H
