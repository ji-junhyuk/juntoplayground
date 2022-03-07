#include "../ch01/stdafx.h"

void test_func(const int &i_param)
{
	int &i_new_param = const_cast<int &>(i_param);
	i_new_param = 20;
}

int _tmain(int argc, _TCHAR *argv[])
{
	int i_data = 10;
	test_func(i_data);
	cout << i_data << '\n';
	return 0;
}
