#include "../ch01/stdafx.h"

class CTestData
{
	public:
		explicit CTestData(int i_param) : m_i_data(i_param) { }
		explicit operator int(void) { return m_i_data; }
		int get_data() const { return m_i_data; }
		void set_data(int i_param) { m_i_data = i_param; }
	private:
		int m_i_data = 0;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CTestData a(10);
	cout << a.get_data() << '\n';
//	cout << a << '\n';
	cout << (int)a << '\n';
	cout << static_cast<int>(a) << '\n';
}
