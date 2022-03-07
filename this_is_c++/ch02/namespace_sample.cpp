#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

namespace test
{
	int n_i_data = 100;
	void test_func(void)
	{
		cout << "test_func" << '\n';
	}
}

int _tmain(int argc, _TCHAR *argv[])
{
	test::test_func();
	cout << test::n_i_data << '\n';
	return (0);
}
