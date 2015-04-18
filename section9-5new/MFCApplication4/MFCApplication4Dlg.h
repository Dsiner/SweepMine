
// MFCApplication4Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
struct Messageinfo
{
	CString* m_edit1;
	HWND hWnd;
};


// CMFCApplication4Dlg 对话框
class CMFCApplication4Dlg : public CDialog
{
// 构造
public:
	CMFCApplication4Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };

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
	afx_msg LRESULT OnThreadMsg(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	CString m_edit;
	CButton m_start;
	Messageinfo m_MessageInfo;
	afx_msg void OnBnClickedButton1();
};
