#pragma once

#include "Graph theory.h"

// PointNumDia �Ի���

class PointNumDia : public CDialogEx
{
	DECLARE_DYNAMIC(PointNumDia)

public:
	PointNumDia(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PointNumDia();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	int n;
};
