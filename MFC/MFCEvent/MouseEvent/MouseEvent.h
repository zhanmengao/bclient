
// MouseEvent.h : MouseEvent Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMouseEventApp:
// �йش����ʵ�֣������ MouseEvent.cpp
//

class CMouseEventApp : public CWinApp
{
public:
	CMouseEventApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMouseEventApp theApp;
