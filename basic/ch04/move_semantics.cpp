#include "../ch01/stdafx.h"

class CTestData
{
	public:
		CTestData() { cout << "CTestData()" << '\n'; }
		~CTestData() { cout << "~CTestData()" << '\n'; }

		CTestData(const CTestData &rhs) : m_i_data(rhs.m_i_data)
	{
		cout << "CTestData(const CTestData &)" << '\n';
	}
		CTestData(CTestData &&rhs) : m_i_data(rhs.m_i_data)
	{
		cout << "CTestData(const CTestData &&)" << '\n';
	}
		int get_data() const { return m_i_data; }
		void set_data(int i_param) { m_i_data = i_param; }
	private:
		int m_i_data = 0;
};

CTestData test_func(int i_param)
{
	cout << "**test_func(): begin**" << '\n';
	CTestData a;
	a.set_data(i_param);
	cout << "**test_func(): end**" << '\n';
	return a;
}

int _tmain(int argc, _TCHAR *argv[])
{
	CTestData b;
	cout << "==before==" << '\n';
	b = test_func(20); // 삭제된 함수를 참조하려고 합니다
	cout << "==after==" << '\n';
	CTestData c(b);
}
