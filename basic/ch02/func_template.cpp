#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

template <typename T>
T test_func(T a)
{
	cout << " 매개변수 a: " << a << '\n';
	return (a);
}

int _tmain(int argc, _TCHAR *argv[])
{
	cout << test_func(3) << '\n';
	cout << test_func(3.3) << '\n';
	cout << test_func('A') << '\n';
	cout << test_func("hello, junto") << '\n';
}
