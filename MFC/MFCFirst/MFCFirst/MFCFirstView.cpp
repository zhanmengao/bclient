
// MFCFirstView.cpp : CMFCFirstView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCFirst.h"
#endif

#include "MFCFirstDoc.h"
#include "MFCFirstView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCFirstView

IMPLEMENT_DYNCREATE(CMFCFirstView, CView)

BEGIN_MESSAGE_MAP(CMFCFirstView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ViewFrame, &CMFCFirstView::OnViewframe)
END_MESSAGE_MAP()

// CMFCFirstView 构造/析构

CMFCFirstView::CMFCFirstView()
{
	// TODO: 在此处添加构造代码

}

CMFCFirstView::~CMFCFirstView()
{
}

BOOL CMFCFirstView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	//把边框风格去掉，去掉后主窗口客户区宽度 == 视图窗口客户区宽度
	//cs.style &= ~WS_BORDER;
	return CView::PreCreateWindow(cs);
}

// CMFCFirstView 绘制

void CMFCFirstView::OnDraw(CDC* /*pDC*/)
{
	CMFCFirstDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCFirstView 打印

BOOL CMFCFirstView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCFirstView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCFirstView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCFirstView 诊断

#ifdef _DEBUG
void CMFCFirstView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCFirstView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCFirstDoc* CMFCFirstView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCFirstDoc)));
	return (CMFCFirstDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCFirstView 消息处理程序


void CMFCFirstView::OnViewframe()
{
	// TODO: 在此添加命令处理程序代码
	CRect rt;
	CString str;

	GetClientRect(&rt);
	//视图窗口客户区宽度比主窗口客户去小了4（视图窗口左右两个边框的宽度之和）
	str.Format(_T("视图窗口客户区宽度 %d 高度 %d"), rt.Width(), rt.Height());
	AfxMessageBox(str);
}
