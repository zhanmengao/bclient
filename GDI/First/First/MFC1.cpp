#include"MFC1.h"

MyApp app;
 BOOL MyApp::InitInstance()			//��д
{
	CWinAppEx::InitInstance();
	SetRegistryKey(TEXT("Hello MFC App"));					//��������������ô洢��ע���
	AfxMessageBox(_T("Hello World!\nFrom MFC"));
	return TRUE;
}