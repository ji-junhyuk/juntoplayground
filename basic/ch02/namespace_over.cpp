#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

void test_func(void)
{
	cout << "::test_func()" << '\n';
}

namespace TEST
{
	void test_func(void)
	{
		cout << "TEST::test_func()" << '\n';
	}
}

namespace MYDATA
{
	void test_func(void)
	{
		cout << "DATA::test_func()" <<'\n';
	}
}

int _tmain(int argc, _TCHAR *argv[])
{
	test_func();
	::test_func();
	TEST::test_func();
	MYDATA::test_func();
	return (0);
}
