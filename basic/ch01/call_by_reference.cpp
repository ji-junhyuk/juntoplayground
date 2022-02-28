#include "stdafx.h"
#include <iostream>
using namespace std;

void test_func(int &r_param)
{
	r_param = 100;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n_data = 0;
	test_func(n_data);
	cout << n_data << '\n';
	return (0);
}
