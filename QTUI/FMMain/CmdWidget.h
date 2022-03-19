#ifndef CMDWIDGET_H
#define CMDWIDGET_H

#include<QWidget>
#include<QLabel>
#include<QScrollArea>
#include<QLineEdit>
#include <QPushButton>
#include<QGridLayout>
class CmdWidget:public QWidget
{
private:
public:
    CmdWidget(QWidget* parent = nullptr);
    ~CmdWidget();
    bool IsSame() const;
    void InitCmd(unsigned int nSocket);
private slots:
    void OnClickClose();
    void OnEnterCommand();
private:
    QLabel *pLab;
    QScrollArea *pArea;
    QLineEdit *pInput;
    QPushButton *mCloseBtn;
    unsigned int mSocket;
};

#endif // CMDWIDGET_H
