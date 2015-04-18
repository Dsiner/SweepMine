
// section7-4.h : section7-4 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// Csection74App:
// 有关此类的实现，请参阅 section7-4.cpp
//

class Csection74App : public CWinAppEx
{
public:
	Csection74App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Csection74App theApp;
