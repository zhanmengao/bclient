#include"../First/MFC1.h"
#include"MainFrm.h"
MyApp app;
BOOL MyApp::InitInstance()
{
	CWinAppEx::InitInstance();
	SetRegistryKey(L"Hello MFC App");
	m_pMainWnd = new CMainFrame();					//�����ڿ�ܷ����ڴ�
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}