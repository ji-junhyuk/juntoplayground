#include "../ch01/stdafx.h"

class CMyData
{
	public:
		CMyData() { cout << "CMyData()" << '\n'; }
		CMyData(int i_param) { cout << "CMyData(int)" << '\n'; }
		CMyData(double d_param) { cout << "CMyData(double)" << '\n'; }
};

class CMyDataEx : public CMyData
{
	public:
		using CMyData::CMyData;
//		CMyDataEx() { cout << "CMyDataEx()" << '\n'; }
//		CMyDataEx(int i_param) : CMyData(i_param)
//	{
//		cout << "CMyDataEx(int)" << '\n';
//	}
//		CMyDataEx(double d_param) : CMyData()
//	{
//		cout << "CMyDataEx(double)" << '\n';
//	}
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyDataEx a;
	cout << "==========" << '\n';
	CMyDataEx b(5);
	cout << "==========" << '\n';
	CMyDataEx c(5.5);
}
