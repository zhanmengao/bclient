#include"../First/MFC1.h"
#include"MainFrm.h"
MyApp app;
BOOL MyApp::InitInstance()
{
	CWinAppEx::InitInstance();
	SetRegistryKey(L"Hello MFC App");
	m_pMainWnd = new CMainFrame();					//给窗口框架分配内存
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}