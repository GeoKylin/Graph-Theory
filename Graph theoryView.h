
// Graph theoryView.h : CGraphtheoryView 类的接口
//

#pragma once
#include "Graph theoryDoc.h"

class CGraphtheoryView : public CView
{
protected: // 仅从序列化创建
	CGraphtheoryView();
	DECLARE_DYNCREATE(CGraphtheoryView)

// 特性
public:
	CGraphtheoryDoc* GetDocument() const;

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
	virtual ~CGraphtheoryView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void On32771();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

public:
	bool mypoint = false;
	int count = 0;
	int n, t = 0;
	int _point[3][100], _line[2][100], _matrix[100][100], cotreematrix[100][100], circlespace[100][100];
	int linenum = 0, treematrix[100][100];
	int tree[100], cotree[100];

	afx_msg void On32772();
	afx_msg void On32778();
	afx_msg void On32781();
	afx_msg void On32783();
};

#ifndef _DEBUG  // Graph theoryView.cpp 中的调试版本
inline CGraphtheoryDoc* CGraphtheoryView::GetDocument() const
   { return reinterpret_cast<CGraphtheoryDoc*>(m_pDocument); }
#endif

