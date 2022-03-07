#include "stdafx.h"
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i_x, i_y;
	i_x = 10;
	i_y = 20;
	swap(i_x, i_y);
	cout << i_x << ' ' << i_y << '\n';
	return (0);
}
