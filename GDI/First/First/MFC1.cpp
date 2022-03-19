#include"MFC1.h"

MyApp app;
 BOOL MyApp::InitInstance()			//重写
{
	CWinAppEx::InitInstance();
	SetRegistryKey(TEXT("Hello MFC App"));					//声明本程序的设置存储在注册表
	AfxMessageBox(_T("Hello World!\nFrom MFC"));
	return TRUE;
}