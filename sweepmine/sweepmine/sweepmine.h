
// sweepmine.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CsweepmineApp:
// �йش����ʵ�֣������ sweepmine.cpp
//

class CsweepmineApp : public CWinApp
{
public:
	CsweepmineApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CsweepmineApp theApp;