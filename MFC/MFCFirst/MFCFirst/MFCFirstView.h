
// MFCFirstView.h : CMFCFirstView ��Ľӿ�
//

#pragma once


class CMFCFirstView : public CView
{
protected: // �������л�����
	CMFCFirstView();
	DECLARE_DYNCREATE(CMFCFirstView)

// ����
public:
	CMFCFirstDoc* GetDocument() const;

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
	virtual ~CMFCFirstView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnViewframe();
};

#ifndef _DEBUG  // MFCFirstView.cpp �еĵ��԰汾
inline CMFCFirstDoc* CMFCFirstView::GetDocument() const
   { return reinterpret_cast<CMFCFirstDoc*>(m_pDocument); }
#endif

