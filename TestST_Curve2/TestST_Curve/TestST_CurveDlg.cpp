
// TestST_CurveDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestST_Curve.h"
#include "TestST_CurveDlg.h"
#include "afxdialogex.h"

#include <locale.h>
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#ifdef _DEBUG
#define ShowEvent(str) _tprintf(str _T("\r\n"))
#else
#define ShowEvent(str)
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestST_CurveDlg �Ի���



CTestST_CurveDlg::CTestST_CurveDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestST_CurveDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestST_CurveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	DDX_Control(pDX, IDC_STCURVECTRL, m_ST_Curve);
}

BEGIN_MESSAGE_MAP(CTestST_CurveDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_WM_TIMER()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	ON_BN_CLICKED(IDC_BUTTON14, OnButton14)
	ON_BN_CLICKED(IDC_BUTTON15, OnButton15)
	ON_BN_CLICKED(IDC_BUTTON16, OnButton16)
	ON_BN_CLICKED(IDC_BUTTON17, OnButton17)
	ON_BN_CLICKED(IDC_BUTTON18, OnButton18)
	ON_BN_CLICKED(IDC_BUTTON19, OnButton19)
	ON_BN_CLICKED(IDC_BUTTON20, OnButton20)
	ON_BN_CLICKED(IDC_BUTTON21, OnButton21)
	ON_BN_CLICKED(IDC_BUTTON22, OnButton22)
	ON_BN_CLICKED(IDC_BUTTON23, OnButton23)
	ON_BN_CLICKED(IDC_BUTTON24, OnButton24)
	ON_BN_CLICKED(IDC_BUTTON25, OnButton25)
	ON_BN_CLICKED(IDC_BUTTON26, OnButton26)
	ON_BN_CLICKED(IDC_BUTTON27, OnButton27)
	ON_BN_CLICKED(IDC_BUTTON28, OnButton28)
	ON_BN_CLICKED(IDC_BUTTON29, OnButton29)
	ON_BN_CLICKED(IDC_BUTTON30, OnButton30)
	ON_BN_CLICKED(IDC_BUTTON31, OnButton31)
	ON_BN_CLICKED(IDC_BUTTON32, OnButton32)
	ON_BN_CLICKED(IDC_BUTTON33, OnButton33)
	ON_BN_CLICKED(IDC_BUTTON34, OnButton34)
	ON_BN_CLICKED(IDC_BUTTON35, OnButton35)
	ON_BN_CLICKED(IDC_BUTTON36, OnButton36)
	ON_BN_CLICKED(IDC_BUTTON37, OnButton37)
	ON_BN_CLICKED(IDC_BUTTON38, OnButton38)
	ON_BN_CLICKED(IDC_BUTTON39, OnButton39)
	ON_BN_CLICKED(IDC_BUTTON40, OnButton40)
	ON_BN_CLICKED(IDC_BUTTON41, OnButton41)
	ON_BN_CLICKED(IDC_BUTTON42, OnButton42)
	ON_BN_CLICKED(IDC_BUTTON43, OnButton43)
	ON_BN_CLICKED(IDC_BUTTON44, OnButton44)
	ON_BN_CLICKED(IDC_BUTTON45, OnButton45)
	ON_BN_CLICKED(IDC_BUTTON46, OnButton46)
	ON_BN_CLICKED(IDC_BUTTON47, OnButton47)
	ON_BN_CLICKED(IDC_BUTTON48, OnButton48)
	ON_BN_CLICKED(IDC_BUTTON49, OnButton49)
	ON_BN_CLICKED(IDC_BUTTON50, OnButton50)
	ON_BN_CLICKED(IDC_BUTTON51, OnButton51)
	ON_BN_CLICKED(IDC_BUTTON52, OnButton52)
	ON_BN_CLICKED(IDC_BUTTON53, OnButton53)
	ON_BN_CLICKED(IDC_BUTTON54, OnButton54)
	ON_BN_CLICKED(IDC_BUTTON55, OnButton55)
	ON_BN_CLICKED(IDC_BUTTON56, OnButton56)
	ON_BN_CLICKED(IDC_BUTTON57, OnButton57)
	ON_BN_CLICKED(IDC_BUTTON58, OnButton58)
	ON_BN_CLICKED(IDC_BUTTON59, OnButton59)
	ON_BN_CLICKED(IDC_BUTTON60, OnButton60)
	ON_BN_CLICKED(IDC_BUTTON61, OnButton61)
	ON_BN_CLICKED(IDC_BUTTON62, OnButton62)
	ON_BN_CLICKED(IDC_BUTTON63, OnButton63)
	ON_BN_CLICKED(IDC_BUTTON64, OnButton64)
	ON_BN_CLICKED(IDC_BUTTON65, OnButton65)
	ON_BN_CLICKED(IDC_BUTTON66, OnButton66)
	ON_BN_CLICKED(IDC_BUTTON67, OnButton67)
	ON_BN_CLICKED(IDC_BUTTON68, OnButton68)
	ON_BN_CLICKED(IDC_BUTTON69, OnButton69)
	ON_BN_CLICKED(IDC_BUTTON70, OnButton70)
	ON_BN_CLICKED(IDC_BUTTON71, OnButton71)
	ON_BN_CLICKED(IDC_BUTTON72, OnButton72)
	ON_BN_CLICKED(IDC_BUTTON73, OnButton73)
	ON_BN_CLICKED(IDC_BUTTON74, OnButton74)
	ON_BN_CLICKED(IDC_BUTTON75, OnButton75)
	ON_BN_CLICKED(IDC_BUTTON76, OnButton76)
	ON_BN_CLICKED(IDC_BUTTON77, OnButton77)
	ON_BN_CLICKED(IDC_BUTTON78, OnButton78)
	ON_BN_CLICKED(IDC_BUTTON79, OnButton79)
	ON_BN_CLICKED(IDC_BUTTON80, OnButton80)
	ON_BN_CLICKED(IDC_BUTTON81, OnButton81)
	ON_BN_CLICKED(IDC_BUTTON82, OnButton82)
	ON_BN_CLICKED(IDC_BUTTON83, OnButton83)
	ON_BN_CLICKED(IDC_BUTTON84, OnButton84)
	ON_BN_CLICKED(IDC_BUTTON85, OnButton85)
	ON_BN_CLICKED(IDC_BUTTON86, OnButton86)
	ON_BN_CLICKED(IDC_BUTTON87, OnButton87)
	ON_BN_CLICKED(IDC_BUTTON88, OnButton88)
	ON_BN_CLICKED(IDC_BUTTON89, OnButton89)
	ON_BN_CLICKED(IDC_BUTTON90, OnButton90)
	ON_BN_CLICKED(IDC_BUTTON91, OnButton91)
	ON_BN_CLICKED(IDC_BUTTON92, OnButton92)
END_MESSAGE_MAP()


// CTestST_CurveDlg ��Ϣ�������
/*
LRESULT CTestST_CurveDlg::OnPageChange(WPARAM wParam, LPARAM lParam)
{
	CString str;
	str.Format(_T("%u:%u"), (ULONG) wParam, (ULONG) wParam);
	SetDlgItemText(IDC_EDIT10, str);
	return 0;
}
*/
BOOL CTestST_CurveDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
//	uMSH_MOUSEWHEEL = RegisterWindowMessage(MSH_MOUSEWHEEL);

	// TODO: Add extra initialization here
	OleTime.ParseDateTime(_T("2007-5-8 0:0:0"));
//	OleTime.ParseDateTime(_T("9999-12-30 3:0:0"));
	Time2 = Time1 = OleTime; //COleDateTime::GetCurrentTime();
	TimeSpan = 1.0 / 24; //һСʱ

//	m_ST_Curve.MoveWindow(0, 0, 1000, 380);
//	m_ST_Curve.MoveWindow(0, 0, 980, 380);
	m_ST_Curve.SetMaxLength(1000, 700);
//	m_ST_Curve.SetValueStep(1.0f);
//	m_ST_Curve.SetMSGRecWnd(SplitHandle(m_hWnd));
//	m_ST_Curve.SetPageChangeMSG(PAGECHANGE);

//	m_ST_Curve.SetBackColor(RGB(100, 100, 100));
//	m_ST_Curve.SetForeColor(RGB(0, 0, 0));
//	m_ST_Curve.EnableZoom(FALSE);
//	m_ST_Curve.EnableToolTip(FALSE);

	m_ST_Curve.SetFootNote(_T("https://github.com/youngwolf-project/ST_Curve"));
	m_ST_Curve.SetHUnit(_T("MHz")); //���ں�������ʾΪʱ�䣬���������λ��ʾ�����������ǽ��������Ϊ��ʾֵ

	m_ST_Curve.SetCurveTitle(_T("ST_Curve������"));
//	m_ST_Curve.SetTitleColor(RGB(0, 0, 255)); //����ɫ
//	m_ST_Curve.SetFootNoteColor(RGB(0, 255, 0)); //��עɫ
	m_ST_Curve.SetWaterMark(_T("ST_Curve"));

/*	//ͨ��������λͼ��HBITMAP��
	CBitmap b;
	b.LoadBitmap(nBitmap);
	m_ST_Curve.AddBitmapHandle(SplitHandle(m_ST_Curve, b.Detach()), FALSE);
*/
	HINSTANCE h = AfxGetResourceHandle();
	m_ST_Curve.SetRegister1(GetH32bit(h));
	for (int i = IDB_1; i <= IDB_12; ++i) //���ѭ�����涼Ҫʹ��ͬһ����32λ������ǰ��ͳһ����
		m_ST_Curve.AddBitmapHandle3((long) h, i, FALSE);
	m_ST_Curve.AddImageHandle(_T("xiao.png"), FALSE);

	m_ST_Curve.SetBeginTime(_T("2007-5-7 16:00:00"));
	m_ST_Curve.SetTimeSpan(1.0 / 24 / 4); //15����
	m_ST_Curve.SetBeginValue(81.0f);

//	COleDateTimeSpan span;
//	span.SetDateTimeSpan(0, 8, 0, 0);
//	m_ST_Curve.SetVisibleCoorRange(OleTime, OleTime + span, .0f, .0f, 3);
//	m_ST_Curve.SetVisibleCoorRange(.0, .0, 90.0f, 98.0f, 0xc);

	m_ST_Curve.SetSorptionRange(8);
//	m_ST_Curve.EnableAdjustZOrder(FALSE);
	m_ST_Curve.EnableHZoom(TRUE);
//	m_ST_Curve.SetMoveMode(0x87);

	//����������Զ���ʵʩ���ţ��ɲ����ʵ��
//	m_ST_Curve.LoadLuaScript(_T("ST_Curve_PlugIn.lua"), 1, 0x3C);

#ifdef _DEBUG
	m_ST_Curve.SetEventMask(0x1FFF); //���������¼�

	AllocConsole();
	FILE* stream;
	_tfreopen_s(&stream, _T("CONOUT$"), _T("w"), stdout);
#ifdef _UNICODE
	_tsetlocale(LC_ALL, _T("chs")); //unicode�����������Ҫ����ansi�汾����Ҫ
#endif
#endif

	m_Combo.SetCurSel(0);
	OnSelchangeCombo1();

	//��ݼ�����λ�㣬�ӵ�λ��Ϊ1��ʾ��������Щ��ݼ�ֻ�ܰ��鿪�����߽�ֹ��
	//���ż���-+����ȻҲ�ǿ�ݼ�����ͨ��EnableZoom�������ֹ
	//1 -F4
	//2 -F5
	//3 -F6
	//4 -F7
	//5 -home/page up/page down/end
	//6 -���·����
	//7 -���ҷ����
	//8 -����1��
	//9 -����2��
	//...
	//16-����9��
//	m_ST_Curve.SetShortcutKeyMask(0x80); //ֻ����������1��
	m_ST_Curve.SetGridMode(m_ST_Curve.GetGridMode() + 8);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTestST_CurveDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTestST_CurveDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTestST_CurveDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//static short HGraduationSize = 21;
//static short VGraduationSize = 21;
void CTestST_CurveDlg::OnButton1() //����ɫ
{
//	HGraduationSize += 5;
//	m_ST_Curve.SetGraduationSize((HGraduationSize << 16) + VGraduationSize);
//	return;

	m_ST_Curve.SetBackColor(0x80000000 | m_ST_Curve.GetBackColor());
//	m_ST_Curve.ExportMetaFile(0, 11, 1, 5, FALSE, 2);
//	m_ST_Curve.ExportImageFromPage(_T("c:\\***.bmp"), 0, 1, 100, TRUE, 1);
//	m_ST_Curve.EnableSelectCurve(FALSE);
//	m_ST_Curve.SetToolTipDelay(1000);
}

void CTestST_CurveDlg::OnButton4() 
{
//	HGraduationSize -= 5;
//	m_ST_Curve.SetGraduationSize((HGraduationSize << 16) + VGraduationSize);
//	return;

	CString str;
	str.Format(_T("%08X"), m_ST_Curve.GetBackColor());
	AfxMessageBox(str);
//	m_ST_Curve.SelectCurve(13, TRUE);
}

void CTestST_CurveDlg::OnButton2() //����ɫ
{
//	VGraduationSize += 5;
//	m_ST_Curve.SetGraduationSize((HGraduationSize << 16) + VGraduationSize);
//	return;

	m_ST_Curve.SetForeColor(0x80000000 | m_ST_Curve.GetForeColor());
//	CColorDialog dlg;
//	if (IDOK == dlg.DoModal())
//		m_ST_Curve.SetForeColor(dlg.GetColor());
}

void CTestST_CurveDlg::OnButton5() 
{
//	VGraduationSize -= 5;
//	m_ST_Curve.SetGraduationSize((HGraduationSize << 16) + VGraduationSize);
//	return;

	CString str;
	str.Format(_T("%08X"), m_ST_Curve.GetForeColor());
	AfxMessageBox(str);
}

void CTestST_CurveDlg::OnButton3() //������ɫ
{
	m_ST_Curve.SetAxisColor(0x80000000 | m_ST_Curve.GetAxisColor());
//	CColorDialog dlg;
//	if (IDOK == dlg.DoModal())
//		m_ST_Curve.SetAxisColor(dlg.GetColor());
}

void CTestST_CurveDlg::OnButton6() 
{
	CString str;
	str.Format(_T("%08X"), m_ST_Curve.GetAxisColor());
	AfxMessageBox(str);
}

void CTestST_CurveDlg::OnButton46() //����ɫ
{
	m_ST_Curve.SetGridColor(0x80000000 | m_ST_Curve.GetGridColor());
//	CColorDialog dlg;
//	if (IDOK == dlg.DoModal())
//		m_ST_Curve.SetGridColor(dlg.GetColor());
}

void CTestST_CurveDlg::OnButton47() 
{
	CString str;
	str.Format(_T("%08X"), m_ST_Curve.GetGridColor());
	AfxMessageBox(str);
}

void CTestST_CurveDlg::OnButton48() 
{
	m_ST_Curve.SetGridMode(3);
}

void CTestST_CurveDlg::OnButton49() 
{
	m_ST_Curve.SetGridMode(0);
}

void CTestST_CurveDlg::OnButton7() //���ÿ�ʼʱ��
{
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	if (!m_ST_Curve.SetBeginTime(str))
		AfxMessageBox(_T("����ʧ�ܣ�"));
}

void CTestST_CurveDlg::OnButton8() 
{
	SetDlgItemText(IDC_EDIT1, m_ST_Curve.GetBeginTime());
}

void CTestST_CurveDlg::OnButton9() //����ʱ�䲽��
{
	CString str;
	GetDlgItemText(IDC_EDIT2, str);
	USES_CONVERSION;
	const char* pstr = T2A((LPTSTR)(LPCTSTR) str);
	if (!m_ST_Curve.SetTimeSpan(atof(pstr)))
		AfxMessageBox(_T("ʱ��������ȷ��"));
}

void CTestST_CurveDlg::OnButton10() 
{
	CString str;
	str.Format(_T("%f"), m_ST_Curve.GetTimeSpan());
	SetDlgItemText(IDC_EDIT2, str);
}

void CTestST_CurveDlg::OnButton11() //���������꿪ʼֵ
{
	CString str;
	GetDlgItemText(IDC_EDIT3, str);
	USES_CONVERSION;
	const char* pstr = T2A((LPTSTR)(LPCTSTR) str);
	m_ST_Curve.SetBeginValue((float) atof(pstr));
}

void CTestST_CurveDlg::OnButton12() 
{
	CString str;
	str.Format(_T("%f"), m_ST_Curve.GetBeginValue());
	SetDlgItemText(IDC_EDIT3, str);
}

void CTestST_CurveDlg::OnButton13() //���������경��
{
	CString str;
	GetDlgItemText(IDC_EDIT4, str);
	USES_CONVERSION;
	const char* pstr = T2A((LPTSTR)(LPCTSTR) str);
	if (!m_ST_Curve.SetValueStep((float) atof(pstr)))
		AfxMessageBox(_T("�ݱ경������ȷ��"));
}

void CTestST_CurveDlg::OnButton14() 
{
	CString str;
	str.Format(_T("%f"), m_ST_Curve.GetValueStep());
	SetDlgItemText(IDC_EDIT4, str);
}

void CTestST_CurveDlg::OnButton15() 
{
	CString str;
	GetDlgItemText(IDC_EDIT5, str);
	if (!m_ST_Curve.SetUnit(str))
		AfxMessageBox(_T("��λ̫����"));
}

void CTestST_CurveDlg::OnButton16() 
{
	SetDlgItemText(IDC_EDIT5, m_ST_Curve.GetUnit());
}

void CTestST_CurveDlg::OnButton18() 
{
	int iv = GetDlgItemInt(IDC_EDIT6);
	if (!m_ST_Curve.DelLegend(iv, FALSE, TRUE))
		AfxMessageBox(_T("ɾ��ʧ�ܣ�"));
}

void CTestST_CurveDlg::OnButton19() 
{
	CString str;
	int iv = GetDlgItemInt(IDC_EDIT6);
	str = m_ST_Curve.QueryLegend(iv);
	COLORREF Color;
	if (m_ST_Curve.GetLegend(str, (long*) &Color, 0, 0, 0, 0, 0, 0))
	{
		str.Format(_T("%08X"), Color);
		AfxMessageBox(str);
	}
}

void CTestST_CurveDlg::OnTimer(UINT_PTR nIDEvent) 
{
	static float Value1 = -10000.0f;
	static float Value2 = 77.0f;
	if (100 == nIDEvent)
	{
		Value1 -= 5.0f;
		Time1 -= TimeSpan / 4;
		m_ST_Curve.AddMainData2(14, (double) Time1, Value1, 0, 1/*0x19*//*0x21*/, FALSE);
//		if (2 == m_ST_Curve.AddMainData2(14, (double) Time1, Value1, 0, 1/*0x19*/, FALSE))
//			m_ST_Curve.SetZOffset(14, 41, TRUE);
	}
	else if (101 == nIDEvent)
	{
		Value2 += 5.0f; //10.0f;
		Time2 += TimeSpan / 4;
		m_ST_Curve.AddMainData2(13, (double) Time2, Value2, 0, 1/*0x19*//*7*/, TRUE);
//		if (2 == m_ST_Curve.AddMainData2(13, (double) Time2, Value2, 0, 1/*0x19*//*7*/, TRUE))
//			m_ST_Curve.SetZOffset(13, 20, TRUE);
	}
	else if (1 == nIDEvent)
	{
		m_ST_Curve.DelRange2(0, 0, -1, TRUE, TRUE);
		KillTimer(1);
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CTestST_CurveDlg::OnButton23() //ɾ������
{
	int iv = GetDlgItemInt(IDC_EDIT8);
	m_ST_Curve.DelRange2(iv, 0, -1, FALSE, TRUE);
}

void CTestST_CurveDlg::OnButton24() 
{
	m_ST_Curve.Refresh();
//	SetTimer(1, 5000, NULL);
}

void CTestST_CurveDlg::OnButton25() 
{
	if (!m_ST_Curve.FirstPage(FALSE, TRUE))
		AfxMessageBox(_T("������ҳ��"));

//	m_ST_Curve.AddLegend(11, _T("����������"), 0, 0, 0, 0, 0, 0, 0, 1, TRUE);
//	m_ST_Curve.MoveCurveToLegend(11, _T("����������"));
	//�������д��룬Ч����ȫһ�������Կ���MoveCurveToLegend�ǳ�����

//	m_ST_Curve.ChangeLegendName(_T("��һ������"), _T("��ʮ������"));
}

void CTestST_CurveDlg::OnButton26() 
{
	if (!m_ST_Curve.GotoPage(-1, TRUE))
		AfxMessageBox(_T("������ҳ��"));
}

void CTestST_CurveDlg::OnButton27() 
{
	if (!m_ST_Curve.GotoPage(1, TRUE))
		AfxMessageBox(_T("����ĩҳ��"));
//	m_ST_Curve.GotoPage(1, FALSE);
//	m_ST_Curve.ExportBMP("c:\\123.bmp");
}

void CTestST_CurveDlg::OnButton28() 
{
	if (!m_ST_Curve.FirstPage(TRUE, TRUE))
		AfxMessageBox(_T("����ĩҳ��"));
}

void CTestST_CurveDlg::OnButton33() 
{
	int iv = GetDlgItemInt(IDC_EDIT9);
	m_ST_Curve.SetZoom(iv);
}

void CTestST_CurveDlg::OnButton34() 
{
	SetDlgItemInt(IDC_EDIT9, m_ST_Curve.GetZoom());
}

void CTestST_CurveDlg::OnButton37() 
{
	int iv = GetDlgItemInt(IDC_EDIT11);
	m_ST_Curve.SetHPrecision(iv);
	if (!m_ST_Curve.SetVPrecision(iv))
		AfxMessageBox(_T("���ȴ���"));
}

void CTestST_CurveDlg::OnButton38() 
{
	SetDlgItemInt(IDC_EDIT11, m_ST_Curve.GetVPrecision());
}

void CTestST_CurveDlg::OnButton39() 
{
	int iv = GetDlgItemInt(IDC_EDIT12);
	if (!m_ST_Curve.AddLegend(0, _T("��һ������"), 0, 0, iv, 0, 0, 0, 0, 8, TRUE))
		AfxMessageBox(_T("�ʿ����"));
}

void CTestST_CurveDlg::OnButton40() 
{
	short iv;
	if (m_ST_Curve.GetLegend(_T("��һ������"), 0, 0, &iv, 0, 0, 0, 0))
		SetDlgItemInt(IDC_EDIT12, iv);
	else
		AfxMessageBox(_T("û���ҵ���Ӧ��ͼ��"));
}

void CTestST_CurveDlg::OnButton41() 
{
//	m_ST_Curve.SetCurveIndex(11, 2);

// 	DATE Time = .0;
// 	float Value = .0f;
// 	m_ST_Curve.GetBenchmark(&Time, &Value);
// 	Time -= 1.0;
// 	Value += 1.0f;
// 	m_ST_Curve.SetBenchmark(Time, Value);
//	return;

// 	m_ST_Curve.SetFixedZoomMode('+');
// 	return;

// 	DATE Time;
// 	float Value;
// 	m_ST_Curve.GetOneFirstPos(13, &Time, &Value, FALSE);
// 	long x, y;
// 	m_ST_Curve.GetPixelPoint(Time, Value, &x, &y);
// 	m_ST_Curve.FixedZoom('-', (short) x, (short) y, FALSE); //Ҫ��֤xy�����ڻ������棬�����޷���������
// 	return;

// 	m_ST_Curve.SetCommentPosition(0);
// 	return;

	COleDateTime OleTime = COleDateTime::GetCurrentTime();
	CString Title, FootNote;
	Title.Format(_T("ĳС��%d�·��õ�����ͼ"), OleTime.GetMonth());
	FootNote.Format(_T("��ӡʱ�䣺%s  ����Ա������"), OleTime.Format(VAR_DATEVALUEONLY));

	static int nPrintTime = 0;
	m_ST_Curve.PrintCurve(12, //���һ����������ָ����ӡ�������ߣ����������12�����ߵ�ַ����������
						  .0, .0, 0, //BTime��ETime����Ч�����ӡ���ʱ�䷶Χ
						  50, 50, 50, 50,
						  Title, FootNote,
//						  0, FootNote,
						  (nPrintTime & 1) ? 0x51 : 0x11, //Flag
//						  FALSE //one curve
						  TRUE  //all curve
						  );
	++nPrintTime; //һ��������ӡ��һ��λͼ��ӡ
}

void CTestST_CurveDlg::OnButton35() //��ʱ�����
{
	COleDateTime Time = OleTime;
	Time += 5 * TimeSpan;
//	Time -= 5 * TimeSpan; //ʧ�ܵĽ�ȡ

	m_ST_Curve.DelRange(11, .0, Time, 2, FALSE, TRUE); //ֻ��ETime��Ч
}

void CTestST_CurveDlg::OnButton36() //����������
{
	/*
	CString str;
	double d;
	double f;

	m_ST_Curve.GetOneTimeRange(13, &d, &f);
	str.Format(L"%f, %f", d, f);
	AfxMessageBox(str);
	*/
	m_ST_Curve.DelRange2(11, 0, 6, FALSE, TRUE);
//	m_ST_Curve.DelRange2(13, 0, 0, FALSE, TRUE); //ʧ�ܵĽ�ȡ
}

void CTestST_CurveDlg::OnButton45() //��ʱ�����
{
	COleDateTime Time = OleTime;
	Time += 5 * TimeSpan;
//	Time += 20 * TimeSpan; //ʧ�ܵĽ�ȡ

	m_ST_Curve.DelRange(11, Time, .0, 1, FALSE, TRUE); //ֻ��BTime��Ч
}

void CTestST_CurveDlg::OnButton50() //����������
{
	m_ST_Curve.DelRange2(11, m_ST_Curve.GetCurveLength(11) - 5, -1, FALSE, TRUE);
//	m_ST_Curve.DelRange2(11, m_ST_Curve.GetCurveLength(11), -1, FALSE, TRUE); //ʧ�ܵĽ�ȡ
}

void CTestST_CurveDlg::OnButton44() //��ʱ�����
{
	COleDateTime Time1 = OleTime, Time2 = OleTime;
	Time1 += 5 * TimeSpan;
	Time2 += 7 * TimeSpan;

	double dt1 = Time1, dt2 = Time2;
	m_ST_Curve.DelRange(11, dt1, dt2, 3, FALSE, TRUE); //BTime��ETime����Ч
//	m_ST_Curve.DelRange(11, dt2, dt1, 3, FALSE, TRUE); //ʧ�ܵĽ�ȡ
}

void CTestST_CurveDlg::OnButton51() //����������
{
	m_ST_Curve.DelRange2(11, 3, 5, FALSE, TRUE);
//	m_ST_Curve.DelRange2(11, m_ST_Curve.GetDotNum(11), 5, FALSE, TRUE); //ʧ�ܵĽ�ȡ
//	m_ST_Curve.DelRange2(11, 5, -1, FALSE, TRUE); //�൱�ڱ������4�����ݣ��������÷����Է�������
}

void CTestST_CurveDlg::OnButton55() //��ʱ�����ͷ
{
	COleDateTime Time1 = OleTime, Time2 = OleTime;
	Time1 += 3 * TimeSpan;
	Time2 += 8 * TimeSpan;

	m_ST_Curve.DelRange(11, .0, Time1, 2, FALSE, TRUE); //ֻ��ETime��Ч
	m_ST_Curve.DelRange(11, Time2, .0, 1, FALSE, TRUE); //ֻ��BTime��Ч
}

void CTestST_CurveDlg::OnButton52() //����������ͷ
{
	m_ST_Curve.DelRange2(11, 0, 2, FALSE, TRUE);
	//ע�⣬�ڶ��ε��õ�ʱ�򣬵ڶ�������������ţ�ָ���ǵ�һ�ε��ú�������е����
	m_ST_Curve.DelRange2(11, 6, -1, FALSE, TRUE);
}

void CTestST_CurveDlg::OnButton53() 
{
	m_ST_Curve.TrimCoor();
}

void CTestST_CurveDlg::OnButton29() //��ȡ���̶ȼ��
{
	SetDlgItemInt(IDC_EDIT13, m_ST_Curve.GetScaleInterval() >> 8);
}

void CTestST_CurveDlg::OnButton30() 
{
	int iv = GetDlgItemInt(IDC_EDIT13);
	m_ST_Curve.SetHInterval(iv);
}

void CTestST_CurveDlg::OnButton31()//��ȡ�ݱ�̶ȼ��
{
	SetDlgItemInt(IDC_EDIT14, m_ST_Curve.GetScaleInterval() & 0xFF);
}

void CTestST_CurveDlg::OnButton32() 
{
	int iv = GetDlgItemInt(IDC_EDIT14);
	m_ST_Curve.SetVInterval(iv);
}

void CTestST_CurveDlg::OnButton20() 
{
	/*
	short nCount = m_ST_Curve.GetCurveCount();
	for (short i = 0; i < nCount; i++)
	{
		CString str;
		str.Format(L"%d", m_ST_Curve.GetCurve(i));
		AfxMessageBox(str);
	}
	*/
	/*
	short nCount = m_ST_Curve.GetLegendCount();
	for (short i = 0; i < nCount; i++)
		AfxMessageBox(m_ST_Curve.GetLegend(i));
	*/
	/*
	short nLegendCount = m_ST_Curve.GetLegendCount();
	for (short i = 0; i < nLegendCount; i++)
	{
		short nLegendAddressCount = m_ST_Curve.GetLegendAddressCount(i);
		for (short j = 0; j < nLegendAddressCount; j++)
		{
			CString str;
			str.Format(L"%d", m_ST_Curve.GetLegendAddress(i, j));
			AfxMessageBox(str);
		}
	}
	*/

	m_ST_Curve.SetFont(SplitHandle(m_ST_Curve, 0));
	/*
	CFontDialog dlg;
	if (IDOK == dlg.DoModal())
	{
		LOGFONT l;
		dlg.GetCurrentFont(&l);

		m_ST_Curve.SetHFont((long) ::CreateFontIndirect(&l));
//		CFont font;
//		font.CreateFontIndirect(&l);
//		m_ST_Curve.SetHFont((long) font.Detach());
	}
	*/
}

void CTestST_CurveDlg::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	static int n = 1;
	if (n)
		m_ST_Curve.MoveWindow(11, 11, 991, 361);
	else
		m_ST_Curve.MoveWindow(50, 50, 560, 301);
	n = !n;

	CDialogEx::OnLButtonDblClk(nFlags, point);
}

void CTestST_CurveDlg::OnRButtonDblClk(UINT nFlags, CPoint point) 
{
#ifdef _DEBUG
	_tsystem(_T("cls\r\n"));
#endif

	CDialogEx::OnRButtonDblClk(nFlags, point);
}

void CTestST_CurveDlg::OnButton54() 
{
	int iv = GetDlgItemInt(IDC_EDIT7);
	m_ST_Curve.SetLegendSpace(iv);
}

void CTestST_CurveDlg::OnButton21() 
{
	SetDlgItemInt(IDC_EDIT7, m_ST_Curve.GetLegendSpace());
}

void CTestST_CurveDlg::OnButton42() //�������ߵ�ͼƬ���ߵ��ļ�
{
	m_ST_Curve.ExportImage(0); //ͼƬ
}

void CTestST_CurveDlg::OnButton84() 
{
//	/*
	m_ST_Curve.ExportImageFromPage(0, 11, 1, -1, TRUE, 2); //ansi txt
	m_ST_Curve.ExportImageFromPage(0, 11, 1, -1, TRUE, 3); //unicode txt
	m_ST_Curve.ExportImageFromPage(0, 11, 1, -1, TRUE, 4); //unicode big endian txt
	m_ST_Curve.ExportImageFromPage(0, 11, 1, -1, TRUE, 5); //utf8 txt
	m_ST_Curve.ExportImageFromPage(0, 11, 1, -1, TRUE, 6); //binary
//	*/
}

void CTestST_CurveDlg::OnButton83() //��������
{
	m_ST_Curve.DelRange2(0, 0, -1, TRUE, TRUE);

	//����ImportFile���������pFileNameΪ�գ���Style���������ԣ������ļ����ͽ������û���ѡ��
	//ȷ�����ı��ļ����Ƕ������ļ��������ı��ļ����ֻ�����ļ�ͷ��ȷ���ı��ļ��ľ����ʽ
	long re = m_ST_Curve.ImportFile(0, 0, TRUE);

	m_ST_Curve.FirstPage(FALSE, FALSE);
}

void CTestST_CurveDlg::OnButton77() 
{
	m_ST_Curve.BatchExportImage(_T("d:\\x*"), 10);
}

void CTestST_CurveDlg::OnButton78() 
{
	m_ST_Curve.ExportImageFromPage(_T("c:\\x**y.jpg"), 13, 1, 1, FALSE, 1);
//	COleDateTime BTime, ETime;
//	BTime.ParseDateTime(_T("2007-5-8"));
//	ETime.ParseDateTime(_T("2007-5-8 10:30:00"));
//	m_ST_Curve.ExportImageFromTime(_T("c:\\x**y.jpg"), 13, BTime, ETime, 3, FALSE, 1);
}

void CTestST_CurveDlg::OnButton56() 
{
	m_ST_Curve.SetShowMode(GetDlgItemInt(IDC_EDIT15));
}

void CTestST_CurveDlg::OnButton57() 
{
	SetDlgItemInt(IDC_EDIT15, m_ST_Curve.GetShowMode());
//	m_ST_Curve.SetBottomSpace(GetDlgItemInt(IDC_EDIT15));
}

void CTestST_CurveDlg::OnButton58() 
{
	m_ST_Curve.AddLegend(0, _T("��һ������"), 0, 0, 0, 0, 0, GetDlgItemInt(IDC_EDIT16), 0, 0x40, TRUE);
}

void CTestST_CurveDlg::OnButton59() 
{
	short vi;
	m_ST_Curve.GetLegend(_T("��һ������"), 0, 0, 0, 0, 0, &vi, 0);
	SetDlgItemInt(IDC_EDIT16, vi);
}

void CTestST_CurveDlg::OnButton60() 
{
	m_ST_Curve.SetFillDirection(11, GetDlgItemInt(IDC_EDIT17), TRUE);
}

void CTestST_CurveDlg::OnButton61() 
{
	SetDlgItemInt(IDC_EDIT17, m_ST_Curve.GetFillDirection(11));
}

void CTestST_CurveDlg::OnButton62() 
{
	m_ST_Curve.SetMoveMode(GetDlgItemInt(IDC_EDIT18));
}

void CTestST_CurveDlg::OnButton63() 
{
	SetDlgItemInt(IDC_EDIT18, m_ST_Curve.GetMoveMode());
}

static short nBitmap = IDB_1;
void CTestST_CurveDlg::OnButton64() //��ӱ���λͼ
{
	if (nBitmap > IDB_10)
		nBitmap = IDB_1;
	m_ST_Curve.SetBkBitmap(nBitmap - IDB_1);
	m_ST_Curve.SetBkMode(0x80);
	m_ST_Curve.SetCanvasBkBitmap(nBitmap - IDB_1);
	m_ST_Curve.SetCanvasBkMode(1);

	nBitmap++;
}

void CTestST_CurveDlg::OnButton65() //ȡ������λͼ
{
//	m_ST_Curve.SetBkBitmap(-1);
	m_ST_Curve.SetCanvasBkBitmap(-1);
}

void CTestST_CurveDlg::OnButton66() //����λͼ��ʾģʽ
{
	m_ST_Curve.SetCanvasBkMode(GetDlgItemInt(IDC_EDIT19));
}

void CTestST_CurveDlg::OnButton67() //��ȡλͼ��ʾģʽ
{
	SetDlgItemInt(IDC_EDIT19, m_ST_Curve.GetBkMode());
}

void CTestST_CurveDlg::OnButton68() //ѡ������
{
	m_ST_Curve.SelectCurve(GetDlgItemInt(IDC_EDIT20), TRUE);
}

void CTestST_CurveDlg::OnButton71() //ȡ��ѡ��
{
	m_ST_Curve.SelectCurve(GetDlgItemInt(IDC_EDIT20), FALSE);
}

void CTestST_CurveDlg::OnButton69() //��ʾͼ��
{
	CString str;
	GetDlgItemText(IDC_EDIT21, str);
	m_ST_Curve.ShowLegend(str, TRUE);
}

void CTestST_CurveDlg::OnButton70() //����ͼ��
{
	CString str;
	GetDlgItemText(IDC_EDIT21, str);
	m_ST_Curve.ShowLegend(str, FALSE);
}

void CTestST_CurveDlg::OnButton72() //��ʾ�ڵ�
{
	m_ST_Curve.AddLegend(0, _T("��һ������"), 0, 0, 0, 0, 0, 0, 1, 0x80, TRUE);
}

void CTestST_CurveDlg::OnButton73() //���ؽڵ�
{
	m_ST_Curve.AddLegend(0, _T("��һ������"), 0, 0, 0, 0, 0, 0, 0, 0x80, TRUE);
}

void CTestST_CurveDlg::OnButton74()
{
	m_ST_Curve.TrimCurve(GetDlgItemInt(IDC_EDIT22), GetDlgItemInt(IDC_EDIT23),
		GetDlgItemInt(IDC_EDIT24), GetDlgItemInt(IDC_EDIT25), GetDlgItemInt(IDC_EDIT26), FALSE);
}

void CTestST_CurveDlg::OnButton75() //ɾ��ͼ��
{
	CString str;
	GetDlgItemText(IDC_EDIT27, str);
	m_ST_Curve.DelLegend2(str, TRUE);
//	CString s;
//	s.Format(_T("%d"), m_ST_Curve.QueryLegend4(str));
//	AfxMessageBox(s);
}

void CTestST_CurveDlg::OnButton76() //��ȡͼ��
{
	CString str;
	GetDlgItemText(IDC_EDIT27, str);
	COLORREF Color;
	if (m_ST_Curve.GetLegend(str, (long*) &Color, 0, 0, 0, 0, 0, 0))
	{
		str.Format(_T("%08X"), Color);
		AfxMessageBox(str);
	}
}

void CTestST_CurveDlg::OnButton79() 
{
	m_ST_Curve.GotoCurve(12);
}

void CTestST_CurveDlg::OnButton81() 
{
	short nCurveIndex = m_ST_Curve.GetCurveIndex(11);
	if (nCurveIndex >= 0)
	{
//		m_ST_Curve.DelRange2(11, 5, -1, FALSE, TRUE);

		long CurveLen = m_ST_Curve.GetCurveLength(11);
		for (int i = 0; i < CurveLen; ++i)
		{
			//�����ȷ����ö�ٹ����У����߲������κ��޸ģ�������λ�øı䣨�ο�SetCurveIndex��������ɾ�����
			//����ȫ���Բ���CanContinueEnum�жϣ�ע���һ������Ϊ����ö�ٵ����ߵĵ�ַ
			//������������ö��11���ߣ�����Ҳ������11����CanContinueEnum
			if (!m_ST_Curve.CanContinueEnum(11, nCurveIndex, i))
				break; //�޷��ټ���ö����
			//���ܼ���ö�ٵ�ԭ���У�
			//һ�����߲�η����˱仯����ʱ�ٴε���GetCurveIndex�õ��µ�nCurveIndex���ɽ���ö��
			//���������е㱻ɾ������i�Ѿ�������߳�������β������ʱö��Ӧ�ý���
			//ע������е㱻ɾ������i��Ȼ�������ķ�Χ֮�ڣ�����Ϊ�ǿ�ö�ٵģ���ν��һ��ɾ��һ��ö�ٵ����⣬�뿴����
			//ע����������ӵ㣬��ʱi�϶���Ȼ�������ķ�Χ֮�ڣ���ʱҲҪ���ο�����ȥ��֤��Ҫ�ظ�ö��
			//��֮һ��ԭ��ɾ����������ö�ٲ�ȫ�����ӵ��������ظ�ö��

			float value = m_ST_Curve.GetValueData(nCurveIndex, i);
			CString str;
			str.Format(_T("%s, %f"), ((COleDateTime) m_ST_Curve.GetTimeData(nCurveIndex, i)).Format(), value);
			AfxMessageBox(str);

			if (value > 92.0f) //ɾ��yֵ����92.0f�ĵ㣬ģ��һ��ö��һ��ɾ��
			{
				m_ST_Curve.DelPoint(nCurveIndex, i);
				--i; //��ǰi��λ��ɾ���ˣ�����Ĳ���������������Ҫ���������λ���Ͻ���ö��
				--CurveLen; //��Ϊɾ����һ���㣬���Ե������Ҫ��һ
			}
		}

		m_ST_Curve.Refresh();
	}
}

void CTestST_CurveDlg::OnButton82() 
{
	m_ST_Curve.SetMoveMode(0x80 | m_ST_Curve.GetMoveMode());
}

void CTestST_CurveDlg::OnButton85() 
{
	static int HelpTipState;
	++HelpTipState;
	m_ST_Curve.EnableHelpTip(HelpTipState % 2);
}

void CTestST_CurveDlg::OnButton86() 
{
	AfxMessageBox(_T("ST_Curven�ѿ�Դ�����github�����м����¡�"));
}

void CTestST_CurveDlg::ResetAll()
{
	m_ST_Curve.DelLegend(0, TRUE, FALSE);
	m_ST_Curve.DelRange2(0, 0, -1, TRUE, FALSE);
	m_ST_Curve.DelComment(0, TRUE, FALSE);
	m_ST_Curve.DelInfiniteCurve(0, TRUE, FALSE);

	m_ST_Curve.SetZLength(0);
}

//	#define PS_SOLID            0
//	#define PS_DASH             1
//	#define PS_DOT              2
//	#define PS_DASHDOT          3
//	#define PS_DASHDOTDOT       4
//	#define PS_NULL             5
//	#define PS_INSIDEFRAME      6

//	#define HS_HORIZONTAL       0       /* ----- */
//	#define HS_VERTICAL         1       /* ||||| */
//	#define HS_FDIAGONAL        2       /* \\\\\ */
//	#define HS_BDIAGONAL        3       /* ///// */
//	#define HS_CROSS            4       /* +++++ */
//	#define HS_DIAGCROSS        5       /* xxxxx */
void CTestST_CurveDlg::OnSelchangeCombo1() 
{
	ResetAll();

	COleDateTime Time = OleTime;
	switch (m_Combo.GetCurSel())
	{
	case 0: //����ͨ����ʾ��ʽ
		m_ST_Curve.AddLegendHelper(10, _T("��һ������"), (unsigned long) RGB(255, 255, 0), PS_SOLID, 1, FALSE);
//		m_ST_Curve.AddLegend(10, _T("��һ������"),
//			(unsigned long) RGB(255, 0, 0), PS_SOLID, 1, (unsigned long) RGB(0, 255, 255), 5/*HS_DIAGCROSS*/, 0, 1, 0xFF, FALSE);

//		m_ST_Curve.AddLegendHelper(11, _T("�ڶ�������"), (unsigned long) RGB(255, 0, 0), PS_SOLID, 1, FALSE);
		m_ST_Curve.AddLegend(11, _T("�ڶ�������"),
			(unsigned long) RGB(255, 0, 0), PS_SOLID, 1, (unsigned long) RGB(0, 0, 255), 6/*HS_HORIZONTAL*/, 3, 2, 0xFF, FALSE);
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

		//��ʶ��ʼ���������
		m_ST_Curve.AppendLegendEx(_T("��һ������"),
			(unsigned long) RGB(0, 255, 255), (unsigned long) RGB(255, 0, 255), (unsigned long) RGB(0, 0, 255), 7);

		for (int i = 0; i < 12; i++)
		{
			if (i % 2)
			{
				m_ST_Curve.AddMainData2(11, Time, 90 + .5f * i, i < 5, 0, TRUE);
				m_ST_Curve.AddMainData2(13, Time, 89 + .7f * i, 0, 0, TRUE);

				//m_ST_Curve.AddComment(Time, 89 + .7f * i, 4, 12, 0, 0, 0, NULL, 0, 7, 7, FALSE);
			}
			else
			{
				m_ST_Curve.AddMainData2(11, Time, 90 + .6f * i, i < 5, 0, TRUE);
				m_ST_Curve.AddMainData2(13, Time, 89 + .8f * -i, 0x100, 0, TRUE);

				//m_ST_Curve.AddComment(Time, 89 + .8f * -i, 4, 12, 0, 0, 0, NULL, 0, 7, 7, FALSE);
			}

			Time += TimeSpan;
		}

//		Time += TimeSpan * 12;
		for (int i = 0; i < 12; i++)
		{
			m_ST_Curve.AddMainData2(12, Time, 88 + .5f * i, 0, 0, TRUE);

			Time += TimeSpan;
		}

//		m_ST_Curve.SetFillDirection(10, 1, FALSE);
		m_ST_Curve.SetFillDirection(11, 0x31, TRUE); //��ʾƽ��ֵ���������
		//����11�������ڵ�ͼ��û��ָ����䣬������������ò���������

		//������12�ӵ�����11�ϣ���ʵʲô������������Ϊ����12������11û����ͬ�ĺ����꣩
//		m_ST_Curve.ArithmeticOperate(11, 12, 0, -1, '+');
/*
		//������13�������������ʮ���֮һ�ӵ�����11��
		m_ST_Curve.CloneCurve(13, 100); //100����ʱ����
		m_ST_Curve.OffSetCurve(100, .0, 1.0f / 15, '*'); //����ʱ���������������Ϊԭ����ʮ���֮һ������1.0f / 15��
		m_ST_Curve.ArithmeticOperate(11, 100, '+'); //����ʱ���߼ӵ�����11��
		m_ST_Curve.DelRange2(100, 0, -1, FALSE, TRUE); //ɾ����ʱ����
*/
		//������12���뵽11�������
//		m_ST_Curve.UniteCurve(11, m_ST_Curve.GetCurveLength(11), 12, 0, 3);
		//������12���뵽11���м�λ��
//		m_ST_Curve.UniteCurve(11, 5, 12, 0, 3);

//		m_ST_Curve.CloneCurve(11, 14); //��11Ϊ�������Ƴ���һ������14
		//ƫ��һ������14��������11��ȫ�ص���ע�⣬����ͼ������û��14���ߣ�������ʾΪ����
//		m_ST_Curve.OffSetCurve(14, 1.0 / 24 / 2, .95f, ('+' << 8) + '*'); //��������ִ�г˲������Ժ�����ִ�мӲ���
//		m_ST_Curve.OffSetCurve(14, 1.5, .0f, '*' << 8); //�Ժ�����ִ�г˲�����������ʧ�ܣ���Ϊ��������ʾΪʱ�䣬��ʾΪֵʱ���ԣ�

		//�������ע����ع���
		m_ST_Curve.AddComment((double) Time - 1.0, 92.0f, 3, 10, 0, 0, 0xFFFFFF,
			_T("����ע��\n�ڶ��ŵڶ�����\n������"), 0xFFFFFF, 20, 10, FALSE);
		m_ST_Curve.AddComment((double) Time - 1.0, 92.0f, 0, 11, 0, 0, 0xFFFFFF, //Time Valueһ������Position��ͬ������Ч��
			_T("����ע��"), 0xFFFFFF, 20, 10, FALSE);
//		m_ST_Curve.AddComment(Time - 1.0, 92.0f, 0, 10, 0, 0, 0xFFFFFF, NULL, 0xFFFFFF, 20, 10, TRUE);

		//����Ĵ���û��ʵ����Ч������Ϊ����ע�ⲻ�������ѵ�һ��ע���Position��Ϊ0������Ч����
		m_ST_Curve.SwapCommentIndex(0, 1, TRUE); //��һ��ע�⣨λͼ�Ƿۺ�ɫ�ģ������ᵽ���ϲ㣬û�����д���ʱ���������²㣩
//		m_ST_Curve.ShowComment(0, FALSE, FALSE); //����ǰ���н�����䣬�����������ص��ǵڶ���ע�⣨��ɫ�Ǹ���

		//������ʾ��������
		m_ST_Curve.AddInfiniteCurve(11, (double) Time - 1.0, .0f, (8 << 8) + 1, FALSE); //��ֱ����ֱ�ߣ��������
		m_ST_Curve.AddInfiniteCurve(12, .0, 92.0f, 0, FALSE); //ˮƽ����ֱ�ߣ������
		//ע�⣬���Ϊ����ֱ�����ӵ�����ͼ�����������õ�����ͨ���ߵ�ͼ���������ܺã���Ϊ��
		//һ������ֱ��һ����˵����ɫ��Ӧ������ͨ����������������ҲӦ�õ���Ϊ�����ͼ��
		//�������ܻ���Ч����ʧ
		//Ҫ�ﵽ���Ч�ʣ�����ֱ�ߵ�ͼ������һ���ر�����ͼ���������ԣ������AddLegend�ӿڿ�����
		//CurveMode = 0;
		//NodeMode = 0;
		//������ͼ����չ���ԣ������AppendLegendEx�ӿڿ�����
		//BeginNodeColor = 0;
		//EndNodeColor = 0;
		//SelectedNodeColor = 0;
		//NodeModeEx = 0;
		//������ͼ�����������ԣ������SetXYFormat�ӿڿ�����
		//Format = 0;
		//����AddLegend�ӿڣ����ڱ���Ҫ���ã�������Ҫָ��CurveMode��NodeMode��Ϊ0
		//����AppendLegendEx��SetXYFormat�ӿڣ��㲻��������Ĭ�Ͼ����������������Ծͼ��ˣ������ü���
		//���⻹��һ���򵥵ķ������������Ҫ���Ļ�������AddLegendHelper��ӳ�����ͼ����Ҳ���������Ҫ��
		break;
	case 1:
		//����ͨ����ʾ��ʽ
		m_ST_Curve.AddLegendHelper(10, _T("��һ������"), (unsigned long) RGB(255, 255, 0), PS_SOLID, 1, FALSE);
		//Hatch��䣬���Խڵ�
		m_ST_Curve.AddLegend(11, _T("�ڶ�������"),
			(unsigned long) RGB(255, 0, 0), PS_SOLID, 1, (unsigned long) RGB(255, 0, 0), HS_DIAGCROSS, 0, 2, 0xFF, FALSE);
		//������ʾ��Solid��䣬���ؽڵ�
		m_ST_Curve.AddLegend(12, _T("����������"),
			(unsigned long) RGB(0, 255, 0), PS_SOLID, 1, (unsigned long) RGB(0, 255, 0), 127, 1, 0, 0xFF, FALSE);

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
				m_ST_Curve.AddMainData2(11, Time, 90 + .5f * i, i < 2, 0, TRUE);
				m_ST_Curve.AddMainData2(13, Time, 89 + .7f * (i < 6 ? i : (12 - i)), 0, 0, TRUE);
			}
			else
			{
				m_ST_Curve.AddMainData2(11, Time, 90 + .6f * i, 1, 0, TRUE);
				m_ST_Curve.AddMainData2(13, Time, 89 + .8f * (i < 6 ? i : (12 - i)), 0, 0, TRUE);
			}

			Time += TimeSpan;
		}

//		Time += TimeSpan * 12;
		for (int i = 0; i < 12; i++)
		{
			m_ST_Curve.AddMainData2(12, Time, 88 + .5f * i, 0, 0, TRUE);

			Time += TimeSpan;
		}

		m_ST_Curve.SetFillDirection(11, 0x11, TRUE); //��ʾƽ��ֵ��������䣨ʹ��ǰ��ɫ��ʾ��һ��ֵ��
		m_ST_Curve.SetFillDirection(12, 0x61, TRUE); //��ʾ�ұ�ֵ��������䣨ʹ��������ɫ��û��Ч������Ϊ��Solid��䣩
		//ֻ��Hatch��Pattern���ʱ�ſ���ָ����ʾ��ɫ
		//12�������������Ƕ���2��������һ�����״ͼ�������ұߵ�ֵ��ʲô��Ҫ�����ߵ�λ�ã��ؼ����Ƶ���һ�����������ұ߸ܵĵ㣬
		//�������ǽ�Ҫ��ʾ��ֵ��������״ͼӦ����������Ϊһ�����������Ϊһ���Ļ�������ʾֵ��ʱ����������λ�õĲ�ͬ��
		//����᲻ͬ��
		break;
	case 2:
		//Hatch��䣬���ؽڵ�
		m_ST_Curve.AddLegend(10, _T("��һ������"),
			(unsigned long) RGB(255, 255, 0), PS_NULL, 1, (unsigned long) RGB(255, 255, 0), HS_VERTICAL, 0, 0, 0xFF, FALSE);
		//Solid��䣬���ؽڵ�
		m_ST_Curve.AddLegend(11, _T("�ڶ�������"),
			(unsigned long) RGB(255, 0, 0), PS_NULL, 1, (unsigned long) RGB(255, 0, 0), 127, 0, 0, 0xFF, FALSE);
		//Pattern��䣬���ؽڵ�
		m_ST_Curve.AddLegend(12, _T("����������"),
			(unsigned long) RGB(0, 255, 0), PS_NULL, 1, (unsigned long) RGB(0, 255, 0), 128, 0, 0, 0xFF, FALSE);

		//��13������ӵ�����һ�����ߡ����ͼ���������ַ���
		//һ��
//		m_ST_Curve.AddLegend(13, _T("��һ������"), 0, 0, 0, 0, 0, 0, 0, 1, FALSE); //Mask����1��ֻ��Address��Ч
		//����
		m_ST_Curve.AddLegendHelper(13, _T("��һ������"), (unsigned long) RGB(255, 255, 0), PS_NULL, 1, FALSE);
		//��ΪAddLegendHelper����û��Mask������PenColor PenStyle LineWidthҪ��д�������ı���Щ��

		//��������ò��������ã�ԭ���ǻ���Ϊ�գ����㻭�ʲ�Ϊ�գ���NodeModeΪ0���ο������AddLegend�ӿڵ��ã�
		//������Ȼ����������
		//Ҫ���ʶ��ʼ��������㣬�����ǻ��ʲ�Ϊ�գ���NodeMode��Ϊ0
		m_ST_Curve.AppendLegendEx(_T("��һ������"), (unsigned long) RGB(255, 0, 0), (unsigned long) RGB(0, 255, 0), 0, 3);
		//SelectedNodeColorδʹ�õ�����ͨ�����һ������NodeModeExָ��

		for (int i = 0; i < 3; ++i) //��������
		{
			Time = OleTime;
			Time += i * TimeSpan;
			for (int j = 0; j < 4; ++j) //����
				for (int k = 0; k < 4; ++k) //����һ�飬��һ��
				{
					if (k < 2)
						m_ST_Curve.AddMainData2(11 + i, Time, 88 + 1.0f * (i + j), !k, 0, TRUE);
					Time += TimeSpan;
				}
		}

		m_ST_Curve.SetFillDirection(13, 4, TRUE); //�������
		break;
	case 3:
		//Hatch��䣬���ؽڵ�
		m_ST_Curve.AddLegend(10, _T("��һ������"),
			(unsigned long) RGB(255, 255, 0), PS_NULL, 1, (unsigned long) RGB(255, 255, 0), HS_VERTICAL, 0, 0, 0xFF, FALSE);
		//Solid��䣬���ؽڵ�
		m_ST_Curve.AddLegend(11, _T("�ڶ�������"),
			(unsigned long) RGB(255, 0, 0), PS_NULL, 1, (unsigned long) RGB(255, 255, 255), 127, 0, 0, 0xFF, FALSE);
		//Pattern��䣬���ؽڵ�
		m_ST_Curve.AddLegend(12, _T("����������"),
			(unsigned long) RGB(0, 255, 0), PS_NULL, 1, (unsigned long) RGB(0, 255, 0), 128, 0, 0, 0xFF, FALSE);

		//��13������ӵ�����һ�����ߡ����ͼ���������ַ���
		//һ��
//		m_ST_Curve.AddLegend(13, _T("��һ������"), 0, 0, 0, 0, 0, 0, 0, 1, FALSE); //Mask����1��ֻ��Address��Ч
		//����
		m_ST_Curve.AddLegendHelper(13, _T("��һ������"), (unsigned long) RGB(255, 255, 0), PS_NULL, 1, FALSE);
		//��ΪAddLegendHelper����û��Mask������PenColor PenStyle LineWidthҪ��д�������ı���Щ��

		m_ST_Curve.AddLegend(14, _T("123"),
			(unsigned long) RGB(255, 0, 255), PS_NULL, 1, (unsigned long) RGB(255, 0, 255), 129, 0, 0, 0xFF, FALSE);

		Time = OleTime - TimeSpan;
		m_ST_Curve.AddMainData2(14, Time, 88.0f, 0, 0, TRUE);
		m_ST_Curve.AddMainData2(14, Time, 90.0f, 0, 0, TRUE);

		{
			BYTE MemData[2048];
			//����һ���㹻�ڵ��ڴ�ռ䣬��������������������ߣ�ÿ����ռ��18���ֽ�
			//�����ǣ���ַ��4��+ ʱ�䣨8��+ ֵ��4��+ State��2��
			//���ԣ����Ҫ��ȷ����������Ҫ��������ڴ棬����ͨ����������18������õ�

			LPBYTE pMemData = MemData;
			for (int i = 0; i < 3; ++i) //��������
			{
				Time = OleTime;
				Time += i * TimeSpan;

				for (int j = 0; j < 4; ++j) //����
					for (int k = 0; k < 4; ++k) //����һ�飬��һ��
					{
						if (k < 2)
						{
							*(long*) pMemData = 11 + i;
							*(double*) (pMemData + 4) = Time;
							*(float*) (pMemData + 4 + 8) = 88 + 1.0f * (i + j);
							*(short*) (pMemData + 16) = !k;

							pMemData += 18;
						}
						Time += TimeSpan;
					}
			}
			m_ST_Curve.AddMemMainData(SplitHandle(m_ST_Curve, MemData), (long) (pMemData - MemData), TRUE); //һ�������������
		}

		m_ST_Curve.SetFillDirection(11, 0x21, TRUE); //��ʾ�ڶ���ֵ���������
		m_ST_Curve.SetFillDirection(13, 4, TRUE); //�������
		m_ST_Curve.SetFillDirection(14, 0x98, TRUE); //��ʾ��һ��ֵ��������䣨ʹ��ǰ��ɫ�ķ�ɫ��
		return; //��ֹ�����FirstPage����
		break;
	case 4: //��Բ�������õ��÷�
//		m_ST_Curve.AddLegend(14, _T("123"),
//			(unsigned long) RGB(255, 0, 255), PS_NULL, 1, (unsigned long) RGB(255, 0, 255), 129, 0, 0, 0xFF, FALSE);
		m_ST_Curve.AddLegend(14, _T("123"),
			(unsigned long) RGB(255, 0, 255), PS_SOLID, 1, (unsigned long) RGB(255, 0, 255), 0xFF, 0, 0, 0xFF, FALSE);
		m_ST_Curve.AddLegend(15, _T("456"),
			(unsigned long) RGB(255, 255, 255), PS_SOLID, 1, (unsigned long) RGB(255, 255, 255), 131, 3, 0, 0xFF, FALSE);

		//������ͨ�������һ��2������
		Time = OleTime;
		Time -= 5 * TimeSpan;

		m_ST_Curve.AddMainData2(15, Time, 87.0f, 0, 0, TRUE);
		Time += TimeSpan;
		m_ST_Curve.AddMainData2(15, Time, 86.0f, 0, 0, TRUE);
		Time += TimeSpan;
		m_ST_Curve.AddMainData2(15, Time, 85.0f, 0, 0, TRUE);
		m_ST_Curve.AddMainData2(15, Time, 87.0f, 0, 0, TRUE);
		Time -= TimeSpan;
		m_ST_Curve.AddMainData2(15, Time, 86.0f, 0, 0, TRUE);
		Time -= TimeSpan;
//		m_ST_Curve.AddMainData2(15, Time - 0.01, 85.0f, 0, 0, TRUE);
		m_ST_Curve.AddMainData2(15, Time, 85.0f, 0, 0, TRUE);
		m_ST_Curve.AddMainData2(15, Time, 87.0f, 0, 0, TRUE);

		Time = OleTime;
		{
			BYTE MemData[2048];
			//��һ��Բ
			LPBYTE pMemData = MemData;
			for (int i = 0; i >= -350; i -= (i >= -180 ? 10 : 5))
			{
				*(long*) pMemData = 14;
				double h = i * 3.1415926 / 180;
				*(double*) (pMemData + 4) = (double) Time + .1 * cos(h);
				*(float*) (pMemData + 4 + 8) = 88 + 5.0f * (float) sin(h);
				*(short*) (pMemData + 16) = 0;

				pMemData += 18;
			}
			m_ST_Curve.AddMemMainData(SplitHandle(m_ST_Curve, MemData), (long) (pMemData - MemData), TRUE);
		}
		m_ST_Curve.Refresh();
		break;
	case 5: //��ʾ��άЧ��
		m_ST_Curve.SetZLength(2);
		m_ST_Curve.AddLegendHelper(10, _T("��һ������"), (unsigned long) RGB(0, 255, 0), PS_SOLID, 1, FALSE);
		m_ST_Curve.AddLegendHelper(11, _T("�ڶ�������"), (unsigned long) RGB(255, 0, 0), PS_SOLID, 1, FALSE);
		m_ST_Curve.AddLegend(12, _T("����������"), //����ʹ��AddLegendHelper��������Ϊ������3��4����������Ĭ�ϵ�
			(unsigned long) RGB(0, 0, 255), PS_SOLID, 1, 0, 255, 2, 1, 0xFF, FALSE);

		//��13������ӵ�����һ�����ߡ����ͼ���������ַ���
		//һ��
//		m_ST_Curve.AddLegend(13, _T("��һ������"), 0, 0, 0, 0, 0, 0, 0, 1, FALSE); //Mask����1��ֻ��Address��Ч
		//����
		m_ST_Curve.AddLegendHelper(13, _T("��һ������"), (unsigned long) RGB(0, 255, 0), PS_SOLID, 1, FALSE);
		//��ΪAddLegendHelper����û��Mask������PenColor PenStyle LineWidthҪ��д�������ı���Щ��

		for (int i = 0; i < 12; i++)
		{
			float Value = 90 + .5f * i;
			//������ȫ�غϵ�����
			m_ST_Curve.AddMainData2(11, Time, Value, 0, 0, TRUE);
			m_ST_Curve.AddMainData2(12, Time, Value, 0, 0, TRUE);
			m_ST_Curve.AddMainData2(13, Time, Value, 0, 0, TRUE);
			Time += TimeSpan;
		}
		m_ST_Curve.SetZOffset(13, 30, TRUE); //��Z����ƫ��13���ߣ�ƫ����1��Z�ᵥλ��
		m_ST_Curve.SetZOffset(12, 61, TRUE); //��Z��������12���ߣ�ƫ����2��Z�ᵥλ�࣬���Ա����ص��ˣ�
		//60��Ȼ�Ѿ�����2����λZ���ˣ������ڸ�����ת��������������Ȼ�ɼ�12���ߣ�������С����Ϊ61
		//ÿһ����λ��Z�ᣬ��Ļ����Ϊ29.698484809834996������������ֻ��Ҫ���������������Ϳ�������������
		break;
	}

	m_ST_Curve.FirstPage(FALSE, FALSE);
}

void CTestST_CurveDlg::OnButton43() 
{
	if (KillTimer(100) || KillTimer(101))
		return;

	ResetAll();

//	/*
	m_ST_Curve.AddLegend(13, _T("��һ������"),
		(unsigned long) RGB(255, 255, 0), PS_SOLID, 1, (unsigned long) RGB(255, 255, 0), 255, 0, 1, 0xFF, FALSE);
	m_ST_Curve.AddLegend(14, _T("123"),
		(unsigned long) RGB(0, 255, 0), PS_SOLID, 1, (unsigned long) RGB(0, 255, 0), 128, 0, 1, 0xFF, FALSE);
	m_ST_Curve.AppendLegendEx(_T("123"), (unsigned long) RGB(255, 0, 0), (unsigned long) RGB(0, 0, 255), 0, 3);
//	*/
//	m_ST_Curve.AddLegendHelper(13, _T("��һ������"), (unsigned long) RGB(255, 255, 0), PS_SOLID, 1, FALSE);
//	m_ST_Curve.AddLegendHelper(14, _T("�ڶ�������"), (unsigned long) RGB(255, 0, 0), PS_SOLID, 1, FALSE);

	m_ST_Curve.SetValueStep(20.0f);
//	m_ST_Curve.SetAutoRefresh(31, 0); //3.1 seconds
//	m_ST_Curve.SetAutoRefresh(0, 3);
//	m_ST_Curve.LimitOnePage(TRUE);
//	m_ST_Curve.SetLimitOnePageMode(1);

	SetTimer(100, 1000, NULL);
//	SetTimer(101, 1000, NULL);
}

void CTestST_CurveDlg::OnButton17() 
{
	static int ct;
	if (ct & 1)
	{
		m_ST_Curve.AddLegend(14, _T("123"),
			(unsigned long) RGB(255, 0, 255), PS_SOLID, 1, (unsigned long) RGB(255, 0, 255), 129, 0, 0, 0xA0, FALSE); //ֻ���Ļ�ˢ��ʽ�ͽڵ�ģʽ

		//�����صĵ���ʾ����
		m_ST_Curve.TrimCurve(14, 0, 1, -1, 2, FALSE);
//		m_ST_Curve.TrimCurve2(14, 0, OleTime + TimeSpan, .0, 1, 2, FALSE);
		//���ɶϵ�
		m_ST_Curve.TrimCurve(14, 1, 2, -1, 2, FALSE);
//		m_ST_Curve.TrimCurve2(14, 1, OleTime + TimeSpan + TimeSpan, .0, 1, 2, FALSE);
		m_ST_Curve.Refresh();
	}
	else
	{
		m_ST_Curve.DelLegend(0, TRUE, FALSE);
		m_ST_Curve.DelRange2(0, 0, -1, TRUE, FALSE);

		m_ST_Curve.AddLegend(14, _T("123"),
			(unsigned long) RGB(255, 0, 255), PS_SOLID, 1, (unsigned long) RGB(255, 0, 255), 255, 0, 1, 0xFF, FALSE);

		//�����������ߣ���������һЩ���ص㣬���������Ժ��Ϊ��״ͼ��ʾ
		COleDateTime Time = OleTime;
		for (int i = 0; i < 11; ++i)
		{
			m_ST_Curve.AddMainData2(14, Time, 87.0f + i / 2, i & 1 ? 2 : 0, 0, TRUE);
			Time += TimeSpan;
		}

		AfxMessageBox(_T("����ԭʼ���ߣ��ٴε���ð�ť�л�����״ͼ��ʾ��"));
	}

	++ct;
}

void CTestST_CurveDlg::OnButton22() 
{
	static int bFullScreen = 0;
	++bFullScreen;
	m_ST_Curve.EnableFullScreen(bFullScreen & 1);
	SetDlgItemText(IDC_BUTTON22, bFullScreen & 1 ? _T("ȡ��ȫ��") : _T("ȫ��"));
}

void CTestST_CurveDlg::OnButton80() //����һҳ
{
	m_ST_Curve.SetZoom(0);
	m_ST_Curve.EnableZoom(FALSE);
	m_ST_Curve.SetMoveMode(0);
	m_ST_Curve.LimitOnePage(TRUE);
}

void CTestST_CurveDlg::OnButton87() //��������
{
//	m_ST_Curve.SetZoom(0);
//	m_ST_Curve.EnableZoom(FALSE);
//	m_ST_Curve.SetMoveMode(0);
	double BeginTime, EndTime;
	float BeginValue, EndValue;
	if (m_ST_Curve.GetOneTimeRange(11, &BeginTime, &EndTime))
	{
		m_ST_Curve.GetOneValueRange(11, &BeginValue, &EndValue);
		m_ST_Curve.FixCoor(BeginTime, EndTime, BeginValue, EndValue, 2); //ֻ���ƺ��������ֵ
	}
}

void CTestST_CurveDlg::OnButton88() //ˢ����������
{
	m_ST_Curve.RefreshLimitedOrFixedCoor();
}

void CTestST_CurveDlg::OnButton89() //λ��Ԥ������
{
	static int bPreview = 1;
	++bPreview;
	m_ST_Curve.EnablePreview(bPreview & 1);
}

void CTestST_CurveDlg::OnButton90() 
{
	m_ST_Curve.SetXYFormat(_T("�ڶ�������"), GetDlgItemInt(IDC_EDIT28));
}

void CTestST_CurveDlg::OnButton91() 
{
	long re = m_ST_Curve.LoadPlugIn(_T("ST_Curve_PlugIn.dll"), 1, 3); //��XY�ᶼʹ�ò��
	if (re)
		AfxMessageBox(_T("����ST_Curve_PlugIn.dllʧ�ܣ�"));

	re = m_ST_Curve.LoadLuaScript(_T("ST_Curve_PlugIn.lua"), 1, 0x3E); //��Ӧ�����ƣ�11 1110
	//��Y��ʹ��lua��������Ḳ��ST_Curve_PlugIn.dll�����Y���ʹ�ã�
	//ͬʱ����OnInitDialog���������µ��ã�
	//m_ST_Curve.LoadLuaScript(_T("ST_Curve_PlugIn.lua"), 1, 0x3C);
	//Ϊ����0x3Cλ���ϵ���Ȼ��Ч������ʹ����0x3E = 0x3C + 2(��Y��ʹ�ò��)
	if (re)
		AfxMessageBox(_T("����ST_Curve_PlugIn.luaʧ�ܣ�"));
}

void CTestST_CurveDlg::OnButton92() 
{
	long TempBuffSize;
	long AllBuffSize;
	float UseRate;
	long Address;
	if (m_ST_Curve.GetMemInfo(&TempBuffSize, &AllBuffSize, &UseRate, &Address))
	{
		CString str;
		str.Format(_T("��ʱ�����С��POINT����%d\r\n���߻����С���㣩��%d\r\n���������ʣ�%f\r\n��С�������������ߣ�%d\r\n"),
			TempBuffSize, AllBuffSize, UseRate, Address);
		AfxMessageBox(str);
	}
}

BEGIN_EVENTSINK_MAP(CTestST_CurveDlg, CDialogEx)
    //{{AFX_EVENTSINK_MAP(CTestST_CurveDlg)
	ON_EVENT(CTestST_CurveDlg, IDC_STCURVECTRL, -605 /* MouseDown */, OnMouseDownStcurvectrl, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CTestST_CurveDlg, IDC_STCURVECTRL, -606 /* MouseMove */, OnMouseMoveStcurvectrl, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CTestST_CurveDlg, IDC_STCURVECTRL, -607 /* MouseUp */, OnMouseUpStcurvectrl, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CTestST_CurveDlg, IDC_STCURVECTRL, 1 /* PageChange */, OnPageChangeStcurvectrl, VTS_I4 VTS_I4)
	ON_EVENT(CTestST_CurveDlg, IDC_STCURVECTRL, 2 /* BeginTimeChange */, OnBeginTimeChangeStcurvectrl, VTS_DATE)
	ON_EVENT(CTestST_CurveDlg, IDC_STCURVECTRL, 3 /* BeginValueChange */, OnBeginValueChangeStcurvectrl, VTS_R4)
	ON_EVENT(CTestST_CurveDlg, IDC_STCURVECTRL, 4 /* TimeSpanChange */, OnTimeSpanChangeStcurvectrl, VTS_R8)
	ON_EVENT(CTestST_CurveDlg, IDC_STCURVECTRL, 5 /* ValueStepChange */, OnValueStepChangeStcurvectrl, VTS_R4)
	ON_EVENT(CTestST_CurveDlg, IDC_STCURVECTRL, 6 /* ZoomChange */, OnZoomChangeStcurvectrl, VTS_I2)
	ON_EVENT(CTestST_CurveDlg, IDC_STCURVECTRL, 7 /* SelectedCurveChange */, OnSelectedCurveChangeStcurvectrl, VTS_I4)
	ON_EVENT(CTestST_CurveDlg, IDC_STCURVECTRL, 8 /* LegendVisableChange */, OnLegendVisableChangeStcurvectrl, VTS_I4 VTS_I2)
	ON_EVENT(CTestST_CurveDlg, IDC_STCURVECTRL, 9 /* SorptionChange */, OnSorptionChangeStcurvectrl, VTS_I4 VTS_I4 VTS_I2)
	ON_EVENT(CTestST_CurveDlg, IDC_STCURVECTRL, 10 /* CurveStateChange */, OnCurveStateChangeStcurvectrl, VTS_I4 VTS_I2)
	ON_EVENT(CTestST_CurveDlg, IDC_STCURVECTRL, 11 /* ZoomModeChange */, OnZoomModeChangeStcurvectrl, VTS_I2)
	ON_EVENT(CTestST_CurveDlg, IDC_STCURVECTRL, 12 /* HZoomChange */, OnHZoomChangeStcurvectrl, VTS_I2)
	ON_EVENT(CTestST_CurveDlg, IDC_STCURVECTRL, 13 /* BatchExportImageChange */, OnBatchExportImageChangeStcurvectrl, VTS_I4)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CTestST_CurveDlg::OnMouseDownStcurvectrl(short Button, short Shift, long x, long y) 
{
	ShowEvent(_T("�������"));
}

void CTestST_CurveDlg::OnMouseMoveStcurvectrl(short Button, short Shift, long x, long y) 
{
	//ShowEvent(_T("����ƶ�")); //����¼�̫�࣬������������Ӱ��ۿ������¼���
}

void CTestST_CurveDlg::OnMouseUpStcurvectrl(short Button, short Shift, long x, long y) 
{
	ShowEvent(_T("�������"));

	if (2 == Button)
	{
		/*�������������޸ĵ�
		double Time;
		float Value;

		short nCurveIndex = m_ST_Curve.GetCurveIndex(13);
		m_ST_Curve.GetOneFirstPos(13, &Time, &Value, FALSE);

		//����һ��
		//��13���ߵĵ�2�����޸ģ�����Time Value State����Ч����ȻҲ���Բ�����Ч��
//		m_ST_Curve.InsertMainData2(nCurveIndex, 1, Time, Value + 2.0f, 7 << 8, 0);

		//��������
		//��13���ߵĵ�2�����ǰ������һ���㣬��ʱ������Time Value State��Ȼ����Ч����Ϊ��һ���µ�
//		m_ST_Curve.InsertMainData2(nCurveIndex, 1, Time, Value + 2.0f, 0, -1);

		//��������
		//��13���ߵĵ�2����ĺ�������һ���㣬��ʱ������Time Value State��Ȼ����Ч����Ϊ��һ���µ�
		m_ST_Curve.InsertMainData2(nCurveIndex, 1, Time, Value + 2.0f, 0, 1);

		m_ST_Curve.Refresh();
		*/

		/*��������ӵ�
		double Time;
		float Value;
		long offset = m_ST_Curve.GetZOffset(13); //����Z�����Ӱ�죬������ӵĵ㲻������������������Z���겻Ϊ0�Ļ���
		x -= (offset >> 16);
		y += (offset & 0xFFFF);
		if (m_ST_Curve.GetActualPoint(x, y, &Time, &Value)) //����ڻ�������
			m_ST_Curve.AddMainData2(13, Time, Value, 0, 1, FALSE); //�������ݣ�����ˢ��
		*/

		/*�����ɾ���㣬���������ÿ���Z�����Ӱ��
		long re = m_ST_Curve.GetPointFromScreenPoint(13, x, y, 8);
		if (-1 != re) //�������˵㣬���ҵ�����13���ߣ�����ɾ���õ�
			m_ST_Curve.DelRange2(13, re, 1, FALSE, TRUE);
		*/
	}
}

void CTestST_CurveDlg::OnPageChangeStcurvectrl(long wParam, long lParam) 
{
	CString str;
	str.Format(_T("%d:%d"), wParam, lParam);
	SetDlgItemText(IDC_EDIT10, str);
}

void CTestST_CurveDlg::OnBeginTimeChangeStcurvectrl(DATE NewTime) 
{
	ShowEvent(_T("ԭ�������ı�"));
}

void CTestST_CurveDlg::OnBeginValueChangeStcurvectrl(float NewValue) 
{
	ShowEvent(_T("ԭ��������ı�"));
}

void CTestST_CurveDlg::OnTimeSpanChangeStcurvectrl(double NewTimeSpan) 
{
	ShowEvent(_T("���������ı�"));
}

void CTestST_CurveDlg::OnValueStepChangeStcurvectrl(float NewValueStep) 
{
	ShowEvent(_T("���������ı�"));
}

void CTestST_CurveDlg::OnZoomChangeStcurvectrl(short NewZoom) 
{
	ShowEvent(_T("���Ÿı�"));
}

void CTestST_CurveDlg::OnSelectedCurveChangeStcurvectrl(long NewId) 
{
	ShowEvent(_T("ѡ�����߸ı�"));
}

void CTestST_CurveDlg::OnLegendVisableChangeStcurvectrl(long Index, short State) 
{
	ShowEvent(_T("ͼ���ɼ�״̬�ı�"));
}

void CTestST_CurveDlg::OnSorptionChangeStcurvectrl(long Id, long Index, short State) 
{
	ShowEvent(_T("������ı�"));
}

void CTestST_CurveDlg::OnCurveStateChangeStcurvectrl(long Id, short State) 
{
	ShowEvent(_T("����״̬�ı�"));
}

void CTestST_CurveDlg::OnZoomModeChangeStcurvectrl(short NewMode) 
{
	ShowEvent(_T("����ģʽ�ı�"));
}

void CTestST_CurveDlg::OnHZoomChangeStcurvectrl(short NewZoom) 
{
	ShowEvent(_T("ˮƽ���Ÿı�"));
}


void CTestST_CurveDlg::OnBatchExportImageChangeStcurvectrl(long FileNameIndex) 
{
	ShowEvent(_T("���������ı�"));
}

void CTestST_CurveDlg::OnDestroy() 
{
#ifdef _DEBUG
	FreeConsole();
#endif

	CDialogEx::OnDestroy();
}
