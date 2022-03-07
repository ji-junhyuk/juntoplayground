#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

class CTest
{
	int m_i_data;

	public:
	CTest(int i_param) : m_i_data(i_param)
	{
		cout << "CTest::CTest()" << '\n';
	}
	~CTest()
	{
		cout << "~CTest::CTest()" << m_i_data << '\n';
	}
};

int _tmain(int argc, _TCHAR *argv[])
{
	cout << "begin" << '\n';
	CTest a(1);
	cout << "begore b" << '\n';
	CTest b(2);
	cout << "end" << '\n';
}
