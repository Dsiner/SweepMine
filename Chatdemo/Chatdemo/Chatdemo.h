
// Chatdemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CChatdemoApp:
// �йش����ʵ�֣������ Chatdemo.cpp
//

class CChatdemoApp : public CWinApp
{
public:
	CChatdemoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CChatdemoApp theApp;