
// sweepmineDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

typedef enum GRIDSTATE{ 
	ncMINE,				//地雷
	ncFLAG,				//标记
	ncNULL,				//空地
	ncONE,				//数字1
	ncTWO,				//数字2
	ncTHREE,			//数字3
	ncFOUR,				//数字4
	ncFIVE,				//数字5
	ncSIX,				//数字6
	ncSEVEN,			//数字7
	ncEIGHT,			//数字8
	ncUNDOWN			//背景方块
};

//定义网格类
class GRID
{
public:
	GRIDSTATE  m_State;			//网格状态
	CRect      m_Rect;			//网格区域
	BOOL	   m_IsShow;
public:
	GRID*      m_pRecents[8];	//临近位置
	GRID()
	{
		m_State = ncUNDOWN;		//没按下
		m_IsShow = FALSE;		//显示没按下图片
	}
	~GRID()
	{ 
	}
};
// CsweepmineDlg 对话框
class CsweepmineDlg : public CDialog
{
// 构造
public:
	CsweepmineDlg(CWnd* pParent = NULL);	// 标准构造函数
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
	GRID m_GridNum[20][20];		//网格
	CRect m_FlagRect[70];		//标记位置
	CRect m_MineRect[70];		//地雷位置
	GRIDSTATE m_FlagState[70];	//标记状态
	int row,col;				//网格行列
	int x,y;					//网格起点
	int cx,cy;					//网格宽度和高度
	int m_Mine[70];					//地雷
	int m_Flag;					//标记数
	int m_MineNum;				//地雷数
	GRIDSTATE m_Num;			//数字状态
	BOOL m_IsFlag;				//是否标记
	int m_GameTime;				//游戏时间
// 对话框数据
	enum { IDD = IDD_SWEEPMINE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
