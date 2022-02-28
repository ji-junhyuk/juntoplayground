#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

void test_func(int a)
{
	cout << "test_func(int)" << '\n';
}

void test_func(int a, int b = 10)
{
	cout << "test_func(int, int)" << '\n';
}

int _tmain(int argc, _TCHAR *argv[])
{
	test_func(5);
}
/*
 * 함수를 만든 제작자는 오류를 경험하지 않지만 함수 사용자는 오류를 경험할 수 있다.
 * 실력있는 프로그래머라면 자신이 만들어낸 함수나 객체를 사용하는 또 다른 개발자를 고려해야 한다.
 */
