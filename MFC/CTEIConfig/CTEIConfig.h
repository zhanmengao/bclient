
// CTEIConfig.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCTEIConfigApp: 
// �йش����ʵ�֣������ CTEIConfig.cpp
//

class CCTEIConfigApp : public CWinApp
{
public:
	CCTEIConfigApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCTEIConfigApp theApp;