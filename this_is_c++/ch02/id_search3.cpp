#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

int i_data = 200;

namespace TEST
{
	void test_func(void)
	{
		cout << i_data << '\n';
	}
	int i_data = 100;
}

int _tmain(int argc, _TCHAR *argv[])
{
	TEST::test_func();
	return (0);
}
