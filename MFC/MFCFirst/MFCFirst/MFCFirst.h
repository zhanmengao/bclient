
// MFCFirst.h : MFCFirst Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCFirstApp:
// �йش����ʵ�֣������ MFCFirst.cpp
//

class CMFCFirstApp : public CWinApp
{
public:
	CMFCFirstApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCFirstApp theApp;
