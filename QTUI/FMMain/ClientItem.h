#ifndef CLIENTITEM_H
#define CLIENTITEM_H

#include<QWidget>
#include<QLabel>
#include<QPushButton>
class ClientItem:public QWidget
{
private:
    QLabel *pLab;
    QPushButton *pCmdbtn;
    QPushButton *pFilebtn;
private slots:
    void btn_File();
    void btn_CMD();
public:
    ClientItem(QWidget* parent,unsigned int xPos,unsigned int yPos);
};

#endif // CLIENTITEM_H
