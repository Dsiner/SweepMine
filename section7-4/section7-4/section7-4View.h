
// section7-4View.h : Csection74View ��Ľӿ�
//

#pragma once


class Csection74View : public CView
{
protected: // �������л�����
	Csection74View();
	DECLARE_DYNCREATE(Csection74View)

// ����
public:
	Csection74Doc* GetDocument() const;

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
	virtual ~Csection74View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnAppReg();
};

#ifndef _DEBUG  // section7-4View.cpp �еĵ��԰汾
inline Csection74Doc* Csection74View::GetDocument() const
   { return reinterpret_cast<Csection74Doc*>(m_pDocument); }
#endif

