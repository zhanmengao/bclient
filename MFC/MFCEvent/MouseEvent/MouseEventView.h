
// MouseEventView.h : CMouseEventView 类的接口
//

#pragma once


class CMouseEventView : public CView
{
protected: // 仅从序列化创建
	CMouseEventView();
	DECLARE_DYNCREATE(CMouseEventView)

// 特性
public:
	CMouseEventDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMouseEventView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
};

#ifndef _DEBUG  // MouseEventView.cpp 中的调试版本
inline CMouseEventDoc* CMouseEventView::GetDocument() const
   { return reinterpret_cast<CMouseEventDoc*>(m_pDocument); }
#endif

