// CircleDia.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Graph theory.h"
#include "CircleDia.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "Graph theoryView.h"
#include "Graph theoryDoc.h"


// CircleDia �Ի���

IMPLEMENT_DYNAMIC(CircleDia, CDialogEx)

CircleDia::CircleDia(CWnd* pParent /*=NULL*/)
: CDialogEx(CircleDia::IDD, pParent)
{

}

CircleDia::~CircleDia()
{
}

void CircleDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, allcircle);
}


BEGIN_MESSAGE_MAP(CircleDia, CDialogEx)
END_MESSAGE_MAP()


// CircleDia ��Ϣ�������


BOOL CircleDia::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CGraphtheoryView* pDoc = (CGraphtheoryView*)pMainFrame->GetActiveDocument();
	CGraphtheoryView* pView = (CGraphtheoryView*)pMainFrame->GetActiveView();

	int tc;
	for (int i = 0; i < pView->linenum - pView->t; i++)
	{
		for (int j = 0; j < pView->n; j++)                   //ˢ����֦����
		{
			for (int k = 0; k < pView->t; k++)
			{
				tc = pView->tree[k] - 97;
				if (pView->_line[0][tc] == j + 1 || pView->_line[1][tc] == j + 1) pView->treematrix[k][j] = 1;
				else pView->treematrix[k][j] = 0;
			}
		}
		tc = pView->cotree[i] - 97;                         //���һ����֦
		for (int j = 0; j < pView->n; j++)
		{
			if (pView->_line[0][tc] == j + 1 || pView->_line[1][tc] == j + 1) pView->treematrix[pView->t][j] = 1;
			else pView->treematrix[pView->t][j] = 0;
		}


		bool leaf = true;
		int leafnum, branch;
		while (leaf == true)                              //��Ҷ��ѭ��
		{
			leaf = false;
			for (int j = 0; j < pView->n; j++)
			{
				leafnum = 0;
				for (int k = 0; k < pView->t + 1; k++)
				{
					if (pView->treematrix[k][j] == 1)
					{
						leafnum++;
						branch = k;
					}
				}

				if (leafnum == 1)
				{
					leaf = true;
					for (int k = 0; k < pView->n; k++)
					{
						pView->treematrix[branch][k] = 0;
					}
					break;
				}
			}
		}

		int c = 0;
		bool live = false;
		for (int k = 0; k < pView->t; k++)
		{
			live = false;
			for (int j = 0; j < pView->n; j++)
			{
				if (pView->treematrix[k][j] == 1)
				{
					live = true;
					break;
				}
			}

			if (live == true)
			{
				pView->circlespace[i][c] = pView->tree[k];
				c++;
			}
		}
		pView->circlespace[i][c] = tc + 97;
	}

/*	////////////////////////////////  ��������Ȧ  ///////////////////////////////
	int c = pow(2, pView->linenum - pView->t) - 1;
	int z, y = 0, ys = 0, ii;
	int wk = pView->linenum - pView->t;
	int t[100];
	int tnum = 0;
	for (int i = 1; i <= c; i++)    //���μ�������Ȧ
	{
		ii = i;
		ys = 0;                  //�Ƿ����ϳ��ж�
		while (ii != 0)
		{
			ys += ii % 2;
			ii = ii / 2;
		}

		ii = i;
		z = 0;
		if (ys > 1)      //�Ƕ���ϳɣ���ʼ�ϳ�
		{
			while (t[0] > 0)  //��վ��� 
			{
				t[tnum - 1] = t[tnum];
				tnum--;
			}
			tnum = 0;

			while (ii != 0)    //���ο��ǻ���Ȧ���ϲ����ǲ��ϲ�
			{
				y = ii % 2;
				ii = ii / 2;
				if (y == 1)    //�ϲ��������Ȧ
				{
					int j = 0;
					while (pView->circlespace[z][j]>0)    //���ο����������Ȧ�еı��Ƿ�����ʱ�����е��ظ�
					{
						int zl;
						for (zl = 0; zl < pView->linenum; zl++)   //���������ʱ�����еı�
						{
							if (pView->circlespace[z][j] == t[zl])     //���ظ���ɾ���û���Ȧ�еĴ˱�
							{
								for (int w = zl; w < tnum; w++)
								{
									t[w] = t[w + 1];
								}
								tnum--;
								zl--;
								break;
							}
						}
						if (zl == pView->linenum)
						{
							t[tnum] = pView->circlespace[z][j];
							tnum++;
						}  //δ�ظ�����¼�����
						j++;
					}
				}
				z++;
			}

			tnum = 0;
			while (t[tnum] > 0)   //�ϲ���ɣ����ϲ������ʱ�����еıߵ���Ȧ�ռ����
			{
				pView->circlespace[wk][tnum] = t[tnum];
				tnum++;
			}
			wk++;
		}
	}
	/////////////////////////////////////////////////////////////////////////////////

	int headp, tx, x, ls;
	for (int i = 0; i < c; i++)   //��Ȧ�������
	{
		headp = pView->_line[1][pView->circlespace[i][0] - 97];   //��ʼ��ͷ��
		tx = 0;
		while (pView->circlespace[i][tx]>0)     //�仯�Ĺ̶���
		{
			x = tx + 1;
			while (pView->circlespace[i][x]>0)    //�仯�ı仯��
			{
				if (pView->_line[0][pView->circlespace[i][x] - 97] == headp)
				{
					headp = pView->_line[1][pView->circlespace[i][x] - 97];
					ls = pView->circlespace[i][tx + 1];
					pView->circlespace[i][tx + 1] = pView->circlespace[i][x];
					pView->circlespace[i][x] = ls;
					break;
				}
				else if (pView->_line[1][pView->circlespace[i][x] - 97] == headp)
				{
					headp = pView->_line[0][pView->circlespace[i][x] - 97];
					ls = pView->circlespace[i][tx + 1];
					pView->circlespace[i][tx + 1] = pView->circlespace[i][x];
					pView->circlespace[i][x] = ls;
					break;
				}
				x++;
			}
			tx++;
		}
	}
*/

int circlenum = pView->linenum - pView->t;
int headp, tx, x, ls;
for (int i = 0; i < circlenum; i++)   //��Ȧ�������
{
	headp = pView->_line[1][pView->circlespace[i][0] - 97];   //��ʼ��ͷ��
	tx = 0;
	while (pView->circlespace[i][tx]>0)     //�仯�Ĺ̶���
	{
		x = tx + 1;
		while (pView->circlespace[i][x]>0)    //�仯�ı仯��
		{
			if (pView->_line[0][pView->circlespace[i][x] - 97] == headp)
			{
				headp = pView->_line[1][pView->circlespace[i][x] - 97];
				ls = pView->circlespace[i][tx + 1];
				pView->circlespace[i][tx + 1] = pView->circlespace[i][x];
				pView->circlespace[i][x] = ls;
				break;
			}
			else if (pView->_line[1][pView->circlespace[i][x] - 97] == headp)
			{
				headp = pView->_line[0][pView->circlespace[i][x] - 97];
				ls = pView->circlespace[i][tx + 1];
				pView->circlespace[i][tx + 1] = pView->circlespace[i][x];
				pView->circlespace[i][x] = ls;
				break;
			}
			x++;
		}
		tx++;
	}
}
int c = pow(2, pView->linenum - pView->t) - 1;
int ys;
int plusmatrix[100][100];
for (int i = 1; i <= c; i++)
{
	int a = 0;
	while (plusmatrix[a][0] >= 0)
	{
		int b = 0;
		while (plusmatrix[a][b] >= 0)
		{
			plusmatrix[a][b] = -2;
			b++;
		}
		a++;
	}
	int ii = i;
	int plus[100];
	while (plus[0]>=0)
	{
		plus[ys - 1] = plus[ys];
		ys--;
	}
	int z = 0;
	ys = 0;
	while (ii != 0)
	{
		ys = ii % 2 + ys;
		if (ii % 2)
		{
			plus[ys - 1] = z;
		}
		ii = ii / 2;
		z++;
	}
	if (ys > 1)
	{
		for (int j = 0; j < ys; j++)
		{
			int k = 0;
			while (pView->circlespace[plus[j]][k]>0)
			{
				for (int m = 0; m < pView->n; m++)
				{
					if (pView->_line[0][pView->circlespace[plus[j]][k]-97] == m + 1 || pView->_line[1][pView->circlespace[plus[j]][k]-97] == m + 1)
					{
						plusmatrix[j][m] = 1;
					}
					else
					{
						if (plusmatrix[j][m] != 1)
						{
							plusmatrix[j][m] = 0;
						}
					}
				}
				k++;
			}
		}
		bool havealonecircle = false;
		for (int j = 0; j < ys; j++)
		{
			bool alonep = true;
			for (int k = 0; k < pView->n; k++)
			{
				int pcount = 0;
				if (plusmatrix[j][k] == 1)
				{
					for (int l = 0; l < ys; l++)
					{
						if (plusmatrix[l][k] == 1)
						{
							pcount++;
						}
					}
				}
				if (pcount>1)
				{
					alonep = false; break;
				}
			}
			if (alonep == true)
			{
				havealonecircle = true;
				break;
			}
		}
		if (havealonecircle == true)
		{
			continue;
		}
		else
		{
			int j = 0;
			while (pView->circlespace[plus[0]][j]>0)
			{
				pView->circlespace[circlenum][j] = pView->circlespace[plus[0]][j];
				j++;
			}
			for (int n = 0; n < ys - 1; n++)
			{
				for (int k = 0; k<pView->n; k++)
				{
					plusmatrix[0][k] = 0;
				}
				int k = 0;
				while (pView->circlespace[circlenum][k]>0)
				{
					for (int m = 0; m < pView->n; m++)
					{
						if (pView->_line[0][pView->circlespace[circlenum][k]-97] == m + 1 || pView->_line[1][pView->circlespace[circlenum][k]-97] == m + 1)
						{
							plusmatrix[0][m] = 1;
						}
						else
						{
							if (plusmatrix[0][m] != 1)
							{
								plusmatrix[0][m] = 0;
							}
						}
					}
					k++;
				}
				bool yunsuan;
				for (int k = 0; k < pView->n; k++)
				{
					yunsuan = false;
					if (plusmatrix[0][k] == 1)
					{
						for (int l = 1; l < ys; l++)
						{
							if (plusmatrix[l][k] == 1)
							{
								int m = 0;
								while (pView->circlespace[plus[l]][m]>0)
								{
									int o = 0;
									int q = 0;
									while (pView->circlespace[circlenum][o] > 0)
									{
										if (pView->circlespace[circlenum][o] == pView->circlespace[plus[l]][m])
										{
											int p = o;
											while (pView->circlespace[circlenum][p] > 0)
											{
												pView->circlespace[circlenum][p] = pView->circlespace[circlenum][p+1];		//������
												p++;
											}
											q++;
											break;
										}
										else
										{
											q++;
										}
										o++;
									}
									if (o == q)
									{
										pView->circlespace[circlenum][o] = pView->circlespace[plus[l]][m];
									}
									m++;
								}
								for (int m = 0; m < pView->n; m++)
								{
									plusmatrix[l][m] = 0;
								}
								yunsuan = true;

								int maxdu = 0;
								int maxp_l;
								int wp, maxdu_p;
								int pl;
								for (int wj = 0; wj < pView->n; wj++)
								{
									int wk = 0;
									int dup = 0;
									while (pView->circlespace[circlenum][wk]>0)
									{
										if (pView->_line[0][pView->circlespace[circlenum][wk] - 97] == wj + 1 || pView->_line[1][pView->circlespace[circlenum][wk] - 97] == wj + 1)
										{
											dup++;
											pl = pView->circlespace[circlenum][wk];
											wp = wj + 1;
										}
										wk++;
									}
									if (dup > maxdu)
									{
										maxdu = dup;
										maxdu_p = wp;
										maxp_l = pl;
									}
								}
								int wj = 0;
								int wls;
								while (pView->circlespace[circlenum][wj] > 0)
								{
									if (pView->circlespace[circlenum][wj] == maxp_l)
									{
										wls = pView->circlespace[circlenum][0];
										pView->circlespace[circlenum][0] = pView->circlespace[circlenum][wj];
										pView->circlespace[circlenum][wj] = wls;
									}
									wj++;
								}
								int headp, wtx, wx;
								headp = maxdu_p;   //��ʼ��ͷ��
								if (pView->_line[0][pView->circlespace[circlenum][0]-97] == headp)
								{
									headp = pView->_line[1][pView->circlespace[circlenum][0] - 97];
								}
								else if (pView->_line[1][pView->circlespace[circlenum][0]-97] == headp)
								{
									headp = pView->_line[0][pView->circlespace[circlenum][0] - 97];
								}
								wtx = 0;
								while (pView->circlespace[circlenum][wtx]>0)     //�仯�Ĺ̶���
								{
									wx = wtx + 1;
									while (pView->circlespace[circlenum][wx]>0)    //�仯�ı仯��
									{
										if (pView->_line[0][pView->circlespace[circlenum][wx] - 97] == headp)
										{
											headp = pView->_line[1][pView->circlespace[circlenum][wx] - 97];
											wls = pView->circlespace[circlenum][wtx + 1];
											pView->circlespace[circlenum][wtx + 1] = pView->circlespace[circlenum][wx];
											pView->circlespace[circlenum][wx] = wls;
											break;
										}
										else if (pView->_line[1][pView->circlespace[circlenum][wx] - 97] == headp)
										{
											headp = pView->_line[0][pView->circlespace[circlenum][wx] - 97];
											wls = pView->circlespace[circlenum][wtx + 1];
											pView->circlespace[circlenum][wtx + 1] = pView->circlespace[circlenum][wx];
											pView->circlespace[circlenum][wx] = wls;
											break;
										}
										wx++;
									}
									wtx++;
								}

							}
						}
					}
					if (yunsuan == true)
					{
						break;
					}
				}
			}
			circlenum++;
		}
	}
}



	CString s;
	/*	for (int i = 0; i < c; i++)
	{
	s.Format(_T("%2d : "), i+1 );
	allcircle.SetSel(-1, -1);
	allcircle.ReplaceSel(s);



	}
	*/
	for (int i = 0; i < circlenum; i++)
	{
		s.Format(_T("%2d : "), i + 1);
		allcircle.SetSel(-1, -1);
		allcircle.ReplaceSel(s);

		int j = 0;
		while (pView->circlespace[i][j]>0)
		{
			s.Format(_T(" %c "), pView->circlespace[i][j]);
			allcircle.SetSel(-1, -1);
			allcircle.ReplaceSel(s);
			j++;

			if (pView->circlespace[i][j] > 0)
			{
				allcircle.SetSel(-1, -1);
				allcircle.ReplaceSel(_T(" -> "));
			}
		}

		allcircle.SetSel(-1, -1);
		allcircle.ReplaceSel(_T("\n"));
	}
	//�������
	/*	for (int i = 0; i < pView->linenum-pView->t; i++)
	{
	s.Format(_T(" %c -> "), pView->cotree[i]);

	allcircle.SetSel(-1, -1);
	allcircle.ReplaceSel(s);
	}
	*/
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
