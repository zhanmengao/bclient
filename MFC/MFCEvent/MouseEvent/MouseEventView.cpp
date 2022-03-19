
// MouseEventView.cpp : CMouseEventView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_WM_NCLBUTTONDOWN()
END_MESSAGE_MAP()

// CMouseEventView ����/����

CMouseEventView::CMouseEventView()
{
	// TODO: �ڴ˴���ӹ������

}

CMouseEventView::~CMouseEventView()
{}

BOOL CMouseEventView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMouseEventView ����

void CMouseEventView::OnDraw(CDC* /*pDC*/)
{
	CMouseEventDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMouseEventView ��ӡ

BOOL CMouseEventView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMouseEventView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMouseEventView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMouseEventView ���

#ifdef _DEBUG
void CMouseEventView::AssertValid() const
{
	CView::AssertValid();
}

void CMouseEventView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMouseEventDoc* CMouseEventView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMouseEventDoc)));
	return (CMouseEventDoc*)m_pDocument;
}
#endif //_DEBUG


// CMouseEventView ��Ϣ�������

/*
MK_CONTROL:ctrl������
MK_LBUTTON:���������
MK_MBUTTON:�м�������
MK_RBUTTON:�Ҽ�������
MK_SHIFT:shift������
*/
void CMouseEventView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	AfxMessageBox(_T("������������"));
	CView::OnLButtonDown(nFlags, point);
}


void CMouseEventView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	AfxMessageBox(_T("����Ҽ�˫��"));
	CView::OnRButtonDblClk(nFlags, point);
}


void CMouseEventView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str;
	CPoint screen(point);
	ClientToScreen(&screen);								//�ͻ�����ת��Ϊ��Ļ����

	str.Format(_T("���ͻ�����(%d,%d)�������Ļ����(%d,%d)."), point.x, point.y, screen.x, screen.y);
	
	CClientDC dc(this);
	dc.TextOut(0, 0, str);
	CView::OnMouseMove(nFlags, point);
}


void CMouseEventView::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CView::OnNcLButtonDown(nHitTest, point);
}
