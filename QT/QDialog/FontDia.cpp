#include<QFontDialog>
#include"widget.h"
void Widget::OnClickFont()
{
    bool bOK = false;
    QFont font = QFontDialog::getFont(&bOK,QFont("Courier 10 Pitch"),this);
    if(bOK)
    {
        qDebug(("Select:" + font.key()).toStdString().c_str());
        pLab2->setText(font.key());
        pLab2->setFont(font);
    }
}
