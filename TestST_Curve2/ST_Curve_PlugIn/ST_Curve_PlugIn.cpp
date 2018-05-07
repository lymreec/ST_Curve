// ST_Curve_PlugIn.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include <tchar.h>
#include <assert.h>
#include <atlbase.h>
#include "ST_Curve_PlugIn.h"
#include "..\TestST_Curve\ST_Curve_PlugIn.hpp"

//ע���ڷ�UNICODE�汾�£������̽��޷�ͨ�����룬��Ҫ�����޸�ST_Curve_PlugIn.hpp��������ܹ�
//������ˣ�Ҳ�޷�ʹ�ã���ΪST_Curveֻ�ṩunicode�汾�������COM��dll�ı׶˵õ������ˣ�
TCHAR PlugInBuff[128];
//��TCHAR��Ŀ�����ñ������ڷ�unicode�汾�£��޷�ͨ������

/*
extern "C"
__declspec(dllexport) LPCWSTR FormatXCoordinate(long Address, double DateTime, UINT Action)
{
	switch(Action)
	{
	case 1: //���������Ὺʼ
		break;
	case 2: //���������������
		_stprintf(PlugInBuff, _T("%.2f\n����X������"), DateTime);
		break;
	case 3: //�������������
		break;
	case 4: //��ʾ������ʾ��Tooltip��
		_stprintf(PlugInBuff, _T("%.2f X������ʾ"), DateTime);
		break;
	case 5: //��������
		_stprintf(PlugInBuff, _T("%.2f ����X����"), DateTime);
		break;
	case 6: //����Y��λ��ʱ���ã����ᱻ����
		break;
	case 7: //�������ֵ�����ᱻ����
		break;
	default:
		*PlugInBuff = 0;
		break;
	}

	return PlugInBuff;
}
*/
//���������ʾ���ò���ļ��ɣ��ú����겻���ڶ������ű����£���ʾ��һ��
extern "C"
__declspec(dllexport) LPCWSTR FormatXCoordinate(long Address, DATE DateTime, UINT Action)
{
	static int nTimes = -1;
	switch(Action)
	{
	case 1: //���������Ὺʼ
		nTimes = 0;
		break;
	case 2: //���������������
		assert(nTimes >= 0);
		_stprintf_s(PlugInBuff, _T("��%d��\n��%d��"), ++nTimes, nTimes);
		break;
	case 3: //�������������
		nTimes = -1;
		break;
	case 4: //��ʾ������ʾ��Tooltip��
		_stprintf_s(PlugInBuff, _T("%.2f X������ʾ(dll)"), DateTime);
//		*PlugInBuff = 0; //����ʾ��tooltip
		break;
	case 5: //��������
		_stprintf_s(PlugInBuff, _T("%.2f ����X����"), DateTime);
		break;
	case 6: //����Y��λ�ã����ᱻ����
	case 7: //�������ֵ�����ᱻ����
		break;
	default:
		*PlugInBuff = 0;
		break;
	}

	return PlugInBuff;
}

extern "C"
__declspec(dllexport) LPCWSTR FormatYCoordinate(long Address, float Value, UINT Action)
{
	switch(Action)
	{
	case 1: //���������Ὺʼ
		break;
	case 2: //���������������
		_stprintf_s(PlugInBuff, _T("%.2f ����Y������"), Value);
		break;
	case 3: //�������������
		break;
	case 4: //��ʾ������ʾ��Tooltip��
//		_stprintf(PlugInBuff, _T("%.2f Y������ʾ"), Value);
		*PlugInBuff = 0; //����ʾ��tooltip
		break;
	case 5: //��������
		_stprintf_s(PlugInBuff, _T("%.2f ����Y����"), Value);
		break;
	case 6: //����Y��λ��ʱ����
		_stprintf_s(PlugInBuff, _T("%.2f ����Y������"), Value);
		/*
		������һ�����ɣ����ﷵ�ص��ַ�������������������һ�����ȣ��Ա�ȷ��Y���λ��
		��������ȫ���Է��������ַ�������Ϊ�����������������ģ��ַ������ݲ�û��ʲô����
		����������ɣ�����������ﷵ�غ㶨���ַ��������䳤��Ҳ���Ǻ㶨�ģ�����Y�����ʾλ��Ҳ���Ǻ㶨����
		�㻹���Է��ر�Action����2ʱ���ص��ַ�������������������Y������Y��ճ���һ���ľ���
		*/
		break;
	case 7: //�������ֵ
		_stprintf_s(PlugInBuff, _T("%.0f"), Value); //���۾����Ƕ��٣�����ʾ������λ
		break;
	default:
		*PlugInBuff = 0;
		break;
	}

	return PlugInBuff;
}

extern "C"
__declspec(dllexport) DATE TrimXCoordinate(DATE DateTime) //���2
{
	//����ǿؼ��ڲ���ʵ�֣��ڲ��������Ȼ����ʵ�֣���Ϊ�˺���ǰ���ݣ�
	//���ο�������ȫ���������޸�
	_sntprintf_s(PlugInBuff, 128, _T("%.0f"), DateTime + .5); //����������
	USES_CONVERSION;
	return atof(T2A(PlugInBuff));
}

extern "C"
__declspec(dllexport) float TrimYCoordinate(float Value)  //���3
{
	//����ǿؼ��ڲ���ʵ�֣��ڲ��������Ȼ����ʵ�֣���Ϊ�˺���ǰ���ݣ�
	//���ο�������ȫ���������޸�
	_sntprintf_s(PlugInBuff, 128, _T("%.0f"), Value + .5f); //����������
	USES_CONVERSION;
	return (float) atof(T2A(PlugInBuff));
}

//����ǿؼ��ڲ���ʵʩ���ŵ�ʵ�֣��ڲ��������Ȼ����ʵ�֣���Ϊ�˺���ǰ���ݣ�
//���ο�������ȫ���������޸�
#define GETSTEP(V, ZOOM) (!(ZOOM) ? V : ((ZOOM) > 0 ? V / ((ZOOM) * .25f + 1) : V * (-(ZOOM) * .25f + 1)))

extern "C"
__declspec(dllexport) double CalcTimeSpan(double TimeSpan, short Zoom, short HZoom) //���4
{
	//������ʾһ����̬�÷����������ź����꣬����ʾ�����ʽ�������
	return TimeSpan;
	//�����ǿؼ����ݵ�Ĭ��ʵ��
//	return GETSTEP(TimeSpan, Zoom + HZoom);
}

extern "C"
__declspec(dllexport) float CalcValueStep(float ValueStep, short Zoom)  //���5
{
	//��������������ʾһ���Զ��������ٶȣ����Ŵ�ʱ�����ǷŴ�Zoom���������ǿؼ�Ĭ�ϵ�1/4��
	return Zoom > 0 ? ValueStep / (Zoom + 1) : ValueStep * (-Zoom + 1);
	//�����ǿؼ����ݵ�Ĭ��ʵ��
//	return GETSTEP(ValueStep, Zoom);
}
