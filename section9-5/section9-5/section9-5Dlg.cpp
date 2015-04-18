
// section9-5Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "section9-5.h"
#include "section9-5Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WM_MYMSG WM_USER+1


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// Csection95Dlg 对话框



Csection95Dlg::Csection95Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Csection95Dlg::IDD, pParent)
	, m_edit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Csection95Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_button);
	DDX_Text(pDX, IDC_EDIT, m_edit);
}

BEGIN_MESSAGE_MAP(Csection95Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Csection95Dlg::OnBnClickedButton1)
	ON_MESSAGE(WM_MYMSG,OnThreadMsg)
END_MESSAGE_MAP()


// Csection95Dlg 消息处理程序

BOOL Csection95Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Csection95Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Csection95Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Csection95Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Csection95Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_MessageInfo.m_edit1=&m_edit;
	m_MessageInfo.hWnd=m_hWnd;
	CreateThread(NULL,0,ThreadProc,&m_MessageInfo,0,0);
	m_button.EnableWindow(FALSE);
	UpdateData(FALSE);
}
DWORD WINAPI Csection95Dlg::ThreadProc(LPVOID lpparam)
{
	Messageinfo* pedit=(Messageinfo*)lpparam;
	int a;
	CString str;
	HWND hwnd=pedit->hWnd;
	CString* pedit1=pedit->m_edit1;
	CTime time;
	time = CTime::GetCurrentTime();
	srand(time.GetHour()+time.GetMinute()+time.GetSecond());
	while(1)
	{
		Sleep(1000);
		a=97+rand()%26;
		str.Format(_T("%c"),a);
		*pedit1+=str;
		::SendMessage(hwnd,WM_MYMSG,0,0);
	
		
	}
	return 1;
}
LRESULT Csection95Dlg::OnThreadMsg(WPARAM wParam,LPARAM lParam)
{
	UpdateData(FALSE);
	return 0;
}