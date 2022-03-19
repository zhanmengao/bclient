
// TrayMenuDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TrayMenu.h"
#include "TrayMenuDlg.h"
#include "afxdialogex.h"
#include<tchar.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define UM_TRAYNOTIFY (WM_USER + 0x100)

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTrayMenuDlg 对话框



CTrayMenuDlg::CTrayMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TRAYMENU_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrayMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTrayMenuDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_CLOSE()
	// 增加的映射 
	ON_MESSAGE(UM_TRAYNOTIFY, NotifyIconCallBack)
END_MESSAGE_MAP()


// CTrayMenuDlg 消息处理程序

BOOL CTrayMenuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	InitNotifyIcon();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTrayMenuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTrayMenuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTrayMenuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


BOOL CTrayMenuDlg::InitNotifyIcon()
{
	// Add a Shell_NotifyIcon notificaion
	m_notifyIconData.cbSize = sizeof(m_notifyIconData);
	// 图标ID
	m_notifyIconData.uID = IDR_MAINFRAME;
	m_notifyIconData.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP | NIF_INFO;
	m_notifyIconData.hIcon = m_hIcon;
	// 这里是定义的消息ID
	m_notifyIconData.uCallbackMessage = UM_TRAYNOTIFY;
	lstrcpy(m_notifyIconData.szTip, _T("我是软件"));
	m_notifyIconData.hWnd = m_hWnd;
	// 更新图标的代码
	//m_notifyIconData.uFlags = NIF_ICON;
	//m_notifyIconData.hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDR_MAINFRAME));

	lstrcpy(m_notifyIconData.szInfoTitle, _T("我是标题"));
	lstrcpy(m_notifyIconData.szInfo, _T("我是信息"));
	m_notifyIconData.uTimeout = 50000;
	m_notifyIconData.dwInfoFlags = NIF_INFO;
	// 增加图标到托盘
	Shell_NotifyIcon(NIM_ADD, &m_notifyIconData);
	return 0;
}

BOOL CTrayMenuDlg::ShowNotifyIcon(BOOL bShow)
{
	BOOL bResult = FALSE;
	if (bShow)
	{
		bResult = Shell_NotifyIcon(NIM_ADD, &m_notifyIconData);
	}
	else
	{
		bResult = Shell_NotifyIcon(NIM_DELETE, &m_notifyIconData);
	}
	return bResult;
}

LRESULT CTrayMenuDlg::NotifyIconCallBack(WPARAM wParam, LPARAM lParam)
{
	switch (UINT(lParam))
	{
	case WM_LBUTTONDOWN:    //左键按下(显示隐藏窗口)
	case WM_LBUTTONDBLCLK:  //左键双击
		if (!IsWindowVisible())
			ShowWindow(SW_SHOW);
		else
			ShowWindow(SW_HIDE);
		break;
	case WM_RBUTTONDOWN:    //右键摁下(弹出菜单)
	{
		CMenu menu;
		menu.LoadMenuW(IDR_MENU1);  //IDR_MENU_NOTIFY 菜单ID
		CPoint point;
		GetCursorPos(&point);
		SetForegroundWindow();
		if (menu.GetSubMenu(0))
		{
			auto id = menu.GetSubMenu(0)->TrackPopupMenu(
				TPM_RETURNCMD | TPM_LEFTBUTTON | TPM_RIGHTBUTTON,
				point.x, point.y, this, NULL);
			switch (id)
			{
			case IDM_HELLO:          //退出
				AfxMessageBox(_T("你好"));
				break;
			case IDM_SB:        //注销重新登录  
				AfxMessageBox(_T("傻逼"));
				break;
			case IDM_EXIT:
				exit(0);
				break;
			default:
				break;
			}
			break;
		}
	}
	case 1029:
	{
		AfxMessageBox(L"点气泡");
		break;
	}
	default:
		{
			char buffer[1024] = { 0 };
			sprintf_s(buffer, _countof(buffer), "%s:%u", "RECV MSGID =", lParam);
			mLog.LogDaily(buffer);
		}
		PostMessage(WM_USER, 0, 0);
		break;
	}
	return LRESULT(1);
}
// 还原窗口
LRESULT CTrayMenuDlg::NotifyIconMesgRestore(WPARAM wParam, LPARAM lParam)
{
	// 还原到其原始大小并显示窗口
	ShowWindow(SW_SHOWNORMAL);
	// 置顶窗口
	::SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
	// 删除托盘图标
	ShowNotifyIcon(FALSE);
	return LRESULT();
}

void CTrayMenuDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码

	if (SIZE_MINIMIZED == nType)
	{
		// 最小化时创建托盘图标
		ShowNotifyIcon(TRUE);
		// 隐藏窗口
		ShowWindow(SW_HIDE);
	}
}

//同时要注意修改系统WM_CLOSE的消息响应函数，只隐藏窗口
void CTrayMenuDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	//CloseWindow();

	ShowWindow(SW_HIDE);
	ShowBubble(_T("MFC托盘"), _T("隐藏"));
}

void CTrayMenuDlg::ShowBubble(LPCWSTR text, LPCWSTR title)
{
	lstrcpy(m_notifyIconData.szInfoTitle, title);
	lstrcpy(m_notifyIconData.szInfo, text);
	Shell_NotifyIcon(NIM_MODIFY, &m_notifyIconData);
}