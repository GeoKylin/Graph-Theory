#pragma once

#include "Graph theory.h"
// LineDia �Ի���

class LineDia : public CDialogEx
{
	DECLARE_DYNAMIC(LineDia)

public:
	LineDia(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LineDia();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int point1;
	int point2;
};
