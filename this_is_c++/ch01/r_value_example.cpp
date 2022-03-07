#include "stdafx.h"
#include <iostream>
using namespace std;

int test_func(int i_param)
{
	int i_result = i_param * 2;

	return i_result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i_input = 0;
	cout << "input number: ";
	cin >> i_input;
	int &&i_rdata = i_input + 5;
	cout << i_rdata << '\n';

	int &&i_result = test_func(10);
	i_result += 10;
	cout << i_result << '\n';
	return (0);
}
