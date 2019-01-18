
// Graph theoryView.cpp : CGraphtheoryView 类的实现
//

#include "stdafx.h"

// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Graph theory.h"
#endif

#include "Graph theoryDoc.h"
#include "Graph theoryView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGraphtheoryView

IMPLEMENT_DYNCREATE(CGraphtheoryView, CView)

BEGIN_MESSAGE_MAP(CGraphtheoryView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_32771, &CGraphtheoryView::On32771)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_32772, &CGraphtheoryView::On32772)
	ON_COMMAND(ID_32778, &CGraphtheoryView::On32778)
	ON_COMMAND(ID_32781, &CGraphtheoryView::On32781)
	ON_COMMAND(ID_32783, &CGraphtheoryView::On32783)
END_MESSAGE_MAP()

// CGraphtheoryView 构造/析构

CGraphtheoryView::CGraphtheoryView()
{
	// TODO:  在此处添加构造代码

}

CGraphtheoryView::~CGraphtheoryView()
{
}

BOOL CGraphtheoryView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CGraphtheoryView 绘制

void CGraphtheoryView::OnDraw(CDC* pDC)
{
	CGraphtheoryDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	
}


// CGraphtheoryView 打印

BOOL CGraphtheoryView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CGraphtheoryView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CGraphtheoryView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CGraphtheoryView 诊断

#ifdef _DEBUG
void CGraphtheoryView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphtheoryView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphtheoryDoc* CGraphtheoryView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphtheoryDoc)));
	return (CGraphtheoryDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphtheoryView 消息处理程序


void CGraphtheoryView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CMenu m, *pm;
	if (!m.LoadMenu(IDR_MENU1)) MessageBox(_T("err"));//IDR_MENU1是相应的资源id
	pm = m.GetSubMenu(0); //获取子对话框
	CPoint pot;
	GetCursorPos(&pot);//获取鼠标当前位置
	pm->TrackPopupMenu(TPM_LEFTALIGN, pot.x, pot.y, this);//在鼠标位置弹出菜单

	CView::OnRButtonDown(nFlags, point);
}


void CGraphtheoryView::On32771()
{
	// TODO:  在此添加命令处理程序代码
	PointNumDia p;

	if (p.DoModal() == IDOK)
	{
		n = p.n;
		this->mypoint = true;
		linenum = 0;

		Invalidate();
	}
}


void CGraphtheoryView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);

	int _SIZE = 3;

	CPen black(PS_SOLID, 1, RGB(0, 0, 0));
	CPen red(PS_SOLID, 1, RGB(255, 0, 0));
	CPen blue(PS_SOLID, 1, RGB(0, 0, 255));
	CPen gray(PS_SOLID, 1, RGB(200, 200, 200));
	CBrush blueb(RGB(0, 0, 255));

	if (mypoint == true)
	{
		if (count < n)
		{
			CDC *pDC = GetDC();
			CGdiObject *pOld = pDC->SelectObject(&blueb);
			pDC->Ellipse(point.x - _SIZE, point.y - _SIZE, point.x + _SIZE, point.y + _SIZE);
			CString s; s.Format(_T("%d"), count + 1);
			pDC->TextOutW(point.x + 2 * _SIZE, point.y - 3*_SIZE, s);
			pDC->SelectObject(&blueb);
			
			_point[0][count] = point.x;
			_point[1][count] = point.y;
		}
		if (count==n-1)
		{
			mypoint = false;
			count = -1;
		}
		count++;
	}
}


void CGraphtheoryView::On32772()
{
	// TODO:  在此添加命令处理程序代码

	int hight = 15;

	LineDia l;
	if (l.DoModal() == IDOK)
	{
		CPen black(PS_SOLID, 1, RGB(0, 0, 0));
		CPen red(PS_SOLID, 1, RGB(255, 0, 0));
		CPen blue(PS_SOLID, 1, RGB(0, 0, 255));
		CPen gray(PS_SOLID, 1, RGB(200, 200, 200));

		CDC *pDC = GetDC();
		CGdiObject *pOld = pDC->SelectObject(&black);
		pDC->MoveTo(_point[0][l.point1 - 1], _point[1][l.point1 - 1]);
		pDC->LineTo(_point[0][l.point2 - 1], _point[1][l.point2 - 1]);
		CString s; s.Format(_T("%c"), linenum + 97);
		pDC->TextOutW((_point[0][l.point1 - 1] + _point[0][l.point2 - 1]) / 2, (_point[1][l.point1 - 1] + _point[1][l.point2 - 1]) / 2 - hight, s);
		pDC->SelectObject(&black);

		_line[0][linenum] = l.point1;
		_line[1][linenum] = l.point2;
		linenum++;
	}

	for (int i = 0; i < n; i++)
	{
		(_point[2][i]) = 0;
		for (int j = 0; j < linenum; j++)
		{
			if ((_line[0][j]) == i + 1) (_point[2][i])++;
			else if ((_line[1][j]) == i + 1) (_point[2][i])++;
		}
	}

	int  maxmatrix = 1, sum = 0, mind, minp, minl;
	t = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < linenum; j++)
		{
			if (_line[0][j] == i + 1 || _line[1][j] == i + 1) _matrix[j][i] = 1;
			else _matrix[j][i] = 0;
		}
	}

	while (maxmatrix != 0)
	{
		minp = 1; mind = 200;
		for (int i = 0; i < n; i++)
		{
			sum = 0;
			for (int j = 0; j < linenum; j++)
			{
				sum += _matrix[j][i];
			}
			if (sum < mind&&sum>0)
			{
				mind = sum;
				minp = i + 1;
			}
		}
		minl = 97;
		for (int j = 0; j < linenum; j++)
		{
			if (_matrix[j][minp - 1] == 1)
			{
				minl = j + 97;
				tree[t] = j + 97;
				t++;
				break;
			}
		}

		for (int j = 0; j < linenum; j++)
		{
			if (_matrix[j][minp - 1] == 1)
			{
				for (int i = 0; i < n; i++)
				{
					_matrix[j][i] = 0;
				}
			}
		}

		maxmatrix = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < linenum; j++)
			{
				if (_matrix[j][i] == 1) maxmatrix = 1;
			}
		}
	}

	int co = 0;
	for (int i = 0; i < linenum; i++)
	{
		bool cor = false;
		for (int j = 0; j < t; j++)
		{
			if (i == tree[j]-97)
			{
				cor = true;
			}
		}
		if (cor == false)
		{
			cotree[co] = i + 97;
			co++;
		}
	}
}


void CGraphtheoryView::On32778()
{
	// TODO:  在此添加命令处理程序代码

	CPen black(PS_SOLID, 1, RGB(0, 0, 0));
	CPen red(PS_SOLID, 1, RGB(255, 0, 0));
	CPen blue(PS_SOLID, 1, RGB(0, 0, 255));
	CPen gray(PS_SOLID, 1, RGB(200, 200, 200));

	CDC *pDC = GetDC();
	CGdiObject *pOld = pDC->SelectObject(&black);
	for (int i = 0; i < linenum; i++)
	{
		int p1 = _line[0][i];
		int p2 = _line[1][i];
		pDC->MoveTo(_point[0][p1 - 1], _point[1][p1 - 1]);
		pDC->LineTo(_point[0][p2 - 1], _point[1][p2 - 1]);
	}
	pDC->SelectObject(&red);
	for (int i = 0; i < t; i++)
	{
		int l = tree[i];
		int p1 = _line[0][l - 97];
		int p2 = _line[1][l - 97];
		pDC->MoveTo(_point[0][p1 - 1], _point[1][p1 - 1]);
		pDC->LineTo(_point[0][p2 - 1], _point[1][p2 - 1]);
	}
	pDC->SelectObject(&red);
}


void CGraphtheoryView::On32781()
{
	// TODO:  在此添加命令处理程序代码

	SeeDia s;
	s.DoModal();
}


void CGraphtheoryView::On32783()
{
	// TODO:  在此添加命令处理程序代码
	
	CircleDia c;
	c.DoModal();
}
