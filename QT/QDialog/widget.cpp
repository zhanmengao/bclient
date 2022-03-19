#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //ShowDirsOnly:只显示目录
    //DonResolveSymlinks:不显示符号链接
    //DonConfirmOverwrite:覆盖现存文件不显示警告
    //DontUseNativeDialog:不使用系统默认文件对话框
    //ReadOnly：只读模式
    //HideNameFilterDetails:使用过滤器隐藏文件
    op = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;
    vLayout = new QVBoxLayout();
    for(int i = 0;i<4;i++)
    {
        hLayout[i] = new QHBoxLayout();
        vLayout->addLayout(hLayout[i],i);
    }

    QStringList inputBtnStr = {"Int","Double","List","Text"};
    QStringList fileBtnStr = {"Dir","File","Files","Save"};
    QStringList msgBtnStr = {"Error","Information","Question","My Waring"};
    for(int i = 0 ; i < 4 ; i++)
    {
        inputBtn[i] = new QPushButton(inputBtnStr[i]);
        hLayout[0]->addWidget(inputBtn[i]);
    }

    pLab2 = new QLabel();
    colorBtn = new QPushButton("Color");
    fontBtn = new QPushButton("Font");
    myDialog = new QPushButton("MyDialog");
    hLayout[1]->addWidget(colorBtn);
    hLayout[1]->addWidget(fontBtn);
    hLayout[1]->addWidget(myDialog);
    hLayout[1]->addWidget(pLab2);

    for(int i = 0 ; i < 4 ; i++)
    {
        fileBtn[i] = new QPushButton(fileBtnStr[i]);
        hLayout[2]->addWidget(fileBtn[i]);
    }

    for(int i = 0;i<4;i++)
    {
        msgBtn[i] = new QPushButton(msgBtnStr[i]);
        hLayout[3]->addWidget(msgBtn[i]);
    }
    connect(inputBtn[0],&QAbstractButton::clicked,this,&Widget::OnClickInt);
    connect(inputBtn[1],&QAbstractButton::clicked,this,&Widget::OnClickDouble);
    connect(inputBtn[2],&QAbstractButton::clicked,this,&Widget::OnClickList);
    connect(inputBtn[3],&QAbstractButton::clicked,this,&Widget::OnClickText);
    connect(fileBtn[0],&QAbstractButton::clicked,this,&Widget::OnClickDir);
    connect(fileBtn[1],&QAbstractButton::clicked,this,&Widget::OnClickOpenFile);
    connect(fileBtn[2],&QAbstractButton::clicked,this,&Widget::OnClickOpenFiles);
    connect(fileBtn[3],&QAbstractButton::clicked,this,&Widget::OnClickSaveFile);
    connect(colorBtn,&QAbstractButton::clicked,this,&Widget::OnClickColor);
    connect(fontBtn,&QAbstractButton::clicked,this,&Widget::OnClickFont);
    connect(myDialog,&QAbstractButton::clicked,this,&Widget::OnClickMyDiglog);
    connect(msgBtn[0],&QAbstractButton::clicked,this,&Widget::OnClickMsgCritical);
    connect(msgBtn[1],&QAbstractButton::clicked,this,&Widget::OnClickMsgInformation);
    connect(msgBtn[2],&QAbstractButton::clicked,this,&Widget::OnClickMsgQuestion);
    connect(msgBtn[3],&QAbstractButton::clicked,this,&Widget::OnClickMsgMyWaring);
    setLayout(vLayout);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::OnClickMyDiglog()
{
    MyDialog *mdig = new MyDialog(this);
}

