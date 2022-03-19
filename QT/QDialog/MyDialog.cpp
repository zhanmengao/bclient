#include"MyDiaglog.h"
#include<QHBoxLayout>
#include<QVBoxLayout>
MyDialog::MyDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Custom Dialog");

    lab = new QLabel("Name");
    input = new QLineEdit("");

    okBtn = new QPushButton("OK");
    cancelBtn = new QPushButton("CANCEL");

    QHBoxLayout *hlay1 = new QHBoxLayout();
    hlay1->addWidget(lab);
    hlay1->addWidget(input);

    QHBoxLayout *hlay2 = new QHBoxLayout();
    hlay2->addWidget(okBtn);
    hlay2->addWidget(cancelBtn);

    QVBoxLayout *vlay = new QVBoxLayout();
    vlay->addLayout(hlay1);
    vlay->addLayout(hlay2);

    connect(okBtn,&QPushButton::clicked,this,&MyDialog::OnClickOK);
    connect(cancelBtn,&QPushButton::clicked,this,&MyDialog::OnClickCalcel);
    setLayout(vlay);
    this->exec();
}

MyDialog::~MyDialog()
{

}
void MyDialog::OnClickOK()
{
    qDebug("MyDialog OK");
    this->close();
}
void MyDialog::OnClickCalcel()
{
    qDebug("MyDialog CANCEL");
    this->close();
}
