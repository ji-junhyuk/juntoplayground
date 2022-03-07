#include "../ch01/stdafx.h"
#include <memory>

class CTest
{
	public:
		CTest() { cout << "CTest()" << '\n'; }
		~CTest() { cout << "~CTest()" << '\n'; }
		void test_func() { cout << "test_func()" << '\n'; }
};

void remove_test(CTest *p_test)
{
	cout << "remove_test()" << '\n';
	delete[] p_test;
}

int _tmain(int argc, _TCHAR *argv[])
{
	cout << "begin" << '\n';

	shared_ptr<CTest> ptr(new CTest[3], remove_test);
	cout << "end" << '\n';
}
