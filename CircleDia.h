#pragma once

#include "Graph theory.h"
#include "afxwin.h"
// CircleDia �Ի���

class CircleDia : public CDialogEx
{
	DECLARE_DYNAMIC(CircleDia)

public:
	CircleDia(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CircleDia();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit allcircle;
	virtual BOOL OnInitDialog();
};
