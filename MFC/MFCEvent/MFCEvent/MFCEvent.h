
// MFCEvent.h : MFCEvent Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCEventApp:
// �йش����ʵ�֣������ MFCEvent.cpp
//

class CMFCEventApp : public CWinAppEx
{
public:
	CMFCEventApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCEventApp theApp;
