
// MFCFirstView.cpp : CMFCFirstView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ViewFrame, &CMFCFirstView::OnViewframe)
END_MESSAGE_MAP()

// CMFCFirstView ����/����

CMFCFirstView::CMFCFirstView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCFirstView::~CMFCFirstView()
{
}

BOOL CMFCFirstView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	//�ѱ߿���ȥ����ȥ���������ڿͻ������ == ��ͼ���ڿͻ������
	//cs.style &= ~WS_BORDER;
	return CView::PreCreateWindow(cs);
}

// CMFCFirstView ����

void CMFCFirstView::OnDraw(CDC* /*pDC*/)
{
	CMFCFirstDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCFirstView ��ӡ

BOOL CMFCFirstView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCFirstView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCFirstView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFCFirstView ���

#ifdef _DEBUG
void CMFCFirstView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCFirstView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCFirstDoc* CMFCFirstView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCFirstDoc)));
	return (CMFCFirstDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCFirstView ��Ϣ�������


void CMFCFirstView::OnViewframe()
{
	// TODO: �ڴ���������������
	CRect rt;
	CString str;

	GetClientRect(&rt);
	//��ͼ���ڿͻ�����ȱ������ڿͻ�ȥС��4����ͼ�������������߿�Ŀ��֮�ͣ�
	str.Format(_T("��ͼ���ڿͻ������ %d �߶� %d"), rt.Width(), rt.Height());
	AfxMessageBox(str);
}
