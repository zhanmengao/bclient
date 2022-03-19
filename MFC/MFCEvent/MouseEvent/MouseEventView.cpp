
// MouseEventView.cpp : CMouseEventView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MouseEvent.h"
#endif

#include "MouseEventDoc.h"
#include "MouseEventView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMouseEventView

IMPLEMENT_DYNCREATE(CMouseEventView, CView)

BEGIN_MESSAGE_MAP(CMouseEventView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_WM_NCLBUTTONDOWN()
END_MESSAGE_MAP()

// CMouseEventView 构造/析构

CMouseEventView::CMouseEventView()
{
	// TODO: 在此处添加构造代码

}

CMouseEventView::~CMouseEventView()
{}

BOOL CMouseEventView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMouseEventView 绘制

void CMouseEventView::OnDraw(CDC* /*pDC*/)
{
	CMouseEventDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMouseEventView 打印

BOOL CMouseEventView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMouseEventView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMouseEventView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMouseEventView 诊断

#ifdef _DEBUG
void CMouseEventView::AssertValid() const
{
	CView::AssertValid();
}

void CMouseEventView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMouseEventDoc* CMouseEventView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMouseEventDoc)));
	return (CMouseEventDoc*)m_pDocument;
}
#endif //_DEBUG


// CMouseEventView 消息处理程序

/*
MK_CONTROL:ctrl被按下
MK_LBUTTON:左键被按下
MK_MBUTTON:中键被按下
MK_RBUTTON:右键被按下
MK_SHIFT:shift被按下
*/
void CMouseEventView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	AfxMessageBox(_T("鼠标左键被按下"));
	CView::OnLButtonDown(nFlags, point);
}


void CMouseEventView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	AfxMessageBox(_T("鼠标右键双击"));
	CView::OnRButtonDblClk(nFlags, point);
}


void CMouseEventView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;
	CPoint screen(point);
	ClientToScreen(&screen);								//客户坐标转化为屏幕坐标

	str.Format(_T("鼠标客户坐标(%d,%d)，鼠标屏幕坐标(%d,%d)."), point.x, point.y, screen.x, screen.y);
	
	CClientDC dc(this);
	dc.TextOut(0, 0, str);
	CView::OnMouseMove(nFlags, point);
}


void CMouseEventView::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CView::OnNcLButtonDown(nHitTest, point);
}
