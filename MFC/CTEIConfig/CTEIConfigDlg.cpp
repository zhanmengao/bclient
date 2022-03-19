
// CTEIConfigDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CTEIConfig.h"
#include "CTEIConfigDlg.h"
#include "afxdialogex.h"
#include"../../../System/File/FileManager/FileManager/PathHelper.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CCTEIConfigDlg 对话框



CCTEIConfigDlg::CCTEIConfigDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CTEICONFIG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCTEIConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_VER, mVEREdit);
	DDX_Control(pDX, IDC_ELINK, mELINK);
	DDX_Control(pDX, IDC_CTEI, mCTEIEdit);
}

BEGIN_MESSAGE_MAP(CCTEIConfigDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CCTEIConfigDlg::OnBnClickedOk)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CCTEIConfigDlg 消息处理程序

BOOL CCTEIConfigDlg::OnInitDialog()
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
	//读配置文件
	mConfig.SetPath(PathHelper::GetModuleFolder() + _T("CTEI.ini"));
	mCTEIEdit.SetWindowText(mConfig.ReadString(_T("commonInfo"), _T("CTEI")).c_str());
	mVEREdit.SetWindowText(mConfig.ReadString(_T("commonInfo"), _T("VER")).c_str());
	UINT elink = mConfig.ReadNum(_T("commonInfo"), _T("ELINK"), 1);
	if (elink == 1)
	{
		mELINK.SetState(1);
	}
	else
	{
		mELINK.SetState(0);
	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCTEIConfigDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCTEIConfigDlg::OnPaint()
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
HCURSOR CCTEIConfigDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCTEIConfigDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	//写配置文件
	CString ctei;
	CString ver;
	mCTEIEdit.GetWindowText(ctei);
	mConfig.WriteString(_T("commonInfo"), _T("CTEI"), ctei.GetBuffer());
	mVEREdit.GetWindowText(ver);
	mConfig.WriteString(_T("commonInfo"), _T("VER"), ver.GetBuffer());
	if (mELINK.GetState() == 1)
	{
		mConfig.WriteNum(_T("commonInfo"), _T("ELINK"), 1);
	}
	else
	{
		mConfig.WriteNum(_T("commonInfo"), _T("ELINK"), 2);
	}
	CDialogEx::OnOK();
}


void CCTEIConfigDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CDialogEx::OnClose();
}


void CCTEIConfigDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	//OPEN
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	BOOL bCreate = CreateProcess((PathHelper::GetModuleFolder() + _T("CTEI.exe")).c_str(), NULL, NULL, NULL,
		FALSE, 0, NULL, NULL, &si, &pi);
	if (bCreate)
	{
		MessageBox(_T("CreateProcess OK"));
	}
	else
	{
		TCHAR buffer[1024] = { 0 };
		wsprintf(buffer, _T("CreateProcess Error %d"), GetLastError());
		MessageBox(buffer);
	}
}
