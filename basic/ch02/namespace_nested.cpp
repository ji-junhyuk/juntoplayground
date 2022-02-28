#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

namespace TEST
{
	int n_i_data = 100;
	namespace DEV
	{
		int n_i_data = 200;
		namespace WIN
		{
			int n_i_data = 300;
		}
	}
}

int _tmain(int argc, _TCHAR *argv[])
{
	cout << TEST::n_i_data << '\n';
	cout << TEST::DEV::n_i_data << '\n';
	cout << TEST::DEV::WIN::n_i_data << '\n';
	return (0);
}
