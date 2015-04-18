// ChatSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "Chatdemo.h"
#include "ChatSocket.h"
#include "ChatdemoDlg.h"

// CChatSocket

CChatSocket::CChatSocket()
{
}

CChatSocket::~CChatSocket()
{
}


// CChatSocket 成员函数


void CChatSocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	TCHAR sBuf[255]={0};
	CString sRemoteIP;
	UINT nRemotePort;
	ReceiveFrom(sBuf,254*sizeof(TCHAR),sRemoteIP,nRemotePort);
	CChatdemoDlg* pDlg=(CChatdemoDlg*)AfxGetMainWnd();
	pDlg->m_edReceive.ReplaceSel(sBuf);

	CAsyncSocket::OnReceive(nErrorCode);
}
