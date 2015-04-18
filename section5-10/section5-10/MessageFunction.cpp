#include <afxwin.h>
class CMyWnd:public CFrameWnd
{
public:
	CMyWnd(LPCTSTR szTitle)
	{
		Create(NULL,szTitle);
	}
	DECLARE_MESSAGE_MAP();
	afx_msg void OnClose();
};
class CMyApp:public CWinApp
{
public:
	virtual BOOL InitInstance();

};
BOOL CMyApp:: InitInstance()
{
	m_pMainWnd=new CMyWnd(_T("MFC≥Ã–Ú"));
	m_pMainWnd->ShowWindow(m_nCmdShow);
	return TRUE;
}
CMyApp myAPP;
BEGIN_MESSAGE_MAP(CMyWnd,CFrameWnd)
	ON_WM_CLOSE()
END_MESSAGE_MAP()
void CMyWnd::OnClose()
{
	AfxMessageBox(_T("–ª–ª π”√£°"));
	CFrameWnd::OnClose();
}