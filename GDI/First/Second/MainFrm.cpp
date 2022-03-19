#include"MainFrm.h"

CMainFrame::CMainFrame()
{
	Create(NULL, L"主窗口");						//创建主窗口
}
//定义消息映射表
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_PAINT()							//定义绘制窗口消息映射
	ON_WM_LBUTTONDOWN()			//定义鼠标左键消息映射
END_MESSAGE_MAP()
afx_msg void CMainFrame::OnPaint()
{
	CPaintDC dc(this);					//绘图设备描述表
	CRect rc;
	GetClientRect(&rc);						//得到客户区大小
	dc.DrawText(L"这是一个MFC程序", &rc, FACILITY_VISUALCPP | DT_SINGLELINE | DT_RIGHT);		//绘制文本
}
afx_msg void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	AfxMessageBox(L"你点击了鼠标左键");
	CFrameWndEx::OnLButtonDown(nFlags, point);
}