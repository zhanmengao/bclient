
// MFCEventView.cpp : CMFCEventView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCEvent.h"
#endif

#include "MFCEventDoc.h"
#include "MFCEventView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static int cyChar;					//�ַ��߶�
static int cxClient,cyCllient;				//�ͻ�����ǰ�߶�
static int cyClientMax;			//�ͻ������߶�
static int cMaxLineNum, cLineNum;			//����У���ǰ��
static PMSG pmsg;				//��Ϣ
static RECT rectScroll;					//�ͻ�����ҩ�����ľ�������
static TCHAR szTop[] = TEXT("��Ϣ        ɨ����        ����        ��ֵ        �ַ�        �ַ�ֵ        �ظ�����");
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
	// ��׼��ӡ����
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

// CMFCEventView ����/����

CMFCEventView::CMFCEventView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCEventView::~CMFCEventView()
{
}

BOOL CMFCEventView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCEventView ����

void CMFCEventView::OnDraw(CDC* /*pDC*/)
{
	CMFCEventDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCEventView ��ӡ

BOOL CMFCEventView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCEventView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCEventView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

// CMFCEventView ���

#ifdef _DEBUG
void CMFCEventView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCEventView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCEventDoc* CMFCEventView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCEventDoc)));
	return (CMFCEventDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCEventView ��Ϣ�������




void CMFCEventView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	TCHAR buf[1024] = { 0 };
	short ch = GetKeyState(VK_SHIFT);				//������Ϣʱ��VK_SHIFT��״̬
	if (nChar >= 'A' && nChar <= 'Z')
	{
		wsprintf(buf, _T("OnKeyDown �㰴��%c"), nChar);
		//AfxMessageBox(buf);
	}
	else if (nChar == VK_F1)
	{
		AfxMessageBox(_T("����"));
	}
	//��������˿ո� ���� shiftͬʱ����
	else if (nChar == VK_SPACE && (ch & 0x8000))
	{
		PostQuitMessage(0);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CMFCEventView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
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
			wsprintf(buf, _T("���ص�������Ϣ %u"), pMsg->wParam);
			//AfxMessageBox(buf);
			return 1;					//���ط�0��ʾ���ٽ�����������Ϣ����������
		}
	}
	return CView::PreTranslateMessage(pMsg);
}

//�����ַ���Ϣ
void CMFCEventView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	TCHAR buf[1024] = { 0 };
	short ch = GetKeyState(VK_SHIFT);				//������Ϣʱ��VK_SHIFT��״̬
	if (nChar >= '0' && nChar <= '9')
	{
		wsprintf(buf, _T("OnChar �㰴��%u"), nChar);
		//AfxMessageBox(buf);
	}
	else 	if (nChar >= 'A' && nChar <= 'Z')
	{
		wsprintf(buf, _T("OnChar �㰴��%c"), nChar);
		//AfxMessageBox(buf);
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


int CMFCEventView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO:  �ڴ������ר�õĴ�������
	HDC hdc;
	TEXTMETRIC tm;
	cyClientMax = GetSystemMetrics(SM_CYMAXIMIZED);							//��ȡ��Ļ�߶�
	hdc = ::GetDC(m_hWnd);																		//��ȡ�豸������
	::SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));					//��ϵͳ����ѡ���豸������
	GetTextMetrics(hdc, &tm);																		//�õ�������ߴ�
	cyChar = tm.tmHeight;																			//����߶�
	::ReleaseDC(m_hWnd,hdc);

	cLineNum = 0;
	cMaxLineNum = cyClientMax/cyChar;										//�õ���������ı�������Ļ����ʾ���������
	pmsg = (PMSG)malloc(cMaxLineNum * sizeof(MSG));							//����Ļ���ܹ���ʾ����Ϣ�����ڴ�
	return 0;
}


void CMFCEventView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	//����ͻ����߶ȺͿ��
	cxClient = cx;								
	cyCllient = cy;
	
	//���ڴ�С���ˣ������Ժ����ʱ����Ŀͻ�����������
	rectScroll.left = 0;
	rectScroll.right = cxClient;
	rectScroll.top = cyChar;
	rectScroll.bottom = cyChar*cyCllient / cyChar;

	//�ػ������ͻ���
	InvalidateRect(NULL, TRUE);
}


LRESULT CMFCEventView::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: �ڴ����ר�ô����/����û���

	//�ж��Ƿ��ǰ�����Ϣ�����������ַ���ϵͳ������ϵͳ������ϵͳ�ַ�
	if (message == WM_KEYDOWN || message == WM_KEYUP || message == WM_CHAR ||
		message == WM_SYSKEYDOWN || message == WM_SYSKEYUP || message == WM_SYSCHAR)
	{
		//����Ϣ������һ��λ�ã����һ����Ϣ������
		for (int i = cMaxLineNum - 1; i > 0; i--)
		{
			pmsg[i] = pmsg[i - 1];
		}
		//�ո��յ�����Ϣ���ڵ�һ��λ��
		pmsg[0].hwnd = m_hWnd;
		pmsg[0].message = message;
		pmsg[0].wParam = wParam;
		pmsg[0].lParam = lParam;

		//ȷ��Ҫ��Ϣ��ʾ����һ��
		cLineNum = min(cLineNum + 1, cMaxLineNum);
		//���ݸ����ˣ������ͻ��������ݣ����Ϲ��������µ���Ϣ��ʾ��������
		ScrollWindow(0, -cyChar, &rectScroll, &rectScroll);
	}
	return CView::WindowProc(message, wParam, lParam);
}


void CMFCEventView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CView::OnPaint()
	int nType;
	TCHAR szBuff[MAX_PATH] = { 0 };
	TCHAR szKeyName[30] = { 0 };
	dc.SelectObject(GetStockObject(SYSTEM_FIXED_FONT));								//���ı�����ѡ���豸������
	dc.TextOut(0, 0, szTop, lstrlen(szTop));															//����������ͷ������
	//�����Ѿ����ص�����Ϣ�Լ���������
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

		//��ȡ����(ӡ�ڼ����ϵ��ַ�)
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
		//���
		dc.TextOut(0, (cyCllient / cyChar - 1 - i)*cyChar, szBuff, _tcslen(szBuff));
	}
}
