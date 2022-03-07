#include "../ch01/stdafx.h"

class CMyData
{
	public:
		explicit CMyData(int i_param)
		{
			m_p_i_data = new int(i_param);
		}
		~CMyData() { delete m_p_i_data; }
		operator int() { return *m_p_i_data; }
		CMyData& operator=(const CMyData &rhs)
		{
			if (this == &rhs)
				return *this;
			delete m_p_i_data;
			m_p_i_data = new int(*rhs.m_p_i_data);
			return *this;
		}
		CMyData& operator+=(const CMyData &rhs)
		{
			int *p_i_new_data = new int(*m_p_i_data);
			*p_i_new_data += *rhs.m_p_i_data;
			delete m_p_i_data;
			m_p_i_data = p_i_new_data;
			return *this;
		}
	private:
		int *m_p_i_data = nullptr;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData a(0), b(5), c(15);
	a += b;
	a += c;
	cout << a << '\n';
}
