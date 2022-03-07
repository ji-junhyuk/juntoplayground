#include "../ch01/stdafx.h"

class CMyData
{
	public:
		CMyData(int i_param) : m_i_data(i_param) { }
		int get_data() const { return m_i_data; }
		void set_data(int i_param) { m_i_data = i_param; }
		friend void print_data(const CMyData &);
	private:
		int m_i_data = 0;
};

void print_data(const CMyData &r_data)
{
	cout << "print_data(): " << r_data.m_i_data << '\n';
}

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData a(5);
	print_data(a);
}
