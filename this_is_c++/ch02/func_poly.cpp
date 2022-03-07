#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

int add(int a, int b)
{
	return a + b;
}

int add(int a, int b, int c)
{
	return a + b + c;
}

double add(double a, double b)
{
	return a + b;
}

int _tmain(int argc, _TCHAR *argv[])
{
	cout << add(3, 4) << '\n';
	cout << add(3, 4, 5) << '\n';
	cout << add(3.3, 4.4) << '\n';
}
