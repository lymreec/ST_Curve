// ST_CurvePropPage.cpp : CST_CurvePropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "ST_Curve.h"
#include "ST_CurvePropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CST_CurvePropPage, COlePropertyPage)



// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CST_CurvePropPage, COlePropertyPage)
END_MESSAGE_MAP()



// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CST_CurvePropPage, "STCURVE.STCurvePropPage.1",
	0xd1e97ac2, 0xde26, 0x4919, 0x87, 0xb, 0x29, 0x4d, 0xc5, 0xf3, 0xed, 0x9b)



// CST_CurvePropPage::CST_CurvePropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CST_CurvePropPage ��ϵͳע�����

BOOL CST_CurvePropPage::CST_CurvePropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_ST_CURVE_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, nullptr);
}



// CST_CurvePropPage::CST_CurvePropPage - ���캯��

CST_CurvePropPage::CST_CurvePropPage() :
	COlePropertyPage(IDD, IDS_ST_CURVE_PPG_CAPTION)
{
}



// CST_CurvePropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CST_CurvePropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CST_CurvePropPage ��Ϣ�������
