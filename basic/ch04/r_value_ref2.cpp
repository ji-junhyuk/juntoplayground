#include "../ch01/stdafx.h"

void test_func(int &i_param)
{
	cout << "test_func(int &)" << '\n';
}

void test_func(int &&i_param)
{
	cout << "test_func(int &&)" << '\n';
}

int _tmain(int argc, _TCHAR *argv[])
{
	test_func(3 + 4);
	
	return (0);
}
