// SeeDia.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Graph theory.h"
#include "SeeDia.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "Graph theoryView.h"
#include "Graph theoryDoc.h"


// SeeDia �Ի���

IMPLEMENT_DYNAMIC(SeeDia, CDialogEx)

SeeDia::SeeDia(CWnd* pParent /*=NULL*/)
	: CDialogEx(SeeDia::IDD, pParent)
{

}

SeeDia::~SeeDia()
{
}

void SeeDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST4, _point);
	DDX_Control(pDX, IDC_LIST5, _line);
}


BEGIN_MESSAGE_MAP(SeeDia, CDialogEx)
END_MESSAGE_MAP()


// SeeDia ��Ϣ�������


BOOL SeeDia::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CGraphtheoryView* pDoc = (CGraphtheoryView*)pMainFrame->GetActiveDocument();
	CGraphtheoryView* pView = (CGraphtheoryView*)pMainFrame->GetActiveView();

	_point.InsertColumn(0, _T("��"), LVCFMT_CENTER, 50, -1);
	_point.InsertColumn(1, _T("x����"), LVCFMT_CENTER, 50, -1);
	_point.InsertColumn(2, _T("y����"), LVCFMT_CENTER, 50, -1);
	_point.InsertColumn(3, _T("��"), LVCFMT_CENTER, 50, -1);
	_line.InsertColumn(0, _T("��"), LVCFMT_CENTER, 60, -1);
	_line.InsertColumn(1, _T("�˵�1"), LVCFMT_CENTER, 60, -1);
	_line.InsertColumn(2, _T("�˵�2"), LVCFMT_CENTER, 60, -1);

	for (int i = 0; i < pView->n; i++)
	{
		CString s;
		s.Format(_T("%d"), i+1);

		int row = _point.GetItemCount();
		_point.InsertItem(row, _T(""));
		_point.SetItemText(row, 0, s);
		s.Format(_T("%d"), pView->_point[0][i]);
		_point.SetItemText(row, 1, s);
		s.Format(_T("%d"), pView->_point[1][i]);
		_point.SetItemText(row, 2, s);
		s.Format(_T("%d"), pView->_point[2][i]);
		_point.SetItemText(row, 3, s);
	}

	for (int i = 0; i < pView->linenum; i++)
	{
		CString s;
		s.Format(_T("%c"), i + 97);

		int row = _line.GetItemCount();
		_line.InsertItem(row, _T(""));
		_line.SetItemText(row, 0, s);
		s.Format(_T("%d"), pView->_line[0][i]);
		_line.SetItemText(row, 1, s);
		s.Format(_T("%d"), pView->_line[1][i]);
		_line.SetItemText(row, 2, s);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
