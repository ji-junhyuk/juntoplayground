#include "../ch01/stdafx.h"

int _tmain(int argc, _TCHAR *argv[])
{
	int a = 100, b;
	cout << "input number: ";
	cin >> b;
	try
	{
		if (b == 0)
			throw b;
		else 
			cout << a / b << '\n';
	}
	catch (int i_exp)
	{
		cout << "Error: " << i_exp << "으로 나눌 수 없습니다." << '\n';
	}
	return (0);
}
