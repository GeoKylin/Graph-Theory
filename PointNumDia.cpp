// PointNumDia.cpp : 实现文件
//

#include "stdafx.h"
#include "Graph theory.h"
#include "PointNumDia.h"
#include "afxdialogex.h"


// PointNumDia 对话框

IMPLEMENT_DYNAMIC(PointNumDia, CDialogEx)

PointNumDia::PointNumDia(CWnd* pParent /*=NULL*/)
	: CDialogEx(PointNumDia::IDD, pParent)
	, n(0)
{

}

PointNumDia::~PointNumDia()
{
}

void PointNumDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, n);
}


BEGIN_MESSAGE_MAP(PointNumDia, CDialogEx)
END_MESSAGE_MAP()


// PointNumDia 消息处理程序






