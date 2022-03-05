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
	cout << "===begin===" << '\n';
	shared_ptr<CTest> ptr1(new CTest);
	cout << "Counter: " << ptr1.use_count() << '\n';
	{
		shared_ptr<CTest> ptr2(ptr1);
		cout << "Counter: " << ptr1.use_count() << '\n';
		ptr2->test_func();
	}
	cout << "Counter: " << ptr1.use_count() << '\n';
	ptr1->test_func();
	cout << "===end===" << '\n';
	return (0);
}
