
// CTEIConfigDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CTEIConfig.h"
#include "CTEIConfigDlg.h"
#include "afxdialogex.h"
#include"../../../System/File/FileManager/FileManager/PathHelper.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CCTEIConfigDlg �Ի���



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


// CCTEIConfigDlg ��Ϣ�������

BOOL CCTEIConfigDlg::OnInitDialog()
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
	//�������ļ�
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
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCTEIConfigDlg::OnPaint()
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
HCURSOR CCTEIConfigDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCTEIConfigDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//д�����ļ�
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CDialogEx::OnClose();
}


void CCTEIConfigDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
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
