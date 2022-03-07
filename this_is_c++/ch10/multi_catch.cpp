#include "../ch01/stdafx.h"

void except_test1()
{
	int i_input;
	cout << "1 ~ 10 양의 정수를 입력하세요.: ";
	cin >> i_input;
	if (i_input < 1 || i_input > 10)
		throw i_input;
}

void except_test2()
{
	char c;
	cout << "Menu: [A]dd\t [D]elete\t [E]xit\n:";
	cin >> c;

	if (c != 'a' && c != 'd' && c != 'e')
		throw c;
}

int _tmain(int argc, _TCHAR *argv[])
{
	cout << "begin" << '\n';
	try
	{
		except_test1();
		except_test2();
	}
	catch(int i_exp)
	{
		cout << "Error:" << i_exp << "는 범위를 벗어난 숫자입니다." << '\n';
	}
	catch (char c)
	{
		cout << "Error:" << c << "알 수 없는 메뉴입니다." << '\n';
	}
	cout << "end" << '\n';
}
