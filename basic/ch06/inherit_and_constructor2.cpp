#include "../ch01/stdafx.h"

class CMyDataA
{
	public:
		CMyDataA() 
		{ 
			cout << "CMyDataA()" << '\n'; 
			m_p_size_data = new char[32];
		}
		~CMyDataA() 
		{ 
			cout << "~CMyDataA()" << '\n'; 
			delete m_p_size_data;
		}
	protected:
		char *m_p_size_data;
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
		~CMyDataC() 
		{ 
			cout << "~CMyDataC()" << '\n'; 
			delete m_p_size_data;
		};
};

int _tmain(int argc, _TCHAR *argv[])
{
	cout << "====begin====" << '\n';
	CMyDataC data;
	cout << "====end====" << '\n';
	return (0);
}
