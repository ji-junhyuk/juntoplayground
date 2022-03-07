#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

class CMyData
{
	public:
		CMyData(int i_param) : m_i_data(i_param) { };
		CMyData(int x, int y) : m_i_data(x + y) { };
		int get_data(void) { return m_i_data; };
	private:
		int m_i_data;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData a(10);
	CMyData b(3, 4);
	cout << a.get_data() << '\n';
	cout << b.get_data() << '\n';
}
