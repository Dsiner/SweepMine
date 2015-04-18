// RegDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "section7-4.h"
#include "RegDlg.h"
#include "afxdialogex.h"


// CRegDlg �Ի���

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


// CRegDlg ��Ϣ�������


void CRegDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnCancel();
}


void CRegDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	
	CDialog::OnOK();
	
}


void CRegDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���

	CDialog::OnCancel();
	
}


void CRegDlg::PostNcDestroy()
{
	// TODO: �ڴ����ר�ô����/����û���

	CDialog::PostNcDestroy();
	
}


void CRegDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


BOOL CRegDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
