#include"UIInput.h"


void InputWidget::InitLineEdit()
{
    mStr = ("QLineEdit Text:");
    mInput = new QLineEdit("    ",this);
    mInput->setGeometry(10,30,100,30);

    mLabel = new QLabel(mStr,this);
    mLabel->setGeometry(10,80,200,30);
    connect(mInput, &QLineEdit::textChanged, this, &InputWidget::textChanged);
   // connect(mInput,SIGNAL(textChanged(Qstring)),this,SLOT(textChanged(QString)));

    int yPos = 120;
    for(int i = 0;i<4;i++)
    {
        mEdit[i] = new QLineEdit("I Love Ju Ju",this);
        mEdit[i]->setGeometry(10,yPos,200,40);
        yPos+=50;
    }

    mEdit[0]->setEchoMode(QLineEdit::Normal);            //默认
    mEdit[1]->setEchoMode(QLineEdit::NoEcho);            //隐藏输入的文本
    mEdit[2]->setEchoMode(QLineEdit::Password);           //密码
    mEdit[3]->setEchoMode(QLineEdit::PasswordEchoOnEdit);  //若编辑则默认，但移出去以后就是*
}
void InputWidget::textChanged(const QString& str)
{
    mLabel->setText(mStr + str);
}
