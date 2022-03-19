
// MFCFirstView.h : CMFCFirstView 类的接口
//

#pragma once


class CMFCFirstView : public CView
{
protected: // 仅从序列化创建
	CMFCFirstView();
	DECLARE_DYNCREATE(CMFCFirstView)

// 特性
public:
	CMFCFirstDoc* GetDocument() const;

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
	virtual ~CMFCFirstView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnViewframe();
};

#ifndef _DEBUG  // MFCFirstView.cpp 中的调试版本
inline CMFCFirstDoc* CMFCFirstView::GetDocument() const
   { return reinterpret_cast<CMFCFirstDoc*>(m_pDocument); }
#endif

