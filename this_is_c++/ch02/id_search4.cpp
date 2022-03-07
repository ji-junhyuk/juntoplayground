#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

int i_data = 100;

namespace TEST
{
	int i_data = 200;
}

using namespace TEST; //

int _tmain(int argc, _TCHAR *argv[])
{
	cout << i_data << '\n'; // 모호하다
	return (0);
}
