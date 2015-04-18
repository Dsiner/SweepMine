
// section9-5Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"

struct Messageinfo
{
	CString* m_edit1;
	HWND hWnd;
};

// Csection95Dlg 对话框
class Csection95Dlg : public CDialogEx
{
// 构造
public:
	Csection95Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SECTION95_DIALOG };

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
	CButton m_button;
	CString m_edit;
	static DWORD WINAPI ThreadProc(LPVOID lpparam);
	afx_msg void OnBnClickedButton1();
	afx_msg LRESULT OnThreadMsg(WPARAM wParam,LPARAM lParam);
	Messageinfo m_MessageInfo;
};
