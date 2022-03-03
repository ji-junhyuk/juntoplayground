#include "../ch01/stdafx.h"

class CMyData
{
	public:
		explicit CMyData(int i_param)
		{
			cout << "CMyData(int)" << '\n';
			m_p_i_data = new int(i_param);
		}
		CMyData(const CMyData &rhs)
		{
			cout << "CMyData(const CMyData &)" << '\n';
			m_p_i_data = new int(*rhs.m_p_i_data);
		}
		~CMyData() { delete m_p_i_data; }
		operator int() { return *m_p_i_data; }
		CMyData operator+(const CMyData &rhs)
		{
			return CMyData(*m_p_i_data + *rhs.m_p_i_data);
		}
		CMyData &operator=(const CMyData &rhs)
		{
			cout << "operator=" << '\n';
			if (this == &rhs)
				return *this;
			delete m_p_i_data;
			m_p_i_data = new int(*rhs.m_p_i_data);
			return *this;
		}
		CMyData &operator=(CMyData &&rhs)
		{
			cout << "operator=(move)" << '\n';
			m_p_i_data = rhs.m_p_i_data;
			rhs.m_p_i_data = NULL;
			return *this;
		}
	private:
		int *m_p_i_data = nullptr;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData a(0), b(3), c(4);
	cout << "======before=======" << '\n';
	a = b + c;
	cout << "======after=======" << '\n';
	cout << a << '\n';
	a = b;
	cout << a << '\n';
	return (0);
}
