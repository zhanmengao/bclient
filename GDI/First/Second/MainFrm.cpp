#include"MainFrm.h"

CMainFrame::CMainFrame()
{
	Create(NULL, L"������");						//����������
}
//������Ϣӳ���
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_PAINT()							//������ƴ�����Ϣӳ��
	ON_WM_LBUTTONDOWN()			//������������Ϣӳ��
END_MESSAGE_MAP()
afx_msg void CMainFrame::OnPaint()
{
	CPaintDC dc(this);					//��ͼ�豸������
	CRect rc;
	GetClientRect(&rc);						//�õ��ͻ�����С
	dc.DrawText(L"����һ��MFC����", &rc, FACILITY_VISUALCPP | DT_SINGLELINE | DT_RIGHT);		//�����ı�
}
afx_msg void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	AfxMessageBox(L"������������");
	CFrameWndEx::OnLButtonDown(nFlags, point);
}