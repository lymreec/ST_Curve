
// TestST_Curve.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestST_CurveApp:
// �йش����ʵ�֣������ TestST_Curve.cpp
//

class CTestST_CurveApp : public CWinApp
{
public:
	CTestST_CurveApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestST_CurveApp theApp;