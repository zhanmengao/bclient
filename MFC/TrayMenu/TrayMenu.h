
// TrayMenu.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTrayMenuApp: 
// �йش����ʵ�֣������ TrayMenu.cpp
//

class CTrayMenuApp : public CWinApp
{
public:
	CTrayMenuApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTrayMenuApp theApp;