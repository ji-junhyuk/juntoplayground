#include "../ch01/stdafx.h"

class CMyData
{
	public:
		CMyData(int i_param) : m_i_data(i_param) { }
		CMyData operator+(const CMyData &rhs)
		{
			return CMyData(m_i_data + rhs.m_i_data);
		}
		CMyData &operator=(const CMyData &rhs)
		{
			m_i_data = rhs.m_i_data;
			return *this;
		}
		operator int() { return m_i_data; }
	protected:
		int m_i_data = 0;
};

class CMyDataEx : public CMyData
{
	public:
		CMyDataEx(int i_param) : CMyData(i_param) { }
		CMyDataEx operator+(const CMyDataEx &rhs)
		{
			return CMyDataEx(static_cast<int>(CMyData::operator+(rhs)));
		}
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData a(3), b(4);
	cout << a + b << '\n';
	CMyDataEx c(3), d(4), e(0);
	e = c + d;
	cout << e << '\n';
	return 0;
}
