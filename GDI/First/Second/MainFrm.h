#pragma once
#include<afxframewndex.h>			//CFrameWndEx

class CMainFrame : public CFrameWndEx
{
public:
	CMainFrame();
	DECLARE_MESSAGE_MAP()		//������Ϣӳ���
	//��Ϣ������
	afx_msg void OnPaint();				
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};