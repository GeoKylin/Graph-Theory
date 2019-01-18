#pragma once

#include "Graph theory.h"
#include "afxwin.h"
// CircleDia 对话框

class CircleDia : public CDialogEx
{
	DECLARE_DYNAMIC(CircleDia)

public:
	CircleDia(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CircleDia();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit allcircle;
	virtual BOOL OnInitDialog();
};
