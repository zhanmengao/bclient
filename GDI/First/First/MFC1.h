#pragma once
#include<sdkddkver.h>				//����SDK�汾
#include<afxwin.h>					//MFC������
#include<afxwinappex.h>			//CWinAppEx
#include<afxframewndex.h>			//CFrameWndEx

class MyApp : public CWinAppEx
{
public:
	virtual BOOL InitInstance();			//��д
};