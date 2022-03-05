#include "../ch01/stdafx.h"

void test_func1()
{
	cout << "test_func1() - begin" << '\n';
	throw 0;
	cout << "test_func1() - end" << '\n';
}

void test_func2()
{
	cout << "test_func2() - begin" << '\n';
	test_func1();
	cout << "test_func2() - end" << '\n';
}

void test_func3()
{
	cout << "test_func3() - begin" << '\n';
	test_func2();
	cout << "test_func3() - end" << '\n';
}

int _tmain(int argc, _TCHAR *argv[])
{
	try
	{
		test_func3();
	}
	catch(...)
	{
		cout << "Exception handling" << '\n';
	}
	return 0;
}
