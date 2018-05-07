
// TestST_Curve3View.h : CTestST_Curve3View ��Ľӿ�
//

#pragma once
#include "CDST_Curve.h"

class CTestST_Curve3View : public CView
{
protected: // �������л�����
	CTestST_Curve3View();
	DECLARE_DYNCREATE(CTestST_Curve3View)

// ����
public:
	CTestST_Curve3Doc* GetDocument() const;

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
	virtual ~CTestST_Curve3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CDST_Curve m_ST_Curve;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPrintcurve();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // TestST_Curve3View.cpp �еĵ��԰汾
inline CTestST_Curve3Doc* CTestST_Curve3View::GetDocument() const
   { return reinterpret_cast<CTestST_Curve3Doc*>(m_pDocument); }
#endif

