
// Graph theoryView.h : CGraphtheoryView ��Ľӿ�
//

#pragma once
#include "Graph theoryDoc.h"

class CGraphtheoryView : public CView
{
protected: // �������л�����
	CGraphtheoryView();
	DECLARE_DYNCREATE(CGraphtheoryView)

// ����
public:
	CGraphtheoryDoc* GetDocument() const;

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
	virtual ~CGraphtheoryView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // Graph theoryView.cpp �еĵ��԰汾
inline CGraphtheoryDoc* CGraphtheoryView::GetDocument() const
   { return reinterpret_cast<CGraphtheoryDoc*>(m_pDocument); }
#endif

