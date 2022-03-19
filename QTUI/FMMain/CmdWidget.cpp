#include"CmdWidget.h"
#include"widget.h"
CmdWidget::CmdWidget(QWidget* parent):QWidget(parent)
{
    this->setGeometry(0,0,800,600);
    mCloseBtn = new QPushButton("Close",this);
    mCloseBtn->setGeometry(700,0,50,30);
    connect(mCloseBtn, &QPushButton::clicked, this, &CmdWidget::OnClickClose);
    pInput = new QLineEdit(this);
    pInput->setGeometry(220,500,300,30);
    connect(pInput, &QLineEdit::returnPressed, this,&CmdWidget::OnEnterCommand);

    pArea = new QScrollArea(this);
    pLab = new QLabel(this);
    pLab->setGeometry(20, 50, 600, 400);
    pArea->setWidget(pLab);
    pArea->setGeometry(20, 50, 650, 400);
    pArea->setBackgroundRole(QPalette::Light);
}
CmdWidget::~CmdWidget()
{
}
bool CmdWidget::IsSame() const
{
    return false;
}
void CmdWidget::OnClickClose()
{
    if(Widget::Instance()!=nullptr)
    {
        Widget::Instance()->OnClickCloseCMD();
    }
}
void CmdWidget::InitCmd(unsigned int nSocket)
{
    QString str("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqaaaaaaB\n");
    for(int i = 0;i<nSocket;i++)
    {
        str += str;
    }
    pLab->setText(str);
    pLab->adjustSize();
}
void CmdWidget::OnEnterCommand()
{
    qDebug((string("Command:") + pInput->text().toStdString()).c_str());
    pInput->clear();
}
