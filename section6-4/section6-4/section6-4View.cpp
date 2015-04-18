
// section6-4View.cpp : Csection64View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "section6-4.h"
#endif

#include "section6-4Doc.h"
#include "section6-4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Csection64View

IMPLEMENT_DYNCREATE(Csection64View, CView)

BEGIN_MESSAGE_MAP(Csection64View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_OP_SHOW, &Csection64View::OnOpShow)
//	ON_WM_RBUTTONUP()
//ON_WM_RBUTTONUP()
//ON_WM_NCMOUSELEAVE()
ON_WM_RBUTTONUP()
//ON_UPDATE_COMMAND_UI(ID_OP_SHOW, &Csection64View::OnUpdateOpShow)
//ON_UPDATE_COMMAND_UI(ID_OP_SHOW, &Csection64View::OnUpdateOpShow)
//ON_WM_TIMER()
//ON_WM_TIMER()
ON_COMMAND(ID_STUDENT_1, &Csection64View::OnStudent1)
ON_COMMAND(ID_STUDENT_2, &Csection64View::OnStudent2)
END_MESSAGE_MAP()

// Csection64View 构造/析构

Csection64View::Csection64View()
{
	// TODO: 在此处添加构造代码

}

Csection64View::~Csection64View()
{
}

BOOL Csection64View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Csection64View 绘制

void Csection64View::OnDraw(CDC* /*pDC*/)
{
	Csection64Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Csection64View 打印

BOOL Csection64View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Csection64View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Csection64View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Csection64View 诊断

#ifdef _DEBUG
void Csection64View::AssertValid() const
{
	CView::AssertValid();
}

void Csection64View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Csection64Doc* Csection64View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Csection64Doc)));
	return (Csection64Doc*)m_pDocument;
}
#endif //_DEBUG


// Csection64View 消息处理程序


void Csection64View::OnOpShow()
{
	// TODO: 在此添加命令处理程序代码

	CDC* pDC=GetDC();
	CString strText=_T("hello SDI");
	pDC->TextOut(100,100,strText);
	ReleaseDC(pDC);
	
}


//void Csection64View::OnRButtonUp(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	CMenu menu;
//	
//
//	CView::OnRButtonUp(nFlags, point);
//}


//void Csection64View::OnRButtonUp(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	CMenu menu;
//	menu.LoadMenuW(IDR_MY
//
//	CView::OnRButtonUp(nFlags, point);
//}


//void Csection64View::OnNcMouseLeave()
//{
//	// 该功能要求使用 Windows 2000 或更高版本。
//	// 符号 _WIN32_WINNT 和 WINVER 必须 >= 0x0500。
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//
//	CView::OnNcMouseLeave();
//}


void Csection64View::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMenu menu;
	menu.LoadMenu(IDR_MYPOP_MENU);
	CMenu* pMenu=menu.GetSubMenu(0);
	ClientToScreen(&point);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,this);


	CView::OnRButtonUp(nFlags, point);
}


//void Csection64View::OnUpdateOpShow(CCmdUI *pCmdUI)
//{
//	// TODO: 在此添加命令更新用户界面处理程序代码
//	pCmdUI->SetCheck(m_nShowed);
//}


//void Csection64View::OnUpdateOpShow(CCmdUI *pCmdUI)
//{
//	// TODO: 在此添加命令更新用户界面处理程序代码
//	
//	
//}


//void Csection64View::OnTimer(UINT_PTR nIDEvent)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	CTime t;
//	t=CTime::GetLocalTm();
//
//	CView::OnTimer(nIDEvent);
//}


//void Csection64View::OnTimer(UINT_PTR nIDEvent)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	CString s;
//	s=CTime::GetTime.Format(_T"
//
//	CView::OnTimer(nIDEvent);
//}


void Csection64View::OnStudent1()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC=GetDC();
	CString strText=_T("姓名：李白");
	pDC->TextOut(100,100,strText);
	strText=_T("学好：20121234");
	pDC->TextOut(100,150,strText);
	ReleaseDC(pDC);
	
}


void Csection64View::OnStudent2()
{
	// TODO: 在此添加命令处理程序代码
	
	CDC* pDC=GetDC();
	CString strText1=_T("                               ");
	pDC->TextOut(100,100,strText1);
	strText1=_T("                                       ");
	pDC->TextOut(100,150,strText1);
	
	CString strText=_T("姓名：g");
	pDC->TextOut(100,100,strText);
	strText=_T("学好：52");
	pDC->TextOut(100,150,strText);
	ReleaseDC(pDC);
}
