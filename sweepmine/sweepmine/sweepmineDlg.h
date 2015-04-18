
// sweepmineDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

typedef enum GRIDSTATE{ 
	ncMINE,				//����
	ncFLAG,				//���
	ncNULL,				//�յ�
	ncONE,				//����1
	ncTWO,				//����2
	ncTHREE,			//����3
	ncFOUR,				//����4
	ncFIVE,				//����5
	ncSIX,				//����6
	ncSEVEN,			//����7
	ncEIGHT,			//����8
	ncUNDOWN			//��������
};

//����������
class GRID
{
public:
	GRIDSTATE  m_State;			//����״̬
	CRect      m_Rect;			//��������
	BOOL	   m_IsShow;
public:
	GRID*      m_pRecents[8];	//�ٽ�λ��
	GRID()
	{
		m_State = ncUNDOWN;		//û����
		m_IsShow = FALSE;		//��ʾû����ͼƬ
	}
	~GRID()
	{ 
	}
};
// CsweepmineDlg �Ի���
class CsweepmineDlg : public CDialog
{
// ����
public:
	CsweepmineDlg(CWnd* pParent = NULL);	// ��׼���캯��
	void ShowAllMine();
	BOOL IsWin();
	void DblClkNum(GRID* pGRID, int n);
	UINT IsNumber(GRIDSTATE State);
	void DownNullShow(GRID* pGRID);
	void GetShowNum(UINT n);
	GRID* GetLikeGrid(CPoint point);
	UINT CountNumber(GRID *pGRID);
	void SetGridState();
	void SetRandMine();
	void SetRecentGrid(GRID *pGrid);
	GRID* GetGridRect(CRect rc);
	void InitializeGrid();
	GRID m_GridNum[20][20];		//����
	CRect m_FlagRect[70];		//���λ��
	CRect m_MineRect[70];		//����λ��
	GRIDSTATE m_FlagState[70];	//���״̬
	int row,col;				//��������
	int x,y;					//�������
	int cx,cy;					//�����Ⱥ͸߶�
	int m_Mine[70];					//����
	int m_Flag;					//�����
	int m_MineNum;				//������
	GRIDSTATE m_Num;			//����״̬
	BOOL m_IsFlag;				//�Ƿ���
	int m_GameTime;				//��Ϸʱ��
// �Ի�������
	enum { IDD = IDD_SWEEPMINE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CStatic m_Number;
	CStatic m_Time;
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButstart();
};
