#include "../ch01/stdafx.h"

class CMyData
{
	public:
		int get_data() { return m_i_data; }
		void set_data(int i_param) { m_i_data = i_param; }
	private:
		int m_i_data = 0;
};

class CMyDataEx : public CMyData
{
	public:
		void set_data(int i_param)
		{
			if (i_param < 0)
				CMyData::set_data(0);
			if (i_param > 10)
				CMyData::set_data(10);
		}
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyDataEx a;
	CMyData &r_data = a;
	r_data.set_data(15);
	cout << r_data.get_data() << '\n';
//	CMyData a;
//	a.set_data(-10);
//	cout << a.get_data() << '\n';
//
//	CMyDataEx b;
//	b.set_data(15);
//	cout << b.get_data() << '\n';
}
