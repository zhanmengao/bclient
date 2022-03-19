#include"widget.h"


void Widget::InitTab()
{
    pMainTab = new QTabWidget(this);
    pMainWid = new QWidget();
	pMainTab->addTab(pMainWid, "Main");
	pClientScroll = new QScrollArea(pMainWid);
	pClientWid = new QWidget(pMainWid);
	pClientScroll->setGeometry(0, 10, 750, 550);
	pClientScroll->setBackgroundRole(QPalette::Light);
	pClientWid->setGeometry(0, 0, 700, 550);
	pClientScroll->setWidget(pClientWid);
    unsigned int xPos = 30,yPos = 0;
    for(int i = 0;i<20;i++)
    {
        AddClient(xPos,yPos);
        yPos += 65;
    }
}
void Widget::AddClient(unsigned int xPos,unsigned int yPos)
{
    mClientItemVec.push_back(new ClientItem(pClientWid,xPos,yPos));
    pClientWid->resize(700, 65 * mClientItemVec.size());
    pClientScroll->update();
}
void Widget::OnClickCloseFile()
{
    auto pLogic = GetCurFileDetail();
	if (pLogic == nullptr)
	{
		return;
	}
    for (auto it = pFileWidgetVec.begin(); it != pFileWidgetVec.end(); it++)
	{
		if (false)
		{
            pFileWidgetVec.erase(it);
			break;
		}
	}
    pMainTab->removeTab(pMainTab->currentIndex());
    pMainTab->setCurrentIndex(0);
}
void Widget::OnClickCloseCMD()
{
    auto pLogic = GetCurCMDWidget();
    if (pLogic == nullptr)
    {
        return;
    }
    for (auto it = pCmdWidgetVec.begin(); it != pCmdWidgetVec.end(); it++)
    {
        if (false)
        {
            pCmdWidgetVec.erase(it);
            break;
        }
    }
    pMainTab->removeTab(pMainTab->currentIndex());
    pMainTab->setCurrentIndex(0);
}
void Widget::OnChooseFile(FileDetailItem* item)
{
    auto pLogic = GetCurFileDetail();
	if (pLogic != nullptr)
	{
		pLogic->OnFileChoose(item);
	}
}
//file list
void Widget::OnEnterFile(ClientItem *item)
{
    FileDetailWidget* pDetail = nullptr;
    for(auto it = pFileWidgetVec.begin();it!=pFileWidgetVec.end();it++)
    {
        if((*it)->IsSame())
        {
            pDetail = *it;
            break;
        }
    }
    if(pDetail == nullptr)
    {
        pDetail = new FileDetailWidget();
        pMainTab->addTab(pDetail,"");
        pDetail->InitDetailList();
        pFileWidgetVec.push_back(pDetail);
    }
    pMainTab->setCurrentWidget(pDetail);
}
void Widget::OnEnterCmd(ClientItem *item)
{
    CmdWidget* pCmd = nullptr;
    for(auto it = pCmdWidgetVec.begin();it!=pCmdWidgetVec.end();it++)
    {
        if((*it)->IsSame())
        {
            pCmd = *it;
            break;
        }
    }
    if(pCmd == nullptr)
    {
        pCmd = new CmdWidget();
        pMainTab->addTab(pCmd,"");
        pCmd->InitCmd(9);
        pCmdWidgetVec.push_back(pCmd);
    }
    pMainTab->setCurrentWidget(pCmd);
}
void Widget::OnCmdEnter(const string& input)
{
    qDebug((string("CMD:") + input).c_str());
}
void Widget::DelClient(unsigned short nSocket)
{

}
FileDetailWidget* Widget::GetCurFileDetail()
{
	if (pMainTab->currentIndex() > 0)
	{
        return dynamic_cast<FileDetailWidget*>(pMainTab->currentWidget());
	}
	return nullptr;
}
CmdWidget* Widget::GetCurCMDWidget()
{
    if (pMainTab->currentIndex() > 0)
    {
        return dynamic_cast<CmdWidget*>(pMainTab->currentWidget());
    }
    return nullptr;
}
void Widget::OnClickBack()
{

}
void Widget::OnEnterClick(FileDetailItem *item)
{

}



