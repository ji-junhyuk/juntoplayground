#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

class CTest
{
	public:
		CTest()
		{
			cout << "CTest::CTest()" << '\n';
		}
		~CTest()
		{
			cout << "~CTest::CTest()" << '\n';
		}
};

int _tmain(int argc, _TCHAR *argv[])
{
	cout << "begin" << '\n';
	CTest a;
	cout << "before b" << '\n';
	CTest b;
	cout << "end" << '\n';
	/*
	 * begin -> a() -> b -> b() -> end -> ~a() -> ~b()
	 */
}
