#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

int i_test_func(int i_param1, int i_param2 = 2)
{
	return i_param1 * i_param2;
}

int _tmain(int argc, _TCHAR *argv[])
{
	cout << i_test_func(10) << '\n';
	cout << i_test_func(10, 5) << '\n';
}
