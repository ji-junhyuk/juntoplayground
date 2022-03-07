#include "../ch01/stdafx.h"
#include <memory>

class CTest
{
	public:
		CTest() { cout << "CTest()" << '\n'; }
		~CTest() { cout << "~CTest()" << '\n'; }
		void test_func() { cout << "test_func()" << '\n'; }
};

int _tmain(int argc, _TCHAR *argv[])
{
	unique_ptr<CTest> ptr1(new CTest);
//	unique_ptr<CTest> ptr2(ptr1)
	return 0;
}
