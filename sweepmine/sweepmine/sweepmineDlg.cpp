
// sweepmineDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "sweepmine.h"
#include "sweepmineDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CsweepmineDlg �Ի���



CsweepmineDlg::CsweepmineDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CsweepmineDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	row = col = 21;
	cx = cy = 32;
	x = 2;
	y = 42;
}

void CsweepmineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NUMBER, m_Number);
	DDX_Control(pDX, IDC_TIME, m_Time);
}

BEGIN_MESSAGE_MAP(CsweepmineDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_BUTSTART, &CsweepmineDlg::OnBnClickedButstart)
END_MESSAGE_MAP()


// CsweepmineDlg ��Ϣ�������

BOOL CsweepmineDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	for (int i=0; i<row-1; i++)
	{
		for (int j=0; j<col-1; j++)
		{
			m_GridNum[i][j].m_Rect= CRect(x+cx*j,y+cy*i,x+cx*(j+1),y+cy*(i+1)); 
		}
	}
	for (int i=0; i<row-1; i++)
	{
		for (int j=0; j<col-1; j++)
		{
			SetRecentGrid(&m_GridNum[i][j]);
		}
	}
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CsweepmineDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CsweepmineDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	CDC* pDC = GetDC();
	CBitmap bmp1,bmp2,bmp3,bmp4,bmp5,bmp6,bmp7,bmp8,bmp9,bmp10,bmp11,bk;
	CDC memdc;
	memdc.CreateCompatibleDC(pDC);
	bmp1.LoadBitmap(IDB_MINE);
	bmp2.LoadBitmap(IDB_FLAG);
	bmp3.LoadBitmap(IDB_NULL);
	bmp4.LoadBitmap(IDB_ONE);
	bmp5.LoadBitmap(IDB_TWO);
	bmp6.LoadBitmap(IDB_THREE);
	bmp7.LoadBitmap(IDB_FOUR);
	bmp8.LoadBitmap(IDB_FIVE);
	bmp9.LoadBitmap(IDB_SIX);
	bmp10.LoadBitmap(IDB_SEVEN);
	bmp11.LoadBitmap(IDB_EIGHT);
	bk.LoadBitmap(IDB_UNDOWN);
	CRect rect;
	GetClientRect(rect);
	for (int m=0; m<row-1; m++)
	{
		for (int n=0; n<col-1; n++)
		{
			memdc.SelectObject(&bk);
			pDC->BitBlt(m_GridNum[m][n].m_Rect.left,m_GridNum[m][n].m_Rect.top,
				32,32,&memdc,0,0,SRCCOPY);
			if(m_GridNum[m][n].m_IsShow == TRUE)
			{
				if(m_GridNum[m][n].m_State == ncMINE)
				{
					memdc.SelectObject(&bmp1);
					pDC->BitBlt(m_GridNum[m][n].m_Rect.left,m_GridNum[m][n].m_Rect.top,
						32,32,&memdc,0,0,SRCCOPY);	
				}
				else if(m_GridNum[m][n].m_State == ncFLAG)
				{
					memdc.SelectObject(&bmp2);
					pDC->BitBlt(m_GridNum[m][n].m_Rect.left,m_GridNum[m][n].m_Rect.top,
						32,32,&memdc,0,0,SRCCOPY);				
				}
				else if(m_GridNum[m][n].m_State == ncNULL)
				{
					memdc.SelectObject(&bmp3);
					pDC->BitBlt(m_GridNum[m][n].m_Rect.left,m_GridNum[m][n].m_Rect.top,
						32,32,&memdc,0,0,SRCCOPY);				
				}
				else if(m_GridNum[m][n].m_State == ncONE)
				{
					memdc.SelectObject(&bmp4);
					pDC->BitBlt(m_GridNum[m][n].m_Rect.left,m_GridNum[m][n].m_Rect.top,
						32,32,&memdc,0,0,SRCCOPY);				
				}
				else if(m_GridNum[m][n].m_State == ncTWO)
				{
					memdc.SelectObject(&bmp5);
					pDC->BitBlt(m_GridNum[m][n].m_Rect.left,m_GridNum[m][n].m_Rect.top,
						32,32,&memdc,0,0,SRCCOPY);				
				}
				else if(m_GridNum[m][n].m_State == ncTHREE)
				{
					memdc.SelectObject(&bmp6);
					pDC->BitBlt(m_GridNum[m][n].m_Rect.left,m_GridNum[m][n].m_Rect.top,
						32,32,&memdc,0,0,SRCCOPY);				
				}
				else if(m_GridNum[m][n].m_State == ncFOUR)
				{
					memdc.SelectObject(&bmp7);
					pDC->BitBlt(m_GridNum[m][n].m_Rect.left,m_GridNum[m][n].m_Rect.top,
						32,32,&memdc,0,0,SRCCOPY);				
				}
				else if(m_GridNum[m][n].m_State == ncFIVE)
				{
					memdc.SelectObject(&bmp8);
					pDC->BitBlt(m_GridNum[m][n].m_Rect.left,m_GridNum[m][n].m_Rect.top,
						32,32,&memdc,0,0,SRCCOPY);				
				}
				else if(m_GridNum[m][n].m_State == ncSIX)
				{
					memdc.SelectObject(&bmp9);
					pDC->BitBlt(m_GridNum[m][n].m_Rect.left,m_GridNum[m][n].m_Rect.top,
						32,32,&memdc,0,0,SRCCOPY);				
				}
				else if(m_GridNum[m][n].m_State == ncSEVEN)
				{
					memdc.SelectObject(&bmp10);
					pDC->BitBlt(m_GridNum[m][n].m_Rect.left,m_GridNum[m][n].m_Rect.top,
						32,32,&memdc,0,0,SRCCOPY);				
				}
				else if(m_GridNum[m][n].m_State == ncEIGHT)
				{
					memdc.SelectObject(&bmp11);
					pDC->BitBlt(m_GridNum[m][n].m_Rect.left,m_GridNum[m][n].m_Rect.top,
						32,32,&memdc,0,0,SRCCOPY);				
				}
			}
		}
	}
	ReleaseDC(&memdc);
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CsweepmineDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CsweepmineDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	GRID* grid = GetLikeGrid(point); 
	if(grid != NULL)
	{
		grid->m_IsShow = TRUE;
		if(grid->m_State == ncMINE)
		{
			ShowAllMine();
			Invalidate();
			KillTimer(1);
			MessageBox(_T("�����ˣ�"));
			if(MessageBox(_T("�Ƿ��������Ϸ��"),_T("ϵͳ��ʾ"),MB_YESNO 
				| MB_ICONQUESTION) == IDYES)
			{
				OnBnClickedButstart();
			}
			else
				OnCancel();
		}
		else if(grid->m_State == ncNULL)
			DownNullShow(grid);
		Invalidate();
	}
	CDialog::OnLButtonDown(nFlags, point);
}


void CsweepmineDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	GRID* grid = GetLikeGrid(point); 
	if(grid != NULL)
	{
		if(m_Flag == 70)
		{
			MessageBox(_T("��������꣡"));
			return;
		}
		if(grid->m_State==ncFLAG)
		{
			for(int i=0;i<70;i++)
			{
				if(m_FlagRect[i] == grid->m_Rect)
				{
					grid->m_State = m_FlagState[i];
					m_FlagState[i] = ncUNDOWN;
					m_FlagRect[i] = 0;
					grid->m_IsShow = FALSE;
					m_Flag--;
					CString str;
					str.Format(_T("ʣ���������%d"),70-m_Flag);
					m_Number.SetWindowText(str);
				}
			}
		}
		else
		{
			if(grid->m_IsShow == FALSE)
			{
				m_FlagRect[m_Flag] = grid->m_Rect;
				m_FlagState[m_Flag++] = grid->m_State;
				CString str;
				str.Format(_T("ʣ���������%d"),70-m_Flag);
				m_Number.SetWindowText(str);
				grid->m_State = ncFLAG;
				grid->m_IsShow = TRUE;
				if(IsWin())
				{
					KillTimer(1);
					MessageBox(_T("��Ӯ��"));
					if(MessageBox(_T("�Ƿ��������Ϸ��"),_T("ϵͳ��ʾ"),MB_YESNO 
						| MB_ICONQUESTION) == IDYES)
					{
						OnBnClickedButstart();
					}
					else
						OnCancel();
				}
			}
		}
		Invalidate();
	}
	CDialog::OnRButtonDown(nFlags, point);
}


void CsweepmineDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_GameTime++;
	CString str;
	str.Format(_T("��Ϸʱ�䣺%d��"),m_GameTime);
	m_Time.SetWindowText(str);
	CDialog::OnTimer(nIDEvent);
}


void CsweepmineDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	GRID* grid = GetLikeGrid(point); 
	if(grid != NULL)
	{
		int num = IsNumber(grid->m_State);
		if(num != 9)
		{
			grid->m_IsShow = TRUE;
			DblClkNum(grid,num);
		}
	/*	for(int i=0;i<70;i++)
		{
			if(grid->m_State==ncFLAG)
			{
				if(m_FlagRect[i] == grid->m_Rect)
					grid->m_State = m_FlagState[i];
			}
		}*/
		Invalidate();	
	}
	CDialog::OnLButtonDblClk(nFlags, point);
}


void CsweepmineDlg::OnBnClickedButstart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetTimer(1,1000,NULL);
	m_GameTime = 0;
	m_Flag = 0;
	m_MineNum = 0;
	InitializeGrid();
	SetGridState();
	Invalidate();
	m_Number.SetWindowText(_T("ʣ���������70"));
	m_Time.SetWindowText(_T("��Ϸʱ�䣺0��"));
}
void CsweepmineDlg::SetRecentGrid(GRID *pGrid)
{
	//����һ���ڵ���8���ٽ��ڵ�
	CRect rect = pGrid->m_Rect;
	//���Ϸ����ٽ��ڵ�
	CRect rc1 = CRect(rect.left-cx,rect.top-cy,rect.left,rect.top);
	pGrid->m_pRecents[0]= GetGridRect(rc1);
	//�Ϸ��ٽ��ڵ�
	CRect rc2 = CRect(rect.left,rect.top-cy,rect.right,rect.top);
	pGrid->m_pRecents[1]= GetGridRect(rc2);
	//���Ϸ��ٽ��ڵ�
	CRect rc3 = CRect(rect.right,rect.top-cy,rect.right+cx,rect.top);
	pGrid->m_pRecents[2]= GetGridRect(rc3);
	//�󷽽ڵ��ٽ��ڵ�
	CRect rc4 = CRect(rect.left-cx,rect.top,rect.left,rect.bottom);
	pGrid->m_pRecents[3]= GetGridRect(rc4);
	//�ҷ��ڵ��ٽ��ڵ�
	CRect rc5 = CRect(rect.right,rect.top,rect.right+cx,rect.bottom);
	pGrid->m_pRecents[4]= GetGridRect(rc5);
	//���·��ٽ��ڵ�
	CRect rc6 = CRect(rect.left-cx,rect.bottom,rect.left,rect.bottom+cy);
	pGrid->m_pRecents[5]= GetGridRect(rc6);
	//�·��ٽ��ڵ�
	CRect rc7 = CRect(rect.left,rect.bottom,rect.right,rect.bottom+cy);
	pGrid->m_pRecents[6]= GetGridRect(rc7);
	//���·��ٽ��ڵ�
	CRect rc8 = CRect(rect.right,rect.bottom,rect.right+cx,rect.bottom+cy);
	pGrid->m_pRecents[7]= GetGridRect(rc8);
}
void CsweepmineDlg::InitializeGrid()
{
	for(int i=0; i<row-1; i++)
	{
		for(int j=0; j<col-1; j++)
		{
			m_GridNum[i][j].m_State = ncUNDOWN;	
			m_GridNum[i][j].m_IsShow = FALSE;	
		}
	}
	for(int n=0;n<70;n++)
	{
		m_FlagState[n] = ncUNDOWN;
		m_FlagRect[n] = 0;
	}
}
void CsweepmineDlg::SetGridState()
{
	SetRandMine();
	for(int i=0; i<row-1; i++)
	{
		for(int j=0; j<col-1; j++)
		{
			BOOL m = FALSE;
			for(int n=0;n<70;n++)
			{
				int num = i*20+j;
				if(m_Mine[n] == num)
					m = TRUE;
			}
			if(m)
			{
				m_GridNum[i][j].m_State = ncMINE;	
				m_MineRect[m_MineNum++] = m_GridNum[i][j].m_Rect;
			}
		}
	}
	for(int i=0; i<row-1; i++)
	{
		for(int j=0; j<col-1; j++)
		{
			if(m_GridNum[i][j].m_State != ncMINE)
			{
				UINT num = CountNumber(&m_GridNum[i][j]);
				GetShowNum(num);
				m_GridNum[i][j].m_State = m_Num;
			}
		}
	}
}
void CsweepmineDlg::SetRandMine()
{
	CTime time;
	time = CTime::GetCurrentTime();
	srand(time.GetHour()+time.GetMinute()+time.GetSecond());
	m_Mine[0] = rand()%399;
	int k=1,n=0,m=0;
	while(k != 70)
	{
		n = rand()%399;
		for(int i=0;i<k;i++)
		{
			if(m_Mine[i] == n)
			{
				m = 1;
			}
		}
		if(m == 0)	
		{
			k++;
			m_Mine[k-1] = n;
		}
		m = 0;
	}
}
UINT CsweepmineDlg::CountNumber(GRID *pGRID)
{
	int result=0;
	GRID* tmp = pGRID->m_pRecents[0]; 
	if(tmp!=NULL && tmp->m_State == ncMINE)
		result++;
	tmp = pGRID->m_pRecents[1]; 
	if(tmp!=NULL && tmp->m_State == ncMINE)
		result++;
	tmp = pGRID->m_pRecents[2]; 
	if(tmp!=NULL && tmp->m_State == ncMINE)
		result++;
	tmp = pGRID->m_pRecents[3]; 
	if(tmp!=NULL && tmp->m_State == ncMINE)
		result++;
	tmp = pGRID->m_pRecents[4]; 
	if(tmp!=NULL && tmp->m_State == ncMINE)
		result++;
	tmp = pGRID->m_pRecents[5]; 
	if(tmp!=NULL && tmp->m_State == ncMINE)
		result++;
	tmp = pGRID->m_pRecents[6]; 
	if(tmp!=NULL && tmp->m_State == ncMINE)
		result++;
	tmp = pGRID->m_pRecents[7]; 
	if(tmp!=NULL && tmp->m_State == ncMINE)
		result++;
	return result;
}
void CsweepmineDlg::GetShowNum(UINT n)
{
	switch(n)
	{
	case 0:
		m_Num = ncNULL;
		break;
	case 1:
		m_Num = ncONE;
		break;
	case 2:
		m_Num = ncTWO;
		break;
	case 3:
		m_Num = ncTHREE;
		break;
	case 4:
		m_Num = ncFOUR;
		break;
	case 5:
		m_Num = ncFIVE;
		break;
	case 6:
		m_Num = ncSIX;
		break;
	case 7:
		m_Num = ncSEVEN;
		break;
	case 8:
		m_Num = ncEIGHT;
		break;
	}
}
GRID* CsweepmineDlg::GetGridRect(CRect rc)
{
	for(int i=0 ; i<row-1; i++)
	{
		for(int j=0; j<col-1; j++)
		{
			if(m_GridNum[i][j].m_Rect == rc)
				return &m_GridNum[i][j];
		}
	}
	return NULL;
}
GRID* CsweepmineDlg::GetLikeGrid(CPoint point)
{
	for(int i = 0 ;i<row-1;i++)
	{
		for(int j = 0; j<col-1;j++)
		{
			if (m_GridNum[i][j].m_Rect.PtInRect(point))
				return &m_GridNum[i][j];
		}
	}
	return NULL;
}
void CsweepmineDlg::DownNullShow(GRID *pGRID)
{
	int result=0;
	for(int i=0;i<8;i++)
	{
		GRID* tmp = pGRID->m_pRecents[i];
		if(tmp != NULL)
		{
			if(tmp->m_State==ncNULL && tmp->m_IsShow != TRUE)
			{
				tmp->m_IsShow = TRUE;
				DownNullShow(tmp);
			}
			tmp->m_IsShow = TRUE;	
		}
	}
}
UINT CsweepmineDlg::IsNumber(GRIDSTATE State)
{
	switch(State)
	{
	case ncONE:
		return 1;
	case ncTWO:
		return 2;
	case ncTHREE:
		return 3;
	case ncFOUR:
		return 4;
	case ncFIVE:
		return 5;
	case ncSIX:
		return 6;
	case ncSEVEN:
		return 7;
	case ncEIGHT:
		return 8;
	default :
		return 9;
	}
}
BOOL CsweepmineDlg::IsWin()
{
	int num=0;
	for(int i=0;i<70;i++)
	{
		for(int j=0;j<70;j++)
		{
			if(m_MineRect[i] == m_FlagRect[j])
				num++;
		}
	}
	if(num == 70)
		return TRUE;
	else
		return FALSE;
}
void CsweepmineDlg::ShowAllMine()
{
	for(int i = 0 ;i<row-1;i++)
	{
		for(int j = 0; j<col-1;j++)
		{
			if(m_GridNum[i][j].m_State == ncMINE)
				m_GridNum[i][j].m_IsShow = TRUE;
		}
	}
}
void CsweepmineDlg::DblClkNum(GRID *pGRID, int n)
{
	BOOL IsWin = TRUE;
	int num = 0;
	for(int i=0;i<8;i++)
	{
		GRID* tmp = pGRID->m_pRecents[i];
		if(tmp != NULL)
		{
			for(int j=0;j<70;j++)
			{
				if(tmp->m_Rect == m_FlagRect[j])
					num++;
			}
		}
	}
	if(n == num)
	{
		for(int i=0;i<8;i++)
		{
			GRID* tmp = pGRID->m_pRecents[i];
			if(tmp != NULL)
			{
				tmp->m_IsShow = TRUE;	
				if(tmp->m_State == ncNULL)
					DownNullShow(tmp);
				if(tmp->m_State == ncMINE)
					IsWin = FALSE;
			}
		}
		Invalidate();
		if(IsWin == FALSE)
		{
			KillTimer(1);
			ShowAllMine();
			Invalidate();
			MessageBox(_T("�����ˣ�"));
			if(MessageBox(_T("�Ƿ��������Ϸ��"),_T("ϵͳ��ʾ"),MB_YESNO 
				| MB_ICONQUESTION) == IDYES)
			{
				OnBnClickedButstart();
			}
			else
				OnCancel();
		}
	}
}