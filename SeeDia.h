#pragma once

#include "Graph theory.h"
#include "afxcmn.h"
// SeeDia �Ի���

class SeeDia : public CDialogEx
{
	DECLARE_DYNAMIC(SeeDia)

public:
	SeeDia(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SeeDia();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl _point;
	virtual BOOL OnInitDialog();
	CListCtrl _line;
};
