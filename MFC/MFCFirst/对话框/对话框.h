
// �Ի���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�Ի���App: 
// �йش����ʵ�֣������ �Ի���.cpp
//

class C�Ի���App : public CWinApp
{
public:
	C�Ի���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�Ի���App theApp;