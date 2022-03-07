#include "../ch01/stdafx.h"

class CMyData
{
	public:
		CMyData(int i_param)
		{
			m_p_i_data = new int;
			*m_p_i_data = i_param;
		}
		CMyData(const CMyData &rhs)
		{
			cout << "CMyData(const CMyData &)" << '\n';
			m_p_i_data = new int;
			*m_p_i_data = *rhs.m_p_i_data;
		}
		~CMyData()
		{
			delete m_p_i_data;
		}
		CMyData &operator=(const CMyData &rhs)
		{
			*m_p_i_data = *rhs.m_p_i_data;
			return *this;
		}
		int get_data()
		{
			if (m_p_i_data != NULL)
				return *m_p_i_data;
			return 0;
		}
	private:
		int *m_p_i_data = nullptr;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData a(10);
	CMyData b(20);

	a = b;
	cout << a.get_data() << '\n';
	return 0;
}
