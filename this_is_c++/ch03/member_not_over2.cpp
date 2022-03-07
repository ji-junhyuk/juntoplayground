#include "../ch01/stdafx.h"

class CMyData
{
	public:
		CMyData() : m_i_data(0) { };
		int get_data(void) { return m_i_data; }
		void set_data(void) { m_i_data = i_param; }
		void set_data(double d_param) = delete;
	private:
		int m_i_data;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData a;
	a.set_data(10);
	cout << a.get_data() << '\n';

	CMyData b;
	b.set_data(10.5);
	cout << b.get_data() << '\n';
	return (0);
}
