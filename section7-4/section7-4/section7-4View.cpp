
// section7-4View.cpp : Csection74View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_COMMAND(ID_APP_REG, &Csection74View::OnAppReg)
//ON_COMMAND(ID_APP_REG, &Csection74View::OnAppReg)
ON_COMMAND(ID_APP_REG, &Csection74View::OnAppReg)
END_MESSAGE_MAP()

// Csection74View ����/����

Csection74View::Csection74View()
{
	// TODO: �ڴ˴���ӹ������

}

Csection74View::~Csection74View()
{
}

BOOL Csection74View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Csection74View ����

void Csection74View::OnDraw(CDC* /*pDC*/)
{
	Csection74Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Csection74View ��ӡ

BOOL Csection74View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Csection74View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Csection74View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Csection74View ���

#ifdef _DEBUG
void Csection74View::AssertValid() const
{
	CView::AssertValid();
}

void Csection74View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Csection74Doc* Csection74View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Csection74Doc)));
	return (Csection74Doc*)m_pDocument;
}
#endif //_DEBUG


// Csection74View ��Ϣ�������


void Csection74View::OnAppReg()
{
	// TODO: �ڴ���������������
	CRegDlg dlg;
	
	if(dlg.DoModal()==IDOK)
	
		if(dlg.m_edUserName==_T("Ҧ����")&&dlg.m_edEmail==_T("yaodongfeng@163.com")&&dlg.m_edPhone==_T("130789671125"))
		    AfxMessageBox(_T("��¼�ɹ���"));
		else
			AfxMessageBox(_T("��¼ʧ�ܣ�"));



	
}