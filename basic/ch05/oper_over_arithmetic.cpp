#include "../ch01/stdafx.h"

class CMyData
{
	public:
		CMyData(int i_param) : m_i_data(i_param)
	{
		cout << "CMyData(int)" << '\n';
	}
		CMyData(const CMyData &rhs) : m_i_data(rhs.m_i_data)
	{
		cout << "CMyData(const CMyData &)" << '\n';
	}
		CMyData(const CMyData &&rhs) : m_i_data(rhs.m_i_data)
	{
		cout << "CMyData(const CMyData &&)" << '\n';
	}
		operator int() { return m_i_data; }
		CMyData operator+(const CMyData &rhs)
		{
			cout << "operator+" << '\n';
			CMyData result(0);
			result.m_i_data = this->m_i_data + rhs.m_i_data;
			return result;
		}
		CMyData &operator=(const CMyData &rhs)
		{
			cout << "operator=" << '\n';
			m_i_data = rhs.m_i_data;
			return *this;
		}
	private:
		int m_i_data = 0;
};

int _tmain(int argc, _TCHAR *argv[])
{
	cout << "======begin=======" << '\n';
	CMyData a(0), b(3), c(4);
	a = b + c;
	cout << a << '\n';
	cout << "======end=======" << '\n';
	return (0);
}
