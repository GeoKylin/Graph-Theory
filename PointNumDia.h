#pragma once

#include "Graph theory.h"

// PointNumDia 对话框

class PointNumDia : public CDialogEx
{
	DECLARE_DYNAMIC(PointNumDia)

public:
	PointNumDia(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PointNumDia();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	int n;
};
