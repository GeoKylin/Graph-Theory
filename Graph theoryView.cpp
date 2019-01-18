
// Graph theoryView.cpp : CGraphtheoryView ���ʵ��
//

#include "stdafx.h"

// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CGraphtheoryView ����/����

CGraphtheoryView::CGraphtheoryView()
{
	// TODO:  �ڴ˴���ӹ������

}

CGraphtheoryView::~CGraphtheoryView()
{
}

BOOL CGraphtheoryView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CGraphtheoryView ����

void CGraphtheoryView::OnDraw(CDC* pDC)
{
	CGraphtheoryDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	
}


// CGraphtheoryView ��ӡ

BOOL CGraphtheoryView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CGraphtheoryView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CGraphtheoryView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CGraphtheoryView ���

#ifdef _DEBUG
void CGraphtheoryView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphtheoryView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphtheoryDoc* CGraphtheoryView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphtheoryDoc)));
	return (CGraphtheoryDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphtheoryView ��Ϣ�������


void CGraphtheoryView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CMenu m, *pm;
	if (!m.LoadMenu(IDR_MENU1)) MessageBox(_T("err"));//IDR_MENU1����Ӧ����Դid
	pm = m.GetSubMenu(0); //��ȡ�ӶԻ���
	CPoint pot;
	GetCursorPos(&pot);//��ȡ��굱ǰλ��
	pm->TrackPopupMenu(TPM_LEFTALIGN, pot.x, pot.y, this);//�����λ�õ����˵�

	CView::OnRButtonDown(nFlags, point);
}


void CGraphtheoryView::On32771()
{
	// TODO:  �ڴ���������������
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

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
	// TODO:  �ڴ���������������

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
	// TODO:  �ڴ���������������

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
	// TODO:  �ڴ���������������

	SeeDia s;
	s.DoModal();
}


void CGraphtheoryView::On32783()
{
	// TODO:  �ڴ���������������
	
	CircleDia c;
	c.DoModal();
}
