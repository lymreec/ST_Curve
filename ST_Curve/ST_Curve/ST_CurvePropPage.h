#pragma once

// ST_CurvePropPage.h : CST_CurvePropPage ����ҳ���������


// CST_CurvePropPage : �й�ʵ�ֵ���Ϣ������� ST_CurvePropPage.cpp��

class CST_CurvePropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CST_CurvePropPage)
	DECLARE_OLECREATE_EX(CST_CurvePropPage)

// ���캯��
public:
	CST_CurvePropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_ST_CURVE };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

