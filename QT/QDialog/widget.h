#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QFileDialog>
#include<QHBoxLayout>
#include<QPushButton>
#include<QLabel>
#include"MyDiaglog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void OnClickDir();
    void OnClickOpenFile();
    void OnClickOpenFiles();
    void OnClickSaveFile();
    void OnClickInt();
    void OnClickDouble();
    void OnClickList();
    void OnClickText();
    void OnClickColor();
    void OnClickFont();
    void OnClickMsgCritical();
    void OnClickMsgInformation();
    void OnClickMsgQuestion();
    void OnClickMsgMyWaring();
    void OnClickMyDiglog();
private:
    Ui::Widget *ui;
    QFileDialog::Options op;

    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout[4];
    QPushButton *fileBtn[4];
    QPushButton *inputBtn[4];
    QPushButton *colorBtn;
    QPushButton *fontBtn;
    QPushButton *myDialog;
    QPushButton *msgBtn[4];
    QLabel *pLab2;

};
#endif // WIDGET_H
