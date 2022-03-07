#include "../ch01/stdafx.h"

class CMyData
{
	public:
		CMyData() { cout << "CMyData()" << '\n'; }
		int get_data() { return m_i_data; }
		void set_data(int i_param) { m_i_data = i_param; }
	protected:
		void print_data() { cout << "CMyData::print_data()" << '\n';}
	private:
		int m_i_data = 0;
};

class CMyDataEx : public CMyData
{
	public:
		CMyDataEx() { cout << "CMyDataEX()" << '\n'; }
		void test_func()
		{
			print_data();
			set_data(5);
			cout << CMyData::get_data() << '\n';
		}
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyDataEx data;
	data.set_data(10);
	cout << data.get_data() << '\n';
	data.test_func();
}
