
// section9-5Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

struct Messageinfo
{
	CString* m_edit1;
	HWND hWnd;
};

// Csection95Dlg �Ի���
class Csection95Dlg : public CDialogEx
{
// ����
public:
	Csection95Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SECTION95_DIALOG };

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
	DECLARE_MESSAGE_MAP()
public:
	CButton m_button;
	CString m_edit;
	static DWORD WINAPI ThreadProc(LPVOID lpparam);
	afx_msg void OnBnClickedButton1();
	afx_msg LRESULT OnThreadMsg(WPARAM wParam,LPARAM lParam);
	Messageinfo m_MessageInfo;
};
