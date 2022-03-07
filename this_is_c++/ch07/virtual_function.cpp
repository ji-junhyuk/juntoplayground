#include "../ch01/stdafx.h"

class CMyData
{
	public:
		virtual void print_data()
		{
			cout << "CMyData: " << m_i_data << '\n';
		}
		void test_func()
		{
			cout << "***test_func***" << '\n';
			print_data();
			cout << "===============" << '\n';
		}
	protected:
		int m_i_data = 10;
};

class CMyDataEx : public CMyData
{
	public:
		virtual void print_data()
		{
			cout << "CMyDataEx: " << m_i_data * 2 << '\n';
		}
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyDataEx a;
	a.print_data();
	CMyData &b = a;
	b.print_data();
	a.test_func();
}
