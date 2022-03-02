#include "../ch01/stdafx.h"

void test_func(int i_param)
{
	cout << i_param << '\n';
}

int _tmain(int argc, _TCHAR *argv[])
{
	test_func(10);
	test_func(5.5);
	return (0);
}
