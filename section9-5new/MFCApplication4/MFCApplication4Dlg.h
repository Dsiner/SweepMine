
// MFCApplication4Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
struct Messageinfo
{
	CString* m_edit1;
	HWND hWnd;
};


// CMFCApplication4Dlg �Ի���
class CMFCApplication4Dlg : public CDialog
{
// ����
public:
	CMFCApplication4Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };

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
	afx_msg LRESULT OnThreadMsg(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	CString m_edit;
	CButton m_start;
	Messageinfo m_MessageInfo;
	afx_msg void OnBnClickedButton1();
};
