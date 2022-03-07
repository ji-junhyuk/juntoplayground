#include "../ch01/stdafx.h"

class CMyDataA
{
	public:
		CMyDataA() { cout << "CMyDataA()" << '\n'; }
		~CMyDataA() { cout << "~CMyDataA()" << '\n'; }
};

class CMyDataB : public CMyDataA
{
	public:
		CMyDataB() { cout << "CMyDataB()" << '\n'; }
		~CMyDataB() { cout << "~CMyDataB()" << '\n'; }
};

class CMyDataC : public CMyDataB
{
	public:
		CMyDataC() { cout << "CMyDataC()" << '\n'; };
		~CMyDataC() { cout << "~CMyDataC()" << '\n'; };
};

int _tmain(int argc, _TCHAR *argv[])
{
	cout << "====begin====" << '\n';
	CMyDataC data;
	cout << "====end====" << '\n';
	return (0);
}
