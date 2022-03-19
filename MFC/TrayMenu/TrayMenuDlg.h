
// TrayMenuDlg.h : 头文件
//

#pragma once
#include<Winuser.h>
#include"../../../C++space/LogManager/LogManager/LogManager.hpp"
// CTrayMenuDlg 对话框
class CTrayMenuDlg : public CDialogEx
{
// 构造
public:
	CTrayMenuDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRAYMENU_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnClose();
private:
	// 托盘图标用到的变量
	NOTIFYICONDATA m_notifyIconData{ 0 };
	LogManager mLog;
public:
	// 初始化m_notifyIconData
	BOOL InitNotifyIcon();
	// 控制显示/隐藏托盘图标
	BOOL ShowNotifyIcon(BOOL bShow);
	// 托盘图标回调函数
	afx_msg LRESULT NotifyIconCallBack(WPARAM wParam, LPARAM lParam);
	LRESULT NotifyIconMesgRestore(WPARAM wParam, LPARAM lParam);

	void ShowBubble(LPCWSTR text, LPCWSTR title);
	NOTIFYICONDATA m_notifyBubbleData{ 0 };
};
