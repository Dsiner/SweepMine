
// section6-4View.h : Csection64View ��Ľӿ�
//

#pragma once


class Csection64View : public CView
{
protected: // �������л�����
	Csection64View();
	DECLARE_DYNCREATE(Csection64View)
	

// ����
public:
	Csection64Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Csection64View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOpShow();
//	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnNcMouseLeave();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnUpdateOpShow(CCmdUI *pCmdUI);
//	afx_msg void OnUpdateOpShow(CCmdUI *pCmdUI);
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnStudent1();
	afx_msg void OnStudent2();
};

#ifndef _DEBUG  // section6-4View.cpp �еĵ��԰汾
inline Csection64Doc* Csection64View::GetDocument() const
   { return reinterpret_cast<Csection64Doc*>(m_pDocument); }
#endif

