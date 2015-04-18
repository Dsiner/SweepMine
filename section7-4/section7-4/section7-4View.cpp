
// section7-4View.cpp : Csection74View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "section7-4.h"
#endif

#include "section7-4Doc.h"
#include "section7-4View.h"
#include "RegDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Csection74View

IMPLEMENT_DYNCREATE(Csection74View, CView)

BEGIN_MESSAGE_MAP(Csection74View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_COMMAND(ID_APP_REG, &Csection74View::OnAppReg)
//ON_COMMAND(ID_APP_REG, &Csection74View::OnAppReg)
ON_COMMAND(ID_APP_REG, &Csection74View::OnAppReg)
END_MESSAGE_MAP()

// Csection74View 构造/析构

Csection74View::Csection74View()
{
	// TODO: 在此处添加构造代码

}

Csection74View::~Csection74View()
{
}

BOOL Csection74View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Csection74View 绘制

void Csection74View::OnDraw(CDC* /*pDC*/)
{
	Csection74Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Csection74View 打印

BOOL Csection74View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Csection74View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Csection74View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Csection74View 诊断

#ifdef _DEBUG
void Csection74View::AssertValid() const
{
	CView::AssertValid();
}

void Csection74View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Csection74Doc* Csection74View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Csection74Doc)));
	return (Csection74Doc*)m_pDocument;
}
#endif //_DEBUG


// Csection74View 消息处理程序


void Csection74View::OnAppReg()
{
	// TODO: 在此添加命令处理程序代码
	CRegDlg dlg;
	
	if(dlg.DoModal()==IDOK)
	
		if(dlg.m_edUserName==_T("姚东风")&&dlg.m_edEmail==_T("yaodongfeng@163.com")&&dlg.m_edPhone==_T("130789671125"))
		    AfxMessageBox(_T("登录成功！"));
		else
			AfxMessageBox(_T("登录失败！"));



	
}