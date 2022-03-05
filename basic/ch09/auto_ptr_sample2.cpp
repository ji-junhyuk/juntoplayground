#include "../ch01/stdafx.h"
#include <memory>
#include <iostream>

class CMyData
{
	public:
		CMyData() { cout << "CMyData()" << '\n'; }
		~CMyData() { cout << "~CMyData()" << '\n'; }
		void test_func() { cout << "CMyData::test_func()" << '\n'; }
};

int _tmain(int argc, _TCHAR *argv[])
{
	auto_ptr<CMyData> ptr_test(new CMyData);
	auto_ptr<CMyData> ptr_new;
	cout << "0x:" << ptr_test.get() << '\n';
	ptr_new = ptr_test;
	cout << "0x:" << ptr_test.get() << '\n';
	ptr_test->test_func();
	return (0);
}
