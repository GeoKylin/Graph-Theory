// LineDia.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Graph theory.h"
#include "LineDia.h"
#include "afxdialogex.h"


// LineDia �Ի���

IMPLEMENT_DYNAMIC(LineDia, CDialogEx)

LineDia::LineDia(CWnd* pParent /*=NULL*/)
	: CDialogEx(LineDia::IDD, pParent)
	, point1(0)
	, point2(0)
{

}

LineDia::~LineDia()
{
}

void LineDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, point1);
	DDX_Text(pDX, IDC_EDIT2, point2);
}


BEGIN_MESSAGE_MAP(LineDia, CDialogEx)
END_MESSAGE_MAP()


// LineDia ��Ϣ�������

