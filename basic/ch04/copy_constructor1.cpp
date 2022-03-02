#include "../ch01/stdafx.h"

class CMyData
{
	public:
		CMyData() { cout << "CMyData()" << '\n'; }
		CMyData(const CMyData &rhs)
			// : m_i_data(rhs.m_i_data); 로 생성자초기화목록도 이용가능하다.
		{
			this->m_i_data = rhs.m_i_data;
			cout << "CMyData(const CMyData &)" << '\n';
		}
		int get_data(void) const { return m_i_data; }
		void set_data(int i_param) { m_i_data = i_param; }
	private:
		int m_i_data = 0;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData a;
	a.set_data(10);
	CMyData b(a);
	cout << b.get_data() << '\n';
	return (0);
}
