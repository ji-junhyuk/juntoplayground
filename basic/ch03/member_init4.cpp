#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

class CTest
{
	public:
		CTest()
			: m_i_data1(10), m_i_data2(20)
		{}
		int m_i_data1;
		int m_i_data2;
		void print_data(void)
		{
			cout << m_i_data1 << '\n';
			cout << m_i_data2 << '\n';
		}
};

int _tmain(int argc, _TCHAR *argv[])
{
	CTest t;
	t.print_data();
	return (0);
}
