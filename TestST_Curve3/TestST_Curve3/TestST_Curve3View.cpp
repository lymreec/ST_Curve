
// TestST_Curve3View.cpp : CTestST_Curve3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "TestST_Curve3.h"
#endif

#include "TestST_Curve3Doc.h"
#include "TestST_Curve3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestST_Curve3View

IMPLEMENT_DYNCREATE(CTestST_Curve3View, CView)

BEGIN_MESSAGE_MAP(CTestST_Curve3View, CView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_PRINTCURVE, OnPrintcurve)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestST_Curve3View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTestST_Curve3View ����/����

CTestST_Curve3View::CTestST_Curve3View()
{
	// TODO: �ڴ˴���ӹ������

}

CTestST_Curve3View::~CTestST_Curve3View()
{
}

BOOL CTestST_Curve3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CTestST_Curve3View ����

void CTestST_Curve3View::OnDraw(CDC* /*pDC*/)
{
	CTestST_Curve3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CTestST_Curve3View ��ӡ


void CTestST_Curve3View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestST_Curve3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CTestST_Curve3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CTestST_Curve3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CTestST_Curve3View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestST_Curve3View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestST_Curve3View ���

#ifdef _DEBUG
void CTestST_Curve3View::AssertValid() const
{
	CView::AssertValid();
}

void CTestST_Curve3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestST_Curve3Doc* CTestST_Curve3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestST_Curve3Doc)));
	return (CTestST_Curve3Doc*)m_pDocument;
}
#endif //_DEBUG


// CTestST_Curve3View ��Ϣ�������
int CTestST_Curve3View::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here
	RECT rect;
	GetClientRect(&rect);
	m_ST_Curve.Create(_T("ST_Curve in view"), WS_CHILD | WS_VISIBLE, rect, this, 1000);
	m_ST_Curve.SetGridMode(m_ST_Curve.GetGridMode() + 8);

	COleDateTime Time;
	Time.ParseDateTime(_T("2007-5-8 0:0:0"));
	COleDateTimeSpan TimeSpan = 0.041666666666666666666666666666;

	m_ST_Curve.AddLegendHelper(10, _T("��һ������"), (unsigned long) RGB(255, 255, 0), PS_SOLID, 1, FALSE);
	m_ST_Curve.AddLegend(11, _T("�ڶ�������"),
		(unsigned long) RGB(255, 0, 0), PS_SOLID, 1, (unsigned long) RGB(0, 0, 255), 6/*HS_HORIZONTAL*/, 3, 1, 0xFF, FALSE);
	//ƽ�����ߣ�Hatch��䣬ע�⣬��ʽ6��GDI+����ģ���Ϊƽ������ʹ��GDI+���������Կ��ã������ƽ�����ߣ���ʹ��
	//GDI����ʱ������֧����ʽ6����ʽ6��GDI+�ж���ΪHatchStyle05Percent������ֱ��ʹ��6����ΪVC6��û���������ͷ�ļ��ģ�
	m_ST_Curve.AddLegend(12, _T("����������"), //����ʹ��AddLegendHelper��������Ϊ������3��4����������Ĭ�ϵ�
		(unsigned long) RGB(0, 255, 0), PS_SOLID, 1, 0, 255, 2, 1, 0xFF, FALSE);

	//��13������ӵ�����һ�����ߡ����ͼ���������ַ���
	//һ��
	//		m_ST_Curve.AddLegend(13, _T("��һ������"), 0, 0, 0, 0, 0, 0, 0, 1, FALSE); //Mask����1��ֻ��Address��Ч
	//����
	m_ST_Curve.AddLegendHelper(13, _T("��һ������"), (unsigned long) RGB(255, 255, 0), PS_SOLID, 1, FALSE);
	//��ΪAddLegendHelper����û��Mask������PenColor PenStyle LineWidthҪ��д�������ı���Щ��

	for (int i = 0; i < 12; i++)
	{
		if (i % 2)
		{
			m_ST_Curve.AddMainData2(11, Time, 90 + .5f * i, i < 5, 0, TRUE);
			m_ST_Curve.AddMainData2(13, Time, 89 + .7f * i, 0, 0, TRUE);
		}
		else
		{
			m_ST_Curve.AddMainData2(11, Time, 90 + .6f * i, i < 5, 0, TRUE);
			m_ST_Curve.AddMainData2(13, Time, 89 + .8f * i, 0, 0, TRUE);
		}
	
		Time += TimeSpan;
	}

	//		Time += TimeSpan * 12;
	for (int i = 0; i < 12; i++)
	{
		m_ST_Curve.AddMainData2(12, Time, 88 + .5f * i, 0, 0, TRUE);
		
		Time += TimeSpan;
	}

	m_ST_Curve.SetFillDirection(11, 0x31, TRUE); //��ʾƽ��ֵ���������

	return 0;
}

void CTestST_Curve3View::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	if (SIZE_MAXIMIZED == nType || SIZE_RESTORED == nType)
	{
		m_ST_Curve.MoveWindow(0, 0, cx, cy, TRUE);
		m_ST_Curve.SetLegendSpace(0);
	}
}

void CTestST_Curve3View::OnPrintcurve() 
{
	COleDateTime OleTime = COleDateTime::GetCurrentTime();
	CString Title, FootNote;
	Title.Format(_T("ĳС��%d�·��õ�����ͼ"), OleTime.GetMonth());
	FootNote.Format(_T("��ӡʱ�䣺%s  ����Ա������"), OleTime.Format(VAR_DATEVALUEONLY));

	m_ST_Curve.PrintCurve(12, //���һ����������ָ����ӡ�������ߣ����������12�����ߵ�ַ����������
						  .0, .0, 0, //BTime��ETime����Ч�����ӡ���ʱ�䷶Χ
						  50, 50, 50, 50,
						  Title, FootNote,
//						  0, FootNote,
						  0x11, //Flag
//						  FALSE //one curve
						  TRUE  //all curve
						  );
}
