#include "stdafx.h"
#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 10;
	int y = 20;
	swap(x, y);
	cout << x << '\n';
	cout << y << '\n';
	return (0);
}
