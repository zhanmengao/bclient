
// TrayMenuDlg.h : ͷ�ļ�
//

#pragma once
#include<Winuser.h>
#include"../../../C++space/LogManager/LogManager/LogManager.hpp"
// CTrayMenuDlg �Ի���
class CTrayMenuDlg : public CDialogEx
{
// ����
public:
	CTrayMenuDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRAYMENU_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnClose();
private:
	// ����ͼ���õ��ı���
	NOTIFYICONDATA m_notifyIconData{ 0 };
	LogManager mLog;
public:
	// ��ʼ��m_notifyIconData
	BOOL InitNotifyIcon();
	// ������ʾ/��������ͼ��
	BOOL ShowNotifyIcon(BOOL bShow);
	// ����ͼ��ص�����
	afx_msg LRESULT NotifyIconCallBack(WPARAM wParam, LPARAM lParam);
	LRESULT NotifyIconMesgRestore(WPARAM wParam, LPARAM lParam);

	void ShowBubble(LPCWSTR text, LPCWSTR title);
	NOTIFYICONDATA m_notifyBubbleData{ 0 };
};
