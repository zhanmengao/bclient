
// MouseEventView.h : CMouseEventView ��Ľӿ�
//

#pragma once


class CMouseEventView : public CView
{
protected: // �������л�����
	CMouseEventView();
	DECLARE_DYNCREATE(CMouseEventView)

// ����
public:
	CMouseEventDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMouseEventView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
};

#ifndef _DEBUG  // MouseEventView.cpp �еĵ��԰汾
inline CMouseEventDoc* CMouseEventView::GetDocument() const
   { return reinterpret_cast<CMouseEventDoc*>(m_pDocument); }
#endif

