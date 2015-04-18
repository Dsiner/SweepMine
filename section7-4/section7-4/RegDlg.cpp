// RegDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "section7-4.h"
#include "RegDlg.h"
#include "afxdialogex.h"


// CRegDlg 对话框

IMPLEMENT_DYNAMIC(CRegDlg, CDialog)

CRegDlg::CRegDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegDlg::IDD, pParent)
	, m_edUserName(_T(""))
	, m_edEmail(_T(""))
	, m_edPhone(_T(""))
{

}

CRegDlg::~CRegDlg()
{
}

void CRegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ED_USERNAME, m_edUserName);
	DDX_Text(pDX, IDC_ED_EMAIL, m_edEmail);
	DDX_Text(pDX, IDC_ED_PHONE, m_edPhone);
	DDV_MaxChars(pDX, m_edPhone, 13);
}


BEGIN_MESSAGE_MAP(CRegDlg, CDialog)
	ON_BN_CLICKED(IDCANCEL, &CRegDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT1, &CRegDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CRegDlg 消息处理程序


void CRegDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}


void CRegDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	
	CDialog::OnOK();
	
}


void CRegDlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialog::OnCancel();
	
}


void CRegDlg::PostNcDestroy()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialog::PostNcDestroy();
	
}


void CRegDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


BOOL CRegDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
