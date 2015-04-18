
// section6-4View.h : Csection64View 类的接口
//

#pragma once


class Csection64View : public CView
{
protected: // 仅从序列化创建
	Csection64View();
	DECLARE_DYNCREATE(Csection64View)
	

// 特性
public:
	Csection64Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Csection64View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // section6-4View.cpp 中的调试版本
inline Csection64Doc* Csection64View::GetDocument() const
   { return reinterpret_cast<Csection64Doc*>(m_pDocument); }
#endif

