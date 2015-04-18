
// section7-4View.h : Csection74View 类的接口
//

#pragma once


class Csection74View : public CView
{
protected: // 仅从序列化创建
	Csection74View();
	DECLARE_DYNCREATE(Csection74View)

// 特性
public:
	Csection74Doc* GetDocument() const;

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
	virtual ~Csection74View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnAppReg();
};

#ifndef _DEBUG  // section7-4View.cpp 中的调试版本
inline Csection74Doc* Csection74View::GetDocument() const
   { return reinterpret_cast<Csection74Doc*>(m_pDocument); }
#endif

