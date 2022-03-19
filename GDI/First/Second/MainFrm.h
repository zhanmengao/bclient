#pragma once
#include<afxframewndex.h>			//CFrameWndEx

class CMainFrame : public CFrameWndEx
{
public:
	CMainFrame();
	DECLARE_MESSAGE_MAP()		//声明消息映射表
	//消息处理函数
	afx_msg void OnPaint();				
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};