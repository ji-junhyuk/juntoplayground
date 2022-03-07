#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int i_list[5] = {10, 20, 30, 40, 50};
	for (int idx = 0; idx < 5; idx++)
		cout << i_list[idx] << ' ';
	cout << '\n';

	for (auto n : i_list)
		cout << n << ' ';
	cout << '\n';

	for (auto &n : i_list)
		cout << n << ' ';
	cout << '\n';
	return (0);
}
