// ChatSocket.cpp : ʵ���ļ�
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


// CChatSocket ��Ա����


void CChatSocket::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	TCHAR sBuf[255]={0};
	CString sRemoteIP;
	UINT nRemotePort;
	ReceiveFrom(sBuf,254*sizeof(TCHAR),sRemoteIP,nRemotePort);
	CChatdemoDlg* pDlg=(CChatdemoDlg*)AfxGetMainWnd();
	pDlg->m_edReceive.ReplaceSel(sBuf);

	CAsyncSocket::OnReceive(nErrorCode);
}
