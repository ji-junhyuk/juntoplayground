#include "../ch01/stdafx.h"

class CMyData 
{
	public:
		CMyData(int i_param) : m_i_data(i_param) { }
		operator int() { return m_i_data; }
		int operator++()
		{
			cout << "operator++()" << '\n';
			return ++m_i_data;
		}
		int operator++(int)
		{
			cout << "operator++(int)" << '\n';
			int i_data = m_i_data;
			m_i_data++;
			return i_data;
		}
	private:
		int m_i_data = 0;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData a(10);

	cout << ++a << '\n';
	cout << a++ << '\n';
	cout << a << '\n';
}
