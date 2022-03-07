#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

#define ADD(a, b)((a) + (b))

int add(int a, int b)
{
	return a + b;
}

inline int add_new(int a, int b)
{
	return a + b;
}

int _tmain(int argc, _TCHAR *argv[])
{
	int a, b;
	cin >> a >> b;
	cout << ADD(a, b) << '\n';
	cout << add(a, b) << '\n';
	cout << add_new(a, b) << '\n';
	return (0);
}
