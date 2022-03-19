
// MFCEventView.cpp : CMFCEventView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCEvent.h"
#endif

#include "MFCEventDoc.h"
#include "MFCEventView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static int cyChar;					//字符高度
static int cxClient,cyCllient;				//客户区当前高度
static int cyClientMax;			//客户区最大高度
static int cMaxLineNum, cLineNum;			//最大行，当前行
static PMSG pmsg;				//消息
static RECT rectScroll;					//客户区中药滚动的矩形坐标
static TCHAR szTop[] = TEXT("消息        扫描码        键符        键值        字符        字符值        重复计数");
static TCHAR* szMessage[] =
{
	TEXT("WM_KEYDOWN"),TEXT("KEY_UP"),
	TEXT("WM_CHAR"),TEXT("WM_DEADCHAR"),
	TEXT("WM_SYSKEYDOWN"),TEXT("WM_SYSKEYUP")
	TEXT("WM_SYSCHAR"),TEXT("WM_SYSDEADCHAR")
};
// CMFCEventView

IMPLEMENT_DYNCREATE(CMFCEventView, CView)

BEGIN_MESSAGE_MAP(CMFCEventView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	//	ON_WM_KEYUP()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFCEventView 构造/析构

CMFCEventView::CMFCEventView()
{
	// TODO: 在此处添加构造代码

}

CMFCEventView::~CMFCEventView()
{
}

BOOL CMFCEventView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCEventView 绘制

void CMFCEventView::OnDraw(CDC* /*pDC*/)
{
	CMFCEventDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCEventView 打印

BOOL CMFCEventView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCEventView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCEventView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

// CMFCEventView 诊断

#ifdef _DEBUG
void CMFCEventView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCEventView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCEventDoc* CMFCEventView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCEventDoc)));
	return (CMFCEventDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCEventView 消息处理程序




void CMFCEventView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	TCHAR buf[1024] = { 0 };
	short ch = GetKeyState(VK_SHIFT);				//产生消息时，VK_SHIFT的状态
	if (nChar >= 'A' && nChar <= 'Z')
	{
		wsprintf(buf, _T("OnKeyDown 你按了%c"), nChar);
		//AfxMessageBox(buf);
	}
	else if (nChar == VK_F1)
	{
		AfxMessageBox(_T("帮助"));
	}
	//如果按下了空格 并且 shift同时按下
	else if (nChar == VK_SPACE && (ch & 0x8000))
	{
		PostQuitMessage(0);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CMFCEventView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN)
	{
		TCHAR buf[1024] = { 0 };
		if (pMsg->wParam == 229 || pMsg->wParam == VK_SHIFT)
		{
		}
		else if (pMsg->wParam >= 'A' && pMsg->wParam <= 'Z')
		{
			return 0;
		}
		else 	if (pMsg->wParam >= '0' && pMsg->wParam <= '9')
		{
			return 0;
		}
		else
		{
			wsprintf(buf, _T("拦截到按键信息 %u"), pMsg->wParam);
			//AfxMessageBox(buf);
			return 1;					//返回非0表示不再交给正常的消息处理函数处理
		}
	}
	return CView::PreTranslateMessage(pMsg);
}

//处理字符消息
void CMFCEventView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	TCHAR buf[1024] = { 0 };
	short ch = GetKeyState(VK_SHIFT);				//产生消息时，VK_SHIFT的状态
	if (nChar >= '0' && nChar <= '9')
	{
		wsprintf(buf, _T("OnChar 你按了%u"), nChar);
		//AfxMessageBox(buf);
	}
	else 	if (nChar >= 'A' && nChar <= 'Z')
	{
		wsprintf(buf, _T("OnChar 你按了%c"), nChar);
		//AfxMessageBox(buf);
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


int CMFCEventView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO:  在此添加您专用的创建代码
	HDC hdc;
	TEXTMETRIC tm;
	cyClientMax = GetSystemMetrics(SM_CYMAXIMIZED);							//获取屏幕高度
	hdc = ::GetDC(m_hWnd);																		//获取设备描述表
	::SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));					//把系统字体选进设备描述表
	GetTextMetrics(hdc, &tm);																		//得到该字体尺寸
	cyChar = tm.tmHeight;																			//保存高度
	::ReleaseDC(m_hWnd,hdc);

	cLineNum = 0;
	cMaxLineNum = cyClientMax/cyChar;										//得到该字体的文本能在屏幕上显示的最大行数
	pmsg = (PMSG)malloc(cMaxLineNum * sizeof(MSG));							//给屏幕上能够显示的消息分配内存
	return 0;
}


void CMFCEventView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	//缓存客户区高度和宽度
	cxClient = cx;								
	cyCllient = cy;
	
	//窗口大小变了，更新以后滚动时所需的客户区矩形坐标
	rectScroll.left = 0;
	rectScroll.right = cxClient;
	rectScroll.top = cyChar;
	rectScroll.bottom = cyChar*cyCllient / cyChar;

	//重画整个客户区
	InvalidateRect(NULL, TRUE);
}


LRESULT CMFCEventView::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: 在此添加专用代码和/或调用基类

	//判断是否是按键信息，按键弹起，字符，系统按键，系统键弹起，系统字符
	if (message == WM_KEYDOWN || message == WM_KEYUP || message == WM_CHAR ||
		message == WM_SYSKEYDOWN || message == WM_SYSKEYUP || message == WM_SYSCHAR)
	{
		//把消息往后移一个位置，最后一条消息被舍弃
		for (int i = cMaxLineNum - 1; i > 0; i--)
		{
			pmsg[i] = pmsg[i - 1];
		}
		//刚刚收到的消息放在第一个位置
		pmsg[0].hwnd = m_hWnd;
		pmsg[0].message = message;
		pmsg[0].wParam = wParam;
		pmsg[0].lParam = lParam;

		//确定要消息显示在哪一行
		cLineNum = min(cLineNum + 1, cMaxLineNum);
		//数据更新了，滚动客户区的内容，向上滚动，最新的消息显示在最下行
		ScrollWindow(0, -cyChar, &rectScroll, &rectScroll);
	}
	return CView::WindowProc(message, wParam, lParam);
}


void CMFCEventView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CView::OnPaint()
	int nType;
	TCHAR szBuff[MAX_PATH] = { 0 };
	TCHAR szKeyName[30] = { 0 };
	dc.SelectObject(GetStockObject(SYSTEM_FIXED_FONT));								//把文本字体选进设备上下文
	dc.TextOut(0, 0, szTop, lstrlen(szTop));															//画出各个列头的名称
	//画出已经拦截到的消息以及各个参数
	for (int i = 0; i < min(cLineNum, cyCllient / cyChar - 1); i++)
	{
		if (pmsg[i].message == WM_CHAR || pmsg[i].message == WM_SYSCHAR)
		{
			nType = 1;
		}
		else
		{
			nType = 0;
		}

		//获取键符(印在键盘上的字符)
		if (!GetKeyNameText(pmsg[i].lParam, szKeyName, _countof(szKeyName)))
		{
			wsprintf(szBuff, _T("GetKeyNameText Error %u"), GetLastError());
			dc.TextOut(0, (cyCllient / cyChar - 1 - 1)*cyChar, szBuff,_tcslen(szBuff));
			return;
		}

		if(nType)
		{
			wsprintf(szBuff, TEXT("%-13s %4d        %ls        %c        0x%04X%6u"),
				szMessage[pmsg[i].message - WM_KEYFIRST],
				pmsg[i].lParam & 0xFF,
				TEXT("    "),
				pmsg[i].wParam,
				pmsg[i].wParam,
				LOWORD(pmsg[i].lParam)
				);
		}
		else
		{
			wsprintf(szBuff, TEXT("%-13s  %4d        %-15s%c        %3d        %6u"),
				szMessage[pmsg[i].message - WM_KEYFIRST],
				pmsg[i].lParam & 0xFF,
				szKeyName,
				_T('        '),
				pmsg[i].wParam,
				LOWORD(pmsg[i].lParam));
		}
		//输出
		dc.TextOut(0, (cyCllient / cyChar - 1 - i)*cyChar, szBuff, _tcslen(szBuff));
	}
}
