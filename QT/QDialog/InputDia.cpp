#include"widget.h"
#include<QInputDialog>
void Widget::OnClickInt()
{
    bool retVal;
    int i = QInputDialog::getInt(this,tr("Title::getInteger"),tr("int label"),25,0,100,1,&retVal);
    if(retVal)
    {
        qDebug("On Click OK %d",i);
    }
    else
    {
        qDebug("On Click Calcel %d",i);
    }
}
void Widget::OnClickDouble()
{
    bool retVal;
    double d = QInputDialog::getDouble(this,tr("Title::getDouble"),tr("double label"),48.56,-99.9,100.2,2,&retVal);
    if(retVal)
    {
        qDebug("On Click OK $%1",d);
    }
    else
    {
        qDebug("On Click Calcel $%1",d);
    }
}
void Widget::OnClickList()
{
    bool retVal;
    QStringList sList;
    sList<<tr("Spring")<<tr("Summer")<<tr("Fall")<<tr("Winter");

    QString item = QInputDialog::getItem(this,tr("Title::getItem"),tr("item"),sList,0,false,&retVal);
    if(retVal && item.size() > 0)
    {
        qDebug((std::string("getItem OK") + item.toStdString()).c_str());
    }
}
void Widget::OnClickText()
{
    bool retVal;
    QString text = QInputDialog::getText(this,tr("Title::getText"),tr("username"),
                                         QLineEdit::Normal,QDir::home().dirName(),&retVal);
    if(retVal && text.size() > 0)
    {
        qDebug((std::string("getText OK") + text.toStdString()).c_str());
    }
}
