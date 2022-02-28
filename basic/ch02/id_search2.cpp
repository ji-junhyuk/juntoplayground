#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR *argv[])
{
	int i_input = 0;
	cout << "11이상의 정수를 입력하세요" << '\n';
	cin >> i_input;
	if (i_input > 10)
		cout << i_input << '\n';
	else 
		cout << "error" << '\n';
	return (0);
}
