#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

template <typename T>
T add(T a, T b)
{
	return a + b;
}

int _tmain(int argc, _TCHAR *argv[])
{
	cout << add(3, 4) << '\n';
	cout << add(3.3, 4.4) << '\n';
}
