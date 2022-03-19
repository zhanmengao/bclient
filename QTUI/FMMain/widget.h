#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTabWidget>
#include<vector>
#include<map>
#include<QScrollArea>
#include"ClientItem.h"
#include"DetailWidget.h"
#include"DetailItem.h"
#include"CmdWidget.h"
using namespace  std;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    virtual void resizeEvent(QResizeEvent *event);          //窗口大小变化事件
private:
    static Widget* _Ins;
public:
    static Widget* Instance()
    {
        return _Ins;
    }
public:
    void InitTab();

public:
    void OnEnterFile(ClientItem *item);
    void OnEnterCmd(ClientItem *item);
    void OnCmdEnter(const string& input);
    void OnClickBack();
    void OnEnterClick(FileDetailItem *item);
    void OnClickCloseFile();
    void OnClickCloseCMD();
public:
    void AddClient(unsigned int xPos,unsigned int yPos);
	void DelClient(unsigned short nSocket);

    void OnChooseFile(FileDetailItem* item);
    FileDetailWidget* GetCurFileDetail();
    CmdWidget* GetCurCMDWidget();

private:
    Ui::Widget *ui;
    QScrollArea *pClientScroll;
    QTabWidget *pMainTab;
	QWidget *pMainWid;
    QWidget *pClientWid;


    std::vector<FileDetailWidget*> pFileWidgetVec;
    std::vector<CmdWidget*> pCmdWidgetVec;
    vector<ClientItem*> mClientItemVec;
};
#endif // WIDGET_H
