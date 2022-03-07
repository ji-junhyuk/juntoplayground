#include "../ch01/stdafx.h"

class CMyData
{
	public:
		CMyData()
		{
			cout << "CMyData()" << '\n';
		}
		virtual ~CMyData() { }
		virtual void test_func1() { }
		virtual void test_func2() { }
};

class CMyDataEx : public CMyData
{
	public:
		CMyDataEx()
		{
			cout << "CMyDataEx()" << '\n';
		}
		virtual ~CMyDataEx() { }
		virtual void test_func1() { }
		virtual void test_func2()
		{
			cout << "test_func2()" << '\n';
		}
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData *p_data = new CMyDataEx;
	p_data->test_func2();
	delete p_data;
	return 0;
}
