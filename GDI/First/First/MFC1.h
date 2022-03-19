#pragma once
#include<sdkddkver.h>				//定义SDK版本
#include<afxwin.h>					//MFC部分类
#include<afxwinappex.h>			//CWinAppEx
#include<afxframewndex.h>			//CFrameWndEx

class MyApp : public CWinAppEx
{
public:
	virtual BOOL InitInstance();			//重写
};