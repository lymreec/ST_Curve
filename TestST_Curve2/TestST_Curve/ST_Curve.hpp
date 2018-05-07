#if !defined(AFX_ST_CURVE_HPP__A736A297_FA0A_4cf1_BA9B_E12251C13461__INCLUDED_)
#define AFX_ST_CURVE_HPP__A736A297_FA0A_4cf1_BA9B_E12251C13461__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ST_Curve.hpp : header file
//

#pragma comment(lib, "ST_Curve.lib")

/*===============================================================================
��������GetDIBFromDDB
������hDC       �豸���������Ϊ0
	  hBitmap   DDBλͼ���
����ֵ��LPBITMAPINFO����ָ�룬���Ϊ0����ʧ��
�������ܼ��÷���
ͨ��λͼ�����DDB���õ�DIB���ݣ��������ִ�гɹ��������߸����ͷ��ڴ棬��ʽ���£�
LocalFree((HLOCAL) lpbi); //lpbiΪ�������ķ���ֵ
===============================================================================*/
extern "C"
__declspec(dllimport) LPBITMAPINFO __stdcall GetDIBFromDDB(HDC hDC/*[in]*/, HBITMAP hBitmap/*[in]*/);

/*===============================================================================
��������ExportBMP
������hBitmap   DDBλͼ���
	  pFileName ָ���ļ��������Ϊ�գ����ؼ������ļ�ѡ����û�ѡ��
����ֵ�������ɹ�������ʧ�ܡ�
�������ܼ��÷���
��DDBλͼ���浽�ļ��У�ͼ���ʽ��꡾�����֧��bmp png jpg gif�ȸ�ʽ
ע��ֻ�ṩUNICODE�棨��Ϊ�ؼ�ֻ�ṩUNICODE�棩�����Ҫ��mbcs����ʹ�ã���Ҫ���ַ���ת��
===============================================================================*/
extern "C"
__declspec(dllimport) BOOL __stdcall ExportBMP(HBITMAP hBitmap/*[in]*/, const unsigned short* pFileName/*[in]*/);

/*===============================================================================
��������CheckUpdate
������pHomePage   ���ڽ��չٷ���ҳ������Ҫ����NULL
	  pVersion	  ���ڽ��հ汾�ţ�����Ҫ����NULL
	  pModifyTime ���ڽ����޸�ʱ�䣬����Ҫ����NULL
����ֵ��-2 δ֪���ϣ��ٷ���ҳ���ܱ����ˣ�-1 ������ϣ�0 �ɹ������޸��£�1 �ɹ������и���
�������ܼ��÷���
���ؼ��Ƿ��и��£����������ٷ���ҳ��ַ���汾���Լ��ؼ����޸�ʱ��
===============================================================================*/
extern "C"
__declspec(dllimport) int __stdcall CheckUpdate(BSTR FAR* pHomePage/*[out]*/, BSTR FAR* pVersion/*[out]*/, BSTR FAR* pModifyTime/*[out]*/);

#endif // !defined(AFX_ST_CURVE_HPP__A736A297_FA0A_4cf1_BA9B_E12251C13461__INCLUDED_)