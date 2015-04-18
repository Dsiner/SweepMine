
// ChatdemoDlg.h : ͷ�ļ�
//

#pragma once
#include "ChatSocket.h"
#include "afxwin.h"
#include "afxcmn.h"


// CChatdemoDlg �Ի���
class CChatdemoDlg : public CDialog
{
// ����
public:
	CChatdemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CHATDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	CChatSocket m_ChatSocket;
	// ���ɵ���Ϣӳ�亯��
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
