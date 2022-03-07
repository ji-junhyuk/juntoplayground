#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

class CTest
{
	public:
		CTest(){}

		//C++11 부터 선언과 동시에 멤버 변수를  초기화할 수 있다.
		int m_i_data1 = 10;
		int m_i_data2 = 20;
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
