#include"widget.h"
#include<QMessageBox>

void Widget::OnClickMsgCritical()
{
    QMessageBox::StandardButton reply =
            QMessageBox::critical(this,tr("OnClickMsgCritical"),"There is no a disk!",
                                  QMessageBox::Abort | QMessageBox::Retry | QMessageBox::Ignore);
    if(reply == QMessageBox::StandardButton::Abort)
    {
        pLab2->setText("Abort");
    }
    else if(reply == QMessageBox::StandardButton::Retry)
    {
        pLab2->setText("Retry");
    }
    else if(reply == QMessageBox::StandardButton::Ignore)
    {
        pLab2->setText("Ignore");
    }
}
void Widget::OnClickMsgInformation()
{
    QMessageBox::StandardButton reply =
            QMessageBox::information(this,tr("OnClickMsgInformation"),"I am a C++ Developer. <br>"\
                                                                      "I Love QT!",
                                  QMessageBox::Yes | QMessageBox::No |
                                     QMessageBox::Ok | QMessageBox::Cancel);
    if(reply == QMessageBox::StandardButton::Ok)
    {
        pLab2->setText("Ok");
    }
    else if(reply == QMessageBox::StandardButton::Cancel)
    {
        pLab2->setText("Cancel");
    }
    else if(reply == QMessageBox::StandardButton::Yes)
    {
        pLab2->setText("Yes");
    }
    else if(reply == QMessageBox::StandardButton::No)
    {
        pLab2->setText("No");
    }
}
void Widget::OnClickMsgQuestion()
{
    QMessageBox::StandardButton reply =
            QMessageBox::question(this,tr("OnClickMsgQuestion"),"Do you save this files",
                                  QMessageBox::Save | QMessageBox::SaveAll | QMessageBox::Close);
    if(reply == QMessageBox::StandardButton::Save)
    {
        pLab2->setText("Save");
    }
    else if(reply == QMessageBox::StandardButton::SaveAll)
    {
        pLab2->setText("SaveAll");
    }
    else if(reply == QMessageBox::StandardButton::Close)
    {
        pLab2->setText("Close");
    }
}
void Widget::OnClickMsgMyWaring()
{
    QMessageBox msgBox(QMessageBox::Warning,tr("OnClickMsgMyWaring"),"Are you go to Wuhan");
    msgBox.addButton(tr("Go &Again"),QMessageBox::AcceptRole);
    msgBox.addButton(tr("呜呜呜"),QMessageBox::RejectRole);
    auto ret = msgBox.exec();
    if(ret == QMessageBox::AcceptRole)
    {
        pLab2->setText("AcceptRole");
    }
    else if(ret == QMessageBox::RejectRole)
    {
        pLab2->setText("RejectRole");
    }
}
