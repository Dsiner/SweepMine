#pragma once


// CRegDlg 对话框

class CRegDlg : public CDialog
{
	DECLARE_DYNAMIC(CRegDlg)

public:
	CRegDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRegDlg();

// 对话框数据
	enum { IDD = IDD_REG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	virtual void OnOK();
	virtual void OnCancel();
	virtual void PostNcDestroy();
	afx_msg void OnEnChangeEdit1();
	CString m_edUserName;
	CString m_edEmail;
	CString m_edPhone;
	virtual BOOL OnInitDialog();
};
