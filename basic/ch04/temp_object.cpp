#include "../ch01/stdafx.h"

class CTestData
{
	public:
		CTestData(int i_param, char *p_size_name) : m_i_data(i_param), m_p_c_size_name(p_size_name)
	{
		cout << "CTestData(int): " << m_p_c_size_name << '\n';
	}
		~CTestData()
		{
			cout << "~CTestData(): " << m_p_c_size_name << '\n';
		}
		CTestData(const CTestData &rhs) : m_i_data(rhs.m_i_data), m_p_c_size_name(rhs.m_p_c_size_name)
	{
		cout << "CTestData(const CTestData &): " << m_p_c_size_name << '\n';
	}
		CTestData &operator=(const CTestData &rhs)
		{
			cout << "operator=" << '\n';
			m_i_data = rhs.m_i_data;
			return *this;
		}
		int get_data() const { return m_i_data; }
		void set_data(int i_param) { m_i_data = i_param; }
	private:
		int m_i_data = 0;
		char *m_p_c_size_name = nullptr;
};

CTestData test_func(int i_param)
{
	CTestData a(i_param, "a");
	return a;
}

int _tmain(int argc, _TCHAR *argv[])
{
//	CTestData b(5, "b");
	cout << "=========before==========" << '\n';
//	b = test_func(10);
//	test_func(10);
	CTestData &r_data = test_func(10);
	cout << "=========after==========" << '\n';
//	cout << b.get_data() << '\n';
	return (0);
}
