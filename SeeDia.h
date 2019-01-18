#pragma once

#include "Graph theory.h"
#include "afxcmn.h"
// SeeDia 对话框

class SeeDia : public CDialogEx
{
	DECLARE_DYNAMIC(SeeDia)

public:
	SeeDia(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SeeDia();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl _point;
	virtual BOOL OnInitDialog();
	CListCtrl _line;
};
