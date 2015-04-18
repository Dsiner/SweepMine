
// ChatdemoDlg.h : 头文件
//

#pragma once
#include "ChatSocket.h"
#include "afxwin.h"
#include "afxcmn.h"


// CChatdemoDlg 对话框
class CChatdemoDlg : public CDialog
{
// 构造
public:
	CChatdemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CHATDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	CChatSocket m_ChatSocket;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edReceive;
	CIPAddressCtrl m_IPAddress;
	CString m_edSend;
	afx_msg void OnBnClickedButton1();
};
