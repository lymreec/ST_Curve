
#include "conf.h"

#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*�Ѿ�������Ӵ˹��ܣ���Ϊ���ο�������ʵ�ִ˹��ܽ����ӵ�������
//�ƶ�������Ҫ�����ݽṹ
typedef struct tagMoveBuddy
{
	HWND hBuddy; //�����
	BYTE Relation;
//	�ӵ�λ��
//	1�������ڶ�����hBuddy�ײ�������2�������ڵײ���hBuddy������������ʱ�����ڵ����š�������Ϊ�෴
//	3�������ڶ�����hBuddy����������4�������ڵײ���hBuddy�ײ���������ʱ�����ڵ����š�������Ϊ��ͬ
	DWORD MaxExpand; //���š��������ֵ���ο�SetMoveBuddy��MaxExpand
	short CurExpand; //��ǰ�����š�����ֵ�����Ǵ�������״̬�����Ǵ�������״̬��0�Ǵ���ԭʼ״̬
	RECTS rect; //����϶�����������θ߶���ʱȷ��Ϊ3������
}MoveBuddy;
*/

//ͼ�����ݽṹ
typedef struct tagLegendData //ռ��16�ֽڣ������Ա��λ����֯�Ĳ��ã���ռ��40�ֽ����ϣ��޸ĵ�ʱ��ע�⣬����ṹû���κ�����ֽ�
{
	tagLegendData(LPCTSTR _pSign){ASSERT(_pSign); auto len = _tcslen(_pSign) + 1; pSign = new TCHAR[len]; _tcscpy_s(pSign, len, _pSign);}

	vector<long> Addrs; //ռ16�ֽ�
	LPTSTR pSign;
	short SignWidth; //ͼ�����ִ�ӡʱռ�Ŀ�ȣ������أ��������ַ�������

	//��������BYTE���ǰ���short���µĶ���ռ�
	BYTE PenStyle; //������ʽ���ο�CreatePen����
	BYTE LineWidth; //���ʿ��
	COLORREF PenColor; //������ɫ

	COLORREF BrushColor; //��ˢ��ɫ
	BYTE BrushStyle; //���������������Ļ�ˢ
	//255������䣻127��solid brush��ʽ���ο�CreateSolidBrush��������ɫΪBrushColor
	//0-126��hatch brush��ʽ���ο�CreateHatchBrush��������ɫΪBrushColor
	//128-254��pattern brush��ʽ���ο�CreatePatternBrush������(BrushStyle - 128)��Ϊλͼ��BitBmps��������

	BYTE CurveMode; //������ۣ�0��Ĭ����ۣ�����֮����ֱ��������1���ȴ�ֱ��ˮƽ�ķ�����2����ˮƽ��ֱ�ķ�����3��������������
	BYTE NodeModeEx : 4; //��λ�㣬�ӵ�λ��1-�Ƿ���ʾͷ�ڵ㣻2-�Ƿ���ʾβ�ڵ㣻3-�Ƿ���ʾѡ�е㣻
	BYTE NodeMode : 4; //0������ʾ�ڵ㣻1��������ɫ��ʾ�ڵ㣻2��������ɫ�ķ�ɫ��ʾ�ڵ�
	BYTE Lable : 7; //�������㣬�ӵ�λ��1-�Ƿ���ʾXֵ��2-�Ƿ���ʾYֵ��3-�Ƿ����ص�λ��4-�Ƿ���ʾ����
	BYTE State : 1; //Ϊ1��������ʾ״̬��Ϊ0����ʾ

	COLORREF BeginNodeColor; //��ʼ��ڵ���ɫ���Ƿ�ʹ��Ҫ��NodeModeEx
	COLORREF EndNodeColor; //������ڵ���ɫ���Ƿ�ʹ��Ҫ��NodeModeEx
	COLORREF SelectedNodeColor; //��ѡ�е����ɫ

	bool operator ==(LPCTSTR _pSign){return 0 == _tcscmp(pSign, _pSign);}
	bool operator ==(const tagLegendData& _LegendData){return this == &_LegendData;}
	bool operator !=(const tagLegendData& _LegendData){return !(*this == _LegendData);}
	bool operator ==(const tagLegendData* pLegendData){return this == pLegendData;}
	bool operator !=(const tagLegendData* pLegendData){return !(this == pLegendData);}
	operator LPCTSTR(){return pSign;}
	operator COLORREF(){return PenColor;}
}LegendData;

typedef struct tagActualPoint
{
	HCOOR_TYPE Time;
	float Value;
}ActualPoint;

//�������ݽṹ
typedef struct tagOrigMainData //��Ҫ��ActualPoint�̳У����ṹռ���ڴ�16�ֽڣ������ActualPoint�̳У���ռ���ڴ��24�ֽڣ���ΪActualPoint��ռ��16�ֽ�
{
	//����������Ա��λ�ú���Ҫ���ο�WriteFile�������ڵ���λ�õ�ʱ��һ��Ҫע���ڴ�ռ��������Ҫ�ǿ��Ƕ����������䣩����Ϊ������ṹ��������������������
	HCOOR_TYPE Time;
	float Value;
	union
	{
		struct {
			//״̬��
			//0����ͨ�㣬��˼�����Ƿ�����״̬
			//1���ϵ㣬������������ĵ�����
			//2�����ظõ㣨ǰһ�㽫�ͺ�һ��ֱ�����ӣ��൱��û������㣩
			BYTE State;
			//��λ�㣺
			//��1λ������ʾ�ڵ㣬����ͼ��ָʾ��Ҫ��ʾ
			//�����Ժ��д���չ
			BYTE StateEx;
		};
		USHORT AllState;
	};
	USHORT Reserved;

	operator HCOOR_TYPE(){return Time;}
	operator float(){return Value;}
	bool operator ==(const tagOrigMainData& _OrigMainData){return this == &_OrigMainData;}
	bool operator !=(const tagOrigMainData& _OrigMainData){return !(*this == _OrigMainData);}
	bool operator ==(const tagOrigMainData* pOrigMainData){return this == pOrigMainData;}
	bool operator !=(const tagOrigMainData* pOrigMainData){return !(this == pOrigMainData);}
	bool operator >=(const tagOrigMainData& _OrigMainData){return Time >= _OrigMainData.Time;}
	bool operator <=(const tagOrigMainData& _OrigMainData){return Time <= _OrigMainData.Time;}
}OrigMainData;

typedef struct tagMainData : OrigMainData //�����ļ̳й�ϵ����������������䣨�����������䣩
{
	POINT ScrPos; //����Ļ�ϵ�����
}MainData;

#define CommentLen	64
typedef struct tagCommentData : tagMainData
{
	short nBkBitmap; //-1��ʹ�ñ���
	char XOffSet; //����ƫ����
	char YOffset; //����ƫ����
	COLORREF TransColor; //λͼ�е���͸���������ɫ
	COLORREF TextColor : 24; //������ɫ
	COLORREF Position : 7; //0-���Ͻ� 1-���½� 2-���Ͻ� 3-���½� 4-���ģ�������BYTE�������ͼ��ɣ���Ϊ�˷���TextColorʣ���һ���ֽڣ�ֻ��������COLORREF��
	COLORREF State : 1; //Ϊ1��������ʾ״̬��Ϊ0����ʾ
	short Width; //ע�����ʾ���
	short Height; //ע�����ʾ�߶�
	TCHAR Comment[CommentLen];
}CommentData;

typedef struct tagBitBmp
{
	HBITMAP hBitBmp;
	UINT State; //�ӵ�λ�𣬵�1λ���Ƿ�Ϊ������ʱ���Զ��ͷž��������2λ���Ƿ�Ϊ�ؼ�������λͼ���
	//������Ϊ�ؼ����������򲻹��Ƿ�Ϊ���������ɿؼ����ͷž���������������ɿؼ���������ؼ�ֻ�ڷǹ����������ͷž��

	operator HBITMAP(){return hBitBmp;}
	operator UINT(){return State;}
	bool operator ==(const HBITMAP hBitBmp){return this->hBitBmp == hBitBmp;}
	bool operator !=(const HBITMAP hBitBmp){return !(*this == hBitBmp);}
	bool operator ==(const tagBitBmp& _BitBmp){return this->hBitBmp == _BitBmp.hBitBmp;}
	bool operator !=(const tagBitBmp& _BitBmp){return !(*this == _BitBmp);}
	bool operator ==(const tagBitBmp* pBitBmp){return this->hBitBmp == pBitBmp->hBitBmp;}
	bool operator !=(const tagBitBmp* pBitBmp){return !(this == pBitBmp);}
}BitBmp;
/*
template <typename T = HCOOR_TYPE>
class IsInRange
{
public:
	IsInRange(T Min, T Max){ASSERT(Min <= Max); this->Min = Min; this->Max = Max;}
	bool operator()(const T Value){return Min <= Value && Value <= Max;}
protected:
	T Min, Max;
};
*/
/*
������������ڽ��vc2010���棬��������δ��ʼ��������֮���==�Ƚ�ʱ�����Ķ��Դ���
����������==���������ֻ������ߣ���������Ĵ����ǲ��еģ�
vector<int> v;
v.push_back(100);
null_iterator<vector<int>::iterator> null_iter; //һ��δ��ʼ��������
vector<int>::iterator iter = begin(v);
if (iter == null_iter) //iter != null_iterҲһ��
	; //����
������ʵ��û�е���null_iterator��==����������ǵ�����null_iterator��T()�������������ˣ�
if (iter == (vector<int>::iterator) null_iter)

��ȷ�ķ����ǰ�null_iterд��ǰ�棬���£�
if (null_iter == iter) //null_iter != iterҲһ��

����ΪʲôҪ����һ��T()�����������Ϊ���ǵ���null_iterator����ʼ��һ���������������󣬱��磺
vector<int>::iterator iter = null_iterator<vector<int>::iterator>();

ע�⣬��������T&()������Է���һ��T&����Ϊ��null_iterator����Ĭ�ϲ�����ʱ��
�������޷���T()����T&()֮��ѡ����ɴ��󣬱��磺
void fun(vector<int>::iterator iter = null_iterator<vector<int>::iterator>());

������T&Ҳ��һ���ô�������������һ��������
void fun(vector<int>::iterator& iter);
��������µ��ã�
void fun(null_iterator<vector<int>::iterator>());
���û��T&()�����޷����룬��ֻ�����¶�����Σ�
null_iterator<vector<int>::iterator> NoUse;
void fun(NoUse);

Ȩ�����ֱ׶ˣ�����ѡ���˲�����T&()����Ϊ����ĵط���ҪĬ�ϲ�����������Ҫ���ݵ���������
*/
template<typename T>
class null_iterator
{
public:
	null_iterator() {}
	virtual ~null_iterator() {}

public:
	bool operator ==(T& iter) { return nullptr == iter._Ptr; }
	bool operator !=(T& iter) { return !(*this == iter); }
	operator T() { return m_t; } //��һ����������ʼ��Ϊһ��δ��ʼ���ĵ�����
//	operator T&() { return m_t; } //��Ҫ�������ã���������ΪĬ�ϲ�����ʱ�򣬱������޷���T()����T&()֮��ѡ����ɴ���

protected:
	T m_t; //δ��ʼ��������
};

//�����κβ�������һ��iterator���������������
#define NullDataIter (null_iterator<vector<MainData>::iterator>())
#define NullDataListIter (null_iterator<vector<DataListHead<MainData>>::iterator>())
#define NullInfiniteCurveIter (null_iterator<vector<InfiniteCurveData>::iterator>())
#define NullLegendIter (null_iterator<vector<LegendData>::iterator>())
#define NullAddrs (null_iterator<vector<long>::iterator>())
#define NullBitBmps (null_iterator<vector<BitBmp>::iterator>())

template<typename T>
void free_container(T& con)
{
#if _MSC_VER >= 1600
	T NoUse(move(con)); //vc2010�������ϵİ汾��ֻ���������ܳ����ͷŻ��棬֮ǰ�İ汾����clear()����
#else
	con.clear();
#endif
}

template<typename T, typename V>
void do_fill_1_value(T* _p, V v)
{
	if (!IsBadWritePtr(_p, sizeof(T)))
		*_p = v;
}

template <typename T>
struct OrigDataListHead
{
	OrigDataListHead() : pDataVector(new vector<T>) {}

	long Address;
	vector<T>* pDataVector;
	//�������Ҫ����Ϊָ�룬�����ڽ���ĳ����DataListHead��ʱ��ʱ�临�ӶȽ������Ե�
	//���������������DataListHead���ֹ��ܣ����޷��������ߵ���ʾ��δ���
	//�����ָ�����һ��С���⣬������ɾ��DataListHeadʱ����Ҫ�ͷ����ָ��ָ����ڴ�
	//���½�DataListHeadʱ����Ҫȥ��̬�������ָ��ָ��Ŀռ䣨��һ�����Է��ڹ��캯��������У�
	//ע�⣬�������������������ͷ�pDataVector����Ϊ����MainDataListArr.push_back���Ǹ���ʱ��������������ʱ��
	//�������ͷŵ�pDataVector�������pDataVector��MainDataListArr���滹Ҫʹ��
	//���ǱȽ����ף����ǲ��ö���Ϊָ�����ʽ

	bool operator ==(const OrigDataListHead& _OrigDataListHead){return this == &_OrigDataListHead;} //��ַ��Ȳ���Ϊ���
	bool operator !=(const OrigDataListHead& _OrigDataListHead){return !(*this == _OrigDataListHead);}
	bool operator ==(const OrigDataListHead* pOrigDataListHead){return this == pOrigDataListHead;} //��ַ��Ȳ���Ϊ���
	bool operator !=(const OrigDataListHead* pOrigDataListHead){return !(this == pOrigDataListHead);}
	operator long(){return Address;}
};

/*
����DataListHead���õ��������������ݽṹ�����������ڵ�����ʧЧ��ʱ����µ������Ƿǳ���Ҫ�ģ�
һ�������ͼ����ʱ�򣬵�LegendArr�����ڴ治����Ҫ���·����ڴ�ʱ���������ͼ����ǰ����ͼ��������������DataListHead��LegendIter
������ɾ��ͼ����ʱ�򣬸��´�ɾ��λ�ÿ�ʼ������ͼ��������������DataListHead��LegendIter
*/
template <typename T>
struct DataListHead : OrigDataListHead<T> //ռ��76�ֽڣ�������������ֽڣ�����������չ
{
	MainData LeftTopPoint;
	MainData RightBottomPoint;
	vector<LegendData>::iterator LegendIter;

	size_t SelectedIndex; //��ѡ�еĵ㣬���Ľڵ㽫��ʾΪͼ����SelectedNodeColor��ɫ������ڵ�����ʾ�Ļ���

	BYTE FillDirection;
	//�ӵ�λ��
	//1���������
	//2���������
	//3���������
	//4���������
	//���ؼ�û�жԸ���λ���л��⣬��ʵ���ϣ�ĳЩλ�Ľ����û������ģ������������������䣬����ȫ����������䣬���⽻�����ο�����
	//ע�⣬Ҫ��䣬��Ҫͼ����֧�֣����ͼ��ָʾ����䣬������ֽ���Ч
	//��5��6λ����һ�����忴����������������֮����ʾ������ֵ��
	//0������ʾֵ��1����ʾ��һ��ֵ��2����ʾ���һ��ֵ��3����ʾƽ��ֵ
	//��7��8λֻ����5��6λ��Ϊ0��ʱ����Ч���������ģʽֻ����hatch��Pattern���ģʽ��������ָ����ʾ���������ɫ�������������£�
	//��7λ��
	//0��ʹ��ǰ��ɫ��1��ʹ�ñ������ߵĻ��ʵ���ɫ
	//��8λ���Ϊ1����ʹ�õ�7λָʾ����ɫ�ķ�ɫ
	//�����ģʽΪSolidģʽʱ��7��8λ��Ч����ʱ��ʹ��Solidģʽ�����ɫ�ķ�ɫ����ʾ������

	BYTE Power; //�ݴΣ�0�κ�1�ξ�����1�Σ�����1�ζ�����2��

	short Zx, Zy; //Z��������X��Y�����ϵķ���
	//��ʣ�������ֽ�û���䣬�˷ѵ���
};

struct InfiniteCurveData : MainData
{
	long Address;

	//BYTE State;
	//���ֵ��OrigMainData�̳ж����������岻һ����0-ˮƽ��Value��Ч��1-��ֱ��Time��Ч

	//��DataListHead���Ӧ�ĳ�Ա������Ҳһ������FillDirectionֻ֧��0-0xF������������ʾֵ
	vector<LegendData>::iterator LegendIter;
	BYTE FillDirection;

	//����MainData������HCOOR_TYPE��float�����Ա��಻��ͨ������long�÷��ͺ���find��������
	operator long(){return Address;}
	bool operator ==(const long Address){return this->Address == Address;}
};

typedef struct tagBatchExport
{
	LPTSTR pFileName;
	LPTSTR pStart;
	UINT nWidth;
	UINT nFileNum;
	TCHAR cNumFormat[16];
}BatchExport;

#define PolyTextLen		32
template <typename T>
struct CoorData
{
	CoorData(){pPolyTexts = 0; pTexts = 0; nPolyText = 0; nScales = 0; RangeMask = 0;}
	CoorData(int _nPolyText){ASSERT(_nPolyText >= 0); nPolyText = _nPolyText; nScales = 0; RangeMask = 0; assign();}
	~CoorData(){clear();}

	void clear(){if (pPolyTexts) delete[] pPolyTexts; pPolyTexts = nullptr; if (pTexts) delete[] pTexts; pTexts = nullptr; nPolyText = 0;}
	void reserve(int _nPolyText)
	{
		if (_nPolyText > nPolyText) //ֻ���ڴ治����ʱ�����·����ڴ棬�ڴ��ж���ʱ�������������Ҫ�ջض�����ڴ棬���ȵ���FreeMemһ���ٵ��ñ���������
		{
			clear();
			nPolyText = _nPolyText;
			assign();
		}
	}

	T		fStep;      //���경��
	T		fCurStep;   //��ǰ���������경������û�����ŵ�ʱ��������fTimeStep

	POLYTEXT* pPolyTexts;	//����PolyTextOut����
	TCHAR	(*pTexts)[PolyTextLen];	//ÿһ��PolyTextOut����ʱ��Ҫ���ַ���
	USHORT	nPolyText : 14;	//pTextsָ��ĵ�ַ��TCHAR[PolyTextLen]�ĸ���
	USHORT	RangeMask : 2;  //�ӵ�λ��ÿһλ���δ���fMinVisibleValue��fMaxVisibleValue����Ч�ԣ�1Ϊ��Ч
	USHORT	nScales;		//����̶ȸ���

	T		fMinVisibleValue;
	T		fMaxVisibleValue;

protected:
	void assign()
	{
		pPolyTexts = new POLYTEXT[nPolyText];
		memset(pPolyTexts, 0, nPolyText * sizeof(POLYTEXT));
		pTexts = new TCHAR[nPolyText][PolyTextLen];
		for (auto i = 0; i < nPolyText; ++i)
			pPolyTexts[i].lpstr = pTexts[i];
	}
};
