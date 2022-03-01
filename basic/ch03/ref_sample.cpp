#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

class CRefTest
{
	public:
		CRefTest(int &i_param) : m_i_data(i_param) { };
		int get_data(void) { return m_i_data; }

	private:
		// 참조형 멤버는 객체가 생성될 때 반드시 초기화해야 한다.
		int &m_i_data;
}

int _tmain(int argc, _TCHAR *argv[])
{
	int a = 10;
	CRefTest t(a);
}
