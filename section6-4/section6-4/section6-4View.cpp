
// section6-4View.cpp : Csection64View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// Csection64View ����/����

Csection64View::Csection64View()
{
	// TODO: �ڴ˴���ӹ������

}

Csection64View::~Csection64View()
{
}

BOOL Csection64View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Csection64View ����

void Csection64View::OnDraw(CDC* /*pDC*/)
{
	Csection64Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Csection64View ��ӡ

BOOL Csection64View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Csection64View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Csection64View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Csection64View ���

#ifdef _DEBUG
void Csection64View::AssertValid() const
{
	CView::AssertValid();
}

void Csection64View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Csection64Doc* Csection64View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Csection64Doc)));
	return (Csection64Doc*)m_pDocument;
}
#endif //_DEBUG


// Csection64View ��Ϣ�������


void Csection64View::OnOpShow()
{
	// TODO: �ڴ���������������

	CDC* pDC=GetDC();
	CString strText=_T("hello SDI");
	pDC->TextOut(100,100,strText);
	ReleaseDC(pDC);
	
}


//void Csection64View::OnRButtonUp(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	CMenu menu;
//	
//
//	CView::OnRButtonUp(nFlags, point);
//}


//void Csection64View::OnRButtonUp(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	CMenu menu;
//	menu.LoadMenuW(IDR_MY
//
//	CView::OnRButtonUp(nFlags, point);
//}


//void Csection64View::OnNcMouseLeave()
//{
//	// �ù���Ҫ��ʹ�� Windows 2000 ����߰汾��
//	// ���� _WIN32_WINNT �� WINVER ���� >= 0x0500��
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//
//	CView::OnNcMouseLeave();
//}


void Csection64View::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMenu menu;
	menu.LoadMenu(IDR_MYPOP_MENU);
	CMenu* pMenu=menu.GetSubMenu(0);
	ClientToScreen(&point);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,this);


	CView::OnRButtonUp(nFlags, point);
}


//void Csection64View::OnUpdateOpShow(CCmdUI *pCmdUI)
//{
//	// TODO: �ڴ������������û����洦��������
//	pCmdUI->SetCheck(m_nShowed);
//}


//void Csection64View::OnUpdateOpShow(CCmdUI *pCmdUI)
//{
//	// TODO: �ڴ������������û����洦��������
//	
//	
//}


//void Csection64View::OnTimer(UINT_PTR nIDEvent)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	CTime t;
//	t=CTime::GetLocalTm();
//
//	CView::OnTimer(nIDEvent);
//}


//void Csection64View::OnTimer(UINT_PTR nIDEvent)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	CString s;
//	s=CTime::GetTime.Format(_T"
//
//	CView::OnTimer(nIDEvent);
//}


void Csection64View::OnStudent1()
{
	// TODO: �ڴ���������������
	CDC* pDC=GetDC();
	CString strText=_T("���������");
	pDC->TextOut(100,100,strText);
	strText=_T("ѧ�ã�20121234");
	pDC->TextOut(100,150,strText);
	ReleaseDC(pDC);
	
}


void Csection64View::OnStudent2()
{
	// TODO: �ڴ���������������
	
	CDC* pDC=GetDC();
	CString strText1=_T("                               ");
	pDC->TextOut(100,100,strText1);
	strText1=_T("                                       ");
	pDC->TextOut(100,150,strText1);
	
	CString strText=_T("������g");
	pDC->TextOut(100,100,strText);
	strText=_T("ѧ�ã�52");
	pDC->TextOut(100,150,strText);
	ReleaseDC(pDC);
}
