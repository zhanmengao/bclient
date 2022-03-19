
// TrayMenuDlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CTrayMenuDlg �Ի���



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
	// ���ӵ�ӳ�� 
	ON_MESSAGE(UM_TRAYNOTIFY, NotifyIconCallBack)
END_MESSAGE_MAP()


// CTrayMenuDlg ��Ϣ�������

BOOL CTrayMenuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	InitNotifyIcon();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTrayMenuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTrayMenuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


BOOL CTrayMenuDlg::InitNotifyIcon()
{
	// Add a Shell_NotifyIcon notificaion
	m_notifyIconData.cbSize = sizeof(m_notifyIconData);
	// ͼ��ID
	m_notifyIconData.uID = IDR_MAINFRAME;
	m_notifyIconData.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP | NIF_INFO;
	m_notifyIconData.hIcon = m_hIcon;
	// �����Ƕ������ϢID
	m_notifyIconData.uCallbackMessage = UM_TRAYNOTIFY;
	lstrcpy(m_notifyIconData.szTip, _T("�������"));
	m_notifyIconData.hWnd = m_hWnd;
	// ����ͼ��Ĵ���
	//m_notifyIconData.uFlags = NIF_ICON;
	//m_notifyIconData.hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDR_MAINFRAME));

	lstrcpy(m_notifyIconData.szInfoTitle, _T("���Ǳ���"));
	lstrcpy(m_notifyIconData.szInfo, _T("������Ϣ"));
	m_notifyIconData.uTimeout = 50000;
	m_notifyIconData.dwInfoFlags = NIF_INFO;
	// ����ͼ�굽����
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
	case WM_LBUTTONDOWN:    //�������(��ʾ���ش���)
	case WM_LBUTTONDBLCLK:  //���˫��
		if (!IsWindowVisible())
			ShowWindow(SW_SHOW);
		else
			ShowWindow(SW_HIDE);
		break;
	case WM_RBUTTONDOWN:    //�Ҽ�����(�����˵�)
	{
		CMenu menu;
		menu.LoadMenuW(IDR_MENU1);  //IDR_MENU_NOTIFY �˵�ID
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
			case IDM_HELLO:          //�˳�
				AfxMessageBox(_T("���"));
				break;
			case IDM_SB:        //ע�����µ�¼  
				AfxMessageBox(_T("ɵ��"));
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
		AfxMessageBox(L"������");
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
// ��ԭ����
LRESULT CTrayMenuDlg::NotifyIconMesgRestore(WPARAM wParam, LPARAM lParam)
{
	// ��ԭ����ԭʼ��С����ʾ����
	ShowWindow(SW_SHOWNORMAL);
	// �ö�����
	::SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
	// ɾ������ͼ��
	ShowNotifyIcon(FALSE);
	return LRESULT();
}

void CTrayMenuDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������

	if (SIZE_MINIMIZED == nType)
	{
		// ��С��ʱ��������ͼ��
		ShowNotifyIcon(TRUE);
		// ���ش���
		ShowWindow(SW_HIDE);
	}
}

//ͬʱҪע���޸�ϵͳWM_CLOSE����Ϣ��Ӧ������ֻ���ش���
void CTrayMenuDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	//CloseWindow();

	ShowWindow(SW_HIDE);
	ShowBubble(_T("MFC����"), _T("����"));
}

void CTrayMenuDlg::ShowBubble(LPCWSTR text, LPCWSTR title)
{
	lstrcpy(m_notifyIconData.szInfoTitle, title);
	lstrcpy(m_notifyIconData.szInfo, text);
	Shell_NotifyIcon(NIM_MODIFY, &m_notifyIconData);
}