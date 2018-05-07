#pragma once

#include "structs.h"
#include <gdiplus.h>

#define BUDDYMSG	(WM_APP + 1)
/*
wParam	0			�����������������ͻ���
lParam	HWND		�������������ھ��
���ͷ�������������->�����ͻ���

wParam	1			ȡ��������ϵ
lParam	HWND(0)		�����ͻ������ھ��
���ͷ���˫�������������������Ϣ�������ͻ�������lParamΪ0����֮Ϊ�ͻ������ھ��

wParam	2			���õ�ǰҳ��ʼʱ��
lParam	HCOOR_TYPE*		�µĿ�ʼʱ��
���ͷ���˫��

wParam	3			����ʱ����
lParam	HCOOR_TYPE*		�µ�ʱ����
���ͷ���˫��

wParam	4			���÷Ŵ���
lParam	short		�µķŴ���
���ͷ���˫��

wParam	5			����������λ�ã����������λ�ò�ͬ����������꿪ʼʱ����ͬ����ô���߻��ǻ���һ�㲻ͬ��
lParam	short		�µ�������λ�ã���ֵ�������пͻ����ͷ���������СLeftSpace�����ֵ
���ͷ�������������->�����ͻ���

wParam	6			ѯ�ʿͻ�����LeftSpace�����ؿͻ�������СLeftSpace
lParam	0
���ͷ�������������->�����ͻ���

wParam	7			�ͻ�����������ȷ��LeftSpace�������пͻ����ͷ���������СLeftSpace�����ֵ
lParam	0
���ͷ��������ͻ���->����������

wParam	8			����ˮƽ�Ŵ���
lParam	short		�µķŴ���
*/

//#define MOVEBUDDYMSG	(WM_APP + 2) //�Ѿ�������Ӵ˹��ܣ���Ϊ���ο�������ʵ�ִ˹��ܽ����ӵ�������
/*
BOOL SetMoveBuddy(OLE_HANDLE hBuddy, short Relation, long MaxExpand); //�����ƶ�����ϵ
hBuddy���Է����ھ��HWND�����Ϊ0����ȡ���ƶ�����ϵ
Relation���ӵ�λ��
1�������ڶ�����hBuddy�ײ�������2�������ڵײ���hBuddy������������ʱ�����ڵ����š�������Ϊ�෴
3�������ڶ�����hBuddy����������4�������ڵײ���hBuddy�ײ���������ʱ�����ڵ����š�������Ϊ��ͬ
MaxExpand�����ؼ������š�����ֵ
�߶��ֽ�Ϊ�ϱ��ص�������š�����ֵ������ֵ��
�Ͷ��ֽ�Ϊ�±��ص�������š�����ֵ������ֵ��
����������ֵΪ0����������ŵ����Ĵ��ڸ߶�Ϊ0
����������ֵΪ0��������������Լ��Ĵ��ڸ߶�Ϊ0

wParam	1			���š����������ϱ���
lParam				�����ƶ�ֵ����Ϊ���ţ���Ϊ����

wParam	2			���š����������±���
lParam				�����ƶ�ֵ����Ϊ���ţ���Ϊ����
*/

//#define VMOVE		(WM_APP + 3)

#define LEFTSPACE    5  //��հף��������������߿�ľ���
//#define VSTEP        21 //��������Ļ����
//#define HSTEP        21 //��������Ļ����
//#define Hypotenuse	 29.698484809834996 //б��

#define MOVEMODE     1 //�ƶ�ģʽ
#define DRAGMODE	 2 //�϶�ģʽ
#define ZOOMIN       3 //�Ŵ�ģʽ
#define ZOOMOUT      4 //��Сģʽ

#define REPORTPAGE	 1
#define REPORTDELAY	 100

#define SHOWTOOLTIP  2
#define SHOWDELAY    100
//#define HIDETIP	 3
//#define HIDETIPF	 5000

#define BATCHEXPORTBMP 4

#define HIDEHELPTIP	 5 //�ؼ��ڿ�ʼ���е�ʱ���Զ���ʾ������������10����Զ�����
#define HIDECOPYRIGHTINFO 6 //�ؼ��ڿ�ʼ���е�ʱ����ʾ��Ȩ��Ϣ��������10����Զ����أ����ȼ���ͣ���û������
#define HIDEDELAY	 10000

#define AUTOREFRESH	 7 //��ʱ�����Զ�ˢ��

#define GETSTEP(V, ZOOM) (!(ZOOM) ? V : ((ZOOM) > 0 ? V / ((ZOOM) * .25f + 1) : V * (-(ZOOM) * .25f + 1)))

#define UPDATERECT(MASK, F) \
{ \
	if (Mask & (MASK)) \
		F(hDC); \
}

#define ERASEBKG(MASK, R, bMoveRect) \
if (Mask & (MASK)) \
{ \
	rect = R; \
	if (bMoveRect) \
		MOVERECT(rect, m_ShowMode); \
	BitBlt(hDC, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, hBackDC, rect.left, rect.top, SRCCOPY); \
	if (IsRectEmpty(&InvalidRect)) \
		InvalidRect = rect; \
	else \
		UnionRect(&InvalidRect, &InvalidRect, &rect); \
}

#define REFRESHFOCUS(F1, F2) \
{ \
	F1; \
	if (SysState & 0x100) \
	{ \
		SelectObject(hDC, GetStockObject(NULL_BRUSH)); \
		SelectObject(hDC, hAxisPen); \
		Rectangle(hDC, 0, 0, WinWidth, WinHeight); \
	} \
	else \
	{ \
		BitBlt(hDC, 0, 0, WinWidth, 1, hFrceDC, 0, 0, SRCCOPY); \
		BitBlt(hDC, WinWidth - 1, 0, 1, WinHeight, hFrceDC, WinWidth - 1, 0, SRCCOPY); \
		BitBlt(hDC, 0, 0, 1, WinHeight, hFrceDC, 0, 0, SRCCOPY); \
		BitBlt(hDC, 0, WinHeight - 1, WinWidth, 1, hFrceDC, 0, WinHeight - 1, SRCCOPY); \
	} \
	F2; \
}

#define MOVEPOINT(POINT, MASK) \
{ \
	if ((MASK) & 1) \
		POINT.x = WinWidth - POINT.x - 1; \
	if ((MASK) & 2) \
		POINT.y = WinHeight - POINT.y - 1; \
}

#define MOVERECT(RECT, MASK) \
{ \
	if ((MASK) & 1) \
	{ \
		auto Temp = RECT.right; \
		RECT.right = WinWidth - RECT.left; \
		RECT.left = WinWidth - Temp; \
	} \
	if ((MASK) & 2) \
	{ \
		auto Temp = RECT.bottom; \
		RECT.bottom = WinHeight - RECT.top; \
		RECT.top = WinHeight - Temp; \
	} \
}

#define MOVERECTLIMIT(RECT, LIMITRECT, MASK) \
{ \
	if ((MASK) & 1) \
	{ \
		auto Temp = RECT.right; \
		auto TotalWidth = LIMITRECT.left + LIMITRECT.right; \
		RECT.right = TotalWidth - RECT.left; \
		RECT.left = TotalWidth - Temp; \
	} \
	if ((MASK) & 2) \
	{ \
		auto Temp = RECT.bottom; \
		auto TotalHeight = LIMITRECT.top + LIMITRECT.bottom; \
		RECT.bottom = TotalHeight - RECT.top; \
		RECT.top = TotalHeight - Temp; \
	} \
}

#define CHANGEMOUSESTATE \
{ \
	POINT pt; \
	GetCursorPos(&pt); \
	ScreenToClient(&pt); \
	PostMessage(WM_MOUSEMOVE, 0, (pt.y << 16) + pt.x); \
	PostMessage(WM_SETCURSOR, (WPARAM) m_hWnd, HTCLIENT | WM_MOUSEMOVE); \
}

#define DELRANGE(CON1, CON2, C1, C2, C3, bUseMore, C4) \
{ \
	for (auto i = begin(MainDataListArr); i < end(MainDataListArr);) \
	{ \
		auto tempIter = i++; \
		if (bAll || Address == *tempIter) \
		{ \
			auto pDataVector = tempIter->pDataVector; \
			auto j = begin(*pDataVector); \
			if (bUseMore && 2 == tempIter->Power) \
				while (j < end(*pDataVector)) \
					if (C4) \
					{ \
						auto k = j++; \
						if (DoDelMainData(tempIter, k, j, bUpdate) & 8) \
						{ \
							i = tempIter; \
							break; \
						} \
					} \
					else \
						++j; \
			else \
			{ \
				CON1; \
				for (; j < end(*pDataVector) && (C1); ++j); \
				if (j < end(*pDataVector)) \
				{ \
					vector<MainData>::iterator k = NullDataIter; \
					if (C2) \
						k = end(*pDataVector); \
					else \
						for (CON2; k < end(*pDataVector) && (C3); ++k); \
					if (j < k && DoDelMainData(tempIter, j, k, bUpdate) & 8) \
						i = tempIter; \
				} \
			} \
		} \
	} \
}

#define CHANGE_MAP_MODE(HDC, SHOW_MODE) \
if (0 == ((SHOW_MODE) & 3)) \
{ \
	SetMapMode(HDC, MM_TEXT); \
	SetViewportOrgEx(HDC, 0, 0, nullptr); \
} \
else \
{ \
	CHANGE_PRINT_MAP_MODE(HDC, WinWidth, WinHeight, 0, 0, SHOW_MODE); \
}

#define CHANGE_PRINT_MAP_MODE(HDC, VIEW_WIDTH, VIEW_HEIGHT, XOFFSET, YOFFSET, SHOW_MODE) \
SetMapMode(HDC, MM_ANISOTROPIC); \
SetWindowExtEx(HDC, WinWidth, WinHeight, nullptr); \
switch ((SHOW_MODE) & 3) \
{ \
case 0: \
	SetViewportExtEx(HDC, VIEW_WIDTH, VIEW_HEIGHT, nullptr); \
	SetViewportOrgEx(HDC, XOFFSET, YOFFSET, nullptr); \
	break; \
case 1: \
	SetViewportExtEx(HDC, -(VIEW_WIDTH), VIEW_HEIGHT, nullptr); \
	SetViewportOrgEx(HDC, VIEW_WIDTH - 1 + XOFFSET, YOFFSET, nullptr); \
	break; \
case 2: \
	SetViewportExtEx(HDC, VIEW_WIDTH, -(VIEW_HEIGHT), nullptr); \
	SetViewportOrgEx(HDC, XOFFSET,  VIEW_HEIGHT - 1 + YOFFSET, nullptr); \
	break; \
case 3: \
	SetViewportExtEx(HDC, -(VIEW_WIDTH), -(VIEW_HEIGHT), nullptr); \
	SetViewportOrgEx(HDC, VIEW_WIDTH - 1 + XOFFSET, VIEW_HEIGHT - 1 + YOFFSET, nullptr); \
	break; \
}

//2012.8.5
//CHVIEWORG�������ʲô���ã������ú����ʲô��
/*
#define CHVIEWORG(HDC, WIDTH, HEIGHT, MASK) \
switch ((MASK) & 3) \
{ \
case 1: \
	SetViewportOrgEx(HDC, WIDTH, 0, 0); \
	break; \
case 2: \
	SetViewportOrgEx(HDC, 0, HEIGHT, 0); \
	break; \
case 3: \
	SetViewportOrgEx(HDC, WIDTH, HEIGHT, 0); \
	break; \
}
*/
#define DRAWGRID(VAR1, ROOT1, END1, STEP, VAR2, ROOT2, END2) \
{ \
	VAR1 = ROOT1; \
	auto n = 0; \
	while (VAR1 < END1) \
	{ \
		if (!(SysState & 4) || !(n % (m_hInterval + 1))) \
			for (VAR2 = ROOT2; VAR2 < (END2); VAR2 += 7) \
				SetPixelV(hDC, ix, iy, m_gridColor); \
		VAR1 += STEP; \
		++n; \
	} \
}

#define DRAWGRID2(VAR1, ROOT1, END1, STEP, VAR2, ROOT2, END2) \
{ \
	VAR1 = ROOT1; \
	auto n = (END1 - ROOT1) / STEP; \
	while (VAR1 < END1) \
	{ \
		if (!(SysState & 4) || !(n % (m_vInterval + 1))) \
			for (VAR2 = ROOT2; VAR2 < (END2); VAR2 += 7) \
				SetPixelV(hDC, ix, iy, m_gridColor); \
		VAR1 += STEP; \
		--n; \
	} \
}

#define DRAWSOLIDGRIP(VAR, ROOT, END, STEP, BEGINX, BEGINY, ENDX, ENDY) \
{ \
	VAR = ROOT; \
	auto n = 0; \
	while (VAR < END) \
	{ \
		if (!(SysState & 4) || !(n % (m_hInterval + 1))) \
		{ \
			MoveToEx(hDC, BEGINX, BEGINY, nullptr); \
			LineTo(hDC, ENDX, ENDY); \
		} \
		VAR += STEP; \
		++n; \
	} \
}

#define DRAWSOLIDGRIP2(VAR, ROOT, END, STEP, BEGINX, BEGINY, ENDX, ENDY) \
{ \
	VAR = ROOT; \
	auto n = (END - ROOT) / STEP; \
	while (VAR < END) \
	{ \
		if (!(SysState & 4) || !(n % (m_vInterval + 1))) \
		{ \
			MoveToEx(hDC, BEGINX, BEGINY, nullptr); \
			LineTo(hDC, ENDX, ENDY); \
		} \
		VAR += STEP; \
		--n; \
	} \
}

#define CHECKCOLOR(COLOR) \
{ \
	COLOR &= 0x80FFFFFF; \
	if (COLOR & 0x80000000) \
	{ \
		COLOR &= 0xFFFFFF; \
		CHOOSECOLOR cc; \
		memset(&cc, 0, sizeof(CHOOSECOLOR)); \
		cc.lStructSize = sizeof(CHOOSECOLOR); \
		cc.hwndOwner = m_hWnd; \
		cc.rgbResult = COLOR; \
		cc.lpCustColors = CustClr; \
		cc.Flags = CC_ANYCOLOR | CC_FULLOPEN | CC_RGBINIT; \
		if (ChooseColor(&cc)) \
			COLOR =cc.rgbResult; \
		else \
			return; \
	} \
}

#define DEFAULT_foreColor		RGB(0xff, 0xff, 0xff)
#define DEFAULT_backColor		RGB(0x27, 0x27, 0x27)
#define DEFAULT_axisColor		RGB(0, 0xff, 0x80)
#define DEFAULT_gridColor		RGB(0xa0, 0xa0, 0xa0)
#define DEFAULT_titleColor		RGB(0xff, 0xff, 0xff) //Ĭ��ʱ��������ɫ����ǰ��ɫ
#define DEFAULT_footNoteColor	RGB(0xbe, 0xbe, 0xbe) //Ĭ��ʱ����ע��ɫ����ǰ��ɫ��3/4
#define DEFAULT_pageChangeMSG	0L

#define OnePageLength	(CanvasRect[1].right - CanvasRect[1].left - nZLength * HSTEP)

#define GETPAGENUM(T1, T2) \
{ \
	nPageNum = 0; \
	if (nVisibleCurve > 0 && (T2) > (T1)) \
	{ \
		MainData NoUse; \
		NoUse.Time = T1; \
		CalcOriginDatumPoint(NoUse, 1); \
		auto TotalLen = -NoUse.ScrPos.x; \
		NoUse.Time = T2; \
		CalcOriginDatumPoint(NoUse, 1); \
		TotalLen += NoUse.ScrPos.x; \
		auto PageLen = OnePageLength; \
		nPageNum = TotalLen / PageLen; \
		if (TotalLen % PageLen) \
			++nPageNum; \
	} \
}

#define CHANGEONERANGE(VALUE, NEW, O, P, NP) \
if (VALUE O (NEW)) \
{ \
	VALUE = NEW; \
	P = NP; \
}

#define CHANGERANGE(MIN, MAX, NEW, P1, P2, NP) \
{ \
	CHANGEONERANGE(MIN, NEW, >, P1, NP) \
	else \
	CHANGEONERANGE(MAX, NEW, <, P2, NP) \
}

#define DOFILL1VALUE(pVALUE, VALUE) do_fill_1_value(pVALUE, VALUE)

#define DOFILL2VALUE(pVALUE1, pVALUE2, VALUE1, VALUE2) \
DOFILL1VALUE(pVALUE1, VALUE1); \
DOFILL1VALUE(pVALUE2, VALUE2)

#define DOFILL3VALUE(pVALUE1, pVALUE2, pVALUE3, VALUE1, VALUE2, VALUE3) \
DOFILL2VALUE(pVALUE1, pVALUE2, VALUE1, VALUE2); \
DOFILL1VALUE(pVALUE3, VALUE3)

#define DOFILL4VALUE(pVALUE1, pVALUE2, pVALUE3, pVALUE4, VALUE1, VALUE2, VALUE3, VALUE4) \
DOFILL2VALUE(pVALUE1, pVALUE2, VALUE1, VALUE2); \
DOFILL2VALUE(pVALUE3, pVALUE4, VALUE3, VALUE4)

#define DOFILL8VALUE(pVALUE1, pVALUE2, pVALUE3, pVALUE4, pVALUE5, pVALUE6, pVALUE7, pVALUE8, VALUE1, VALUE2, VALUE3, VALUE4, VALUE5, VALUE6, VALUE7, VALUE8) \
DOFILL4VALUE(pVALUE1, pVALUE2, pVALUE3, pVALUE4, VALUE1, VALUE2, VALUE3, VALUE4); \
DOFILL4VALUE(pVALUE5, pVALUE6, pVALUE7, pVALUE8, VALUE5, VALUE6, VALUE7, VALUE8)

#define FILL2VALUE(CON, pVALUE1, pVALUE2, VALUE1, VALUE2) \
{ \
	CON \
	{ \
		DOFILL2VALUE(pVALUE1, pVALUE2, VALUE1, VALUE2); \
		return TRUE; \
	} \
	return FALSE; \
}

#define SYNBUDDYS(wParam, lParam) \
{ \
	if (hBuddyServer) \
	{ \
		if (!(BuddyState & 1)) \
			::SendMessage(hBuddyServer, BUDDYMSG, (WPARAM) wParam, (LPARAM) lParam); \
	} \
	else if (pBuddys) \
		for (auto i = begin(*pBuddys); i < end(*pBuddys); ++i) \
			::SendMessage(*i, BUDDYMSG, (WPARAM) wParam, (LPARAM) lParam); \
}

#define CANCELBUDDYS \
{ \
	if (hBuddyServer) \
	{ \
		::SendMessage(hBuddyServer, BUDDYMSG, 1, (LPARAM) m_hWnd); \
		hBuddyServer = nullptr; \
	} \
	else if (pBuddys) \
	{ \
		for (auto i = begin(*pBuddys); i < end(*pBuddys); ++i) \
			::SendMessage(*i, BUDDYMSG, 1, 0); \
		pBuddys->clear(); \
		delete pBuddys; \
		pBuddys = nullptr; \
		CHLeftSpace(ActualLeftSpace); \
	} \
}

#define REMOVEBUDDY(hBuddy) \
{ \
	if (pBuddys) \
	{ \
		auto i = find(begin(*pBuddys), end(*pBuddys), hBuddy); \
		if (i < end(*pBuddys)) \
		{ \
			pBuddys->erase(i); \
			if (pBuddys->empty()) \
			{ \
				delete pBuddys; \
				pBuddys = nullptr; \
			} \
			auto MaxLeftSpace = GetMaxLeftSpace(ActualLeftSpace); \
			if (MaxLeftSpace < LeftSpace) \
			{ \
				BROADCASTLEFTSPACE(MaxLeftSpace); \
				CHLeftSpace(MaxLeftSpace); \
			} \
		} \
	} \
}

#define BROADCASTLEFTSPACE(NEWLEFTSPACE) \
{ \
	if (pBuddys) \
		for (auto i = begin(*pBuddys); i < end(*pBuddys); ++i) \
			::SendMessage(*i, BUDDYMSG, 5, (LPARAM) NEWLEFTSPACE); \
}

#define GETTIMEEND \
auto n = 0; \
auto pTemp = Buff + i; \
while (pTemp > pDateTime) \
{ \
	if (',' == *pTemp--) \
		++n; \
	if (2 == n) \
		break; \
} \
if (pTemp > pDateTime) \
{ \
	*++pTemp = 0;

//��Ϊ�ǰ�%c����ȡ�ַ�������Ҫ��ȥ0x30�������������ݣ���ȻҲ���Ը�Ϊ��%d����������%dҪ��int��װ
#define SCANDATA(F, S, S1, S2) \
if (!State) \
{ \
	State = 2; \
	auto pDateTime = pRowStart; \
	while (pDateTime < Buff + i && ',' != *pDateTime) \
		++pDateTime; \
	if (pDateTime < Buff + i) \
	{ \
		++pDateTime; \
		GETTIMEEND \
			for (auto i = pDateTime; i < pTemp; ++i) \
				if ('.' != *i && !_istdigit(*i)) \
				{ \
					State = 1; \
					break; \
				} \
			*pTemp = ','; \
		} \
	} \
} \
ASSERT(pBinBuff - BinBuff <= BINBUFFLEN); \
if (pBinBuff - BinBuff >= BINBUFFLEN) \
{ \
	nImportRow += iAddMemMainData(BinBuff, (long) (pBinBuff - BinBuff), bAddTrail); \
	pBinBuff = BinBuff; \
} \
if (2 == State) \
{ \
	if (4 == F(pRowStart, S, pBinBuff, pBinBuff + 4, pBinBuff + 4 + 8, pBinBuff + 4 + 8 + 4)) \
	{ \
		++nTotalRow; \
		pBinBuff += 18; \
	} \
} \
else if (1 == F(pRowStart, S1, pBinBuff)) \
{ \
	auto pDateTime = pRowStart; \
	while (pDateTime < Buff + i && ',' != *pDateTime) \
		++pDateTime; \
	if (pDateTime < Buff + i) \
	{ \
		++pDateTime; \
		GETTIMEEND \
			HCOOR_TYPE Time; \
			auto hr = VarDateFromStr(CComBSTR(pDateTime), LANG_USER_DEFAULT, 0, &Time); \
			if (SUCCEEDED(hr)) /*ǧ��Ҫ��alt���ַ���ת���꣬�������ܻ���Ϊջ���ù������������ʹ��CComBSTR�������ַ���ת��*/ \
			{ \
				*(HCOOR_TYPE*) (pBinBuff + 4) = Time; \
				++pTemp; \
				if (2 == F(pTemp, S2, pBinBuff + 4 + 8, pBinBuff + 4 + 8 + 4)) \
				{ \
					++nTotalRow; \
					pBinBuff += 18; \
				} \
			} \
		} \
	} \
}

#define WRITEFILE(PRINT, Buff, PRE, OPDT, EXT) \
{ \
	auto len = PRINT(Buff, BUFF_A_W_LEN, PRE"%d,", Address); \
	if (ShowMode & 0x80) \
		len += PRINT(Buff + len, BUFF_A_W_LEN - len, PRE"%lf,", MainDataIter->Time); \
	else if (ISHVALUEVALID(MainDataIter->Time)) \
	{ \
		BSTR bstr; \
		auto hr = VarBstrFromDate(*MainDataIter, LANG_USER_DEFAULT, 0, &bstr); \
		ASSERT(SUCCEEDED(hr)); \
		OPDT; \
		SysFreeString(bstr); \
	} \
	len += PRINT(Buff + len, BUFF_A_W_LEN - len, PRE"%f,", MainDataIter->Value); \
	len += PRINT(Buff + len, BUFF_A_W_LEN - len, PRE"%d\r\n", MainDataIter->State); \
	EXT; \
	WriteFile(hFile, Buff, len * sizeof(*Buff), &WritedLen, nullptr); \
	ASSERT(len * sizeof(*Buff) == WritedLen); \
}

#define DELETEDC(hDC) \
if (hDC) \
{ \
	DeleteDC(hDC); \
	hDC = nullptr; \
}

#define DELETEOBJECT(hOb) \
if (hOb) \
{ \
	DeleteObject(hOb); \
	hOb = nullptr; \
}

#define FILLVALUE(V, XY) \
V = 0; \
while (++nNum) \
{ \
	V += i->ScrPos.XY; \
	if (0x30 == ValueMask) \
		Value += i->Value; \
	if (i == EndPos) \
		break; \
	++i; \
} \
V /= nNum; \
if (0x30 == ValueMask) \
	Value /= nNum;

#define FILLPATH(MASK, X1, Y1, X2, Y2) \
if (MASK & DataListIter->FillDirection) \
{ \
	if (2 == DataListIter->Power || (MASK & 5 && EndDrawPos->ScrPos.x != j->ScrPos.x || MASK & 0xA && EndDrawPos->ScrPos.y != j->ScrPos.y)) \
	{ \
		if (3 == CurveMode) \
			pPath->AddCurve((Gdiplus::Point*) &points.front(), (int) points.size(), Tension); \
		if (EndDrawPos->ScrPos.x != j->ScrPos.x || EndDrawPos->ScrPos.y != j->ScrPos.y) \
			if (3 == CurveMode) \
			{ \
				Gdiplus::Point point[] = {Gdiplus::Point(points.back().x, points.back().y), Gdiplus::Point(X1, Y1), Gdiplus::Point(X2, Y2), \
					Gdiplus::Point(points.front().x, points.front().y)}; \
				pPath->AddLines(point, 4); \
			} \
			else \
			{ \
				POINT NoUse = {X1, Y1}; \
				points.push_back(NoUse); \
				NoUse.x = X2; \
				NoUse.y = Y2; \
				points.push_back(NoUse); \
			} \
		if (3 == CurveMode) \
		{ \
			UnlockGdiplus; /*��GDI+��Ч������Ҫʹ����*/\
			pGraphics->FillPath(pBrush, pPath); \
			LockGdiplus; /*�����������GDI+ʧЧ*/\
			pPath->Reset(); \
		} \
		else \
			Polygon(hDC, &points.front(), (int) points.size()); \
		if (DataListIter->FillDirection & 0x30) \
			FillValue(hDC, DataListIter, j, EndDrawPos, DataListIter->FillDirection & (0x30 | MASK), LegendIter); \
	} \
}

#define MOVEWITHMOUS(CON) \
if (CON && nVisibleCurve > 0) \
{ \
	short xStep = 0; \
	short yStep = 0; \
	if (m_MoveMode & 1) \
	{ \
		auto hd = m_ShowMode & 1 ? -1 : 1; \
		xStep = (short) (hd * (spoint.x - BeginMovePoint.x) / HSTEP); \
	} \
	if (m_MoveMode & 2) \
	{ \
		auto vd = m_ShowMode & 2 ? -1 : 1; \
		yStep = (short) (vd * (BeginMovePoint.y - spoint.y) / VSTEP); \
	} \
	MoveCurve(xStep, yStep); \
	BeginMovePoint.x += xStep * (m_ShowMode & 1 ? -HSTEP : HSTEP); \
	BeginMovePoint.y -= yStep * (m_ShowMode & 2 ? -VSTEP : VSTEP); \
}

#define NormalizeRect(rect) \
if (rect.left > rect.right) \
{ \
	rect.left ^= rect.right; rect.right ^= rect.left; rect.left ^= rect.right; \
} \
if (rect.top > rect.bottom) \
{ \
	rect.top ^= rect.bottom; rect.bottom ^= rect.top; rect.top ^= rect.bottom; \
}

#define TRIMCURVE(CON1, C1, bUseMore, C2) \
long re = 0; \
for (auto i = begin(MainDataListArr); i < end(MainDataListArr); ++i) \
	if (bAll || Address == *i) \
	{ \
		auto pDataVector = i->pDataVector; \
		auto j = begin(*pDataVector); \
		if (bUseMore && 2 == i->Power) \
		{ \
			for (auto k = 0; j < end(*pDataVector); ++k, ++j)\
				if (!(k % nStep) && C2) \
				{ \
					j->AllState = State; \
					++re; \
					SysState |= 0x200; \
				} \
		} \
		else \
		{ \
			CON1; \
			if (j < end(*pDataVector)) \
			{ \
				for (auto k = 0; j < end(*pDataVector) && C1; k += nStep, j += nStep) \
					if (!(k % nStep)) \
					{ \
						j->AllState = State; \
						++re; \
					} \
				SysState |= 0x200; \
			} \
		} \
		if (!bAll) \
			break; \
	} \
if (re) \
	UpdateRect(hFrceDC, CanvasRectMask); \
return re;

#define PREPAREUNITECURVE(C, CON, CALL) \
auto DataListIter = FindMainData(Address); \
if (NullDataListIter != DataListIter) \
{ \
	auto DesDataListIter = FindMainData(DesAddr); \
	if (NullDataListIter != DesDataListIter) \
	{ \
		auto pDesDataVector = DesDataListIter->pDataVector; \
		vector<MainData>::iterator InsertIter = NullDataIter; \
		if (C) \
			CON; \
		CALL; \
		return TRUE; \
	} \
} \
return FALSE;

#define UNITECURVE(CON1, CON2, C1, C2, CON3, bUseMore, C3) \
auto pDataVector = DataListIter->pDataVector; \
auto pDesDataVector = DesDataListIter->pDataVector; \
auto i = begin(*pDataVector); \
auto bFound = FALSE; \
if (bUseMore && 2 == DataListIter->Power) \
	for (; i < end(*pDataVector) && C3 && (bFound = TRUE); ++i) \
	{ \
		if (NullDataIter == InsertIter) \
			AddMainData2(DesDataListIter->Address, i->Time, i->Value, i->State, 0, FALSE); \
		else \
			pDesDataVector->insert(InsertIter, *i); \
	} \
else \
{ \
	CON1; \
	if (i < end(*pDataVector)) \
	{ \
		if (NullDataIter == InsertIter) \
			for (CON2; i < end(*pDataVector) && C1 && (bFound = TRUE); ++i) \
				AddMainData2(DesDataListIter->Address, i->Time, i->Value, i->State, 0, FALSE); \
		else \
		{ \
			auto k = i; \
			if (C2) \
				CON3; \
			else \
				i = end(*pDataVector); \
			if (k < i) \
			{ \
				bFound = TRUE; \
				pDesDataVector->insert(InsertIter, k, i); \
			} \
		} \
	} \
	if (bFound) \
	{ \
		if (NullDataIter != InsertIter) \
			InvalidCurveSet.insert(DesDataListIter->Address); \
		UpdateRect(hFrceDC, CanvasRectMask); \
	} \
}

#define OFFSETVALUE(Style, OldValue, OpValue) \
if ('+' == Style) \
	OldValue += OpValue; \
else \
	OldValue *= OpValue;

#define OFFSETCURVE(MainData) \
if (ChMask & 1) \
{ \
	OFFSETVALUE(Operator1, (MainData).Time, TimeSpan); \
	(MainData).ScrPos.x -= XOff; \
} \
if (ChMask & 2) \
{ \
	OFFSETVALUE(Operator2, (MainData).Value, ValueStep); \
	(MainData).ScrPos.y -= YOff; \
}

#define GetSorptionRect(RECT, X, Y, RANGE) \
RECT.left = X - RANGE; \
RECT.right = X + RANGE +  1; \
RECT.top = Y - RANGE; \
RECT.bottom = Y + RANGE + 1;

//��λͼ��Դ�����Чʱ��ȥ������Դ������
//��ȥ����λͼ��Դ�ڵ�ǰ�жϵ�������Դ��ǰ���ʱ��ִ��ˢ��
#define UpdateImageIndex(nImageIndex, OP1, OP2, MASK) \
if ((size_t) nImageIndex >= BitBmps.size()) \
{ \
	OP1; \
	OP2; \
	UpdateMask |= MASK; \
} \
else if (nImageIndex >= nIndex) \
{ \
	OP2; \
	UpdateMask |= MASK; \
}

#define MakeHotspotRect \
PreviewHotspotRect.right = VAxisRect.right; \
PreviewHotspotRect.left = PreviewHotspotRect.right - 5; \
PreviewHotspotRect.top = VAxisRect.bottom; \
PreviewHotspotRect.bottom = PreviewHotspotRect.top + 5; \
MOVERECT(PreviewHotspotRect, m_ShowMode);

#define MakePreviewRect \
PreviewRect.left = CanvasRect[1].left; \
PreviewRect.right = PreviewRect.left + 4 * HSTEP + 1; \
PreviewRect.bottom = CanvasRect[1].bottom; \
PreviewRect.top = PreviewRect.bottom - 2 * VSTEP - 1; \
MOVERECT(PreviewRect, m_ShowMode);

#define MakeNodeRect(RECT, POINT, PenWidth, NodeMode) \
{ \
	auto x = m_ShowMode & 1 ? 1 : 0, y = m_ShowMode & 2 ? 1 : 0; \
	auto step = 0; \
	if (NodeMode) \
	{ \
		x += 1; \
		y += 1; \
		step = 2; \
	} \
	RECT.left = (POINT).x - PenWidth / 2 - x; \
	RECT.top = (POINT).y - PenWidth / 2 - y; \
	RECT.right = RECT.left + PenWidth + step; \
	RECT.bottom = RECT.top + PenWidth + step; \
}

#define DrawNode(POINT, PenWidth, NodeMode) \
{ \
	RECT rect; \
	DrawNodeRect(rect, POINT, PenWidth, NodeMode); \
}

#define DrawNodeRect(RECT, POINT, PenWidth, NodeMode) \
{ \
	MakeNodeRect(RECT, POINT, PenWidth, NodeMode); \
	ExtTextOut(hDC, 0, 0, ETO_OPAQUE, &RECT, nullptr, 0, nullptr); \
}

#define CreateCommentRect(pos) \
if (4 == pos) \
{ \
	if (Width) \
		PosX -= Width / 2; \
	if (Height) \
		PosY -= Height / 2; \
} \
else \
{ \
	if (Width && pos > 1) \
		PosX -= Width; \
	if (Height && (1 == pos || 3 == pos)) \
		PosY -= Height; \
}

#define ISCURVESHOWN(DATALISTITER) (NullLegendIter == (DATALISTITER)->LegendIter  || (DATALISTITER)->LegendIter->State)
#define ISCURVEINPAGE(DATALISTITER, bPart, bXOnly) (NullDataIter != GetFirstVisiblePos(DATALISTITER, bPart, bXOnly))
#define ISCURVEVISIBLE(DATALISTITER, bPart, bXOnly) (ISCURVESHOWN(DATALISTITER) && ISCURVEINPAGE(DATALISTITER, bPart, bXOnly))

#define GETPAGESTARTTIME(BT, SP) (BT + (HCoorData.nScales - nZLength) * HCoorData.fCurStep * ((SP)  - 1))

//���ö���֮һǰ��ɫ
#define SetOneHalfColor(HDC) \
auto OneHalfColor = (m_foreColor & 0xFEFEFE) >> 1; \
if (IsColorsSimilar(OneHalfColor, m_backColor)) \
	OneHalfColor = ~OneHalfColor & 0xFFFFFF; \
SetTextColor(HDC, OneHalfColor);

//�����ķ�֮��ǰ��ɫ
#define SetThreeQuarterColor(HDC) \
auto ThreeQuarterColor = (m_foreColor & 0xFEFEFE) >> 1; \
ThreeQuarterColor += (ThreeQuarterColor & 0xFEFEFE) >> 1; \
if (IsColorsSimilar(ThreeQuarterColor, m_backColor)) \
	ThreeQuarterColor = ~ThreeQuarterColor & 0xFFFFFF; \
SetTextColor(HDC, ThreeQuarterColor);

#define LockGdiplus \
if (pGraphics) \
	pGraphics->GetHDC();

#define UnlockGdiplus \
if (pGraphics) \
	pGraphics->ReleaseHDC(hDC);

#define RemovePlugInOrScript(OP, bUpdate) \
long Mask = 0; \
if (pFormatXCoordinate && pFormatXCoordinate OP luaFormatXCoordinate) \
{ \
	pFormatXCoordinate = nullptr; \
	UpdateMask |= HLabelRectMask; \
	Mask |= 1; \
} \
if (pFormatYCoordinate && pFormatYCoordinate OP luaFormatYCoordinate) \
{ \
	pFormatYCoordinate = nullptr; \
	UpdateMask |= VLabelRectMask; \
	Mask |= 2; \
} \
if (pTrimXCoordinate && pTrimXCoordinate OP luaTrimXCoordinate) \
{ \
	pTrimXCoordinate = nullptr; \
	Mask |= 4; \
} \
if (pTrimYCoordinate && pTrimYCoordinate OP luaTrimYCoordinate) \
{ \
	pTrimYCoordinate = nullptr; \
	Mask |= 8; \
} \
if (pCalcTimeSpan && pCalcTimeSpan OP luaCalcTimeSpan) \
{ \
	pCalcTimeSpan = nullptr; \
	UpdateMask |= HLabelRectMask; \
	Mask |= 0x10; \
} \
if (pCalcValueStep && pCalcValueStep OP luaCalcValueStep) \
{ \
	pCalcValueStep = nullptr; \
	UpdateMask |= VLabelRectMask; \
	Mask |= 0x20; \
} \
if (bUpdate && !(Mask & 0x22 && SetLeftSpace()) && Mask & 0x33) \
{ \
	if (nVisibleCurve > 0) \
		UpdateMask |= CanvasRectMask; \
	UpdateRect(hFrceDC, UpdateMask); \
} \
return Mask;

#define UpdateForPlugInOrScript \
if (!(UpdateMask & VLabelRectMask && SetLeftSpace()) && UpdateMask & (VLabelRectMask | HLabelRectMask)) \
{ \
	if (nVisibleCurve > 0) \
		UpdateMask |= CanvasRectMask; \
	UpdateRect(hFrceDC, UpdateMask); \
}

#define CloseLua \
if (g_L) \
{ \
	lua_close(g_L); \
	g_L = nullptr; \
}

#define ClosePlugIn \
if (hPlugIn) \
{ \
	FreeLibrary(hPlugIn); \
	hPlugIn = nullptr; \
}

#define ReportPageChanges \
if (!(SysState & 1) && (m_pageChangeMSG && m_iMSGRecWnd || EventState & 1)) \
	SetTimer(REPORTPAGE, REPORTDELAY, nullptr)

#define FIRE_1(D, Mask, FUN) \
if (EventState & Mask) \
	FUN(D)

#define FIRE_2(D1, D2, Mask, FUN) \
if (EventState & Mask) \
	FUN(D1, D2)

#define FIRE_3(D1, D2, D3, Mask, FUN) \
if (EventState & Mask) \
	FUN(D1, D2, D3)

#define FIRE_PageChange(D1, D2) FIRE_2(D1, D2, 1, FirePageChange)
#define FIRE_BeginTimeChange(D) FIRE_1(D, 2, FireBeginTimeChange)
#define FIRE_BeginValueChange(D) FIRE_1(D, 4, FireBeginValueChange)
#define FIRE_TimeSpanChange(D) FIRE_1(D, 8, FireTimeSpanChange)
#define FIRE_ValueStepChange(D) FIRE_1(D, 0x10, FireValueStepChange)
#define FIRE_ZoomChange(D) FIRE_1(D, 0x20, FireZoomChange)
#define FIRE_SelectedCurveChange(D) FIRE_1(D, 0x40, FireSelectedCurveChange)
#define FIRE_LegendVisableChange(D1, D2) FIRE_2(D1, D2, 0x80, FireLegendVisableChange)
#define FIRE_SorptionChange(D1, D2, D3) FIRE_3(D1, D2, D3, 0x100, FireSorptionChange)
#define FIRE_CurveStateChange(D1, D2) FIRE_2(D1, D2, 0x200, FireCurveStateChange)
#define FIRE_ZoomModeChange(D) FIRE_1(D, 0x400, FireZoomModeChange)
#define FIRE_HZoomChange(D) FIRE_1(D, 0x800, FireHZoomChange)
#define FIRE_BatchExportImageChange(D) FIRE_1(D, 0x1000, FireBatchExportImageChange)

#define SYNA_TO_TRUE_POINT \
ScrPos = spoint; \
ClientToScreen(&ScrPos); \
SetCursorPos(ScrPos.x, ScrPos.y)

#define IsCursorNotInCanvas(POINT) (nVisibleCurve <= 0 || SysState & 0x80000000 && PtInRect(&PreviewRect, POINT) || !PtInRect(CanvasRect, POINT))

#define SCROLLCURVE(MASK, DEC, ADD, xStep, yStep) \
if (m_MoveMode & MASK) \
{ \
	auto hd = m_ShowMode & 1 ? -1 : 1; \
	auto vd = (m_ShowMode & 3) < 2 ? -1 : 1; \
	switch (wParam & 0xFFFF) \
	{ \
	case DEC: \
		if (MoveCurve(hd * -xStep, vd * yStep)) \
			return 0; \
		break; \
	case ADD: \
		if (MoveCurve(hd * xStep, vd * -yStep)) \
			return 0; \
		break; \
	} \
}

#ifdef _WIN64
	#define Format64bitHandle(HANDLETYPE, LOW32BIT) ((HANDLETYPE) (((ULONGLONG) m_register1 << 32) + (ULONG) LOW32BIT))
	#define SplitHandle(H) (m_register1 = (OLE_HANDLE) ((ULONGLONG) H >> 32), (OLE_HANDLE) H)
#else
	#define Format64bitHandle(HANDLETYPE, LOW32BIT) ((HANDLETYPE) LOW32BIT)
	#define SplitHandle(H) ((OLE_HANDLE) H)
#endif

//���º�ֻ�������ڵ���_sntprintf֮�󣬶Է��س��ȵ�У��
//_sntprintf_s���������ݱ��ض�ʱ������-1������ʱ�����������˵�
//ע�⣺�����ֻ������Ŀ�Ļ���д�������ص����������ֻ������CoorData������صĵط�
#define adjust_poly_len(Coor_Data) adjust_poly_len2(Coor_Data.pPolyTexts[nIndex].n, PolyTextLen - 1)

#define adjust_poly_len2(d, m) \
if (-1 == d) \
	d = m

#define MINTIME	-657434.0 //100-1-1
#define MAXTIME	2958465.0 //9999-12-31

#define ISHVALUEVALID(DV) (MINTIME <= DV && DV <= MAXTIME)
#define ISHVALUEINVALID(DV) (!(m_ShowMode & 0x80) && !ISHVALUEVALID(DV))

#define IsTimeInvalidate	(dStepTime < .01 / (24 * 60 * 60)) //����С��0.01�룬���������ޣ�2.1.0.1��
#define IsValueInvalidate	(thisValueStep < .000001f) //����С��.000001�����������ޣ�2.1.0.1��

#define IsMainDataStateValidate(STATE) ((State & 0xFF) <= 2 && (USHORT) (State & 0xFF00) <= 0x100)

// ST_CurveCtrl.h : CST_CurveCtrl ActiveX �ؼ����������


// CST_CurveCtrl : �й�ʵ�ֵ���Ϣ������� ST_CurveCtrl.cpp��

class CST_CurveCtrl : public COleControl
{
	DECLARE_DYNCREATE(CST_CurveCtrl)

// ���캯��
public:
	CST_CurveCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual DWORD GetControlFlags();
	virtual BOOL OnSetExtent(LPSIZEL lpSizeL);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void Serialize(CArchive& ar);
	virtual void OnResetState();
protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

// ʵ��
protected:
	IWebBrowser2* pWebBrowser; //����ȷ���ؼ��Ƿ�������IE��

	ULONG_PTR m_gdiplusToken;

	HWND	hBuddyServer;  //��������������������ͻ��������ֵ��������������ֵΪ0
	vector<HWND>* pBuddys; //�����ͻ������飬���������������ֵ�������ͻ�����ֵΪ0
	BYTE BuddyState;
	//�ӵ�λ��ʼ����һλ�����ڴ���������鷢������Ϣ����ʱ���ɷ�����ȥ��
	//��Щ״̬��ֻ�Կͻ�����Ч������������Ҫ����Ϣ������ȥ

	//���У��������ʾ����7λ��
	//0��ʼ�հ�Z�������0��У��������ʾ����ʵ���ǲ�У��
	//1��ʼ�հ�ѡ�����ߵ�Z������У��������ʾ�����û��ѡ�����ߣ����Ч��0
	//2�����ѡ�е������ڻ����У���ѡ�����ߵ�Z������У��������ʾ����û��ѡ�����ߣ�����ѡ�����߲��ڻ�����ʱ����Ч��0
	//3��ֻ�����ߵ�����ʾ������ʾ
	BYTE	m_ReviseToolTip;

	WORD	MouseMoveMode; //����ƶ�ģʽ���ƶ�ģʽ���϶�ģʽ������ģʽ
	HCURSOR	hZoomIn, hZoomOut, hMove, hDrag; //�Ŵ���С���ƶ����϶�ʱ����꣬�ƶ�ʱ�������

	//��ǰ�������ڵ����ߵ�ַ��ԭʼ����
	long m_CurActualAddress;
	ActualPoint m_CurActualPoint;

	/*�Ѿ�������Ӵ˹��ܣ���Ϊ���ο�������ʵ�ִ˹��ܽ����ӵ�������
	MoveBuddy* pMoveBuddy[2]; //�ƶ�����������ݽṹ������������������͵ײ�����û���ƶ�������ϵ�ĸ�ֵΪ0
	*/

	//�������ʱ������Ϊ̫Ƶ���õ�����������Ϊ���Ա������ע�ⲻ������Ϊȫ�ֱ��������򵱶���ؼ���ͬһ������ʱ������
	//���ܻ���ַ��ʳ�ͻ
	RECT	InvalidRect; //��������ж�ˢ�����򣨴�ֲ������������ô���

#define StrBuffLen	128
#define StrTitleLen	128
#define StrWaterMarkLen	48
	TCHAR	StrBuff[StrBuffLen];	 //�ַ�������
	TCHAR	CurveTitle[StrTitleLen]; //���߱���
	TCHAR	FootNote[StrTitleLen];   //���߽�ע
	TCHAR	WaterMark[StrWaterMarkLen]; //ˮӡ
	BatchExport* m_BE; //��ʱ����ͼƬʱʹ��

	HPEN	hAxisPen;  //����������ʱʹ��
	HRGN	hScreenRgn; //�������򣬴�ӡʱ�������

	HFONT	hFont; //�������ֻ���ʱ�õ����壬��ӡʱ�������
	HFONT	hTitleFont; //��������
	BYTE	fHeight, fWidth; //�ֵĸ߶ȺͿ��

	BYTE	m_ShowMode;
	//�ӵ�λ�𣬵�һλ��1��Y����ʾ���ұߣ�0��Y����ʾ����ߣ��ڶ�λ��1��X����ʾ���ϱߣ�0��X����ʾ���±�
	//����λ��1������ʾ�����գ�0����ʾ
	//����λ��1������ʾʱ���룬0����ʾ
	//�ڰ�λ���Ϊ1��������꽫��ֵ�ķ�ʽ��ʾ����ʱ��������λ��Ч
	BYTE	m_MoveMode;
	//�ӵ�λ��
	//1���Ƿ�������ˮƽ���ƶ�����
	//2���Ƿ������ڴ�ֱ���ƶ�����
	//3���Ƿ�Ϊ�����ƶ�ģʽ�����ڰ�ס����ƶ��������ƶ����ߣ������Ϊ�����ƶ�ģʽ����������������ʱ�ƶ�����
	//��8λ���Ϊ1����������ƶ������϶����ߣ�ʱ����ʾΪ���ͣ�������ʾΪʮ�ּܣ���ʱ������ʾʧЧ������ЧӦҲʧЧ
	BYTE	m_BkMode; //����λͼ����ʾģʽ����m_hBkBitmap��Ϊ0ʱ����Ч����7λ��0��ƽ�̣�1�����У�2�����죻��8λ���Ƿ�ü�������
	BYTE	m_CanvasBkMode; //����������ʾģʽ������ͬm_BkMode��ֻ�ǲ������õ�8λ

	short	m_vInterval, m_hInterval;
	//��ֱ��ˮƽ���ϣ�ÿ���̶�ֵ֮��Ŀ̶���������ֱ����С�̶���1���ף����̶�ֵ��СΪ1���ף���ʱ�̶ȼ��Ϊ9

	short	m_LegendSpace; //ͼ���ַ��������������Ľ����ɼ�
	short	LeftSpace;  //������߾�
	short	ActualLeftSpace; //������������߾࣬���û������������ϵ�������LeftSpace

	short	Zoom; //���ţ���Ϊ�Ŵ󣬸�Ϊ��С
	short	HZoom; //ˮƽ�ϵ����ţ���Zoom��Ӳ������������ţ����ֵ��Ҫ����ʵ��ͨ��������ֻ��ˮƽ�����ţ����Ʊ�����

	short	TopSpace;	//�Ͽհ�
	short	RightSpace;	//�ҿհ�
	short	BottomSpace;//�¿հ�
	BYTE	BottomSpaceLine; //�¿հף�������
	BYTE	CommentPosition; //ע��λ�ã�0-��ײ� 1-��߲�

	typedef BOOL (CST_CurveCtrl::*OnMouseWheel)(int zDelta);
	OnMouseWheel OnMouseWheelFun[4];

	BOOL OnMouseWheelZoom(int zDelta);
	BOOL OnMouseWheelHZoom(int zDelta);
	BOOL OnMouseWheelHMove(int zDelta);
	BOOL OnMouseWheelVMove(int zDelta);

	//0-��ֱ�ƶ��� 1-���ţ�2-ˮƽ���ţ� 3-ˮƽ�ƶ�
	BYTE	MouseWheelMode; //�ӵ�λ��ÿ��λΪһ�飬�����ǣ�shift alt ctrl�Ͳ�����
	BYTE	MouseWheelSpeed; //�������ٶȣ�������
	//���������ֽ�δʹ��

	ActualPoint BenchmarkData; //����OriginPoint��Ļ����ʱ�Ļ�׼
	MainData LeftTopPoint; //����������ռ������СX�����Y
	MainData RightBottomPoint; //����������ռ�������X����СY
#define m_MinTime LeftTopPoint.Time
#define m_MaxValue LeftTopPoint.Value
#define m_MaxTime RightBottomPoint.Time
#define m_MinValue RightBottomPoint.Value
	MainData OriginPoint; //ԭ��
	//���ﶼû��ʹ��MainData��State��Ա

	CoorData<HCOOR_TYPE> HCoorData; //������
	CoorData<float> VCoorData;  //������

	set<long> InvalidCurveSet;
	//��û�и���LeftTopPoint��RightBottomPoint��nPower�ȳ�Ա�����ߣ�ֻ��AddMainData2��InsertMainData2��������ʹ�ã�

#define StrUintLen	16
#define StrPreExpLen 8
	TCHAR	Unit[StrUintLen]; //��λ
	TCHAR	HUnit[StrUintLen]; //ˮƽֵ��λ
	TCHAR	VPrecisionExp[StrPreExpLen]; //��ʾ������ʱ�Ĵ�ӡ�ַ��������а�������
	TCHAR	HPrecisionExp[StrPreExpLen]; //��ʾ������ʱ�Ĵ�ӡ�ַ��������а�������

	long	MaxLength, CutLength; //ÿ���������������ﵽ���������ǰ��ص��ĵ���
	int		nVisibleCurve; //��ǰ������ʾ״̬����������

	vector<LegendData> LegendArr;
	vector<CString> HLegend;
	vector<DataListHead<MainData>> MainDataListArr;
	vector<InfiniteCurveData> InfiniteCurveArr;
	vector<CommentData> CommentDataArr;
	//ͼ�����������������
	size_t CurCurveIndex;

	//ר�Ź�Polygon��Polyline����ʹ�õĻ��棬�ڴ���������ظ��ķ������ͷţ������������������ڴ涼�ܴ����ʵ
	//Ĭ��Ϊ������ÿһ�����������һ���ռ�
	vector<POINT> points;

	//����ÿһ������������ĵڶ���ֵΪ���������µ����꣬��һ��ֵΪ��ǰ����ϵ�µ�����
	RECT	UnitRect, LegendMarkRect, TimeRect;
	RECT	VAxisRect, HAxisRect, VLabelRect, HLabelRect, LegendRect[2], CanvasRect[2];
	RECT	CurveTitleRect; //�������û��ӳ������
	RECT	FootNoteRect;

	//ȫ��λ�ô������
	RECT	PreviewHotspotRect; //���������ڣ�����ȫ��λ�ô��ڣ���Ļλ�ã�
	RECT	PreviewRect; //ȫ��λ�ô��ڵ�λ�ã���Ļλ�ã�
	POINT	PreviewPoint; //��ǰ������ȫ��λ�ô��������λ�ã����ε����Ͻǵ㣩

	int		WinWidth, WinHeight;
	float	Tension; //���ƻ�����������ʱ��ϵ��
	UINT	SysState;
	//�ӵ�λ��
	// 1���Ƿ����ڴ�ӡ
	// 2���Ƿ����ڰ�ҳ����ͼƬ
	// 3���Ƿ�ֻ��ʾ���������̶�֮�ϣ�Ĭ��Ϊ��
	// 4���Ƿ�����ѡ������
	// 5���Ƿ���ˮƽ���ţ�Ĭ���ڰ���alt���������ʱִ�У����޸ģ�
	// 6����Ҫ��spoint�뵱ǰ����ͬ����������alt��֮����Ҫ�����������忴cpp�ļ���
	// 7����Ҫ�ѵ�ǰ������spointͬ��
	// 8����Ȩ��Ϣ�Ƿ��Ѿ����أ���δʵ�֣�
	// 9���Ƿ��ڽ���״̬
	//10���Ƿ���δ���Ƶ�hFrceDC�����ݣ�������ӵ���û��ָ��bEnsureViaibleΪTRUE�������
	//11���Ƿ���������
	//12��������ʾ�Ƿ�����ʾ��
	//13�������Ƿ��Ѿ�����
	//14���Ƿ������Զ��������߲��
	//15���Ƿ���������ЧӦ
	//16���Ƿ��Ѿ�����������Ѿ���������m_CurActualPoint������Ǳ������ĵ�
	//17����Դ֮����ʹ��
	//18���Ƿ��Զ��������꣨�ڶ������ź��Զ�ִ��TrimCoor������
	//19���Ƿ�������ʾ�򵥵İ�����Ϣ�ڱ���֮��
	//20���Ƿ���ʾ��������
	//21���Ƿ���ʾ��������
	//22���Ƿ���ȫ����ʾ״̬֮��
	//23���Ƿ���ʾ����״̬
	//24���Ƿ����ʵ������
	//25���Ƿ�̶�X�Ὺʼ����
	//26���Ƿ�̶�X���������
	//27���Ƿ�̶�Y�Ὺʼ����
	//28���Ƿ�̶�Y���������
	//29���Ƿ�ֻ��ʾһҳ����ʱ25��28λ��Ч
	//30���Ƿ�ǿ����ֹˢ�£�ʹ����SetRedraw������
	//31���Ƿ���ֹDrawCurve�����ƶ����ߣ�ֻ�ڴ�ֱ��������Ч��
	//32��ȫ��λ�ô����Ƿ�����ʾ��

	UINT EventState;
	//�ӵ�λ��
	//1 ��PageChange
	//2 ��BeginTimeChange
	//3 ��BeginValueChange
	//4 ��TimeSpanChange
	//5 ��ValueStepChange
	//6 ��ZoomChange
	//7 ��SelectedCurveChange
	//8 ��LegendVisableChange
	//9 ��SorptionChange
	//10��CurveStateChange
	//11��ZoomModeChange
	//12��HZoomChange
	//13��BatchExportImageChange
#define ALL_EVENT_MASK	0x1FFF

	USHORT VSTEP; //��������Ļ����
	USHORT HSTEP; //��������Ļ����

	//�Զ�ˢ�£���2�ֽ��еĵ�15λ���������������2�ֽڴ���ʱ��������λ��1/10�룬��������6553.5��
	//Ӱ�쵽�Ľӿ��У�AddMainData(2)
	UINT AutoRefresh;

	HCOOR_TYPE FixedBeginTime, FixedEndTime;
	float FixedBeginValue, FixedEndValue;

	USHORT nZLength; //Z�᳤�ȣ���λΪ�̶���
	short nCanvasBkBitmap; //��������λͼ
	COLORREF LeftBkColor, BottomBkColor;

	POINT	BeginMovePoint; //��ʼ�ƶ���
	POINT	LastMousePoint; //�ϴ�������꣬����Ĩ��ʮ�ֽ�����
	RECT	ToolTipRect; //������ʾ��tooltipռ�ľ��Σ�����Ĩ��tooltip
	short	SorptionRange;

	short	nBkBitmap; //����λͼ���
	vector<BitBmp> BitBmps;
	HBITMAP	hBackBmp; //�ڴ汳��λͼ�����ˢ���ٶ�
	HBITMAP hFrceBmp; //�ڴ�ǰ��λͼ�����ˢ���ٶ�
	HDC		hBackDC;  //�ڴ����DC������hBackBmp
	HDC		hFrceDC;  //�ڴ����DC������hFrceDC
	HDC		hTempDC;  //�ڴ����DC�����ڸ���������ʱʹ�õĵط�
	void	DrawBkgImage(HDC hDC, HBITMAP hBitmap, RECT& rect, UINT BkMode);
	void	DrawBkg(BOOL bReCreate = FALSE);  //���Ʊ�����BkBitmap��
	void	InitFrce(BOOL bReCreate = FALSE); //��ʼ��ǰ��DC

	void AddBitmap(HBITMAP hBitmap, UINT State);

	//���ƺ���
	void DrawGrid(HDC hDC);   //��������
	void DrawUnit(HDC hDC);   //���Ƶ�λ
	void DrawVAxis(HDC hDC);  //����������
	void DrawHAxis(HDC hDC);  //���ƺ�����
	void DrawVLabel(HDC hDC); //�����ݿ̶�
	void DrawHLabel(HDC hDC); //���ƺ�̶�
	void DrawLegend(HDC hDC); //����ͼ��
	void DrawTime(HDC hDC);   //���Ƶ�λ
	void DrawLegendSign(HDC hDC); //���Ƶ�λ
	void DrawCurveTitle(HDC hDC); //���Ʊ���
	void DrawFootNote(HDC hDC); //���ƽ�ע
	void DrawPreviewView(HDC hDC); //����ȫ��λ�ô���
	void DrawComment(HDC hDC); //����ע��
	UINT GetPoints(vector<DataListHead<MainData>>::iterator DataListIter,
		vector<MainData>::iterator BeginPos, vector<MainData>::iterator EndPos, vector<MainData>::iterator& EndDrawPos,
		UINT CurveMode, BOOL bClosedAndFilled, BOOL bDrawNode, HDC hDC, UINT NodeMode, UINT PenWidth);
	void FillValue(HDC hDC, vector<DataListHead<MainData>>::iterator DataListIter,
		vector<MainData>::iterator BeginPos, vector<MainData>::iterator EndPos, UINT FillDirection, vector<LegendData>::iterator LegendIter);
	void DrawCurve(HDC hDC, HRGN hRgn, vector<DataListHead<MainData>>& DataListArr, UINT& CurvePosition, BOOL bInfiniteCurve = FALSE,
		vector<DataListHead<MainData>>::iterator DataListIter = NullDataListIter, vector<MainData>::iterator BeginPos = NullDataIter);
	void DrawCurve(HDC hDC, HRGN hRgn,
		vector<DataListHead<MainData>>::iterator DataListIter = NullDataListIter, vector<MainData>::iterator BeginPos = NullDataIter); //��������
	//����ˢ�£���Mask��Ϊ1��λ������Ӧ�����򽫱�ˢ�£�lpRect������Ҫ����Ļ��ˢ�µ�����
	//Mask��ÿһλ��Ӧ���������£�
#define UnitRectMask		1
#define LegendMarkRectMask	2
#define TimeRectMask		4
#define VAxisRectMask		8
#define HAxisRectMask		16
#define VLabelRectMask		32
#define HLabelRectMask		64
#define LegendRectMask		128
#define CanvasRectMask		256
#define CurveTitleRectMask	512
#define FootNoteRectMask	1024
#define PreviewRectMask		2048
#define TitleRectMask		(CurveTitleRectMask | UnitRectMask | LegendMarkRectMask)
#define AllRectMask			(TimeRectMask | VAxisRectMask | HAxisRectMask | VLabelRectMask | HLabelRectMask | LegendRectMask | CanvasRectMask | TitleRectMask | FootNoteRectMask)
#define PrintRectMask		(AllRectMask & ~(CanvasRectMask | CurveTitleRectMask | FootNoteRectMask))
#define ForeRectMask		(AllRectMask & ~(VAxisRectMask | HAxisRectMask | CanvasRectMask))
#define MostRectMask		(AllRectMask & ~(TitleRectMask | LegendRectMask))
	void UpdateRect(HDC hDC, UINT Mask, vector<DataListHead<MainData>>::iterator DataListIter = NullDataListIter, BOOL bUpdate = TRUE);
	void DrawAcrossLine(const LPPOINT pPoint); //Ĩ����һ�ε�ʮ�ֽ����߼�������ʾ�����һ���ʮ�ֽ�����
	void RepairAcrossLine(HDC hDC, LPCRECT pRect, BOOL bCheckBound = TRUE);
	void ShowToolTip(HDC hDC);
	BOOL SetLeftSpace(BOOL bCanvasWidthCh = FALSE); //����LeftSpace��ֵ������������ƶ����򷵻��棬���򷵻ؼ�
	BOOL CHLeftSpace(short ThisLeftSpace, BOOL bCanvasWidthCh = FALSE); //�޸�LeftSpace������ֵͬSetLeftSpace
	short GetMaxLeftSpace(short RootLeftSpace);
	//��ȡ���пͻ�����LeftSpace�е����ֵ��RootLeftSpace��������������СLeftSpace
	short RestoreLeftSpace(); //��ȡ�Լ�����СLeftSpace

	BOOL IsLineInCanvas(vector<LegendData>::iterator LegendIter, const POINT& p1, const POINT& p2);
//	inline int IsPointOutdrop(POINT& p);
//	inline int IsLineOutdrop(POINT& p1, POINT& p2);
	BOOL IsPointVisible(vector<DataListHead<MainData>>::iterator DataListIter, vector<MainData>::iterator DataIter, BOOL bPart, BOOL bXOnly, UINT Mask = 3);
	vector<MainData>::iterator GetFirstVisiblePos(long Address);
	vector<MainData>::iterator GetFirstVisiblePos(vector<DataListHead<MainData>>::iterator DataListIter,
		BOOL bPart, BOOL bXOnly, UINT* pPosition = nullptr, vector<MainData>::iterator DataIter = NullDataIter);
	//Mask�ӵ�λ��1���Ƿ����һ�㣬2���Ƿ���ǰһ��
	size_t DoGetPointFromScreenPoint(vector<DataListHead<MainData>>::iterator DataListIter, long x, long y, short MaxRange);

	UINT CheckVPosition(float fBeginValue); //����Ƿ�����ÿ�ʼֵΪfBeginValue
	UINT CheckHPosition(HCOOR_TYPE fBeginTime); //����Ƿ�����ÿ�ʼֵΪfBeginTime
	UINT CheckPosition(short xStep, short yStep); //����Ƿ�ɰ������ľ����ƶ�����

	//����ָ�����ߵ��ݴ�
	void UpdatePower(vector<DataListHead<MainData>>::iterator DataListIter);

	//��������ϼ�
	void DoUniteCurve(vector<DataListHead<MainData>>::iterator DataListIter, vector<MainData>::iterator InsertIter,
		vector<DataListHead<MainData>>::iterator DesDataListIter, long nBegin, long nCount);
	void DoUniteCurve(vector<DataListHead<MainData>>::iterator DataListIter, vector<MainData>::iterator InsertIter,
		vector<DataListHead<MainData>>::iterator DesDataListIter, HCOOR_TYPE BTime, HCOOR_TYPE ETime, short Mask);

	//1.3.0.6
	long ExportMetaFileFromTime(LPCTSTR pFileName, long Address, vector<DataListHead<MainData>>::iterator ExportIter, HCOOR_TYPE MinTime, HCOOR_TYPE MaxTime, short Style);

	//1.3.0.7
	UINT UpdateFixedValues(HCOOR_TYPE MinTime, HCOOR_TYPE MaxTime, float MinValue, float MaxValue, UINT Mask);
	//Mask�����������Ч�ԣ��ӵ��������ǣ���4λ����MinTime��MaxTime��MinValue��MaxValue
	//����ֵ�ӵ�λ�������ǣ�SetBeginTime2��SetTimeSpan��SetBeginValue��SetValueStep������ִ�н������TRUE����1��������0����Щ�����ɷ���FALSE��TRUE��2��

	/*
	���¶�λ����λ��
	OpStyle�ӵ�λ��ʼ
	��1λ��1��ǿ�д�ֱ����
	��2λ��1�����ֱ�ҳ������
	��3λ��1�����ֱ�ҳ������λ��
	����ֵ
	��1λ��1����ҳ�ǿ�
	��2λ��1���ƶ�������
	*/
	UINT	ReSetCurvePosition(UINT OpStyle, BOOL bUpdate, vector<DataListHead<MainData>>::iterator DataListIter = NullDataListIter);
	//�����������õ�����˵ڼ���ͼ�����������Ѿ���ͼ����Χ֮�ڣ�LegendRect��������ͼ���������أ����������Ų�һ��������ȫ��ͼ���е����
	size_t	GetLegendIndex(long y);
	BOOL	SelectLegendFromIndex(size_t nIndex); //�����ѡ��ͼ����ֻӰ���ͼ���ĵ�һ�����ߣ��������ѡ�У���ȡ��ѡ��
	void	ChangeSelectState(vector<DataListHead<MainData>>::iterator DataListIter);
	HCOOR_TYPE	GetNearFrontPos(HCOOR_TYPE DateTime, HCOOR_TYPE BenchmarkTime);
	void	ReSetUIPosition(int cx, int cy);
	//����ָ�����ߵ�MinTime��MaxTimeֵ��MinValue��MaxValueֵ�����һ�����������ڻ���ʵʱ���ߵ�ʱ��
	void	UpdateOneRange(vector<DataListHead<MainData>>::iterator DataListIter, vector<MainData>::iterator DataIter = NullDataIter);
	void	UpdateTotalRange(BOOL bRectOnly = FALSE);
	void	ShowLegendFromIndex(size_t nIndex);  //�������ʾͼ����Ӱ���ͼ�����������ߣ�������Ѿ���ʾ��������
	vector<LegendData>::iterator FindLegend(LPCTSTR pSign); //����ͼ��
	vector<LegendData>::iterator FindLegend(long Address, BOOL bInLegend = FALSE); //����ͼ��
	COLORREF FindLegend(vector<LegendData>::iterator LegendPos, long Address, BOOL bDel = FALSE, BOOL bAll = FALSE);
	BOOL DoDelLegend(vector<LegendData>::iterator LegendPos, long Address, BOOL bDelAll, BOOL bUpdate);
	void ReSetDataListLegend(vector<LegendData>::iterator BeginPos, vector<LegendData>::iterator EndPos);
	void DoMoveCurveToLegend(long Address, vector<LegendData>::iterator& LegendIter, BOOL bUpdate);
	//ɾ��������㣬����ֵ����λ�㣬�ӵ�λ��ʼ��1��2��δʹ�� 3���Ƿ�ɾ����CurCurveIter��4���Ƿ�ɾ����DataListIter��������
	UINT DoDelMainData(vector<DataListHead<MainData>>::iterator& DataListIter, vector<MainData>::iterator BeginPos, vector<MainData>::iterator EndPos, BOOL bUpdate);
	vector<DataListHead<MainData>>::iterator FindMainData(long Address); //��������
	//����ʵʱ����
	//VisibleState�ӵ�λ��AddMainData, AddMainData2��ͬ����������һ������
	//1���Ƿ����ϻ�����ӵĵ㣨���Ըò�����
	//2�����������겻��
	//3�����ֺ����겻��
	void RefreshRTData(vector<DataListHead<MainData>>::iterator DataListIter, vector<MainData>::iterator Pos, short VisibleState);
	//�ƶ����ߣ�bCheckBound����ȷ�����ƶ��Ϸ��Եļ��
	UINT MoveCurve(short xStep, short yStep, BOOL bUpdate = TRUE, BOOL bCheckBound = TRUE);
	UINT MoveCurve(SIZE size);
	//��ʵ�����������Ļ���꣬���ԭ������δ�䣬ֻ�ǻ�����С����λ�øı䣬��ChMask��Ϊ0���ӵ�λ�𣬵�1λ����ˮƽ���򣬵�2λ����ֱ����
	void CalcOriginDatumPoint(MainData& ap, UINT ChMask = 3, int XOff = 0, int YOff = 0, vector<DataListHead<MainData>>::iterator DataListIter = NullDataListIter);
	//����Ļ��ת��ʵ������ֵ
	ActualPoint CalcActualPoint(const POINT& point);
	//������ָ����ɼ�ʱ��Ҫ���ƶ���
	SIZE MakePointVisible(vector<DataListHead<MainData>>::iterator DataListIter, vector<MainData>::iterator DataIter, short VisibleState = 0);
	//���ߴ�ӡ����������ʵ�ʴ�ӡ��ҳ����1
	BOOL DoPrintCurve(HDC hPrintDC,
					  vector<DataListHead<MainData>>::iterator DataListIter,
					  HCOOR_TYPE BeginTime,
					  LPCTSTR pTitle,
					  LPCTSTR pFootNote,
					  int ViewWidth,
					  int ViewHeight,
					  int OrgX,
					  int OrgY,
					  WORD PageFrom,
					  WORD PageTo,
					  short Flag);
	void ClearCurve();
	void ClearLegend();
	void DeleteGDIObject();

	BOOL IsCurveClosed2(vector<DataListHead<MainData>>::iterator DataListIter);

	int FormatToolTipString(long Address, HCOOR_TYPE DateTime, float Value, UINT Action); //����X��Y����ķָ�λ�ã���\n��λ��
	UINT DrawSelectedNode(HDC hDC, HRGN hRen, vector<DataListHead<MainData>>::iterator DataListIter, UINT PenWidth, size_t OldSelectedNode);
	void UpdateSelectedNode(vector<DataListHead<MainData>>::iterator DataListIter, size_t OldSelectedNode);
	BOOL CanCurveBeDrawnAlone(vector<DataListHead<MainData>>::iterator DataListIter);
	void MoveSelectNodeForward();
	void MoveSelectNodeBackward();

	BOOL DoFixedZoom(const POINT& point); //���������жϣ�����ǰҪ��֤�Ϸ�
	void DoSetFixedZoomMode(WORD ZoomMode, POINT& point); //���������жϣ�����ǰҪ��֤�Ϸ������ڿɼ�����ʱ���ã�
	void DoSetFixedZoomMode(WORD ZoomMode); //���������жϣ�����ǰҪ��֤�Ϸ��������ڿɼ�����ʱ���ã�

	vector<InfiniteCurveData>::iterator FindInfiniteCurve(long Address); //������������

	//������
	//��Ҫ�ص��ǽ�ֵת�����ַ���
	typedef const TCHAR* FormatXCoordinate(long Address, HCOOR_TYPE DateTime, UINT Action); //���0
	typedef const TCHAR* FormatYCoordinate(long Address, float Value, UINT Action); //���1
	//������������ڿ��Ʊ��ؼ���Ҫ������Щ������0-31���ɼ�ÿһ�������ֻ֧��32���ӿ�
	//�������̫�࣬��Ҫ�Բ������

/*
Address�����Ľ������£�
Ҫ����������ʾ�����ߵ�ַ��ֻ��������ЧӦ�������ο�SetSorptionRange�ӿڣ�����
ֻ�����ߵ�����������ʾ���ο�SetReviseToolTip�ӿڣ�������²������壬��������0x7fffffff
����Ҫ��ʹ��Address�������Ͳ��ò���ʧһЩ����
���续�����������������ʾ���ܣ�����ͨ��SetReviseToolTip���ã�Ĭ�ϲ��ǣ�
�˲��������ڶ�����ϵ�£����һ�ֻ����������ʾ��ʱ��һ���Ҳ�����Ҫ�����������

Action�����Ľ������£�
1-���������Ὺʼ����ʱDateTime��Value��Ч������ֵ��Ч
2-��������������У���ʱDateTime��Value��Ч
���ص��ַ����У�֧�ֻ��з���\n�������֧��һ�������û�л��з�������ʾΪһ��
�л��з���ʱ�򣬽���ʾΪ���У�ÿ�����32���ַ���Y�᲻֧�ֻ��з�
3-�����������������ʱDateTime��Value��Ч������ֵ��Ч

4-��ʾ������ʾ��Tooltip��
	��ʱFormatXCoordinate��FormatYCoordinate���ص��ַ����ĳ��Ⱥͱ�����127���ַ�֮��
	����Ķ���
	������ֻ�ṩ��FormatXCoordinate��FormatYCoordinate����һ������δ�ṩ�߲���
	�ؼ�ԭ���Ĵ�ӡ��ʽ����������Ĵ�ӡ�����������Ȼ������127���ַ�֮��

5-�������꣬����Ҫ��ͬ4
	����ʲô�ǻ������꣬�ο�SetXYFormat�ӿ�

6-����Y��λ��ʱ���ã����ڶ�λY����߿�ľ��룬�Ա���ʾ����Y����
	��������߿���������һ�����Y��λ�õ���ʾ�����ص��ַ���������127���ַ�֮��
	ֻ���Y������ô˽ӿ�

7-�������ֵ
	����ʲô�����ֵ���ο�SetFillDirection�ӿ�
	ֻ���Y������ô˽ӿڣ���������127���ַ�

	�������еķ���ֵ��������˵���⣬����֧�ֻ��з�
*/
	FormatXCoordinate*	pFormatXCoordinate;
	FormatYCoordinate*	pFormatYCoordinate;

	//��Ҫ�ص��Ƿ���ֵ
	typedef HCOOR_TYPE TrimXCoordinate(HCOOR_TYPE DateTime); //���2
	typedef float TrimYCoordinate(float Value); //���3
	/*
	�������꣬�����Luaʵ�֣�������Luaʧ��ʱ�������ÿؼ��ڲ���Ĭ�ϴ���ʽ����
	*/
	typedef double CalcTimeSpan(double TimeSpan, short Zoom, short HZoom); //���4
	typedef float CalcValueStep(float ValueStep, short Zoom); //���5
	/*
	ʹ�ò����������������Է���ֵ���Ϸ��Լ���
	ע����һ����ο����߱���Ҫע�⣬�Ŵ����ű��뱣֤Բ����ʲô��˼�أ����Ǹ�����������˼�����磺
	double a = ...;
	double a1 = CalcTimeSpan(a, 1, 0); //��a�Ŵ�1��
	double a2 = CalcTimeSpan(a1, -1, 0); //��a1��С1��
	��ʱ��aӦ�õ���a2�����÷Ŵ�n���Ľ����ȥ��Сn�����õ��Ľ��Ӧ�õ���ԭʼֵ���൱��û�зŴ�Ҳû����С��
	�������ƿؼ�ֻ��ʾһҳ��ʱ����Ҫʹ�ã������ȷ������ʹ�á�����һҳ��������ܣ�����Բ���������Ĺ涨
	�����Luaʵ�֣�������Luaʧ��ʱ�������ÿؼ��ڲ���Ĭ�ϴ���ʽ����
	*/

	TrimXCoordinate* pTrimXCoordinate;
	TrimYCoordinate* pTrimYCoordinate;
	CalcTimeSpan* pCalcTimeSpan;
	CalcValueStep* pCalcValueStep;
	//��1�����������
#define PlugInType1Mask		0x3F //��һ����Ŀǰ����6��

	HMODULE hPlugIn;

	long FreePlugIn(UINT& UpdateMask, BOOL bUpdate); //�ͷŲ����ֻ���ͷ��ɲ��dll���صĽӿڣ�
	long FreeLuaScript(); //�ͷ�Lua�ű���ֻ���ͷ���Lua�ű����صĽӿڣ�

	USHORT ShortcutKey;
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
#define ALL_SHORTCUT_KEY	0xFFFF

	USHORT LimitOnePageMode; //����һҳģʽ��
	//0-����һҳ����������С���ڻ�������ߣ������������ڻ������ұߣ�
	//1-������Ƶ�����֮��ʱ���Ѻ�������С���Ƶ���������ߣ��Ѻ�����������ԭ����2����ѭ��ֱ������㻭���˻���֮�ڣ�
	//2-ͬ�ϣ�ֻ�Ǻ�����������ԭ����3��
	//n-ͬ�ϣ�ֻ�Ǻ�����������ԭ����n+1��
	//ȡֵ0-16������ֵ�����Ժ���չ

	USHORT FontPitch; //������
	USHORT ToolTipDely; //��ʾtooltip����ʱ�������λΪ���룬���Ϊ0������ʾtooltip

	//Ϊ�˼���32��64λ��д�ĸ�������������Сi��ͷ
	HWND m_iMSGRecWnd;
	void iSetFont(HFONT hFont);
	long iAddMemMainData(LPBYTE pMemMainData, long MemSize, BOOL bAddTrail);

	~CST_CurveCtrl();

	DECLARE_OLECREATE_EX(CST_CurveCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CST_CurveCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CST_CurveCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CST_CurveCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	OLE_COLOR m_foreColor;
	afx_msg void OnForeColorChanged();
	OLE_COLOR m_backColor;
	afx_msg void OnBackColorChanged();
	OLE_COLOR m_axisColor;
	afx_msg void OnAxisColorChanged();
	OLE_COLOR m_gridColor;
	afx_msg void OnGridColorChanged();
	long m_pageChangeMSG;
	afx_msg void OnPageChangeMSGChanged();
	OLE_HANDLE m_MSGRecWnd;
	afx_msg void OnMSGRecWndChanged();
	OLE_COLOR m_titleColor;
	afx_msg void OnTitleColorChanged();
	OLE_COLOR m_footNoteColor;
	afx_msg void OnFootNoteColorChanged();
	OLE_HANDLE m_register1;
	afx_msg void OnRegister1Changed();
	afx_msg BOOL SetVInterval(short VInterval);
	afx_msg BOOL SetHInterval(short HInterval);
	afx_msg short GetScaleInterval();
	afx_msg void EnableHelpTip(BOOL bEnable);
	afx_msg BOOL SetLegendSpace(short LegendSpace);
	afx_msg short GetLegendSpace();
	afx_msg BOOL SetBeginValue(float fBeginValue);
	afx_msg float GetBeginValue();
	afx_msg BOOL SetBeginTime(LPCTSTR pBeginTime);
	afx_msg BOOL SetBeginTime2(HCOOR_TYPE fBeginTime);
	afx_msg BSTR GetBeginTime();
	afx_msg HCOOR_TYPE GetBeginTime2();
	afx_msg BOOL SetTimeSpan(double TimeStep);
	afx_msg double GetTimeSpan();
	afx_msg BOOL SetValueStep(float ValueStep);
	afx_msg float GetValueStep();
	afx_msg BOOL SetVPrecision(short Precision);
	afx_msg short GetVPrecision();
	afx_msg BOOL SetUnit(LPCTSTR pUnit);
	afx_msg BSTR GetUnit();
	afx_msg void TrimCoor();
	afx_msg short AddLegend(long Address, LPCTSTR pSign, OLE_COLOR PenColor, short PenStyle, short LineWidth, OLE_COLOR BrushColor, short BrushStyle, short CurveMode, short NodeMode, short Mask, BOOL bUpdate);
	afx_msg BOOL GetLegend(LPCTSTR pSign, OLE_COLOR* pPenColor, short* pPenStyle, short* pLineWidth, OLE_COLOR* pBrushColor, short* pBrushStyle, short* pCurveMode, short* pNodeMode);
	afx_msg BSTR QueryLegend(long Address);
	afx_msg short GetLegendCount();
	afx_msg BOOL GetLegend2(short nIndex, OLE_COLOR* pPenColor, short* pPenStyle, short* pLineWidth, OLE_COLOR* pBrushColor, short* pBrushStyle, short* pCurveMode, short* pNodeMode);
	afx_msg short GetLegendIdCount(short nIndex);
	afx_msg long GetLegendId(short nIndex, short nAddressIndex);
	afx_msg BOOL DelLegend(long Address, BOOL bAll, BOOL bUpdate);
	afx_msg BOOL DelLegend2(LPCTSTR pSign, BOOL bUpdate);
	afx_msg short AddMainData(long Address, LPCTSTR pTime, float Value, short State, short VisibleState, BOOL bAddTrail);
	afx_msg short AddMainData2(long Address, HCOOR_TYPE Time, float Value, short State, short VisibleState, BOOL bAddTrail);
	afx_msg void SetVisibleCoorRange(HCOOR_TYPE MinTime, HCOOR_TYPE MaxTime, float MinValue, float MaxValue, short Mask);
	afx_msg void GetVisibleCoorRange(HCOOR_TYPE* pMinTime, HCOOR_TYPE* pMaxTime, float* pMinValue, float* pMaxValue);
	afx_msg void DelRange(long Address, HCOOR_TYPE BTime, HCOOR_TYPE ETime, short Mask, BOOL bAll, BOOL bUpdate);
	afx_msg void DelRange2(long Address, long nBegin, long nCount, BOOL bAll, BOOL bUpdate);
	afx_msg BOOL FirstPage(BOOL bLast, BOOL bUpdate);
	afx_msg short GotoPage(short RelativePage, BOOL bUpdate);
	afx_msg BOOL SetZoom(short Zoom);
	afx_msg short GetZoom();
	afx_msg BOOL SetMaxLength(long MaxLength, long CutLength);
	afx_msg long GetMaxLength();
	afx_msg long GetCutLength();
	afx_msg BOOL SetShowMode(short ShowMode);
	afx_msg short GetShowMode();
	afx_msg BOOL SetBkBitmap(short nIndex);
	afx_msg short GetBkBitmap();
	afx_msg BOOL SetFillDirection(long Address, short FillDirection, BOOL bUpdate);
	afx_msg short GetFillDirection(long Address);
	afx_msg BOOL SetMoveMode(short MoveMode);
	afx_msg short GetMoveMode();
	afx_msg void SetFont(OLE_HANDLE hFont);
	afx_msg BOOL AddImageHandle(LPCTSTR pFileName, BOOL bShared);
	afx_msg void AddBitmapHandle(OLE_HANDLE hBitmap, BOOL bShared);
	afx_msg BOOL AddBitmapHandle2(OLE_HANDLE hInstance, LPCTSTR pszResourceName, BOOL bShared);
	afx_msg BOOL AddBitmapHandle3(OLE_HANDLE hInstance, long nIDResource, BOOL bShared);
	afx_msg long GetBitmapCount();
	afx_msg BOOL SetBkMode(short BkMode);
	afx_msg short GetBkMode();
	afx_msg BOOL ExportImage(LPCTSTR pFileName);
	afx_msg long ExportImageFromPage(LPCTSTR pFileName, long Address, long nBegin, long nCount, BOOL bAll, short Style);
	afx_msg long ExportImageFromTime(LPCTSTR pFileName, long Address, HCOOR_TYPE BTime, HCOOR_TYPE ETime, short Mask, BOOL bAll, short Style);
	afx_msg BOOL BatchExportImage(LPCTSTR pFileName, long nSecond);
	afx_msg void EnableAutoTrimCoor(BOOL bEnable);
	afx_msg long ImportFile(LPCTSTR pFileName, short Style, BOOL bAddTrail);
	afx_msg BOOL GetOneTimeRange(long Address, HCOOR_TYPE* pMinTime, HCOOR_TYPE* pMaxTime);
	afx_msg BOOL GetOneValueRange(long Address, float* pMinValue, float* pMaxValue);
	afx_msg BOOL GetOneFirstPos(long Address, HCOOR_TYPE* pTime, float* pValue, BOOL bLast);
	afx_msg BOOL GetTimeRange(HCOOR_TYPE* pMinTime, HCOOR_TYPE* pMaxTime);
	afx_msg BOOL GetValueRange(float* pMinValue, float* pMaxValue);
	afx_msg void GetViableTimeRange(HCOOR_TYPE* pMinTime, HCOOR_TYPE* pMaxTime);
	afx_msg long AddMemMainData(OLE_HANDLE pMemMainData, long MemSize, BOOL bAddTrail);
	afx_msg BOOL ShowCurve(long Address, BOOL bShow);
	afx_msg void SetFootNote(LPCTSTR pFootNote);
	afx_msg BSTR GetFootNote();
	afx_msg long TrimCurve(long Address, short State, long nBegin, long nCount, short nStep, BOOL bAll);
	afx_msg short PrintCurve(long Address, HCOOR_TYPE BTime, HCOOR_TYPE ETime, short Mask, short LeftMargin, short TopMargin, short RightMargin, short BottomMargin, LPCTSTR pTitle, LPCTSTR pFootNote, short Flag, BOOL bAll);
	afx_msg long GetEventMask();
	afx_msg long GetScaleNums();
	afx_msg long ReportPageInfo();
	afx_msg BOOL ShowLegend(LPCTSTR pSign, BOOL bShow);
	afx_msg BOOL SelectCurve(long Address, BOOL bSelect);
	afx_msg short DragCurve(short xStep, short yStep, BOOL bUpdate);
	afx_msg BOOL VCenterCurve(long Address, BOOL bUpdate);
	afx_msg BOOL GetSelectedCurve(long* pAddress);
	afx_msg void EnableAdjustZOrder(BOOL bEnable);
	afx_msg BOOL IsSelected(long Address);
	afx_msg BOOL IsLegendVisible(LPCTSTR pSign);
	afx_msg BOOL IsCurveVisible(long Address);
	afx_msg BOOL IsCurveInCanvas(long Address);
	afx_msg BOOL GotoCurve(long Address);
	afx_msg void EnableZoom(BOOL bEnable);
	afx_msg long GetCurveLength(long Address);
	afx_msg BSTR GetLuaVer();
	afx_msg HCOOR_TYPE GetTimeData(short nCurveIndex, long nIndex);
	afx_msg float GetValueData(short nCurveIndex, long nIndex);
	afx_msg short GetState(short nCurveIndex, long nIndex);
	afx_msg BOOL InsertMainData(short nCurveIndex, long nIndex, LPCTSTR pTime, float Value, short State, short Position, short Mask);
	afx_msg BOOL InsertMainData2(short nCurveIndex, long nIndex, HCOOR_TYPE Time, float Value, short State, short Position, short Mask);
	afx_msg BOOL CanContinueEnum(long Address, short nCurveIndex, long nIndex);
	afx_msg BOOL DelPoint(short nCurveIndex, long nIndex);
	afx_msg short GetCurveCount();
	afx_msg long GetCurve(short nIndex);
	afx_msg BOOL RemoveBitmapHandle(OLE_HANDLE hBitmap, BOOL bDel);
	afx_msg BOOL RemoveBitmapHandle2(short nIndex, BOOL bDel);
	afx_msg OLE_HANDLE GetBitmap(short nIndex);
	afx_msg short GetBitmapState(short nIndex);
	afx_msg short GetBitmapState2(OLE_HANDLE hBitmap);
	afx_msg BOOL SetBuddy(OLE_HANDLE hBuddy, short State);
	afx_msg short GetBuddyCount();
	afx_msg OLE_HANDLE GetBuddy(short nIndex);
	afx_msg void SetCurveTitle(LPCTSTR pCurveTitle);
	afx_msg BSTR GetCurveTitle();
	afx_msg BOOL SetHUnit(LPCTSTR pHUnit);
	afx_msg BSTR GetHUnit();
	afx_msg BOOL SetHPrecision(short Precision);
	afx_msg short GetHPrecision();
	afx_msg BOOL SetCurveIndex(long Address, short nIndex);
	afx_msg short GetCurveIndex(long Address);
	afx_msg BOOL SetGridMode(short GridMode);
	afx_msg short GetGridMode();
	afx_msg void SetBenchmark(HCOOR_TYPE Time, float Value);
	afx_msg void GetBenchmark(HCOOR_TYPE* pTime, float* pValue);
	afx_msg short GetPower(long Address);
	afx_msg long TrimCurve2(long Address, short State, HCOOR_TYPE BTime, HCOOR_TYPE ETime, short Mask, short nStep, BOOL bAll);
	afx_msg BOOL ChangeId(long Address, long NewAddr);
	afx_msg BOOL CloneCurve(long Address, long NewAddr);
	afx_msg BOOL UniteCurve(long DesAddr, long nInsertPos, long Address, long nBegin, long nCount);
	afx_msg BOOL UniteCurve2(long DesAddr, long nInsertPos, long Address, HCOOR_TYPE BTime, HCOOR_TYPE ETime, short Mask);
	afx_msg BOOL UniteCurve3(long DesAddr, HCOOR_TYPE fInsertPos, long Address, long nBegin, long nCount);
	afx_msg BOOL UniteCurve4(long DesAddr, HCOOR_TYPE fInsertPos, long Address, HCOOR_TYPE BTime, HCOOR_TYPE ETime, short Mask);
	afx_msg BOOL OffSetCurve(long Address, double TimeSpan, float ValueStep, short Operator);
	afx_msg long ArithmeticOperate(long DesAddr, long Address, short Operator);
	afx_msg void ClearTempBuff();
	afx_msg BOOL PreMallocMem(long Address, long size);
	afx_msg long GetMemSize(long Address);
	afx_msg BOOL IsCurve(long Address);
	afx_msg void SetSorptionRange(short Range);
	afx_msg short GetSorptionRange();
	afx_msg BOOL IsLegend(LPCTSTR pSign);
	afx_msg short AddLegendHelper(long Address, LPCTSTR pSign, OLE_COLOR PenColor, short PenStyle, short LineWidth, BOOL bUpdate);
	afx_msg BOOL GetActualPoint(long x, long y, HCOOR_TYPE* pTime, float* pValue);
	afx_msg long GetPointFromScreenPoint(long Address, long x, long y, short MaxRange);
	afx_msg void EnableFullScreen(BOOL bEnable);
	afx_msg HCOOR_TYPE GetEndTime();
	afx_msg float GetEndValue();
	afx_msg void SetZLength(short ZLength);
	afx_msg short GetZLength();
	afx_msg BOOL SetCanvasBkBitmap(short nIndex);
	afx_msg short GetCanvasBkBitmap();;
	afx_msg void SetLeftBkColor(OLE_COLOR Color);
	afx_msg OLE_COLOR GetLeftBkColor();
	afx_msg void SetBottomBkColor(OLE_COLOR Color);
	afx_msg OLE_COLOR GetBottomBkColor();
	afx_msg BOOL SetZOffset(long Address, short nOffset, BOOL bUpdate);
	afx_msg long GetZOffset(long Address);
	afx_msg void EnableFocusState(BOOL bEnable);
	afx_msg BOOL SetReviseToolTip(short Type);
	afx_msg short GetReviseToolTip();
	afx_msg long ExportMetaFile(LPCTSTR pFileName, long Address, long nBegin, long nCount, BOOL bAll, short Style);
	afx_msg void LimitOnePage(BOOL bLimit);
	afx_msg BOOL FixCoor(HCOOR_TYPE MinTime, HCOOR_TYPE MaxTime, float MinValue, float MaxValue, short Mask);
	afx_msg short GetFixCoor(HCOOR_TYPE* pMinTime, HCOOR_TYPE* pMaxTime, float* pMinValue, float* pMaxValue);
	afx_msg BOOL RefreshLimitedOrFixedCoor();
	afx_msg BOOL SetCanvasBkMode(short CanvasBkMode);
	afx_msg short GetCanvasBkMode();
	afx_msg void EnablePreview(BOOL bEnable);
	afx_msg void SetWaterMark(LPCTSTR pWaterMark);
	afx_msg long GetSysState();
	afx_msg void SetTension(float Tension);
	afx_msg float GetTension();
	afx_msg OLE_HANDLE GetFont();
	afx_msg BOOL SetXYFormat(LPCTSTR pSign, short Format);
	afx_msg short GetXYFormat(LPCTSTR pSign);
	afx_msg short GetXYFormat2(short nIndex);
	afx_msg long LoadPlugIn(LPCTSTR pFileName, short Type, long Mask);
	afx_msg BOOL AppendLegendEx(LPCTSTR pSign, OLE_COLOR BeginNodeColor, OLE_COLOR EndNodeColor, OLE_COLOR SelectedNodeColor, short NodeModeEx);
	afx_msg BOOL GetLegendEx(LPCTSTR pSign, OLE_COLOR* pBeginNodeColor, OLE_COLOR* pEndNodeColor, OLE_COLOR* pSelectedNodeColor, short* pNodeModeEx);
	afx_msg BOOL GetLegendEx2(short nIndex, OLE_COLOR* pBeginNodeColor, OLE_COLOR* pEndNodeColor, OLE_COLOR* pSelectedNodeColor, short* pNodeModeEx);
	afx_msg long GetSelectedNodeIndex(long Address);
	afx_msg BOOL SetSelectedNodeIndex(long Address, long NewNodeIndex);
	afx_msg long LoadLuaScript(LPCTSTR pFileName, short Type, long Mask);
	afx_msg void SetShortcutKeyMask(long ShortcutKey);
	afx_msg long GetShortcutKeyMask();
	afx_msg OLE_HANDLE GetFrceHDC();
	afx_msg BOOL SetBottomSpace(short Space);
	afx_msg short GetBottomSpace();
	afx_msg BSTR GetEndTime2();
	afx_msg BSTR GetTimeData2(short nCurveIndex, long nIndex);
	afx_msg short AddComment(HCOOR_TYPE Time, float Value, short Position, short nBkBitmap, short Width, short Height, OLE_COLOR TransColor, LPCTSTR pComment, OLE_COLOR TextColor, short XOffSet, short YOffSet, BOOL bUpdate);
	afx_msg BOOL DelComment(long nIndex, BOOL bAll, BOOL bUpdate);
	afx_msg long GetCommentNum();
	afx_msg BOOL GetComment(long nIndex, HCOOR_TYPE* pTime, float* pValue, short* pPosition, short* pBkBitmap, short* pWidth, short* pHeight, OLE_COLOR* pTransColor, BSTR* pComment, OLE_COLOR* pTextColor, short* pXOffSet, short* pYOffSet);
	afx_msg short SetComment(long nIndex, HCOOR_TYPE Time, float Value, short Position, short nBkBitmap, short Width, short Height, OLE_COLOR TransColor, LPCTSTR pComment, OLE_COLOR TextColor, short XOffSet, short YOffSet, short Mask, BOOL bUpdate);
	afx_msg BOOL SwapCommentIndex(long nIndex, long nOldIndex, BOOL bUpdate);
	afx_msg BOOL ShowComment(long nIndex, BOOL bShow, BOOL bUpdate);
	afx_msg BOOL IsCommentVisiable(long nIndex);
	afx_msg void SetEventMask(long Event);
	afx_msg BOOL SetFixedZoomMode(short ZoomMode);
	afx_msg short GetFixedZoomMode();
	afx_msg BOOL FixedZoom(short ZoomMode, short x, short y, BOOL bHoldMode);
	afx_msg BOOL SetCommentPosition(short Position);
	afx_msg short GetCommentPosition();
	afx_msg BOOL GetPixelPoint(HCOOR_TYPE Time, float Value, long* px, long* py);
	afx_msg BOOL GetMemInfo(long* pTempBuffSize, long* pAllBuffSize, float* pUseRate, long* pAddress);
	afx_msg BOOL IsCurveClosed(long Address);
	afx_msg BOOL GetPosData(short nCurveIndex, long nIndex, long* px, long* py);
	afx_msg void EnableHZoom(BOOL bEnable);
	afx_msg BOOL SetHZoom(short Zoom);
	afx_msg short GetHZoom();
	afx_msg BOOL MoveCurveToLegend(long Address, LPCTSTR pSign);
	afx_msg BOOL ChangeLegendName(LPCTSTR pFrom, LPCTSTR pTo);
	afx_msg BOOL SetAutoRefresh(short TimeInterval, short NumInterval);
	afx_msg long GetAutoRefresh();
	afx_msg void EnableSelectCurve(BOOL bEnable);
	afx_msg void SetToolTipDelay(short Delay);
	afx_msg short GetToolTipDelay();
	afx_msg BOOL SetLimitOnePageMode(short Mode);
	afx_msg short GetLimitOnePageMode();
	afx_msg BOOL AddInfiniteCurve(long Address, HCOOR_TYPE Time, float Value, short State, BOOL bUpdate);
	afx_msg BOOL DelInfiniteCurve(long Address, BOOL bAll, BOOL bUpdate);
	afx_msg BOOL SetGraduationSize(long size);
	afx_msg long GetGraduationSize();
	afx_msg void SetMouseWheelMode(short Mode);
	afx_msg short GetMouseWheelMode();
	afx_msg BOOL SetMouseWheelSpeed(short Speed);
	afx_msg short GetMouseWheelSpeed();
	afx_msg BOOL SetHLegend(LPCTSTR pHLegend);
	afx_msg BSTR GetHLegend();
	DECLARE_DISPATCH_MAP()

// �¼�ӳ��
	void FirePageChange(long wParam, long lParam)
		{FireEvent(eventidPageChange,EVENT_PARAM(VTS_I4 VTS_I4), wParam, lParam);}
	void FireBeginTimeChange(HCOOR_TYPE NewTime)
		{FireEvent(eventidBeginTimeChange,EVENT_PARAM(HCOOR_VTS_TYPE), NewTime);}
	void FireBeginValueChange(float NewValue)
		{FireEvent(eventidBeginValueChange,EVENT_PARAM(VTS_R4), NewValue);}
	void FireTimeSpanChange(double NewTimeSpan)
		{FireEvent(eventidTimeSpanChange,EVENT_PARAM(VTS_R8), NewTimeSpan);}
	void FireValueStepChange(float NewValueStep)
		{FireEvent(eventidValueStepChange,EVENT_PARAM(VTS_R4), NewValueStep);}
	void FireZoomChange(short NewZoom)
		{FireEvent(eventidZoomChange,EVENT_PARAM(VTS_I2), NewZoom);}
	void FireSelectedCurveChange(long NewAddr)
		{FireEvent(eventidSelectedCurveChange,EVENT_PARAM(VTS_I4), NewAddr);}
	void FireLegendVisableChange(long nIndex, short State)
		{FireEvent(eventidLegendVisableChange,EVENT_PARAM(VTS_I4 VTS_I2), nIndex, State);}
	void FireSorptionChange(long Address, long nIndex, short State)
		{FireEvent(eventidSorptionChange,EVENT_PARAM(VTS_I4 VTS_I4 VTS_I2), Address, nIndex, State);}
	void FireCurveStateChange(long Address, short State)
		{FireEvent(eventidCurveStateChange,EVENT_PARAM(VTS_I4 VTS_I2), Address, State);}
	void FireZoomModeChange(short NewMode)
		{FireEvent(eventidZoomModeChange,EVENT_PARAM(VTS_I2), NewMode);}
	void FireHZoomChange(short NewZoom)
		{FireEvent(eventidHZoomChange,EVENT_PARAM(VTS_I2), NewZoom);}
	void FireBatchExportImageChange(long FileNameIndex)
		{FireEvent(eventidBatchExportImageChange,EVENT_PARAM(VTS_I4), FileNameIndex);}
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
		dispidForeColor = 1L,
		dispidBackColor = 2L,
		dispidAxisColor = 3L,
		dispidGridColor = 4L,
		dispidPageChangeMSG = 5L,
		dispidMSGRecWnd = 6L,
		dispidTitleColor = 7L,
		dispidFootNoteColor = 8L,
		dispidSetVInterval = 9L,
		dispidSetHInterval = 10L,
		dispidGetScaleInterval = 11L,
		dispidEnableHelpTip = 12L,
		dispidSetLegendSpace = 13L,
		dispidGetLegendSpace = 14L,
		dispidSetBeginValue = 15L,
		dispidGetBeginValue = 16L,
		dispidSetBeginTime = 17L,
		dispidSetBeginTime2 = 18L,
		dispidGetBeginTime = 19L,
		dispidGetBeginTime2 = 20L,
		dispidSetTimeSpan = 21L,
		dispidGetTimeSpan = 22L,
		dispidSetValueStep = 23L,
		dispidGetValueStep = 24L,
		dispidSetVPrecision = 25L,
		dispidGetVPrecision = 26L,
		dispidSetUnit = 27L,
		dispidGetUnit = 28L,
		dispidTrimCoor = 29L,
		dispidAddLegend = 30L,
		dispidGetLegend = 31L,
		dispidQueryLegend = 32L,
		dispidGetLegendCount = 33L,
		dispidGetLegend2 = 34L,
		dispidGetLegendIdCount = 35L,
		dispidGetLegendId = 36L,
		dispidDelLegend = 37L,
		dispidDelLegend2 = 38L,
		dispidAddMainData = 39L,
		dispidAddMainData2 = 40L,
		dispidSetVisibleCoorRange = 41L,
		dispidGetVisibleCoorRange = 42L,
		dispidDelRange = 43L,
		dispidDelRange2 = 44L,
		dispidFirstPage = 45L,
		dispidGotoPage = 46L,
		dispidSetZoom = 47L,
		dispidGetZoom = 48L,
		dispidSetMaxLength = 49L,
		dispidGetMaxLength = 50L,
		dispidGetCutLength = 51L,
		dispidSetShowMode = 52L,
		dispidGetShowMode = 53L,
		dispidSetBkBitmap = 54L,
		dispidGetBkBitmap = 55L,
		dispidSetFillDirection = 56L,
		dispidGetFillDirection = 57L,
		dispidSetMoveMode = 58L,
		dispidGetMoveMode = 59L,
		dispidSetFont = 60L,
		dispidAddImageHandle = 61L,
		dispidAddBitmapHandle = 62L,
		dispidAddBitmapHandle2 = 63L,
		dispidAddBitmapHandle3 = 64L,
		dispidGetBitmapCount = 65L,
		dispidSetBkMode = 66L,
		dispidGetBkMode = 67L,
		dispidExportImage = 68L,
		dispidExportImageFromPage = 69L,
		dispidExportImageFromTime = 70L,
		dispidBatchExportImage = 71L,
		dispidEnableAutoTrimCoor = 72L,
		dispidImportFile = 73L,
		//74L ��Դ֮�󣬲���ʹ��
		dispidGetOneTimeRange = 75L,
		dispidGetOneValueRange = 76L,
		dispidGetOneFirstPos = 77L,
		dispidGetTimeRange = 78L,
		dispidGetValueRange = 79L,
		dispidGetViableTimeRange = 80L,
		dispidAddMemMainData = 81L,
		dispidShowCurve = 82L,
		//83L ��Դ֮�󣬲���ʹ��
		dispidSetFootNote = 84L,
		dispidGetFootNote = 85L,
		dispidTrimCurve = 86L,
		dispidPrintCurve = 87L,
		dispidGetEventMask = 88L,
		dispidGetScaleNums = 89L,
		dispidReportPageInfo = 90L,
		dispidShowLegend = 91L,
		dispidSelectCurve = 92L,
		dispidDragCurve = 93L,
		dispidVCenterCurve = 94L,
		dispidGetSelectedCurve = 95L,
		dispidEnableAdjustZOrder = 96L,
		dispidIsSelected = 97L,
		dispidIsLegendVisible = 98L,
		dispidIsCurveVisible = 99L,
		dispidIsCurveInCanvas = 100L,
		dispidGotoCurve = 101L,
		dispidEnableZoom = 102L,
		dispidGetCurveLength = 103L,
		dispidGetLuaVer = 104L,
		dispidGetTimeData = 105L,
		dispidGetValueData = 106L,
		dispidGetState = 107L,
		dispidInsertMainData = 108L,
		dispidInsertMainData2 = 109L,
		dispidCanContinueEnum = 110L,
		dispidDelPoint = 111L,
		dispidGetCurveCount = 112L,
		dispidGetCurve = 113L,
		dispidRemoveBitmapHandle = 114L,
		dispidRemoveBitmapHandle2 = 115L,
		dispidGetBitmap = 116L,
		dispidGetBitmapState = 117L,
		dispidGetBitmapState2 = 118L,
		dispidSetBuddy = 119L,
		dispidGetBuddyCount = 120L,
		dispidGetBuddy = 121L,
		dispidSetCurveTitle = 122L,
		dispidGetCurveTitle = 123L,
		dispidSetHUnit = 124L,
		dispidGetHUnit = 125L,
		dispidSetHPrecision = 126L,
		dispidGetHPrecision = 127L,
		dispidSetCurveIndex = 128L,
		dispidGetCurveIndex = 129L,
		dispidSetGridMode = 130L,
		dispidGetGridMode = 131L,
		dispidSetBenchmark = 132L,
		dispidGetBenchmark = 133L,
		dispidGetPower = 134L,
		dispidTrimCurve2 = 135L,
		dispidChangeId = 136L,
		dispidCloneCurve = 137L,
		dispidUniteCurve = 138L,
		dispidUniteCurve2 = 139L,
		dispidUniteCurve3 = 140L,
		dispidUniteCurve4 = 141L,
		dispidOffSetCurve = 142L,
		dispidArithmeticOperate = 143L,
		dispidClearTempBuff = 144L,
		dispidPreMallocMem = 145L,
		dispidGetMemSize = 146L,
		dispidIsCurve = 147L,
		dispidSetSorptionRange = 148L,
		dispidGetSorptionRange = 149L,
		dispidIsLegend = 150L,
		dispidAddLegendHelper = 151L,
		dispidGetActualPoint = 152L,
		dispidGetPointFromScreenPoint = 153L,
		dispidEnableFullScreen = 154L,
		dispidGetEndTime = 155L,
		dispidGetEndValue = 156L,
		dispidSetZLength = 157L,
		dispidGetZLength = 158L,
		dispidSetCanvasBkBitmap = 159L,
		dispidGetCanvasBkBitmap = 160L,
		dispidSetLeftBkColor = 161L,
		dispidGetLeftBkColor = 162L,
		dispidSetBottomBkColor = 163L,
		dispidGetBottomBkColor = 164L,
		dispidSetZOffset = 165L,
		dispidGetZOffset = 166L,
		dispidEnableFocusState = 167L,
		dispidSetReviseToolTip = 168L,
		dispidGetReviseToolTip = 169L,
		dispidExportMetaFile = 170L,
		dispidLimitOnePage = 171L,
		dispidFixCoor = 172L,
		dispidGetFixCoor = 173L,
		dispidRefreshLimitedOrFixedCoor = 174L,
		dispidSetCanvasBkMode = 175L,
		dispidGetCanvasBkMode = 176L,
		dispidEnablePreview = 177L,
		dispidSetWaterMark = 178L,
		dispidGetSysState = 179L,
		dispidSetTension = 180L,
		dispidGetTension = 181L,
		dispidGetFont = 182L,
		dispidSetXYFormat = 183L,
		dispidGetXYFormat = 184L,
		dispidGetXYFormat2 = 185L,
		dispidLoadPlugIn = 186L,
		dispidAppendLegendEx = 187L,
		dispidGetLegendEx = 188L,
		dispidGetLegendEx2 = 189L,
		dispidGetSelectedNodeIndex = 190L,
		dispidSetSelectedNodeIndex = 191L,
		dispidLoadLuaScript = 192L,
		dispidSetShortcutKeyMask = 193L,
		dispidGetShortcutKeyMask = 194L,
		dispidGetFrceHDC = 195L,
		dispidSetBottomSpace = 196L,
		dispidGetBottomSpace = 197L,
		dispidGetEndTime2=198L,
		dispidGetTimeData2 = 199L,
		dispidAddComment = 200L,
		dispidDelComment = 201L,
		dispidGetCommentNum = 202L,
		dispidGetComment = 203L,
		dispidSetComment = 204L,
		dispidSwapCommentIndex = 205L,
		dispidShowComment = 206L,
		dispidIsCommentVisiable = 207L,
		dispidSetEventMask = 208L,
		dispidSetFixedZoomMode = 209L,
		dispidGetFixedZoomMode = 210L,
		dispidFixedZoom = 211L,
		dispidSetCommentPosition = 212L,
		dispidGetCommentPosition = 213L,
		dispidGetPixelPoint = 214L,
		dispidGetMemInfo = 215L,
		dispidIsCurveClosed = 216L,
		dispidGetPosData = 217L,
		dispidEnableHZoom = 218L,
		dispidSetHZoom = 219L,
		dispidGetHZoom = 220L,
		dispidMoveCurveToLegend = 221L,
		dispidChangeLegendName = 222L,
		dispidSetAutoRefresh = 223L,
		dispidGetAutoRefresh = 224L,
		dispidEnableSelectCurve = 225L,
		dispidSetToolTipDelay = 226L,
		dispidGetToolTipDelay = 227L,
		dispidSetLimitOnePageMode = 228L,
		dispidGetLimitOnePageMode = 229L,
		dispidAddInfiniteCurve = 230L,
		dispidDelInfiniteCurve = 231L,
		dispidRegister1 = 232L,
		dispidSetGraduationSize = 233L,
		dispidGetGraduationSize = 234L,
		dispidSetMouseWheelMode = 235L,
		dispidGetMouseWheelMode = 236L,
		dispidSetMouseWheelSpeed = 237L,
		dispidGetMouseWheelSpeed = 238L,
		dispidSetHLegend = 239L,
		dispidGetHLegend = 240L,
		eventidPageChange = 1L,
		eventidBeginTimeChange = 2L,
		eventidBeginValueChange = 3L,
		eventidTimeSpanChange = 4L,
		eventidValueStepChange = 5L,
		eventidZoomChange = 6L,
		eventidSelectedCurveChange = 7L,
		eventidLegendVisableChange = 8L,
		eventidSorptionChange = 9L,
		eventidCurveStateChange = 10L,
		eventidZoomModeChange = 11L,
		eventidHZoomChange = 12L,
		eventidBatchExportImageChange = 13L,
	};
};

